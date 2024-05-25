#include "Thu_Vien.h"
// hàm tạo mảng
void arrayMake(vector<int> &a, int arr[], int n)
{
    int i = 0;
    a.resize(0);
    while (i < n)
    {
        a.push_back(arr[i]);
        i++;
    }
}
// hàm cout ra các phần tử trong mảng
void intarrayOutput(vector<int> &a, ostream &output)
{
    for (int i = 0; i < a.size(); i++)
    {
        output << a[i] << " ";
    }
    output << endl;
}
// hàm gộp2 mảng lại vào nhau
void intarrayCat(vector<int> &dest, vector<int> &src)
{
    int size1 = dest.size(), size2 = src.size();
    int index = size1, newsize = size1 + size2, i = 0;
    dest.resize(newsize);
    while (index < newsize)
    {
        dest[index] = src[i];
        index++;
        i++;
    }
}
// hàm cắt mảng tại vị trí port
void intarrayCutFrom(vector<int> &a, int port, vector<int> &b)
{
    int size = a.size(), j = port;
    if (j < 0 || j >= a.size())
    {
        return;
    }
    b.resize(0);
    while (j < size)
    {
        b.push_back(a[j]);
        j++;
    }
    a.resize(port);
}

void intarrayInsert(vector<int> &a, int port, int elements)
{
    if (port < 0 || port >= a.size())
    {
        return;
    }
    vector<int> b;
    intarrayCutFrom(a, port, b);
    a.push_back(elements);
    intarrayCat(a, b);
}
// test case
int main()
{
    int x[] = {3, 5, 2, 4, 5, 2, 1};
    int n = sizeof(x) / sizeof(int);
    vector<int> a, b, c;
    arrayMake(a, x, n);
    cout << "a: ";
    intarrayOutput(a, cout);
    intarrayCutFrom(a, 3, b);
    cout << "a now:";
    intarrayOutput(a, cout);
    cout << "b: ";
    intarrayOutput(b, cout);
    intarrayCat(b, a);
    cout << "b now: ";
    intarrayOutput(b, cout);
    a.pop_back();
    cout << "a now: ";
    intarrayOutput(a, cout);
    intarrayInsert(b, 3, 999);
    cout << "b now: ";
    intarrayOutput(b, cout);
}
