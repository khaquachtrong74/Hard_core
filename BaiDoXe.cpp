#include "function.h"

int main()
{
    vector<park> P;
    int n;
    cout << "Nhap so luon bai cua ban";
    cin >> n;
    P.resize(n);
    int k = 0;
    int luachon = 0;
    ofstream Data_Bienso("Data_Bienso.txt");
    ofstream Data_TongHop("Data_TongHop.txt");
    vector<Car> my_Object;
    string line;
    my_Object.resize(25);
    cout << "Ban co 4 lua chon" << endl;
    cout << "{1} Nhap xe vao bai x" << endl;
    cout << "{2} Xuat 1 xe ra khoi bai" << endl;
    cout << "{3} Tong hop so luong xe da ra vao bai trong ngay" << endl;
    cout << "{4} Tim 1 xe trong bai " << endl;
    cin >> luachon;
    int index = 0;
    Make_Park(2, 2, P[k].Park);
    Reset_Park(P[k].Park, 2, 2);
    while (true)
    {
        bool f = true;
        switch (luachon)
        {
        case 1:
            function_01(P[k].Park, my_Object, index, k);
            Data_Bienso << "________________________" << endl;
            Data_Bienso << my_Object[index].BienSo << endl;

            Data_TongHop << "________________________" << endl;
            Data_TongHop << my_Object[index].BienSo << endl;
            Data_TongHop << ctime(&my_Object[index].time1) << endl;
            cin >> luachon;
            index++;
            break;
        case 2:
            Release(P[k].Park, my_Object, index);
            cin >> luachon;
            break;
        case 3:
            Tonghop();
            cin >> luachon;
            break;
        case 4:
            find_vitri(my_Object, P[k].Park);
            cin >> luachon;
            break;
        default:
            break;
            break;
        }
    }
    Data_Bienso.close();
    Data_TongHop.close();
    return 0;
}