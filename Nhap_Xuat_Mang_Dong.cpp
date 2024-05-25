#include "Thu_Vien.h"
using namespace std;

void arrayOutput(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

void arrayInput(vector<int> &a)
{
    int n;
    cin >> n;
    if (n < 1)
    {
        return;
    }
    a.resize(n);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
}

int main()
{
    vector<int> a;
    cout << "Nhap mang, nhap so luong phan tu vao mang" << endl;
    arrayInput(a);
    cout << "Cac phan tu trong mang a" << endl;
    arrayOutput(a);
    int x[] = {1, 2, 3, 4, 5};
    arrayOutput(a);

    cout << endl;
}