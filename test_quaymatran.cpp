#include <iostream>
using namespace std;

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

void hang(int arr[3][3], int &row, int &col, int size, int &dem, int &m, bool &b)
{
    if (b)
    {
        if (col == size - dem)
        {
            col--;
            row++;
            b = false;
            return;
        }
        arr[row][col] = m++;
        col++;
        hang(arr, row, col, size, dem, m, b);
    }
    else
    {
        if (col == dem - 1)
        {
            col++;
            row--;
            dem++;
            b = true;
            return;
        }
        arr[row][col] = m++;
        col--;
        hang(arr, row, col, size, dem, m, b);
    }
}

void cot(int arr[3][3], int &row, int &col, int size, int &dem, int &m, bool &b)
{
    if (b)
    {
        if (row == size - dem)
        {
            row--;
            col--;
            b = false;
            return;
        }
        arr[row][col] = m++;
        row++;
        cot(arr, row, col, size, dem, m, b);
    }
    else
    {
        if (row == dem - 1)
        {
            row++;
            col++;
            b = true;
            return;
        }
        arr[row][col] = m++;
        row--;
        cot(arr, row, col, size, dem, m, b);
    }
}

void xoay(int arr[3][3], int row, int col, int size, int dem, int m, bool b)
{
    if (m > size * size)
    {
        in_matran(arr, 3);
        return;
    }
    hang(arr, row, col, size, dem, m, b);
    cot(arr, row, col, size, dem, m, b);
    xoay(arr, row, col, size, dem, m, b);
}

int main()
{
    int arr[3][3] = {0};
    int row = 0, col = 0, size = 3, dem = 0, m = 1;
    bool b = true;
    xoay(arr, row, col, size, dem, m, b);
    return 0;
}
