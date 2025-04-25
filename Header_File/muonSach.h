#ifndef MUON_SACH_H
#define MUON_SACH_H
#include <iostream>
using namespace std;

#define MAX_SACH_MUON 5  // Số sách tối đa được mượn
#define MAX_DOC_GIA 1000 // Số lượng độc giả tối đa

// Biến toàn cục quản lý phiếu mượn
extern char ngayMuon[MAX_DOC_GIA][15];
extern char ngayTraDuKien[MAX_DOC_GIA][15];
extern char ngayTraThucTe[MAX_DOC_GIA][15];
extern long long danhSachISBNMuon[MAX_DOC_GIA][MAX_SACH_MUON];
extern int soLuongSachMuon[MAX_DOC_GIA];
extern int soPhieuMuon;


// Khai báo hàm
void khoiTaoDocGia();
void muonSach();
//void xemDanhSachPhieuMuon();

#endif