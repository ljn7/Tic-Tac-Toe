#include <iostream>
#include <vector>

using std::vector;

void show_table(const vector<vector<char>>& p_table) {

    std::cout << "    1      2      3 " << std::endl; 
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1;
        for (int j = 0; j < 3; j++) 
            std::cout << " | " << p_table[i][j] << " | ";
        std::cout << std::endl << std::endl;
    }
}