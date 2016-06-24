#pragma once
#include "UnionFind.hpp"

#include <memory>
#include <vector>
#include <stdint.h>


//class UnionFind;

class Percolation {
  public:
    // create N-by-N grid, with all sites blocked
    Percolation(uint64_t N);
    
    // open site (row i, column j) if it is not open already
    void open(uint64_t i, uint64_t j);
    
    // is site (row i, column j) open?
    bool isOpen(uint64_t i, uint64_t j);
    
    // is site (row i, column j) full?
    bool isFull(uint64_t i, uint64_t j) {};
    
    // does the system percolate?
    bool percolates();
    
    // displays the grid
    void display();
    
  private:
    uint64_t N_;
    std::unique_ptr<UnionFind> uf_;
    std::vector<bool> grid_;
    
    uint64_t flatten(uint64_t i, uint64_t j);
};
