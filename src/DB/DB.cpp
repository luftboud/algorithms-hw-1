#include "DB.hpp"

void DB::clear() { list.clear(); hash.clear(); bst.clear(); }

//change group ----------------
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

//find by group ----------------
vector<pair<string, string>> DB::find_by_group(const string& group){
    vector<pair<string, string>> result;
    if (this->mode == Mode::List) {
        result = this->find_bg_list(group);
    } else if (this->mode == Mode::Hash) {
        result = this->find_bg_hash(group);
    } else {
        result = this->find_bg_bst(group);
    }
    return result;
}

vector<pair<string, string>> DB::find_bg_list(const string& group){
    vector<pair<string, string>> result;
    if (this->mode != Mode::List) return result;

    for ( vector<string >& s : this->list)  {
        if (s[6] == group) {
            result.emplace_back(s[1], s[0]);
        }
    }
    return result;
}

vector<pair<string, string>> DB::find_bg_hash(const string& group){
    vector<pair<string, string>> result;
    if (this->mode != Mode::Hash) return result;

    result.reserve(this->hash.count(group));
    auto [it, last] = this->hash.equal_range(group);

    for (; it != last; ++it) {
        const vector<string >& student = it->second;
        result.emplace_back(student[1], student[0]);
    }
    return result;

}

vector<pair<string, string>> DB::find_bg_bst(const string& group){
    vector<pair<string, string>> result;
    if (this->mode != Mode::BST) return result;
    result.reserve(this->bst.count(group));

    auto [it, last] = this->bst.equal_range(group);
    for (; it != last; ++it) {
        const vector<string >& student = it->second;
        result.emplace_back(student[1], student[0]);
    }
    return result;
}

//groups by surname ------------

vector<string> DB::groups_by_surname(const string& surname) {
    vector<string> result;
    if (this->mode == Mode::List) {
        result = this->groups_bs_list(surname);
    } else if (this->mode == Mode::Hash) {
        result = this->groups_bs_hash(surname);
    } else {
        result = this->groups_bs_bst(surname);
    }
    return result;
}
vector<string > DB::groups_bs_list(const string& surname) {
    vector<string> result;
    if (this->mode != Mode::List) return result;

    std::unordered_set<std::string> seen; // that's so groups won't repeat

    for ( vector<string >& s : this->list)  {
        if (s[1] == surname) {
            if (seen.insert(s[6]).second) {// .second == true if val is not in seen yet
                result.emplace_back(s[6]);
            }
        }
    }
    return result;
}
vector<string > DB::groups_bs_hash(const string& surname) {
    vector<string> result;
    if (this->mode != Mode::Hash) return result;

    result.reserve(this->hash.count(surname));
    auto [it, last] = this->hash.equal_range(surname);

    std::unordered_set<std::string> seen; // that's so groups won't repeat

    for (; it != last; ++it) {
        const vector<string >& student = it->second;
        if (seen.insert(student[6]).second) {// .second == true if val is not in seen yet
            result.emplace_back(student[6]);
        }
    }

    return result;
}
vector<string > DB::groups_bs_bst(const string& surname) {
    vector<string> result;
    if (this->mode != Mode::BST) return result;

    result.reserve(this->bst.count(surname));
    auto [it, last] = this->bst.equal_range(surname);

    std::unordered_set<std::string> seen; // that's so groups won't repeat

    for (; it != last; ++it) {
        const vector<string >& student = it->second;
        if (seen.insert(student[6]).second) {// .second == true if val is not in seen yet
            result.emplace_back(student[6]);
        }
    }

    return result;
}
