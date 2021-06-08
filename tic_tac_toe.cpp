/*TicTacToe*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

class Game {
public:
	int board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
	char referenceDict[3] = { ' ', 'x', 'o'};
	unordered_map<char, string> hashMap;

	int refMap[10][2] = { {10,10}, {2,0}, {2,1}, {2,2}, {1,0}, {1,1}, {1,2}, {0,0}, {0,1}, {0,2} };
	int runGame() {
		char temp;
		cout << "Starting game" << endl;
		while (true){
			printBoard();
			if (isWonGame()) {
				break;
			}
			if (isBoardFilled()) {
				cout << "Result: Draw" << endl;
				break;
			}
			/*input from player*/
			while (true){
				cout << "Enter input: ";
				cin >> temp;
				if (temp == 'q' or temp == 'Q') {
					cout << "Forfeiting" << endl;
					return 0;
				}
				if (updateBoard(temp)) {
					printBoard();
					break;
				}
				else {
					cout << "Invalid input" << endl;
				}
			}
			/*Computer Logic*/
			computerLogic();
		}
	}

private:
	void printBoard() {
		cout << referenceDict[board[0][0]] << " | " << referenceDict[board[0][1]] << " | " 
			<< referenceDict[board[0][2]] << endl;
		cout << "--+---+--" << endl;
		cout << referenceDict[board[1][0]] << " | " << referenceDict[board[1][1]] << " | "
			<< referenceDict[board[1][2]] << endl;
		cout << "--+---+--" << endl;
		cout << referenceDict[board[2][0]] << " | " << referenceDict[board[2][1]] << " | "
			<< referenceDict[board[2][2]] << endl;
		cout << endl;
	}
	bool isBoardFilled() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 0){
					return false;
				}
			}
		}
		return true;
	}
	bool isWonGame() {
		for (int i = 0; i < 3; i++) {
			if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) &&
				(board[i][0] == 1 || board[i][0] == 2)) {
				cout << "row " << i << endl;
				cout << referenceDict[board[i][0]] << " won";
				return true;
			}
		}

		for (int i = 0; i < 3; i++) {
			if ((board[0][i] == board[1][i] && board[0][i] == board[2][i]) &&
				(board[0][i] == 1 || board[0][i] == 2)) {
				cout << "column " << i << endl;
				cout << referenceDict[board[0][i]] << " won";
				return true;
			}
		}

		if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) &&
			(board[0][0] == 1 || board[0][0] == 2)) {
			cout << "diag 1" << endl;
			cout << referenceDict[board[0][0]] << " won";
			return true;
		}

		if ((board[0][2] == board[1][1] && board[0][2] == board[2][0]) &&
			(board[0][2] == 1 || board[0][2] == 2)) {
			cout << "diag 2" << endl;
			cout << referenceDict[board[0][2]] << " won";
			return true;
		}

		return false;
	}
	bool updateBoard(char temp) {
		//cout << "Updating board" << endl;
		if (isdigit(temp)) {
			int intTemp = temp - '0';
			cout << "intTemp: " << intTemp << endl;
			cout << refMap[intTemp][0] << ", " << refMap[intTemp][1] << endl;
			int row = refMap[intTemp][0];
			int col = refMap[intTemp][1];
			cout << "row, col: " << row << ", " << col << endl;
			if (board[row][col] == 0) {
				board[row][col] = 1;
				return true;
			}
		}
		return false;
	}
	void FillCell(int intTemp) {
		int row = refMap[intTemp][0];
		int col = refMap[intTemp][1];
		cout << "row, col: " << row << ", " << col << endl;
		board[row][col] = 2;
	}
	int getCell(int cell) {
		int row = refMap[cell][0];
		int col = refMap[cell][1];
		return board[row][col];
	}
	int computerLogic() {
		cout << "Computer playing" << endl;
		if (compWinningMove()) {
			return 0;
		}
		if (compSavingMove()) {
			return 0;
		}
		if (compCenterFill()) {
			return 0;
		}
		if (compCornerFill()) {
			return 0;
		}
	}
	int compWinningMove() {
		cout << "Looking for winning move" << endl;
		//Row
		for (int i = 0; i < 3; i++) {
			int count = 0;
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 2) {
					count += 1;
				}
			}
			if (count == 2) {
				for (int j = 0; j < 3; j++) {
					if (board[i][j] == 0) {
						board[i][j] = 2;
						return true;
					}
				}
			}
		}
		//Column
		for (int i = 0; i < 3; i++) {
			int count = 0;
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == 2) {
					count += 1;
				}
			}
			if (count == 2) {
				for (int j = 0; j < 3; j++) {
					if (board[j][i] == 0) {
						board[j][i] = 2;
						return true;
					}
				}
			}
		}
		//Diag1
		int count = 0;
		for (int i = 0; i < 3; i++) {
			if (board[i][i] == 2) {
				count += 1;
			}
		}
		if (count == 2) {
			for (int i = 0; i < 3; i++) {
				if (board[i][i] == 0) {
					board[i][i] = 2;
					return true;
				}
			}
		}
		//Diag2
		count = 0;
		for (int i = 0; i < 3; i++) {
			if (board[i][2-i] == 2) {
				count += 1;
			}
		}
		if (count == 2) {
			for (int i = 0; i < 3; i++) {
				if (board[i][2-i] == 0) {
					board[i][2-i] = 2;
					return true;
				}
			}
		}
		return false;
	}
	int compSavingMove() {
		cout << "Looking for saving move" << endl;
		//Row
		for (int i = 0; i < 3; i++) {
			int count = 0;
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 1) {
					count += 1;
				}
			}
			if (count == 2) {
				for (int j = 0; j < 3; j++) {
					if (board[i][j] == 0) {
						board[i][j] = 2;
						return true;
					}
				}
			}
		}
		//Column
		for (int i = 0; i < 3; i++) {
			int count = 0;
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == 1) {
					count += 1;
				}
			}
			if (count == 2) {
				for (int j = 0; j < 3; j++) {
					if (board[j][i] == 0) {
						board[j][i] = 2;
						return true;
					}
				}
			}
		}
		//Diag1
		int count = 0;
		for (int i = 0; i < 3; i++) {
			if (board[i][i] == 1) {
				count += 1;
			}
		}
		if (count == 2) {
			for (int i = 0; i < 3; i++) {
				if (board[i][i] == 0) {
					board[i][i] = 2;
					return true;
				}
			}
		}
		//Diag2
		count = 0;
		for (int i = 0; i < 3; i++) {
			if (board[i][2 - i] == 1) {
				count += 1;
			}
		}
		if (count == 2) {
			for (int i = 0; i < 3; i++) {
				if (board[i][2 - i] == 0) {
					board[i][2 - i] = 2;
					return true;
				}
			}
		}
		return false;
	}
	int compCenterFill() {
		cout << "Comp trying center fill" << endl;
		if (board[1][1] == 0) {
			board[1][1] = 2;
			return true;
		}
		return false;
	}
	int compCornerFill() {
		cout << "Comp trying corner fill" << endl;
		int cornerCoor[4][2] = { {0,0}, {0,2}, {2,0}, {2,2} };
		for (int i = 0; i < 4; i++) {
			if (board[cornerCoor[i][0]][cornerCoor[i][1]] == 0) {
				board[cornerCoor[i][0]][cornerCoor[i][1]] = 2;
				//cout << "Comp inserting in " << cornerCoor[i][0] << ", " << cornerCoor[i][1] << endl;
				return true;
			}
		}
		return false;
	}
};

int main() {
	Game game;
	game.runGame();
	return 0;
}