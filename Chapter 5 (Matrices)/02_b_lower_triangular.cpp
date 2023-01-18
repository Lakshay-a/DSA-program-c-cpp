#include <iostream>
using namespace std;

class lower_triangular
{
    private:
    int *A;
    int n;

    public:
    lower_triangular()
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    lower_triangular(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~lower_triangular()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; }
};

void lower_triangular::Set(int i, int j, int x)
{
    if (i >= j)
        A[i*(i-1)/2+j-1] = x;                   //used row major here
}

int lower_triangular::Get(int i, int j)
{
    if (i >= j)
        return A[i*(i-1)/2+j-1];
    return 0;
}
void lower_triangular::Display()
{
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i*(i-1)/2+j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout << endl;
    }
}
int main()
{
    int d;
    cout << "Enter Dimensions ";
    cin >> d;
    lower_triangular lt(d);
    int x;
    cout << "Enter All Elements";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lt.Set(i, j, x);
        }
    }
    lt.Display();
    return 0;
}