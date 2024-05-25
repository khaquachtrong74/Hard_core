#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct PhongBan
{
    string maphong;
    string tenphong;
};

struct PhanSo
{
    int tuso;
    int mauso;
};
struct NhanVien
{
    string ma;
    string hoten;
    int namvao, namsinh;
};
void nhap(PhongBan &A)
{
    cout << "Nhap ma phong: ";
    cin >> A.maphong;
    cout << "Nhap ten phong ban: ";
    cin >> A.tenphong;
}
void xuat(PhongBan &a)
{
    cout << "Ma phong: " << a.maphong << endl;
    cout << "Ten phong: " << a.tenphong << endl;
}
void bai1()
{
    PhongBan a;
    nhap(a);
    xuat(a);
}
PhanSo tong_PS(PhanSo &a, PhanSo &b, char c)
{
    PhanSo Moi;
    if (a.mauso == 0 || b.mauso == 0)
        return Moi;
    if (a.mauso != b.mauso)
    {
        int t;

        switch (c)
        {
        case '+':
            a.tuso = a.tuso * b.mauso;
            b.tuso = b.tuso * a.mauso;
            Moi.tuso = a.tuso + b.tuso;
            a.mauso *= b.mauso;
            b.mauso = a.mauso;
            Moi.mauso = a.mauso;
            break;
        case '-':
            a.tuso = a.tuso * b.mauso;
            b.tuso = b.tuso * a.mauso;
            Moi.tuso = a.tuso - b.tuso;
            a.mauso *= b.mauso;
            b.mauso = a.mauso;
            Moi.mauso = a.mauso;
            break;
        case '/':
            Moi.tuso = b.mauso;
            Moi.mauso = b.tuso;

        case '*':
            Moi.tuso *= a.tuso;
            Moi.mauso *= a.mauso;
            break;
        }
        return Moi;
    }
    else
    {
        Moi.mauso = a.mauso;
        switch (c)
        {
        case '+':
            Moi.tuso = a.tuso + b.tuso;
            break;
        case '-':
            Moi.tuso = a.tuso - b.tuso;
            break;
        case '/':
            Moi.tuso = a.tuso / b.tuso;
            Moi.mauso = 1;
            break;
        case '*':
            Moi.tuso = a.tuso * b.tuso;
            Moi.mauso *= a.mauso;
            break;
        }
    }
    return Moi;
}
PhanSo Input(PhanSo &a)
{
    cout << "Tu so:";
    cin >> a.tuso;
    cout << "Mau so:";
    cin >> a.mauso;
    return a;
}
void bai2()
{
    PhanSo so1;
    PhanSo so2;
    Input(so1);
    Input(so2);
    char c;
    cout << "Nhap phep tinh";
    cin >> c;
    cout << so1.tuso << "/" << so1.mauso << endl;
    cout << c << endl;
    cout << "_______" << endl;
    cout << so2.tuso << "/" << so2.mauso << endl;
    cout << "=" << endl;
    cout << tong_PS(so1, so2, c).tuso << "/" << tong_PS(so1, so2, c).mauso << endl;
}

void nhapNhanVien(NhanVien &a)
{
    cout << "Hay nhap thong tin cua nhan vien vao day" << endl;
    cout << "Ma nhan vien: ";
    cin >> a.ma;
    cout << "Ho va Ten: ";
    cin >> a.hoten;
    cout << "Nam sinh: ";
    cin >> a.namsinh;
    cout << "Thoi gian vao lam: ";
    cin >> a.namvao;
    cout << "Ket thuc qua trinh dien thong tin" << endl;
}
void xuatThongTin(NhanVien &a)
{
    cout << "Thong tin cua nhan vien " << a.hoten << "." << endl;
    cout << "Ma nhan vien: " << a.ma << endl;
    cout << "Tuoi cua nhan vien: " << 2024 - a.namsinh << endl;
    cout << "Tham nien lam viec: " << 2024 - a.namvao << endl;
}

