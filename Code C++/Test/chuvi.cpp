#include <iostream>
#include <cmath>
using namespace std;

class Diem {
	float x, y;
public:
	void nhap();
	float kc(Diem& d);	
};

void Diem::nhap() {
	cout <<"Nhap toa do: ";
	cin >> x >> y;
}
float Diem::kc(Diem& d) {
	return sqrt((x-d,x)*(x-d,x)+(y-d,y)*(y-d,y));
}
int main() {
	Diem d1, d2, d3;
	d1.nhap();
	d2.nhap();
	d3.nhap();
	float a, b, c;
	a = d1.kc(d2);
	a = d2.kc(d3);
	a = d3.kc(d1);
	cout << "Chu vi la: "<< a+b+c;
}