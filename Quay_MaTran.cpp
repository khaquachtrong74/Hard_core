#include <iostream>
using namespace std;

void in_matran(int arr[3][3], int n);

void Zigzag_matran(int **&arr, int n)
{
    cout << "Nhap do dai ma tran";
    cin >> n;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    int k = 0, m = 1;
    while (k < n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            arr[i][k] = m;
            m++;
        }
        k++;
    }
    // in_matran(arr, n);
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}

void in_matran(int arr[3][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void hang(int arr[3][3], int &row, int &col, int size, int &dem, int &m, bool b)
{
    if (b == true)
    {
        // row = col == dem;
        if (col == size - dem)
        {
            // row = dem;
            // col == size - dem;
            return;
        }
        arr[row][col] = m;
        m = m + 1;
        hang(arr, row, col = col + 1, size, dem, m, b);
    }
    else
    {
        // row == col;
        if (col == dem)
        {
            dem = dem + 1;
            return;
        }
        arr[row][col] = m;
        m = m + 1;
        hang(arr, row, col = col - 1, size, dem, m, b);
    }
}

void cot(int arr[3][3], int &row, int &col, int size, int dem, int &m, bool &b)
{

    if (b == true)
    {
        // row = dem+1
        // col = size - dem - 1;
        if (row == col + 1)
        {
            // row == col == size - dem - 1
            b = false;
            return;
        }
        arr[row][col] = m;
        m = m + 1;
        cot(arr, row = row + 1, col, size, dem, m, b);
    }
    else
    {
        // row == col
        // col == dem == 0;
        // dem == 1;
        if (row == dem)
        {
            // row = dem = 1;
            // col = 0;
            b = true;
            return;
        }
        arr[row][col] = m;
        m += 1;
        hang(arr, row = row - 1, col, size, dem, m, b);
    }
}

void xoay(int arr[3][3], int row, int col, int size, int dem, int m, bool b)
{
    if (m < 15)
    {
        in_matran(arr, 3);
        return;
    }
    hang(arr, row, col, size, dem, m, b);
    cot(arr, row += 1, col -= 1, size, dem, m, b);
    xoay(arr, row, col, size, dem, m, b);
}

int main()
{
    // int **arr, n;

    // Zigzag_matran(arr, n);
    // xoay_mang();

    int arr[3][3];
    int row = 0, col = 0, size = 3, dem = 0, m = 1;
    bool b = true;
    xoay(arr, row, col, size, dem, m, b);
}

void xoay_mang()
{
    int arr[3][3];
    int m = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = m;
            m++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
