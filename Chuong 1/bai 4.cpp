/*Bai 4 
a)Cho mảng một chiều gồm n số nguyên a0,a1,....an-1 .Viết hàm đệ quy tìm giá trị lớn nhất của mảng.
b)Cho mảng một chiều gồm n số nguyên a0,a1,....an-1.Viết hàm đệ quy tính tổng các phần tử của mảng.
c)Cho mảng một chiều gồm n số nguyên a0,a1.....an-1.Viết hàm đệ quy đếm xem mảng có bao nhiêu số nguyên tố
*/
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n)
{
	if(n<2) return false;
	
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	 } 
	 return true;
}
int de_quy_gia_tri_max(int a[100],int n)
{
	if(n==0)
	{
		return a[n];
	}
	int max_lonnhat=a[n-1];
	return max(max_lonnhat,de_quy_gia_tri_max(a,n-1));
	
}
int de_quy_gia_tri_max_2(int a[], int n) {
    if (n == 1) {
        return a[0];
    }
    int max_lonnhat = de_quy_gia_tri_max(a, n - 1);
    return max(a[n - 1], max_lonnhat);
}
//Cho mảng một chiều gồm n số nguyên a0,a1,....an-1.Viết hàm đệ quy tính tổng các phần tử của mảng.
int tong_de_quy(int a[],int n)
{
	if(n==1)
	{
		return a[0];
	}
	return a[n-1]+tong_de_quy(a,n-1);
}
//c)Cho mảng một chiều gồm n số nguyên a0,a1.....an-1.Viết hàm đệ quy đếm xem mảng có bao nhiêu số nguyên tố
int dem_so_nguyen_to_mang(int a[],int n)
{
	if(n==0)
	{
		return 0;
	}
	int dem=0;
	if(isPrime(a[n-1]))
	{
		 dem = dem +1;
	}
	
	return dem + dem_so_nguyen_to_mang(a,n-1);
}
int main()
{
	int n;
	cout << "Nhap so phan tu mang : ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
}
for(int i=0;i<n;i++)
{
	cout<<a[i]<<" ";
}
	cout <<endl;
	int dequymax=de_quy_gia_tri_max(a,n);
	cout <<dequymax<<endl;
	
    int dequymax2=de_quy_gia_tri_max_2(a,n);
    cout <<dequymax2<<endl;
    
    
    int tong=tong_de_quy(a,n);
    cout <<tong <<endl;
    
    int demsnt=dem_so_nguyen_to_mang(a,n);
    cout <<demsnt<<endl;
	return 0;
}