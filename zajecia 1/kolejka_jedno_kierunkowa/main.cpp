//Poniżej znajduje się przykładowy program w C++, który demonstruje budowę prostej listy jednokierunkowej (bez głowy)
// za pomocą zmiennych typu wskaźnikowego. Lista jednokierunkowa
#include <iostream>

// Definicja struktury dla węzła listy
struct Node {
    int data;
    Node* next;
};

// Funkcja tworząca nowy węzeł z podaną wartością
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Funkcja dodająca nowy węzeł na końcu listy
void appendNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Funkcja wyświetlająca zawartość listy
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Funkcja zwalniająca pamięć zajmowaną przez listę
void deleteList(Node*& head) {
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;

    // Dodawanie elementów do listy
    appendNode(head, 10);
    appendNode(head, 20);
    appendNode(head, 30);
    appendNode(head, 40);

    // Wyświetlanie zawartości listy
    std::cout << "Zawartość listy: ";
    displayList(head);

    // Zwalnianie pamięci
    deleteList(head);

    return 0;
}

/*
Opis programu
Definicja struktury Node: Struktura Node reprezentuje pojedynczy węzeł listy, który zawiera dane (data) oraz wskaźnik na następny węzeł (next).

Funkcja createNode: Tworzy nowy węzeł i zwraca wskaźnik do niego.

Funkcja appendNode: Dodaje nowy węzeł na końcu listy. Jeśli lista jest pusta (wskaźnik head jest nullptr), nowy węzeł staje się pierwszym węzłem. W przeciwnym razie przechodzi przez listę do ostatniego węzła i ustawia jego wskaźnik next na nowy węzeł.

Funkcja displayList: Przechodzi przez listę i wyświetla wartości danych w kolejnych węzłach.

Funkcja deleteList: Przechodzi przez listę i zwalnia pamięć zajmowaną przez każdy węzeł, aby uniknąć wycieków pamięci.

Funkcja main: Tworzy listę, dodaje kilka elementów, wyświetla zawartość listy, a następnie zwalnia pamięć.

Program demonstruje podstawowe operacje na listach jednokierunkowych, takie jak dodawanie elementów, wyświetlanie zawartości listy oraz zwalnianie pamięci.
*/