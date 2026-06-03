#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    // Helper function to get the height of a node
    int height(TreeNode* node) {
        return node == nullptr ? 0 : node->height;
    }

    // Helper function to calculate the balance factor of a node
    int balanceFactor(TreeNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Function to update the height of a node
    void updateHeight(TreeNode* node) {
        if (node != nullptr) {
            node->height = 
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    // Right rotation
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        // Return new root
        return x;
    }

    // Left rotation
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        // Return new root
        return y;
    }

    // Balances the tree at the given node
    TreeNode* balance(TreeNode* node) {
        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rightRotate(node);

        // Left Right Case
        if (balance > 1 && balanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(node->right) <= 0)
            return leftRotate(node);

        // Right Left Case
        if (balance < -1 && balanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;  // No rotation needed
    }

    // Recursive function to insert a new key and balance the tree
    TreeNode* insert(TreeNode* node, int key) {
        // Perform standard BST insertion
        if (node == nullptr)
            return new TreeNode(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;  // Duplicate keys not allowed in BST

        // Update height of this ancestor node
        updateHeight(node);

        // Balance the node if it has become unbalanced
        return balance(node);
    }

    // In-order traversal of the AVL tree
    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    TreeNode* root;

    AVLTree() : root(nullptr) {}

    // Public insert function
    void insert(int key) {
        root = insert(root, key);
    }

    // Public inorder traversal function
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    int values[] = {10, 20, 30, 40, 50, 25};
    for (int value : values) {
        tree.insert(value);
        cout << "Inorder traversal after insertion of " << value << ": ";
        tree.inorderTraversal();
    }

    return 0;
}
