/*Minimum number of bricks that can be intersected*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> getArrayFromInput() {
	string inputString;
	int temp;
	vector<int> tt;
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

int main()
{
	int i, min, noOfRows = 6, maxOcc = 0;
	vector<vector<int>> wall;
	unordered_map<int, int> hashMap;
	cout << "Enter number of rows in wall: ";
	cin >> noOfRows;
	cin.ignore();
	for (i = 0; i < noOfRows; i++) {
		cout << "Bricks for wall row " << i + 1 << ": ";
		wall.push_back(getArrayFromInput());
	}
	//wall = { {1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1} };
	/*for (i = 0; i < noOfRows; i++) {
		printVector(wall[i], "Vector");
	}*/
	for (auto x : wall) {
		int no = 0;
		//cout << "New Row" << endl;
		for (int y = 0; y < x.size() - 1; y++) {
			//cout << "Brick: " << x[y] << endl;
			no += x[y];
			//cout << "Sum: " << no << endl;
			if (hashMap.find(no) != hashMap.end()) {
				//cout << "Found:" << no << endl;
				hashMap[no] += 1;
			}
			else {
				hashMap[no] = 1;
			}
			//cout << "Occurences of number in hashmap: " << hashMap[no] << endl;
			maxOcc = max(maxOcc, hashMap[no]);
		}
	}
	//cout << "Max occ: " << maxOcc << endl;	
	cout << "Minimum no. of bricks that can be intersected: " <<  wall.size() - maxOcc << endl;

	return 0;
}
