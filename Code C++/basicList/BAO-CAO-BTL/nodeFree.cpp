#ifndef __nodeFree__cpp__
#define __nodeFree__cpp__
#include "node.cpp"
template <class T>

class nodeFree {
	private:
		NODE *curr;
	public:
		
		nodeFree(NODE *p = NULL) {
			curr = p;
		}
		NODE *getCurr() {
			return curr;
		}
		frNodev & operator = (frNode *it) {
			this->curr = it->getCurr();
			return *this;
		}
		T & operator *() {
			curr->getData();
		}
		frNode operator ++ (int) {
			curr = curr->getNext();
			return curr;
		}
		frNode operator ++ () {
			frNode it = curr;
			curr = curr->getNext();
			return it;
		}
		bool operator != (frNode it) {
			return curr != it.getCurr();
		}
};
#endif