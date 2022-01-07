#include <iostream>
using namespace std;
class CTime {
		int nHours, nMinutes, nSeconds;
	public:
		CTime();
		CTime(int h, int m, int s);
		void Display();
		void AddIt(CTime Time1, CTime Time2);
		~CTime();
};

CTime::CTime() {
	cout<< "Ham contructor mac dinh\n";
	nHours = nMinutes = nSeconds = 0;
}
CTime::CTime(int h, int m,  int s) {
	cout<<"Ham contructor voi ba doi so\n";
	nHours = h;
	nMinutes = m;
	nSeconds = s;
}

void CTime::Display() {
	cout<< nHours <<':'<< nMinutes <<':'<< nSeconds << endl;
}

void CTime::AddIt(CTime Time1, CTime Time2) {
	nHours = Time1.nHours + Time2.nHours;
	nMinutes = Time1.nMinutes + Time2.nMinutes;
	nSeconds = Time1.nSeconds + Time2.nSeconds;
	if(nSeconds >= 60) {
		nSeconds -= 60;
		nMinutes++;
	}
	if (nMinutes >= 60) 
	{
		nMinutes -= 60;
		nHours++;
	}
}

CTime::~CTime() {
	cout<<"Ham destructor\n";
}

int main() {
	CTime Result;
	CTime T1(1, 49, 50);
	CTime T2(3, 40, 30);
	Result.AddIt(T1, T2);
	cout<<"Ket qua la: ";
	Result.Display();
}