// https://www.acmicpc.net/problem/2309
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec;
    int height, sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> height;
        sum += height;
        vec.push_back(height);
    }
    sort(vec.begin(), vec.end());
    sum -= 100;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (vec[i] + vec[j] == sum) {
                vec.erase(vec.begin() + j);
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }

    for (int i = 0; i < 7; i++)
        cout << vec[i] << '\n';
    
    return 0;
}
