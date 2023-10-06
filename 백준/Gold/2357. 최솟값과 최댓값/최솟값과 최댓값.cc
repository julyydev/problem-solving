#include <cmath>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int min, max;
    Data() {}
    Data(int min, int max) : min(min), max(max) {}
};

struct Node {
    int start, end;
    Data data;
    Node() {}
    Node(int start, int end, Data data) : start(start), end(end), data(data) {}
};

class SegmentTree {
    int n;
    vector<Node> nodes;

   public:
    SegmentTree() {}

   private:
    Node _init(const vector<int>& nums, int index, int start, int end) {
        if (start == end) {
            return nodes[index] =
                       Node(start, end, {nums[start - 1], nums[start - 1]});
        }

        Node left = _init(nums, index * 2, start, (start + end) / 2);
        Node right = _init(nums, index * 2 + 1, (start + end) / 2 + 1, end);
        return nodes[index] = Node(start, end,
                                   {min(left.data.min, right.data.min),
                                    max(left.data.max, right.data.max)});
    }

   public:
    void init(const vector<int>& nums) {
        n = nums.size();
        int h = (int)ceil(log2(n));
        nodes.resize(1 << (h + 1));

        _init(nums, 1, 1, n);
    }

    Data query(int left, int right, int index) {
        if (nodes[index].start == left && nodes[index].end == right)
            return nodes[index].data;

        if (left > nodes[2 * index].end)
            return query(left, right, index * 2 + 1);
        else if (right < nodes[2 * index + 1].start)
            return query(left, right, index * 2);

        Data l = query(left, nodes[2 * index].end, index * 2);
        Data r = query(nodes[2 * index + 1].start, right, index * 2 + 1);
        return {min(l.min, r.min), max(l.max, r.max)};
    }
};

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];

    SegmentTree segment_tree;
    segment_tree.init(nums);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Data data = segment_tree.query(a, b, 1);
        cout << data.min << " " << data.max << "\n";
    }

    return 0;
}