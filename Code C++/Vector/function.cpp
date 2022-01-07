#include <iostream> 
using namespace std;
#include <vector>

/*
resive();							Setup số lượng phần tử của mảng
at(i);								Truy xuất đến phần tử thứ i
push_back(i);						Thêm 1 phần tử có giá trị i vào cuối
pop_back();							Xóa phần tử ở cuối 
front();							Truy xuất đến phần tử đầu tiên
back();								Truy xuất đến phần tử cuối cùng
capacity()							Kich thước thực của mảng
erase(arr.begin() + 2);				Xóa đi 1 phần tử tại vị trí số 
insert(ar.begin() + 2, 69);			Thêm phần tử có giá trị 69 vào vị trí trí số 2
clear();							Xóa toàn bộ các phần tử hiện có trong mảng
swap(x);							Hoán đổi 2 mảng arr và x cho nhau
*/


//Hàm xuất mảng 
void outVector(vector(int) arr) {
	for (int i = 0; i < ar.size(); i++) {
		cout  << arr.at(i);			//In phần tử thứ i của mảng vector arr
	}
}
int main() {

	vector<int> arr;
	vector<int> x;
	for (int i = 1; i < 5; i++) {
		arr.push_back(i);
	}
	cout <<"\nXuat mang: ";
	outVector(arr);
	cout <<"\nKinh thuoc thuc cua mang arr: " << arr.capacity();
	system("pause");
	reuturn 0;
}