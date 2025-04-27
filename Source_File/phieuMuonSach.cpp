/*
    File: muonSach.cpp
    Mô tả: 
        - Cung cấp chức năng mượn sách cho thư viện.
        - Bao gồm các hàm:
            + timKiemSachTheoTen(): Tìm kiếm sách trong thư viện theo tên sách.
            + muonSach(): Thực hiện quá trình mượn sách cho độc giả.
    Người thực hiện: Phạm Bảo Việt - Nhập môn lập trình
*/
#include <iostream>
#include <cstring>
#include "../Header_File/muonSach.h"
#include "../Header_File/docgia.h"
#include "../Header_File/quanlysach.h"


using namespace std;


int timKiemSachTheoTen(char tenSachCanTim[50]) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(tenSach[i], tenSachCanTim) == 0) {
            return i; // Trả về chỉ số của sách tìm thấy
        }
    }
    return -1; // Không tìm thấy sách
}
void muonSach(){
    int soLuongMuon = 0;

    // Nhập mã độc giả
    cout << "Nhap ma doc gia: ";
    int maDocGiaNhap;
    cin >> maDocGiaNhap;
    cin.ignore();
    // Tìm vị trí trong mảng
    int viTriDocGia = -1;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (maDocGia[i] == maDocGiaNhap) {
            viTriDocGia = i;
            break;
        }
    }
    // Kiểm tra mã độc giả
    bool found = false;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (maDocGia[i] == maDocGiaNhap) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Ma doc gia khong ton tai!\n";
        return;
    }

    // Nhập số lượng sách muốn mượn
    cout << "Nhap so sach muon (1-5): ";
    cin >> soLuongMuon;
    if (soLuongMuon <= 0 || soLuongMuon > MAX_SACH_MUON) {
        cout << "So sach muon phai tu 1 den " << MAX_SACH_MUON << "!" << endl;
        return;
    }

    cin.ignore();  // Xóa bộ đệm
    soLuongSachMuon[viTriDocGia] = soLuongMuon;

    for (int i = 0; i < soLuongMuon; i++) {
        char tenSachCanTim[50];
        cout << "Nhap ten sach can tim: ";
        cin.getline(tenSachCanTim, 50);
        int indexSach = timKiemSachTheoTen(tenSachCanTim);
        if (indexSach == -1) {
            cout << "Khong tim thay sach voi ten: " << tenSachCanTim << ". Vui long nhap lai.\n";
            i--;  
        } else {
            danhSachISBNMuon[viTriDocGia][i] = ISBN[indexSach];
            soLuong[indexSach]--;
            cout << "Sach da duoc muon!\n";
        }
    }

    cout << "Nhap ngay muon (dd/mm/yyyy): ";
    cin >> ngayMuon[viTriDocGia];
    cout << "Nhap ngay tra du kien (dd/mm/yyyy): ";
    cin >> ngayTraDuKien[viTriDocGia];

    strcpy(ngayTraThucTe[viTriDocGia], "");

    soPhieuMuon++;  // Tăng số phiếu mượn

    cout << "Phieu muon sach da duoc tao thanh cong!\n";
}
