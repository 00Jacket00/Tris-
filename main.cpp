#include <iostream>

using namespace std;

void printBoard(char[3][3], int, int);
int getRow(void);
int getCol(void);
void playerOMove(char array[][3]);
void playerXMove(char array[][3]);
bool checkOWin(char array[][3]);
bool checkXWin(char array[][3]);

int main ()
{	
	// Named constants for array dimensions
	const int ROWS = 3;
	const int COLUMNS = 3;
	
	// Initialize Board
	char board[ROWS][COLUMNS] = {{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'}};
	
	bool isWinner = false;
	int counter = 0;
	printBoard(board, ROWS, COLUMNS);
	
	do {
		
		// Allow player X to move, check if X wins, and print the board
		playerXMove(board);
		isWinner = checkXWin(board);
		// If X wins, print the board and exit loop
		if (isWinner) { printBoard(board, ROWS, COLUMNS); break; }
		printBoard(board, ROWS, COLUMNS);
		
		// only player X gets to move on last iteration. board should then be full
		if (counter < 4) {
			// Allow player O to move, check if O wins, and print the board
			playerOMove(board);
			isWinner = checkOWin(board);
			// If O wins, print the board and exit loop
			if (isWinner) { printBoard(board, ROWS, COLUMNS); break; }
			printBoard(board, ROWS, COLUMNS);
		}
		
		counter++;
	} while (counter < 5);
	
	if (!isWinner) cout << "Tie! No Winner, Great Game!" << endl;
	
	return 0;
}

bool checkXWin(char array[][3])
{
	bool winner = false;
	if ( array[0][0] + array[0][1] + array[0][2] == 264
			|| array[1][0] + array[1][1] + array[1][2] == 264
			|| array[2][0] + array[2][1] + array[2][2] == 264
			|| array[0][0] + array[1][0] + array[2][0] == 264
			|| array[0][1] + array[1][1] + array[2][1] == 264
			|| array[0][2] + array[1][2] + array[2][2] == 264
			|| array[0][0] + array[1][1] + array[2][2] == 264
			|| array[0][2] + array[1][1] + array[2][0] == 264 )
		winner = true;
	if (winner) cout << "Player X Wins!\nGreat Job!" << endl;
	return winner;
}

bool checkOWin(char array[][3])
{
	bool winner = false;
	if ( array[0][0] + array[0][1] + array[0][2] == 237
			|| array[1][0] + array[1][1] + array[1][2] == 237
			|| array[2][0] + array[2][1] + array[2][2] == 237
			|| array[0][0] + array[1][0] + array[2][0] == 237
			|| array[0][1] + array[1][1] + array[2][1] == 237
			|| array[0][2] + array[1][2] + array[2][2] == 237
			|| array[0][0] + array[1][1] + array[2][2] == 237
			|| array[0][2] + array[1][1] + array[2][0] == 237 )
		winner = true;
	if (winner) cout << "Player O Wins!\nGreat Job!" << endl;
	return winner;
}

// Asks user to input what row for move
int getRow(void)
{
	int row;
	
	do {
		cout << "What row to make move?" << endl;
		cin >> row;
		// check for valid input
		if (row > 2 || row < 0) cout << "Incorrect row, please choose between 0, 1, or 2." << endl;
	} while (row > 2 || row < 0);
	
	return row;
}

// Asks user to input what column for move
int getCol(void)
{
	int col;
	
	do {
		cout << "What column to make move?" << endl;
		cin >> col;
		// check for valid input
		if (col > 2 || col < 0) cout << "Incorrect column, please choose between 0, 1, or 2." << endl;
	} while (col > 2 || col < 0);
	
	return col;
}

// Allows Player 'X' to move
void playerXMove(char array[][3])
{
	while (true) {
		cout << "Pleyer X's turn" << endl;
		int row = getRow();
		int col = getCol();
		// check if space is taken
		if (array[row][col] == '-') { array[row][col] = 'X'; break; }
		cout << "Space already occupied, please select another." << endl;
	}
}

// Allows Player 'O' to make a move
void playerOMove(char array[][3])
{
	while (true) {
		cout << "Pleyer O's turn" << endl;
		int row = getRow();
		int col = getCol();
		// check if space is taken
		if (array[row][col] == '-') { array[row][col] = 'O'; break; }
		cout << "Space already occupied, please select another." << endl;
	}
}

// Function to print boad at whatever state it is in
void printBoard(char array[][3], int rows, int cols)
{
	cout << "Heres the board:" << endl;
	
	for (int i =0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}
}