/*bài 7
Cho f1=1;f2=1 và fn=fn-1+fn-2 với mọi n>2
Hãy tính :
Sn= 1/1+f1 + 2/1+f2 + ..... + n/1+fn (với n là số nguyên dương)
a)Hãy tính S5
b)Viết hàm tính Sn bằng cách sử dụng đệ quy(fn cũng đệ quy)
c)Viết hàm tính Sn bằng cách không sử dụng đệ quy cũng không biến mảng (fn cũng không đệ quy,không mảng)
*/

#include <iostream>
using namespace std;

int de_quy_fn(int n) {
    if (n <= 2)
        return 1;
    return de_quy_fn(n - 1) + de_quy_fn(n - 2);
}

// Hàm tính Sn sử dụng đệ quya
double de_quy_sn(int n) {
    if (n == 1)
        return 1.0 / (1 + de_quy_fn(1));
    return de_quy_sn(n - 1) +  static_cast<double>(n) / (1 + de_quy_fn(n));
}
int khong_de_quy_fn(int n) {
    if (n <= 2)
        return 1;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Hàm tính Sn không sử dụng đệ quy và không mảng
double khong_de_quy_sn(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += static_cast<double>(i) / (1 + khong_de_quy_fn(i));
    }
    return sum;
}
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    float sn = de_quy_sn(n);
    cout << sn << endl;
    
    double sn2=khong_de_quy_sn(n);
    cout << sn2<<endl;
    return 0;
}



