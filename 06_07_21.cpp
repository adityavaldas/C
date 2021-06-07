/*Find a string in a file*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>
using namespace std;

void find_string(string fileName, string stringTerm) {
	transform(stringTerm.begin(), stringTerm.end(), stringTerm.begin(), ::tolower);
	cout << "stringTerm: " << stringTerm << endl;
	int index;
	string line;
	ifstream myFile;
	myFile.open(fileName);
	if (!myFile) {
		cout << "File " << fileName << "does not exist" << endl;
		exit(1);
	}
	while (!myFile.eof()) {
		getline(myFile, line);
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		index = line.find(stringTerm, 0);
		if (index != string::npos) {
			cout << "Found " << stringTerm << " in line " << line << endl;	
		}
	}
	myFile.close();
}
int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "Invalid input/arguments" << endl;
		cout << "Ex: <EXE> <FILE> <STRING>" << endl;
		return 1;
	}
	string myFile = string(argv[1]);
	string stringTerm = string(argv[2]);
	find_string(myFile, stringTerm);
	return 0;
}
