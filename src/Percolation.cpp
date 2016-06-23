#include <iostream>

#include "Percolation.hpp"

Percolation::Percolation(size_t N)
:N_(N),
 uf_(new PathCompressionWeightedQuickUnionUF(N_*N_ + 2)),
 grid_(N_*N_, false)
{
  
}

bool Percolation::isOpen(size_t i, size_t j)
{
  return grid_[flatten(i,j)];
}


void Percolation::open(size_t i, size_t j) {
  grid_[flatten(i,j)] = true;
  
  if (i == 0) uf_->connect(0, flatten(i,j)+1);
  if (i == N_ - 1) uf_->connect(N_*N_ + 1, flatten(i,j)+1);
  
  if ((i > 0) && isOpen(i-1,j))
    uf_->connect(flatten(i,j)+1, flatten(i-1,j)+1);
  
  if ((i < N_ - 1) && isOpen(i+1,j))
    uf_->connect(flatten(i,j)+1, flatten(i+1,j)+1);
    
  if ((j > 0) && isOpen(i,j-1))
    uf_->connect(flatten(i,j)+1, flatten(i,j-1)+1);
  
  if ((j < N_ - 1) && isOpen(i,j+1))
    uf_->connect(flatten(i,j)+1, flatten(i,j+1)+1);
}



bool Percolation::percolates()
{
  return uf_->connected(0, N_*N_ + 1);
}

size_t Percolation::flatten(size_t i, size_t j)
{
  return (i * N_ + j);
}

void Percolation::display()
{
  for (size_t i = 0; i < N_; ++i) {
   for (size_t j = 0; j < N_; ++j) {
     
     if (uf_->connected(0, flatten(i, j) + 1)) 
       std::cout << " ";
     else if (grid_[flatten(i, j)])
       std::cout << "O";
     else
       std::cout << "X";
   }
   std::cout << std::endl;
  }
  std::cout << std::endl;
}



