#include <bits/stdc++.h>
using namespace std;

enum class Mode { List, Hash, BST };

struct DB {
    // this is a class used for creating the needed data structure
    // you can make it into a hash-table, a binary search tree or a simple list
    // just describe the mode when using constructor
    Mode mode;
    vector<vector<string>> list;
    unordered_multimap<string, vector<string>> hash;
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

    vector<pair<string, string>> find_bg_list(const string& group);
    vector<pair<string, string>> find_bg_hash(const string& group);
    vector<pair<string, string>> find_bg_bst(const string& group);

    vector<pair<string, string>> find_by_group(const string& group);

    vector<string > groups_bs_list(const string& surname);
    vector<string> groups_bs_hash(const string& surname);
    vector<string> groups_bs_bst(const string& surname);


    vector<string > groups_by_surname(const string& surname);

    static void write_csv_row(std::ofstream& out, const vector<string>& row);
    inline void save_csv(const string& filename,
                         const vector<vector<string>>& rows,
                         const string* header_line = nullptr);
    void standard_sort(bool write_csv);
    void bst_sort(bool write_csv);
};