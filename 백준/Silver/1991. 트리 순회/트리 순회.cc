#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    char left;
    char right;
    Node() : left('.'), right('.') {}
    Node(char left, char right) : left(left), right(right) {}
};

unordered_map<char, Node> tree;

void preorder(char node) {
    if (node == '.') return;
    cout << node;              
    preorder(tree[node].left);  
    preorder(tree[node].right); 
}

void inorder(char node) {
    if (node == '.') return;
    inorder(tree[node].left);   
    cout << node;               
    inorder(tree[node].right);  
}

void postorder(char node) {
    if (node == '.') return;
    postorder(tree[node].left); 
    postorder(tree[node].right);
    cout << node;               
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root] = Node(left, right); 
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}