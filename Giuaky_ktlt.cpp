#include <iostream>
#include <ctime>
using namespace std;
void function_xuat(int **arr, int ngay, int sanpham);
int function_min(int **&arr, int ngay, int sanpham, int index, int soluong);
int function_max(int **&arr, int ngay, int ketqua, int index, int SP);
bool check(int a, int b);
int sum_SP(int **&arr, int ngay, int SP, int index, int kq);

void swap(int &a, int &b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
int *ptr_check(int **&arr, int day, int SP);
void sapxep_lungtung(int **&arr, int day);
void function_nhap(int **&arr, int &ngay, int &sanpham)
{
    srand(time(0));

    cout << "Nhap so ngay:";
    cin >> ngay;
    cout << "Nhap so san pham:";
    cin >> sanpham;
    arr = new int *[ngay];
    for (int i = 0; i < ngay; i++)
    {
        *(arr + i) = new int[sanpham];
    }
    // số sản phẩm sẽ được random ngẫu nhiên từ 1 tới 99;
    for (int i = 0; i < ngay; i++)
    {
        for (int j = 0; j < sanpham; j++)
        {
            *(*(arr + i) + j) = 10 + rand() % 89;
        }
    }
    // gọi hàm xuất đồng thời ngừng cấp phát động:
    function_xuat(arr, ngay, sanpham);
}

void function_xuat(int **arr, int ngay, int sanpham)
{

    // khúc này thì xuất ra thôi
    cout << "          ";
    for (int i = 0; i < sanpham; i++)
    {
        cout << " SP " << i + 1 << "   ";
    }
    cout << endl;
    for (int i = 0; i < ngay; i++)
    {
        if (i < 9)
            cout << " Ngay: " << i + 1;
        else
            cout << " Ngay:" << i + 1;
        for (int j = 0; j < sanpham; j++)
        {
            cout << " | " << *(*(arr + i) + j) << " | ";
        }

        cout << endl;
    }
    int min = 100, col;
    // dòng này vòng lặp sẽ chạy hết các cột sản phẩm và tìm ra giá trị thấp nhất
    for (int i = 0; i < sanpham; i++)
    {
        int a = function_min(arr, ngay, arr[0][i], 0, i);
        cout << "So luong thap nhat cua san pham " << i + 1 << " la " << a << endl;
        // trả về thứ tự của mặt hàng có số lượng thấp nhất trong cả 3
        if (min > a)
        {
            min = a;
            col = i;
        }
    }
    for (int i = 0; i < ngay; i++)
    {
        if (arr[i][col] == min)
        {
            cout << "Mat hang co so luong it nhat tai ngay " << i + 1 << " Cot SP " << col + 1 << " voi gia tri la " << min << endl;
            break;
        }
    }
    int n;
    cout << "Nhap ngay ma ban muon xem SP nao ban nhieu nhat ";
    cin >> n;
label1:
{
    if (check(n - 1, ngay))
    {
        int a = function_max(arr, n, arr[0][0], 0, sanpham);
        for (int i = 0; i < sanpham; i++)
        {
            if (arr[n - 1][i] == a)
            {
                cout << "SP " << i + 1 << " : ban duoc nhieu so luong nhat la " << a << endl;
            }
        }
    }
    else
    {
        cout << "Yeu cau nhap lai";
        cin >> n;
        goto label1;
    }
}
    int soluong;

    cout << "Nhap SP ma ban muon tinh tong cua no";
    cin >> soluong;
    int a = sum_SP(arr, ngay, soluong, 0, 0);
    cout << "Tong cua SP " << soluong << " la " << a << endl;
    system("pause");
    sapxep_lungtung(arr, ngay);
}

int function_min(int **&arr, int ngay, int ketqua, int index, int SP)
{
    // biến index có tác dụng đi từ ngày 1 tới biến ngay đối với mỗi SP
    if (index == ngay)
    {
        return ketqua;
    }
    return function_min(arr, ngay, ketqua < arr[index][SP] ? ketqua : arr[index][SP], index + 1, SP);
}

int function_max(int **&arr, int ngay, int ketqua, int index, int SP)
{
    // biến index có tác dụng đi từ ngày 1 tới biến ngay đối với mỗi SP
    if (index == SP)
    {
        return ketqua;
    }
    return function_max(arr, ngay, ketqua > arr[ngay - 1][index] ? ketqua : arr[ngay - 1][index], index + 1, SP);
}

bool check(int a, int b)
{
    return a < b ? true : false;
}

// Tổng số lượng của một mặt hàng
int sum_SP(int **&arr, int ngay, int SP, int index, int kq)
{
    if (index == ngay)
    {
        return kq;
    }
    return sum_SP(arr, ngay, SP, index + 1, kq += arr[index][SP - 1]);
}

// Hàm hoán đổi hai số nguyên
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân chia và chọn pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Chọn phần tử cuối cùng làm pivot
    int i = (low - 1);     // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Hàm QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Đệ quy sắp xếp các phần tử trước và sau khi phân chia
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// hàm gần cuối
void sapxep_lungtung(int **&arr, int day)
{
    int *ptr_a = new int[day];
    // dãy tăng dần
    for (int i = 0; i < day; i++)
    {
        *(ptr_a + i) = arr[i][0];
    }
    // mấy hàm quickSort này là lấy code mạng do lười gõ hàm sắp xếp :v
    quickSort(ptr_a, 0, day - 1);
    cout << "sau khi sap xep xong theo thu tu tang dan" << endl;
    for (int i = 0; i < day; i++)
    {
        cout << *(ptr_a + i) << endl;
    }
    // ngày lẻ tăng dần trong khi ngày chẵn giảm dần
    cout << "Ngay chan giam dan, ngay le tang dan " << endl;
    int chan = 1, le = 0;
    for (int i = 0; i < day; i++)
    {
        if (i % 2 == 0)
        {
            cout << *(ptr_a + le) << endl;
            le++;
        }
        else
        {
            cout << *(ptr_a + day - chan) << endl;
            chan++;
        }
    }
    delete[] ptr_a;
    ptr_a = nullptr;
}

// hàm cuối
int *ptr_check(int **&arr, int day, int SP)
{
    int m = 0;
    int *ptr;
    for (int i = 0; i < day; i++)
    {
        for (int j = 0; j < SP; j++)
        {
            if (m < *(*(arr + i) + j))
            {
                ptr = &*(*(arr + i) + j);
                m = *(*(arr + i) + j);
            }
        }
    }
    return ptr;
}
int main()
{
    int **arr = nullptr;
    int ngay, sanpham;
    int *ptr = nullptr;

    function_nhap(arr, ngay, sanpham);
    // làm người có đạo đức tí : có new thì có delete
    cout << ngay << "|" << sanpham << endl;
    ptr = ptr_check(arr, ngay, sanpham);
    cout << "Dia chi mat hang co so luong lon nhat" << ptr_check(arr, ngay, sanpham) << endl;
    int dem = 1;
    while (arr++)
    {
        if (ptr == *arr)
        {
            int z = float(dem / ngay) > (dem / ngay) + 0.5 ? (dem / ngay) + 1 : dem / ngay;
            cout << "So ngay bang " << ngay - dem << " tai SP" << z;
        }
        dem++;
    }
    for (int i = 0; i < ngay; i++)
    {
        for (int j = 0; j < sanpham; j++)
        {
            if (ptr == &arr[i][j])
            {
                cout << "Mat hang co so luong ban lon nhat la SP " << j + 1 << " Tai ngay " << i + 1 << "voi gia tri la " << *ptr << endl;
                break;
            }
        }
    }
    for (int i = 0; i < ngay; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
    if (arr == nullptr)
    {
        cout << "Da giai phong thanh cong" << endl;
    }

    return 0;
}