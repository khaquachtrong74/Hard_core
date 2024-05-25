#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
void bai3_1(char *s)
{
	cout << "Truoc khi xoa khoang trang" << endl;
	cout << "|" << s << "|" << endl;
	int start = 0;
	while (isspace(s[start]))
	{
		start++;
	}
	int end = strlen(s) - 1;
	while (end > 0 && isspace(s[end]))
	{
		end--;
	}
	int j = 0;
	for (int i = start; i <= end; i++)
	{
		s[j++] = s[i];
	}
	s[j] = '\0';
	cout << "Sau khi xoa khoang trang" << endl;
	cout << "|" << s << "|" << endl;
}
void bai3_2(char *s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (isspace(s[i]))
		{
			dem++;
		}
	}
	cout << dem;
}
void bai3_3(char *s)
{
	int demchuso = 0;
	int demchucai = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (isalnum(s[i]))
		{
			demchuso++;
		}
		if (isalpha(s[i]))
		{
			demchucai++;
		}
	}
	cout << "So ky tu chu so trong chuoi: " << demchuso - demchucai << endl;
	cout << "So ky tu chu cai trong chuoi: " << demchucai << endl;
}
void bai3_4(char *s)
{
	int deminhoa = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (isupper(s[i]))
		{
			deminhoa++;
		}
	}
	cout << "So ky tu in hoa trong chuoi: " << deminhoa << endl;
}
void bai3_5(char *s)
{
	int deminthuong = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (islower(s[i]))
		{
			deminthuong++;
		}
	}
	cout << "So ky tu in thuong trong chuoi: " << deminthuong << endl;
}
void bai3_6(char *s)
{
	int upper = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		s[upper++] = toupper(s[i]);
	}
	s[upper] = '\0';
	cout << "Sau khi chuyen toan bo chuoi sang in HOA: " << s << endl;
}
void bai3_7(char *s)
{
	int lower = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		s[lower++] = tolower(s[i]);
	}
	s[lower] = '\0';
	cout << "Sau khi chuyen toan bo chuoi sang in THUONG: " << s << endl;
}
void bai3_8(char *s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (isspace(s[i]))
		{
			s[0] = toupper(s[0]);
			s[i + 1] = toupper(s[i + 1]);
		}
	}
	cout << "Chuoi sau ki viet hoa cac ky tu dau: " << s << endl;
}
void bai3_9(char *s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (isspace(s[i]) && isalpha(s[i - 1]))
		{
			dem++;
		}
	}
	cout << "So tu co trong chuoi: " << dem << endl;
}
void bai4(char *s)
{
	int start = 0;
	int end = strlen(s) - 1;
	int palindrome = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = tolower(s[i]);
	}
	while (start < end)
	{
		if (s[start] == s[end])
		{
			palindrome++;
		}
		start++;
		end--;
	}
	if (palindrome == (strlen(s) / 2))
	{
		cout << "Chuoi vua nhap la chuoi palindrome \n";
	}
	else
	{
		cout << "Chuoi vua nhap KHONG phai la chuoi palindrome \n";
	}
}
int bai6(char *s)
{
	static char day[50];
	static char month[50];
	static char year[50];
	int d = 0, m = 0, y = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]) && d <= 1)
		{
			day[d] = s[i];
			d++;
		}
		else if (isdigit(s[i]) && m <= 1)
		{
			month[m] = s[i];
			m++;
		}
		else if (isdigit(s[i]) && y <= 3)
		{
			year[y] = s[i];
			y++;
		}
	}
	day[d] = '\0';
	month[m] = '\0';
	year[y] = '\0';
	int Day = atoi(day);
	int Month = atoi(month);
	int Year = atoi(year);
	int dayofmonth = 0;
	int dayofyear = 0;
	int thang = Month - 1;
	while (thang > 0)
	{
		if (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0)
		{
			if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
			{
				dayofmonth = 31;
			}
			else if (thang == 2)
			{
				dayofmonth = 29;
			}
			else
			{
				dayofmonth = 30;
			}
		}
		else
		{
			if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
			{
				dayofmonth = 31;
			}
			else if (thang == 2)
			{
				dayofmonth = 28;
			}
			else
			{
				dayofmonth = 30;
			}
		}
		dayofyear = dayofyear + dayofmonth;
		thang--;
	}
	return dayofyear + Day;
}
int bai7(char *s1, char *s2)
{
	int i = 0;
	char copy[30];
	while (i < strlen(s1))
	{									   // lam den khi het chuoi s1
		strncpy(copy, s1 + i, strlen(s2)); // copy s1 vao copy voi do dai = s2, "s1 + i" la vi tri bat dau copy
		if (strcmp(s2, copy) == 0)
		{
			return 1;
		}
		else if (strcmp(s2, copy) > 0 || strcmp(s2, copy) < 0)
		{
			i++;
		}
		// cout << copy << endl;
	}
	return 0;
}
int main()
{
	// Bai1
	/*char s1[100];
	cin.get(s1, 100);
	cin.ignore();
	char s2[50];
	cin.get(s2, 50);
	cout << "so ki tu s1: " << strlen(s1) << endl << "so ki tu s1: " << strlen(s2) << endl;
	if (strlen(s1) > strlen(s2)) {
		cout << "Chuoi s1 dai hon s2\n";
	}
	else if (strlen(s1) == strlen(s2)) {
		cout << "Chuoi s1 va s2 dai bang nhau\n";
	}
	else {
		cout << "Chuoi s2 dai hon s1\n";
	}
	for (int i = 0; i < strlen(s1); i++) {
		if (isspace(s1[i])) {
			s1[0] = toupper(s1[0]);
			s1[i + 1] = toupper(s1[i + 1]);
		}
	}
	for (int i = 0; i < strlen(s1); i++) {
		if (isspace(s2[i])) {
			s2[0] = toupper(s2[0]);
			s2[i + 1] = toupper(s2[i + 1]);
		}
	}
	cout << "Sau khi in hoa chu cai dau moi ky tu:\n";
	cout << s1 << endl << s2;
	strcat_s(s1, s2);
	cout << "Sau khi noi s2 vao s1, ta co: " << s1 << endl;*/

	// Bai2
	/*char s[50];
	char s1[50];
	cout << "Nhap 'ho, ten' vao: "; cin.get(s, 50);
	int j = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (!ispunct(s[i])) {
			s1[j++] = s[i];
		}
		s1[j] = '\0';
	}

	cout << s1;*/

	// Bai3
	char s[50];
	cout << "Nhap chuoi s: ";
	cin.get(s, 50);
	cout << "Sau khi xoa khoang trang dau, cuoi: ";
	bai3_1(s);
	// cout << "\n";
	// cout << "So khoang trang co trong chuoi: ";
	// bai3_2(s);
	// cout << "\n";
	// bai3_3(s);
	// bai3_4(s);
	// bai3_5(s);
	// bai3_6(s);
	// bai3_7(s);
	// bai3_8(s);
	// bai3_9(s);

	// Bai4
	/*char s[50];
	cout << "Nhap chuoi s: "; cin.get(s, 50);
	bai4(s);*/

	// Bai5
	/*int max = 0;
	char s[15];
	char S[15];
	char password_correct[] = "SinhVienCQ";
	label: cout << "Nhap passwrod: ";
	cin.get(s, 15);
	cin.ignore();
	strcpy_s(S, s);
	system("cls");
	for (int i = 0; i < strlen(s); i++) {
		s[i] = '*';
	}
	cout << "Password vua nhap: ";
	for (int i = 0; i < strlen(s); i++) {
		cout << s[i] << " ";
	}
	if (strcmp(S, password_correct) == 0) {
		cout << "Nhap thanh cong !\n";
	}
	else {
		if (max > 1) {
			cout << "Da het so lan nhap. Quay lai sau !\n";
			exit(0);
		}
		cout << "Nhap sai. Nhap lai !\n";
		++max;
		goto label;
	}*/

	// bai6
	/*char s[50];
	cout << "Nhap vao 'Ngay-Thang-Nam': ";
	cin.get(s, 50);
	cin.ignore();
	cout << "Ngay " << s << " la ngay thu " << bai6(s) << " trong nam" << endl;*/

	// Bai8
	/*char s1[50];
	char s2[] = " ";
	char* s3;
	cout << "Nhap Ho va Ten cua ban vao day: ";
	cin.get(s1, 50);
	char* ptok = strtok_s(s1, s2, &s3); //t�ch s1 theo �i?u ki?n l� k� t? ? s2 v� l�u v�o s3
	while (ptok != NULL) {
		cout << ptok << endl;
		ptok = strtok_s(NULL, s2, &s3);
	}*/

	// Bai7
	/*char s1[50];
	char s2[50];
	cin.get(s1, 50);
	cin.ignore();
	cin.get(s2, 50);
	if (bai7(s1, s2) == 1) {
		cout << "Chuoi s2: '" << s2 << "' co trong chuoi s1: '" << s1 << "'" << endl;
	}
	if (bai7(s1, s2) == 0) {
		cout << "Chuoi s2: '" << s2 << "' khong co trong chuoi s1: '" << s1 << "'" << endl;
	}*/

	return 0;
}
