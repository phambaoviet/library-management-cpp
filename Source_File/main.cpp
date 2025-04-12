#include <iostream>
#include <iomanip>
#include <cstring>
#include "../Header_File/quanlysach.h"
#include "../Header_File/docgia.h"
#include "../Header_File/muonSach.h"
#include "../Header_File/traSach.h"
#include "../Header_File/thongKe.h"
// #include <thongkesach.h>
using namespace std;
// void quanLyDocGia(); // Khai báo hàm quản lý độc giả
// void quanLySach(); // Khai báo hàm quản lý sách
void hienThiMeNu() {
    int luaChon;
    do
    {
        cout << "==================== QUAN LY THU VIEN ====================" << endl;
        cout << "1. Quan ly doc gia" << endl;
        cout << "2. Quan Ly sach" << endl;
        cout << "3. Lap phieu muon sach" << endl;
        cout << "4. Lap phieu tra sach" << endl;
        cout << "5. Thong ke sach" << endl;
        cout << "Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                // Gọi hàm quản lý độc giả 
                khoiTaoDocGia(); // Khởi tạo độc giả
                quanLyDocGia();
                //cout << "Chuc nang quan ly doc gia chua duoc hoan thanh!" << endl;
                break;
            case 2:
                // Gọi hàm quản lý sách
                khoiTaoSach(); // Khởi tạo sách
                quanLySach();
                //cout << "Chuc nang quan ly sach chua duoc hoan thanh!" << endl;
                break;
            case 3:
                // Gọi hàm lập phiếu mượn sách
                muonSach();
                break;
            case 4:
                // Gọi hàm lập phiếu trả sách
                traSach();
                break;
            case 5:
                thongKe();
                break;
            case 0:
                cout << "Quay lai menu chinh" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
        
    } while (luaChon != 0);
    
}
int main() {
    hienThiMeNu();                  // Gọi hàm hiển thị 
    // //khoiTaoDocGia();              // Gọi hàm khởi tạo độc giả
    // quanLyDocGia();             // Gọi hàm quản lý độc giả
    // //khoiTaoSach();              // Gọi hàm khởi tạo sách
    // quanLySach();             // Gọi hàm quản lý sách
    // muonSach();             // Gọi hàm quản lý mượn sách
    
    // cout << "Cam on ban da su dung chuong trinh!" << endl;
    // cout << "Hen gap lai!" << endl;
    // cout << "==========================================================" << endl;
    return 0;
}