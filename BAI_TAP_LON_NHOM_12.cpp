@@ -0,0 +1,380 @@
#include<iostream>
#include<iomanip>
#include<string.h>
#include<windows.h>
 
using namespace std;
struct doanhthu {
	string ngayban;
	int ngay, thang, nam;
	int tienmat, visa, momo, platfrom;
	int tong;
};
struct Ngay{
	doanhthu n;
    Ngay *next;
};
struct List {
    Ngay *pHead;
    Ngay *pTail;
};
doanhthu nhap() {
    doanhthu dt;
    bool trueNgayban = true;
	do {
        do {
            cout << "Ngay: ";
            cin >> dt.ngay;
        } while (dt.ngay < 1 || dt.ngay > 31);
        do {
            cout << "Thang: ";
            cin >> dt.thang;
        } while (dt.thang < 1 || dt.thang > 12);
        do {
            cout << "Nam: ";
            cin >>dt.nam;
        } while (dt.nam < 1 );
        if (dt.thang == 2) {
            if (dt.nam % 4 == 0 && dt.nam % 100 != 0 || dt.nam % 400 == 0) {
                if (dt.ngay > 29) {
                    trueNgayban = false;
                } else {
                     trueNgayban  = true;
                }
            } else {
                if (dt.ngay > 28) {
                    trueNgayban = false;
                } else {
                    trueNgayban = true;
                }
            }
        } else if (dt.thang == 4 || dt.thang == 6 || dt.thang == 9 || dt.thang == 11) {
            if (dt.ngay > 30) {
                trueNgayban = false;
            } else {
                trueNgayban = true;
            }
        } else {
            trueNgayban = true;
        }
    } while (! trueNgayban);
    dt.ngayban = "";
    if (dt.ngay < 10) {
        dt.ngayban += "0";
        dt.ngayban += dt.ngay + '0';
    } else {
        dt.ngayban += dt.ngay / 10 + '0';
       dt.ngayban += dt.ngay % 10 + '0';
    }
    dt.ngayban += "/";
    if (dt.thang < 10) {
        dt.ngayban += "0";
        dt.ngayban += dt.thang + '0';
    } else {
        dt.ngayban += dt.thang / 10 + '0';
        dt.ngayban += dt.thang % 10 + '0';
    }
    dt.ngayban += "/";
    dt.ngayban += dt.nam / 1000 + '0';
    dt.ngayban += dt.nam  / 100 % 10 + '0';
    dt.ngayban += dt.nam  / 10 % 10 + '0';
    dt.ngayban += dt.nam  % 10 + '0';
    cout<<"tien mat:";
	fflush(stdin);
	cin>>dt.tienmat;
	cout<<"visa:";
	fflush(stdin);
	cin>>dt.visa;
    cout<<"momo:";
	fflush(stdin);
	cin>>dt.momo;
	cout<<"platfrom:";
	fflush(stdin);
	cin>>dt.platfrom;
	dt.tong=(dt.tienmat+dt.visa+dt.momo+dt.platfrom);
	cout<<endl;
	return dt;
}
Ngay *createNgay () {
    Ngay *ngay = new Ngay;
    ngay->n = nhap();
    ngay->next = NULL;
    return ngay;
}
bool isEmpty (List *list) {
    if (list->pHead == NULL) {
        return true;
    }
    return false;
}
    List *createList () {
    List *list = new List();
    list->pHead = NULL;
    list->pTail = NULL;
    return list;
}
void addHead (List *&list) {
    Ngay *ngay = createNgay();
    if (list->pHead == NULL) {
        list->pHead = ngay;
        list->pTail = ngay;
        return;
    }
    ngay->next = list->pHead;
    list->pHead = ngay;
}
void addTail (List *&list) {
    Ngay *ngay = createNgay();
    if (list->pHead == NULL) {
        list->pHead = ngay;
        list->pTail = ngay;
        return;
    }
    list->pTail->next = ngay;
    list->pTail = ngay;
}
void deleteHead (List *&list) {
    if (isEmpty(list)) {
        cout << "Danh sach rong" << endl;
        return;
    }
    Ngay *ngay = list->pHead;
    list->pHead = list->pHead->next;
    delete ngay;
}
void deleteTail (List *&list) {
    if (isEmpty(list)) {
        cout << "Danh sach rong" << endl;
        return;
    }
    Ngay *ngay = list->pHead;
    while (ngay->next != list->pTail) {
        ngay = ngay->next;
    }
    delete list->pTail;
    list->pTail = ngay;
    ngay->next = NULL;
}
int countNgay(List *&list)
{
	int count =0 ;
	Ngay * ngay = list -> pHead;
	while (ngay != NULL)
	{
		count++;
		ngay = ngay -> next ;
	}
	return count ;
}
void insert ( List *&List, int pos )
{
	 Ngay * ngay = createNgay();
	 Ngay * temp = List -> pHead;
	 if  (pos==1 )
  {
	addHead(List);
	return;
  };
    
    if ( pos == countNgay(List)+1)
    {
    	addTail(List);
    	return;
	};
      if (pos > countNgay(List)+1)
	  {
	  	cout<<"Vi tri khong hop le "<<endl;
	  	return;
	   } ;
	   
     for ( int i =1 ; i < pos -1 ; i++)
	 {
	 	temp = temp -> next;
	 }
		ngay -> next = temp -> next ;
		temp -> next = ngay;
};

