#include <iostream>

using namespace std;
// Nhập danh sách liên kết đơn các số nguyên sau đó tìm mã trong danh sách
 
 struct node {    			//Khai báo Node
 	int data;
 	node *pNext;   			//Khai báo con trỏ
 };

 typedef struct node NODE;  //Thay thế truct node --> NODE

struct list {     			//Khai báo cấu trúc danh sach liên kết
	NODE *pHead;
	NODE *pTail;
};

typedef struct list LIST;

//Khởi tạo cấu trúc danh sách liên kết 
void create (LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//Khỏi tạo 1 node
NODE *createNODE(int x) {
	NODE *p = new NODE; 	//Cấp phát bộ nhớ cho NODE p
	if (p == NULL) {
		cout << "\nKhong du bo nho cap phat !";
		return NULL;
	}
	p->data = x;        	 //Truyền giá trị x vào data
	p->pNext = NULL;    	//Con trỏ node mới trỏ tới NULL
	return p;
}

//Thêm node vào đầu danh sách liên kết
void addTofirst(LIST &l, NODE *p) {
	if (l.pHead == NULL) {   //Danh sách rỗng
		l.pHead = l.pTail = p;
	} else {
		p->pNext = l.pHead;  //Cho con trỏ của node p liên kết đến đầu pHead
		l.pHead = p;        //Cập nhật lại pHead
	}
}

void addTofinal(LIST &l, NODE *p) {
	if (l.pHead == NULL) {   //Danh sách rỗng
		l.pHead = l.pTail = p;
	} else {
		l.pTail->pNext = p;  //Cho con trỏ của pTail liên kết với node p
		l.pTail = p;        //Cập nhật lại p là node pTail
	}
}
//Xuất dnah sách liên kết 
void printList(LIST l) {
	for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data <<" ";
	}
}
int main() {
	LIST l;
	create(l);
	int n;
	cout << "\nNhap so luong node can them: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cout << "\nNhap gia tri: ";
		cin >> x;
		NODE *p = createNODE(x);
		addTofirst(l, p);
	}
	cout<< "\nDanh sach lien ket: ";
	printList(l);
} 