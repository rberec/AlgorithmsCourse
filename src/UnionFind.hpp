#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory>
#include <vector>

class UnionFind {
  public:
    bool connected(uint64_t p, uint64_t q);
    void connect(uint64_t p, uint64_t q);

  private:
    virtual bool doConnected(uint64_t p, uint64_t q) = 0;
    virtual void doConnect(uint64_t p, uint64_t q) = 0;

  protected:
    UnionFind(uint64_t N):id_(N) {
        for (uint64_t i = 0; i < N; ++i)
            id_[i] = i;
    }

    std::vector<uint64_t> id_;
};

class QuickFindUF: public UnionFind {
  public:
    QuickFindUF(uint64_t N):UnionFind(N) { }

  private:
    bool doConnected(uint64_t p, uint64_t q);
    void doConnect(uint64_t p, uint64_t q);
};

class QuickUnionUF: public UnionFind {
  public:
    QuickUnionUF(uint64_t N):UnionFind(N) { }

  private:
    bool doConnected(uint64_t p, uint64_t q);
    void doConnect(uint64_t p, uint64_t q);

  protected:
    uint64_t root(uint64_t p);
};

class WeightedQuickUnionUF: public QuickUnionUF {
  public:
    WeightedQuickUnionUF(uint64_t N):
        QuickUnionUF(N),
        w_(N)
    {
        for (uint64_t i = 0; i < N; ++i)
            w_[i] = 1;
    }

private:
    std::vector<uint64_t> w_;
    void doConnect(uint64_t p, uint64_t q);
};

class PathCompressionWeightedQuickUnionUF: public WeightedQuickUnionUF {
  public:
    PathCompressionWeightedQuickUnionUF(uint64_t N):WeightedQuickUnionUF(N) { };
    
  protected:
    uint64_t root(uint64_t p);
};
  

static void testUnionFind(UnionFind* uf) {

    uf->connect(0,1);
    uf->connect(1,5);

    std::printf("%d\n", uf->connected(0,5));
    std::printf("%d\n", uf->connected(0,9));
}
