#include <iostream>
#include <iomanip>
#include <cstring>
#include "../Header_File/docgia.h"
using namespace std;

int maDocGia[MAX_DOC_GIA];
char hoTen[MAX_DOC_GIA][50];
char ngaySinh[MAX_DOC_GIA][20];
char gioiTinh[MAX_DOC_GIA][10];
char cmnd[MAX_DOC_GIA][20];
char diaChi[MAX_DOC_GIA][100]; 
char email[MAX_DOC_GIA][50];
char ngayLapThe[MAX_DOC_GIA][20];
char ngayHetHan[MAX_DOC_GIA][20];
void khoiTaoDocGia() {
    maDocGia[0] = 101;
    strcpy(hoTen[0], "Nguyen Van Nam");
    strcpy(cmnd[0], "123456789");
    strcpy(ngaySinh[0], "01/01/1990");
    strcpy(gioiTinh[0], "Nam");
    strcpy(email[0], "nam0101@gmail.com");
    strcpy(diaChi[0], "Ha Noi");
    strcpy(ngayLapThe[0], "01/01/2022");
    strcpy(ngayHetHan[0], "01/01/2026");

    maDocGia[1] = 102;
    strcpy(hoTen[1], "Tran Thi Be");
    strcpy(cmnd[1], "987654321");
    strcpy(ngaySinh[1], "15/05/1995");
    strcpy(gioiTinh[1], "Nu");
    strcpy(email[1], "be1505@gmail.com");
    strcpy(diaChi[1], "TP Ho Chi Minh");
    strcpy(ngayLapThe[1], "15/02/2023");
    strcpy(ngayHetHan[1], "15/02/2027");

    maDocGia[2] = 103;
    strcpy(hoTen[2], "Le Van Cuong");
    strcpy(cmnd[2], "555555555");
    strcpy(ngaySinh[2], "20/12/2000");
    strcpy(gioiTinh[2], "Nam");
    strcpy(email[2], "cuong@gmail.com");
    strcpy(diaChi[2], "Da Nang");
    strcpy(ngayLapThe[2], "10/03/2024");
    strcpy(ngayHetHan[2], "10/03/2028");

    maDocGia[3] = 104;
    strcpy(hoTen[3], "Pham Thi Hoa");
    strcpy(cmnd[3], "444444444");
    strcpy(ngaySinh[3], "30/06/1992");
    strcpy(gioiTinh[3], "Nu");
    strcpy(email[3], "hoa3006@gmail.com");
    strcpy(diaChi[3], "Hai Phong");
    strcpy(ngayLapThe[3], "20/04/2021");
    strcpy(ngayHetHan[3], "20/04/2025");

    maDocGia[4] = 105;
    strcpy(hoTen[4], "Nguyen Van Tuyen");
    strcpy(cmnd[4], "111111111");
    strcpy(ngaySinh[4], "10/10/1988");
    strcpy(gioiTinh[4], "Nam"); 
    strcpy(email[4], "tuyen1010@gmail.com");
    strcpy(diaChi[4], "Can Tho");
    strcpy(ngayLapThe[4], "01/01/2020");
    strcpy(ngayHetHan[4], "01/01/2024");

    maDocGia[5] = 106;
    strcpy(hoTen[5], "Nguyen Thi Mai");
    strcpy(cmnd[5], "222222222");
    strcpy(ngaySinh[5], "25/12/1998");
    strcpy(gioiTinh[5], "Nu");
    strcpy(email[5], "mai2512@gmail.com");
    strcpy(diaChi[5], "Nha Trang");
    strcpy(ngayLapThe[5], "15/05/2023");
    strcpy(ngayHetHan[5], "15/05/2027");
    soLuongDocGia = 6;
}


