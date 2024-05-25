#include <iostream>
#include <vector>
using namespace std;
bool sole(int n);
bool sochan(int n)
{
    if (n == 0)
    {
        return true;
    }
    return sole(n);
}

bool sole(int n)
{
    return !sochan(n - 1);
}

int cau1()
{
    int start, end;
    cin >> start >> end;
    int ketqua = 0;
    if (start != end)
    {
        for (int i = start; i <= end; i++)
        {
            if (sochan(i))
                ketqua += i;
        }
    }
    return ketqua;
}
void helloworld()
{
    cout << "helloworld!" << endl;
    return;
}
// dequy ho tuong
bool not_prime(int n, int div);
bool prime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    return not_prime(n, n - 1);
}
bool not_prime(int n, int div)
{
    if (div == 1)
    {
        return true;
    }
    if (n % div == 0)
    {
        return false;
    }
    return not_prime(n, div - 1);
}

int souoc(int n)
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            dem++;
        }
    }
    return dem;
}
void cau2()
{
    int n;
    cin >> n;
    const int m = n;
    int *ketqua = new int[n];
    while (n != 0)
    {
        int start, end;
        cin >> start >> end;
        int k = 0;
        if (start != end)
        {
            for (int i = start; i <= end; i++)
            {
                if (prime(souoc(i)))
                    k++;
            }
            *(ketqua + n - 1) = k;
            n--;
        }
    }
    for (int i = 0; i < m; i++)
        cout << ketqua[i] << " ";
    delete[] ketqua;
    ketqua = nullptr;
    if (ketqua == nullptr)
    {
        cout << "da giai phong bo nho" << endl;
    }
}
void sapxep(int *&ptr, int size, int x)
{
    if (x == size - 1)
    {
        return;
    }
    int min = ptr[x];
    int position = x;

    for (int i = x; i < size; i++)
    {
        if (min > ptr[i])
        {
            min = ptr[i];
            position = i;
        }
    }

    int temp = ptr[x];
    ptr[x] = ptr[position];
    ptr[position] = temp;
    sapxep(ptr, size, x + 1);
}
void cau3()
{
    int n;
    int so1, so2, x;
    cin >> n;
    int const m = n;
    int *ptr_r = new int[n];
    while (n > 0)
    {
        cin >> so1 >> so2 >> x;
        int *ptr = new int[x];
        bool f = true;
        int dem = 0;
        for (int i = 0; i < x; i++)
        {
            if (f)
            {
                ptr[i] = so1 * (i + 1 - dem);
                int m = i - 1;
                int t = i - 2;
                while (ptr[m] == ptr[i] || ptr[t] == ptr[i])
                {
                    ptr[i] += so1;
                }
                f = false;
            }
            else
            {

                dem++;
                ptr[i] = so2 * (dem);
                int m = i - 1;
                int t = i - 2;
                while (ptr[m] == ptr[i] || ptr[t] == ptr[i])
                {
                    dem++;
                    ptr[i] = so2 * (dem);
                }
                f = true;
            }
        }
        // sapxep(ptr, x, 0);
        ptr_r[n - 1] = ptr[x - 1];

        delete[] ptr;

        n--;
    }
    cout << endl;
    for (int i = m - 1; i >= 0; i--)
    {
        cout << ptr_r[i] << endl;
    }
    delete[] ptr_r;
    ptr_r;
}
int main()

{
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Cau 1" << endl;
        cout << cau1();
        break;
    case 2:
        cout << "Cau 2" << endl;
        cau2();
        break;
    case 3:
        cout << "Cau 3" << endl;
        cau3();
        break;
    default:
        cout << "Ket thuc chuong trinh" << endl;
    }
}