#ifndef __sList_ite__cpp__
#define __sList_ite__cpp__
#include"snode.cpp"
template <class T>
class sList_ite{
	private:
		snode<T> *curr;
	public:
		sList_ite(snode<T> *c=0) {
			curr = c;
		}
		snode<T> *getCurr() {
			return curr;
		}
		sList_ite<T> &operator = (sList_ite<T> *it) {
			this->curr = it->getCurr();
			return *this;
		}
		T & operator *() {
			curr->getElem();
		}
		sList_ite<T> operator ++ (int) {
			curr = curr->getNext();
			return curr;
		}
		sList_ite<T> operator ++ () {
			sList_ite<T> it = curr;
			curr = curr->getNext();
			return it;
		}
		bool operator != (sList_ite<T> it) {
			return curr != it.getCurr();
		}
};
#endif