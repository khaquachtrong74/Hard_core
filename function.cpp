#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
struct park
{
    vector<vector<int>> Park;
};

struct Car
{
    time_t time1 = time(0);
    std::string BienSo;
    int col;
    int row;
};
// amount: bãi trả về | col: số cột | row: số hàng
void Make_Park(int col, int row, vector<vector<int>> &amount)
{
    // tạo ra bãi đậu xe
    amount.resize(row);
    for (int i = 0; i < col; i++)
    {
        amount[i].resize(col);
    }
}

void Reset_Park(vector<vector<int>> &amount, int hang, int cot)
{
    // làm trống bãi đậu xe với 0.
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            amount[i][j] = 0;
        }
    }
}

bool Check_Empty(vector<vector<int>> &amount, int row, int col)
{
    // Hàm kiểm tra xem chỗ đó có trống không?
    return amount[row][col] == 0 ? true : false;
}

void Input_Things(vector<vector<int>> &amount, int row, int col, bool &flag)
{
    if (Check_Empty(amount, row, col))
    {
        amount[row][col] = 1;
        flag = true;
    }
}

void Output_Park(vector<vector<int>> &amount)
{
    // lưu ý chỗ amount sẽ có từng bãi riêng nên yêu cầu nhập bãi muốn xem.
    for (int i = 0; i < amount.size(); i++)
    {
        for (int j = 0; j < amount[i].size(); j++)
        {
            cout << amount[i][j] << " ";
        }
        cout << endl;
    }
}
// Một đối tượng khi vào func 1 sẽ tự tạo biển số xe_ thời gian_
void Make_BienSo(vector<Car> &a, int index)
{ // tạo ra biển số xe
    srand(static_cast<unsigned int>(time(0)));
    a[index].BienSo = "";

    for (int i = 0; i < 9; i++)
    {
        if (i < 2 || i > 3)
        {
            int Random = rand() % 10;
            a[index].BienSo += to_string(Random);
        }
        else if (i == 2)
        {
            a[index].BienSo += "-";
        }
        else if (i == 3)
        {
            a[index].BienSo += char('A' + rand() % 26);
        }
    }
}

void Print_Output(Car &a)
{
    fstream Data_TongHop("Data_TongHop.txt");
    int fee = 50000; // phí gửi xe
    time_t time2 = time(NULL);
    if (difftime(time2, a.time1) > 1800)
    {
        fee += 30000 * (difftime(time2, a.time1) / 1800.0);
    }
    Data_TongHop << "So tien phi la " << fee << endl;
    Data_TongHop << "Xe vao bai luc " << ctime(&a.time1) << endl;
    Data_TongHop << "Xe ra khoi bai luc " << ctime(&time2) << endl;
    cout << "So tien phi la " << fee << endl;
    cout << "Xe vao bai luc " << ctime(&a.time1) << endl;
    cout << "Xe ra khoi bai luc " << ctime(&time2) << endl;
}

void function_01(vector<vector<int>> &Park, vector<Car> &a, int index, int &k)
{
    srand(static_cast<unsigned int>(time(0)));
    bool flag = true;
    // Make_BienSo(a, index);
    a[index].time1 = time(NULL);
    cout << "Truoc khi " << endl;
    Output_Park(Park);
    Make_BienSo(a, index);
    for (int i = 0; i < Park.size(); i++)
    {
        for (int j = 0; j < Park[i].size(); j++)
        { // kiểm tra xem bãi xe còn trống không
            if (Park[i][j] == 0)
            {
                flag = false;
                break;
            }
        }
    }
    // trường hợp thoả mãn bãi còn chỗ để xe
    if (flag == false)
    {
        // random vị trí
        while (flag == false)
        {
            a[index].row = rand() % 2;
            a[index].col = rand() % 2;
            Input_Things(Park, a[index].row, a[index].col, flag);
        }
    }

    else
    { // trường hợp bãi full
        cout << "Bai nay da full chung toi se doi ban sang bai khac!" << endl;
        k++;
        Make_Park(2, 2, Park);
        return;
    }
    cout << "Sau khi: " << endl;
    Output_Park(Park);
}

void Release(vector<vector<int>> &Park, vector<Car> a, int index)
{
    ifstream readfile("Data_Bienso.txt");
    string find;
    string line;
    int local = -1;
    while (getline(readfile, line))
    {
        cout << line << endl;
    }
    cout << "Nhap bien so xe ";
    cin >> find;
    for (int i = 0; i < index; i++)
    {
        if (a[i].BienSo == find)
        {
            local = i;
        }
    }
    if (local == -1)
    {
        return;
    }
    Park[a[local].row][a[local].col] = 0;
    cout << "Xuat xe " << a[local].BienSo << " ra khoi bai!" << endl;
    Print_Output(a[local]);
    readfile.close();
}

void Tonghop()
{
    ifstream inFile("Data_TongHop.txt");
    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }
    inFile.close();
}

void find_vitri(vector<Car> &a, vector<vector<int>> Park)
{
    string bienso;
    cin >> bienso;
    int index = 0;
    while (index < a.size())
    {
        for (int i = 0; i < Park.size(); i++)
        {
            for (int j = 0; j < Park[i].size(); j++)
            {
                if (a[index].BienSo == bienso && a[index].row == i && a[index].col == j && Park[i][j] == 1)
                {
                    cout << "VI tri da thay [" << i << "][" << j << "]" << endl;
                    return;
                }
            }
        }
        index++;
    }
    cout << "Khong tim thay " << endl;
    return;
}