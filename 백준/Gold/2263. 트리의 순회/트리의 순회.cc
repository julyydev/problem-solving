#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

vector<int> inorder, postorder;

void recursion(const int& inorder_index, const int& postorder_index,
               const int& size) {
    cout << postorder[postorder_index + size - 1] << " ";
    int in_index = find(inorder.begin(), inorder.end(),
                        postorder[postorder_index + size - 1]) -
                   inorder.begin();
    int left_size = in_index - inorder_index;
    int right_size = size - left_size - 1;

    if (left_size) recursion(inorder_index, postorder_index, left_size);
    if (right_size)
        recursion(in_index + 1, postorder_index + left_size, right_size);

    return;
}

int main() {
    FASTIO();
    int n;
    cin >> n;
    inorder.resize(n), postorder.resize(n);

    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    recursion(0, 0, postorder.size());
    cout << "\n";

    return 0;
}