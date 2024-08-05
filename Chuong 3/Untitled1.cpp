#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void cau1_dem_mang_ki_tu_hoa_thuong_khac_khoang_trang(char *s) {
    int n = strlen(s);
    int dem_hoa = 0;
    int dem_khac_khoang_trang = 0;
    int dem_thuong = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            dem_hoa++;
        }
        if (s[i] != ' ') {
            dem_khac_khoang_trang++;
        }
        if (islower(s[i])) {
            dem_thuong++;
        }
    }
    cout << "Chuoi co: " << dem_hoa << " ky tu hoa, " << dem_khac_khoang_trang 
         << " ky tu khac khoang trang, " << dem_thuong << " ky tu thuong" << endl;
}

void cau2_tim_ma_ascii_moi_ky_tu(char *s) {
    int n = strlen(s);
    cout << "Bang ma ASCII moi ky tu la: " << endl;
    for (int i = 0; i < n; i++) {
        cout << int(s[i]) << ' ';
    }
    cout << endl;
}

void cau3_chuyen_ki_tu_dau_hoa_con_lai_thuong(char *s) {
    strlwr(s);
    int n = strlen(s);
    s[0] = toupper(s[0]);
    for (int i = 1; i < n; i++) {
        if (s[i] == ' ' && s[i+1] != ' ' && s[i+1] != '\0') {
            s[i+1] = toupper(s[i+1]);
        }
    }
    cout << s << endl;
}

void cau4_dem_so_luong_tu_chuoi(char *s) {
    int n = strlen(s);
    int dem_tu = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            dem_tu++;
        }
    }
    cout << "Chuoi s co: " << dem_tu + 1 << " tu" << endl;
}

void cau5_dem_so_ky_tu_moi_tu(char *s) {
    int n = strlen(s);
    int sokytumoitu = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
        //	cout <<s[i];
            sokytumoitu++;
        } else {
            if (sokytumoitu > 0) {
                cout << sokytumoitu << " ";
            }
            sokytumoitu = 0;
        }
    }
    if (sokytumoitu > 0) {
        cout << sokytumoitu << endl;
    }
}

void cau6_tu_dai_nhat_so_ky_tu(char *s) {
    int n = strlen(s);
    int demkytu = 0;
    int max_kytu = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            demkytu++;
        } else {
            if (demkytu > max_kytu) {
                max_kytu = demkytu;
            }
            demkytu = 0;
        }
    }
    if (demkytu > max_kytu) {
        max_kytu = demkytu;
    }
    cout << "Tu dai nhat co: " << max_kytu << endl;
}

void cau7_sap_xep_ky_tu_theo_chieu_tang_ky_tu_khoang_trang_giu_nguyen_vi_tri(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (s[i] > s[j] && s[i] != ' ' && s[j] != ' ') {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    cout << "Chuoi sau khi sap xep chieu tang la: " << s << endl;
}

void cau8_dao_nguoc_cac_tu_trong_chuoi(char *s) {
    int n = strlen(s);
    for (int j = n-1; j >= 0; j--) {
        if (s[j-1] == ' ' || j == 0) {
            for (int i = j; i < n; i++) {
                cout << s[i];
                if (s[i+1] == ' ' || s[i+1] == '\0') {
                    break;
                }
            }
            cout << " ";
        }
    }
    cout << endl;
}

void cau9_xoa_khoang_trang_dau_giua_cuoi_du_thua(char *s) {
    int n = strlen(s);
    int i = 0;
    while (s[i] == ' ') {
        i++;
    }
    if (i > 0) {
        strcpy(s, s + i);
    }
    
    int j = 0;
    int spacecount = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            s[j++] = s[i];
            spacecount = 0;
        } else {
            spacecount++;
            if (spacecount == 1) {
                s[j++] = s[i];
            }
        }
    }
    s[j] = '\0';
    while (n > 0 && s[n-1] == ' ') {
        s[n-1] = '\0';
        n--;
    }
    cout << "Chuoi sau khi xoa khoang trang du thua la: " << s << endl;
}

void cau10_tach_1_tu_ben_phai_s(char *s) {
    int n = strlen(s);
    char *temp = new char[255];
    int j = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] != ' ') {
            temp[j++] = s[i];
        } else {
            break;
        }
    }
    temp[j] = '\0';
    cout << "Mot tu ben phai chuoi s la: ";
    for (int k = j-1; k >= 0; k--) {
        cout << temp[k];
    }
    cout << endl;
    delete[] temp;
}

void cau11_tach_1_tu_ben_trai_s(char *s) {
    int n = strlen(s);
    char *temp = new char[255];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ' && s[i] != '\0') {
            temp[j++] = s[i];
        } else {
            break;
        }
    }
    temp[j] = '\0';
    cout << "Mot tu ben trai chuoi s la: " << temp << endl;
    delete[] temp;
}

void cau12_tim_mot_tu_dai_nhat(char *s) {
    int n = strlen(s);
    int start = 0;
    int demkytu = 0;
    int max_kytu = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            demkytu++;
        } else {  
            if (demkytu > max_kytu) {
                max_kytu = demkytu;
                start = i - max_kytu;
            }
            demkytu = 0;
        }
    }
    if (demkytu > max_kytu) {
        max_kytu = demkytu;
        start = n - max_kytu;
    }
    char *temp = new char[max_kytu + 1];
    strncpy(temp, &s[start], max_kytu);
    temp[max_kytu] = '\0';
    cout << "Tu dai nhat chuoi la: " << temp << endl;
    delete[] temp;
}

