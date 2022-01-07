#include<iostream>
#include<math.h>
using namespace std;

typedef struct node {
	int data;
	node *pNext;
} NODE;
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

class List {
	private:
		NODE *pHead;
		NODE *pTail;
		int lengthList;
	public:
		List() {
			pHead = NULL;
			pTail = NULL;
			lengthList = 0;
		}
		int size() {
			return lengthList;
		}
		bool empty() {
			return lengthList == 0;
		}
		void push_front(int a) {
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
		void push_back(int a) {
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
		void pop_front() {
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
		void pop_back() {
			if(lengthList == 1) {
				delete pHead;
				pHead = pTail = NULL;
			}
			lengthList--;
		}
		int front() {
			return pHead->data;
		}
		int back() {
			return pTail->data;
		}
		void deleteElem(int t) {
			NODE *p = pHead;
			for(int i = 1; i <= t; i++) {
				p = p->pNext;
			}
			NODE *temp = p->pNext;
			p->pNext = p->pNext->pNext;
			delete(temp);
		}
		void xuat() {
			cout << "\nDanh sach hien tai la: ";
			NODE *k = pHead;
			for (int i = 0; i < lengthList; i++) {
				cout << k->data <<"\t";
				k = k->pNext;
			}
		}
		void addElem(int a, int n);
		int coutElem(int x);
		void checkEvenNum();
		void deleteSameElem() {
			int n = 0, m = 0;
			for(NODE *temp1 = pHead; temp1 != NULL; temp1 = temp1->pNext) {
				n++;
				for(NODE *temp2 = temp1->pNext; temp2 != NULL; temp2 = temp2->pNext) {
					m++;
					if(temp1->data == temp2->data) {
						deleteElem(m);
					}
				}
			}
		}
		void sortList();
		void Menu();
}; 

void List::addElem(int a, int n) {
	if(n < 0 || n > lengthList) {
		cout <<"\nVi tri can chen khong hop le!";
		return;
	}
	if(empty()) {
		cout<<"\nDanh sach trong!";
		return;
	}
	
	if(n == 0)
		push_front(a);
	if(n == lengthList - 1)
		push_back(a);
	 else {
	 	n--;
		NODE *k = pHead;
		while(n--) {
			k = k->pNext;
		};	
		NODE *q = createNode(a);
		q->pNext = k;
		NODE *g = k->pNext;
		k->pNext = q;
		q->pNext = g;
	}
	lengthList++;
}
int List::coutElem(int x) {
	int count = 0;
	for(NODE *k = pHead; k !=NULL; k = k->pNext) {
		if(x == k->data) {
			count++;
		}
	}
	return count;
}

// Hàm kiểm tra 3 số chẵn dương
void List::checkEvenNum() {
	int a = 0;
	NODE *k = pHead;
	for(int i = 1; i < lengthList; i++) {
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
}
void List::sortList() {
			for(NODE *temp1 = pHead; temp1 != NULL; temp1 = temp1->pNext) {
				for(NODE *temp2 = temp1->pNext; temp2 != NULL; temp2 = temp2->pNext) {
					if(temp1->data > temp2->data) {
						int temp = temp1->data;
						temp1->data = temp2->data;
						temp2->data = temp;
					}
				}
			}
		}


void List::Menu() {
	int select;
	while(69) {
		system("cls");
		cout <<"\n\n\t\t==========Menu==========";
		cout <<"\n\t1. Nhap danh sach.";
		cout <<"\n\t2. Them 1 phan tu vao danh sach.";
		cout <<"\n\t3. Dem so phan tu co gia tri can tim.";
		cout <<"\n\t4. Kiem tra 3 so duong lien tiep.";
		cout <<"\n\t5. Sap xep danh sach theo thu tu tang dan.";
		cout <<"\n\t6. Xoa tat ca cac so nguyen to co trong danh sach";
		cout <<"\n\t7. Xoa cac phan tu co gia tri trung nhau chi giu lai 1 phan tu.";
		cout <<"\n\n\t\t==========END==========";
		cout << endl;
		xuat();
		cout <<"\nNhap lua chon: ";
		cin >> select;
		if(select < 0 || select > 8) {
			cout <<"\nLua chon khong hop le!";
			system("pause");
		}
		if (select == 1) {
			int x;
			cout <<"\nNhap danh sach: ";
			while(int(x)) {
				cin >> x;
				push_back(x);
			}
			cout <<"\nKet thuc nhap!";
		}
		else if (select == 2) {
			int n;
			int a;
			cout <<"\nNhap vi tri can them: ";
			cin >> n;
			cout <<"\nNhap gia tri phan tu can them: ";
			cin >> a;
			addElem(a, n);
		}
		else if (select == 3) {
			int x;
			cout <<"\nNhap gia tri can dem: ";
			cin >> x;
			cout <<"\nDanh sach co " << coutElem(x) <<" phan tu co gia tri " << x <<".";
		}
		else if (select == 4) {
			checkEvenNum();
		}
		else if (select == 5) {
			sortList();
		}
		else if (select == 6) {
			NODE *k = pHead;
			for(int i = 1; i <= size(); i++) {
				for(int j = 2; j < sqrt(k->data); j++) {
					if(k->data % i == 0)
						deleteElem(i);
				}
			}
		}
		else if (select == 7) {
			deleteSameElem();
		} else {
			break;
		}
	};
}
int main(){
	List l;
	l.Menu();
	return 0;
}
