#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    char left;
    char right;
};

void preorder(vector<Node> tree, int i) {
    cout << tree[i].data;

    if (tree[i].left != '.') {
        preorder(tree, tree[i].left - 'A');
    }

    if(tree[i].right != '.') {
        preorder(tree, tree[i].right - 'A');
    }

    return;
}

void inorder(vector<Node> tree, int i) {
    if (tree[i].left != '.') {
        inorder(tree, tree[i].left - 'A');
    }

    cout << tree[i].data;

    if(tree[i].right != '.') {
        inorder(tree, tree[i].right - 'A');
    }

    return;
}

void postorder(vector<Node> tree, int i) {
    if (tree[i].left != '.') {
        postorder(tree, tree[i].left - 'A');
    }

    if(tree[i].right != '.') {
        postorder(tree, tree[i].right - 'A');
    }
    
    cout << tree[i].data;

    return;
}

int main() {
    int N;
    cin >> N;
    vector<Node> tree;

    for (int i = 0; i < N; i++) {
        Node node;
        cin >> node.data >> node.left >> node.right;
        tree.push_back(node);
    }

    sort(tree.begin(), tree.end(), [](Node a, Node b){return a.data < b.data;});

    preorder(tree, 0);
    cout << '\n';
    inorder(tree, 0);
    cout << '\n';
    postorder(tree, 0);
    cout << '\n';

    return 0;
}