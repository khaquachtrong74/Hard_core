#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

struct SanPham
{
    char MaSP[100];
    char TenSP[100];
    int SoLuong;
    float SoThuc;
    char PhanLoai[100];
    float giaThanh;
};

const int size = 50;

int nhap(SanPham A[size][10])
{
    // Ham nhap duoc toi da 50 SP
    int n;
    cout << "Nhap so san pham muon luu ";
    cin >> n;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Ma San Pham ";
        cin >> A[i][0].MaSP;
        cout << "Nhap Ten San Pham";
        cin >> A[i][1].TenSP;
        cout << "Nhap so luong san pham";
        cin >> A[i][2].SoLuong;
        cout << "Nhap don gia cho san pham";
        cin >> A[i][3].SoThuc;
        cout << "Nhap Loai San Pham";
        cin >> A[i][4].PhanLoai;
    }
    return n;
}

void hamxuat(SanPham B[5])
{
    ifstream Data("D:\\My_Self_Studying\\C++\\Ky_Thuat_Lap_Trinh\\file.txt", ios::in);

    if (Data.is_open())
    {
        cout << "File doc da duoc mo ra" << endl;
    }

    string c;
    string temp;
    int dem = 0;

    while (getline(Data, c))
    {
        istringstream iss(c);
        string t;
        getline(iss, t, ',');
        // cout
        //     << "Test" << t;
        int end;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                end = i;
                for (int j = i + 1; j < t.size(); j++)
                {
                    if (t[j] == '#')
                    {
                        int k = 0;
                        for (int i = end + 1; i < j; i++)
                        {
                            B[dem].TenSP[k] = t[i];
                            k++;
                        }
                        break;
                    }
                }

                break;
            }
        }
        for (int i = t.size() - 1; i >= 0; i--)
        {
            if (t[i] == '#')
            {
                end = i;
                int k = 0;
                for (int j = end + 1; j < t.size(); j++)
                {
                    B[dem].PhanLoai[k] = t[j];
                    k++;
                }
                dem++;
                break;
            }
        }
    }
    cout << "Cac ten san pham co phan loai la vat dung" << endl;
    for (int i = 0; i < 5; i++)
    {

        if (B[i].PhanLoai[0] == 'V')
        {
            cout << "Vat pham : " << B[i].TenSP << endl;
        }
    }

    Data.close();
    if (!Data.is_open())
    {
        cout << "File doc da duoc dong" << endl;
    }
}

void hamnhap(SanPham B[5])
{
    ofstream Bt("BT.txt");
    if (Bt.is_open())
    {
        cout << "Da mo file ghi" << endl;
    }
    for (int i = 0; i < 5; i++)
    {

        if (B[i].PhanLoai[0] == 'V')
        {
            Bt << B[i].TenSP << " | ";
        }
    }
    Bt.close();
    if (!Bt.is_open())
    {
        cout << "Da dong file ghi" << endl;
    }
}
void hamTinhtien(SanPham B[5])
{
    ifstream docfile("file.txt");
    if (docfile.is_open())
    {
        cout << "Da mo file doc" << endl;
    }
    string c;
    int k = 0;
    while (getline(docfile, c))
    {
        istringstream iss(c);
        string t;
        getline(iss, t, ',');
        int dem = 0, end = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                dem++;
                if (dem == 2)
                {
                    string a;
                    for (int j = i + 1; j < t.size(); j++)
                    {
                        a += t[j];
                        if (t[j] == '#')
                        {
                            end = j;
                            break;
                        }
                    }
                    B[k].SoLuong = stoi(a);
                    break;
                }
            }
        }
        string a;
        for (int i = end + 1; i < t.size(); i++)
        {

            if (t[i] == '#')
            {
                break;
            }
            a += t[i];
        }
        B[k].SoThuc = stof(a);
        k++;
    }
    for (int i = 0; i < k; i++)
    {

        B[i].giaThanh = float(B[i].SoLuong) * B[i].SoThuc;
    }
    for (int i = 0; i < k; i++)
    {
        cout << "Gia thanh cua vat pham " << B[i].TenSP << " la " << float(B[i].giaThanh) << endl;
    }
}

int dem_An(SanPham B[5])
{
    int k = 0;
    int dem = 0;
    int size = 0;

    for (int k = 0; k < 5; k++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (B[k].TenSP[j] >= 'a' && B[k].TenSP[j] <= 'z' || B[k].TenSP[j] >= 'A' && B[k].TenSP[j] <= 'Z')
            {
                size++;
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (B[k].TenSP[i] == 'a' && B[k].TenSP[i + 1] == 'n')
            {
                dem++;
                break;
            }
        }
    }
    return dem;
}
int main()
{
    SanPham A[size][10];

    // int n = nhap(A);
    // for (int j = 0; j < n; j++)
    // {
    //     cout << "San Pham    " << j + 1 << " ";
    //     cout << "Ma SP       |" << A[j][0].MaSP << "| ";
    //     cout << "Ten SP      |" << A[j][1].TenSP << "| ";
    //     cout << "So luong SP |" << A[j][2].SoLuong << "| ";
    //     cout << "Don gia SP  |" << A[j][3].SoThuc << "| ";
    //     cout << "Phan Loai   |" << A[j][4].PhanLoai << "| ";
    //     cout << endl;
    // }

    // ifstream Data("D:\\My_Self_Studying\\C++\\Ky_Thuat_Lap_Trinh\\file.txt", ios::in);
    // string line;
    // string temp;
    // if (Data.is_open())
    // {
    //     cout << "Da mo file" << endl;
    // }

    // int dem = 1;
    // // for (int i = 0; i < 20; i++)
    // // {
    // //     if (i == dem + 4)
    // //     {

    // //         Data >> B[dem - 1].MaSP;
    // //         cout << B[dem - 1].MaSP;
    // //         dem + 4;
    // //     }
    // // }
    // while (getline(Data, line))
    // {
    //     istringstream iss(line);
    //     while (getline(iss, temp, '/'))
    //     {
    //         cout << temp << endl;
    //     }
    // }
    // Data.close();
    // if (!Data.is_open())
    // {
    //     cout << "Da dong file" << endl;
    // }
    SanPham B[5];
    hamxuat(B);
    hamnhap(B);
    hamTinhtien(B);
    int a = dem_An(B);
    cout << "So san pham co ten co ki tu 'an' la " << a;
    return 0;
}