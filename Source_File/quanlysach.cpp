/*
    File: quanlysach.cpp
    Mô tả: 
        - Định nghĩa các hàm xử lý chức năng quản lý sách trong thư viện.
        - Các chức năng bao gồm:
            + khoiTaoSach()
            + xemDanhSachSach()
            + themSach()
            + chinhSuaSach()
            + xoaSach() 
            + timKiemSachTheoISBN()
            + timKiemSachTheoTenSach()
    Người thực hiện: Phạm Bảo Việt - Nhập môn lập trình
*/
#include "../Header_File/quanlysach.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Hàm khởi tạo sách
void khoiTaoSach(){
    // Thêm một số sách mẫu vào danh sách
    ISBN[0] = 9781234567890;
    strcpy(tenSach[0], "Ngay xua co mot truyen tinh");      
    strcpy(tacGia[0], "Nguyen Nhat Anh");
    strcpy(theLoai[0], "Truyen ngan");
    strcpy(nhaXuatBan[0], "NXB Kim Dong");
    namXuatBan[0] = 2020;
    soLuong[0] = 10; // Số lượng sách hiện có
    giaSach[0] = 50000;

    ISBN[1] = 9780131103627;
    strcpy(tenSach[1], "Nha gia kim");
    strcpy(tacGia[1], "Paulo Coelho");
    strcpy(theLoai[1], "Khoa hoc vien tuong");
    strcpy(nhaXuatBan[1], "NXB Kim Dong");
    namXuatBan[1] = 2021;
    soLuong[1] = 5; 
    giaSach[1] = 55000;

    ISBN[2] = 9780132350884;
    strcpy(tenSach[2], "Ke an hon");
    strcpy(tacGia[2], "Thao Trang");
    strcpy(theLoai[2], "Kinh di");
    strcpy(nhaXuatBan[2], "NXB Thanh Nien");
    namXuatBan[2] = 2019;
    soLuong[2] = 8; 
    giaSach[2] = 600000;

    ISBN[3] = 9780134685991;
    strcpy(tenSach[3], "Bo gia");
    strcpy(tacGia[3], "Mario Puzo");
    strcpy(theLoai[3], "Khoa hoc vien tuong");
    strcpy(nhaXuatBan[3], "NXB Kim Dong");
    namXuatBan[3] = 2017;
    soLuong[3] = 12; 
    giaSach[3] = 80000;

    ISBN[4] = 9780134686092;
    strcpy(tenSach[4], "Nguoi thay");
    strcpy(tacGia[4], "Nguyen Chi Vinh");
    strcpy(theLoai[4], "Tu Truyen");
    strcpy(nhaXuatBan[4], "NXB Quan Doi");
    namXuatBan[4] = 2023;
    soLuong[4] = 20; 
    giaSach[4] = 100000;


    ISBN[5] = 9780132350884;
    strcpy(tenSach[5], "Tet o lang dia nguc");
    strcpy(tacGia[5], "Thao Trang");
    strcpy(theLoai[5], "Kinh di");
    strcpy(nhaXuatBan[5], "NXB Thanh Nien");
    namXuatBan[5] = 2009;
    soLuong[5] = 15; 
    giaSach[5] = 70000;

    ISBN[6] = 9780134685999;
    strcpy(tenSach[6], "Chi Pheo");
    strcpy(tacGia[6], "Nam Cao");
    strcpy(theLoai[6], "Truyen ngan");
    strcpy(nhaXuatBan[6], "NXB Van hoc");
    namXuatBan[6] = 2017;
    soLuong[6] = 25; 
    giaSach[6] = 90000;
   
    ISBN[7] = 9780134686097;
    strcpy(tenSach[7], "Noi buon chien tranh");
    strcpy(tacGia[7], "Bao Ninh");
    strcpy(theLoai[7], "Tieu thuyet");
    strcpy(nhaXuatBan[7], "NXB Tre");
    namXuatBan[7] = 2008;
    soLuong[7] = 30; 
    giaSach[7] = 90000;
   

}
// Hàm hiển thị danh sách sách
void xemDanhSachSach() {
    cout << "=========================================================== DANH SACH SACH ===================================================" << endl;

    // In tiêu đề cột
    cout << left << setw(15) << "ISBN" 
         << setw(30) << "Ten Sach" 
         << setw(20) << "Tac Gia"
         << setw(20) << "Nha Xuat Ban" 
         << setw(15) << "Nam Xuat Ban" 
         << setw(20) << "The Loai"
         << setw(10) << "Gia Sach" 
         << setw(10) << "Hien con"
         << endl;

    // In dấu phân cách giữa các dòng
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;

    // In thông tin các sách
    for (int i = 0; i < soLuongSach; i++) {
        cout << left << setw(15) << ISBN[i] 
             << setw(30) << tenSach[i] 
             << setw(20) << tacGia[i]     
             << setw(20) << nhaXuatBan[i] 
             << setw(15) << namXuatBan[i] 
             << setw(20) << theLoai[i]
             << setw(10) << giaSach[i] 
             << setw(10) << soLuong[i]
             << endl;
    }
}
// Hàm thêm sách
void themSach() {
    // Code thêm sách
    cout << "Them sach" << endl;
    if (soLuongSach >= MAX_SACH)
    {
        cout << "Khong the them sach, danh sach da day!!!" << endl;
    }
    int index = soLuongSach; // Lấy vị trí trống tiếp theo
    cout << "Nhap ISBN: ";
    cin >> ISBN[index];
    cin.ignore(); // Bỏ qua ký tự newline còn lại trong bộ đệm

    // Kiểm tra ISBN đã tồn tại hay chưa
    bool daTonTai = false;
    for (int i = 0; i < soLuongSach; i++)
    {
        if (ISBN[i] == ISBN[soLuongSach])
        {
            daTonTai = true;
            break;
        }
    }
    if (daTonTai)
    {
        cout << "Sach da ton tai trong danh sach!" << endl;
        return;
    }
    
    cout << "Nhap ten sach: ";
    cin.getline(tenSach[index], 50);
    cout << "Nhap tac gia: ";
    cin.getline(tacGia[index], 50);
    cout << "Nhap the loai: ";
    cin.getline(theLoai[index], 20);
    cout << "Nhap nha xuat ban: ";
    cin.getline(nhaXuatBan[index], 50);
    cout << "Nhap nam xuat ban: ";
    cin >> namXuatBan[index];
    cout << "Nhap so luong sach: ";
    cin >> soLuong[index];
    cout << "Nhap gia sach: ";
    cin >> giaSach[index];
    soLuongSach++; // Tăng số lượng sách
    cout << "Them sach thanh cong!" << endl;
    // In danh sách sách sau khi thêm
    xemDanhSachSach();
}
void chinhSuaSach(){
    cout << "Chinh sua sach" << endl;
    long long isbnCanChinhSua;
    cout << "Nhap ISBN sach can chinh sua: ";
    cin >> isbnCanChinhSua;
    int index = -1;
    for (int i = 0; i < soLuongSach; i++)
    {
        if (ISBN[i] == isbnCanChinhSua)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Khong tim thay sach voi ISBN: " << isbnCanChinhSua << endl;
        return;
    }
    cout << "Nhap ten sach moi: ";
    cin.ignore(); // Bỏ qua ký tự newline còn lại trong bộ đệm
    cin.getline(tenSach[index], 50);
    cout << "Nhap tac gia moi: ";
    cin.getline(tacGia[index], 50);
    cout << "Nhap the loai moi: ";
    cin.getline(theLoai[index], 20);
    cout << "Nhap nha xuat ban moi: ";
    cin.getline(nhaXuatBan[index], 50);
    cout << "Nhap nam xuat ban moi: ";  
    cin >> namXuatBan[index];
    cout << "Nhap so luong sach moi: ";
    cin >> soLuong[index];
    cout << "Nhap gia sach moi: ";
    cin >> giaSach[index];
    cout << "Chinh sua sach thanh cong!" << endl;
    cout << "=========================================================== DANH SACH SACH HIEN TAI ===================================================" << endl;
    xemDanhSachSach();
}
// Hàm xoá sách
void xoaSach() {
    int index = -1;
    long long isbnCanXoa;
    if (soLuongSach == 0) {
        cout << "Thu vien khong co sach nao de xoa!" << endl;
        return;
    }
    
    while (true)
    {
        cout << "Nhap ISBN cua sach can xoa: ";
        cin >> isbnCanXoa;
        for (int i = 0; i < soLuongSach; i++)
        {
            if (ISBN[i] == isbnCanXoa)
            {
                index = i;
                break;
            }
            
        }
        if (index == -1)
        {
            cout << "Khong tim thay sach voi ISBN: " << isbnCanXoa << endl;
            cout << "Vui long nhap lai!" << endl;
        }
        else
        {
            break; // Nếu tìm thấy, thoát vòng lặp
        }
    }
    
    
    // Hiển thị thông tin sách sẽ xoá
    cout << "===============THONG TIN SACH SE XOA===============" << endl;
    cout << "ISBN: " << ISBN[index] << endl;
    cout << "Ten Sach: " << tenSach[index] << endl;
    cout << "Tac Gia: " << tacGia[index] << endl;
    cout << "The Loai: " << theLoai[index] << endl;
    cout << "Nha Xuat Ban: " << nhaXuatBan[index]  << endl;
    cout << "Nam Xuat Ban: " << namXuatBan[index] << endl;
    cout << "Gia Sach: " << giaSach[index] << endl;
    cout << "So Luong: " << soLuong[index] << endl;
    cout << "===================================================" << endl;

    cout << "Ban co chac chan muon xoa sach nay khong? (y/n): ";
    char xacNhan;
    cin >> xacNhan;
    if (xacNhan != 'y' && xacNhan != 'Y') {
        cout << "Huy xoa sach!" << endl;
        return;
    }

    // Dịch chuyển các phần tử phía sau lên để lấp khoảng trống
    for (int i = index; i < soLuongSach - 1; i++) {
        ISBN[i] = ISBN[i + 1];
        strcpy(tenSach[i], tenSach[i + 1]);
        strcpy(tacGia[i], tacGia[i + 1]);
        strcpy(theLoai[i], theLoai[i + 1]);
        strcpy(nhaXuatBan[i], nhaXuatBan[i + 1]);
        namXuatBan[i] = namXuatBan[i + 1];
        giaSach[i] = giaSach[i + 1];
    }

    // Giảm số lượng sách
    soLuongSach--;

    cout << "Xoa sach thanh cong!" << endl;
    // In danh sách sách sau khi xóa
    xemDanhSachSach();
    
}
// Hàm tìm kiếm sách theo ISBN
void timKiemSachTheoISBN(){
    if (soLuongSach == 0) {
        cout << "Thu vien khong co sach nao de tim kiem!" << endl;
        return;
    }

    cout << "Tim kiem sach theo ISBN" << endl;
    long long isbnCanTim;
    
    cout << "Nhap ISBN sach can tim: ";
    cin >> isbnCanTim;
    int index = -1;

    for (int i = 0; i < soLuongSach; i++) {
        if (ISBN[i] == isbnCanTim) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay sach voi ISBN: " << isbnCanTim << endl;
        return;
    }

    // Hiển thị thông tin sách tìm thấy
    cout << "Thong tin sach tim thay:" << endl;
    cout << left << setw(15) << "ISBN" 
         << setw(20) << "Ten Sach" 
         << setw(20) << "Tac Gia" 
         << setw(20) << "The Loai" 
         << setw(20) << "Nha Xuat Ban" 
         << setw(10) << "Nam XB" 
         << setw(10) << "Gia Sach" 
         << setw(10) << "Hien con"
         << endl;
    
    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << left << setw(15) << ISBN[index]
         << setw(20) << tenSach[index]
         << setw(20) << tacGia[index]
         << setw(20) << theLoai[index]
         << setw(20) << nhaXuatBan[index]
         << setw(10) << namXuatBan[index]
         << setw(10) << giaSach[index]
         << setw(10) << soLuong[index]
         << endl;
}
// Hàm tìm kiếm sách theo tên sách
void timKiemSachTheoTenSach(){
    if (soLuongSach == 0) {
        cout << "Thu vien khong co sach nao de tim kiem!" << endl;
        return;
    }

    cout << "Tim kiem sach theo ten sach" << endl;
    char tenSachCanTim[50];
    
    cout << "Nhap ten sach can tim: ";
    cin.ignore(); // Bỏ qua ký tự newline còn lại trong bộ đệm
    cin.getline(tenSachCanTim, 50);

    // Kiểm tra lỗi nhập liệu
    if (cin.fail()) {
        cin.clear();  // Xóa trạng thái lỗi của cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa bộ đệm nhập
        cout << "Nhap ten sach khong hop le!" << endl;
        return;
    }

    int index = -1;

    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(tenSach[i], tenSachCanTim) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay sach voi ten: " << tenSachCanTim << endl;
        return;
    }

    // Hiển thị thông tin sách tìm thấy
    cout << "Thong tin sach tim thay:" << endl;
    cout << left << setw(15) << "ISBN" 
         << setw(20) << "Ten Sach" 
         << setw(20) << "Tac Gia" 
         << setw(20) << "The Loai" 
         << setw(20) << "Nha Xuat Ban" 
         << setw(10) << "Nam XB" 
         << setw(10) << "Gia Sach" 
         << setw(10) << "Hien con"
         << endl;

    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << left << setw(15) << ISBN[index]
         << setw(20) << tenSach[index]
         << setw(20) << tacGia[index]
         << setw(20) << theLoai[index]
         << setw(20) << nhaXuatBan[index]
         << setw(10) << namXuatBan[index]
         << setw(10) << giaSach[index]
         << setw(10) << soLuong[index]
         << endl;
}

