#include "String_Cstring.h"

void arrayFloatOutput(const vector<string> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

void arrayFloatInput(vector<string> &a)
{
    float x;
    while (cin >> x)
    {
        a.push_back(to_string(x));
    }
}

int main()
{
    vector<string> a;
    cout << "Nhap cac phan tu vao mang, nhan Crtl+W -> stop!" << endl;
    arrayFloatInput(a);
    cout << "Cac phan tu co trong mang la" << endl;
    arrayFloatOutput(a);
    cout << endl;
}