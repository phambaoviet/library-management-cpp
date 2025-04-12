#ifndef TRASACH_H
#define TRASACH_H
#include <iostream>
#include <iomanip>
#include <cstring>

#define MAX_DOC_GIA 1000 // Số lượng độc giả tối đa
#define MAX_SACH_MUON 5  // Số sách tối đa được mượn
using namespace std;
// Khai báo các biến toàn cục
extern int maDocGia[MAX_DOC_GIA];
extern char ngayMuon[MAX_DOC_GIA][15];
extern char ngayTraDuKien[MAX_DOC_GIA][15];
extern char ngayTraThucTe[MAX_DOC_GIA][15];
extern long long danhSachISBNMuon[MAX_DOC_GIA][MAX_SACH_MUON];
extern int soLuongSachMuon[MAX_DOC_GIA];
extern int soPhieuMuon;
extern int soSachMuon;

int timKiemSachTheoISBN(long long isbn);
void traSach();
int chuyenNgayThanhSo(char ngay[]);
#endif