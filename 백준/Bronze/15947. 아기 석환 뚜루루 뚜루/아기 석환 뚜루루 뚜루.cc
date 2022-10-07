// https://www.acmicpc.net/problem/15947
// written by julyy

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> vec = 
    {"baby", "sukhwan", "tururu", "turu",
    "very", "cute", "tururu", "turu",
    "in", "bed", "tururu", "turu",
    "baby", "sukhwan"};

    int N, rep;
    cin >> N;
    rep = (N - 1) / 14;

    if (((N - 1) % 14) % 4 == 0 || ((N - 1) % 14) % 4 == 1)
        cout << vec[((N - 1) % 14)];
    else if (((N - 1) % 14) % 4 == 2) {
        if (rep >= 3) {
            cout << "tu+ru*" << rep + 2;
        }
        else {
            cout << "tururu";
            for (int j = 0; j < rep; j++)
                cout << "ru";
        }
    }
    else {
        if (rep >= 4) {
            cout << "tu+ru*" << rep + 1;
        }
        else {
            cout << "turu";
            for (int j = 0; j < rep; j++)
                cout << "ru";
        }
    }
    
    return 0;
}

/*
    ios::sync_with_stdio(false);
    cin.tie(NULL);
*/