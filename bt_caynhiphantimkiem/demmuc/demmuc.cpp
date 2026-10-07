#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dem = 0;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* taonode(int x)
{
    Node* p = new Node();
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(Node* root, Node* newnode)
{

    if (root->data < newnode->data)
    {
        if (root->right == NULL)
        {
            root->right = newnode;
            return;
        }
        else insert(root->right, newnode);
    }
    else
    {
        if (root->left == NULL)
        {
            root->left = newnode;
            return;
        }
        else insert(root->left, newnode);

    }


}

void print(Node* root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        print(root->left);
        print(root->right);
    }
}

void dem1(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 0)
    {
        if (root)
            cout << root->data << ' ';
    }
    dem1(root->left, level - 1);
    dem1(root->right, level - 1);
}


double Average_Muc(Node* root, int x)
{
    if (x == 0) return root->data;
    queue<Node*> q;
    q.push(root);
    int i = 0;
    while (i < x) {
        if (q.empty()) return 0;
        int qsize = q.size();
        for (int j = 0; j < qsize; j++)
        {
            Node* temp = q.front();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            q.pop();
        }
        i++;
    }

    double res = 0;
    while (!q.empty()) {
        Node* temp = q.front();
        res += temp->data;
        q.pop();
    }
    return res / pow(2, x);
}


double Average2(Node* root, int x) {
    if (x == 0) return root->data;
    vector<Node*> v;
    v.push_back(root);
    int i = 0;
    while (i < x) {
        if (v.empty()) return 0;
        int vsize = v.size();
        for (int i = 0; i < vsize; i++)
        {
            v.push_back(v[i]->left);
            v.push_back(v[i]->right);
        }
        v.erase(v.begin(), v.begin() + vsize);
        i++;
    }
    double res = 0;
    for (int i = 0; i < v.size(); i++) res += v[i]->data;
    return res / pow(2, x);
}


int main()
{
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        Node* p = taonode(value);
        if (root == NULL)
        {
            root = p;
        }
        else
        {
            insert(root, p);
        }

    }
    int level;
    cin >> level;
    dem1(root, level);
 //   cout << dem << '\n';
    cout << '\n' << Average_Muc(root, level) << '\n';
    cout << Average2(root, level);
    return 0;
}