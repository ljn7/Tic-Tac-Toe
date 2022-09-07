#pragma once

#include <iostream>
#include <vector>
#include "player_struct.h"

using std::vector;

void chooseThePlace (vector<vector<char>>& p_table, 
                     Player& p_p1,
                     vector<vector<bool>>& p_player_hash,
                     vector<vector<bool>>& p_table_hash);