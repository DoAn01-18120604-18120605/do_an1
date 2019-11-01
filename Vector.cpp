#include "Vector.h"

Vector::Vector()
{
	_len = 0; // do dai vector = 0
	_vt = new int[_len]; //cap phat dong cho con tro vt
}
Vector:: Vector(int len)
{
	_len = len;
	_vt = new int[_len];
}
Vector:: ~Vector()
{
	delete[]_vt; //giai phong vung nho cho con tro
}
void Vector::input()
{
	cout << "\tnhap so chieu cua vector: ";
	cin >> _len; // nhap so chieu vector
	cout << "\t\tnhap thanh phan cua  vector" << endl;
	//nhap tung thanh phan cua vector
	for (int i = 0; i < _len; i++)
	{
		cout << "\t\t\tv[" << i + 1<<"]: ";
		cin >> _vt[i];
	}
}
void Vector::output()
{
	cout << "(";
	// xuat cac thanh phan cua vector
	for (int i = 0; i < _len; i++)
	{
		cout << _vt[i] ;
		if (i <= _len - 2) 
		{
			cout << ",";
		}
	}
	cout << ")" << endl;
}
void Vector::addTo(Vector* other)
{
	Vector *vt =new  Vector(0) ; //khoi tao 1 vector rong
	if (_len != other->_len) //neu vector vua tao co so chieu khac voi vector ban dau
	{
		cout << "\t\t\tkhong the cong 2 vector" << endl; 
	}
	else //neu vector vua tao co so chieu giong voi vector ban dau
	{
		// cong tung thanh phan cua vector voi nhau
		for (int i = 0; i < _len; i++)
		{
			vt->_vt[i] = _vt[i] + other->_vt[i];
			vt->_len++;
		}
		cout << "\t";
		vt->output(); // xuat vector vua cong
	}
}


void Vector::multiTo(int alpha)
{
	//lay tung thanh phan cua vector nhan voi so alpha
	for (int i = 0; i < _len; i++)
	{
		_vt[i] = alpha * _vt[i];
	}
}
void menu(Vector* p)
{
	int choose; // bien de nguoi dung nhap lua chon
	while (1) //vong lap se dung khi nguoi dung nhap 0
	{
		system("cls"); // xoa man hinh sau moi lan lap
		cout << "\n\t\t======================================VECTOR======================================="<<endl;
		cout << "\n\t\t\t\t\t\t1. Nhap vector";
		cout << "\n\t\t\t\t\t\t2. Xuat vector";
		cout << "\n\t\t\t\t\t\t3. Cong 2 vector";
		cout << "\n\t\t\t\t\t\t4. Nhan vector voi 1 so alpha";
		cout << "\n\t\t\t\t\t\t0. Ve man hinh chinh"<<endl;
		cout << "\n\t\t===================================================================================" << endl << endl;
		cout << "NHAP LUA CHON CUA BAN: ";
		cin >> choose; // nguoi dung nhap lua chon
		if (choose == 1) // neu nhap 1 thi goi phuong thuc nhap vector
		{
			cout << endl;
			p = new Vector(0);
			p->input();
		}
		else if (choose == 2) //nhap 2 thi goi phuong thuc xuat vector
		{
			cout << endl;
			p->output();
			system("pause");
		}
		else if (choose == 3) //nhap 3 de cong 2 vector
		{
			cout << endl;
			Vector* a(p); // tao 1 vector sao chep vector  ban dau nhap vao de khi thuc hien cac lenh se khong lam thay doi vector ban dau
			cout << "\tvector ban dau ";
			cout << "\t";
			a->output(); // xuat vector vua tao
			cout << endl;
			Vector* vt1 = new Vector(0); // khoi tao 1 vector rong
			cout << "\tnhap vector" << endl;
			vt1->input(); // nhap vector vua khoi tao
			cout << "\tvector vua nhap\t";
			vt1->output(); // xuat vector vua nhap
			cout << "\ttong vector ban dau va vector ban vua nhap: ";

			a->addTo(vt1); // xuat ket qua cua phuong thuc cong 2 vector

			system("pause"); //dừng màn hình
			
		}
		else if (choose == 4) // nhap 4 de tinh tich vector voi 1 so alpha
		{
			cout << endl;
			Vector* a(p); //tao 1 vector sao chep vector  ban dau nhap vao de khi thuc hien cac lenh se khong lam thay doi vector ban dau
			cout << "\tvector ban dau:";
			cout << "\t";
			a->output(); //xuat vector vua sao chep
			cout << endl;
			int alpha; // bien luu so alpha
			cout << "\tnhap so alpha: ";
			cin >> alpha; // nhap so alpha
			cout << "\ttich vector ban dau voi so ban vua nhap: ";
			a->multiTo(alpha); // goi phuong thuc nhan vector voi so alpha
			cout << "\t";
			a->output();//xuat vector vua nhan

			system("pause");//dung man hinh de xem ket qua
		}
		else if(choose == 0) //nhap 0 de ket thuc
		{
			break; // thoat khoi vong lap
		}
	}
}