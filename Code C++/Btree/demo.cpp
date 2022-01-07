#include<bits/stdc++.h>
#include"btree.cpp"
using namespace std;
void print(bnode<int>*p)
{
	cout<<p->getElem()<<"\t";
}
int tong=0;
void tinhtong(bnode<int>*p){
	tong = tong + p->getElem();
}
int main()
{
	btree<int> b;
	bnode<int> *p;
	p = b.insert(0,10);
	p = b.insert(b.getroot(),30);
	b.insert(p,50);
	b.insert(p,40);
	p = b.insert(b.getroot(),20);
	b.insert(p, 60);
	cout<<"So nut cua cay:"<<b.size();
	cout<<"\n";
	b.preOrder(b.getroot(),print);
	cout<<"\n";
	b.inOrder(b.getroot(),print);
	cout<<"\n";
	b.postOrder(b.getroot(),print);
	
	b.postOrder(b.getroot(),tinhtong);
	cout<<"\nTong cac nut tren cay = "<<tong;
	b.remove(b.getroot()->getRight());
	cout<<"\nCay sau khi xoa: ";
	b.preOrder(b.getroot(),print);
	cout<<"\nSo nut cua cay:"<<b.size();
}