void xemDanhSachDocGia() {
    if (soLuongDocGia == 0) {
        cout << "Chua co doc gia nao trong thu vien!" << endl;
        return;
    }    

    cout << "====================================================== DANH SACH DOC GIA ======================================================" << endl;
    cout << left << setw(12) << "Ma Doc Gia"
         << setw(22) << "Ho Ten"
         << setw(15) << "CMND"
         << setw(12) << "Ngay Sinh"
         << setw(12) << "Gioi Tinh"
         << setw(20) << "Email"
         << setw(15) << "Dia Chi"
         << setw(15) << "Ngay Lap The"
         << setw(15) << "Ngay Het Han"
         << endl;

    for (int i = 0; i < soLuongDocGia; i++) {
        cout << left << setw(12) << maDocGia[i]
             << setw(22) << hoTen[i]
             << setw(15) << cmnd[i]
             << setw(12) << ngaySinh[i]
             << setw(12) << gioiTinh[i]
             << setw(20) << email[i]
             << setw(15) << diaChi[i]
             << setw(15) << ngayLapThe[i]
             << setw(15) << ngayHetHan[i]
             << endl;
    }
}
// Hàm thêm độc giả 
void themDocGia(){
    if (soLuongDocGia > MAX_DOC_GIA)
    {
        cout << "Khong the them doc gia, danh sach da day!!!" << endl;
    }
    int index = soLuongDocGia; // Lấy vị trí trống tiếp theo
    cout << "Nhap ma doc gia: ";
    cin >> maDocGia[index];
    cin.ignore(); // Xóa bộ đệm
    cout << "Nhap ho ten doc gia: ";
    cin.getline(hoTen[index], 50);
    cout << "Nhap CMND: ";
    cin.getline(cmnd[index], 20);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin.getline(ngaySinh[index], 20);
    cout << "Nhap gioi tinh: ";
    cin.getline(gioiTinh[index], 10);
    cout << "Nhap email: ";
    cin.getline(email[index], 50);
    cout << "Nhap dia chi: ";
    cin.getline(diaChi[index], 100);
    cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    cin.getline(ngayLapThe[index], 20);


    int day, month, year;
    if (sscanf(ngayLapThe[index], "%d/%d/%d", &day, &month, &year) != 3) {
        cout << "Dinh dang ngay lap the khong hop le! Su dung dd/mm/yyyy." << endl;
        return;
    }

    // Thêm 48 tháng (4 năm)
    month += 48;
    while (month > 12) {  // Sửa thành month > 12 (không phải year > 12)
        month -= 12;
        year++;
    }

    // Kiểm tra ngày/tháng hợp lệ
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
        cout << "Ngay lap the khong hop le!" << endl;
        return;
    }

    // Format lại ngày hết hạn
    snprintf(ngayHetHan[index], sizeof(ngayHetHan[index]), "%02d/%02d/%d", day, month, year);
    cout << "Ngay het han: " << ngayHetHan[index] << endl;
    soLuongDocGia++; // Tăng số lượng độc giả
    cout << "Them doc gia thanh cong!" << endl;
}
// Hàm chỉnh sửa độc giả
void chinhSuaDocGia(){
    int ma;
    cout << "Nhap ma doc gia can chinh sua: ";
    cin >> ma;
    int index = -1;
    while (true) {
        cout << "Nhap ma doc gia can chinh sua: ";
        cin >> ma;

        // Tìm độc giả theo mã
        index = -1;
        for (int i = 0; i < soLuongDocGia; i++) {
            if (maDocGia[i] == ma) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            break;  // Nếu tìm thấy, thoát vòng lặp
        }

        cout << " Khong tim thay doc gia co ma " << ma << ". Vui long nhap lai!\n";
    }
    // Hiển thị thông tin cũ
    cout << "\n--- Thong tin hien tai cua doc gia ---\n";
    cout << "1. Ho Ten: " << hoTen[index] << endl;
    cout << "2. CMND: " << cmnd[index] << endl;
    cout << "3. Ngay Sinh: " << ngaySinh[index] << endl;
    cout << "4. Gioi Tinh: " << gioiTinh[index] << endl;
    cout << "5. Email: " << email[index] << endl;
    cout << "6. Dia Chi: " << diaChi[index] << endl;
    cout << "7. Ngay Lap The: " << ngayLapThe[index] << endl;
    cout << "8. Ngay Het Han: " << ngayHetHan[index] << endl;
    
    // Cập nhật thông tin
    cout << "Cap nhat thong tin moi (bo trong neu khong muon thay doi)" << endl;
    cout << "Ho va ten" << endl;
    string temp;
    getline(cin, temp);
    if (!temp.empty()) strcpy(hoTen[index], temp.c_str());

    cout << "CMND: ";
    getline(cin, temp);
    if (!temp.empty()) strcpy(cmnd[index], temp.c_str());

    cout << "Ngay Sinh (dd/mm/yyyy): ";
    getline(cin, temp);
    if (!temp.empty()) strcpy(ngaySinh[index], temp.c_str());

    cout << "Gioi Tinh: ";
    getline(cin, temp);
    if (!temp.empty()) strcpy(gioiTinh[index], temp.c_str());

    cout << "Email: ";
    getline(cin, temp);
    if (!temp.empty()) strcpy(email[index], temp.c_str());

    cout << "Dia Chi: ";
    getline(cin, temp);
    if (!temp.empty()) strcpy(diaChi[index], temp.c_str());

    cout << "Ngay Lap The (dd/mm/yyyy): ";
    getline(cin, temp);
    if (!temp.empty()) {
        strcpy(ngayLapThe[index], temp.c_str());

        // Tính ngày hết hạn (48 tháng sau ngày lập thẻ)
        int day, month, year;
        sscanf(ngayLapThe[index], "%d/%d/%d", &day, &month, &year);
        month += 48;
        while (month > 12) {
            month -= 12;
            year++;
        }
        snprintf(ngayHetHan[index], sizeof(ngayHetHan[index]), "%02d/%02d/%d", day, month, year);
    }

    cout << "\nChinh sua thanh cong!\n";
    
}
// Hàm xoá độc giả
void xoaDocGia(){
    int maCanXoa;
    int index = -1;
    while (true)
    {
        cout << "Nhap ma can xoa" << endl;
        cin >> maCanXoa;
        index = -1;
        for (int i = 0; i < soLuongDocGia; i++)
        {
            if (maDocGia[i] == maCanXoa)
            {
                index = i;
                break;
            }
            
        }
        if (index == -1)
        {
            cout << "Khong tim thay doc gia co ma " << maCanXoa << ". Vui long nhap lai!\n";
        }
        else
        {
            break;
        }
        
    }
    
    // Hiển thị thông tin độc giả trước khi xóa
    cout << "\n--- Thong tin doc gia can xoa ---\n";
    cout << "Ho Ten: " << hoTen[index] << endl;
    cout << "CMND: " << cmnd[index] << endl;
    cout << "Email: " << email[index] << endl;
    cout << "Ngay Lap The: " << ngayLapThe[index] << endl;
    cout << "Ngay Het Han: " << ngayHetHan[index] << endl;
    // Xác nhận xóa
    char xacNhan;
    cout << "\nBan co chac chan muon xoa doc gia nay? (Y/N): ";
    cin >> xacNhan;

    if (xacNhan != 'Y') {
        cout << "Huy xoa doc gia!\n";
        return;
    }
    // Dời các phần tử về trước để lấp khoảng trống
    for (int i = index; i < soLuongDocGia - 1; i++) {
        maDocGia[i] = maDocGia[i + 1];
        strcpy(hoTen[i], hoTen[i + 1]);
        strcpy(cmnd[i], cmnd[i + 1]);
        strcpy(ngaySinh[i], ngaySinh[i + 1]);
        strcpy(gioiTinh[i], gioiTinh[i + 1]);
        strcpy(email[i], email[i + 1]);
        strcpy(diaChi[i], diaChi[i + 1]);
        strcpy(ngayLapThe[i], ngayLapThe[i + 1]);
        strcpy(ngayHetHan[i], ngayHetHan[i + 1]);
    }

    // Giảm số lượng độc giả
    soLuongDocGia--;

    cout << "Xoa doc gia thanh cong!\n";
    // In danh sách độc giả sau khi xoá
    for (int i = 0; i < soLuongDocGia; i++) {
        if (maDocGia[i] != 0) {  // Chỉ in nếu mã độc giả hợp lệ
            cout << "Ma: " << maDocGia[i] << " - Ho Ten: " << hoTen[i] << " - CMND: " << cmnd[i] << " - Ngay Sinh: " << ngaySinh[i] << " - Gioi Tinh: " << gioiTinh[i] << endl;
        }
    }
}
// Hàm tìm độc giả theo cmnd
void timDocGiaTheoCMND(){
    bool found = false;
    char cmndCanTim[20];
    cout << "Nhap cmnd can tim" << endl;
    cin >> cmndCanTim; 
    for (int i = 0; i < soLuongDocGia; i++)
    {
        if (strcmp(cmnd[i], cmndCanTim) == 0)
        {
            // Nếu tìm thấy, in thông tin độc giả
            cout << "Ma: " << maDocGia[i] << " - Ho Ten: " << hoTen[i] << " - CMND: " << cmnd[i] << " - Ngay Sinh: " << ngaySinh[i] << " - Gioi Tinh: " << gioiTinh[i] << endl;
            found = true;
            break;
        }
        
    }
    // Nếu không tìm thấy, thông báo cho người dùng
    if (!found) {
        cout << "Khong tim thay doc gia voi CMND: " << cmndCanTim << endl;
    }
    
}
// Hàm tìm độc giả theo tên
void timDocGiaTheoTen(){
    cout << "\n=== TIM KIEM DOC GIA THEO TEN ===" << endl;
    
    // Xóa bộ đệm nhập trước khi đọc tên
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    char hoTenCanTim[50];
    cout << "Nhap ho ten can tim: ";
    cin.getline(hoTenCanTim, 50);
    
    // Kiểm tra chuỗi nhập vào
    if (strlen(hoTenCanTim) == 0) {
        cout << "Khong duoc bo trong ten!" << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < soLuongDocGia; i++) {
        // Chuyển cả hai chuỗi về chữ thường để so sánh không phân biệt hoa thường
        char hoTenLower[50], hoTenCanTimLower[50];
        strcpy(hoTenLower, hoTen[i]);
        strcpy(hoTenCanTimLower, hoTenCanTim);
        
        // Chuyển về chữ thường
        for (char *p = hoTenLower; *p; ++p) *p = tolower(*p);
        for (char *p = hoTenCanTimLower; *p; ++p) *p = tolower(*p);
        
        if (strstr(hoTenLower, hoTenCanTimLower) != NULL) {
            cout << "----------------------------------------" << endl;
            cout << "Ma doc gia: " << maDocGia[i] << endl;
            cout << "Ho ten: " << hoTen[i] << endl;
            cout << "CMND: " << cmnd[i] << endl;
            cout << "Ngay sinh: " << ngaySinh[i] << endl;
            cout << "----------------------------------------" << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay doc gia co ten chua '" << hoTenCanTim << "'" << endl;
    }

}


void quanLyDocGia() {
    int luaChon;
    do
    {
        cout << "==================== QUAN LY DOC GIA ====================" << endl;
        cout << "1. Xem danh sach doc gia" << endl;
        cout << "2. Them doc gia" << endl;
        cout << "3. Sua thong tin doc gia" << endl;
        cout << "4. Xoa thong tin doc gia" << endl;
        cout << "5. Tim kiem doc gia theo CMND" << endl;
        cout << "6. Tim kiem sach theo ho ten" << endl;
        cout << "Quay lai menu chinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
    
        switch (luaChon)
        {
        case 1:
            xemDanhSachDocGia();
            break;
        case 2:
            themDocGia();
            break;
        case 3:
            chinhSuaDocGia();
            break;
        case 4:
            xoaDocGia();
            break;
        case 5: 
            timDocGiaTheoCMND();
            break;
        case 6:
            timDocGiaTheoTen();
            break;
        case 0:
            cout << "Quay lai menu chinh" << endl;
            break;
        default:
            break;
        }
    } while (luaChon != 0);
}
// int main(){
//     khoiTaoDocGia(); // Gọi hàm khởi tạo độc giả
//     quanLyDocGia(); // Gọi hàm quản lý độc giả
//     return 0;
// }