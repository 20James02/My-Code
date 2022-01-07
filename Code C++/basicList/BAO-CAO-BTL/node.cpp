#include <iostream>
using namespace std;
#ifndef __node__cpp__
#define __node__cpp__
typedef struct node {
	float data;
	node *pNext;
} NODE;
NODE* createNode(float a) {
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
		int lengthList = 0;
	public:
		List();
		List(List &l) {
			pHead = NULL;
			pTail = NULL;
		}
		~List();
		bool empty() {
			return lengthList == 0;
		}
		void push_front(List &l, float a) {
			NODE *p = createNode(a);
			if(l.pHead == NULL) {
				l.pHead = l.pTail = p;
			}
			else {
				p->pNext = l.pHead;
				l.pHead = p;
			}
			lengthList++;
		}
		void push_back(List &l, float a) {
			NODE *p = createNode(a);
			if(l.pHead == NULL) {
				l.pHead = l.pTail = p;
			}
			else {
				l.pTail->pNext = p;
				l.pTail = p;
			}
			lengthList++;
		}
		float front(List l) {
			return l.pHead->data;
		}
		float back(List l) {
			return l.pTail->data;
		}
		void xuat(List l) {
			cout << "\n Danh sach hien tai la: ";
			for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
				cout << k->data <<"\t";
			}
		}

};
#endif