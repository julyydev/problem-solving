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
    int n, m, c, a, b;
    cin >> n >> m;
    DisjointSet ds(n + 1);

    while (m--) {
        cin >> c >> a >> b;
        if (c == 0) {
            ds.merge(a, b);
        } else {
            if (ds.find(a) == ds.find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}