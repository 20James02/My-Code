#include <iostream>
#include <string.h>
using namespace std;
class Cstring {
		char* strName;
	public:
		Cstring(char* str) {
			int size = strlen(str);
			strName = new char[size + 1];
			strcpy(strName,str):
		}
		void Display() {
			cout << strName << endl;
			cout <<"Chieu dai cua chuoi = "<< strlen(strName) << endl;
		}
		~CString() {
			delete [] strName;
		}
};

int main() {
	Cstring strFirst("Chao cac ban");
	Cstring strSecond("Chao tam biet");
	strFirst.Display();
	strSecond.Display();
}