#include <iostream>
struct Node {
    int Data;
    Node* Next;
};
Node* head = NULL;  //initialize head = 0

void Create_LinkedList(int);
void Print_List();
void Destruction();

int main()
{
    int n; std::cin >> n;
    Create_LinkedList(n);
    Print_List();
    Destruction();
    return 0;
}

void Create_LinkedList(int n) {
    int x;
    for (int i = 1; i <= n; i++) {
        std::cin >> x;
        Node* newNode = new Node;
        newNode->Data = x;
        newNode->Next = NULL;

        if (head == NULL) head = newNode;
        else {
            Node* temp = head;
            while (temp->Next != NULL) temp = temp->Next;
            temp->Next = newNode;
        }
    }
}

void Print_List() {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->Data << ' ';
        temp = temp->Next;
    }
    std::cout << '\n';
}

void Destruction() {
    int i = 0;
    while (head != NULL) {
        Node* temp = head;
        head = head->Next;
        delete temp;
        std::cout << "Da xoa phan tu thu " << i << '\n';
        i++;
    }
}