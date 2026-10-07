#include <iostream>
struct Node {
    int Data;
    Node* Next;
};
Node* head = NULL;  //initialize head = 0

void Create_LinkedList();
void Print_List();
void Destruction();
void inp_n(int);

int main()
{
    Create_LinkedList();
    Print_List();
    int k = 0;
    std::cout << "Nhap gia tri can chen: "; std::cin >> k;
    inp_n(k);
    Print_List();
    Destruction();
    return 0;
}

void Create_LinkedList() {
    int x = 1;
    while (x != 0) {
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


void inp_n(int x) {
    Node* temp = head;
    while (temp->Next != NULL) {
        if (temp->Next->Data >= x) {
            break;
        }
        temp = temp->Next;
    }
    Node* NewNode = new Node;
    NewNode->Data = x; NewNode->Next = temp->Next;
    temp->Next = NewNode;
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