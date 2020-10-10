#include "start.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << setiosflags(std::ios::fixed) << std::setprecision(2);
    while(1)
        if(start())
            break;
    return 0;
}
