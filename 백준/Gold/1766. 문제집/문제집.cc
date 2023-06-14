#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Node {
    int in_degree;
    vector<int> outs;
    Node() {}
};

class Graph {
    int num_of_vertices;
    vector<Node> graph;

   public:
    Graph(int num_of_vertices) : num_of_vertices(num_of_vertices) {
        graph.reserve(num_of_vertices + 1);
    }

    void add_edge(int u, int v) {
        graph[v].in_degree++;
        graph[u].outs.push_back(v);
    }

    vector<int> topology_sort() {
        vector<int> result(num_of_vertices + 1);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i <= num_of_vertices; i++)
            if (graph[i].in_degree == 0) pq.push(i);

        for (int i = 1; i <= num_of_vertices; i++) {
            if (pq.empty()) return {};

            int cur = pq.top();
            pq.pop();
            result[i] = cur;

            for (const int& out : graph[cur].outs)
                if (--graph[out].in_degree == 0) pq.push(out);
        }

        return result;
    }
};

int main() {
    FASTIO();
    int N, M, A, B;
    cin >> N >> M;
    Graph graph(N);
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph.add_edge(A, B);
    }

    vector<int> result = graph.topology_sort();
    for (int i = 1; i <= N; i++) cout << result[i] << " ";
    cout << "\n";

    return 0;
}