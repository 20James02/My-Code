//Kĩ thuật thêm Node p vào sau Node q
#include <iostream>

using namespace std;

//Nhập danh sách liên kết đơn các số nguyên
struct node {							//Khai báo cấu trúc Node
	int data;
	struct node *pNext;
};
typedef struct node NODE;

struct list {							//Khai báo danh sách liên kết
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void createDSLK (LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *createNode (int x) {				//Khởi tạo node
	NODE *p = new NODE;
	if (p == NULL) {
		cout <<"\nKhong du bo nho cap phat!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addTofirst(LIST &l, NODE *p) {
	if(l.pHead == NULL) {
		l.pHead = l.pTail = p;

	} else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

 void addTofinal(LIST &l, NODE *p) {
 	if(l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		l.pTail->pNext = p;		
		l.pTail = p;
	}
 }

 void printList (LIST l)  {
 	for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
 		cout << k->data << " ";
 	}
 }

 //Thêm node q vào sau node p(Nằm trong list)
 void addTofree(LIST &l, NODE *p) {
 	int x;
 	cout <<"\nNhap gia tri node p: ";
 	cin >> x;
 	NODE *q = createNode(x);

 	if (q->data == l.pHead->data && l.pHead->pNext == NULL) {   //List chỉ chứa 1 node 
 		addTofinal(l, p);
 	} else {
 		for(NODE *k = l.pHead; k !=   NULL; k->pNext) {
 			if (p->data == k->data) {
 				NODE *h = createNode(p->data); //Khởi tạo node h mới thêm vào sau q
 				NODE *g = k->pNext;   //Gán node nằm sau cho node g trỏ đến node sau q
 				h->pNext = g;   //Liên kết h đến node g
 				k->pNext = h;   //Liên kết q đến node h
 			}
 		}
 	}
 }

 //Menu

 void Menu(LIST &l) {
 	int select;
 	while (69) {
 		system ("cls"); //Xóa màn hình
 		cout << "\n\n\t\t==========Menu==========";
 		cout <<"\n\t 1. Them node vao danh sach";
 		cout <<"\n\t 2. Xuat danh sach lien ket don";
 		cout <<"\n\t 3. Them 1 node p vao sau node q";
 		cout <<"\n\t 0. Thoat";
 		cout << "\n\n\t\t==========End==========";

 		cout << "\nNhap lua chon: ";
 		cin >> select;
 		if (select < 0 || select > 3) {
 			cout << "\nLua chon k hop le!";
 			system ("pause");
 		}
 		if (select == 1) {
 			int x;
 			cout <<"\nNhap mot so nguyen: ";
 			cin >> x;
 			NODE *p =  createNode(x);
 			addTofinal(l, p);
 		} 
 		else if (select == 2) {
 			printList(l);
 		} else if (select == 3) {
 			int x;
 			cout << "\nNhap gia tri node p can them vao sau: ";
 			cin >> x;
 			NODE *p = createNode(x);	//Khởi tạo node p
 			addTofree(l, p);          //Thêm node p vào sau node q
 		}
 		else {
 			break;
 		}
 	}
 }


int main() {
		LIST l;
		createDSLK(l); //Luôn khởi tạo trước khi thao tác vs list
		Menu(l);
	return 0;
}