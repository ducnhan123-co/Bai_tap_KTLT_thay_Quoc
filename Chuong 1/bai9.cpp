/*Dãy số xn được định nghĩa như sau:
xo=1;x1=1;
x=n*x0 + (n-1)*x1+ (n-2)*x2+(n-3)*x3 +.....+xn-1 với mọi n>1
a) tính x7
b)viết hàm đệ quy tính giá trị xn
c)viết hàm không đệ quy tính giá trị xn
*/
#include <iostream>
using namespace std;
int de_quy_xn(int n) {
    if (n == 0 || n == 1)
        return 1;

    int tong = 0;
    for (int i = 0; i < n; ++i) {
        tong += (n - i) * de_quy_xn(i);
    }
    return tong;
}
int khong_de_quy_xn(int n) {
    if (n == 0 || n == 1)
        return 1;

    int* xn = new int[n + 1];
    xn[0] = 1;
    xn[1] = 1;

    for (int i = 2; i <= n; ++i) {
        int tong = 0;
        for (int j = 0; j < i; ++j) {
            tong += (i - j) * xn[j];
        }
        xn[i] = tong;
    }

    int result = xn[n];
    delete[] xn; // Giải phóng bộ nhớ
    return result;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Gia tri cua x_" << n << " la: " << khong_de_quy_xn(n) << endl;
    cout << "Gia tri cua x_" << n << " la: " << de_quy_xn(n) << endl;
    return 0;
}