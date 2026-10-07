#include <iostream>
struct Node {
    int Data;
    Node* Next;
};
Node* head = NULL;  //initialize head = 0

void Create_LinkedList();
void Print_List();
void Destruction();
void delete_n(int);
int Travel_List();

int main()
{
    Create_LinkedList();
    Print_List();
    int x = Travel_List(); //phan tu cuoi danh sach
    delete_n(x);
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


void delete_n(int x) {
    Node* temp = head;
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
    else std::cout << 0;
    std::cout << '\n';
}

int Travel_List() {
    Node* temp = head;
    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    return temp->Data;
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