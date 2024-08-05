#include<iostream>
#include<fstream>
#include<cmath>
#include<limits.h>
using namespace std;

void doc_file(int *&a,int &n)
{
    ifstream inputfile("input.txt");
    if(!inputfile.is_open())
    {
        cout<<"khong mo duoc file ";
        return;
    }
    inputfile >>n;
    
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        inputfile >> a[i];
    }
    inputfile.close();
}
void tong_cac_phan_tu(int *a,int n,ofstream &outputfile)
{
    int tong=0;
    for(int i=0;i<n;i++)
    {
        tong+=a[i];
    }
    outputfile <<"Tong cac phan tu trong file la : "<< tong <<endl;
}
int tong_chu_so_1_so(int n)
{
    int tong=0;
    while (n>0)
    {
        int r=n%10;
        tong +=r;
        n=n/10;
    }
    
    return tong;
}

void tong_chu_so_tat_ca_cac_so(int *a,int n,ofstream &outputfile)
{
    int tong=0;
    for(int i=0;i<n;i++)
    {
        tong +=tong_chu_so_1_so(a[i]);
    }
    outputfile <<"Tong chu so tat ca cac so la : "<< tong <<endl;
}

bool isPrime(int n)
{
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

bool isPalindrome(int n)
{
    int sobandau=n;
    int sodaonguoc=0;
    while(n>0){
        int r=n%10;
        sodaonguoc=sodaonguoc*10+r;
        n=n/10;
    }
    
    return(sobandau==sodaonguoc);
}
void dem_so_luong_nguyen_to_dem_vua_nguyen_to_vua_doi_xung(int *a,int n,ofstream &outputfile)
{
    int dem_nt=0;
    int dem_ntvadx =0;
    for(int i=0;i<n;i++)
    {
        if(isPrime(a[i]))
        {
            dem_nt++;
        }
        else if(isPrime(a[i]) && isPalindrome(a[i]))
        {
            dem_ntvadx++;
        }
    }
    outputfile <<"File co : "<< dem_nt <<" so nguyen to va : "<< dem_ntvadx <<" so vua nguyen to vua doi xung "<<endl;
}

void tim_gia_tri_lon_nhat_va_so_nguyen_to_lon_nhat_so_am_lon_nhat(int *a,int n,ofstream &outputfile)
{
    int max_day =INT_MIN;
    int max_ngto=INT_MIN;
    int max_am=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max_day)
        {
            max_day=a[i];
        }
        if(isPrime(a[i]) && a[i]>max_ngto)
        {
            max_ngto=a[i];
        }
        if(a[i]<0 && a[i]>max_am)
        {
            max_am=a[i];   
        }
    }
    if(max_am==INT_MIN)
    {
        outputfile <<"File khong co so am nao "<<endl;
    }
    outputfile <<"Gia tri lon nhat file la : "<< max_day << " va gia tri nguyen to lon nhat file la : "<< max_ngto << " va gia tri am lon nhat la : " << max_am <<endl;
}
bool isPrimePalindrome(int n) {
    if (n <= 2) return false;
    if (!isPrime(n)) return false;

    int truoc = n - 1;
    int sau = n + 1;

    // Tìm số nguyên tố liền trước
    while (truoc > 1 && !isPrime(truoc)) {
        truoc--;
    }

    // Tìm số nguyên tố liền sau
    while (!isPrime(sau)) {
        sau++;
    }

    // Kiểm tra nếu n là trung bình cộng của hai số nguyên tố liền trước và liền sau
    if ((truoc + sau) / 2 == n) {
        return true;
    }

    return false;
}

void dem_so_nguyen_to_doi_xung(int *a,int n,ofstream &outputfile)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(isPrimePalindrome(a[i])) 
        {
            outputfile << a[i]<<" ";
            dem++;
        }
    }
    outputfile <<"File co : "<<dem << " so nguyen to doi xung "<<endl;
}
void sap_xep_theo_thu_tu_tang_dan(int *&a,int &n,ofstream &outputfile)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        outputfile << a[i]<<" ";
    }
    outputfile <<endl;
}
void nguyen_to_dau_mang_thuong_cuoi_mang(int *&a, int &n, ofstream &outputfile) {
    int *b = new int[n];
    int j = 0;
    
    // Đưa các số nguyên tố vào đầu mảng
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            b[j++] = a[i];
        }
    }
    
    // Đưa các số không nguyên tố vào phần còn lại của mảng
    for (int i = 0; i < n; i++) {
        if (!isPrime(a[i])) {
            b[j++] = a[i];
        }
    }
    
    // Ghi kết quả ra file
    for (int i = 0; i < n; i++) {
        outputfile << b[i] << " ";
    }
    
    delete[] b; // Giải phóng bộ nhớ tạm thời
}
void sap_xep_chan_dau_tang_le_cuoi_giam(int *&a, int &n, ofstream &outputfile) {
    // Đếm số lượng số chẵn và lẻ
    int count_chan = 0, count_le = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            count_chan++;
        } else {
            count_le++;
        }
    }

    // Tạo mảng tạm thời cho số chẵn và số lẻ
    int *chan = new int[count_chan];
    int *le = new int[count_le];
    
    // Phân tách mảng ban đầu vào mảng chẵn và lẻ
    int index_chan = 0, index_le = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            chan[index_chan++] = a[i];
        } else {
            le[index_le++] = a[i];
        }
    }
    
    // Sắp xếp mảng chẵn tăng dần
    for (int i = 0; i < count_chan - 1; ++i) {
        for (int j = i + 1; j < count_chan; ++j) {
            if (chan[i] > chan[j]) {
                swap(chan[i], chan[j]);
            }
        }
    }
    
    // Sắp xếp mảng lẻ giảm dần
    for (int i = 0; i < count_le - 1; ++i) {
        for (int j = i + 1; j < count_le; ++j) {
            if (le[i] < le[j]) {
                swap(le[i], le[j]);
            }
        }
    }
    
    // Ghép hai mảng lại thành mảng kết quả
    int index = 0;
    for (int i = 0; i < count_chan; ++i) {
        a[index++] = chan[i];
    }
    for (int i = 0; i < count_le; ++i) {
        a[index++] = le[i];
    }
    
    // Ghi kết quả ra file
    for (int i = 0; i < n; ++i) {
        outputfile << a[i] << " ";
    }
    
    // Giải phóng bộ nhớ tạm thời
    delete[] chan;
    delete[] le;
}

