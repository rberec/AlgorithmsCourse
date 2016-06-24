#include <string>
#include <sstream>

#include <PercolationStats.hpp>

int main(int argc, char *argv[])
{
  
    if (argc != 3) throw "Not enough parameters for PercolationStats test";
      
    std::istringstream ss(argv[1]);
    int N;
    if (!(ss >> N)) throw "Invalid number " + std::string(argv[1]) + '\n';
    
    
    ss.clear();
    ss.str(argv[2]);
    int T;
    if (!(ss >> T)) throw "Invalid number " + std::string(argv[2]) + '\n';
    
    PercolationStats ps(static_cast<size_t>(N), static_cast<size_t>(T));
    std::printf("Mean is: %f \n", ps.mean());
    std::printf("Stdev is: %f \n", ps.stdev());
    
    
    return 0;
}