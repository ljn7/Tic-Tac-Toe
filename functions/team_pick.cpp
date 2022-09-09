#include <iostream>

#include "..\includes\player_struct.h"

void pickTheTeam (Player& p_p1, Player& p_p2) {
    std::cout << "\t\t\tand press the enter key\n\t\t\t";
    do {    
        std::cin.clear();
        std::cin >> p_p1.playerTeam;

        if (!(p_p1.playerTeam == 'X' || p_p1.playerTeam == 'x') && 
            !(p_p1.playerTeam == 'O' || p_p1.playerTeam == 'o'))
                std::cout << "\t\t\tInvalid Team, Please pick a valid team!" 
                          << std::endl;

    } while (!(p_p1.playerTeam == 'X' || p_p1.playerTeam == 'x') && 
            !(p_p1.playerTeam == 'O' || p_p1.playerTeam == 'o'));

    if (p_p1.playerTeam == 'X' || p_p1.playerTeam == 'x')
        p_p2.playerTeam = 'O';
    else   
        p_p2.playerTeam = 'X';
}