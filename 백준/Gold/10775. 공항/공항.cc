#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class DisjointSet {
    vector<int> parent;

   public:
    DisjointSet(int n) : parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool merge(int x, int y) {
        int px = find(x), py = find(y);

        if (px == py) return false;
        parent[px] = py;
        return true;
    }
};

int main() {
    FASTIO();
    int G, P, g;
    cin >> G >> P;

    DisjointSet disjoint_set(G + 1);

    int count = 0;
    bool flag = true;
    for (int i = 0; i < P; i++) {
        cin >> g;
        if (!flag) continue;

        int index = disjoint_set.find(g);
        if (index == 0) {
            flag = false;
            continue;
        }

        disjoint_set.merge(index, index - 1);
        count++;
    }

    cout << count << "\n";

    return 0;
}