#include <iostream>
struct Node {
    int Data;
    Node* Next;
};
struct List {
    Node* head;
    Node* tail;
};

void Create_LinkedList(List&);
void Print_List(List);
void Destruction(List);
void Merge(List&, List);

int main()
{
    List A, B;
    A.head = NULL; B.head = NULL;
    Create_LinkedList(A);
    Create_LinkedList(B);
    Merge(A, B);
    Print_List(A);
    Destruction(A);
    return 0;
}

void Create_LinkedList(List& p) {
    int x = 1;
    while (x != 0) {
        std::cin >> x;
        Node* newNode = new Node;
        newNode->Data = x;
        newNode->Next = NULL;

        if (p.head == NULL) {
            p.head = newNode; p.tail = p.head;
        }
        else {
            Node* temp = p.head;
            while (temp->Next != NULL) temp = temp->Next;
            temp->Next = newNode;
            p.tail = newNode;
        }
    }
}

void Print_List(List p) {
    Node* temp = p.head;
    while (temp != NULL) {
        std::cout << temp->Data << ' ';
        temp = temp->Next;
    }
    std::cout << '\n';
}

void Merge(List& p, List q) {
    p.tail->Next = q.head;
}


void Destruction(List p) {
    int i = 0;
    while (p.head != NULL) {
        Node* temp = p.head;
        p.head = p.head->Next;
        delete temp;
        std::cout << "Da xoa phan tu thu " << i << '\n';
        i++;
    }
}