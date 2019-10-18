//
//  main.cpp
//  Lab_04
//
//  Created by Andrew Ma on 2019-10-15.
//  Copyright © 2019 Andrew Ma. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <array>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 4;

void display_board(int board [][4], int ARRAY_SIZE);
//PURPOSE: prints out the current state of the board
//  INPUTS: board - multidimensional array that contains game board
//          array_size - the size of the first dimension of the array
//  RETURNS: nothing to return

bool line_completed(int board [][4], int ARRAY_SIZE, int& scoreX, int& scoreO);
//PURPOSE: Checks if there are straight lines made across the tic tac toe board.
//  INPUTS: board - multidimensional array that contains game board
//          array_size - max size of the array
//  RETURNS: True or false value of whether somebody has won the game yet

bool full_board(int board [][4], int ARRAY_SIZE, int& ties);
//PURPOSE: Checks if the board is full
//  INPUTS: board - multidimensional array that contains game board
//          array_size - max size of the array
//  RETURNS: True or false value of whether somebody has won the game yet

bool play_again(int board [][4], int ARRAY_SIZE);
//PURPOSE: asks player if they want to play again and resets the board if players want to play again
//  INPUTS: score_O - number of games that player controlling the O board has won
//          score_X - number of games that player controlling X has won
//  RETURNS: true or false value of whether the people want to play the game again

bool run_tic_tac_toe();
//PURPOSE: Runs the game of tic-tac-toe
//  INPUTS: nothing to input
//  RETURNS: true or false value of whether the game ran correctly

bool position_chosen(int board [][4], int ARRAY_SIZE, int counter, int position_chosen);
//PURPOSE: Allows user to input a symbol into chosen value of board
//  INPUTS: board - multidimensional array that contains game board
//          array_size - max size of the array
//          symbol - the move that
//  RETURNS: whether a postion has been chosen yet



int main() {
    //Initialize variables
    if(run_tic_tac_toe()){
        cout << "The game has run successfully!\n";
    }
    return 0;
    
}

void display_board(int board [][4], int ARRAY_SIZE){
    // [SETUP] step1. initialize corresponding variables
    int index1, index2;
    
    //[INPUT] step2. no input handling.
    
    //[PROCESSING] step3. prints out value within the array.
    for (index1 = 0; index1 < ARRAY_SIZE; ++index1){
        for(index2 = 0; index2 < ARRAY_SIZE; ++index2) {
            if(board [index1][index2] == 79 ){
                char o = board [index1][index2];
                cout << o << " ";
            } else if(board [index1][index2] == 88 ) {
                char x = board [index1][index2];
                cout << x << " ";
            } else {
                cout << board [index1][index2] << " ";
            }
        }
        cout << endl;
    }
}

