/*
    File: thongke.cpp
    Mô tả: 
        - Cung cấp chức năng mượn sách cho thư viện.
        - Bao gồm các hàm:
            + thongKeSoLuongSach()
            + thongKeSachTheoTheLoai()
            + thongKeDocGia()
            + thongKeSoLuongDocGiaTheoGioiTinh()
            + thongKeSoSachDangDuocMuon()
            + thongKeDocGiaTreHan()
            + thongKe()
    Người thực hiện: Phạm Bảo Việt - Nhập môn lập trình
*/

#include <iostream>

#include "../Header_File/thongKe.h"
#include "../Header_File/quanlysach.h"
#include "../Header_File/docgia.h"
#include "../Header_File/muonSach.h"
#include "../Header_File/traSach.h"

using namespace std;

// Hàm thống kê tổng số lượng sách trong thư viện
void thongKeSoLuongSach(){
    int tong = 0;
    for (int i = 0; i < soLuongSach; i++)
    {
        tong += soLuong[i];
    }
    cout << "Tong so luong sach trong thu vien: " << tong << endl;
}
// Hàm thống kê sách theo từng thể loại
void thongKeSachTheoTheLoai(){
    char theLoaiDem[MAX_SACH][30];
    int soLuongTheLoai[MAX_SACH] = {0};
    int dem = 0;
    for (int i = 0; i < soLuongSach; i++)
    {
        bool daCo = false;              // Kiểm tra thể loại sách đã tồn tại trong mảng chưa??
        for (int j = 0; j < dem; j++)
        {
            if (strcmp(theLoaiDem[j], theLoai[i]) == 0)
            {
                soLuongTheLoai[j] += soLuong[i];        // Nếu có thì cộng thêm
                daCo = true;
                break;
            }
        }
        if (!daCo)        // Nếu không có thì thêm vào mảng
        {
            strcpy(theLoaiDem[dem], theLoai[i]);
            soLuongTheLoai[dem] = soLuong[i];
            dem++;
        }
    }
    // In danh sách thể loại và số lượng
    cout << "==================== THONG KE SACH THEO THE LOAI ====================" << endl;
    cout << left << setw(20) << "The Loai" << setw(20) << "So Luong" << endl;
    for (int i = 0; i < dem; i++)
    {
        cout << left << setw(20) << theLoaiDem[i] << setw(20) << soLuongTheLoai[i] << endl;
    }
    
}
// Hàm thống kê tổng số độc giả
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
// Hàm thống kê số sách đang được mượn
void thongKeSoSachDangDuocMuon(){
    int tong = 0;
    for (int i = 0; i < soLuongDocGia; i++)
    {
        tong += soLuongSachMuon[i];         // Cộng tổng số sách đang được mượn
    }
    cout << "==================== THONG KE SO SACH DANG DUOC MUON ====================" << endl;
    cout << "Tong so sach dang duoc muon: " << tong << endl;
}
// Hàm thống kê độc giả quá hạn
void thongKeDocGiaTreHan(){
    int treHan = 0;
    cout << "==================== THONG KE DOC GIA TRE HAN ====================\n";
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strlen(ngayTraDuKien[i]) > 0 && strlen(ngayTraThucTe[i]) > 0) {         // Kiểm tra ngày mượn và ngày trả
            int ngayDuKien = chuyenNgayThanhSo(ngayTraDuKien[i]);
            int ngayThucTe = chuyenNgayThanhSo(ngayTraThucTe[i]);

            if (ngayThucTe > ngayDuKien) {      // Nếu ngày trả muộn hơn thực tế
                treHan++;   
                // In thông tin độc giả bị trễ hạn
                cout << "- " << hoTen[i] << endl;
                cout << "  CMND: " << cmnd[i] << endl;
                cout << "  Ngay muon: " << ngayMuon[i] << endl;
                cout << "  Ngay tra du kien: " << ngayTraDuKien[i] << endl;
                cout << "  Ngay tra thuc te: " << ngayTraThucTe[i] << endl;
                cout << "  So sach muon: " << soLuongSachMuon[i] << endl;

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
    cout << "0. Quay lai menu chinh" << endl;
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


