#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Item {
    int w, v;
    Item() {}
    Item(int w, int v) : w(w), v(v) {}
};

int main() {
    FASTIO();
    int N, K, w, v;
    cin >> N >> K;
    vector<int> knapsack(K + 1, 0);
    vector<Item> items(K + 1);

    for (int i = 1; i <= N; i++) {
        cin >> w >> v;
        items[i] = {w, v};
    }

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 1; j--) {
            if (items[i].w <= j)
                knapsack[j] =
                    max(knapsack[j], knapsack[j - items[i].w] + items[i].v);
        }
    }
    cout << knapsack[K] << "\n";

    return 0;
}