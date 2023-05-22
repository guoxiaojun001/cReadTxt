#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct modelData{
    string type;
    string content;

} MOD;

MOD ParseLine(const string& line) {
  vector<string> v;
  int pos = 0;
  int pos2 = 0;
  int len = line.length();
  while (pos < len) {
    pos2 = line.find(" ", pos);
    if (pos2 == -1) pos2 = len;
    v.push_back(line.substr(pos, pos2 - pos));
    pos = pos2 + 1;
  }

    MOD mod ;
    mod.type = v[2];
    mod.content = line;
    for (int i = 0; i<v.size(); ++i)
	{
		cout << v[i]  << endl;
	}

  return mod;
};

MOD* ParseLine2(const string& line) {
  vector<string> v;
  int pos = 0;
  int pos2 = 0;
  int len = line.length();
  while (pos < len) {
    pos2 = line.find(" ", pos);
    if (pos2 == -1) pos2 = len;
    v.push_back(line.substr(pos, pos2 - pos));
    pos = pos2 + 1;
  }

	MOD *mod = new MOD();

    mod->type = v[2];
    mod->content = line;

    // cout << mod->type << "	" << mod->content << endl;
  return mod;
};


int main() {
    // std::ifstream file("idPASide.txt");
    std::ifstream file("test.txt");
     vector<MOD> vMOD;
     vector<MOD*> vMOD2;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // std::cout << line << std::endl;
        //    vMOD.push_back(ParseLine(line));
           vMOD2.push_back(ParseLine2(line));
        }

    cout << "---------------------------------------------------" << endl;
    for (int i = 0; i<vMOD.size(); ++i)
	{
		cout << vMOD[i].type << " , " << vMOD[i].content << endl;
	}

    cout << "=====================================================" << endl;

    for (int i = 0; i<vMOD2.size(); ++i)
	{
		cout << vMOD2[i]->type << "  , " << vMOD2[i]->content << endl;
	}

     file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
    return 0;
}
