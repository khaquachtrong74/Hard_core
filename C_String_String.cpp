#include "String_Cstring.h"
string chuyen_Doi(string &a)
{
    vector<int> my_vector;
    my_vector.push_back(0);
    // Lưu những vị trí trước sau tại  khoảng trắng
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ')
        {
            my_vector.push_back(i - 1);
            my_vector.push_back(i + 1);
        }
    }
    my_vector.push_back(a.size() - 1); // nạp vào phần tử cuối của chuỗi
    if (my_vector[my_vector.size() - 1] == my_vector[my_vector.size() - 2])
    { // trường hợp giá trị phần tử cuối trùng nhau trong my_vector thì xoá
        my_vector.pop_back();
    }
    // chạy lần lượt chuỗi a tại vị trí my_vector[my_vector.size() - 1]
    // để chuyển đổi nếu thoả mãn nó là kí tự thường

    while (my_vector.size() != 0)
    {

        for (int i = 'a'; i < 'z'; i++)
        {
            if (a[my_vector[my_vector.size() - 1]] == i)
            {
                a[my_vector[my_vector.size() - 1]] -= 32;
                break;
            }
        }
        my_vector.pop_back();
    }
    // in ra màn hình
    // trả về kết quả
    return a;
}

// dùng để tách "họ,tên" thành "họ tên"
// cách 1 phổ thông
string concat_TwoString(string hoten)
{
    string b;
    for (int i = 0; i < hoten.size(); i++)
    {
        if (hoten[i] == ',')
        {
            int t = i + 1;
            while (t < hoten.size())
            {
                b += hoten[t];
                t++;
            }
            hoten.resize(i);
            break;
        }
    }
    string result = hoten + " " + b;
    return result;
}
// cách 2 ứng dụng các hàm built in
string tach_HoTen(string hoten)
{
    size_t vitrikhoangtrang = hoten.find(',');
    if (vitrikhoangtrang == string::npos)
    {
        return hoten;
    }
    // tách họ và tên;
    // từ 0 tới dấu ,
    string ho = hoten.substr(0, vitrikhoangtrang);
    // từ sau dấu , tới hết
    string ten = hoten.substr(vitrikhoangtrang + 1);
    chuyen_Doi(ho);
    chuyen_Doi(ten);
    string newHoTen = ho + " " + ten;
    return newHoTen;
}
// câu 3 xây các hàm
void edit_KhoangTrang(char *a)
{ // thay đổi ký tự đầu nếu nó là khoảng trắng
    if (*a == ' ')
    {
        *a = '@';
    }
    int size = 0;
    while (*a != '\0')
    {
        size++;
        ++a;
    }
    if (*(a + size - 2) == ' ')
    {
        *(a + size - 2) = '@';
    }
    int index = 0;
    while (index < size)
    {
        cout << *(a + index);
        index++;
    }
    int i = 0;
    for (int i = 0; i < size; i++)
    {
        cout << *(a + i);
    }
    return;
}
int main()
{
    int a = 3 * false;
    cout << a;
}