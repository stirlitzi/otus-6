#include "matrix.h"
#include <iostream>
#include <cassert>
#include <map>
#include <tuple>


using namespace std;




int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    Matrix<int, 0> matrix;

    for (int i = 0; i < 10; i++)
        matrix[i][i] = i;

    for (int i = 0; i < 10; i++)
        matrix[0 + i][9 - i] = 9 - i;

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "size: " << matrix.size() << '\n';

    for (const auto &e: matrix) {
        const int x = e.first.first;
        const int y = e.first.second;
        const int v = e.second;
        cout << x << ' ' << y << ' ' << v << '\n';
    }


    return 0;
}
