/*
Xây dựng lớp Hang, trong đó có các thuộc tính (private) : mã hàng, tên hàng, số lượng, đơn giá (triệu đồng) và các hàm (public): Hàm tạo, các hàm nhập/xuất...
Xây dựng lớp Maytinh (Máy tính) dẫn xuất từ lớp Hang, trong đó thêm các thuộc tính (private): hệ điều hành (Win, Mac), trọng lượng, giá. 
Viết chương trình:§Nhập thông tin cho n đối tượng Maytinh.§In danh sách các loại máy tính chạy Win có trọng lượng không quá 2,5 kg.
Tìm máy tính Mac có giá rẻ nhất.
*/

#include<bits/stdc++.h>
using namespace std;

class Hang {
    private:
        string maHang, tenHang;
        int soLuong;
        float donGia;
    public:
        Hang() {
            soLuong=0;
        }
        void nhap() {
            cout <<"Nhap ma hang: ";
            cin >> maHang; cin.ignore();
            cout <<"Nhap ten hang: ";
            getline(cin, tenHang);
            cout <<"Nhap so luong: ";
            cin >> soLuong;
            cout <<"Nhap don gia: ";
            cin >> donGia;
        }
        void xuat() {
            cout << setw(7) << left << maHang << setw(15) << tenHang << setw(5) << soLuong << setw(5) << donGia;
        }
};
class Maytinh:public Hang {
    private:
        string heDieuHanh;
        float trongLuong, gia;
    public:
        void nhap() {
            Hang::nhap();
            cout <<"Nhap he dieu hanh: ";
            cin >> heDieuHanh;
            cout <<"Nhap trong luong: ";
            cin >> trongLuong;
            cout <<"Nhap gia: ";
            cin >> gia;
        }
        void xuat() {
            Hang::xuat();
            cout << setw(10) << heDieuHanh << trongLuong << "kg" << setw(5) << gia << "\n";
        }
        string getHDH() {
            return heDieuHanh;
        }
        float getTrongLuong() {
            return trongLuong;
        }
        float getGia() {
            return gia;
        }
};
int main() {
    int n;
    cout <<"Nhap so luong may tinh: ";
    cin >> n;
    Maytinh *a = new Maytinh[n+5];
    for(int i=0; i<n; i++) {
        cout <<"Nhap thong tin cho may tinh thu " << i+1 << ": \n";
        a[i].nhap();
    }
    cout << "----------Danh sach cac loai may tinh chay Win co trong luong <= 2.5kg: ----------\n";
    int kt=0;
    for(int i=0; i<n; i++) {
        if(a[i].getHDH() == "win" || a[i].getHDH() == "Win")        
            if(a[i].getTrongLuong() <= 2.5) {
                a[i].xuat();
                kt=1;
            }
    }
    if(kt==0) cout << "Khong co may tinh chay Win co trong luong <= 2.5kg";
    float min = INT_MAX;
    Maytinh reNhat;
    kt=0;
    for(int i=0; i<n; i++) {
        if(a[i].getHDH() == "mac" || a[i].getHDH() == "Mac")   {
            if(a[i].getGia() < min) {
                min = a[i].getGia();
                reNhat = a[i];
                kt=1;
            }
        }        
    }
    if(kt==0) cout <<"Khong tim thay may tinh Mac co gia re nhat";
    else reNhat.xuat();
}