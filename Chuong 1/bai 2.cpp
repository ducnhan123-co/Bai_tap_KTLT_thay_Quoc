/*Cho dãy số an được định nghĩa như sauL
a0=1;
an=1/2 * an-1 với n là số nguyên lớn hơn 0; vìa số hạng đầu tiên của dãy an là 1,1/2,1/4,1/8,1/16,...
	a) viết hàm đệ quy tìm số hạng thứ n dãy trên 
	b)viết hàm không đệ quy tìm số hạng thứ n dãy số trên
	c)viết hàm tính tổng S=1+1/2+1/4+1/8+1/16 +.....+1/2^n với mọi n>=0
*/
#include<iostream>
#include<cmath>
using namespace std;
float de_quy_tim_xn(int n)
{
	if(n==0) return 1;
	
	if(n==1) return 1.0/2;
	return 1.0/2 * de_quy_tim_xn(n-1);
}

float khu_de_quy_tim_xn(int n) {
    return 1.0 / pow(2, n);
}
float tong_s(int n)
{
	float tong =0;
	for(int i=0;i<=n;i++)
	{
		tong += 1.0/pow(2,i);
	}
	return tong;
}
int main()
{
	int n;
	cin>>n;
	float caua=de_quy_tim_xn(n);
	cout <<caua<<endl;
	float caub=khu_de_quy_tim_xn(n);
	cout <<caub<<endl;
	float cauc=tong_s(n);
	cout <<cauc<<endl;
	return 0;
}