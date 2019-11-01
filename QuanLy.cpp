#include "QuanLy.h"

QuanLy::QuanLy()
{
	_boole = new Bool();
	_vt = new Vector();
	_mt =  new Matrix();
}

QuanLy::QuanLy(const QuanLy& other)
{
	_boole = other._boole;
	_vt = other._vt;
	_mt = other._mt;
}
QuanLy::~QuanLy()
{
	delete _boole;
	delete _vt;
	delete _mt;
}
void QuanLy::control()
{
	int choose;//bien luu lua chon nguoi dung nhap
	while (1)
	{
		system("cls"); //xoa man hinh sau moi lan lap
		cout << "\n\t===================================UNG DUNG HO TRO HOC TAP====================================" << endl;
		cout << "\n\t\t\t\t\t\t1. Ham Bool";
		cout << "\n\t\t\t\t\t\t2. Vector";
		cout << "\n\t\t\t\t\t\t3. Matrix";
		cout << "\n\t\t\t\t\t\t0. End" << endl;
		cout << "\n\t==============================================================================================" << endl << endl;
		cout << "nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == 1) //neu nguoi dung nhap 1
		{
			_boole = new Bool();
			menu(_boole); // goi menu ham bool
		}
		else if (choose == 2) //neu nguoi dung nhap 2
		{
			Vector* p = new Vector(0);
			menu(p); // goi menu vector
		}
		else if (choose == 3) //neu nguoi dung nhap 3
		{
			Matrix* p = new Matrix(0, 0);
			menu(p); // goi menu ma tran
		}
		else if (choose == 0) //neu nguoi dung nhap 0
		{
			break; //thoat khoi vong lap
		}
	}

}