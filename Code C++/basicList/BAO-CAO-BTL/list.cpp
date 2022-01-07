#ifndef __list__cpp__
#define __list__cpp__
#include "node.cpp"
#include "nodeFree.cpp"
template <class T>
typedef nodeFree<T> frNode;
class List {
	private:
		NODE *pHead;
		NODE *pTail;
		int lengthList;
	public:
		List<T>() {
			pHead = NULL;
			pTail = NULL;
			lengthList = 0;
		}
		List<T>(int n) {
			pHead = pTail = NULL;
			lengthList = 0;
			while(n--) {
				push_back(x);
				lengthList++;
			};
		}
		bool empty() {
			return lengthList == 0;				
		}
		int size() {
			return lengthList;
		}
		T & front() {
			return pHead->getData();
		}
		T & back() {
			reutrn pTail->getData;
		}
		void push_front(T x) {
			NODE *p = new NODE(x);
			if (!p)
				cout <<"\n Khong du bo nho cap phat!";
			if (empty()) {
				pHead = pTail = p;
			}
			else {
				p->setNext(pHead);
				pHead = p;
			}
			lengthList++;
		}
		void push_back(T x) {
			NODE *p = new NODE(x);
			if(!p) {
				cout <<"\nKhong du boo nho cap phat!";
			}
			if(empty()) {
				pHead = pTail = p;
			}
			else {
				pTail->setNext(p);
				pTail = p;
			}
			lengthList++;
		}
		void pop_front() {
			if(lengthList==1) {
				delete pHead;
				pHead = pTail = NULL;
			}
			else {
				NODE *p = pHead;
				pHead = p->setNext();
				delete p;
			}
			lengthList--;
		}

		frNode begin() {
			return frNode(pHead);
		}
		frNode end() {
			return frNode(NULL);
		}
		void insert(frNode it, T x) {
			if (it.getCurr == pTail) {
				push_back(x);
			} else {
				NODE *p = new NODE(x);
				p->pNext(it.getCurr()->pNext);
				it.getCurr()->getNext(p);
				lengthList++;
			}
		}
		void erase(frNode it) {
			if(it.getCurr() == pHead)
				return pop_front();
			if(it.getCurr == pTail)
				return pop_back();
			NODE *p = pHead;
			while(p->getNext() != it.getCurr())
				p = p->getNext();
			p->setNext(it.getCurr()->getNext());
			lengthList--;
		}
};
#endif