#include <iostream>
#include <vector>
#include <algorithm>

#include "..\includes\player_struct.h"
#include "..\includes\show_table.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

void chooseThePlace (vector<vector<char>>& p_table, 
                     Player& p_p1,
                     vector<vector<bool>>& p_player_hash,
                     vector<vector<bool>>& p_table_hash) {

    short int row;
    short int column;

    cout << "On which row and column do you want to place\n"
                "(Enter the number respectively) " << p_p1.playerTeam << endl;

    show_table(p_table);
    cout << endl;
    
    while (true) {
        
        do {
            cout << "Please choose an empty space" << endl;
            cin >> row;
            cin >> column;

            while(cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Invalid input, retry again." << endl;
                cin >> row;
                cin >> column;
            }
            
        } while (!(row >= 1 && row <= 3) || !(column <= 3 && column >= 1));

        if (!p_table_hash[row - 1][column - 1]) {
            p_table[row - 1][column - 1] = p_p1.playerTeam;
            p_player_hash[row - 1][column - 1] = true;
            p_table_hash[row - 1][column - 1] = true;
            return;
        }   
    }    
}