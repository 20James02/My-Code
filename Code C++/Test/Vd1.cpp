#include <iostream>
using namespace std;
class PS {
int ts, ms;
public:
void nhap();
void xuat() { cout<<ts<<"/"<<ms; }
PS nhan(PS p);
PS cong(PS p);
};



void PS::nhap() {
cout<<"\nTu so, mau so: ";
cin>>this->ts>>this->ms;
}
PS PS::nhan(PS p) {
PS t;
t.ms= this->ms * p.ms;
t.ts= this->ts * p.ts;
return t;
}
PS PS::cong(PS p) {
PS t;
t.ms= ms * p.ms;
t.ts= ts * p.ms + ms*p.ts;
return t;
}
int main() {
PS p1, p2, p3, p4;
p1.nhap();
p2.nhap();
p3= p1.nhan(p2);
cout<<"\nTich hai phan so: ";
p3.xuat();
p4= p1.cong(p2);
cout<<"\nTong hai phan so: ";
p4.xuat();
}