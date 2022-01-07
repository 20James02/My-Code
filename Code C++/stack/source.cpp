//Khởi tạo cấu trúc stack
/*
1. Push thêm 1 đối tượng vào đầu stack (cơ chế FIFO)
2. Pop lấy phần tử đầu stack và trả về giá trị đầu stack đồng thời hủy nó đi
3. Top xem thông tin phần tử ở đầu 
4. IsEmpty kiểm tra ngăn xếp 
*/

#include <iostream>
using namespace std;

//Nhập danh sách chứa các số nguyên sau đó xuất ra màn hình
//Khai báo cấu trúc
struct node {
	int data;
	struct node *pNext;
};
typedef struct node NODE;

//Khai báo cấu trúc stack
struct stack {
	NODE *pTop;
};
typedef struct stack STACK;

//Khởi tạo stack
void createStack(STACK &s) {
	s.pTop = NULL;					//Khai báo con trỏ đầu trỏ tới NULL
}

//Kiểm tra list rỗng
bool IsEmpty(STACK s) {
	if(s.pTop == NULL)
		return true;
	return false;					//List có phần tử
}

//Khởi tạo 1 node
NODE *createNode(int x) {
	NODE *p = new NODE();			//Cấp bộ nhớ
	if (p == NULL) {
		cout <<"Khong du bo nho cap phat!";
		return NULL;
	}
	p->data = x;					//Gán giá trị data cho bằng x
	p->pNext = NULL;				//Con trỏ của node mới bằng NULL
	return p;
}
//Đặt giá trị vào stack
bool Push(STACK &s, NODE *p) {
	if (p == NULL)
		return false;
	if (IsEmpty(s) == true) {		//Nếu list chưa có phần tử		
		s.pTop = p;
	} else {
		p->pNext = s.pTop;   	//Cho con trỏ của p trỏ tới đầu stack
		s.pTop = p; 			//Cập nhật lại node đầu
	}
	return true;
}
//Lấy giá trị ở đầu ra khỏi Stack
bool Pop(STACK &s, int &x) {
	if(IsEmpty(s) == true) 
		return false;
	else {
		NODE *p = s.pTop;		//Khởi tạo con trỏ  p là node ở đầu 
		x = p->data;			//Lấy giá trị của node p
		s.pTop = s.pTop->pNext; //Cập nhật lại con trỏ đầu là node tiếp theo
		delete p;
	}
	return true;				//Lấy thành công giá trị
}
//Truy xuất đến giá trị ở đầu
bool Top(STACK &s, int &x) {
	if(IsEmpty(s) == true)
		return false;
	x = s.pTop->data;			//Lấy giá trị ở đầu 
	return true;
}
//Xuất Stack
void outStack (STACK s) {
	while(IsEmpty(s) == false) {
		int x;
		Pop(s, x);
		cout << x <<" ";
	}
	if (IsEmpty(s) == true) {
		cout <<"\nDanh sach dang rong";
	}
}

void inStack(STACK &s) {
	int select;
	while (true) {
		system("cls");
		cout <<"\n\n\t ==========Stack======== ";
		cout <<"\n\t 1. Them phan tu vao stack";
		cout <<"\n\t 2. Xuat danh sach stack ra";
		cout <<"\n\t 3. Xem thong tin phan tu o dau stack";
		cout <<"\n\t 0. Thoat";
		cout <<"\n\n\t ==========END==========";

		cout <<"\nNhap lua chon: ";
		cin >> select;
		if (select == 1){
			int x;
			cout <<"\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = createNode(x);
			Push(s, p);
		} else if (select == 2) {
			outStack(s);
			system("pause");
		}
		else if (select == 3) {
			int x;
			Top(s, x);
			cout <<"Phan tu o dau stack la: " << x;
			system("pause");

		} else 
			break;	
	}
}

int main() {
	STACK s;
	createStack(s);
	inStack(s);
	return 0;
}