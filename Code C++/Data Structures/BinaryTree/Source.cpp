#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *pLeft;
	struct node *pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

void createTree(TREE &t) {
	t = NULL;
}

void addNode(TREE &t, int x) {
	if(t == NULL) {
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	} else {
		if(t->data > x) {
			addNode(t->pLeft, x);
		} else if (t->data < x) {
			addNode(t->pRight, x);
		}
	}
}

void NLR (TREE t) {
	if (t != NULL) {
		cout << t->data << " ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

void menu(TREE &t) {
	while (true) {
		system("cls");
		cout <<"\n\n\t\t========== Menu ==========";
		cout <<"\n\t\t\t1. Nhap du lieu: ";
		cout <<"\n\t\t\t2. Xuat du lieu: ";
		cout <<"\n\t\t\t0. Ket thuc!";
		cout <<"=============================";

		int select;

		cout <<"\nNhap lua chon: ";
		cin >> select;
		if (select < 0 || select > 2) {
			cout <<"\nLua chon k hop le!";
			system("pause");
		} else if(select == 2) {
			cout <<"\nDuyet cay theo NLR: ";
			NLR(t);
		} else if (select == 1) {
			int x;
			cout <<"\nNhap gia tri can them: ";
			cin >> x;
			addNode(t, x);
		}
	}
	
}

int main() {
	NODE t;
	createTree(t);
	menu(t);
	system("pause");
	return 0;
}
