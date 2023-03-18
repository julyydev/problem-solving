#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct compare {
    bool operator()(int &a, int &b) {
        if (a > 0) {
            if (b > 0)
                return a > b;
            else {
                if (a == -b) return true;
                return a > -b;
            }
        } else {
            if (b > 0) {
                if (-a == b) return false;
                return -a > b;
            } else
                return -a > -b;
        }
    }
};

int main() {
    FASTIO();
    int N, x;
    priority_queue<int, vector<int>, compare> pq;
    cin >> N;

    while (N--) {
        cin >> x;
        if (x == 0) {
            if (pq.size() == 0)
                cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else
            pq.push(x);
    }

    return 0;
}