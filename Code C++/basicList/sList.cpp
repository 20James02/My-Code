#ifndef __sList__cpp__
#define __sList__cpp__
#include"snode.cpp"
#include"sList_ite.cpp"
template <class T>
class sList {
	private:
		snode<T> *head;
		snode<T> *trail;
		int num;
	public:
		sList<T>() {
			head = trail = 0;
			num = 0;
		}
		sList<T>(int n, T x) {
			head = trail = 0;
			num = 0;
			while(--n)
				push_back(x);
		}
		bool empty() {
			return num == 0;
		}
		int size() {
			return num;
		}
		T & front() {
			return head->getElem();
		}
		T & back() {
			return trail->getElem();
		}
		void push_front(T x) {
			snode<T> *newNode = new snode<T>(x);
			if(!newNode)
				return;
			if(empty())
				head = trail = newNode;
			else {
				newNode->setNext(head);
				head = newNode;
			}
			num++;
		}
		void push_back(T x) {
			snode<T> *newNode = new snode<T>(x);
			if(!newNode)
				return;
			if(empty())
				head = trail = newNode;
			else {
				trail->setNext(newNode);
				trail = newNode;
			}
			num++;
		}
		void pop_front() {
			if(num == 1) {
				delete head;
				head = trail = 0;
			}
			else {
				snode<T> *p = head;
				head = head->getNext();
				delete p;
			}
			num--;
		}
		void pop_back() {
			if(num == 1) {
				delete head;
				head = trail = 0;
			}
			else {
				snode<T> *p;
				p = head;
				while (p->getNext()!=trail)
					p = p->getNext();
				delete trail;
				trail = p;
			}
			num--;
		}
		typedef sList_ite<T> iterator;
		iterator begin(){
			return sList_ite<T>(head);
		}
		iterator end(){
			return sList_ite<T>(0);
		}
		void insert(iterator it, T x) {
			if(it.getCurr()==trail)
				push_back(x);
			else {
				snode<T> *newNode = new snode<T>(x);
				newNode->setNext(it.getCurr()->getNext());
				it.getCurr()->getNext(newNode);
				num++;
			}
		}
		void erase(iterator it) {
			if(it.getCurr()==head)
				return pop_front();
			if (it.getCurr()==trail)
				return pop_back();
			snode<T> *p = head;
			while(p->getNext() != it.getCurr())
				p = p->getNext();
			p->setNext(it.getCurr()->getNext());
			num--;
		}
};
#endif