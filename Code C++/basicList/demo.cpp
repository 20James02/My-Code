#include<iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;

//Khai báo cấu trúc Node
typedef struct node {
	int data;
	node *pNext;
} NODE;

//Khởi tạo Node
NODE* createNode(int a) {
	NODE *p = new NODE;
	if(p == NULL) 
		cout <<"Khong du bo nho cap phat!";
	else {
		p->data = a;
		p->pNext = NULL;
	}
	return p;
}

//Tạo lớp List
class List {
	private:
		NODE *pHead;								//Khai báo con trỏ đầu
		NODE *pTail;								//Khai báo con trỏ cuối
		int lengthList;								//Khai báo biến lưu số lượng phần tử
	public:
		List() {									//Hàm tạo không đối
			pHead = NULL;
			pTail = NULL;
			lengthList = 0;
		}
		NODE *getHead() {							//Lấy con trỏ đầu
			return pHead;
		}
		void setSize(int n) {						//Thiết  số lượng phần tử
			lengthList = n;
		}
		int size() {								//Lấy số lượng phần tử
			return lengthList;
		}
		bool empty() {								//Kiểm tra danh sách rỗng 
			return lengthList == 0;
		}
		void push_front(int a) {					//Thêm 1 phần tử có giá trị a vào đầu danh sách
			NODE *p = createNode(a);
			if(pHead == NULL) {
				pHead = pTail = p;
			}
			else {
				p->pNext = pHead;
				pHead = p;
			}
			lengthList++;
		}
		void push_back(int a) {						//Thêm 1 phần tử có giá trị a vào cuối danh sách
			NODE *p = createNode(a);
			if(pHead == NULL) {
				pHead = pTail = p;
			}
			else {
				pTail->pNext = p;
				pTail = p;
			}
			lengthList++;
		}
		void pop_front() {							//Lấy phần tử ở đầu ra khởi danh sách
			if(lengthList == 1) {
				delete pHead;
				pHead = pTail = NULL;
			}
			else {
				NODE *p = pHead;
				pHead = p->pNext;
				delete p;
			}
			lengthList--;
		}
		void pop_back() {							//Lấy phần tử ở cuối ra khởi danh sách
			if(lengthList == 1) {
				delete pHead;
				pHead = pTail = NULL;
			} else {
				NODE *p = pHead;
				while (p->pNext->pNext !=NULL) {
					p = p->pNext;
				}
				delete (p->pNext);
				p->pNext = NULL;
				pTail = p;
			}
			lengthList--;
		}
		int front() {								//Truy xuất đến giá trị của phần tử 
			return pHead->data;
		}
		int back() {								//Truy xuất đến giá trị của phần tử cuối
			return pTail->data;
		}	
};

//Hàm xóa 1 phần tử ở vị trí t  
void deleteElem(List &l, int t) {
	NODE *p = l.getHead();
	for(int i = 1; i <= t; i++) {
		p = p->pNext;
	}
	NODE *temp = p->pNext;
	p->pNext = p->pNext->pNext;
	delete(temp);
}

//Hàm xuất danh sách
void xuat(List l) {
	cout << "\nDanh sach hien tai la: ";
	NODE *k = l.getHead();
	for (int i = 1; i <= l.size(); i++) {
		cout << k->data <<"\t";
		k = k->pNext;
	}
}

//Hàm xóa các phần tử có giá trị trùng nhau ( chỉ giữ lại phần tử đứng trước )
void deleteSameElem(List &l) {
	NODE *h = l.getHead();
	NODE *k = h->pNext;
	for (int i = 1; i < l.size(); i++) {
		for(int j = i+1; j <= l.size(); j++) {
			if(h->data == k->data) {
				deleteElem(l, j);
				l.setSize(l.size() - 1);
			}
			k = k->pNext;
		}
		h = h->pNext;
	}
}

