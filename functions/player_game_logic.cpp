#include <vector>
#include "..\includes\player_struct.h"

using std::vector;


bool gameLogic (vector<vector<bool>>& p_player_hash) {

    if (p_player_hash[0][0]) {
        if (p_player_hash[0][1])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[1][0]) 
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[2][3])
                return 0;
        else if (p_player_hash[0][2])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[1][1])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[0][1])
                return 0;
    }
    //checking table[0][1]
    if (p_player_hash[0][1]) {
        if (p_player_hash[0][0])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[0][2])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[2][1])
                return 0;
        else if (p_player_hash[2][1])
            if (p_player_hash[1][1])
                return 0;
    }
    //checking table[0][2]
    if (p_player_hash[0][2]) {
        if (p_player_hash[0][1])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][0])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[1][2])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[1][2])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[1][1])
                return 0;
    }
    //checking table[1][0]
    if (p_player_hash[1][0]) {
        if (p_player_hash[0][0])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[1][2])
                return 0;
        else if (p_player_hash[1][2])
            if (p_player_hash[1][1])
                return 0;
    }
    if (p_player_hash[1][1]) {
        if (p_player_hash[0][0])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][1])
            if (p_player_hash[2][1])
                return 0;
        else if (p_player_hash[2][1])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[0][2])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[0][2])
                return 0;
    }
    //checking table[1][2]
    if (p_player_hash[1][2]) {
        if (p_player_hash[0][2])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[1][0])
            if (p_player_hash[1][1])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[1][0])
                return 0;
    }
    //checking table[2][0]
    if (p_player_hash[2][0]) {
        if (p_player_hash[1][0])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][0])
            if (p_player_hash[1][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[2][1])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[2][1])
                return 0;
    }
    //checking table[2][1]
    if (p_player_hash[2][1]) {
        if (p_player_hash[2][0])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[0][1])
            if (p_player_hash[1][1])
                return 0;
    }
    //checking table[2][2]
    if (p_player_hash[2][2]) {
        if (p_player_hash[2][1])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[2][1])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][0])
            if (p_player_hash[1][1])
                return 0;
        else if (p_player_hash[1][2])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[0][2])
            if (p_player_hash[1][2])
                return 0;
    }
    //checking table[0][0]
    if (p_player_hash[0][0]) {
        if (p_player_hash[0][1])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[1][0])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[2][3])
                return 0;
        else if (p_player_hash[0][2])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[1][1])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[0][1])
                return 0;
    }
    //checking table[0][1]
    if (p_player_hash[0][1]) {
        if (p_player_hash[0][0])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[0][2])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[2][1])
                return 0;
        else if (p_player_hash[2][1])
            if (p_player_hash[1][1])
                return 0;
    }
    //checking table[0][2]
    if (p_player_hash[0][2]) {
        if (p_player_hash[0][1])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][0])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[1][2])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[1][2])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[0][1])
                return 0;
    }
    //checking table[1][0]
    if (p_player_hash[1][0]) {
        if (p_player_hash[0][0])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[1][2])
                return 0;
        else if (p_player_hash[1][2])
            if (p_player_hash[1][1])
                return 0;
    }
    if (p_player_hash[1][1]) {
        if (p_player_hash[0][0])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][1])
            if (p_player_hash[2][1])
                return 0;
        else if (p_player_hash[2][1])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[0][2])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[0][2])
                return 0;
    }
    //checking table[1][2]
    if (p_player_hash[1][2]) {
        if (p_player_hash[0][2])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[1][0])
            if (p_player_hash[1][1])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[1][0])
                return 0;
    }
    //checking table[2][0]
    if (p_player_hash[2][0]) {
        if (p_player_hash[1][0])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][0])
            if (p_player_hash[1][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[0][2])
                return 0;
        else if (p_player_hash[2][1])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[2][1])
                return 0;
    } 
    //checking table[2][1]
    if (p_player_hash[2][1]) {
        if (p_player_hash[2][0])
            if (p_player_hash[2][2])
                return 0;
        else if (p_player_hash[2][2])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[0][1])
                return 0;
        else if (p_player_hash[0][1])
            if (p_player_hash[1][1])
                return 0;
    }
    //checking table[2][2]
    if (p_player_hash[2][2]) {
        if (p_player_hash[2][1])
            if (p_player_hash[2][0])
                return 0;
        else if (p_player_hash[2][0])
            if (p_player_hash[2][1])
                return 0;
        else if (p_player_hash[1][1])
            if (p_player_hash[0][0])
                return 0;
        else if (p_player_hash[0][0])
            if (p_player_hash[1][1])
                return 0;
        else if (p_player_hash[1][2])
            if (p_player_hash[0][2])
                return 0; 
        else if (p_player_hash[0][2])
            if (p_player_hash[1][2])
                return 0;
    }
    return 1;
}
