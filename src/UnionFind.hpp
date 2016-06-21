#pragma once
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <vector>

class UnionFind {
  public:
    bool connected(size_t p, size_t q) const;
    void connect(size_t p, size_t q);

  private:
    virtual bool doConnected(size_t p, size_t q) const = 0;
    virtual void doConnect(size_t p, size_t q) = 0;

  protected:
    UnionFind(size_t N):id_(N) {
        for (size_t i = 0; i < N; ++i)
            id_[i] = i;
    }

    std::vector<size_t> id_;
};

class QuickFindUF: public UnionFind {
  public:
    QuickFindUF(size_t N):UnionFind(N) { }

  private:
    bool doConnected(size_t p, size_t q) const;
    void doConnect(size_t p, size_t q);
};

class QuickUnionUF: public UnionFind {
  public:
    QuickUnionUF(size_t N):UnionFind(N) { }

  private:
    bool doConnected(size_t p, size_t q) const;
    void doConnect(size_t p, size_t q);

  protected:
    size_t root(size_t p) const;
};

class WeightedQuickUnionUF: public QuickUnionUF {
  public:
    WeightedQuickUnionUF(size_t N):
        QuickUnionUF(N),
        w_(N)
    {
        for (size_t i = 0; i < N; ++i)
            w_[i] = 1;
    }

private:
    std::vector<size_t> w_;
    void doConnect(size_t p, size_t q);
};

static void testUnionFind(UnionFind* uf) {

    uf->connect(0,1);
    uf->connect(1,5);

    std::cout << uf->connected(0,5) << std::endl;
    std::cout << uf->connected(0,9) << std::endl;
}
