#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
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
			if(!board[r][c] == '.')
				return false;
	}
	return true;
}

/* internal helper method to check whether digit to be placed on the board is out of range */
bool is_out_of_range(const int row_to_check, const int col_to_check, const int num_to_check){
    if((num_to_check < 1 || num_to_check > 9) || (row_to_check < 0 || row_to_check > 8) || (col_to_check <0 || col_to_check > 8)) {
        return false;
    }
    return true;
}

//internal helper method validating whether each row, col and 3*3 section of the board do not have the same
bool is_valid() {
    if (!validate_row && !validate_column && (!validate_section())) {
        return false
    }
    return true;
}


//Helper function validating whether there is no the same value present in a row WORKS
bool validate_row(const char board[9][9], const int y, const int digit){
    for (int i = 0; i <=8; i++){
        if(board[y][row] == digit)
            return false;
    }
    return true;
}

//Helper function validating whether there is no the same value present in a column WORKS
bool validate_column(const char board[9][9], const int k, const int digit){
    for(int j=0; j<=8; j++){
        if(board[j][k] == digit)
            return false;
    }
    return true;
}

//Helper function validating whether the is no same value present in the 3*3 box
bool validate_section(const char board[9][9], const int row_to_check, const int col_to_check) {
    int row = (row_to_check/3)*3;
    int col = (col_to_check/3)*3;
    
    for(row; row < row+3; row++){
        for(col; col < col+3; col++)
            if((row=!row_to_check) && (col!=col_to_check) && board[row][col])
                return false;   //false if all 3 are not correct
    }
    return true;
}

*/

/* function that attempts to place a digit onto a board */
bool make_move(const char *position, const char digit, char board[9][9]) {
	
    //converting the characters into 1-9 integers:
    int row_input = (int) position[0] - 65;
	int col_input = (int) position[1] - 49;
    int num_input = (int) digit - 48;
    
    int row = (row_input/3)*3;
    cout << "Row: " << row_input << endl; //correct row
    cout << "Col input: " << col_input <<endl; //correct col
    cout << "Num: " << num_input << endl; //correct digit
    cout << "(row_input/3)*3 " << row << endl; // 0 - correct
        
   
    /* is_out_of_range is correct
    if((!is_out_of_range(row_input, col_input, num_input)) || (!is_valid(board, row_input, col_input, num_input))){
        cout << "Hello2" << endl;
        cout <<num_input << endl;
        return false;
    } else {
     */
        cout << endl << "make_move: board[row_input][col_input] " << board[row_input][col_input] <<endl;
        cout << "num_input: " << num_input <<endl;
            board[row_input][col_input] = num_input; //does not work
        cout << endl << "new board[row_input][col_input]: " << board[row_input][col_input] <<endl; //it is empty!!
        cout << "new num_input: " << num_input <<endl;
    
    return true;
}





/* Function to copy the board to a file */
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