//Hàm thêm 1 phần tử vào vị trí bất kì
void addElem(List &l, int a, int n) {
	if(n < 1 || n > l.size()+1) {
		cout <<"\nVi tri can chen khong hop le!";
		return;
	}
	if(l.empty()) {
		cout<<"\nDanh sach trong!";
		return;
	}
	
	if(n == 1)
		l.push_front(a);
	if(n == l.size() + 1)
		l.push_back(a);
	 else {
	 	n = n -2;
		NODE *k = l.getHead();
		while(n--) {
			k = k->pNext;
		};	
		NODE *q = createNode(a);
		q->pNext = k;
		NODE *g = k->pNext;
		k->pNext = q;
		q->pNext = g;
	}
	l.setSize(l.size() + 1);
}

//Hàm đếm số phần tử 
int coutElem(List &l, int x) {
	int count = 0;
	for(NODE *k = l.getHead(); k !=NULL; k = k->pNext) {
		if(x == k->data) {
			count++;
		}
	}
	return count;
}

// Hàm kiểm tra 3 số chẵn dương liên tiếp
void checkEvenNum(List &l) {
	int a = 0;
	NODE *k = l.getHead();
	for(int i = 1; i < l.size(); i++) {
		if(a == 3) {
			cout <<"\nVi tri 3 phan tu chan duong lien tiep la: " << i-2 << i-1 << i;
			break;
		}
		if(k->data > 0 && k->data % 2 == 0) {
			a++;
		} else a = 0;
	}
	if(a != 3) {
		cout<<"\nKhong co 3 so chan duong lien tiep trong danh sach.";
	}
	system("pause");
}

//Hàm sắp xếp danh sách theo thứ tự tăng dần
void sortList(List &l) {
	for(NODE *temp1 = l.getHead(); temp1 != NULL; temp1 = temp1->pNext) {
		for(NODE *temp2 = temp1->pNext; temp2 != NULL; temp2 = temp2->pNext) {
			if(temp1->data > temp2->data) {
				int temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
		}
	}
}

//Menu lựa chọn
void Menu(List &l) {
	int select;
	while(69) {
		system("cls");
		cout <<"\n\n\t\t==========Menu==========";
		cout <<"\n\t1. Nhap danh sach.";
		cout <<"\n\t2. Them 1 phan tu vao danh sach.";
		cout <<"\n\t3. Dem so phan tu co gia tri can tim.";
		cout <<"\n\t4. Kiem tra 3 so chan duong lien tiep.";
		cout <<"\n\t5. Sap xep danh sach theo thu tu tang dan.";
		cout <<"\n\t6. Xoa tat ca cac so nguyen to co trong danh sach";
		cout <<"\n\t7. Xoa cac phan tu co gia tri trung nhau chi giu lai 1 phan tu.";
		cout <<"\n\n\t\t==========END==========";
		cout << endl;
		xuat(l);
		cout <<"\nNhap lua chon: ";
		cin >> select;
		if(select < 0 || select > 8) {
			cout <<"\nLua chon khong hop le!";
			system("pause");
		}
		else if(select == 1) {
			cout <<"\nNhap danh sach: ";
			int i = 1;
			while(96) {
				string a;
				cout <<"\nNhap phan tu thu "<< i <<": ";
				cin >> a;
				if(a == "#") {
					break;
				} else {
					l.push_back(atoi(a.c_str()));
					i++;
				}
			};
		}
		else if (select == 2) {
			int n, a;
			cout <<"\nNhap vi tri can them: ";
			cin >> n;
			cout <<"\nNhap gia tri phan tu can them: ";
			cin >> a;
			addElem(l, a, n);
		}
		else if (select == 3) {
			int x;
			cout <<"\nNhap gia tri can dem: ";
			cin >> x;
			cout <<"\nDanh sach co " << coutElem(l, x) <<" phan tu co gia tri " << x <<".";
			system("pause");
		}
		else if (select == 4) {
			checkEvenNum(l);
		}
		else if (select == 5) {
			sortList(l);
		}
		else if (select == 6) {
			NODE *k = l.getHead();
			for(int i = 1; i <= l.size(); i++) {
				for(int j = 2; j < sqrt(k->data); j++) {
					if(k->data % j == 0)
						deleteElem(l, i);
				}
				k = k->pNext;
			}
		}
		else if (select == 7) {
			deleteSameElem(l);
		} else {
			break;
		}
	};
}
// Hàm chính
int main(){
	List l;
	Menu(l); 
	return 0;
}
