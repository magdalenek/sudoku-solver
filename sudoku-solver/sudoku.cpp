#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <stdlib.h>
#include "sudoku.h"
using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++)
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* Function to check whether all positions are occupied by numbers */
bool is_complete(char board[9][9]) {
	for(int r=0; r<9; r++) {
		for(int c=0; c<9; c++)
            if(board[r][c] == '.') {
				return false;
            }
	}
	return true;
}

/* internal helper function to check for out of range*/
bool is_out_of_range(const int row_to_check, const int col_to_check, const char num_to_check){
    if(num_to_check < '1' || num_to_check > '9') {
        return true;
    }
    if((row_to_check < 0 || row_to_check > 8) || (col_to_check <0 || col_to_check > 8)) {
        return true;
    }
    return false;
}
/*internal helper function to check whether there are no two same digits in row, column and 3*3 box*/
bool is_valid(const char board[9][9], int row_to_check, int col_to_check, char digit) {
    for (int i = 0; i <9; i++){
        if(board[row_to_check][i] == digit){
            return false;
        }
    }
    //validating column:
    for(int j=0; j<9; j++){
        if(board[j][col_to_check] == digit) {
            return false;
        }
    }
    //validating 3*3 segment:
    int rowStart = (row_to_check/3)*3;
    int colStart = (col_to_check/3)*3;
    int rowEnd =  rowStart+3;
    int colEnd = colStart+3;

    for(int x = rowStart; x < rowEnd; x++){
        for(int y = colStart; y < colEnd; y++) {
            if(board[x][y] == digit){
                return false;
            }
        }
    }
    return true;
}

/* internal helper function that attempts to place a digit onto a board  */
bool make_move(int row_input, int col_input, const char digit, char board[9][9]) {

    if(board[row_input][col_input] != '.'){
        return false;
    }
    if((is_out_of_range(row_input, col_input, digit)) || (!is_valid(board, row_input, col_input, digit))){
        return false;
    } else {
        board[row_input][col_input] = digit;
        return true;
    }
}

/* Function that attempts to place a digit onto a board */
bool make_move(const char *position, const char digit, char board[9][9]) {

    int row_input = (int) position[0] - 65;
    int col_input = (int) position[1] - 49;

    return make_move(row_input, col_input, digit, board);
}

/* Function to copy the board to a file - AD+
 * D TO MAIN*/
bool save_board(const char *filename, const char board[9][9]) {
	ofstream out;
	out.open(filename);

	for (int r=0; r<9; r++){
		for (int c=0; c<9; c++) {
			if(!out.fail()) {
				out << board[r][c];
			}else {
				return false;
			}
		}
		out << endl;
	}
	return true;
}

/* Function to solve sudoku */
bool solve_board(char board[9][9]){

    if(is_complete(board)){
        return true;
    }

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char digit = '1'; digit <= '9'; digit++) {
                    if (make_move(row, col, digit, board)) {
                        if (solve_board(board)) {
                            return true;
                        }
                        board[row][col] = '.';
                    } else {
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return false;
}

/* Function calculating difficulty level of a puzzle */
bool complexity(char board[9][9], int &count){

    count++;
    if(is_complete(board)){
        return true;
    }

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char digit = '1'; digit <= '9'; digit++) {
                    if (make_move(row, col, digit, board)) {
                        if (complexity(board, count)) {
                            return true;
                        }
                        board[row][col] = '.';
                    } else {
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return false;
}

int solve_as_human(const char board[9][9]){

    int steps = 0;

    //checks whether number can be placed in the box correctly
    for(int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            for(char digit = '1'; digit <= 9; digit++){
                if(is_valid(board, x, y, digit)){
                    int xSegmentStart = (x/3)*3;
                    int ySegmentStart = (y/3)*3;


                }
            }
        }
    }
}