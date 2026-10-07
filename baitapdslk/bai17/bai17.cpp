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
void Create_C(List&, List&, List&);
void delete_n(int, List&);

int main()
{
    List A, B, C;
    A.head = NULL; B.head = NULL; C.head = NULL;
    Create_LinkedList(A);
    Create_LinkedList(B);
    delete_n(0, A);
    delete_n(0, B);
    Create_C(A, B, C);
    Print_List(C);
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

void Create_C(List& A, List& B, List& C) {
    Node* atemp = A.head, * btemp = B.head, * ctemp = C.head;
    if (atemp->Data <= btemp->Data) { C.head = atemp; ctemp = C.head; atemp = atemp->Next; }
    else { C.head = btemp; ctemp = C.head; btemp = btemp->Next; };
    while (atemp != NULL && btemp != NULL) {

        if ((atemp->Data <= btemp->Data && atemp != NULL) || (btemp == NULL)) {
            ctemp->Next = atemp;
            ctemp = atemp;
            atemp = atemp->Next;
            continue;
        }
        else
        {
            ctemp->Next = btemp;
            ctemp = btemp;
            btemp = btemp->Next;
            continue;
        }
    }
    /*if (atemp != NULL) {
        while (atemp != NULL) {
            ctemp->Next = atemp;
            ctemp = atemp;
            atemp = atemp->Next;
        }
    }
    if (btemp != NULL) {
        while (btemp != NULL) {
            ctemp->Next = btemp;
            ctemp = btemp;
            btemp = btemp->Next;
        }
    }*/
}

void delete_n(int x, List& p) {
    Node* temp = p.head;
    bool check_x = 1; //gia su phan tu head la x

    if (temp->Data != x) {
        check_x = 0;
        while (temp->Next != NULL) {
            if (temp->Next->Data == x) {
                check_x = 1;
                break;
            }
            temp = temp->Next;
        }
    }

    if (check_x) {
        Node* delete_node = temp->Next;
        temp->Next = delete_node->Next;
        delete delete_node;
    }
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