void xuat(doanhthu dt) {
    cout <<"Ngay ban:"<<setw(12) << left; 
    cout <<"Tien Mat:"<<setw(12) << left;
    cout <<"Visa:"<<setw(12) << left;
    cout <<"Momo:"<<setw(12) << left;
    cout <<"Platfrom:"<<setw(12) << left << endl;
	cout << setw(12) << left<< dt.visa;
	cout << setw(12) << left<< dt.momo;
	cout << setw(12) << left<< dt.platfrom;
	cout << setw(12) << left<< dt.tong;
	cout << setw(4) << right <<"*";
	cout << endl;
    cout << "*******************************************************************************\n";
}

void testingVisa(List *&list  )
{
	Ngay  *ngay = list-> pHead; 
	Ngay  *temp = list -> pHead;
	while ( ngay != NULL)
	  {
	  	temp = ngay -> next ;
	  while (temp !=NULL )
	  {
	  	if ( ngay ->n.visa < 100 )
	  	{
	  	   doanhthu tempInfo = ngay->n ;
	  	   ngay->n = temp -> n;
	  }
	  temp = temp -> next ;
}
   ngay = ngay -> next;
}
}
// xap xep doanh thu tang dan 
void sortListtang (List *&list) {
    Ngay *ngay = list->pHead;
    Ngay *temp = list->pHead;
    while (ngay != NULL) {
        temp = ngay->next;
        while (temp != NULL) {
            if (ngay->n.tong > temp->n.tong) {
                doanhthu tempInfo = ngay->n;
                ngay->n = temp->n;
                temp->n = tempInfo;
            }
            temp = temp->next;
        }
        ngay = ngay->next;
    }
}
 // xap xep doanh thu giam dan
 void sortListgiam (List *&list) {
    Ngay *ngay = list->pHead;
    Ngay *temp = list->pHead;
    while (ngay != NULL) {
        temp = ngay->next;
        while (temp != NULL) {
            if (ngay->n.tong < temp->n.tong) {
                doanhthu tempInfo = ngay->n;
                ngay->n = temp->n;
                temp->n = tempInfo;
            }
            temp = temp->next;
        }
        ngay = ngay->next;
    }
}

// tim kiem ngay co doanh thu nho nhat
void searchtongMin (List *list) {
    Ngay *ngay = list->pHead;
    Ngay *temp = list->pHead;
    while (ngay != NULL) {
        if (ngay->n.tong < temp->n.tong) {
            temp = ngay;
        }
        ngay = ngay->next;
    }
    printnhap(temp->n);
}

// tim kiem ngay co doanh thu cao nhat 
void searchtongMax (List *list) {
    Ngay *ngay = list->pHead;
    Ngay *temp = list->pHead;
    while (ngay != NULL) {
        if (ngay->n.tong > temp->n.tong) {
            temp = ngay;
        }
        ngay = ngay->next;
    }
    printnhap(temp->n);
}

void printList (List *list) {
    Ngay *ngay = list->pHead;
    cout << "Danh sach quan ly doanh thu: " << endl;
    while (ngay != NULL) {
        printnhap(ngay->n);
        ngay = ngay->next;
    }
}
void set_color ( int code)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( color , code);
};
int main() {
    List *list = createList();
    int choice;
    do { 
    set_color (10);
        cout << "=========================MENU=========================\n";
        set_color(0|15);
        cout << " 1. Them ngay vao dau danh sach quan ly doanh thu   " << endl;      
        cout << " 2. Them ngay vao cuoi danh sach quan ly doanh thu  " << endl;
        cout << " 3. Xoa ngay o dau danh sach quan ly doanh thu      " << endl;
        cout << " 4. Xoa ngay o cuoi danh sach quan ly doanh thu     " << endl;
        cout << " 5. Xap xep doanh thu tang dan                      " << endl;
        cout << " 6. Xap xep doanh thu giam dan                      " << endl;
        cout << " 7. Tim kiem ngay co doanh thu nho nhat             " << endl;
        cout << " 8. Tim kiem ngay co doanh thu cao nhat             " << endl;
        cout << " 9. In danh sach quan ly doanh thu                  " << endl;
        cout << " 10. Them ngay bat ki vao danh sach quan ly doanh thu"<< endl;
	    cout << "11. KIEM TRA VISA LON HON 100                       " << endl;
        cout << " 12. XUAT TXT                                       "  <<endl;
        cout << " 0. Thoat                                           " << endl; 
        set_color(10);
        cout << "======================================================\n";  
        set_color(14);
		cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addHead(list);
                break;
            case 2:
                addTail(list);
                break;
                case 3:
                deleteHead(list);
                break;
            case 4:
                deleteTail(list);
                break;
            case 5:
                sortListtang(list);
                break;
            case 6:
				sortListgiam(list);
				break;
			case 7:
			    searchtongMin(list);
				break;
			case 8:
			    searchtongMax(list);
				break;
			case 9:
			    printList(list);
				break;
			case 10: 
			     int pos;
			     cout<<"Nhap vi tri can them ";
			     cin>>pos;
				 insert(list,pos);
			     break;
			case 11:
			     testingVisa(list); 
				 break;	
			case 12 : 
			   ofstream GhiSo("Ghi So Chan Le.txt");
            case 0:
                cout << "Thoat chuong trinh" << endl;
                break;
            default:
                cout << "Nhap sai, vui long nhap lai" << endl;
                break;
        }
    } while (choice != 0);       

}
	