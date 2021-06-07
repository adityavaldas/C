/*Count strings having sum of ASCII values of characters equal to a Prime No.*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void printVector(vector<string> arr) {
	string outStr = "";
	for (auto x : arr) {
		outStr = outStr + x + ", ";
	}
	outStr = outStr.substr(0, outStr.length() - 2);
	cout << outStr << endl;
}

bool isPrime(int num) {
	bool notPrime = false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			notPrime = true;
			break;
		}
	}
	if (notPrime) {
		return false;
	}
	return true;
}
int countPrime(vector<string> inputVector) {
	int primeCount = 0;
	for (auto word:inputVector) {
		//cout << "Checking for word: " << word << endl;;
		int val = 0;
		for (auto character:word) {
			val += character;
		}
		//cout << "ASCII Value: " << val << endl;
		if (isPrime(val)) {
			cout << "Found prime for word: " << word << ", value:  " << val << endl;;
			primeCount += 1;
		}
	}
	return primeCount;
}

int main() {
	string inputString, tempString;
	vector<string> inputVector;
	cout << "Enter list of words space-separated: ";
	getline(cin, inputString);
	stringstream ss(inputString);
	while (ss >> tempString) {
		inputVector.push_back(tempString);
	}
	int primeCount = countPrime(inputVector);
	cout << "prime count: " << primeCount << endl;
	return 0;
}