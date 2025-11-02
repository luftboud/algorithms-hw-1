#include "init.cpp"

int main() {
    string f = "../students.csv";
    vector<vector<string>> database;
    size_t s = 100;
    initialize(f, s, &database);
}