#ifndef QUANLYSACH_H
#define QUANLYSACH_H
#include <iostream>
#include <cstring>

#define MAX_SACH 1000
using namespace std;

extern long long ISBN[MAX_SACH];
extern char tenSach[MAX_SACH][50];
extern char tacGia[MAX_SACH][50];
extern char theLoai[MAX_SACH][20];
extern char nhaXuatBan[MAX_SACH][50];
extern int namXuatBan[MAX_SACH];
extern int giaSach[MAX_SACH];
extern int soLuong[MAX_SACH];
extern int soDocGia;
extern int soLuongSach;


void khoiTaoSach();
void quanLySach();
void xemDanhSachSach();
void themSach();
void chinhSuaSach();
void xoaSach();
void timKiemSachTheoISBN();
void timKiemSachTheoTenSach();

#endif