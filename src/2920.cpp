// https://www.acmicpc.net/problem/2920
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int n, ret;

    for (int i = 0; i < 8; i++) {
        cin >> n;
        vec.push_back(n);
    }

    vec[0] < vec[1] ? ret = 0 : ret = 1;
    for (int i = 1; i < 7; i++) {
        if ((ret == 0 && vec[i] > vec[i + 1]) || (ret == 1 && vec[i] < vec[i + 1])) {
            ret = 2;
            break;
        }
    }
    switch (ret) {
    case 0:
        cout << "ascending";
        break;
    case 1:
        cout << "descending";
        break;
    case 2:
        cout << "mixed";
        break;
    }
    
    return 0;
}
