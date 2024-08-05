/*Bai 3
Dãy fibonaci là dãy vô hạn các số tự nhiên.Công thức truy hồi dãy như sau:
	f1=1;
	f2=1;
	fn=fn-1+fn-2 với n là số nguyên lớn hơn 2;fn là số hạng thứ n của dãy fibonaci.
	vài số hạng đầu tiên của dãy fibonacci : f1=1,f2=1;f3=2,f4=3,f5=5,f6=8;....
a)viết hàm đệ quy tìm fn
b)viết hàm không đệ quy tìm fn
c)Viết hàm kiểm tra xem một số nguyên dương m có phải số fibonacci hay không(một số thuộc dãy fibonacci được goi là số fibonaci)
*/
#include<iostream>
#include<cmath>
using namespace std;

// Phần a: Hàm đệ quy tìm số Fibonacci thứ n
int de_quy_fibo(int n) {
    if (n <= 0) return 0; // Trường hợp không hợp lệ
    if (n == 1 || n == 2) return 1;
    return de_quy_fibo(n - 1) + de_quy_fibo(n - 2);
}

// Phần b: Hàm không đệ quy tìm số Fibonacci thứ n
int khu_de_quy_fibo(int n) {
    if (n <= 0) return 0; // Trường hợp không hợp lệ
    if (n == 1 || n == 2) return 1;
    
    int f1 = 1, f2 = 1, fn = 0;
    for (int i = 3; i <= n; ++i) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}
bool la_so_fibo(int m)
{
	if(m<0) return false;
	int f1=1;
	int f2=1;
	if(m==0 || m==1 )return true;
	while(f2<m)
	{
		int temp=f2;
		f2=f1+f2;
		f1=temp;
	}
	return (f2==m);
}
int main()
{
	int n;
	cout <<"Nhap n : ";
	cin>>n;
	int caua=de_quy_fibo(n);
	cout <<caua<<endl;
	int caub=khu_de_quy_fibo(n);
	cout<<caub<<endl;
	int m=6;
	if(la_so_fibo(m)){
		cout << m <<" la so fibo . "<<endl;
	}
	else{
		cout << m <<"  Khong phai fibo "<<endl;
	}
	
	return 0;
}