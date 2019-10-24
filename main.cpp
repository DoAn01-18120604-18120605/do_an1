#include "Vector.h"
#include "Matrix.h"
int main()
{
	int choose;
	while (1)
	{
		system("cls");
		cout << "\n\t===================================UNG DUNG HO TRO HOC TAP====================================" << endl;
		cout << "\n\t\t\t\t\t\t1. Vector";
		cout << "\n\t\t\t\t\t\t2. Matrix";
		cout << "\n\t\t\t\t\t\t0. End" << endl;
		cout << "\n\t==============================================================================================" << endl << endl;
		cout << "nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == 1)
		{
			Vector* p = new Vector(0);
			menu(p);
		}
		else if (choose == 2)
		{
			Matrix* p = new Matrix(0, 0);
			menu(p);
		}
		else if (choose == 0)
		{
			break;
		}
	}

	system("pause");
	return 0;
}
