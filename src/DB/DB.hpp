#include <bits/stdc++.h>
using namespace std;

enum class Mode { List, Hash, BST };

struct DB {
    // this is a class used for creating the needed data structure
    // you can make it into a hash-table, a binary search tree or a simple list
    // just describe the mode when using constructor
    Mode mode;
    vector<vector<string>> list;
    unordered_map<string, vector<string>> hash;
    multimap<string, vector<string>> bst;

    explicit DB(Mode m): mode(m) {}
    void clear();
