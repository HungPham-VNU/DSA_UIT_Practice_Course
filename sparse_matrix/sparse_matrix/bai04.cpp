#include <iostream>
using namespace std;
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

void Create_List(List&);
void Add_Node(List&, int, int, int);
void Print_List(List);
int** Input_Matrix(List&, int& n, int& m);
void Release_memory(int**, int);
List Add_result(List, List);


int main()
{
    List A, B;
    Create_List(A); Create_List(B);
    int row1 = 0, col1 = 0;
    int** sparseMatrix1 = Input_Matrix(A, row1, col1);
//    Print_List(A);    //bieu dien ma tran duoi dang danh sach lien ket don
    int row2 = 0, col2 = 0;
    int** sparseMatrix2 = Input_Matrix(B, row2, col2);
//    Print_List(B);

    //phep cong
    if (row1 != row2 || col1 != col2) cout << "Khong the thuc hien phep cong.";
    else {
        cout << "Ket qua phep cong bieu dien tren dslk: " << '\n';
        List Matrix_add = Add_result(A, B);
        Print_List(Matrix_add);
    }
    Release_memory(sparseMatrix1, row1);
    Release_memory(sparseMatrix2, row2);
    return 0;
}

void Create_List(List& p) {
    p.head = NULL;
    p.tail = NULL;
}

void Add_Node(List& p, int row, int col, int value) {
    Node* newNode = new Node;
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    if (p.head == NULL) p.head = newNode;
    else {
        Node* temp = p.head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void Print_List(List p) {
    Node* temp = p.head;
    while (temp != NULL) {
        cout << temp->row << ' ' << temp->col << ' ' << temp->value;
        cout << '\n';
        temp = temp->next;
    }
    cout << '\n';
}

int** Input_Matrix(List& A, int& n, int& m) {
    cout << "Nhap so hang cho ma tran: "; cin >> n;
    cout << "Nhap so cot cho ma tran: "; cin >> m;
    int** tmp;
    tmp = new int* [n];
    for (int i = 0; i < n; i++) tmp[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) std::cin >> tmp[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] != 0) Add_Node(A, i, j, tmp[i][j]);
        }
    cout << '\n';
    return tmp;
}

void Release_memory(int** p, int n) {
    for (int i = 0; i < n; i++) {
        delete[] p[i];
        p[i] = NULL;
    }
    delete[] p;
    p = NULL;
}

List Add_result(List p, List q) {
    Node* temp1 = p.head;
    Node* temp2 = q.head;
    List Res; 
    Create_List(Res);
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->row < temp2->row) {
            Add_Node(Res, temp1->row, temp1->col, temp1->value);
            temp1 = temp1->next;
            continue;
        }
        if (temp1->row > temp2->row) {
            Add_Node(Res, temp2->row, temp2->col, temp2->value);
            temp2 = temp2->next;
            continue;
        }
        if (temp1->row == temp2->row && temp1->col < temp2->col) {
            Add_Node(Res, temp1->row, temp1->col, temp1->value);
            temp1 = temp1->next;
            continue;
        }
        if (temp1->row == temp2->row && temp1->col > temp2->col) {
            Add_Node(Res, temp2->row, temp2->col, temp2->value);
            temp2 = temp2->next;
            continue;
        }
        if (temp1->row == temp2->row && temp1->col == temp2->col) {
            Add_Node(Res, temp1->row, temp1->col, temp1->value + temp2->value);
            temp1 = temp1->next;
            temp2 = temp2->next;
            continue;
        }
    }

    if (temp1 != NULL) {
        while (temp1 != NULL) {
            Add_Node(Res, temp1->row, temp1->col, temp1->value);
            temp1 = temp1->next;
        }
    }
    else if (temp2 != NULL) {
        while (temp2 != NULL) {
            Add_Node(Res, temp2->row, temp2->col, temp2->value);
            temp2 = temp2->next;
        }
    }
    return Res;
}  