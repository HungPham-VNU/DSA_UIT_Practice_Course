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
void Sort_List();

int main()
{
    Create_LinkedList();
    Print_List();
    int x = 0;
    std::cout << "Nhap phan tu: "; std::cin >> x;
    delete_n(x);
    Print_List();
    Sort_List();
    Print_List();
    Destruction();
    return 0;
}

void Create_LinkedList() {
    int x = 1;
    while (x != 0) {
        std::cin >> x;
        if (x == 0) break;
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

void Sort_List() {
    Node* i = head;
    Node* j;
    Node* MinData;

    while (i->Next != NULL) {
        MinData = i;
        j = i->Next;
        while (j != NULL) {
            if (MinData->Data > j->Data) MinData = j;
            j = j->Next;
        }
        if (MinData->Data != i->Data) std::swap(MinData->Data, i->Data);
        i = i->Next;
    }
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