#include <iostream>

#include "..\includes\player_struct.h"

using std::cin;

void pickTheTeam (Player& p_p1, Player& p_p2) {

    do {
            cin >> p_p1.playerTeam;
    } while ((p_p1.playerTeam != 'X' || p_p1.playerTeam != 'x') && 
            (p_p1.playerTeam != 'O' || p_p1.playerTeam != 'o'));

    if (p_p1.playerTeam == 'X' || p_p1.playerTeam == 'x')
        p_p2.playerTeam = 'O';
    else   
        p_p2.playerTeam = 'X';
}