void cau13_xoa_k_kytu_batdautuvitrip_chuoi(char *s, int k, int vitri) {
    int n = strlen(s);
    if (vitri < 0 || vitri >= n) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    for (int i = vitri + k; i <= n; i++) {
        s[i - k] = s[i];
    }
    s[n - k] = '\0';
    cout << "Chuoi sau khi xoa k ky tu la: " << s << endl;
}

int cau14_kiem_tra_chuoi_x_co_thuoc_chuoi_s_khong(char *s, char *x) {
    int len_s = strlen(s);
    int len_x = strlen(x);
    for (int i = 0; i <= len_s - len_x; i++) {
        if (strncmp(s + i, x, len_x) == 0) {
            return i;
        }
    }
    return -1;
}

void cau15_dem_xem_chuoi_y_xuat_hien_bao_nhieu_lan(char *s, char *y) {
    int dem = 0;
    char *p = s;
    while ((p = strstr(p, y)) != NULL) {
        dem++;
        p++;
    }
    cout << "Chuoi y xuat hien: " << dem << " lan trong chuoi s." << endl;
}

void cau16_chen_s2_vao_vi_tri_p_cua_s1(char *s1, char *s2, int p) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *s = new char[len1 + len2 + 1];
    
    // Sao chép phần đầu của s1 vào s
    for (int i = 0; i < p; i++) {
        s[i] = s1[i];
    }
    
    // Chèn chuỗi s2 vào vị trí p của s1
    for (int i = 0; i < len2; i++) {
        s[p + i] = s2[i];
    }
    
    // Sao chép phần còn lại của s1 vào s sau khi đã chèn s2
    for (int i = p; i < len1; i++) {
        s[i + len2] = s1[i];
    }
    
    s[len1 + len2] = '\0';
    cout << "Chuoi sau khi chen: " << s << endl;
    delete[] s;
}


void tan_so_xuat_hien_cac_ky_tu(char *s)
{
    int n=strlen(s);
    int d[256]={0};
    for(int i=0;i<n;i++)
    {
        d[(unsigned char)s[i]]++;
    }
    for(int i=0;i<256;i++)
    {
        if(d[i]!=0)
        {
            cout<<(char)i<<" xuat hien : "<<d[i]<<" lan "<<endl;
        }
    }
}

void cau18_tan_so_xuat_hien_cac_tu(char *s) {
    cout << "So lan xuat hien cua moi tu : " << endl;
    char** words = new char*[20]; // Mảng động để lưu các từ
    int* count = new int[20]; // Mảng động để đếm số lần xuất hiện của các từ
    int n = 0; // Chỉ số của từ hiện tại trong mảng words

    for (int i = 0; i < 20; i++) {
        count[i] = 0; // Khởi tạo mảng count với giá trị 0
        words[i] = new char[256]; // Giả sử mỗi từ tối đa 100 ký tự
    }

    // Tách từ ra khỏi chuỗi s dùng strtok
    char *token = strtok(s, " ");
    while (token != NULL) {
        strcpy(words[n], token);
        n++;
        token = strtok(NULL, " ");
    }

    // Đếm số lần xuất hiện của từng từ
    for (int i = 0; i < n; i++) {
        if (count[i] == 0) {
            count[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    count[i]++;
                    count[j] = -1; // Đánh dấu từ đã đếm
                }
            }
            cout << words[i] << ": " << count[i] << endl;
        }
    }

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < n; i++) {
        delete[] words[i];
    }
    delete[] words;
    delete[] count;
}

int main() {
    char *s = new char[256];
    char *x = new char[256];
    char *y = new char[256];

    cout << "Nhap vao chuoi s: ";
    cin.getline(s, 256);

    cau9_xoa_khoang_trang_dau_giua_cuoi_du_thua(s);
    cau1_dem_mang_ki_tu_hoa_thuong_khac_khoang_trang(s);
    cau2_tim_ma_ascii_moi_ky_tu(s);
    cau3_chuyen_ki_tu_dau_hoa_con_lai_thuong(s);
    cau4_dem_so_luong_tu_chuoi(s);
    cau5_dem_so_ky_tu_moi_tu(s);
    cau6_tu_dai_nhat_so_ky_tu(s);
//    cau7_sap_xep_ky_tu_theo_chieu_tang_ky_tu_khoang_trang_giu_nguyen_vi_tri(s);
//    cau8_dao_nguoc_cac_tu_trong_chuoi(s);
    cau10_tach_1_tu_ben_phai_s(s);
    cau11_tach_1_tu_ben_trai_s(s);
    cau12_tim_mot_tu_dai_nhat(s);
    cau13_xoa_k_kytu_batdautuvitrip_chuoi(s, 2, 2);

    cout << "Nhap chuoi x: ";
    cin.getline(x, 256);
    int cau14_vitri = cau14_kiem_tra_chuoi_x_co_thuoc_chuoi_s_khong(s, x);
    cout << "Vi tri dau tien cua chuoi x trong s la: " << cau14_vitri << endl;

    cout << "Nhap vao chuoi y: ";
    cin.getline(y, 256);
    cau15_dem_xem_chuoi_y_xuat_hien_bao_nhieu_lan(s, y);
    char s1[256], s2[256];
    int p;

    cout << "Nhap vao chuoi s1: ";
    cin.getline(s1, 256);

    cout << "Nhap vao chuoi s2: ";
    cin.getline(s2, 256);

    cout << "Nhap vao vi tri p: ";
    cin >> p;
    cau16_chen_s2_vao_vi_tri_p_cua_s1(s1, s2, p);
    cau17_tan_so_xuat_hien_cac_ky_tu(s);
    cau18_tan_so_xuat_hien_cac_tu(s);
    delete[] s;
    delete[] x;
    delete[] y;

    return 0;
}


