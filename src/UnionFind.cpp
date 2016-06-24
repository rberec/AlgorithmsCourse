#include "UnionFind.hpp"

void UnionFind::connect(uint64_t p, uint64_t q) {
    doConnect(p, q);
}

bool UnionFind::connected(uint64_t p, uint64_t q) {
    return doConnected(p, q);
}

bool QuickFindUF::doConnected(uint64_t p, uint64_t q) {
    return id_[p] == id_[q];
}

void QuickFindUF::doConnect(uint64_t p, uint64_t q) {
    uint64_t pid = id_[p];
    uint64_t qid = id_[q];

    for (uint64_t i = 0; i < id_.size(); ++i)
        if (id_[i] == pid) id_[i] = qid;
}

uint64_t QuickUnionUF::root(uint64_t p) {
    while (p != id_[p]) p = id_[p];
    return p;
}

bool QuickUnionUF::doConnected(uint64_t p, uint64_t q) {
    return root(p) == root(q);
}

void QuickUnionUF::doConnect(uint64_t p, uint64_t q) {
    uint64_t pid = root(p);
    uint64_t qid = root(q);

    id_[pid] = qid;
}

void WeightedQuickUnionUF::doConnect(uint64_t p, uint64_t q) {
    uint64_t pid = root(p);
    uint64_t qid = root(q);

    if (w_[pid] > w_[qid]) {
        id_[qid] = pid;
        w_[pid] += w_[qid];
    } else {
        id_[pid] = qid;
        w_[qid] += w_[pid];
    }
}

uint64_t PathCompressionWeightedQuickUnionUF::root(uint64_t p) {
    while (p != id_[p]) {
      id_[p] = id_[id_[p]];
      p = id_[p];
    }
    return p;
}

