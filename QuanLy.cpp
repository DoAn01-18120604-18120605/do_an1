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
	int choose;//biến để lưu lựa chọn người dùng nhập
	while (1)
	{
		system("cls"); //xóa màn hình
		cout << "\n\t===================================UNG DUNG HO TRO HOC TAP====================================" << endl;
		cout << "\n\t\t\t\t\t\t1. Ham Bool";
		cout << "\n\t\t\t\t\t\t2. Vector";
		cout << "\n\t\t\t\t\t\t3. Matrix";
		cout << "\n\t\t\t\t\t\t0. End" << endl;
		cout << "\n\t==============================================================================================" << endl << endl;
		cout << "nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == 1) //nếu người dùng nhập 1 thì gọi hàm quản lí các thao tác trên hàm bool
		{
			_boole = new Bool();
			menu(_boole);
		}
		else if (choose == 2) //nếu người dùng nhập 2 thỉ gọi hàm quản lí các thao tác trên vector
		{
			Vector* p = new Vector(0);
			menu(p);
		}
		else if (choose == 3) //nếu người dùng nhập 3 thì gọi hàm quản lí các thao tác trên ma trận
		{
			Matrix* p = new Matrix(0, 0);
			menu(p);
		}
		else if (choose == 0) //nếu người dùng nhập 0 thì thoát chương trình
		{
			break;
		}
	}

}