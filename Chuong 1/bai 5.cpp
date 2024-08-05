/*bài 5
a)Cho biểu thức S(n)= căn 2 + ...+ căn 2 ;biểu thức này có n dấu căn.Viết hàm đệ quy tính S(n)
ví dụ n=5 thì kết quả là 1,99759.
b)viết hàm đệ quy/không đệ quy tính tổng 1-1/2+1/3-1/4+....+(-1^n+1)/n;
c),,,,,,,,,  ...........                 -1+2-3+...+(-1^n)*n
d),,,,,,,,,  ...........         S(x,n)=-x+x^2/2! - x^3/3! + .....+(-1)^n. x^n/n!
e)Dãy hiperbolic tangent :T(n)=(e^n-e^-n)/(e^n+e^-n)
trong đó e là số euler,một hằng số toán học quan trọng tương đương với 2,71828
Hãy viết hàm đệ quy/ không đệ quy tính T(n).
*/
#include<iostream>
#include<cmath>
#define e 2.71828
using namespace std;

float de_quy_n_dau_can(int n)
{
	if(n==0)
	{
		return 0;
	}
	return sqrt(2) + de_quy_n_dau_can(n - 1);
}

float de_quy_tong_cau_b(int n)
{
	if(n==1)
	{
		return 1;
	}
	return 1.0*pow(-1,n+1)/n +de_quy_tong_cau_b(n-1);
}

float khu_de_quy_cau_b(int n)
{
	if(n==1) return 1;
	float tong=0;
	for(int i=1;i<=n;i++)
	{
		tong+=1.0* pow(-1,i+1)/i;
	}
	return tong;
}

int de_quy_tong_cau_c(int n)
{
	if(n==1) return -1;
	return pow(-1, n) * n + de_quy_tong_cau_c(n - 1);
}

int khu_de_quy_cau_c(int n)
{
	if(n==1) return 1;
	
	int tong=0;
	for(int i=1;i<=n;i++)
	{
		tong+=pow(-1, i) * i;
	}
	return tong;
}

int giai_thua(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * giai_thua(n - 1);
}

float de_quy_tong_s(int n, int x)
{
    if (n == 1) return -x;
    if (n == 2) return x * x;
    return 1.0 * pow(x, n) * pow(-1, n) / giai_thua(n) + de_quy_tong_s(n - 1, x);
}

float khu_de_quy_tong_s(int n, int x)
{
    if (n == 1) return -x;
    if (n == 2) return x * x;
    float tong = 0;
    int giaithua = 1;
    for (int i = 3; i <= n; i++)
    {
        giaithua *= i;
        tong += 1.0 * pow(x, i) * pow(-1, i) / giaithua;
    }
    return tong;
}

float de_quy_tinh_hiper(int n)
{
	if(n==0) return 0;
	return 1.0* (pow(e,n)-1/pow(e,n))/(pow(e,n) + 1/pow(e,n)) + de_quy_tinh_hiper(n-1);
}

int main()
{
	int n;
	cout <<"Nhap n : ";
	cin>>n;
	float caua=de_quy_n_dau_can(n);
	cout <<caua<<endl;
	
	float caub= de_quy_tong_cau_b(n);
	cout <<caub<<endl;
	
	float caub2=khu_de_quy_cau_b(n);
	cout <<caub2<<endl;
	
	int cauc=de_quy_tong_cau_c(n);
	cout <<cauc<<endl;
	
	int cauc2=khu_de_quy_cau_c(n);
	cout <<cauc2<<endl;
	
	int x;
	cout <<"Nhap x: ";
	cin>>x;
	int caud=de_quy_tong_s(n,x);
	cout <<caud<<endl;
	int caud2=khu_de_quy_tong_s(n,x);
	cout<<caud2<<endl;
	
	float cauf=de_quy_tinh_hiper(n);
	cout <<cauf<<endl;
	
} 