bool line_completed(int board [][4], int ARRAY_SIZE, int& scoreX, int& scoreO){
    //O as an int == 79
    //X as an int == 88
    //[SETUP] step1. initialize corresponding variables
    int i = 0;
    int index1 = 0;
    int index2 = 0;
    bool continuous = true;
    
    //checks if the line is running diagonally from the left corner
    //[PROCESSING] step3.1. determines whether there is straight line running from top left corner
    for (i = 0; i<3; ++i) {
        if (board[index1][index2] == board[index1 + 1][index2 + 1]){
            index1++;
            index2++;
        } else{
            continuous = false;
        }
    }
    
    //increments score and ends function if X or O has diagonal line
    if(continuous && board[index1 - 1][index2 - 1] == 79){
        scoreO++;
        cout << "O is the winner! Congratulations!\n";
        return true;
    } else if(continuous && board[index1 - 1][index2 - 1] == 88){
        scoreX++;
        cout << "X is the winner! Congratulations!\n";
        return true;
    }
    
    //step 3.2. determines whether any horizontal lines have 4 straight equivalent symbols
    for (index1 = 0; index1 < 4; ++index1){
        //resets assumption of continuous line to true
        continuous = true;
        
        //checks for horizontal line
        for(index2 = 0; index2 < 3; ++index2){
            if ((board[index1][index2] != board[index1][index2 + 1])){
                continuous = false;
            }
        }
        
        //increments score and ends function if horizontal line found
        if(continuous && board[index1][index2 - 1] == 79){
            scoreO++;
            cout << "O is the winner! Congratulations!\n";
            return true;
        } else if(continuous && board[index1][index2 - 1] == 88){
            scoreX++;
            cout << "X is the winner! Congratulations!\n";
            return true;
        }
    }
    
    //step 3.3. determines whether any vertical lines have 4 straight equivalent symbols
    for (index2 = 0; index2 < 4; ++index2){
        //resets assumption of continuous line to true
        continuous = true;
        
        //goes through values in vertical line to check if they're equal
        for(index1 = 0; index1 < 3; ++index1){
            if (board[index1][index2] != board[index1 + 1][index2]){
                continuous = false;
            }
        }
        
        //increments score and ends function if horizontal line found
        if(continuous && board[index1 - 1][index2] == 79){
            scoreO++;
            cout << "O is the winner! Congratulations!\n";
            return true;
        } else if(continuous && board[index1 - 1][index2] == 88){
            scoreX++;
            cout << "X is the winner! Congratulations!\n";
            return true;
        }
    }
    
    continuous = true;
    index1 = 0;
    index2 = 3;
    
    //checks if there is a diagonal line going from upper right hand corner
    for (i = 0; i<3; ++i) {
        if (board[0][3] == board[index1 + 1][index2 - 1]){
            index1++;
            index2--;
        } else{
            continuous = false;
        }
    }
    
    //increments score and ends function if X or O has diagonal line
    if(continuous && board[index1 - 1][index2 + 1] == 79){
        scoreO++;
        cout << "O is the winner! Congratulations!\n";
        return true;
    } else if(continuous && board[index1 - 1][index2 + 1] == 88){
        scoreX++;
        cout << "X is the winner! Congratulations!\n";
        return true;
    }
    return false;
}

bool full_board(int board [][4], int ARRAY_SIZE, int& ties) {
    int index1 = 0;
    int index2 = 0;
    
    for(index1 = 0; index1 < ARRAY_SIZE; ++index1 ){
        for(index2 = 0; index2 < ARRAY_SIZE; ++index2){
            if(board[index1][index2] != 79 && board[index1][index2] != 88){
                return false;
            }
        }
    }
    cout << "It's a tie! No winner this time.\n";
    ties++;
    return true;
}

bool play_again(int board [][4], int ARRAY_SIZE){
    bool invalid_input = true;
    char entered_char = '\0';
    int index1 = 0;
    int index2 = 0;
    int assigned_value = 1;
    
    while(invalid_input){
        cout << "Would you like to play again? type in y for yes and n for no. \n";
        cin >> entered_char;
        if(entered_char == 'y' || entered_char == 'n'){
            invalid_input = false;
        } else {
            cout << "please enter a valid input of y or n. \n";
        }
    }
    
    //resets the board if player says yes, returns false is player says no.
    if(entered_char == 'y'){
        for (index1 = 0; index1 < ARRAY_SIZE; ++index1){
            for(index2 = 0; index2 < ARRAY_SIZE; ++index2){
                board [index1][index2] = assigned_value;
                assigned_value++;
            }
        }
        return true;
    } else{
        return false;
    }
}

