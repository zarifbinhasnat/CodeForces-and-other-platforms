#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int height;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
};

class BST
{
public:
    TreeNode *root;

    BST() : root(nullptr) {}

    // Returns the height of a given node
    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Calculates the balance factor of a given node
    int balance_factor(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    // Updates the height of a node and all its ancestors
    void update_height(TreeNode *node)
    {
        while (node != nullptr)
        {
            node->height = 1 + max(height(node->left), height(node->right));
            node = node->parent;
        }
    }

    // Inserts a new key into the BST
    void insertion(int key)
    {
        TreeNode *newNode = new TreeNode(key);
        if (root == nullptr)
        {
            root = newNode;
            update_height(newNode);
            return;
        }

        TreeNode *current = root;
        TreeNode *parent = nullptr;

        // Iteratively find the parent node where new node should be added
        while (current != nullptr)
        {
            parent = current;
            if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }

        // Set the new node's parent and attach it as a child of the found parent
        newNode->parent = parent;
        if (key < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        // Update heights of all affected nodes
        update_height(newNode);
    }

    // In-order traversal that prints each node’s data with its balance factor
    void inorder_with_balance(TreeNode *node)
    {
        if (node != nullptr)
        {
            inorder_with_balance(node->left);
            cout << node->data << "(" << balance_factor(node) << ") ";
            inorder_with_balance(node->right);
        }
    }
    TreeNode *left_rotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // performing the rotation
        y->left = x;
        x->right = T2;

        if (t2 != nullptr)
            T2->parent = x;
            
        x->parent = y;
        update_height(x);
        update_height(y);
        // returning the new root of the rotated subtree
        return y;
    }
    TreeNode *right_rotate(TreeNode *x)
    {
        TreeNode *y = x->left;   // y is the left child of x
        TreeNode *T2 = y->right; // T2 is the right child of y

        // Perform rotation
        y->right = x;
        x->left = T2;

        // Update parents
        if (T2 != nullptr)
            T2->parent = x;
        y->parent = x->parent;
        x->parent = y;

        // Update the heights of x and y
        update_height(x);
        update_height(y);

        // Return new root of the rotated subtree
        return y;
    }
};

int main()
{
    BST bst;
    int key;

    while (true)
    {
        cin >> key;
        if (key == -1)
            break;

        bst.insertion(key);
        bst.inorder_with_balance(bst.root);
        cout << endl;
    }

    return 0;
}
