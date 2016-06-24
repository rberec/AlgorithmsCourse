#include <string>
#include <sstream>

#include <PercolationStats.hpp>

int main(int argc, char *argv[])
{
  
    if (argc != 3) throw "Not enough parameters for PercolationStats test";
      
    std::istringstream ss(argv[1]);
    uint64_t N;
    if (!(ss >> N)) throw "Invalid number " + std::string(argv[1]) + '\n';
    
    
    ss.clear();
    ss.str(argv[2]);
    uint64_t T;
    if (!(ss >> T)) throw "Invalid number " + std::string(argv[2]) + '\n';
    
    PercolationStats ps(N, T);
    std::printf("Mean is: %f \n", ps.mean());
    std::printf("Stdev is: %f \n", ps.stdev());
    
    
    return 0;
}