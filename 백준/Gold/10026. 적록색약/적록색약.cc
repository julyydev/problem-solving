#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N;
vector<vector<char>> vec;
vector<vector<bool>> isVisited;

void bfs(Point p, set<char> c) {
    queue<Point> q;
    q.push(p);
    isVisited[p.x][p.y] = true;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);
            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N)
                continue;
            if (c.find(vec[next.x][next.y]) != c.end() &&
                !isVisited[next.x][next.y]) {
                q.push(next);
                isVisited[next.x][next.y] = true;
            }
        }
    }

    return;
}

int countZone(set<char> c) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (c.find(vec[i][j]) != c.end() && !isVisited[i][j]) {
                bfs({i, j}, c);
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> N;
    vec.resize(N, vector<char>(N));
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) vec[i][j] = s[j];
    }

    isVisited.resize(N, vector<bool>(N, false));
    int red = countZone({'R'});
    int green = countZone({'G'});
    int blue = countZone({'B'});
    isVisited.clear();
    isVisited.resize(N, vector<bool>(N, false));
    int redGreen = countZone({'R', 'G'});
    cout << red + green + blue << " " << redGreen + blue << "\n";

    return 0;
}