#include <iostream>
#include <vector>
// #include <ctime>
// #include <cstdlib>

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

    // std::srand (std::time (0)); //time as a seeder for rand()

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
                
            chooseThePlace (table, p1, playerOneHash, tableHash);
            ++table_space;
            
            cout << endl << endl;

            show_table(table);
            cout << endl << endl;

            if (!gameLogic(playerOneHash)) {
                cout << "Player " << p1.playerTeam << " won the game!";
                cout << endl << endl;
                break;
            } 

            computer_ai(table, p1, p2, playerOneHash, playerTwoHash, 
                        tableHash, table_space);
            ++table_space;
            cout << endl << endl;

            show_table(table);

            cout << endl << endl;
            
            if (!gameLogic(playerTwoHash)) {
                cout << "Player " << p2.playerTeam 
                     << " won the game!" << endl << endl;
                break;
            }
            if (table_space >= 9) {
                cout << "Game Tied!" << endl << endl;
                break;
            }
        }

        cout << "Do you want to continue the game 'y' or 'n' \
                \nDefault 'y'\n" << endl;
        char continueGame = 'y';
        cin >> continueGame;

        if (continueGame == 'n')
            exit(0);
    }
}



