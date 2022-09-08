#include <vector>
#include "..\includes\player_struct.h"

using std::vector;


bool gameLogic (vector<vector<bool>>& p_player_hash) {

    //Row Check
    for (int i = 0; i < 3; i++) 
        if (p_player_hash[i][0])
            if (p_player_hash[i][1])
                if (p_player_hash[i][2])
                    return 0;

    //Column Check
    for (int i = 0; i < 3; i++) 
        if (p_player_hash[0][i])
            if (p_player_hash[1][i])
                if (p_player_hash[2][i])
                    return 0;
    
    //Diagonal Check
    if (p_player_hash[0][0])
        if (p_player_hash[1][1])
            if (p_player_hash[2][2])
                return 0;

    //Diagonal Check
    if (p_player_hash[0][2])
        if (p_player_hash[1][1])
            if (p_player_hash[2][0])
                return 0;

    return 1;
}
