#ifndef __bnode__
#define __bnode__
template <class T>
class bnode{
	private:
		T elem;
		bnode<T> *parent;
		bnode<T> *left;
		bnode<T> *right;
	public:
		bnode<T>()
		{
			parent = 0;
			left = 0;
			right = 0;
		}
		bnode<T> *getParent(){
			return parent;
		}
		bnode<T> *getLeft()
		{
			return left;
		}
		bnode<T> *getRight()
		{
			return right;
		}
		void setLeft(bnode<T> *p){
			left = p;
		}
		void setRight(bnode<T> *p){
			right = p;
		}
		void setParent(bnode<T> *p){
			parent = p;
		}
		bool hasLeft() {
			return left!=0;
		}
		bool hasRight(){
			return right!=0;
		}
		T getElem(){
			return elem;	
		}
		void setElem(T e){
			elem = e;
		}
	};
#endif
