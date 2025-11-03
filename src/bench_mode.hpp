#include "init.hpp"
#include <random>
#include <vector>
#include <string>

inline const vector<string>& pick_random_row(const DB& db, mt19937_64& rng);

void bench_mode(Mode mode, const char* mode_name);