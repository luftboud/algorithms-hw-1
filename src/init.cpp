#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

static vector<string> parse_csv_line(const string& str) {
    vector<string> out;
    string cur;

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

void initialize(string& filename, size_t& s, vector<vector<string>>* db) {
    ifstream infile(filename);
    if (!infile) { cerr << "can't open file\n";}

    (*db).clear();
    (*db).reserve(s);

    string line;
    getline(infile, line);
    while ((*db).size() < s && getline(infile, line)){
        if (line.empty()) continue;
        auto cells = parse_csv_line(line);

        if (cells.size() != 9) {
            continue;
        }

        (*db).push_back(move(cells));
    }
}