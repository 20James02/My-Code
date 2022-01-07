#include <bits/stdc++.h>
using namespace std;

class Sach
{
private:
    string sCode;
    string sName;
    string autName;
    int sYear;

public:
    Sach()
    {
        sCode = "";
        sName = "";
        autName = "";
        sYear = 1900;
    }
    Sach(const string &sCode, const string &sName, const string &autName, const int &sYear)
    {
        this->sCode = sCode;
        this->sName = sName;
        this->autName = autName;
        this->sYear = sYear;
    }
    string getSname() const
    {
        return sName;
    }
    int getSyear() const
    {
        return sYear;
    }
    void nhap()
    {
        cout <<"\nNhap ma sach: "; 
        cin >> sCode;
        cin.ignore();
        cout <<"\nNhap ten sach: " ;
        getline(cin, sName);
        cin.ignore();
        cout <<"\nNhap ten tac gia: "; 
        getline(cin, autName);
        cout <<"\nNhap nam xuat ban: "; 
        cin >> sYear;
    }
    void xuat()
    {
        cout <<"\nMa sach: " << sCode; 
        cout <<"\nTen sach: "<< sName;
        cout <<"\nTen tac gia: " << autName;
        cout <<"\nNam xuat ban: " << sYear; 
    }
};
int main(int argc, char const *argv[])
{
    int n;
    cout << "\nNhap so dau sach: ";
    cin >> n;
    Sach *s;
    s = new Sach[n];
    for (int i = 1; i <= n; i++)
    {
    	cout <<"\nNhap tt dau sach thu "<< i <<": ";
        s[i].nhap();
    }
    string srchName;
    cout << "\nNhap ten sach can tim: ";
    getline(cin, srchName);
    int found = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i].getSname() == srchName)
        {
            found = i;
            break;
        }
    }
    if (found != -1)
    {
        cout << "\nTim thay sach co ten " << srchName;
        s[found].xuat();
    }
    else
    {
        cout <<"\nKhong tim thay sach co ten " << srchName;
    }
    cout <<"\nDanh sach cac sach xuat ban truoc nam 2000: ";
    for (int i = 1; i <= n; i++)
    {
        if (s[i].getSyear() < 2000)
        {
            cout <<"\nSTT " << i << ": ";
            s[i].xuat();
        }
    }
    delete[] s;
    return 0;
}
  
