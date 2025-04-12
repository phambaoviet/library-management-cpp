#ifndef DOCGIA_H
#define DOCGIA_H

#include <iostream>
#include <cstring>


#define MAX_DOC_GIA 1000 // Số lượng độc giả tối đa

using namespace std;


extern int soLuongDocGia;
extern int maDocGia[MAX_DOC_GIA];
extern char hoTen[MAX_DOC_GIA][50];
extern char ngaySinh[MAX_DOC_GIA][20];
extern char gioiTinh[MAX_DOC_GIA][10];
extern char cmnd[MAX_DOC_GIA][20];
extern char diaChi[MAX_DOC_GIA][100]; 
extern char email[MAX_DOC_GIA][50];
extern char ngayLapThe[MAX_DOC_GIA][20];
extern char ngayHetHan[MAX_DOC_GIA][20];
extern int soLuongDocGia; 

void khoiTaoDocGia();
void quanLyDocGia();
void xemDanhSachDocGia();
void themDocGia();
void chinhSuaDocGia();
void xoaDocGia();
void timDocGiaTheoCMND();
void timDocGiaTheoTen();

#endif

