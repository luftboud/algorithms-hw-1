#include <bits/stdc++.h>
using namespace std;

enum class Mode { List, Hash, BST };

struct DB {
    Mode mode;
    vector<vector<string>> list;
    unordered_multimap<string, vector<string>> hash;
    multimap<string, vector<string>> bst;

    explicit DB(Mode m): mode(m) {}
    void clear() { list.clear(); hash.clear(); bst.clear(); }
};