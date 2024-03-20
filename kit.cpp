#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdio>
#include <cstring>

using namespace std;

const string IN_FILE = "/usr/share/kit/kitrc";

string lookup(char** cmd) {
	ifstream file;
	file.open(IN_FILE);
	string str ="I am the very model of a modern major general"; //I just need it to be not "" lol
	int b=0;
	int numVars=0;
	string vars[10]; //if you need more than ten variables what are you doing buddy
	while (str!=""&&(!b)) {
		getline(file,str);
		if(str[0]==':'&&str.substr(1,str.length()-1)==cmd[1]) {
			b=1;
			getline(file,str);
			}
		if(str[0]==';'&&str.substr(1,str.length()-1)==cmd[1]) {
			while(getline(file,str)&&str[0]=='=') {
				if(str[1]=='|') {
					if(cmd[2+numVars]==nullptr)
						vars[numVars]=str.substr(3,str.length()-3);
					else
						vars[numVars]=cmd[2+numVars];
					numVars++;
				}
				if(str[1]=='n') {
					if(cmd[2+numVars]==nullptr) {
						cout << "error: invalid arguments" << endl;
						return "";
					} else
						vars[numVars]=cmd[2+numVars];
					numVars++;
				}
				if(str=="=c dir") {
					string path = "";
					string name=".git";
					while(access(name.c_str(),F_OK)==-1) {
						path="../"+path;
						name=path+".git";
					}
					vars[numVars]=path;
					numVars++;
				}
			}
			b=2;
		}
	}
	if(b==2) {
		for(int i=0,j=0;i<str.length();i++) {
			if(str[i]=='%') {
				str=str.substr(0,i)+vars[j]+str.substr(i+2,str.length()-i);
				j++;
			}
		}


	}
	cout << str << endl;
	if (str!="")
		return str;
	str=cmd[1];
	str="git "+str;
	return str;
}

void help() {
	return;
}

int main(int argN, char** args) {
	if (args[1]==nullptr) {
		cout << "error: argument needed" << endl;
		return 0;
	}
//	cout << lookup(args) << endl;
	system(lookup(args).c_str());
}
