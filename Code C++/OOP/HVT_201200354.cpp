/*
Họ và tên : Hà Văn Thời
Mã sinh viên: 201200354
Mã đề: 66
*/


#include<iostream>
using namespace std;

class Hang {
private:
	int code;
	string name;
	int soLuong;
	int donGia;
public:
	Hang() {}

	void Nhap() {
		cout << "Nhap thong tin don hang: "
		cout << "\nNhap ma don hang: ";
		cin >> code;
		cout << "\nNhap ten don hang: ";
		cin >> name;
		cout >> "\nNhap so luong: ";
		cin >> soLuong;
		cout >> "\nNhap don gia: ";
		cin >> donGia;
	}

	void Xuat () {
		cout << "\n Thong tin don hang: ";
		cout << "\nMa don hang: " << code;
		cout << "\nTen don hang: " << name;
		cout << "\nSo luong: " << soLuong;
		cout << "\nDon gia: " << donGia;
	}
};

class MayGiat : private Hang {
private:
	int canNang;
public:
	MayGiat() : Hang() {}

	void Nhap {
		Hang::Nhap();
		cout << "\nNhap can nang: ";
		cin >> canNang;
	}

	void Xuat () {
		Hang::Xuat();
		cout << "\nCan nang: " << canNang;
	}
	int getCanNang() {
		return canNang;
	}
	string getName {
		return name;
	}
	int getCode {
		return getCode;
	}
	bool search (int code) {
		if (this->code == code) {
			return true;
		}
		return false;
	}
	bool search (string name) {
		if(this->name == name) {
			return true;
		}
		return false;
	}
};


int main() {
	int n;
	cout << "\nNhap so don hang: ";
	cin >> n;
	MayGiat a[n];
	for(int i = 0; i < n; i++) {
		cout << "\nNhap don hang thu " << i << ": ";
		a[i].Nhap();
	}
	int x;
	cout <<"\nTim thong tin don hang: ";
	cout <<"\n\t 1. Tim bang ten don hang: ";
	cout <<"\n\t 2. Timg bang ma don hang: ";
	cout <<"\nNhap lua chon: ";
	cin >> x;
	if (x == 1) {
		string m;
		cout <<"\n Nhap ten don hang can tim: ";
		cin >> m;
		for(int i = 0; i < n; i++) {
			if(a[i].search(m)) {
				a[i].Xuat();
			} else {
				cout <<"\nKhong tim thay!";
			}
		}
	}
	if (x == 2) {
		int m;
		cout <<"\n Nhap ma don hang can tim: ";
		cin >> m;
		for(int i = 0; i < n; i++) {
			if(a[i].search(m)) {
				a[i].Xuat();
			}
		} else {
				cout <<"\nKhong tim thay!";
			}
		
	}
	cout << "\nTim thong tin may giat vui long nhap ma don hang hoac ten don hang: ";
	for(int i = 0; i < n; i++) {

	}
	cout << "\nCac loai may giat nang hon 8kg la: "
	for(int i = 0; i < n; i++) {
		if(a[i].getCanNang() >= 8) {
			a[i].Xuat();
		}
	}

}