# Homework 1
Author: Iia Maharyta <br>
V3, S7. <br>

To run the benchmark:
```shell
cd src
g++     -std=c++20 -O2 -DNDEBUG -I. DB/DB.cpp init.cpp bench_mode.cpp main.cpp -o app && ./app
```