bool run_tic_tac_toe(){
    //Initializes variables
    int board[4][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int move_counter = 0;
    int game_starter = 0;
    int position = 0;
    int score_x = 0;
    int score_o = 0;
    int ties = 0;
    string player_x = "Player X";
    string player_o = "Player O";
    bool run_game = true;
    bool valid_input = true;
    
    //Prints an introductory message
    cout << "Welcome to Tic Tac Toe! \n";
    cout << endl;
    
    //runs the game
    do{
        display_board(board, ARRAY_SIZE);
        if(move_counter % 2 == 0){
            do{
                cout << player_x << " please choose a number displayed on the board to place your X\n";
                cin >> position;
                valid_input = position_chosen(board, ARRAY_SIZE, move_counter, position);
            } while (!valid_input);
            
        } else if (move_counter % 2 == 1){
            do{
                cout << player_o << " please choose a number displayed on the board to place your O\n";
                cin >> position;
                valid_input = position_chosen(board, ARRAY_SIZE, move_counter, position);
            } while (!valid_input);
            
        }
        //changes who is playing
        move_counter++;
        
        //checks if the game is finished, if finished it will stop
        if (full_board(board, ARRAY_SIZE, ties) || line_completed(board, ARRAY_SIZE, score_x, score_o)){
            run_game = play_again(board, ARRAY_SIZE);
            
            //changes who starts each game
            game_starter++;
            move_counter = game_starter;
        }
        
        
        
    } while (run_game);
    
    cout << setw(20) << "\t" << " " << player_x << setw(20) << player_o << endl;
    cout << "Wins" << setw(20) << score_x << setw(20) << score_o << endl;
    cout << endl;
    cout << "Ties: " << ties << endl;
    return true;
}

bool position_chosen(int board [][4], int ARRAY_SIZE, int counter, int position_chosen){
    int symbol;
    
    //processes input, depending on the turn game is on
    if(counter % 2 == 1){
        symbol = 79;
    } else {
        symbol = 88;
    }
    
    if(position_chosen <= 0 || position_chosen > 16){
        cout << "Please choose a value between 1 and 16\n";
        return false;
    }
    
    //Checks if the space is occupied first, then assigns value of array index to a symbol
    switch(position_chosen){
        case 1:
            if(board [0][0] == 79 || board [0][0] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[0][0] = symbol;
                return true;
            }
            break;
    
        case 2:
            if(board [0][1] == 79 || board [0][1] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[0][1] = symbol;
                return true;
            }
            break;
            
        case 3:
            if(board [0][2] == 79 || board [0][2] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[0][2] = symbol;
                return true;
            }
            break;
        
        case 4:
            if(board [0][3] == 79 || board [0][3] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[0][3] = symbol;
                return true;
            }
            break;
        
        case 5:
            if(board [1][0] == 79 || board [1][0] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[1][0] = symbol;
                return true;
            }
            break;
        
        case 6:
            if(board [1][1] == 79 || board [1][1] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[1][1] = symbol;
                return true;
            }
            break;
        
        case 7:
            if(board [1][2] == 79 || board [1][2] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[1][2] = symbol;
                return true;
            }
            break;
            
        case 8:
            if(board [1][3] == 79 || board [1][3] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[1][3] = symbol;
                return true;
            }
            break;
        
        case 9:
            if(board [2][0] == 79 || board [2][0] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[2][0] = symbol;
                return true;
            }

            break;
            
        case 10:
            if(board [2][1] == 79 || board [2][1] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[2][1] = symbol;
                return true;
            }
            break;
            
        case 11:
            if(board [2][2] == 79 || board [2][2] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[2][2] = symbol;
                return true;
            }
            break;
        
        case 12:
            if(board [2][3] == 79 || board [2][3] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[2][3] = symbol;
                return true;
            }
            break;
        
        case 13:
            if(board [3][0] == 79 || board [3][0] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[3][0] = symbol;
                return true;
            }
            break;
        
        case 14:
            if(board [3][1] == 79 || board [3][1] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[3][1] = symbol;
                return true;
            }
            break;
        
        case 15:
            if(board [3][2] == 79 || board [3][2] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[3][2] = symbol;
                return true;
            }
            break;
            
        case 16:
            if(board [3][3] == 79 || board [3][3] == 88){
                cout << "please choose an unoccupied space.\n";
                return false;
            } else{
                board[3][3] = symbol;
                return true;
            }
            break;
        
        default:
            break;
    }
    return false;
}

