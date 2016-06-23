#include <iostream>
#include <string>
#include <memory>
#include <sstream>

#include <UnionFind.hpp>
#include <PercolationStats.hpp>

int main(int argc, char *argv[])
{
    if ( argc == 1 ) {
      PercolationStats ps(200,100);
      
      std::printf("Mean is: %f \n", ps.mean());
      std::printf("Stdev is: %f \n", ps.stdev());
    }
    
    else {
      if ( std::string(argv[1]) == "Percolation") {
	if (argc != 4) throw "Not enough parameters for Percolation";
	
	std::istringstream ss(argv[2]);
	int N;
	if (!(ss >> N))
	    throw "Invalid number " + std::string(argv[2]) + '\n';
	
	
	ss.clear();
	ss.str(argv[3]);
	int T;
	if (!(ss >> T))
	    throw "Invalid number " + std::string(argv[3]) + '\n';
	
	PercolationStats ps(static_cast<size_t>(N), static_cast<size_t>(T));
	std::printf("Mean is: %f \n", ps.mean());
	std::printf("Stdev is: %f \n", ps.stdev());
      }
      
      if ( std::string(argv[1]) == "UnitFind") {
	std::unique_ptr<UnionFind> uf(new QuickFindUF(10));
	testUnionFind(uf.get());

	uf.reset(new QuickUnionUF(10));
	testUnionFind(uf.get());

	uf.reset(new WeightedQuickUnionUF(10));
	testUnionFind(uf.get());
	
	uf.reset(new PathCompressionWeightedQuickUnionUF(10));
	testUnionFind(uf.get());
      }
    }
    
    return 0;
}
