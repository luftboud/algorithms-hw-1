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

    void change_group_list(const string& phone, const string& group);
    void change_group_hash(const string& phone, const string& group);
    void change_group_bst(const string& phone, const string& group);

    // this func is used for changing a group of needed student
    // by finding him with his phone number
    // ATTENTION: the bst or hash-table MUST BE STRUCTURED accordingly
    // to the object of the search. in this case it means you are obligated to
    // give each value (student data) a key represented as the phone number.
    // also, it is pretty simple cuz it just calls one of the three funcs
    // accordingly to the data type.
    void change_st_group(const string& phone, const string& group);
};