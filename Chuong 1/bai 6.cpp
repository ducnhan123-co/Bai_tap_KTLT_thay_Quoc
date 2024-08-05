/* Cho hai dãy số xn yn trong đó x0=1;y0=2 và nếu n>=1 thì xn yn được tính theo quy luậy sau
xn= xn-1/3+ yn-1/2 + 27 ; yn=xn-1/5 + yn-1/7 + 11
a)Hãy tính x3 và y3
b)Hãy tính xn,yn bằng cách sử dụng đệ quy
c)Viết hàm tính xn,yn bằng cách không đệ quy và không mảng Yêu cầu đpt O(n)
*/
#include<iostream>
using namespace std;

float de_quy_xn(int n);
float de_quy_yn(int n);

float de_quy_xn(int n)
{
	if(n==0) return 1;
	return 1.0*de_quy_xn(n-1)/3 + 1.0*de_quy_yn(n-1)/2 + 27;
	
}
float de_quy_yn(int n)
{
	if(n==0) return 2;
	return 1.0*de_quy_xn(n-1)/5 + 1.0*de_quy_yn(n-1)/7 + 11;
	
}

void tinh_xn_yn(int n, double xn, double yn) {
    double x_prev = 1;
    double y_prev = 2;
    for (int i = 1; i <= n; i++) {
        double x_ncurrent = x_prev / 3.0 + y_prev / 2.0 + 27;
        double y_ncurrent = x_prev / 5.0 + y_prev / 7.0 + 11;
        
        x_prev = x_ncurrent;
        y_prev = y_ncurrent;
    }
    xn = x_prev;
    yn = y_prev;
}

int main()
{
	int n;
	cout <<"Nhap n : ";
	cin>>n;
	
	float xn=de_quy_xn(n);
	cout <<"xn= "<<xn<<endl;
	float yn=de_quy_yn(n);
	cout <<"yn= "<<yn<<endl;
	
	int xn2,yn2;
	tinh_xn_yn(n,xn2,yn2);
	cout << xn<<endl;
	cout <<yn<<endl;
	return 0;
}
