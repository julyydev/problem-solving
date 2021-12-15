// https://www.acmicpc.net/problem/1018
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> correct = {
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'}};

int compare_chess_block(vector<vector<char>> chess, int x, int y) {
    int num = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(correct[i][j] != chess[i + x][j + y])
                num++;
        }
    }

    if (num > 32)
        num = 64 - num;

    return num;
}

int main() {
    int M, N, min = 32;
    cin >> M >> N;

    vector<vector<char>> chess(M, vector<char>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chess[i][j];
        }
    }

    for (int i = 0; i <= M - 8; i++) {
        for (int j = 0; j <= N - 8; j++) { // (i, j) 왼쪽 위, 총 경우 (M - 7) * (N - 7)
            int ret = compare_chess_block(chess, i, j);
            if (min > ret)
                min = ret;
        }
    }
    cout << min;
    
    return 0;
}
