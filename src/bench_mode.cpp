#include "init.cpp"

#include <random>
#include <vector>
#include <string>
#include <iterator> // std::advance

//just to randomly pick a value for func call
inline const vector<string>& pick_random_row(const DB& db, mt19937_64& rng) {
    static const vector<string> EMPTY;

    auto size_of = [&](Mode m)->size_t {
        if (m == Mode::List) return db.list.size();
        if (m == Mode::Hash) return db.hash.size();
        return db.bst.size();
    };

    size_t n = size_of(db.mode);
    if (n == 0) return EMPTY;

    uniform_int_distribution<size_t> dist(0, n - 1);
    size_t k = dist(rng);

    if (db.mode == Mode::List) {
        return db.list[k];
    } else if (db.mode == Mode::Hash) {
        auto it = db.hash.begin();
        advance(it, k);
        return it->second;
    } else { // mode::BST
        auto it = db.bst.begin();
        advance(it, k);
        return it->second;
    }
}


static void bench_mode(Mode mode, const char* mode_name) {
    using clock = chrono::steady_clock;
    mt19937_64 rng(1234567);

    uniform_int_distribution<int> pick(0, 64); //A:B:C

    const array<size_t,4> sizes = {100, 1000, 10000, 100000};

    std::cout << "mode,size,ops_total,op1,op2,op3\n";

    for (size_t n : sizes) {
        DB database1(mode);
        DB database2(mode);
        DB database3(mode);

        string f = "../students.csv";

        // tasks idx:
        size_t phone_num = 8; //1
        size_t group = 6; //2
        size_t surname = 1; //3

        initialize(f, n, database1, phone_num);
        initialize(f, n, database2, group);
        initialize(f, n, database3, surname);


        uint64_t c1=0, c2=0, c3=0;

        auto t0 = clock::now();
        while (chrono::duration<double>(clock::now() - t0).count() < 10.0) {
            int r = pick(rng);
            if (r < 5) {               // 5/65
                const auto& row1 = pick_random_row(database1, rng);
                const auto& row2 = pick_random_row(database1, rng);
                if (!row1.empty() && !row2.empty()) database1.change_st_group(row1[8], row2[6]); ++c1;
            } else if (r < 15) {       // 10/65 (бо 5..14)
                const auto& row = pick_random_row(database2, rng);
                if (!row.empty())database2.find_by_group( row[6]); ++c2;
            } else {                   // 50/65 (15..64)
                const auto& row = pick_random_row(database3, rng);
                if (!row.empty()) database3.groups_by_surname(row[1]); ++c3;
            }
        }
        uint64_t total = c1 + c2 + c3;
        std::cout << mode_name << "," << n << "," << total << "," << c1 << "," << c2 << "," << c3 << "\n";
    }
}
