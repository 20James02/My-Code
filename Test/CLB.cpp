#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Cauthu{
	private:
		int cNum;
		string fullName;
		int bDay, bMonth, bYear;
		float wage;
		float contract;
	public:
		int getCnum(){
			return cNum;
		}
		void getWage(float l){
			wage = l;
		} 
		void in()
		{
			cout << "Nhap so ao:";
			cin >> cNum;
			cout << "Nhap ho ten:";
			fflush(stdin); 
			getline(cin, fullName); 
			cout << "Nhap ngay thang nam sinh:";
			cin >> bDay >> bMonth >> bYear;
			cout << "Nhap luong:";
			cin >> wage;
			cout << "Thoi han hop dong (nam):";
			cin >> contract;
		}
		void out(){
			cout << "So ao: "<< cNum;
			cout << "\nHo va ten: "<< fullName;
			cout << "\nNgay sinh: "<< bDay << "/" << bMonth << "/" << bYear;
			cout << "\nMuc luong: "<< wage;
			cout << "nHan hop dong: "<< contract;
		}
};
class CauLacBo{
	private:
		vector<Cauthu> v;
	public:
		void Add()
		{
			Cauthu c;
			c.in( );
			v.push_back(c);
		}
		void Delete()
		{
			int num;
			cout << "So ao cau thu can xoa:";
			cin >> num;
			vector<Cauthu>::iterator it = v.begin();
			for(;it != v.end(); it++)
				if((*it).getCnum() == num)
				{
					v.erase(it);
					return;
				}
			cout << "Khong tim thay";			
		}
		void updateWage()
		{
			int num;
			float newWage;
			cout << "\nSo ao cau thu can thay doi luong:";
			cin >> num;
			cout << "\nLuong moi:";
			cin >> newWage;
			vector<Cauthu>::iterator it = v.begin();
			for(;it != v.end(); it++)
				if((*it).getCnum() == num)
				{
					(*it).getWage(newWage);
					return;
				}
			cout << "Khong tim thay cau thu so ao da nhap!";			
		}
		void inListCauthu()
		{
			int n;
			cout << "So cau thu:";
			cin >> n;
			for(int i = 0; i < n; i++)
				Add();
		}
		void outInfCauthu()
		{
			int num;
			cout << "So ao cau thu can in:\n";
			cin >> num;
			vector<Cauthu>::iterator it = v.begin();
			for(;it != v.end(); it++)
				if((*it).getCnum() == num)
				{
					(*it).out();
					return;
				}
			cout << "Khong tim thay";
		}
		void outListCauthu()
		{
			cout << "Danh sach cac cau thu cua cau lac bo \n";
			vector<Cauthu>::iterator it = v.begin();
			for(;it != v.end(); it++)
			{
				cout << "\n";
				(*it).out();	
			}	
		}	
};


int main()
{
	CauLacBo c;
	int choise;
	do{
		cout << "\n\t1. Them cau thu";
		cout << "\n\t2. Xoa cau thu";
		cout << "\n\t3. Cap nhat luong";
		cout << "\n\t4. Nhap danh sach cau thu";
		cout << "\n\t5. In thong tin 1 cau thu";
		cout << "\n\t6. In danh sach cau thu";
		cout << "\n\t7. Ket thuc";
		cout << "\nNhap 1 so tu 1..7 de chon chuc nang:";
		cin >> choise;
		switch(choise){
			case 1:
				c.Add();
				break;
			case 2:
				c.Delete();
				break;
			case 3:
				c.updateWage();
				break;
			case 4:
				c.inListCauthu();
				break;
			case 5:		
				c.outInfCauthu();
				break;
			case 6:
				c.outListCauthu();
				break;
		system("pause");
		}	
		
	}while(choise!=7);
}
