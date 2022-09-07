#include <iostream>
#include <vector>

#include "..\includes\player_struct.h"
#include "..\includes\computer_ai.h"
#include "..\includes\team_pick.h"
#include "..\includes\show_table.h"
#include "..\includes\player_game_logic.h"
#include "..\includes\place_chooser.h"


using std::cout;
using std::endl;
using std::cin;
using std::vector;

int game() {

    while (true) {

        vector<vector<bool>> playerOneHash = {{0, 0, 0},
                                              {0, 0, 0},
                                              {0, 0, 0}};
        vector<vector<bool>> playerTwoHash = {{0, 0, 0},
                                              {0, 0, 0},
                                              {0, 0, 0}};
        vector<vector<bool>> tableHash = {{0, 0, 0},
                                          {0, 0, 0},
                                          {0, 0, 0}};
        vector<vector<char>> table = { 
                       {'.', '.', '.'},
                       {'.', '.', '.'},
                       {'.', '.', '.'}
                     };
                     
        Player p1;
        Player p2;

        cout << "Choose the team\n For 'X' type X and for 'O' type O" 
             << endl;

        pickTheTeam(p1, p2);

        cout << endl;

        short int table_space;
        table_space = 0;

        while (true) {

            cout << "\t\t\t\tYour Turn" << endl;   
            chooseThePlace (table, p1, playerOneHash, tableHash);
            ++table_space;
            
            cout << endl << endl;

            show_table(table);
            cout << endl << endl;

            if (!gameLogic(playerOneHash)) {
                cout << "\t\t\t\tYou won the game!"
                     << endl << endl;
                break;
            } 
            
            cout <<"\t\t\t\tBot's Turn" << endl;
            computer_ai(table, p1, p2, playerOneHash, playerTwoHash, 
                        tableHash, table_space);
            ++table_space;
            cout << endl << endl;

            show_table(table);

            cout << endl << endl;
            
            if (!gameLogic(playerTwoHash)) {
                cout << "\t\t\t\tBot won the game!" 
                     << endl << endl;
                break;
            }
            if (table_space >= 9) {
                cout << "\t\t\t\tGame Tied!" << endl << endl;
                break;
            }
        }

        cout << "\t\tDo you want to continue the game 'y' or 'n' \
                \n\t\t\tDefault 'y'\n" << endl;
        char continueGame = 'y';
        
        while (cin >> continueGame) {
            if (continueGame == 'n' || continueGame == 'N')
                exit(0);
            if (continueGame == 'y' || continueGame == 'Y')
                break;
        }
    }
}



