#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(){};
    Node(int data);
};

Node::Node(int data)
{
    lchild = NULL;
    this->data = data;
    rchild = NULL;
}

class Tree
{
private:
    Node *root;

public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node *p);
    void Preorder() { Preorder(root); } // Passing Private Parameter in Constructor
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    void Postorder(Node *p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node *p);
    void Levelorder() { Levelorder(root); }
    int Height(Node *p);
    int Height() { return Height(root); }
    void iterativePreorder(Node *p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node *p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node *p);
    void iterativePostorder() { iterativePostorder(root); }
    Node *generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
    void DestroyTree(Node *p);
};

Tree::Tree()
{
    root = NULL;
}

void Tree::DestroyTree(Node *p)
{
    if (p != NULL)
    {
        DestroyTree(p->lchild);
        DestroyTree(p->rchild);
        delete p;
    }
}

Tree::~Tree()
{
    DestroyTree(root);
}

void Tree::CreateTree()
{
    Node *p;
    Node *t;
    int x;
    queue<Node *> q;

    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p)
{
    queue<Node *> q;
    cout << p->data << ", " << flush;
    q.push(p);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        if (p->lchild)
        {
            cout << p->lchild->data << ", " << flush;
            q.push(p->lchild);
        }

        if (p->rchild)
        {
            cout << p->rchild->data << ", " << flush;
            q.push(p->rchild);
        }
    }
}

int Tree::Height(Node *p)
{
    int l = 0;
    int r = 0;
    if (p == NULL)
    {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}

void Tree::iterativePreorder(Node *p)
{
    stack<Node *> stk;
    while (p != NULL || !stk.empty())
    {
        if (p != NULL)
        {
            cout << p->data << ", " << flush;
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p)
{
    stack<Node *> stk;
    while (p != NULL || !stk.empty())
    {
        if (p != NULL)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p)
{
    stack<long int> stk;
    long int temp;
    while (p != NULL || !stk.empty())
    {
        if (p != NULL)
        {
            stk.push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            if (temp > 0)
            {
                stk.push(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << ", " << flush;
                p = NULL;
            }
        }
    }
    cout << endl;
}

int searchInorder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inArray[i] == data)
        {
            return i;
        }
    }
    return -1;
}

Node *Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd)
{
    // Reference: https://algorithms.tutorialhorizon.com/make-a-binary-tree-from-given-inorder-and-preorder-traveral/
    static int preIndex = 0;

    if (inStart > inEnd)
    {
        return NULL;
    }

    Node *node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
    {
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

    return node;
}

int main()
{

    Tree bt;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node *T = bt.generateFromTraversal(inorder, preorder, 0, sizeof(inorder) / sizeof(inorder[0]) - 1);
    bt.Preorder(T);
    cout<<"\n"<<bt.Height(T);

    return 0;
}