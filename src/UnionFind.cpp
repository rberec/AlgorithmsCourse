#include "UnionFind.hpp"

void UnionFind::connect(size_t p, size_t q) {
    doConnect(p, q);
}

bool UnionFind::connected(size_t p, size_t q) {
    return doConnected(p, q);
}

bool QuickFindUF::doConnected(size_t p, size_t q) {
    return id_[p] == id_[q];
}

void QuickFindUF::doConnect(size_t p, size_t q) {
    size_t pid = id_[p];
    size_t qid = id_[q];

    for (size_t i = 0; i < id_.size(); ++i)
        if (id_[i] == pid) id_[i] = qid;
}

size_t QuickUnionUF::root(size_t p) {
    while (p != id_[p]) p = id_[p];
    return p;
}

bool QuickUnionUF::doConnected(size_t p, size_t q) {
    return root(p) == root(q);
}

void QuickUnionUF::doConnect(size_t p, size_t q) {
    size_t pid = root(p);
    size_t qid = root(q);

    id_[pid] = qid;
}

void WeightedQuickUnionUF::doConnect(size_t p, size_t q) {
    size_t pid = root(p);
    size_t qid = root(q);

    if (w_[pid] > w_[qid]) {
        id_[qid] = pid;
        w_[pid] += w_[qid];
    } else {
        id_[pid] = qid;
        w_[qid] += w_[pid];
    }
}

size_t PathCompressionWeightedQuickUnionUF::root(size_t p) {
    while (p != id_[p]) {
      id_[p] = id_[id_[p]];
      p = id_[p];
    }
    return p;
}

