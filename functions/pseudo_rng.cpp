#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int random (int low, int high) {
    if (low > high) return high;
    return low + (std::rand() % (high - low + 1));
}
