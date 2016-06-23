#pragma once
#include "UnionFind.hpp"
#include <memory>
#include <vector>


//class UnionFind;

class Percolation {
  public:
    // create N-by-N grid, with all sites blocked
    Percolation(size_t N);
    
    // open site (row i, column j) if it is not open already
    void open(size_t i, size_t j);
    
    // is site (row i, column j) open?
    bool isOpen(size_t i, size_t j);
    
    // is site (row i, column j) full?
    bool isFull(size_t i, size_t j) {};
    
    // does the system percolate?
    bool percolates();
    
    // displays the grid
    void display();
    
  private:
    size_t N_;
    std::unique_ptr<UnionFind> uf_;
    std::vector<bool> grid_;
    
    size_t flatten(size_t i, size_t j);
};
