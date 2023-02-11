#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int parent;
    vector<int> children;
};

int main() {
    int N, p, d;
    cin >> N;

    vector<Node> tree(N);

    for (int i = 0; i < N; i++) {
        cin >> p;
        if (p == -1) continue;
        tree[i].parent = p;
        tree[p].children.push_back(i);
    }

    cin >> d;

    int total_leaf = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i].children.size() == 0) total_leaf++;
        // cout << "[" << i << "] ";
        // for (auto it = tree[i].children.begin(); it != tree[i].children.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout << "- " << tree[i].children.size() << "개\n";
    }

    // cout << "total_leaf: " << total_leaf << '\n';

    queue<int> q;
    q.push(d);
    int delete_leaf = 0;
    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            int front = q.front();
            q.pop();

            if (tree[front].children.size() == 0) {
                delete_leaf++;
                continue;
            }

            for (auto it = tree[front].children.begin(); it != tree[front].children.end(); it++) {
                q.push(*it);
            }    
        }
    }

    if (tree[d].parent == -1) {
        cout << 0 << '\n';
        return 0;
    }
    // cout << "delete_leaf: " << delete_leaf << '\n';

    cout << total_leaf - delete_leaf + ((tree[tree[d].parent].children.size() == 1) ? 1 : 0) << '\n';


    return 0;
}