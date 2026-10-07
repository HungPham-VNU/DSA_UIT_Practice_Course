/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct TNode {
    int key;
    TNode* left, * right;
};

typedef TNode* TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
    int i;
    TREE root;
    if (inE < inB) return NULL;
    root = new TNode;
    if (root != NULL) {
        root->key = pre[preB];
        for (i = inB; i <= inE; i++)
            if (in[i] == pre[preB]) break;
        root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
        root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
    } return root;
}

void LNR(TREE);
double AverageByLevel(TREE, int);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);

    //cin >> m;

    //cout << setprecision(2) << fixed;

   /* for (int i = 0; i < m; i++) {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }*/

    LNR(r);

    return 0;
}


//###INSERT CODE HERE -
double AverageByLevel(TREE T, int x) {
    if (x == 0) return T->key;
    vector<TNode*> v;
    v.push_back(T);
    int check = 1;
    for (int i = 0; i <= x; i++) {
        int vsize = v.size() - 1;
        cout << vsize << '\n';
        for (int j = 0; j <= vsize; j++)
        {
//            if (v[i]->left == NULL || v[i]->right == NULL) { check = 0; break; }
            v.push_back(v[i]->left);
            cout << "push successfully" << '\n';
            v.push_back(v[i]->right);
            cout << "push successfully" << '\n';
        }
//if (check == 0) break;
        //v.erase(v.begin(), v.begin() + vsize);
        for (int i = 0; i < v.size(); i++) cout << v[i]->key << '\n';
    }
//    if (check == 0) return 0;
    double res = 0;
    for (auto x : v) res += x->key;
    return (res / (pow(2, x)));
}

void LNR(TREE T) {
    if (T != NULL) {
        LNR(T->left);
        cout << T->key << ' ';
        LNR(T->right);
    }
}