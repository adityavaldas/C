/*Find the array element having minimum sum of absolute differences 
with all other array elements*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> getArrayFromInput() {
	string inputString;
	int temp;
	vector<int> tt;
	cout << "Enter elements of array, space separated: ";
	getline(cin, inputString);
	stringstream ss(inputString);
	while (ss >> temp) {
		tt.push_back(temp);
	}
	return tt;
}
void printVector(vector<int> arr, string strr) {
	cout << strr << ": ";
	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;
}
int findAbsDiff(int a, int b) {
	return abs(a - b);
}
int sumOfAbsDiff(int i, vector<int> inputArray) {
	int j, sum = 0;
	for (j = 0; j < inputArray.size(); j++) {
		sum += findAbsDiff(inputArray[i], inputArray[j]);
	}
	return sum;
}
int findMinOfVector(vector<int> vec) {
	int min = vec[0];
	for (int i = 0; i < vec.size(); i++) {
		if (min > vec[i]) min = vec[i];
	}
	return min;
}

int main()
{
	int temp, i, min;
	vector<int> inputArray, outputArray;
	inputArray = getArrayFromInput();
	for (i = 0; i < inputArray.size(); i++) {
		outputArray.push_back(sumOfAbsDiff(i, inputArray));
	}
	printVector(outputArray, "outputArray");
	min = findMinOfVector(outputArray);
	cout << "min: " << min << endl;
	return 0;
}
