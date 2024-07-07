#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Tree {
    int n;
    int root;
    vector<int> sub_vertex_nums;
    vector<unordered_set<int>> edges;

   public:
    Tree(int n, int r, const vector<unordered_set<int>>& edges)
        : n(n), root(r), edges(edges) {
        sub_vertex_nums.assign(n + 1, 0);
        dfs(root, -1);
    }

    int get_sub_vertex_nums(int u) { return sub_vertex_nums[u]; }

   private:
    void dfs(int node, int parent) {
        sub_vertex_nums[node] = 1;
        for (auto child : edges[node]) {
            if (child == parent) continue;
            dfs(child, node);
            sub_vertex_nums[node] += sub_vertex_nums[child];
        }
    }
};

int main() {
    FASTIO();
    int n, r, q, u, v;
    cin >> n >> r >> q;

    vector<unordered_set<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        edges[u].insert(v);
        edges[v].insert(u);
    }
    Tree tree(n, r, edges);

    for (int i = 0; i < q; i++) {
        cin >> u;
        cout << tree.get_sub_vertex_nums(u) << "\n";
    }

    return 0;
}
