#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argN, char** args) {
	execvp("git",args);
}