void quanLySach(){
    int luaChon;
    do
    {
        cout << "==================== QUAN LY SACH ====================" << endl;
        cout << "1. Xem danh sach sach trong thu vien" << endl;
        cout << "2. Them sach" << endl;
        cout << "3. Chinh sua thong tin sach" << endl;
        cout << "4. Xoa thong tin sach" << endl;
        cout << "5. Tim kiem sach theo ISBN" << endl;
        cout << "6. Tim kiem sach theo ten sach" << endl;
        cout << "0. Quay lai menu chinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon)
        {
            case 1:
                xemDanhSachSach(); // Gọi hàm xem danh sách sách
                break;
            case 2:
                themSach(); // Gọi hàm thêm sách
                break;
            case 3:
                chinhSuaSach(); // Gọi hàm chỉnh sửa sách
                break;
            case 4:
                xoaSach(); // Gọi hàm xóa sách
                break;
            case 5:
                timKiemSachTheoISBN(); // Gọi hàm tìm kiếm sách theo ISBN
                break;
            case 6:
                timKiemSachTheoTenSach(); // Gọi hàm tìm kiếm sách theo tên sách
                break;
            case 0:
                cout << "Quay lai menu chinh" << endl;
                break;
            default:
                break;
        }
    }while (luaChon != 0);
}


