#include <iostream>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

   public:
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);

        if (px == py) return;
        parent[px] = py;
    }

    int get_sets_number() {
        set<int> s;
        for (int p : parent) s.insert(find(p));
        return s.size();
    }
};

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;
    DisjointSet ds(N * M);

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            int cur = i * M + j, next;
            if (s[j] == 'U')
                next = cur - M;
            else if (s[j] == 'D')
                next = cur + M;
            else if (s[j] == 'L')
                next = cur - 1;
            else
                next = cur + 1;
            ds.merge(cur, next);
        }
    }

    cout << ds.get_sets_number() << "\n";

    return 0;
}