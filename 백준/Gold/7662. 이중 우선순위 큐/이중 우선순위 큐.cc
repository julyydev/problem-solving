#include <iostream>
#include <queue>
#include <set>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int value, id;
    Data(int value, int id) : value(value), id(id){};
};

struct compareMin {
    bool operator()(const Data& a, const Data& b) { return a.value > b.value; }
};

struct compareMax {
    bool operator()(const Data& a, const Data& b) { return a.value < b.value; }
};

int main() {
    FASTIO();
    int T, k, n;
    string cmd;
    cin >> T;

    while (T--) {
        cin >> k;
        int id = 0;
        priority_queue<Data, vector<Data>, compareMin> min_heap;
        priority_queue<Data, vector<Data>, compareMax> max_heap;
        set<int> set;

        while (k--) {
            cin >> cmd >> n;
            if (cmd == "I") {
                min_heap.push({n, id});
                max_heap.push({n, id});
                set.insert(id++);
            } else if (cmd == "D") {
                if (set.empty()) continue;
                if (n == 1) {
                    while (!max_heap.empty() &&
                           set.find(max_heap.top().id) == set.end())
                        max_heap.pop();
                    set.erase(max_heap.top().id);
                    max_heap.pop();
                    while (!max_heap.empty() &&
                           set.find(max_heap.top().id) == set.end())
                        max_heap.pop();
                } else if (n == -1) {
                    while (!min_heap.empty() &&
                           set.find(min_heap.top().id) == set.end())
                        min_heap.pop();
                    set.erase(min_heap.top().id);
                    min_heap.pop();
                    while (!min_heap.empty() &&
                           set.find(min_heap.top().id) == set.end())
                        min_heap.pop();
                }
            }
        }
        while (!max_heap.empty() && set.find(max_heap.top().id) == set.end())
            max_heap.pop();
        while (!min_heap.empty() && set.find(min_heap.top().id) == set.end())
            min_heap.pop();

        if (set.empty())
            cout << "EMPTY\n";
        else
            cout << max_heap.top().value << " " << min_heap.top().value << "\n";
    }

    return 0;
}