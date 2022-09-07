#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "..\includes\player_struct.h"
#include "..\includes\pseudo_rng.h"

using std::vector;

int computer_ai_util_func(vector<vector<bool>>& p_player1_hash,
                          vector<vector<bool>>& p_player2_hash,
                          vector<vector<bool>>& p_table_hash, 
                          const Player& p_player,
                          vector<vector <char>>& p_table);

// int computer_ai_util_func2(const vector<vector<bool>>& p_player1_hash,
//                           vector<vector<bool>>& p_player2_hash,
//                           vector<vector<bool>>& p_table_hash, 
//                           const Player& p_player,
//                           vector<vector <char>>& p_table);                          

void computer_ai(vector<vector <char>>& p_table,  
                 const Player& p_p1, 
                 const Player& p_p2,
                 vector<vector<bool>>& p_p1_hash,
                 vector<vector<bool>>& p_p2_hash,
                 vector<vector<bool>>& p_table_hash,
                 short int& round) 
{   
    short int row;
    short int column;

    if (round == 1) {
        std::srand (std::time (0));

        do {
            column = random(0, 2);
            row = random(0, 2);
        } while (p_table_hash[row][column]);

        p_table[row][column] = p_p2.playerTeam;
        p_p2_hash[row][column] = true;
        p_table_hash[row][column] = true;
        return;
    }
    
    if (!computer_ai_util_func(p_p2_hash, p_p2_hash, p_table_hash, p_p2, p_table))
        return;

    if (!computer_ai_util_func(p_p1_hash, p_p2_hash, p_table_hash, p_p2, p_table))
        return;
    
    for (int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) {
            if (!p_table_hash[i][j]) {
                p_table[i][j] = p_p2.playerTeam;
                p_p2_hash[i][j] = true;
                p_table_hash[i][j] = true;
                return;
            }

        }


}
    
