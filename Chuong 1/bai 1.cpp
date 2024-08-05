/*Bài 1
a) viết hàm đệ quy tính tổng các chữ số của một số nguyên dương
b) viết hàm đệ quy tìm ước sô chung lớn nhất của 2 số nguyên dương 
*/

#include<iostream>
#include<cmath>
using namespace std;

int tong_chu_so_1_so(int n)
{
	if(n/10==0)
	{
		return n ;
	}
	return (n%10)+ tong_chu_so_1_so(n/10);
}
int tim_uoc_chung_lon_nhat(int a, int b) {
   if(b==0) return a;
   return tim_uoc_chung_lon_nhat(b,a%b);
}

int main()
{
	int n;
	cout << "Nhap n : ";
	cin>>n;
	int tongchuso=tong_chu_so_1_so(n);
	cout << tongchuso <<endl;
	
	int c = tim_uoc_chung_lon_nhat(4,5);
	cout <<c<<endl;
	return 0;
}