#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Bridge {
    int num, weight;
    queue<int> q;

   public:
    Bridge() : num(0), weight(0) {}

    void enter(int w) {
        if (w != 0) num++;
        weight += w;
        q.push(w);
    }

    void leave() {
        if (q.front() != 0) num--;
        weight -= q.front();
        q.pop();
    }

    int get_total_num() { return num; }

    int get_total_weight() { return weight; }

    bool is_empty() { return q.empty(); }
};

int main() {
    FASTIO();
    int n, w, L;
    cin >> n >> w >> L;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    int time = 0, index = 0;
    Bridge bridge;
    while (1) {
        time++;
        if (time > w) bridge.leave();

        if (index == n) {
            if (bridge.is_empty())
                break;
            else
                continue;
        }

        if (bridge.get_total_num() < w &&
            bridge.get_total_weight() + weights[index] <= L)
            bridge.enter(weights[index++]);
        else
            bridge.enter(0);
    }

    cout << time << "\n";

    return 0;
}