#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;



//doc file ở đây
void doc_file(char *s) {
    ifstream inputfile("input.txt");
    if (!inputfile.is_open()) {
        cout << "Khong mo duoc file" << endl;
        return;
    }
    char line[256];
    while (inputfile.getline(line, 256)) {
        strcat(s, line);
        strcat(s, "\n");
    }
    inputfile.close();
}

//Câu 1 đếm chuỗi trong file và tìm chuỗi dài nhất
void dem_chuoi_trong_file_va_tim_chuoi_dai_nhat(char *s, ofstream &outputfile) {
    int n = strlen(s);
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '\n') {
            dem++;
        }
    }
    outputfile << "File co: " << dem << " chuoi" << endl;

//đếm chuỗi dài nhất
    int start = 0;
    int max_length = 0;
    int max_start = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '\n') {
            int length = i - start;
            if (length > max_length) {
                max_length = length;
                max_start = start;
            }
            start = i + 1;
        }
    }
//trường hợp chuỗi cuối cùng
    int last_length = n - start;
    if (last_length > max_length) {
        max_length = last_length;
        max_start = start;
    }

    outputfile << "Chuoi dai nhat co " << max_length << " ky tu:" << endl;
    outputfile << "Chuoi dai nhat la: ";
    for (int i = max_start; i < max_start + max_length; i++) {
        outputfile << s[i];
    }
    outputfile << endl;
}
//câu 2 đếm từ và tìm từ dài nhất trong file
void dem_tu_trong_file(char *s, ofstream &outputfile) {
    int n = strlen(s);
    int dem_tu = 0;
    bool trong_tu = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ' || s[i] == '\n') {
            trong_tu = false;
        } else if (!trong_tu) {
            trong_tu = true;
            dem_tu++;
        }
    }

    outputfile << "File co: " << dem_tu << " tu" << endl;
}
//câu 3 đếm xem file có bao nhiêu nguyên âm ,phụ âm
void dem_nguyen_am_dem_phu_am(char *s, ofstream &outputfile) {
    int n = strlen(s);
    int dem_nguyen_am = 0;
    int dem_phu_am = 0;
    for (int i = 0; i < n; i++) {
        if (strchr("euoaiEOUAI", s[i])) {
            dem_nguyen_am++;
        } else if (isalpha(s[i])) {
            dem_phu_am++;
        }
    }
    outputfile << "Chuoi co: " << dem_nguyen_am << " nguyen am va: " << dem_phu_am << " phu am." << endl;
}
//câu 4.1 tách các từ bên phải của chuỗi
char* tim_tu_ben_phai(char *line) {
    int n = strlen(line);
    char *temp = new char[256];
    int j = 0;

    int i = n - 1;
    while (i >= 0 && line[i] == ' ') {
        i--;
    }

    for (; i >= 0; i--) {
        if (line[i] != ' ') {
            temp[j++] = line[i];
        } else {
            break;
        }
    }
    temp[j] = '\0';

    for (int k = 0; k < j / 2; k++) {
        char t = temp[k];
        temp[k] = temp[j - 1 - k];
        temp[j - 1 - k] = t;
    }

    char* result = new char[j + 1];
    strcpy(result, temp);
    delete[] temp;
    return result;
}
//câu 5.1 tách các từ bên trái của chuỗi
char *tim_tu_dai_nhat_ben_trai(char *line) {
    int n = strlen(line);
    char *temp = new char[256];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (line[i] != ' ') {
            temp[j] = line[i];
            j++;
        } else {
            break;
        }
    }
    temp[j] = '\0';

    char *result = new char[j + 1];
    strcpy(result, temp);
    delete[] temp;
    return result;
}
//câu 6 file có bao nhiêu chuỗi con vietnam
int dem_chuoi_con_moi_dong(char *s, const char *chuoi_con) {
    int dem = 0;
    char *line = strtok(s, "\n");
    while (line != NULL) {
        if (strstr(line, chuoi_con) != NULL) {
            dem++;
        }
        line = strtok(NULL, "\n");
    }
    return dem;
}
//câu 7 file chứa bao nhiêu từ vietnam
void demtuvietnamxuathien(char *s, ofstream &outputfile) {
    char chuoivn[] = "vietnam";
    int demtu = 0;
    int chuoivn_length = strlen(chuoivn);
    int s_length = strlen(s);
    for (int i = 0; i <= s_length - chuoivn_length; i++) {
        if (strncmp(&s[i], chuoivn, chuoivn_length) == 0) {
            demtu++;
        }
    }
    outputfile << "Chuoi co : " << demtu << " tu Viet Nam " << endl;
}

