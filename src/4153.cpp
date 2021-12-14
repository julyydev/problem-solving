// https://www.acmicpc.net/problem/4153
// written by julyy

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int triangle[3];

    while (1) {
        for (int i = 0; i < 3; i++) {
            cin >> triangle[i];
        }
        if (!triangle[0] && !triangle[1] && !triangle[2])
            break;
        sort(triangle, triangle + 3);
        if (triangle[2] * triangle[2] == triangle[0] * triangle[0] + triangle[1] * triangle[1])
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}
