//Khởi tạo cấu trúc Queue
/*
1. IsEmpty kiểm tra Queue có rỗng hay k
2. Push thêm 1 đối tượng vào cuối Queue (cơ chế FIFO)
3. Pop lấy phần thử ở đầu ra khỏi Queue
4. Top Xem thông tin phần tử  ở đầu 
5. Front xem thông tin phần tử ở cuối
*/
#include <iostream>
using namespace std;

//Khai báo cấu trúc Node
struct node {
    int data;
    struct node *pNext;
};
typedef struct node NODE;

//Khai báo cấu trúc Queue
struct queue {
    NODE *pHead;
    NODE *pTail;
};
typedef struct queue QUEUE;

//Khởi tạo Queue
void createQueue (QUEUE &s) {
    s.pHead = NULL;
    s.pTail = NULL;
}

//Kiểm tra Queue rỗng
bool IsEmpty (QUEUE s) {
    if (s.pHead == NULL) 
        return true;
    return false;
}

//Khởi tạo node
NODE *createNode(int x) {
    NODE *p = new NODE();
    if (p == NULL) {
        cout <<"Khong du bo nho cap phat!";
        return NULL;
    } 
    p->data = x;
    p->pNext = NULL;
    return p;
}

//Đặt phần tử vào cuối Queue
bool Push (QUEUE &s, NODE *p) {
    if (p == NULL) 
        return false;
    if (IsEmpty(s) == true) {
        s.pHead = s.pTail = p;      
    } else {
        s.pTail->pNext = p;         
        s.pTail = p;               
    }
    return true;
}

//Lấy giá trị của phần tử đầu đồng thời xóa nó đi
bool Pop (QUEUE &s, int &x) {
    if(IsEmpty(s) == true) 
        return false;
    else {
        NODE *p = s.pHead;           
        x = p->data;                 
        s.pHead = s.pHead->pNext;    
        delete p;                    
    }
    return true;
}

//Truy xuất đến thông tin phần tử đầu
int Top(QUEUE &s) {
    if(IsEmpty(s) == true) {
        cout << "List rong";
    } else {
        int x;
        x = s.pHead->data;
        return x;
    }
    
}

//Truy xuất đến thông tin phần tử cuối 
int Front(QUEUE &s) {
    if(IsEmpty(s) == true){
        cout <<"List rong";
    } else {
        int x; 
        x = s.pTail->data;
        return x;
    }
}

//Xuất List
void outQueue(QUEUE s) {
    if(IsEmpty(s) == false) {
        while (IsEmpty(s) == false) {
            int x;
            Pop(s, x);
            cout << x <<" ";
        }
    }   
    else {
        cout << "Danh sach rong!";
    }
}

int main() {
    QUEUE s;
    createQueue(s);
    int n;
    cout<<"So phan tu muon nhap: ";
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        NODE *p = createNode(x);
        Push(s, p);
    }
    cout <<"\nDanh sach vua nhap la: ";
    outQueue(s);
    cout <<"\nPhan tu o cuoi la: " << Front(s);
    cout <<"\nPhan tu o dau la: " << Top(s); 
    return 0;
}

