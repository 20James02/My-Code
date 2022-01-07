#ifndef __snode__cpp__
#define __snode__cpp__
template <class T>
class snode {
	private:
		T elem;
		snode<T> *next;
	public:
		snode<T>() {
			next = 0;
		}
		snode<T> (T x, snode<T> *nex = 0) {
			elem = x;
			next = nex;
		}
		T & getElem() {
			return elem;
		}
		snode<T> *getNext() {
			return next;
		}
		void setElem(T x) {
			elem = x;
		}
		void setNext(snode<T> *nex = 0) {
			next = nex;
		}
};
#endif
