#include <iostream>
#include <fstream>
#include <unistd.h>
#include <unordered_map>
#include <cstdio>
#include <cstring>

using namespace std;

const string IN_FILE = "kitrc";

string lookup(char* cmd) {
	ifstream file;
	file.open(IN_FILE);
	string str;
	bool b=1;
	while (getline(file,str)&&b) {
		if(str[0]==':'&&str.substr(1,str.length()-1)==cmd)
			b=0;
	}
	str="git "+str;
	return str;
}



int main(int argN, char** args) {
	if (args[1]==nullptr) {
		cout << "error: argument needed" << endl;
		return 0;
	}
	system(lookup(args[1]).c_str());
}
