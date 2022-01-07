#ifndef __btree__
#define __btree__
#include"bnode.cpp"
template <class T>
class btree{
	private:
		bnode<T> *root;
		int n; //So nut cua cay
	public:
		btree<T>(){
			root = 0;
			n = 0;
		}
		bnode<T> *getroot(){
			return root;
		}
		int size(){
			return n;
		}
		int isEmpty(){
			return root==0;
		}
		bool isInternal(bnode<T> *p)
		{
			return p->hasLeft() || p->hasRight();
		}
		bool isExternal(bnode<T> *p)
		{
			return (!p->hasLeft()) && (!p->hasRight());
		}
		bool isRoot(bnode<T> *p){
			return p->getParent()==0;
		}
		void preOrder(bnode<T> *p, void (*visit) (bnode<T> *))
		{
			if(p!=0)
			{
				visit(p);
				preOrder(p->getLeft(), visit);
				preOrder(p->getRight(), visit);			
			}
		}
		void inOrder(bnode<T> *p, void (*visit)(bnode<T> *))
		{
			if(p!=0)
			{				
				inOrder(p->getLeft(), visit);
				visit(p);
				inOrder(p->getRight(), visit);			
			}	
		}
		void postOrder(bnode<T> *p, void (*visit)(bnode<T> *))
		{
			if(p!=0)
			{				
				postOrder(p->getLeft(), visit);			
				postOrder(p->getRight(), visit);	
				visit(p);		
			}
		}
		bnode<T> *insert(bnode<T> *parent, T e)
		{
			bnode<T> *newnode = new bnode<T>();
			newnode->setElem(e);
			if(parent==0)
			{
				root = newnode;
				n++;
				return newnode;
			}
			else
			{
				newnode->setParent(parent);
				if(parent->getLeft()==0)
				{			
					parent->setLeft(newnode);
					n++;
					return newnode;
				}
				else
					if(parent->getRight()==0)
					{
					
						parent->setRight(newnode);
						n++;
						return newnode;
					}	
					else
						delete newnode;				
			}	
			
		}
		void remove(bnode<T> *p)
		{
			if(p!=0)
			{
				if(p->getLeft()!=0)
					remove(p->getLeft());
				if(p->getRight()!=0)
					remove(p->getRight());
				if(p->getParent()!=0)
				{
					if(p==p->getParent()->getLeft())
						p->getParent()->setLeft(0);
					else
						p->getParent()->setRight(0);					
				}
				else
					root = 0;
				delete p;
				n--;
			}
		}
};


#endif
