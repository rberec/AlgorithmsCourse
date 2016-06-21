#include <iostream>
#include <memory>
#include <UnionFind.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;

    std::unique_ptr<UnionFind> uf(new QuickFindUF(10));
    testUnionFind(uf.get());

    uf.reset(new QuickUnionUF(10));
    testUnionFind(uf.get());

    uf.reset(new WeightedQuickUnionUF(10));
    testUnionFind(uf.get());

    return 0;
}
