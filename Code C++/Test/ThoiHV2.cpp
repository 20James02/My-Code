#include <bits/stdc++.h>
using namespace std;

class Subject {
private:
    string codeSub;
    string nameSub;
    int numTerm;

public:
    Subject() {
        codeSub = "";
        nameSub = "";
        numTerm = 0;
    }

    Subject (const string &codeSub, const string &nameSub, const int &numTerm) {
        this->codeSub = codeSub;
        this->nameSub = nameSub;
        this->numTerm = numTerm;
    }

    void nhap() {
        cout << "\nNhap ma mon hoc:";
        getline(cin, codeSub);
        cout << "\nNhap ten mon hoc";
        cin.ignore();
        getline(cin, nameSub);
        cout << "\nNhap so tin chi: ";
        cin >> numTerm;
    }

    void xuat() {
        cout << "\nMa mon hoc: " << codeSub;
        cout << "\nTen mon: " << nameSub;
        cout << "\nSo tin chi: " << numTerm;
    }

    int getNumTerm() const {
        return numTerm;
    }

    string getCodeSub() {
        return codeSub;
    }
};
class DKHP {
    private:
        string codeSV;
        string nameSV;
        int numSub;
        Subject *sub;

    public:
        DKHP() {
            codeSV = "";
            nameSV = "";
            numSub = 0;
            sub = nullptr;
        }

        DKHP(const string &codeSV, const string &nameSV, const int &numSub, Subject *sub) {
            this->codeSV = codeSV;
            this->nameSV = nameSV;
            this->numSub = numSub;
            sub = new Subject[numSub];
            for (int i = 1; i <= numSub; i++) {
                this->sub[i] = sub[i];
            }
        }

        void nhap() {
                cout << "\nNhap ma sinh vien: ";
                getline(cin, codeSV);
                cout << "\nNhap ten sinh vien: ";
                cin.ignore();
                getline(cin, nameSV);
                cout << "\nNhap so mon dang ky: ";
                cin >> numSub;
                cout << "\nNhap danh sach cach mon: ";
                for (int i = 1; i <= numSub; i++) {
                    this->sub[i].nhap();
                }
            }

        int getSumTerm() {
                int sum = 0;
                for (int i = 1; i <= numSub; i++) {
                    sum += sub[i].getNumTerm();
                }
                return sum;
            }

        bool searchSub(const string &codeSub) {
                bool found = false;
                for (int i = 1; i <= numSub; i++) {
                    if (sub[i].getCodeSub() == codeSub)
                    {
                        found = true;
                        break;
                    }
                }
                return found;
            }
    };


int main(int argc, char const *argv[]) {
    int m;
    cout << "\nNhap so mon hoc: ";
    cin >> m;
    Subject *sub = new Subject[m];
    for (int i = 1; i <= m; i++) {
        sub[i].nhap();
    }
    int n;
    cout << "\nNhap so sinh vien: ";
    cin >> n;
    DKHP *sv = new DKHP[n];
    cout << "\nNhap danh sach dang ky hoc phan cua " << n << " sinh vien:";
    for (int i = 1; i <= n; i++) {
        sv[i].nhap();
    }
    cout << "\nTong so tin chi da dang ky cua tung sinh vien: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << "\nSinh vien thu " << i << ": " << sv[i].getSumTerm();
    }
    string codeSub;
    cin.ignore();
    cout << "\nNhap vao ma mon hoc can tim: ";
    getline(cin, codeSub);
    int soSVDK = 0;
    for (int i = 1; i <= n; i++) {
        if (sv[i].searchSub(codeSub)) {
            soSVDK += 1;
        }
    }
    cout << "\nSo sinh vien dang ky mon hoc co ma mon hoc " << codeSub << " la " << soSVDK << endl;
    delete[] sub;
    return 0;
}
