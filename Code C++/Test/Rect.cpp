#include<iostream>
using namespace std;
class Rect {
	float width, height;
public:
	Rect(float width, float height);
	Rect() { }
	float area();
	int isSquare();
	void input();
};

Rect::Rect(float width, float height) {
	this->width= width;
	this->height= height;
}
	float Rect::area() {
		return width*height;
}
int Rect::isSquare() {
	if(width==height)
		return 1;
	else return 0;
}
void Rect::input() {
	cout<<"\nNhap hai canh: ";
	cin>>width>>height;
}
int main() {
	Rect rect(3,5), r[100];
	cout<<"Dien tich = "<<rect.area();
	int n, i, nSquare=0;
	float maxSquare=0;
	cout<<"\nSo hinh: ";
		cin>>n;
	for(i=1; i<=n; ++i) {
		r[i].input();
		if(r[i].isSquare())
	{
	nSquare++;
	if(r[i].area() > maxSquare)
		maxSquare = r[i].area();
	}
}
	cout<<"\nSo hinh vuong = "<<nSquare;
	if(nSquare > 0)
		cout<<"\nDien tich hinh vuong max = "<<maxSquare;
}