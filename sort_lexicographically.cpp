/*Normal Distribution*/

#include <iostream>
#include <string>
#include <fstream>
#include<unordered_map>
#include <ctime>

using namespace std;

class SortLexi {
public:
	//vector<string> stringsVector = { "John Doe", "John Twain",
		//"John", "Johny", "Johny Doe", "Joeny doe rrr" };
vector<string> stringsVector = {};
	void Run() {
		populateVector();
		sortElem();
	}
private:
	void printVector(vector<string> arr) {
		//cout << strr << ": ";
		string strr;
		strr = "Vector: ";
		for (auto x : arr) {
			//cout << x << ", ";
			strr = strr + x + ", ";
		}
		strr = strr.substr(0, strr.length() - 2);
		cout << strr << endl;
	}
	bool needToSwap(string a, string b) {
		if (a > b) {
			return true;
		}
		return false;
	}
	void swapElem(int i, int j) {
		string tempStr;
		tempStr = stringsVector[j];
		stringsVector[j] = stringsVector[i];
		stringsVector[i] = tempStr;
	}
	void sortElem() {
		printVector(stringsVector);
		const int vectorSize = stringsVector.size();
		while (true) {
			bool somethingSwapped = false;
			for (int i = 0; i < vectorSize - 1; i++) {
				for (int j = i+1; j < vectorSize; j++) {
					if (needToSwap(stringsVector[i], stringsVector[j])) {
						//cout << "Swapping " << i << ", " << j << endl;
						swapElem(i, j);

						somethingSwapped = true;
					}
				}
			}
			if (!somethingSwapped) {
				break;
			}
		}
		printVector(stringsVector);
	};
	void populateVector() {
		int N;
		string inputString;
		cout << "Number of strings: ";
		cin >> N;
		cin.ignore();
		for (int i = 0; i < N; i++) {
			getline(cin, inputString);
			stringsVector.push_back(inputString);
		}
	}
};
int main() {
	SortLexi inst;
	inst.Run();

	return 0;
}