void dem_so_cap_so_co_tong_bang_m(int *a,int n,int m,ofstream &outputfile)
{
    int dem_cap=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==m)
            {
                dem_cap++;
            }
        }
    }
    outputfile <<"\nCo : "<< dem_cap <<" cap so thoa man tong bang m "<<endl;
}
/*
void dem_so_cap_so_co_tong_bang_m(int *a, int n, int m, ofstream &outputfile) {
    // Sắp xếp mảng
    sort(a, a + n);
    
    // Dùng hai con trỏ để duyệt qua mảng từ hai đầu của nó
    int left = 0, right = n - 1;
    int dem_cap = 0;
    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == m) {
            // Nếu tổng bằng m, tăng số cặp lên và di chuyển cả hai con trỏ
            dem_cap++;
            left++;
            right--;
        } else if (sum < m) {
            // Nếu tổng nhỏ hơn m, di chuyển con trỏ bên trái sang phải
            left++;
        } else {
            // Nếu tổng lớn hơn m, di chuyển con trỏ bên phải sang trái
            right--;
        }
    }
    
    outputfile << "\nCo : " << dem_cap << " cap so thoa man tong bang m" << endl;
}*/

void tan_so_xuat_hien_cac_so(int *&a, int &n, ofstream &outputfile) {
    // Tìm giá trị lớn nhất và nhỏ nhất trong mảng a
    int max_val = a[0];
    int min_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }

    // Tạo mảng temp với kích thước phù hợp
    int temp_size = max_val - min_val + 1;
    int *temp = new int[temp_size]{0};

    // Đếm tần suất xuất hiện của các phần tử trong mảng
    for (int i = 0; i < n; i++) {
        temp[a[i] - min_val]++;
    }

    // In tần suất xuất hiện của các số
    for (int i = 0; i < temp_size; i++) {
        if (temp[i] > 0) {
            outputfile << "Gia tri " << i + min_val << " xuat hien " << temp[i] << " lan!\n";
        }
    }

    // Giải phóng bộ nhớ
    delete[] temp;
}
bool tinh_chat_g(int a, int b, int k) {
    return (2 * k == (a + b));
}

void dem_tinh_chat_g_thoa_man(int *a, int n, int k, ofstream &outputfile) {
    int dem = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tinh_chat_g(a[i], a[j], k)) {
                dem++;
            }
        }
    }
    outputfile << "File co: " << dem << " cap so thoa man tinh chat g.\n";
}

void ghi_file(int *a,int n)
{
    ofstream outputfile("output.txt");
    if(!outputfile.is_open())
    {
        cout<<"khong ghi duoc file ";
        return;
    }
    outputfile << n <<endl;
    for(int i=0;i<n;i++)
    {
        outputfile << a[i]<<" ";
    }
    outputfile <<endl;
    tong_cac_phan_tu(a,n,outputfile);
     tong_chu_so_tat_ca_cac_so(a,n,outputfile);
     dem_so_luong_nguyen_to_dem_vua_nguyen_to_vua_doi_xung(a,n,outputfile);
     tim_gia_tri_lon_nhat_va_so_nguyen_to_lon_nhat_so_am_lon_nhat(a,n,outputfile);
     dem_so_nguyen_to_doi_xung(a,n,outputfile);
     sap_xep_theo_thu_tu_tang_dan(a,n,outputfile);
     nguyen_to_dau_mang_thuong_cuoi_mang(a,n,outputfile);
     outputfile<<"\nMang sau khi sap xep moi la : "<<endl;
     sap_xep_chan_dau_tang_le_cuoi_giam(a,n,outputfile);
     dem_so_cap_so_co_tong_bang_m(a,n,5,outputfile);
     tan_so_xuat_hien_cac_so(a,n,outputfile);
     dem_tinh_chat_g_thoa_man(a,n,34,outputfile);
     
    outputfile.close();
}
int main()
{
    int *a;
    int n;
    doc_file(a,n);
    ghi_file(a,n);
}