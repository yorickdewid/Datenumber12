#include <iostream>
#include <unistd.h>
#include <unordered_map>

#include "Bagger.h"

int main(int argc, char **argv) {
    const auto nCycle = 8000;
    int nDouble = 0;
    std::unordered_map<std::string, int> match;
    Bagger dg12;

    for (auto i=0; i<nCycle; ++i) {
        dg12.generateRandom();
        std::cout << dg12 << '\n';
        if(match.find(dg12.toString()) != match.end()) {
            ++nDouble;
        } else {
            match[dg12.toString()];
        }
        //usleep(1);
    }
    std::cout << "\nDouble ratio: " << ((double)nDouble/(double)nCycle)*100 << '%'
              << " in " << nCycle << " dg12's\n";

    return 0;
}
