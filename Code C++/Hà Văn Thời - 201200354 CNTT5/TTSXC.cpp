#include <bits/stdc++.h>

using namespace std;

class sinhvien {
	private: 
		int msv;
		string tendem;
		string ten;
		int khoa;
		string lop;
	public:
		sinhvien();
		sinhvien(int, string, string, int, string);
		string getten(){
			return ten;
		}
		void Nhapdulieu(){
			cout << "\nMa sinh vien: ";
			cin >> msv;
			cout << "\nTen dem sinh vien: ";
			cin.ignore();
			getline(cin, tendem);
			cout << "\nTen sinh vien: ";
			cin >> ten;
			cout << "\nSinh vien khoa: ";
			cin >> khoa;
			cout << "\nLop sinh vien: ";
			cin >> lop;
		}
			void Xuatdulieu(){
			cout << "\nMa sinh vien " << msv;
			cout << "\nTen sinh vien " << tendem << " " << ten;
			cout << "\nSinh vien khoa " << khoa;
			cout << "\nLop " << lop;
		}					
};
	sinhvien::sinhvien(int masv, string tendemsv, string tensv, int khoasv, string lopsv){
		msv = masv;
		tendem = tendemsv;
		ten = tensv;
		khoa = khoasv;
		lop = lopsv;
	}

int main() {
	sinhvien a[100], t;
	int n;
	cout << "\nNhap so sinh vien: ";
	cin >> n;
	if (n == 0){
		cout << "\nKhong hop le!";
		return 0;
	}
	for ( int i = 1; i <= n; i++){
		cout << "\nNhap thong tin sinh vien thu " << i  << ":";
		a[i].Nhapdulieu();
	}
	cout << "\nDanh sach sinh vien vua nhap:\n";
	for ( int i = 1; i <= n; i++){
		a[i].Xuatdulieu();
	}
	for( int i = 1; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i].getten() > a[j].getten()){
				swap(a[i],a[j]);
			}
		}
	}
	cout << "\n\nDanh sach sinh vien sau khi sap xep:\n";
	for ( int i = 0; i < n; i++){
		a[i].Xuatdulieu();
	}
}
	
