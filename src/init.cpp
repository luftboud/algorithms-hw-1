#include <iostream>
#include <fstream>
#include "DB/DB.h"
#include <bits/stdc++.h>
using namespace std;

static vector<string> parse_csv_line(const string& str) {
    vector<string> out;
    string cur;
    out.reserve(9);

    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (c == ',') {
            out.push_back(cur);
            cur.clear();
        }
        else if (c == '\r') {}
        else {
            cur.push_back(c);
        }
    }
    out.push_back(cur);
    return out;
}

void initialize(string& filename, size_t limit, DB& db) {
    ifstream infile(filename);
    if (!infile) { cerr << "can't open file\n";}

    db.clear();
    if (db.mode == Mode::List) db.list.reserve(limit);
    if (db.mode == Mode::Hash) db.hash.reserve(limit);

    string line;
    getline(infile, line);

    while (getline(infile, line)){
        if (line.empty()) continue;
        auto cells = parse_csv_line(line);

        if (cells.size() != 9) {
            continue;
        }

        const string& key = cells[0];

        if (db.mode == Mode::List) {
            if (db.list.size() >= limit) break;
            db.list.push_back(std::move(cells));
        } else if (db.mode == Mode::Hash) {
            if (db.hash.size() >= limit) break;
            db.hash.emplace(key, std::move(cells));
        } else {
            if (db.bst.size() >= limit) break;
            db.bst.emplace(key, std::move(cells));
        }
    }
}