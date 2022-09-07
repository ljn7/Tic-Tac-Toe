#include <iostream>
#include <vector>

using std::vector;

void show_table(const vector<vector<char>>& p_table) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            std::cout << " | " << p_table[i][j] << " | ";
        std::cout << std::endl;
    }
}