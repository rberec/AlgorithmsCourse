#include "PercolationStats.hpp"
#include "Percolation.hpp"

#include <stdio.h>
#include <random>
#include <numeric>
#include <algorithm>

PercolationStats::PercolationStats(uint64_t N, uint64_t T)
{
  
  std::vector<double> fractions(T, 0);
  
  std::default_random_engine generator(42);
  std::uniform_int_distribution<uint64_t> distribution(0,N-1);
  
  
  for (uint64_t t = 0; t < T; ++t) {
    Percolation p(N);
    uint64_t n(0);
    while(!p.percolates()) {
      uint64_t i;
      uint64_t j;
      do {
	i = distribution(generator);
	j = distribution(generator);
      } while (p.isOpen(i,j));
      
      p.open(i,j);
      n++;
    }
    
    fractions[t] = static_cast<double>(n)/static_cast<double>(N*N);
    //p.display();
  }    
  
  
  double total = std::accumulate(fractions.begin(), fractions.end(), 0.0, std::plus<double>());
  
  mean_ = total/static_cast<double>(T);
  
  std::vector<double> diff(fractions.size());
  std::transform(fractions.begin(), fractions.end(), diff.begin(), [&](double x) { return x - mean_; });
  double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
  stdev_  = std::sqrt(sq_sum / static_cast<double>(T-1));
 
}
