#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int value;
    string commands;
    Data(int value, string commands) : value(value), commands(commands) {}
};

vector<bool> isVisited;

int D(int n) { return 2 * n % 10000; }

int S(int n) { return (n + 9999) % 10000; }

int L(int n) { return n % 1000 * 10 + n / 1000; }

int R(int n) { return n % 10 * 1000 + n / 10; }

int (*command[4])(int n) = {D, S, L, R};
string c[4] = {"D", "S", "L", "R"};

string bfs(int src, int dst) {
    int temp;
    queue<Data> q;
    q.push({src, ""});
    isVisited[src] = true;

    while (!q.empty()) {
        Data cur = q.front();
        q.pop();
        if (cur.value == dst) return cur.commands;

        for (int i = 0; i < 4; i++) {
            temp = command[i](cur.value);
            if (!isVisited[temp]) {
                q.push({temp, cur.commands + c[i]});
                isVisited[temp] = true;
            }
        }
    }

    return "-";
}

int main() {
    FASTIO();
    int T, A, B;
    cin >> T;

    while (T--) {
        cin >> A >> B;
        isVisited.clear();
        isVisited.resize(10000, false);
        cout << bfs(A, B) << "\n";
    }

    return 0;
}