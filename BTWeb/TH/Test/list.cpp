#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *pNext;
};
typedef struct node NODE;
struct list {
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void createList (LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE createNode (int x) {
	NODE *p = new NODE;
	if (p == NULL) {
		cout <<"Het bo nho!";
		return NULL;
	} 
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addTofirst (lIST &l, NODE *p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void outList (LIST &l) {
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data <<" ";
	}
}
int main() {
	LIST s;
	createList(s);
	int n;
	cout <<"\nSo phan tu muon nhap";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		NODE *p = createNode(a);
		addTofirst(s, p);
	}
	cout <<"\nDanh sach vua nhap la: ";
	outList(s);
	return 0;

}