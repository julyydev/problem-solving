#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

vector<int> inorder, postorder, indexs;

void recursion(const int& in_index, const int& post_index, const int& size) {
    cout << postorder[post_index + size - 1] << " ";
    int target = indexs[postorder[post_index + size - 1]];
    int left_size = target - in_index;
    int right_size = size - left_size - 1;

    if (left_size) recursion(in_index, post_index, left_size);
    if (right_size) recursion(target + 1, post_index + left_size, right_size);

    return;
}

int main() {
    FASTIO();
    int n;
    cin >> n;
    inorder.resize(n), postorder.resize(n), indexs.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        indexs[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++) cin >> postorder[i];
    recursion(0, 0, postorder.size());
    cout << "\n";

    return 0;
}