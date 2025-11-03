#include <iostream>
#include <fstream>
#include "DB/DB.hpp"
#include <bits/stdc++.h>
using namespace std;

static vector<string> parse_csv_line(const string& str);
void initialize(string& filename, size_t limit, DB& db, size_t task_idx);