struct SinhVien
{
    string masosv, hoten, diachi;
    int namsinh;
    double diemtoan, diemvan, diemnn;
};
float tinhdiem(SinhVien *a, int i);
SinhVien *inputSinhVien(int &n)
{

    cout << "Nhap si so sinh vien (khong qua 45)";
    cin >> n;
    if (n > 45 || n < 1)
    {
        cout << "Hay thu lai";
    }
    SinhVien *a = new SinhVien[n];
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": Nhap ma so sinh vien ";
        cin >> a[i].masosv;
        cin.ignore();
        cout << i + 1 << ": Nhap Ho Ten sinh vien ";
        getline(cin, a[i].hoten);
        cout << i + 1 << ": Nhap Dia chi sinh vien ";
        getline(cin, a[i].diachi);
        cout << i + 1 << ": Nhap Nam sinh sinh vien ";
        cin >> a[i].namsinh;
        cout << i + 1 << ": Nhap Diem Toan sinh vien ";
        cin >> a[i].diemtoan;
        cout << i + 1 << ": Nhap Diem Van sinh vien ";
        cin >> a[i].diemvan;
        cout << i + 1 << ": Nhap Diem ngoai ngu sinh vien ";
        cin >> a[i].diemnn;
    }
    return a;
}
void outputSinhVien(SinhVien *a, int i)
{
    cout << "Ma so :" << a[i].masosv << endl;
    cout << "Ho va Ten :" << a[i].hoten << endl;
    cout << "Dia chi : " << a[i].diachi << endl;
    cout << "Nam sinh : " << a[i].namsinh << endl;
    cout << "Diem toan : " << a[i].diemtoan << endl;
    cout << "Diem van : " << a[i].diemvan << endl;
    cout << "Diem ngoai ngu : " << a[i].diemnn << endl;
    float td = tinhdiem(a, i);
    cout << td;
}
float tinhdiem(SinhVien *a, int i)
{
    float diemtb = ((a[i].diemtoan + a[i].diemvan) * 2 + a[i].diemnn) / 5.0;
    cout << "Xep loai sinh vien" << endl;
    if (diemtb >= 8)
    {
        cout << "WOW, sinh vien " << a[i].hoten << " duoc xep loai GIOI Nhe!" << endl;
        return diemtb;
    }
    if (diemtb < 8)
    {
        if (diemtb >= 6.5)
        {
            cout << "Hmm, sinh vien " << a[i].hoten << " duoc xep loai Kha Nhe!" << endl;
            return diemtb;
        }
        else
        {
            if (diemtb >= 5)
            {
                cout << "Hazz em ga qua, sinh vien " << a[i].hoten << " duoc xep loai Trau Bo Nhe!" << endl;
                return diemtb;
            }
            else
            {
                cout << "Thoi em da co het suc roi , sinh vien " << a[i].hoten << " duoc xep loai duoi gon trau bo:<<" << endl;
                return diemtb;
            }
        }
    }
    return 1.0;
}
struct SanPham
{
    char maSP[10];
    string tenSP;
    double gia;
    int soluong;
};
void xuatSP(SanPham *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ma san pham: " << a[i].maSP << endl;
        cout << "Ten san pham: " << a[i].tenSP << endl;
        cout << "Don gia cua san pham: " << a[i].gia << endl;
        cout << "So luong cua san pham trong kho " << a[i].soluong << endl;
    }
}
void suathongtin(SanPham *a, int n)
{
    int p;
    cout << "Nhap so thu tu hang hoa ma ban muon kiem tra";
    cin >> p;
    if (p < 0 || p > n)
    {
        cout << "so thu tu hang khong hop le, hay nhap lai";
        return;
    }
    p--;
    char luachon;

    cout << "Ban muon sua thong tin gi hay nhap theo bang duoi day" << endl;
    cout << "___________________________" << endl;
    cout << "|1. Ma san pham           |" << endl;
    cout << "|2. Ten san pham          |" << endl;
    cout << "|3. Don gia cua san pham  |" << endl;
    cout << "|4. So luong ton kho      |" << endl;
    cout << "|An bat ki de ket thuc    |" << endl;
    cout << "___________________________" << endl;
    bool f = true;
    while (f)
    {
        cout << "Nhap lua chon";
        cin >> luachon;
        cin.ignore();
        switch (luachon)
        {
        case '1':
        {
            char t[10];
            cout << "Nhap lai ma san pham muon sua ";
            cin.get(t, 10);
            cin.ignore();
            for (int k = 0; k < 10; k++)
            {
                a[p].maSP[k] = t[k];
            }

            break;
        }
        case '2':
        {
            string k;
            cout << "Nhap lai ten san pham ma ban muon sua ";
            getline(cin, k);
            cin.ignore();
            a[p].tenSP = k;
            break;
        }
        case '3':
        {
            double gia;
            cout << "NHap lai don gia ma ban muon sua ";
            cin >> gia;
            cin.ignore();
            a[p].gia = gia;
            break;
        }
        case '4':
        {
            int soluong;
            cout << "NHap lai so luong ma ban muon sua ";
            cin >> soluong;
            cin.ignore();
            a[p].soluong = soluong;
            break;
        }
        default:
            cout << "Ket thuc chuong trinh sua thong tin cua san pham!" << endl;
            f = false;
        }
    }
    return;
}
void xoathongtin(SanPham *a, int n)
{
    int p;
    cout << "Nhap so thu tu hang hoa ma ban muon xoa";
    cin >> p;
    if (p < 0 || p > n)
    {
        cout << "so thu tu hang khong hop le, hay nhap lai";
        return;
    }
    p--;
    char luachon;
    cout << "Ban muon xoa thong tin gi hay nhap theo bang duoi day" << endl;
    cout << "___________________________" << endl;
    cout << "|1. Ma san pham           |" << endl;
    cout << "|2. Ten san pham          |" << endl;
    cout << "|3. Don gia cua san pham  |" << endl;
    cout << "|4. So luong ton kho      |" << endl;
    cout << "|An bat ki de ket thuc    |" << endl;
    cout << "___________________________" << endl;

    while (true)
    {
        cout << "Nhap hanh dong tiep theo vao day";
        cin >> luachon;
        switch (luachon)
        {
        case '1':
        {

            strcpy(a[p].maSP, "");

            cout << "Da xoa!" << endl;
            break;
        }
        case '2':
        {

            a[p].tenSP = "DELETE";
            cout << "Da xoa!" << endl;
            break;
        }
        case '3':
        {

            a[p].gia = -1;
            cout << "Da xoa!";
            break;
        }
        case '4':
        {

            a[p].soluong = -1;
            cout << "Da xoa!";
            break;
        }
        default:
            cout << "Ket thuc chuong trinh xoa thong tin cua san pham!" << endl;
            system("pause");
            return;
        }
    }
}
void sapxep(SanPham *a, int size)
{

    int dem = 0;
    int position = 0;
    while (dem < size)
    {
        int min = a[dem].soluong;
        for (int i = dem + 1; i < size; i++)
        {
            if (min > a[i].soluong)
            {
                min = a[i].soluong;
                position = i;
            }
        }
        SanPham tp = a[dem];
        a[dem] = a[position];
        a[position] = tp;

        dem++;
    }
}
void nhapSP()
{

    int n;
    cin >> n;
    if (n > 30 || n < 1)
    {
        cout << "Hay thu lai";
        return;
    }
    SanPham *a = new SanPham[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ma San Pham";
        cin.ignore();
        cin.getline(a[i].maSP, 10);

        cout << "Nhap Ten san pham";

        getline(cin, a[i].tenSP);

        cout << "Nhap gia san pham do";
        cin >> a[i].gia;
        cout << "NHap so luong con trong kho ";
        cin >> a[i].soluong;
    }
    xuatSP(a, n);
    // xoá thông tin của một sản phẩm - số thì thay bằng 0 còn thông tin chữ thì sửa thành '-'
    cout << "__________MENU_________" << endl;
    cout << "|1. Sua thong tin     |" << endl;
    cout << "|2. Xoa thong tin     |" << endl;
    cout << "|3. Sap xep theo SL   |" << endl;
    cout << "|An bat ki de ket thuc|" << endl;
    cout << "_______________________" << endl;
    int luachon;
    while (true)
    {
        cout << "NHap lua chon";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            suathongtin(a, n);
            cout << "Da sua thong tin xong" << endl;
            break;
        }
        case 2:
        {
            xoathongtin(a, n);
            cout << "Da xoa thong tin ma ban muon xoa" << endl;
            break;
        }
        case 3:
        {
            sapxep(a, n);
            cout << "Da sap xep lai Du lieu " << endl;
            cout << "So thu tu" << ". {Ma san pham}" << " [Ten san pham]" << " (Gia san pham)" << " |So luong cua san pham|" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << ". {" << a[i].maSP << "}" << " [" << a[i].tenSP << "]" << " (" << a[i].gia << ")" << " |" << a[i].soluong << "|" << endl;
            }
            break;
        }
        default:
            delete[] a;
            cout << "Ket thuc chuogn trinh" << endl;
            system("pause");

            return;
        }
    }
}
int main()
{
    nhapSP();
}