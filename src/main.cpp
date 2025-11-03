#include "init.cpp"

int main() {
    string f = "../students.csv";
    DB database(Mode::BST);
    size_t s = 100;

    // tasks idx:
    //  1. phone num - 8
    //  2. group     - 6
    //  3. surname   - 1

    initialize(f, s, database, 1);
    vector<string> t = database.groups_by_surname("Шевченко");
    std::cout << database.bst.size() << std::endl;
    std::cout << t.size() << std::endl;
    int a = 0;

}