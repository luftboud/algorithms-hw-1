#include "DB.hpp"

void DB::clear() { list.clear(); hash.clear(); bst.clear(); }

void DB::change_st_group(const string& phone, const string& group){
    if (this->mode == Mode::List) {
        this->change_group_list(phone, group);
    } else if (this->mode == Mode::Hash) {
        this->change_group_hash(phone, group);
    } else {
        this->change_group_bst(phone, group);
    }
}

void DB::change_group_list(const string& phone, const string& group) {
    if (this->mode != Mode::List) return;
    size_t n = this->list.size(); //size of db

    for (size_t i = 0; i < n; ++i) {
        vector current_st = this->list[i];
        if (current_st[8] == phone) {
            this->list[i][6] = group;
            return;
        }
    }
}

void DB::change_group_hash(const string& phone, const string& group) {
    if (this->mode != Mode::Hash) return;

    auto current_st = this->hash.find(phone);
    if (current_st == this->hash.end()) return;

    current_st->second[6] = group;
}

void DB::change_group_bst(const string& phone, const string& group) {
    if (this->mode != Mode::BST) return;
    auto current_st = this->bst.lower_bound(phone);
    if (current_st == this->bst.end() || current_st->first != phone) return;
    current_st->second[6] = group;
}