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
void Split(List&, List&, List&);

int main()
{
    List A, B, C;
    A.head = NULL; B.head = NULL; C.head = NULL;
    Create_LinkedList(A);
    Split(A, B, C);
//    Print_List(A);
    Print_List(B);
    Print_List(C);
    Destruction(B);
    Destruction(C);
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

void Split(List& A, List& B, List& C) {
    B.head = A.head;
    Node* temp = A.head;
    int n = 0;
    while (temp != NULL) {
        n++;
        temp = temp->Next;
    }
    temp = A.head;
    if (n % 2 == 0) n /= 2;
    else n = n / 2 + 1;
    for (int i = 1; i <= n - 1; i++) temp = temp->Next;
    B.tail = temp;
    C.head = temp->Next;
    temp->Next = NULL;
    C.tail = A.tail;
    A.head = NULL; A.tail = NULL;
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