#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class MedianHeap {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

   public:
    MedianHeap() {}

    void insert(int x) {
        if (max_heap.empty() || x < max_heap.top())
            max_heap.push(x);
        else
            min_heap.push(x);

        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (min_heap.size() < max_heap.size() - 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    int top() { return max_heap.top(); }
};

int main() {
    FASTIO();
    int n, x;
    cin >> n;

    MedianHeap median_heap;

    for (int i = 0; i < n; i++) {
        cin >> x;
        median_heap.insert(x);
        cout << median_heap.top() << "\n";
    }

    return 0;
}