//first utility function for computer_ai()
int computer_ai_util_func(vector<vector<bool>>& p_player1_hash,
                          vector<vector<bool>>& p_player2_hash,
                          vector<vector<bool>>& p_table_hash, 
                          const Player& p_player,
                          vector<vector <char>>& p_table) 
{

    if (p_player1_hash[0][0]) {
        if (p_player1_hash[0][1] && !p_table_hash[0][2]) {
            p_table[0][2] = p_player.playerTeam;
            p_table_hash[0][2] = true;
			p_player2_hash[0][2] = true;
            return 0;
        }
        else if (p_player1_hash[1][0] && !p_table_hash[2][0]) {
            p_table[2][0] = p_player.playerTeam;
            p_table_hash[2][0] = true;
			p_player2_hash[2][0] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[2][3]) {
            p_table[2][3] = p_player.playerTeam;
            p_table_hash[2][3] = true;
			p_player2_hash[2][3] = true;
            return 0;
        }
        else if (p_player1_hash[0][2] && !p_table_hash[0][1]) {
            p_table[0][1] = p_player.playerTeam;
            p_table_hash[0][1] = true;
			p_player2_hash[0][1] = true;
            return 0;
        }
        else if (p_player1_hash[2][2] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
        else if (p_player1_hash[2][0] && !p_table_hash[1][0]) {
            p_table[1][0] = p_player.playerTeam;
            p_table_hash[1][0] = true;
			p_player2_hash[1][0] = true;
            return 0;
        }
    }
    //counterpick for table[0][1]
    if (p_player1_hash[0][1]) {
        if (p_player1_hash[0][0] && !p_table_hash[0][2]) {
            p_table[0][2] = p_player.playerTeam;
            p_table_hash[0][2] = true;
			p_player2_hash[0][2] = true;
            return 0;
        }
        else if (p_player1_hash[0][2] && !p_table_hash[0][0]) {
            p_table[0][0] = p_player.playerTeam;
            p_table_hash[0][0] = true;
			p_player2_hash[0][0] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[2][1]) {
            p_table[2][1] = p_player.playerTeam;
            p_table_hash[2][1] = true;
			p_player2_hash[2][1] = true;
            return 0;
        }
        else if (p_player1_hash[2][1] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
    }
    //counterpick for table[0][2]
    if (p_player1_hash[0][2]) {
        if (p_player1_hash[0][1] && !p_table_hash[0][0]) {
            p_table[0][0] = p_player.playerTeam;
            p_table_hash[0][0] = true;
			p_player2_hash[0][0] = true;
            return 0;
        }
        else if (p_player1_hash[0][0] && !p_table_hash[0][1]) {
            p_table[0][1] = p_player.playerTeam;
            p_table_hash[0][1] = true;
			p_player2_hash[0][1] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[2][0]) {
            p_table[2][0] = p_player.playerTeam;
            p_table_hash[2][0] = true;
			p_player2_hash[2][0] = true;
            return 0;
        }
        else if (p_player1_hash[1][2] && !p_table_hash[2][2]) {
            p_table[2][2] = p_player.playerTeam;
            p_table_hash[2][2] = true;
			p_player2_hash[2][2] = true;
            return 0;
        }
        else if (p_player1_hash[2][2] && !p_table_hash[1][2]) {
            p_table[1][2] = p_player.playerTeam;
            p_table_hash[1][2] = true;
			p_player2_hash[1][2] = true;
            return 0;
        }
        else if (p_player1_hash[2][0] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
    }
    //counterpick for table[1][0]
    if (p_player1_hash[1][0]) {
        if (p_player1_hash[0][0] && !p_table_hash[2][0]) {
            p_table[2][0] = p_player.playerTeam;
            p_table_hash[2][0] = true;
			p_player2_hash[2][0] = true;
            return 0;
        }
        else if (p_player1_hash[2][0] && !p_table_hash[0][0]) {
            p_table[0][0] = p_player.playerTeam;
            p_table_hash[0][0] = true;
			p_player2_hash[0][0] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[1][2]) {
            p_table[1][2] = p_player.playerTeam;
            p_table_hash[1][2] = true;
			p_player2_hash[1][2] = true;
            return 0;
        }
        else if (p_player1_hash[1][2] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
    }
    //counter pick for table[1][1]
    if (p_player1_hash[1][1]) {
        if (p_player1_hash[0][0] && !p_table_hash[2][2]) {
            p_table[2][2] = p_player.playerTeam;
            p_table_hash[2][2] = true;
			p_player2_hash[2][2] = true;
            return 0;
        }
        else if (p_player1_hash[2][2] && !p_table_hash[0][0]) {
            p_table[0][0] = p_player.playerTeam;
            p_table_hash[0][0] = true;
			p_player2_hash[0][0] = true;
            return 0;
        }
        else if (p_player1_hash[0][1] && !p_table_hash[2][1]) {
            p_table[2][1] = p_player.playerTeam;
            p_table_hash[2][1] = true;
			p_player2_hash[2][1] = true;
            return 0;
        }
        else if (p_player1_hash[2][1] && !p_table_hash[0][1]) {
            p_table[0][1] = p_player.playerTeam;
            p_table_hash[0][1] = true;
			p_player2_hash[0][1] = true;
            return 0;
        }
        else if (p_player1_hash[0][2] && !p_table_hash[2][0]) {
            p_table[2][0] = p_player.playerTeam;
            p_table_hash[2][0] = true;
			p_player2_hash[2][0] = true;
            return 0;
        }
        else if (p_player1_hash[2][0] && !p_table_hash[0][2]) {
            p_table[0][2] = p_player.playerTeam;
            p_table_hash[0][2] = true;
			p_player2_hash[0][2] = true;
            return 0;
        }
        else if (p_player1_hash[1][0] && !p_table_hash[1][2]) {
            p_table[1][2] = p_player.playerTeam;
            p_table_hash[1][2] = true;
			p_player2_hash[1][2] = true;
            return 0;
        }
        else if (p_player1_hash[1][2] && !p_table_hash[1][0]) {
            p_table[1][0] = p_player.playerTeam;
            p_table_hash[1][0] = true;
			p_player2_hash[1][0] = true;
            return 0;
        }
    }
    //counterpick for table[1][2]
    if (p_player1_hash[1][2]) {
        if (p_player1_hash[0][2] && !p_table_hash[2][2]) {
            p_table[2][2] = p_player.playerTeam;
            p_table_hash[2][2] = true;
			p_player2_hash[2][2] = true;
            return 0;
        }
        else if (p_player1_hash[2][2] && !p_table_hash[0][2]) {
            p_table[0][2] = p_player.playerTeam;
            p_table_hash[0][2] = true;
			p_player2_hash[0][2] = true;
            return 0;
        }
        else if (p_player1_hash[1][0] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[1][0]) {
            p_table[1][0] = p_player.playerTeam;
            p_table_hash[1][0] = true;
			p_player2_hash[1][0] = true;
            return 0;
        }
    }
    //counterpick for table[2][0]
    if (p_player1_hash[2][0]) {
        if (p_player1_hash[1][0] && !p_table_hash[0][0]) {
            p_table[0][0] = p_player.playerTeam;
            p_table_hash[0][0] = true;
			p_player2_hash[0][0] = true;
            return 0;
        }
        else if (p_player1_hash[0][0] && !p_table_hash[1][0]) {
            p_table[1][0] = p_player.playerTeam;
            p_table_hash[1][0] = true;
			p_player2_hash[1][0] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[0][2]) {
            p_table[0][2] = p_player.playerTeam;
            p_table_hash[0][2] = true;
			p_player2_hash[0][2] = true;
            return 0;
        }
        else if (p_player1_hash[0][2] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
        else if (p_player1_hash[2][1] && !p_table_hash[2][2]) {
            p_table[2][2] = p_player.playerTeam;
            p_table_hash[2][2] = true;
			p_player2_hash[2][2] = true;
            return 0;
        }
        else if (p_player1_hash[2][2] && !p_table_hash[2][1]) {
            p_table[2][1] = p_player.playerTeam;
            p_table_hash[2][1] = true;
			p_player2_hash[2][1] = true;
            return 0;
        } 
    }
    //counterpick for table[2][1]
    if (p_player1_hash[2][1]) {
        if (p_player1_hash[2][0] && !p_table_hash[2][2]) {
            p_table[2][2] = p_player.playerTeam;
            p_table_hash[2][2] = true;
			p_player2_hash[2][2] = true;
            return 0;
        }
        else if (p_player1_hash[2][2] && !p_table_hash[2][0]) {
            p_table[2][0] = p_player.playerTeam;
            p_table_hash[2][0] = true;
			p_player2_hash[2][0] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[0][1]) {
            p_table[0][1] = p_player.playerTeam;
            p_table_hash[0][1] = true;
			p_player2_hash[0][1] = true;
            return 0;
        }
        else if (p_player1_hash[0][1] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
    }
    //counterpick for table[2][2]
    if (p_player1_hash[2][2]) {
        if (p_player1_hash[2][1] && !p_table_hash[2][0]) {
            p_table[2][0] = p_player.playerTeam;
            p_table_hash[2][0] = true;
			p_player2_hash[2][0] = true;
            return 0;
        }
        else if (p_player1_hash[2][0] && !p_table_hash[2][1]) {
            p_table[2][1] = p_player.playerTeam;
            p_table_hash[2][1] = true;
			p_player2_hash[2][1] = true;
            return 0;
        }
        else if (p_player1_hash[1][1] && !p_table_hash[0][0]) {
            p_table[0][0] = p_player.playerTeam;
            p_table_hash[0][0] = true;
			p_player2_hash[0][0] = true;
            return 0;
        }
        else if (p_player1_hash[0][0] && !p_table_hash[1][1]) {
            p_table[1][1] = p_player.playerTeam;
            p_table_hash[1][1] = true;
			p_player2_hash[1][1] = true;
            return 0;
        }
        else if (p_player1_hash[1][2] && !p_table_hash[0][2]) {
            p_table[0][2] = p_player.playerTeam;
            p_table_hash[0][2] = true;
			p_player2_hash[0][2] = true;
            return 0;
        } 
        else if (p_player1_hash[0][2] && !p_table_hash[1][2]) {
            p_table[1][2] = p_player.playerTeam;
            p_table_hash[1][2] = true;
			p_player2_hash[1][2] = true;
            return 0;
        }
    }
    return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // //counterpick for table[0][0]
    // if (p_player1_hash[0][0]) {
    //     if (p_player1_hash[0][1] && !p_table_hash[0][2]) {
    //         p_table[0][2] = p_player.playerTeam;
    //         p_table_hash[0][2] = true;
	// 		p_player2_hash[0][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][0] && !p_table_hash[2][0]) {
    //         p_table[2][0] = p_player.playerTeam;
    //         p_table_hash[2][0] = true;
	// 		p_player2_hash[2][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[2][3]) {
    //         p_table[2][3] = p_player.playerTeam;
    //         p_table_hash[2][3] = true;
	// 		p_player2_hash[2][3] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][2] && !p_table_hash[0][1]) {
    //         p_table[0][1] = p_player.playerTeam;
    //         p_table_hash[0][1] = true;
	// 		p_player2_hash[0][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][2] && !p_table_hash[1][1]) {
    //         p_table[1][1] = p_player.playerTeam;
    //         p_table_hash[1][1] = true;
	// 		p_player2_hash[1][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][0] && !p_table_hash[0][1]) {
    //         p_table[0][1] = p_player.playerTeam;
    //         p_table_hash[0][1] = true;
	// 		p_player2_hash[0][1] = true;
    //         return 0;
    //     }
    // }
    // //counterpick for table[0][1]
    // if (p_player1_hash[0][1]) {
    //     if (p_player1_hash[0][0] && !p_table_hash[0][2]) {
    //         p_table[0][2] = p_player.playerTeam;
    //         p_table_hash[0][2] = true;
	// 		p_player2_hash[0][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][2] && !p_table_hash[0][0]) {
    //         p_table[0][0] = p_player.playerTeam;
    //         p_table_hash[0][0] = true;
	// 		p_player2_hash[0][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[2][1]) {
    //         p_table[2][1] = p_player.playerTeam;
    //         p_table_hash[2][1] = true;
	// 		p_player2_hash[2][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][1] && !p_table_hash[1][1]) {
    //         p_table[1][1] = p_player.playerTeam;
    //         p_table_hash[1][1] = true;
	// 		p_player2_hash[1][1] = true;
    //         return 0;
    //     }
    // }
    // //counterpick for table[0][2]
    // if (p_player1_hash[0][2]) {
    //     if (p_player1_hash[0][1] && !p_table_hash[0][0]) {
    //         p_table[0][0] = p_player.playerTeam;
    //         p_table_hash[0][0] = true;
	// 		p_player2_hash[0][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][0] && !p_table_hash[0][1]) {
    //         p_table[0][1] = p_player.playerTeam;
    //         p_table_hash[0][1] = true;
	// 		p_player2_hash[0][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[2][0]) {
    //         p_table[2][0] = p_player.playerTeam;
    //         p_table_hash[2][0] = true;
	// 		p_player2_hash[2][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][2] && !p_table_hash[2][2]) {
    //         p_table[2][2] = p_player.playerTeam;
    //         p_table_hash[2][2] = true;
	// 		p_player2_hash[2][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][2] && !p_table_hash[1][2]) {
    //         p_table[1][2] = p_player.playerTeam;
    //         p_table_hash[1][2] = true;
	// 		p_player2_hash[1][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][0] && !p_table_hash[0][1]) {
    //         p_table[0][1] = p_player.playerTeam;
    //         p_table_hash[0][1] = true;
	// 		p_player2_hash[0][1] = true;
    //         return 0;
    //     }
    // }
    // //counterpick for table[1][0]
    // if (p_player1_hash[1][0]) {
    //     if (p_player1_hash[0][0] && !p_table_hash[2][0]) {
    //         p_table[2][0] = p_player.playerTeam;
    //         p_table_hash[2][0] = true;
	// 		p_player2_hash[2][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][0] && !p_table_hash[0][0]) {
    //         p_table[0][0] = p_player.playerTeam;
    //         p_table_hash[0][0] = true;
	// 		p_player2_hash[0][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[1][2]) {
    //         p_table[1][2] = p_player.playerTeam;
    //         p_table_hash[1][2] = true;
	// 		p_player2_hash[1][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][2] && !p_table_hash[1][1]) {
    //         p_table[1][1] = p_player.playerTeam;
    //         p_table_hash[1][1] = true;
	// 		p_player2_hash[1][1] = true;
    //         return 0;
    //     }
    // }
    // if (p_player1_hash[1][1]) {
    //     if (p_player1_hash[0][0] && !p_table_hash[2][2]) {
    //         p_table[2][2] = p_player.playerTeam;
    //         p_table_hash[2][2] = true;
	// 		p_player2_hash[2][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][2] && !p_table_hash[0][0]) {
    //         p_table[0][0] = p_player.playerTeam;
    //         p_table_hash[0][0] = true;
	// 		p_player2_hash[0][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][1] && !p_table_hash[2][1]) {
    //         p_table[2][1] = p_player.playerTeam;
    //         p_table_hash[2][1] = true;
	// 		p_player2_hash[2][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][1] && !p_table_hash[0][1]) {
    //         p_table[0][1] = p_player.playerTeam;
    //         p_table_hash[0][1] = true;
	// 		p_player2_hash[0][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][2] && !p_table_hash[2][0]) {
    //         p_table[2][0] = p_player.playerTeam;
    //         p_table_hash[2][0] = true;
	// 		p_player2_hash[2][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][0] && !p_table_hash[0][2]) {
    //         p_table[0][2] = p_player.playerTeam;
    //         p_table_hash[0][2] = true;
	// 		p_player2_hash[0][2] = true;
    //         return 0;
    //     }
    // }
    // //counterpick for table[1][2]
    // if (p_player1_hash[1][2]) {
    //     if (p_player1_hash[0][2] && !p_table_hash[2][2]) {
    //         p_table[2][2] = p_player.playerTeam;
    //         p_table_hash[2][2] = true;
	// 		p_player2_hash[2][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][2] && !p_table_hash[0][2]) {
    //         p_table[0][2] = p_player.playerTeam;
    //         p_table_hash[0][2] = true;
	// 		p_player2_hash[0][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][0] && !p_table_hash[1][1]) {
    //         p_table[1][1] = p_player.playerTeam;
    //         p_table_hash[1][1] = true;
	// 		p_player2_hash[1][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[1][0]) {
    //         p_table[1][0] = p_player.playerTeam;
    //         p_table_hash[1][0] = true;
	// 		p_player2_hash[1][0] = true;
    //         return 0;
    //     }
    // }
    // //counterpick for table[2][0]
    // if (p_player1_hash[2][0]) {
    //     if (p_player1_hash[1][0] && !p_table_hash[0][0]) {
    //         p_table[0][0] = p_player.playerTeam;
    //         p_table_hash[0][0] = true;
	// 		p_player2_hash[0][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][0] && !p_table_hash[1][0]) {
    //         p_table[1][0] = p_player.playerTeam;
    //         p_table_hash[1][0] = true;
	// 		p_player2_hash[1][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[0][2]) {
    //         p_table[0][2] = p_player.playerTeam;
    //         p_table_hash[0][2] = true;
	// 		p_player2_hash[0][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][1] && !p_table_hash[2][2]) {
    //         p_table[2][2] = p_player.playerTeam;
    //         p_table_hash[2][2] = true;
	// 		p_player2_hash[2][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][2] && !p_table_hash[2][1]) {
    //         p_table[2][1] = p_player.playerTeam;
    //         p_table_hash[2][1] = true;
	// 		p_player2_hash[2][1] = true;
    //         return 0;
    //     } 
    // }
    // //counterpick for table[2][1]
    // if (p_player1_hash[2][1]) {
    //     if (p_player1_hash[2][0] && !p_table_hash[2][2]) {
    //         p_table[2][2] = p_player.playerTeam;
    //         p_table_hash[2][2] = true;
	// 		p_player2_hash[2][2] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][2] && !p_table_hash[2][0]) {
    //         p_table[2][0] = p_player.playerTeam;
    //         p_table_hash[2][0] = true;
	// 		p_player2_hash[2][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[0][1]) {
    //         p_table[0][1] = p_player.playerTeam;
    //         p_table_hash[0][1] = true;
	// 		p_player2_hash[0][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][1] && !p_table_hash[1][1]) {
    //         p_table[1][1] = p_player.playerTeam;
    //         p_table_hash[1][1] = true;
	// 		p_player2_hash[1][1] = true;
    //         return 0;
    //     }
    // }
    // //counterpick for table[2][2]
    // if (p_player1_hash[2][2]) {
    //     if (p_player1_hash[2][1] && !p_table_hash[2][0]) {
    //         p_table[2][0] = p_player.playerTeam;
    //         p_table_hash[2][0] = true;
	// 		p_player2_hash[2][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[2][0] && !p_table_hash[2][1]) {
    //         p_table[2][1] = p_player.playerTeam;
    //         p_table_hash[2][1] = true;
	// 		p_player2_hash[2][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][1] && !p_table_hash[0][0]) {
    //         p_table[0][0] = p_player.playerTeam;
    //         p_table_hash[0][0] = true;
	// 		p_player2_hash[0][0] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[0][0] && !p_table_hash[1][1]) {
    //         p_table[1][1] = p_player.playerTeam;
    //         p_table_hash[1][1] = true;
	// 		p_player2_hash[1][1] = true;
    //         return 0;
    //     }
    //     else if (p_player1_hash[1][2] && !p_table_hash[0][2]) {
    //         p_table[0][2] = p_player.playerTeam;
    //         p_table_hash[0][2] = true;
	// 		p_player2_hash[0][2] = true;
    //         return 0;
    //     } 
    //     else if (p_player1_hash[0][2] && !p_table_hash[1][2]) {
    //         p_table[1][2] = p_player.playerTeam;
    //         p_table_hash[1][2] = true;
	// 		p_player2_hash[1][2] = true;
    //         return 0;
    //     }
    // }

    


//second utility function for computer_ai()
// // int computer_ai_util_func2(vector<vector<bool>>& p_player1_hash, 
//                           vector<vector<bool>>& p_player2_hash,
//                           vector<vector<bool>>& p_table_hash, 
//                           const Player& p_player,
//                           vector<vector <char>>& p_table) 
// {

//     if (p_player1_hash[0][0]) {
//         if (p_player1_hash[0][1] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][0] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[2][3]) {
//             p_table[2][3] = p_player.playerTeam;
//             p_table_hash[2][3] = true;
// 			p_player2_hash[2][3] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][2] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[0][1]
//     if (p_player1_hash[0][1]) {
//         if (p_player1_hash[0][0] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][2] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][1] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[0][2]
//     if (p_player1_hash[0][2]) {
//         if (p_player1_hash[0][1] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][0] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][2] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[1][2]) {
//             p_table[1][2] = p_player.playerTeam;
//             p_table_hash[1][2] = true;
// 			p_player2_hash[1][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[1][0]
//     if (p_player1_hash[1][0]) {
//         if (p_player1_hash[0][0] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[1][2]) {
//             p_table[1][2] = p_player.playerTeam;
//             p_table_hash[1][2] = true;
// 			p_player2_hash[1][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][2] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//     }
//     if (p_player1_hash[1][1]) {
//         if (p_player1_hash[0][0] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][1] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][1] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][2] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[1][2]
//     if (p_player1_hash[1][2]) {
//         if (p_player1_hash[0][2] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][0] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[1][0]) {
//             p_table[1][0] = p_player.playerTeam;
//             p_table_hash[1][0] = true;
// 			p_player2_hash[1][0] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[2][0]
//     if (p_player1_hash[2][0]) {
//         if (p_player1_hash[1][0] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][0] && !p_table_hash[1][0]) {
//             p_table[1][0] = p_player.playerTeam;
//             p_table_hash[1][0] = true;
// 			p_player2_hash[1][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][1] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         } 
//     }
//     //counterpick for table[2][1]
//     if (p_player1_hash[2][1]) {
//         if (p_player1_hash[2][0] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][1] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[2][2]
//     if (p_player1_hash[2][2]) {
//         if (p_player1_hash[2][1] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][0] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][2] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         } 
//         else if (p_player1_hash[0][2] && !p_table_hash[1][2]) {
//             p_table[1][2] = p_player.playerTeam;
//             p_table_hash[1][2] = true;
// 			p_player2_hash[1][2] = true;
//             return 0;
//         }
//     }


//     //counterpick for table[0][0]
//     if (p_player1_hash[0][0]) {
//         if (p_player1_hash[0][1] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][0] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[2][3]) {
//             p_table[2][3] = p_player.playerTeam;
//             p_table_hash[2][3] = true;
// 			p_player2_hash[2][3] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][2] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[0][1]
//     if (p_player1_hash[0][1]) {
//         if (p_player1_hash[0][0] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][2] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][1] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[0][2]
//     if (p_player1_hash[0][2]) {
//         if (p_player1_hash[0][1] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][0] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][2] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[1][2]) {
//             p_table[1][2] = p_player.playerTeam;
//             p_table_hash[1][2] = true;
// 			p_player2_hash[1][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[1][0]
//     if (p_player1_hash[1][0]) {
//         if (p_player1_hash[0][0] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[1][2]) {
//             p_table[1][2] = p_player.playerTeam;
//             p_table_hash[1][2] = true;
// 			p_player2_hash[1][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][2] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//     }
//     if (p_player1_hash[1][1]) {
//         if (p_player1_hash[0][0] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][1] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][1] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][2] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[1][2]
//     if (p_player1_hash[1][2]) {
//         if (p_player1_hash[0][2] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][0] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[1][0]) {
//             p_table[1][0] = p_player.playerTeam;
//             p_table_hash[1][0] = true;
// 			p_player2_hash[1][0] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[2][0]
//     if (p_player1_hash[2][0]) {
//         if (p_player1_hash[1][0] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][0] && !p_table_hash[1][0]) {
//             p_table[1][0] = p_player.playerTeam;
//             p_table_hash[1][0] = true;
// 			p_player2_hash[1][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][1] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         } 
//     }
//     //counterpick for table[2][1]
//     if (p_player1_hash[2][1]) {
//         if (p_player1_hash[2][0] && !p_table_hash[2][2]) {
//             p_table[2][2] = p_player.playerTeam;
//             p_table_hash[2][2] = true;
// 			p_player2_hash[2][2] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][2] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[0][1]) {
//             p_table[0][1] = p_player.playerTeam;
//             p_table_hash[0][1] = true;
// 			p_player2_hash[0][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][1] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//     }
//     //counterpick for table[2][2]
//     if (p_player1_hash[2][2]) {
//         if (p_player1_hash[2][1] && !p_table_hash[2][0]) {
//             p_table[2][0] = p_player.playerTeam;
//             p_table_hash[2][0] = true;
// 			p_player2_hash[2][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[2][0] && !p_table_hash[2][1]) {
//             p_table[2][1] = p_player.playerTeam;
//             p_table_hash[2][1] = true;
// 			p_player2_hash[2][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][1] && !p_table_hash[0][0]) {
//             p_table[0][0] = p_player.playerTeam;
//             p_table_hash[0][0] = true;
// 			p_player2_hash[0][0] = true;
//             return 0;
//         }
//         else if (p_player1_hash[0][0] && !p_table_hash[1][1]) {
//             p_table[1][1] = p_player.playerTeam;
//             p_table_hash[1][1] = true;
// 			p_player2_hash[1][1] = true;
//             return 0;
//         }
//         else if (p_player1_hash[1][2] && !p_table_hash[0][2]) {
//             p_table[0][2] = p_player.playerTeam;
//             p_table_hash[0][2] = true;
// 			p_player2_hash[0][2] = true;
//             return 0;
//         } 
//         else if (p_player1_hash[0][2] && !p_table_hash[1][2]) {
//             p_table[1][2] = p_player.playerTeam;
//             p_table_hash[1][2] = true;
// 			p_player2_hash[1][2] = true;
//             return 0;
//         }
//     }

//     return 1;
// }