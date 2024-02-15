#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Rectangle {
    int h, w;
    Rectangle(int h, int w): h(h), w(w) {}
    bool operator==(const Rectangle& r) const {
        return h == r.h && w == r.w;
    }
    bool operator<(const Rectangle& r) const {
        if (h * h + w * w == r.h * r.h + r.w * r.w)
            return h > r.h;
        return h * h + w * w > r.h * r.h + r.w * r.w;
    }
};

int main() {
    priority_queue<Rectangle> pq;
    for (int i = 1; i < 150; i++)
        for (int j = i + 1; j <= 150; j++)
            pq.push({i, j});
    
    vector<int> v(pq.size());
    int i = 0;
    while (!pq.empty()) {
        v[i] = pq.top().h * 1000 + pq.top().w;
        pq.pop();
        i++;
    }
    
    int h, w;
    while (1) {
        cin >> h >> w;
        if (!h && !w) break;
        
        int target = *(find(v.begin(), v.end(), h * 1000 + w) + 1);
        cout << target / 1000 << " " << target % 1000 << "\n";
    }
    
    return 0;
}