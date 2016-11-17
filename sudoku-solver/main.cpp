#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

    char board[9][9];

    /* This section illustrates the use of the pre-supplied helper functions. */
    cout << "============== Pre-supplied functions ==================" << endl << endl;

    cout << "Calling load_board():" << endl;
    load_board("easy.dat", board);

    cout << endl << "Displaying Sudoku board with display_board():" << endl;
    display_board(board);
    cout << "Done!" << endl << endl;

    
    cout << "====================== Question 1 ======================" << endl << endl;

    load_board("easy.dat", board);
    cout << "Board is ";
    if (!is_complete(board))
        cout << "NOT ";
    cout << "complete." << endl << endl;

    load_board("easy-solution.dat", board);
    cout << "Board is ";
    if (!is_complete(board))
        cout << "NOT ";
    cout << "complete." << endl << endl;

    
    cout << "====================== Question 2 ======================" << endl << endl;

    load_board("easy.dat", board);

    // Should be OK
    cout << "Putting '1' into I8 is ";
    if (!make_move("I8", '1', board))
        cout << "NOT ";
    cout << "a valid move. The board is:" << endl;
    display_board(board);

    // Should not be OK
    cout << "Putting '8' into B3 is ";
    if (!make_move("B3", '8', board))
        cout << "NOT ";
    cout << "a valid move. The board is:" << endl;
    display_board(board);
    
    // Should not be OK
    cout << "Putting '0' into E5 is ";
    if (!make_move("E5", '0', board))
        cout << "NOT ";
    cout << "a valid move. The board is:" << endl;
    display_board(board);
    
    
    cout << "====================== Question 3 ======================" << endl << endl;
    
    load_board("easy.dat", board);
    if (save_board("easy-copy.dat", board))
        cout << "Save board to 'easy-copy.dat' successful." << endl;
    else
        cout << "Save board failed." << endl;
    cout << endl;

    
    cout << "====================== Question 4 ======================" << endl << endl;
    
    load_board("easy.dat", board);
    if (solve_board(board)) {
        cout << "The 'easy' board has a solution:" << endl;
        display_board(board);
    } else
        cout << "A solution cannot be found." << endl;

    load_board("medium.dat", board);
    if (solve_board(board)) {
        cout << "The 'medium' board has a solution:" << endl;
        display_board(board);
    } else
        cout << "A solution cannot be found." << endl;
    
    //Hardest.dat contains the hardest Sudoku puzzle ever created (as argued by )
    load_board("hardest.dat", board);
    if (solve_board(board)) {
        cout << "The 'hardest' board has a solution:" << endl;
        display_board(board);
    } else
        cout << "A solution cannot be found." << endl;
    
    //Empty.dat contains empty sudoku board.
    load_board("empty.dat", board);
    if (solve_board(board)) {
        cout << "The 'empty' board has a solution:" << endl;
        display_board(board);
    } else
        cout << "A solution cannot be found." << endl;

    cout << "====================== Question 5 ======================" << endl << endl;
    
    //Mystery Board 1
    load_board("mystery1.dat", board);
    if (solve_board(board)) {
        cout << "The 'Mystery1' board has a solution:" << endl;
        display_board(board);
    } else
        cout << "A solution cannot be found." << endl;
    int counter1 = 0;
    load_board("mystery1.dat", board);
    complexity(board, counter1);
    cout << "Mystery Board1 had  " << counter1 << " recursive calls." << endl << endl;
    
    //Mystery Board 2
    load_board("mystery2.dat", board);
    if (solve_board(board)) {
        cout << "The 'Mystery2' board has a solution:" << endl;
        display_board(board);
    } else
        cout << "A solution cannot be found." << endl;
    int counter2 = 0;
    load_board("mystery2.dat", board);
    complexity(board, counter2);
    cout << "Mystery Board2 had  " << counter2 << " recursive calls." << endl << endl;
    
    //Mystery Board 3
    load_board("mystery3.dat", board);
    if (solve_board(board)) {
        cout << "The 'Mystery3' board has a solution:" << endl;
        display_board(board);
    } else
        cout << "A solution cannot be found." << endl;
    int counter3 = 0;
    load_board("mystery3.dat", board);
    complexity(board, counter3);
    cout << "Mystery Board3 had  " << counter3 << " recursive calls." << endl << endl;
    
    //Easy Board
    int counter4 = 0;
    load_board("easy.dat", board);
    complexity(board, counter4);
    cout << "Easy board had  " << counter4 << " recursive calls." << endl << endl;
    
    //Medium Board
    int counter5 = 0;
    load_board("medium.dat", board);
    complexity(board, counter5);
    cout << "Medium board had  " << counter5 << " recursive calls." << endl << endl;
    
    
    return 0;
}
