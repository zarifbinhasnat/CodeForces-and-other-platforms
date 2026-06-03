#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int height;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balance_factor(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    void update_height(TreeNode* node) {
        while (node != nullptr) {
            node->height = 1 + max(height(node->left), height(node->right));
            node = node->parent;
        }
    }

    void insertion(int key) {
        TreeNode* newNode = new TreeNode(key);
        if (root == nullptr) {
            root = newNode;
            update_height(newNode);
            return;
        }

        TreeNode* current = root;
        TreeNode* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;
        if (key < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        update_height(newNode);
    }

    void inorder_with_balance(TreeNode* node) {
        if (node != nullptr) {
            inorder_with_balance(node->left);
            cout << node->data << "(" << balance_factor(node) << ") ";
            inorder_with_balance(node->right);
        }
    }
};

int main() {
    BST bst;
    int key;

    while (true) {
        cin >> key;
        if (key == -1) break;

        bst.insertion(key);
        bst.inorder_with_balance(bst.root);
        cout << endl;
    }

    return 0;
}
