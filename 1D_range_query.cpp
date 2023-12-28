#include <iostream>
#define el '\n'
using namespace std;

struct Node {

    int info { };
    int idx {};
    Node* left { };
    Node* right { };
    
    Node(int info) {
        this->info = info;
        left = right = nullptr;
    }
    
    void insert_node(int v) {
        if (v < info) {
            if (!left)
                left = new Node(v);
            else
                left->insert_node(v);
        }
        else if (v > info) {
            if (!right)
                right = new Node(v);
            else
                right->insert_node(v);
        }
    }
};

struct BST {
    
    Node* root { };
    
    BST() {
        root = nullptr;
    }

    void insert(int v) {
        if (!root) root = new Node(v);
        else root->insert_node(v);
    }

    void printInOrder(Node* node) {
        if (node) {
            printInOrder(node->left);
            cout << node->info << " " << node->idx << el;
            printInOrder(node->right);
        }
    }
    
    void modify_indices(Node* node, int &idx) {
        if (node) {
            modify_indices(node->left, idx);
            node->idx = idx++;
            modify_indices(node->right, idx);
        }
    }
    
    int get_node_idx(Node* node, int val) {
        int idx = 0;
        while (node) {
            idx = node->idx;
            if (val < node->info && node->left && node->left->info > val) {
                node = node->left;
            }
            else if (val > node->info && node->right && node->right->info < val) {
                node = node->right;
            }
            else {
                break;
            }
        }
        return idx;
    }
};

void ReadBinaryTree(BST &tree) {
    vector<int> vals {5, 3, 7, 2, 4, 10, 8};
    for (int &i : vals)
        tree.insert(i);
}

int32_t main() {
    BST tree;
    ReadBinaryTree(tree);
    
    int first_idx = 0;
    tree.modify_indices(tree.root, first_idx);
    
    cout << tree.get_node_idx(tree.root, 8) - tree.get_node_idx(tree.root, 6) + 1 << el;
    
}

