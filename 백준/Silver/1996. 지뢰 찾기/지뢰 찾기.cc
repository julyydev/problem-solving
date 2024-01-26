#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) {}
};

const int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> input(n, vector<int>(n));
    vector<vector<char>> map(n, vector<char>(n));
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '.') input[i][j] = 0;
            else { 
                input[i][j] = c - '0';
                map[i][j] = '*';
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '*') continue;
            
            int sum = 0;
            for (int k = 0; k < 9; k++) {
                Point next(i + dx[k], j + dy[k]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;
                sum += input[next.x][next.y];
            }
            
            if (sum >= 10) map[i][j] = 'M';
            else map[i][j] = '0' + sum;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << map[i][j];
        cout << "\n";
    }
    
    return 0;
}