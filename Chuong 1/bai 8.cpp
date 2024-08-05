/*Bai 8 
Dãy xn được định nghĩa như sau
x1=1;
xn=n(x1+x2+x3+.......+xn-1) với n>1
a)tính x7
b)viết hàm đệ quy tính giá trị xn;
c)viết hàm không đệ quy tính giá trị xn
*/
#include<iostream>
using namespace std;

int de_quy_xn(int n)
{
	if(n==1) return 1;
	int tong=0;
	for(int i=1;i<n;i++)
	{
		tong+=de_quy_xn(i);	
	}
	return n*tong;
	
}
int khong_de_quy_xn(int n) {
    if (n == 1) return 1;
    int* xn = new int[n + 1]; // Mảng để lưu trữ các giá trị xn
    xn[1] = 1; // Giá trị cơ bản
    for (int i = 2; i <= n; ++i) {
        int tong = 0;
        for (int j = 1; j < i; ++j) {
            tong += xn[j]; // Tính tổng các giá trị trước đó
        }
        xn[i] = i * tong; // Tính xn[i] theo công thức
    }
    int result = xn[n];
    delete[] xn; // Giải phóng bộ nhớ
    return result;
}
int main()
{
	int n;
	cout <<"Nhap n : ";
	cin>>n;
	int caua=de_quy_xn(n);
	cout <<caua<<endl;
	
	int caub=khong_de_quy_xn(n);
	cout<<caub<<endl;
	
	return 0;
}