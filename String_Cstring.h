#ifndef STRING_CSTRING_H
#define STRING_CSTRING_H
// thư viện dùng để khai báo cấu trúc các hàm
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
string concat_TwoString(string hoten);
string tach_HoTen(string hoten);
string chuyen_Doi(string &a);
string count_InHoa(string &a);
string Chuyen_InThuong(string &a);

void edit_KhoangTrang(char *a);
char count_KhoangTrang(char *a);
char count_InThuong(char *a);
char Chuyen_InHoa(char *a);

#endif