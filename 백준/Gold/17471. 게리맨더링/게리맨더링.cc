#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int DISABLE = 100000000;

class Gerrymandering {
    int n, total_people = 0, min_value = DISABLE;
    vector<int> people;
    vector<vector<int>> graph;

   public:
    Gerrymandering() {}

    void init() {
        int k;
        cin >> n;

        people.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> people[i];
            total_people += people[i];
        }

        graph.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> k;
            graph[i].resize(k);
            for (int j = 0; j < k; j++) cin >> graph[i][j];
        }
    }

    void divide() {
        for (int bit_mask = 0; bit_mask < (1 << n); bit_mask++) {
            if (!(bit_mask & 1)) {
                int sum = 0;
                for (int j = 1; j <= n; j++) {
                    if (bit_mask & (1 << j)) {
                        sum += people[j];
                    }
                }
                if (!is_connected(bit_mask) || !is_connected(~bit_mask - 1))
                    continue;

                min_value = min(min_value, abs(total_people - 2 * sum));
            }
        }
    }

    bool is_connected(int bit_mask) {
        bit_mask &= (1 << (n + 1)) - 1;
        queue<int> q;
        int bit_visited = 0;

        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (bit_mask & (1 << i)) {
                start = i;
                break;
            }
        }

        q.push(start);
        bit_visited |= (1 << start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                if (!(bit_visited & (1 << next)) && bit_mask & (1 << next)) {
                    bit_visited |= (1 << next);
                    q.push(next);
                }
            }
        }

        return bit_mask == bit_visited;
    }

    int get_min_value() { return (min_value == DISABLE ? -1 : min_value); }
};

int main() {
    FASTIO();
    Gerrymandering gerrymandering;
    gerrymandering.init();
    gerrymandering.divide();
    cout << gerrymandering.get_min_value() << "\n";

    return 0;
}