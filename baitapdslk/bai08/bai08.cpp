#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int Data;
    Node* Next;
};
Node* head = NULL;  //initialize head = 0

void Create_LinkedList();
void Print_List();
void Destruction();

int main()
{
    Create_LinkedList();
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
    stack<int> v;
    while (temp != NULL) {
        v.push(temp->Data);
        temp = temp->Next;
    }
    while (!v.empty())
        std::cout << v.top() << ' ',
        v.pop();
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