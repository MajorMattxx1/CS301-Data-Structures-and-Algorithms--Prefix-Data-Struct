// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@S@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@       @                     @         @     @             @         @
@ @@@ @ @ @@@@@@@ @@@@@ @@@@@ @ @@@@@@@@@ @ @@@ @ @@@ @@@@@@@ @@@@@ @@@
@   @ @ @ @     @ @   @     @   @         @     @   @ @       @   @   @
@ @@@ @ @@@ @@@ @ @ @ @@@@@ @@@@@ @@@@@@@@@@@@@@@ @ @ @ @@@@@@@@@ @@@ @
@ @   @     @   @ @ @       @             @     @ @ @ @   @     @   @ @
@@@ @@@@@@@@@ @@@@@ @@@@@@@@@ @@@@@@@@@@@@@ @@@ @ @ @@@@@ @@@ @ @ @ @ @
@ @       @ @ @     @       @   @   @       @ @ @ @           @   @ @ @
@ @@@@@@@ @ @ @@@ @@@ @@@@@ @@@ @ @ @ @@@@@@@ @ @@@@@@@ @@@@@@@@@@@@@ @
@       @ @ @   @         @     @ @   @   @     @     @ @     @   @   @
@@@@@@@ @ @ @@@ @@@@@@@@@@@@@@@@@ @@@@@ @@@ @@@@@ @@@ @@@ @@@ @ @ @ @ @
@         @                       @               @       @     @   @ @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@F@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/

#define MAX_ROW 100
#define MAX_COL 100

void solveMaze(int r, int c, char map[MAX_ROW][MAX_COL], int w, int h, string path, bool& done) {

	if (done)
		return;

	if (r < 0 || c < 0 ||
		r >= h || c >= w) {
		return;
	}

	if (map[r][c] == 'F') {
		done = true;
		return;
	}

	if (map[r][c] == '.' || map[r][c] == '@') {
		return;
	}


	map[r][c] = '.';

	solveMaze(r - 1, c, map, w, h, path + "U", done);
	solveMaze(r + 1, c, map, w, h, path + "D", done);
	solveMaze(r, c - 1, map, w, h, path + "L", done);
	solveMaze(r, c + 1, map, w, h, path + "R", done);

	if (!done)
		map[r][c] = ' ';
}

int main()
{
	char map[MAX_ROW][MAX_COL];

	ifstream mazeFile("maze.txt");

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