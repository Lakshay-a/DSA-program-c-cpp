#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST
{
private:
    Node *root;

public:
    BST() { root = NULL; }
    Node *getRoot() { return root; }
    void iInsert(int key);
    void Inorder(Node *p);
    Node *iSearch(int key);
    Node *rInsert(Node *p, int key);
    Node *rSearch(Node *p, int key);
    Node *Delete(Node *p, int key);
    int Height(Node *p);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);
    void createFromPreorder(int pre[], int n); //!
};

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void BST::createFromPreorder(int pre[], int n)
{

    // Create root node
    int i = 0, x;
    root = new Node;
    root->data = pre[i++];
    root->lchild = NULL;
    root->rchild = NULL;

    // Iterative steps
    Node *t;
    Node *p = root;
    stack<Node *> stk;

    while (i < n)
    {
        // Left child case
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            // Right child cases

            if (stk.empty())
                x = 32767;
            else
                x = stk.top()->data;
            
            if ((pre[i] > p->data) && (pre[i] < x))
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = NULL;
                t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main()
{

    BST bst;

    // BST from Preorder traversal
    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);

    BST b;
    b.createFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;

    return 0;
}