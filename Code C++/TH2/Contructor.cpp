#include <iostream>
using namespace std;

class CRectangle {
		int nHeight;
		int nWidth;
	public:
		CRectangle();
		int Area();
		void Init(int, int);
		~CRectangle();
};

CRectangle::CRectangle() {
	cout <<"Khoi tao cac thuoc tinh cua ham constructor\n";
	nHeight = 6;
	nWidth = 8;
}

int CRectangle::Area() {
	return nHeight*nWidth;
}

void CRectangle::Init(int Rong, int Dai) {
	cout <<"Khoi tao HCN voi cac bien duoc dua vao\n";
	nWidth = Rong;
	nHeight= Dai;
}
CRectangle::~CRectangle() {
	cout <<"Destructor dang duoc goi\n";
}

int main() {
	CRectangle Box, Square;
	cout<<"Dien tich cua Box la: "<<Box.Area() << "\n";
	cout<<"Dien tich cua Square la: "<< Square.Area() << "\n";
	Box.Init(12, 8);
	Square.Init(8, 8);
	cout<<"Dien tich cua Box la: "<< Box.Area() <<"\n";
	cout<<"Dien tich cua Square la: "<< Square.Area() <<"\n";
}

