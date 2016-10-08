#include <string>
#include <sstream>
#include <stdio.h>

#include <PercolationStats.hpp>

int main(int argc, char *argv[])
{

    if (argc != 3) {
        printf("HAHA");
        throw "Not enough parameters for PercolationStats test";
    }

    std::istringstream ss(argv[1]);
    uint64_t N;
    if (!(ss >> N)) throw "Invalid number " + std::string(argv[1]) + '\n';


    ss.clear();
    ss.str(argv[2]);
    uint64_t T;
    if (!(ss >> T)) throw "Invalid number " + std::string(argv[2]) + '\n';

    PercolationStats ps(N, T);
    printf("Mean is: %f \n", ps.mean());
    printf("Stdev is: %f \n", ps.stdev());


    return 0;
}