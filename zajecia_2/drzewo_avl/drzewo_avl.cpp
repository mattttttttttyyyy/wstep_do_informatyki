//Drzewa AVL to rodzaj samobalansującego drzewa binarnego, które zapewnia, że różnica wysokości pomiędzy lewym a prawym poddrzewem 
//każdego węzła jest nie większa niż 1. Dzięki temu operacje wyszukiwania, wstawiania i usuwania mają gwarantowaną złożoność O(logn).

//Kluczowe operacje w drzewach AVL:
//Rotacje:
//Rotacja w lewo (LL)
//Rotacja w prawo (RR)
//Rotacja w lewo-prawo (LR)
//Rotacja w prawo-lewo (RL)
//Wstawianie: wstawienie nowego węzła z zachowaniem zrównoważenia drzewa.
//Usuwanie: usunięcie węzła z zachowaniem zrównoważenia drzewa.
//Poniżej znajduje się przykładowa implementacja drzewa AVL w C++:

#include <iostream>

using namespace std;

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* insert(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left)
        current = current->left;
    return current;
}

AVLNode* deleteNode(AVLNode* root, int key) {
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void preOrder(AVLNode* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    AVLNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);
    cout << endl;

    root = deleteNode(root, 40);

    cout << "Preorder traversal after deletion of 40:\n";
    preOrder(root);
    cout << endl;

    return 0;
}

//Opis działania
//Wstawianie: Wstawia węzeł do drzewa, po czym balansuje drzewo za pomocą odpowiednich rotacji.
//Usuwanie: Usuwa węzeł z drzewa, a następnie balansuje drzewo za pomocą odpowiednich rotacji.
//Preorder traversal: Wypisuje węzły drzewa w porządku pre-order.
//Program pokazuje wstawianie, usuwanie i przegląd pre-order drzewa AVL. Można go rozbudować o dodatkowe funkcje w zależności od potrzeb.

