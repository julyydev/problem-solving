#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data) {
        left = NULL;
        right = NULL;
    }
};

class BST {
    Node* root;

   public:
    BST(int root_data) { root = new Node(root_data); }

   private:
    void _insert(const int& data, Node* node) {
        if (data < node->data) {
            if (node->left == NULL) {
                Node* temp = new Node(data);
                node->left = temp;
                return;
            }
            _insert(data, node->left);
            return;
        } else {
            if (node->right == NULL) {
                Node* temp = new Node(data);
                node->right = temp;
                return;
            }
            _insert(data, node->right);
            return;
        }
    }
    void _post_order_travel(Node* node) {
        if (node->left != NULL) _post_order_travel(node->left);
        if (node->right != NULL) _post_order_travel(node->right);
        cout << node->data << "\n";
        return;
    }

   public:
    void insert(int data) { _insert(data, root); }
    void post_order_travel() { _post_order_travel(root); }
};

int main() {
    FASTIO();
    int num;
    cin >> num;
    BST bst(num);

    while (cin >> num) bst.insert(num);
    bst.post_order_travel();

    return 0;
}