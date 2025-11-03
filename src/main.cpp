#include "bench_mode.hpp"

int main() {
    bench_mode(Mode::List, "list");
    bench_mode(Mode::Hash, "hash");
    bench_mode(Mode::BST,  "bst", true);
    return 0;
}