#pragma once
#include <stdlib.h>

class PercolationStats {
  public:
    // perform T independent experiments on an N-by-N grid
    PercolationStats(size_t N, size_t T);   
    
    // sample mean of percolation threshold
    double mean() const {return mean_;};
    
    // sample standard deviation of percolation threshold
    double stdev() const {return stdev_;};
    
    // low  endpoint of 95% confidence interval
    double confidenceLo();   
    
    // high endpoint of 95% confidence interval
    double confidenceHi(); 
    
  private:
    double mean_;
    double stdev_;
};

