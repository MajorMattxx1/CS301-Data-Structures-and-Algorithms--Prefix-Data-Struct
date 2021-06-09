

#include "pch.h"
#include <iostream>

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//these numbers are based on the Boggle board mentioned in the instructions
#define MAX_ROW 4
#define MAX_COL 4

//this is a modified solveMaze
/*paramaters are row and column to start, current step(WIP), a string storing progress
the board(is that map?)(WIP),a dictionary to determine if found word(WIP), way to remember visited spaces,
and way to remember found words*/
void SearchForWord(int r, int c, char map[MAX_ROW][MAX_COL], string path, dict foundWordsBool, /*way to remember visited space*/, dict foundWords, bool& done)
{

	if (done)
		return;


	if (r < 0 || c < 0 ||
		r >= h || c >= w) {
		return;
	}

	//as searchForWord is not trying to solve a maze, this is not needed
	/*
	if (map[r][c] == 'F') {
		done = true;
		return;
	}*/
	//maybe this is of use?
	if (map[r][c] == '0') {
		return;
	}

	//counter to update tep board as we go
	int counter = 0;
	map[r][c] = ++counter;

	//this needs heavy modification
	solveMaze(r - 1, c, map, w, h, path + "U", done);
	solveMaze(r + 1, c, map, w, h, path + "D", done);
	solveMaze(r, c - 1, map, w, h, path + "L", done);
	solveMaze(r, c + 1, map, w, h, path + "R", done);

	//this bit may be unneeded
	/*
	if (!done)
		map[r][c] = ' ';
		*/
}

int main()
{
	char map[MAX_ROW][MAX_COL];

	//not needed
	//ifstream mazeFile("maze.txt");

	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++) {
			map[i][j] = ' ';
		}
	int row = 0;

	int startRow, startCol, finalRow, finalCol;

	// Read the file line by line an initialize the maze
	string line;
	while (getline(mazeFile, line)) {
		//cout << line << endl;
		for (int i = 0; i < (int)line.length(); i++) {
			map[row][i] = line[i];
			if (map[row][i] == 'S' || map[row][i] == 'P') {
				startRow = row;
				startCol = i;
				map[row][i] = ' ';
			}
			else if (map[row][i] == 'F') {
				finalRow = row;
				finalCol = i;
			}
		}
		row++;
	}

	cout << "Start Position: (" << startRow << "," << startCol << ")" << endl;

	// figure out the number of rows and columns
	int height = row;
	int width = line.length();

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	bool done = false;
	solveMaze(startRow, startCol, map, width, height, "", done);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}