char* strlwr(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
//câu 8 chuyển ký tự đầu từ thành hoa ,các ký tự từ thành thường
void chuyen_dau_tu_thanh_hoa(char *s) {
    strlwr(s);  // Chuyển toàn bộ chuỗi sang chữ thường
    int n = strlen(s);
    bool new_word = true;  // Đánh dấu khi nào bắt đầu một từ mới

    for (int i = 0; i < n; i++) {
        if (new_word && isalpha(s[i])) {
            s[i] = toupper(s[i]);  // Chuyển ký tự đầu tiên của từ thành chữ hoa
            new_word = false;
        }
        if (s[i] == ' ' || s[i] == '\n') {
            new_word = true;  // Khi gặp khoảng trắng hoặc ký tự xuống dòng, đánh dấu bắt đầu từ mới
        }
    }
}

//câu 9 chuyển tất cả ký tự chuỗi thành chữ hoa
void chuyen_tat_ca_thanh_chu_hoa(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        s[i] = toupper(s[i]);
    }
}
//câu 10 tần số xuất hiện các ký tự
void tan_so_xuat_hien_cac_ky_tu(char *s, ofstream &outputfile) {
    int n = strlen(s);
    int d[256] = {0};

    for (int i = 0; i < n; i++) {
        if (s[i] != ' ' && s[i] != '\n') {
            d[s[i]]++;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (d[i] != 0) {
            outputfile << char(i) << " xuat hien " << d[i] << " lan" << endl;
        }
    }
}
//câu 11 tần số xuất hiện các từ
void tan_so_xuat_hien_cac_tu(char *s, ofstream &outputfile) {
    char *words[100];
    int count[100] = {0};
    int n = 0;
    char *token = strtok(s, " \n");
    while (token != NULL) {
        words[n] = new char[strlen(token) + 1];
        strcpy(words[n], token);
        n++;
        token = strtok(NULL, " \n");
    }

    for (int i = 0; i < n; i++) {
        if (count[i] == 0) {
            count[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    count[i]++;
                    count[j] = -1;
                }
            }
            outputfile << words[i] << " xuat hien : " << count[i] << " lan " << endl;
        }
        delete[] words[i];
    }
}


//ghi file ở đây
void ghi_file(char *s) {
    ofstream outputfile("output.txt");
    if (!outputfile.is_open()) {
        cout << "Khong mo duoc file" << endl;
        return;
    }
    outputfile << s;//ghi lại file (check)
    dem_chuoi_trong_file_va_tim_chuoi_dai_nhat(s, outputfile);//câu 1 
    dem_tu_trong_file(s, outputfile);//câu 2
    dem_nguyen_am_dem_phu_am(s, outputfile);//câu 3


    //câu 4.2
    char *copy = new char[strlen(s) + 1];
    strcpy(copy, s);
    char *line = strtok(copy, "\n");
    char *tu_dai_nhat_ben_phai = nullptr;
    int maxlen = 0;
    while (line != NULL) {
        char *tu_ben_phai = tim_tu_ben_phai(line);
        int len = strlen(tu_ben_phai);
        outputfile << "Mot tu ben phai cua chuoi la: " << tu_ben_phai << endl;

        if (len > maxlen) {
            maxlen = len;
            if (tu_dai_nhat_ben_phai != nullptr) {
                delete[] tu_dai_nhat_ben_phai;
            }
            tu_dai_nhat_ben_phai = new char[len + 1];
            strcpy(tu_dai_nhat_ben_phai, tu_ben_phai);
        }

        delete[] tu_ben_phai;
        line = strtok(NULL, "\n");
    }
    if (tu_dai_nhat_ben_phai != nullptr) {
        outputfile << "Tu dai nhat trong cac tu ben phai la: " << tu_dai_nhat_ben_phai << endl;
        delete[] tu_dai_nhat_ben_phai;
    } else {
        outputfile << "Khong tim thay tu nao ben phai." << endl;
    }//câu 4.2 


    //câu 5.2
    strcpy(copy, s);
    line = strtok(copy, "\n");
    char *tu_dai_nhat_ben_trai = nullptr;
    int maxlentrai = 0;
    while (line != NULL) {
        char *tu_ben_trai = tim_tu_dai_nhat_ben_trai(line);
        int lentrai = strlen(tu_ben_trai);
        outputfile << "Mot tu ben trai cua chuoi la: " << tu_ben_trai << endl;

        if (lentrai > maxlentrai) {
            maxlentrai = lentrai;
            if (tu_dai_nhat_ben_trai != nullptr) {
                delete[] tu_dai_nhat_ben_trai;
            }
            tu_dai_nhat_ben_trai = new char[lentrai + 1];
            strcpy(tu_dai_nhat_ben_trai, tu_ben_trai);
        }

        delete[] tu_ben_trai;
        line = strtok(NULL, "\n");
    }

    if (tu_dai_nhat_ben_trai != nullptr) {
        outputfile << "Tu dai nhat trong cac tu ben trai la: " << tu_dai_nhat_ben_trai << endl;
        delete[] tu_dai_nhat_ben_trai;
    } else {
        outputfile << "Khong tim thay tu nao ben trai." << endl;
    }//câu 5.2

    //câu 6
    strcpy(copy, s);
    int solanxuathienchuoicon = dem_chuoi_con_moi_dong(copy, "vietnam");
    outputfile << "So lan xuat hien chuoi con 'vietnam' (moi dong chi tinh mot lan) la: " << solanxuathienchuoicon << endl;

    //câu 7
    demtuvietnamxuathien(s, outputfile);
    
    //câu 8
    strcpy(copy, s);
    chuyen_dau_tu_thanh_hoa(copy);
    outputfile << copy << endl;

    //câu 9
    chuyen_tat_ca_thanh_chu_hoa(copy);
    outputfile << copy << endl;
    
    //câu 10
    strcpy(copy, s);
    tan_so_xuat_hien_cac_ky_tu(copy, outputfile);

    //câu 11
    strcpy(copy, s);
    tan_so_xuat_hien_cac_tu(copy, outputfile);


    delete[] copy;
    outputfile.close();
}

int main() {
    char s[4096] = {0};
    doc_file(s);
    ghi_file(s);
    return 0;
}
