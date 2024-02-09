#include <iostream>
using namespace std;

int cubes(int n) {
    return n * n * n;
}

int main() {
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b < a; b++) {
            for (int c = b + 1; c < a; c++) {
                for (int d = c + 1; d < a; d++) {
                    if (cubes(a) == cubes(b) + cubes(c) + cubes(d))
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                }
            }
        }
    }
}