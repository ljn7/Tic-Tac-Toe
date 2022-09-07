#pragma once

#include <iostream>
#include <vector>

#include "..\includes\player_struct.h"

using std::vector;

void computer_ai(vector<vector <char>>& p_table,  
                 const Player& p_p1, 
                 const Player& p_p2,
                 vector<vector<bool>>& p_p1_hash,
                 vector<vector<bool>>& p_p2_hash,
                 vector<vector<bool>>& p_table_hash,
                 short int& round);
