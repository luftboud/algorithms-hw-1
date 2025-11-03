#include "init.cpp"

int main() {
    string f = "../students.csv";
    DB database(Mode::BST);
    size_t s = 100;
    initialize(f, s, database);
}