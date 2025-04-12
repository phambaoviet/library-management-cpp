#include <iostream>
using namespace std;
#include "../Header_File/thongKe.h"
#include "../Header_File/quanlysach.h"
#include "../Header_File/docgia.h"
#include "../Header_File/muonSach.h"
#include "../Header_File/traSach.h"

void thongKeSoLuongSach(){
    int tong = 0;
    for (int i = 0; i < soLuongSach; i++)
    {
        tong += soLuong[i];
    }
    cout << "Tong so luong sach trong thu vien: " << tong << endl;
}
void thongKeSachTheoTheLoai(){
    char theLoaiDem[MAX_SACH][30];
    int soLuongTheLoai[MAX_SACH] = {0};
    int dem = 0;
    for (int i = 0; i < soLuongSach; i++)
    {
        bool daCo = false;
        for (int j = 0; j < dem; j++)
        {
            if (strcmp(theLoaiDem[j], theLoai[i]) == 0)
            {
                soLuongTheLoai[j] += soLuong[i];
                daCo = true;
                break;
            }
        }
        if (!daCo)
        {
            strcpy(theLoaiDem[dem], theLoai[i]);
            soLuongTheLoai[dem] = soLuong[i];
            dem++;
        }
    }
    cout << "==================== THONG KE SACH THEO THE LOAI ====================" << endl;
    cout << left << setw(20) << "The Loai" << setw(20) << "So Luong" << endl;
    for (int i = 0; i < dem; i++)
    {
        cout << left << setw(20) << theLoaiDem[i] << setw(20) << soLuongTheLoai[i] << endl;
    }
    
}
void thongKeDocGia(){
    cout << "==================== THONG KE DOC GIA ====================" << endl;
    cout << soLuongDocGia << endl;
}
void thongKeSoLuongDocGiaTheoGioiTinh(){
    int nam = 0, nu = 0;
    for (int i = 0; i < soLuongDocGia; i++)
    {
        if (strcmp(gioiTinh[i], "Nam") == 0)
        {
            nam++;
        }
        else if (strcmp(gioiTinh[i], "Nu") == 0)
        {
            nu++;
        }
    }
    cout << "==================== THONG KE DOC GIA THEO GIOI TINH ====================" << endl;
    cout << "Nam: " << nam << endl;
    cout << "Nu: " << nu << endl;
}
void thongKeSoSachDangDuocMuon(){
    int tong = 0;
    for (int i = 0; i < soLuongDocGia; i++)
    {
        tong += soLuongSachMuon[i];
    }
    cout << "==================== THONG KE SO SACH DANG DUOC MUON ====================" << endl;
    cout << "Tong so sach dang duoc muon: " << tong << endl;
}
void thongKeDocGiaTreHan(){
    int treHan = 0;
    cout << "==================== THONG KE DOC GIA TRE HAN ====================\n";
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strlen(ngayTraDuKien[i]) > 0 && strlen(ngayTraThucTe[i]) > 0) {
            int ngayDuKien = chuyenNgayThanhSo(ngayTraDuKien[i]);
            int ngayThucTe = chuyenNgayThanhSo(ngayTraThucTe[i]);

            if (ngayThucTe > ngayDuKien) {
                treHan++;
                cout << "- " << hoTen[i] << endl;
            }
        }
    }

    if (treHan == 0) {
        cout << "Khong co doc gia nao tra sach tre han.\n";
    } else {
        cout << "\nTong so doc gia tre han: " << treHan << endl;
    }

}
void thongKe(){
    int luaChon;
    cout << "==================== THONG KE SACH ====================" << endl;
    cout << "1. Thong ke so luong sach trong thu vien" << endl;
    cout << "2. Thong ke sach theo the loai" << endl;
    cout << "3. Thong ke doc gia" << endl;
    cout << "4. Thong ke so luong doc gia theo gioi tinh" << endl;
    cout << "5. Thong ke so sach dang duoc muon" << endl;
    cout << "6. Thong ke so danh sach doc gia bi tre han" << endl;
    cout << "Nhap lua chon: ";
    cin >> luaChon;

    switch (luaChon)
    {
        case 1:
            thongKeSoLuongSach();
            break;
        case 2:
            thongKeSachTheoTheLoai();
            break;
        case 3:
            thongKeDocGia();
            break;
        case 4:
            thongKeSoLuongDocGiaTheoGioiTinh();
            break;
        case 5:
            thongKeSoSachDangDuocMuon();
            break;
        case 6:
            thongKeDocGiaTreHan();
            break;
        default:
            break;
    }
}


// int main() {
//     thongKe(); // Gọi hàm thống kê
//     return 0;
// }