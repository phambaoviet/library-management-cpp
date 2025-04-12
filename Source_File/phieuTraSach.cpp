#include <iostream>
#include <iomanip>
#include <cstring>
#include "../Header_File/muonSach.h"
#include "../Header_File/traSach.h"
#include "../Header_File/docgia.h"
#include "../Header_File/quanlysach.h"

using namespace std;

int timKiemSachTheoISBN(long long isbn) {
    for (int i = 0; i < soLuongSach; i++) {
        if (ISBN[i] == isbn) {
            return i;  // Trả về chỉ số của sách trong mảng
        }
    }
    return -1;  // Không tìm thấy sách
}
int chuyenNgayThanhSo(char ngay[]){
    int day, month, year;
    sscanf(ngay, "%d/%d/%d", &day, &month, &year);
    return (year*12*30) + (month*30) + day; // Chuyển đổi thành số ngày (giả sử mỗi tháng là 30 ngày)
}
#include <iostream>
#include <iomanip>  // Để sử dụng setw, left
#include <cstring>
#include "../Header_File/muonSach.h"
#include "../Header_File/docgia.h"
#include "../Header_File/quanlysach.h"

using namespace std;
void traSach() {
    int maDocGiaNhap;
    cout << "Nhap ma doc gia: ";
    cin >> maDocGiaNhap;
    bool found = false;
    // Kiểm tra mã độc giả có tồn tại không
    int viTriDocGia = -1;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (maDocGia[i] == maDocGiaNhap) {
            viTriDocGia = i;
            break;
        }
    }
    if (viTriDocGia == -1) {
        cout << "Ma doc gia khong ton tai!" << endl;
        return;
    }
        // Kiểm tra độc giả có sách mượn không
    int soLuongMuon = soLuongSachMuon[viTriDocGia];
    if (soLuongMuon == 0) {
        cout << "Khong co sach nao de tra!" << endl;
        return;
    }
    // Hiển thị danh sách sách đang mượn
    cout << "\nDanh sach sach da muon:\n";
    cout << left << setw(15) << "ISBN"
         << setw(20) << "Ten Sach"
         << setw(20) << "Tac Gia"
         << setw(20) << "The Loai"
         << setw(20) << "Nha Xuat Ban"
         << setw(15) << "Nam Xuat Ban"
         << setw(10) << "So Luong"
         << setw(10) << "Gia"
         << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------------\n";
    int tongTienPhat = 0;
    for (int i = 0; i < soLuongMuon; i++) {
        long long isbn = danhSachISBNMuon[viTriDocGia][i];
        int indexSach = timKiemSachTheoISBN(isbn);
        if (indexSach != -1) {
            cout << left << setw(15) << ISBN[indexSach]
                 << setw(20) << tenSach[indexSach]
                 << setw(20) << tacGia[indexSach]
                 << setw(20) << theLoai[indexSach]
                 << setw(20) << nhaXuatBan[indexSach]
                 << setw(15) << namXuatBan[indexSach]
                 << setw(10) << soLuong[indexSach]
                 << setw(10) << giaSach[indexSach]
                 << endl;
            char matSach;
            cout << "Sach " << tenSach[indexSach] << " co bi mat khong?? (y/n)??" << endl;
            cin >> matSach;
            if (matSach == 'y' || matSach == 'Y') {
                int tienPhat = giaSach[indexSach] * 2; // Giả sử tiền phạt là gấp đôi giá sách
                cout << "Tien phat: " << tienPhat << " VND"<< endl;
                tongTienPhat += tienPhat;
            }
            else {
                cout << "Khong mat sach!" << endl;
                // Tăng lại số lượng sách (nếu cần)
                soLuong[indexSach]++;
            }
        }
    }

    // Nhập ngày trả thực tế
    char ngayTra[15];
    cout << "\nNhap ngay tra thuc te (dd/mm/yyyy): ";
    cin >> ngayTra;
    strcpy(ngayTraThucTe[viTriDocGia], ngayTra);  // Lưu ngày trả
    // Tính tiền phạt do trả trễ
    int ngayTraThucTeSo = chuyenNgayThanhSo(ngayTra);
    int ngayTraDuKienSo = chuyenNgayThanhSo(ngayTraDuKien[viTriDocGia]);
    int soNgayMuon = ngayTraThucTeSo - ngayTraDuKienSo;
    if (soNgayMuon > 7) {
        int soNgayTre = soNgayMuon - 7; // Giả sử thời gian miễn phí là 7 ngày
        cout << "Ban da tra sach tre: " << soNgayTre << " ngay" << endl;
        // Tính tiền phạt
        int tienPhat = soNgayTre * 5000; // Giả sử tiền phạt là 5000 VND/ngày
        cout << "Tien phat do tra tre: " << tienPhat << " VND" << endl;
        tongTienPhat += tienPhat;
    } else {
        cout << "Ban da tra sach dung han" << endl;
    }
    // Cập nhật số lượng sách đã trả
    for (int i = 0; i < soLuongMuon; i++) {
        long long isbn = danhSachISBNMuon[viTriDocGia][i];
        int indexSach = timKiemSachTheoISBN(isbn);
        if (indexSach != -1) {
            soLuong[indexSach]++;
        }
    }
    // Xóa thông tin sách đã trả
    soLuongSachMuon[viTriDocGia] = 0; // Đặt lại số lượng sách đã mượn
    for (int i = 0; i < MAX_SACH_MUON; i++) {
        danhSachISBNMuon[viTriDocGia][i] = 0; // Đặt lại danh sách ISBN đã mượn
    }
    cout << "\nTong tien phat: " << tongTienPhat << " VND" << endl;
    cout << "\nSach da duoc tra thanh cong!\n";
}
    
// int main(){
//     traSach();
//     return 0;
// }