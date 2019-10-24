#include "Vector.h"

Vector::Vector(int len)
{
	_len = len;
	_vt = new int[_len];
}
Vector:: ~Vector()
{
	delete[]_vt;
}
void Vector::input()
{
	cout << "\tnhap so chieu cua vector: ";
	cin >> _len;
	cout << "\t\tnhap thanh phan cua  vector" << endl;
	for (int i = 0; i < _len; i++)
	{
		cout << "\t\t\tthanh phan " << i + 1 << ": ";
		cin >> _vt[i];
	}
}
void Vector::output()
{
	cout << "(";
	for (int i = 0; i < _len; i++)
	{
		cout << _vt[i];
		if (i <= _len - 2)
		{
			cout << ",";
		}
	}
	cout << ")" << endl;
}
void Vector::addTo(Vector* other)
{
	Vector* vt = new  Vector(0);
	if (_len != other->_len)
	{
		cout << "\t\t\tkhong the cong 2 vector" << endl;
	}
	else
	{
		for (int i = 0; i < _len; i++)
		{
			vt->_vt[i] = _vt[i] + other->_vt[i];
			vt->_len++;
		}
		cout << "\t";
		vt->output();
	}
}
void Vector::multiTo(int alpha)
{
	for (int i = 0; i < _len; i++)
	{
		_vt[i] = alpha * _vt[i];
	}
}

void menu(Vector* p)
{
	int choose;
	while (1)
	{
		system("cls");
		cout << "\n\t\t======================================VECTOR=======================================" << endl;
		cout << "\n\t\t\t\t\t\t1. Nhap vector";
		cout << "\n\t\t\t\t\t\t2. Xuat vector";
		cout << "\n\t\t\t\t\t\t3. Cong 2 vector";
		cout << "\n\t\t\t\t\t\t4. Nhan vector voi 1 so alpha";
		cout << "\n\t\t\t\t\t\t0. Ve man hinh chinh" << endl;
		cout << "\n\t\t===================================================================================" << endl << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == 1)
		{
			p = new Vector(0);
			p->input();
		}
		else if (choose == 2)
		{
			p->output();
			system("pause");
		}
		else if (choose == 3)
		{
			p->input();
			cout << "\t";
			p->output();
			cout << endl;
			Vector* vt1 = new Vector(0);
			vt1->input();
			cout << "\t";
			vt1->output();
			cout << "\ttong 2 vector: ";
			p->addTo(vt1);
			system("pause");

		}
		else if (choose == 4)
		{
			p = new Vector(0);
			p->input();
			cout << "\t";
			p->output();
			cout << endl;
			int alpha;
			cout << "\tnhap so alpha: ";
			cin >> alpha;
			cout << "\ttich vector voi 1 so alpha: ";
			p->multiTo(alpha);
			cout << "\t";
			p->output();
			system("pause");
		}
		else
		{
			break;
		}
	}
}
