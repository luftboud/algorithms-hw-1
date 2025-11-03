#include "bench_mode.cpp"

int main() {
    bench_mode(Mode::List, "list");
    bench_mode(Mode::Hash, "hash");
    bench_mode(Mode::BST,  "bst");
    return 0;

}