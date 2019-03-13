// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

void disp_board(char board[10][10],int x,int y) {
	int i, j;
	int r_bl,c_bl;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			board[i][j] = '#';
			if ((i == x) && (j == y)) {
				board[i][j] = ' ';
				r_bl = rand() % 5;
				c_bl = rand() % 5;
				for (int a = 0; a < r_bl; a++)
					for(int b = 0; b < c_bl; b++)
						board[a][b] = ' ';
			}
			else if ((i == (-1)) && (j == (-1))) {
				board[i][j] = '#';
			}
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			cout <<" "<< board[i][j]<<" ";
		}
		cout << endl;
	}	
}


int main() {

	srand(time(0));
	char board[10][10];
	int r=(-1), c=(-1);
	while(1) {
		system("CLS");
		disp_board(board, r, c);
		cin >> r;
		cin >> c;
	} 

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
