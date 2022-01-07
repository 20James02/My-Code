/*
Xây dựng lớp DaThuc (Đa thức), trong đó có các thuộc tính (private) gồm: Bậc của đa thức và các hệ số xác định đa thức và các hàm (public): Hàm tạo; Hàm nhập một đa thức; Hàm xuất lên màn hình các hệ số của đa thức theo dạng (a0  a1  a2  …  an); Hàm cộng hai đa thức cùng bậc.
Viết chương trình:
1. Nhập hai đa thức P(x) và Q(x) cùng có bậc n
2. Tính giá trị các hệ số của đa thức P(x)+Q(x).
3. In lên màn hình các hệ số của đa thức tổng trên.
*/

#include<bits/stdc++.h>
using namespace std;

class DaThuc {
private:
    int bac;
    float *a;
public:
    DaThuc() {
        bac = 0;
        a = NULL;
    }
    friend istream &operator>>(istream &is, DaThuc &z) {
        cout <<"Nhap bac cua da thuc: ";
        is >> z.bac;
        z.a = new float[z.bac+5];
        for(int i=0; i<=z.bac; i++) {
            cout <<"Nhap he so bac " << i << ": ";
            is >> z.a[i];
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, DaThuc z) {
        for(int i=0; i<=z.bac; i++) {
            os << z.a[i] << "\t";
        }
        return os;
    }
    DaThuc cong(DaThuc z) {
        DaThuc tong;
        tong.bac = z.bac;
        tong.a = new float[tong.bac+5];
        for(int i=0; i<=z.bac; i++) {
            tong.a[i] = z.a[i]+a[i];
        }
        return tong;
    }
};
int main() {
    DaThuc P, Q;
    cout <<"Nhap da thuc P: \n";
    cin >> P;
    cout <<"Nhap da thuc Q: \n";
    cin >> Q;
    DaThuc Z = P.cong(Q);
    cout <<"He so cua da thuc P+Q la: \n";
    cout << Z;
}