#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE1 "kernel"
#define TYPE2 "module"
#define TYPE3 "illegal_module"
#define TYPE4 "app"

static int size = 0;
typedef struct {
    char* name;
    char* content;
} MOD;

MOD* read_mods(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {  
        printf("Failed to open file.\n");
        return NULL;
    }
    char line[100];
     size = 0;
    while (fgets(line, sizeof(line), fp) != NULL) { 
        size++;
    }
    rewind(fp); 
    MOD* arr = (MOD*) malloc(size * sizeof(MOD));  
    if (arr == NULL) { 
        printf("Failed to allocate memory.\n");
        fclose(fp);
        return NULL;
    }
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        (arr+i)->content  = (char*) malloc(strlen(line)+1);
        strcpy((arr + i)->content,line);
        char* token = strtok(line, " ");
        token = strtok(NULL, " ");
        token = strtok(NULL, " ");
        (arr+i)->name  = (char*) malloc(strlen(token)+1);
        strcpy((arr + i)->name, token);
        i++;
    }
    fclose(fp);
    return arr;
}

int main() {
    MOD* arr = read_mods("idPASide.txt");  
    if (arr == NULL) {  
        printf("Failed to read mods.\n");
        return -1;
    }
    printf("size = %d \n",size);
    for (int i = 0; i < size; ++i) {  // 打印结构体
        printf("MOD %d:  name=%s, content=%s\n", i+1, (arr+i)->name, (arr+i)->content);
        
        if(strcmp((arr+i)->name, TYPE1) == 0){
            printf("是 kernel 类型异常日志 .\n");
        }

        if(strcmp((arr+i)->name, TYPE2) == 0){
            printf("是 module 类型异常日志 .\n");
        }

        if(strcmp((arr+i)->name, TYPE3) == 0){
            printf("是 illegal_module 类型异常日志 .\n");
        }
        if(strcmp((arr+i)->name,TYPE4) == 0){
            printf("是 app 类型异常日志 .\n");
        }
    }
    free(arr); 
    return 0;
}