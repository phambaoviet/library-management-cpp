/*
    File: data.cpp
    Mô tả: 
        + Các biến toàn cục được khai báo cho các file header tương ứng.
        + Các biến này dùng để quản lý thông tin độc giả, sách, phiếu mượn, và các thông tin liên quan trong hệ thống quản lý thư viện.
    Người viết  : Phạm Bảo Việt - Nhập môn lập trình
*/

#include "../Header_File/docgia.h"
#include "../Header_File/quanlysach.h"
#include "../Header_File/muonSach.h"
#include "../Header_File/traSach.h"

// Khai báo các biến toàn cục của docgia.h
int soLuongDocGia;
int maDocGia[MAX_DOC_GIA];
char hoTen[MAX_DOC_GIA][50];
char ngaySinh[MAX_DOC_GIA][20];
char gioiTinh[MAX_DOC_GIA][10];
char cmnd[MAX_DOC_GIA][20];
char diaChi[MAX_DOC_GIA][100]; 
char email[MAX_DOC_GIA][50];
char ngayLapThe[MAX_DOC_GIA][20];
char ngayHetHan[MAX_DOC_GIA][20];


// Khai bao các biến toàn cục của quanlysach.h

long long ISBN[MAX_SACH];
char tenSach[MAX_SACH][50];
char tacGia[MAX_SACH][50];
char theLoai[MAX_SACH][20];
char nhaXuatBan[MAX_SACH][50];
int namXuatBan[MAX_SACH];
int giaSach[MAX_SACH]; 
int soLuong[MAX_SACH];
int soLuongSach = 8;
int soDocGia;


// Khai báo các biến toàn cục của muonSach.h
int soPhieuMuon;

// Khai báo các biến toàn cục của traSach.h
char ngayMuon[MAX_DOC_GIA][15];
char ngayTraDuKien[MAX_DOC_GIA][15];
char ngayTraThucTe[MAX_DOC_GIA][15];
long long danhSachISBNMuon[MAX_DOC_GIA][MAX_SACH_MUON];
int soLuongSachMuon[MAX_DOC_GIA];
int soSachMuon;

