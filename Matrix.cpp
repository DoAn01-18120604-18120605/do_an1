#include "Matrix.h"
Matrix::Matrix()
{
	_row = 0; // so hang ma tran = 0
	_col = 0; // so cot ma tran = 0
	_a = NULL; // ma tran chua co gia tri
}
Matrix::Matrix(int row, int col)
{
	_row = row;
	_col = col;
	_a = new double* [_row]; // cap phat mang 2 chieu
	for (int i = 0; i < _row; i++)
	{
		_a[i] = new double[_col]; // cap phat mang 1 chieu
	}
	//khoi tao gia tri cho cac phan tu trong mang bang 0
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			_a[i][j] = 0; 
		}
	}
}
Matrix::Matrix(const Matrix& other) // ham tao sao chep
{
	_row = other._row; // so hang cua ma tran = so hang cua ma tran duoc sao chep
	_col = other._col;// so cot cua ma tran = so cot cua ma tran duoc sap chep
	_a = new double* [_row];  //cap phat dong cho mang 2 chieu
	for (int i = 0; i < _row; i++) 
	{
		_a[i] = new double[_col];
	}
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			_a[i][j] = other._a[i][j]; //gan cac gia tri cua ma tran duoc sao chep cho ma tran can sao chep
		}
	}
}
Matrix::~Matrix()
{
	//thu hoi vung nho cua ma tran
	for (int i = 0; i < _row; i++)
	{
		delete _a[i];
	}
	delete[] _a;
}
void Matrix::input()
{
	cout << "\tnhap so hang cua ma tran: ";
	cin >> _row; //nhap so hang
	cout << "\tnhap so cot cua ma tran: ";
	cin >> _col; //nhap so cot
	_a = new double* [_row];
	for (int i = 0; i < _row; i++)
	{
		_a[i] = new double[_col];
	}
	
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			cout << "\t\tnhap a["<<i << "][" << j << "]=";
			cin >> _a[i][j]; //nhap gia tri cho tung phan tu trong ma tran
		}
		cout << endl;
	}
}
void Matrix::output()
{
	for (int i = 0; i < _row; i++)
	{
		cout << endl;
		for (int j = 0; j < _col; j++)
		{
			cout <<setw(6)<<setprecision(3)<< _a[i][j] << " "; //xuat gia tri cua tung phan tu trong ma tran
		}
	}
}

double Matrix::GetAt(int i, int j)
{
	return _a[i][j]; //tra ve gia tri tai vi tri can lay
}
void Matrix::multiTo(Matrix* other)
{
	//tao 1 ma tran de luu ket qua khi nhan 2 ma tran
	Matrix* temp = new Matrix(_row, other->_col); 
	if (_col != other->_row) //neu so cot cua ma tran nay khac so hang cua ma tran kia
	{
		cout << "khong the nhan 2 ma tran" << endl;
		return;
	}
	//duyet tung phan tu trong ma tran
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < other->_col; j++)
		{
			temp->_a[i][j] = 0;
			for (int k = 0; k < _col; k++)
			{
				temp->_a[i][j] += _a[i][k] * other->_a[k][j]; //tinh gia tri cua tung phan tu o ma tran ket qua
			}
		}
	}
	cout << "\t";
	temp->output(); //xuat ma tran ket qua
}

Matrix* Matrix::MultiTo(Matrix* other)
{
	Matrix* temp = new Matrix(_row, other->_col); // tao ma tran de luu ket qua
	if (_col != other->_row) // neu so cot cua ma tran khac so hang cua ma tran kia
	{
		return NULL; //tra ve gia tri NULL
	}
	//nguoc lai
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < other->_col; j++)
		{
			temp->_a[i][j] = 0; //gan gia tri cho tung phan tu cua ma tran ket qua = 0
			for (int k = 0; k < _col; k++)
			{
				temp->_a[i][j] += _a[i][k] * other->_a[k][j];  //tinh gia tri cho tung phan tu cua ma tran ket qua
			}
		}
	}
	cout << "\t";
	return temp; // tra ve ma tran ket qua
}

Matrix Matrix::toEchelon()
{
	Matrix temp(*this);// tao 1 bien sao chep de  this khong thay doi khi tinh toan
	for (int i = 0; i < _row - 1; i++)
	{
		for (int j = i; j < _col; j++)
		{
			//doi cac dong co so 0 nam truoc xuong duoi
			if (temp._a[i][j] == 0)
				for (int m = i + 1; m < _row; m++)
					if (temp._a[m][j] != 0)
					{
						for (int n = 0; n < _col; n++)
						{
							swap(temp._a[i][n], temp._a[m][n]);
						}
						break;//co break->tam giac tren//khong co ->tam giac duoi
					}
			if (temp._a[i][j] != 0)
			{
				for (int m = i + 1; m < _row; m++)
				{
					double tl = temp._a[m][j] / temp._a[i][j]; //ti le giua 2 so tren cung 1 cot cua 2 dong lien tiep
					for (int n = 0; n < _col; n++)
					{
						temp._a[m][n] -= temp._a[i][n] * tl;
					}
				}
				break;
			}
		}
	}
	return temp;
}

double Matrix::detMatrix() //tinh dinh thuc ma tran
{
	Matrix temp(*this); //tao 1 ma tran sao chep de ma tran this khong bi thay doi khi tinh toan
	double det = 1; //khoi tao bien det = 1
	int x = 1; //quyet dinh dau cua dinh thuc
	for (int i = 0; i < _row - 1; i++) //dua ve dang ma tran bac thang
	{
		int j = i;
		if (temp._a[i][j] == 0)
		{
			for (int m = i + 1; m < _row; m++)
				if (temp._a[m][j] != 0)
				{
					for (int n = 0; n < _col; n++)
					{
						swap(temp._a[i][n], temp._a[m][n]);
					}
					x = -x; //trong dinh thuc, doi dong se doi dau
					j++;
				}
		}
		if (temp._a[i][j] != 0)
		{
			for (int m = i + 1; m < _row; m++)
			{
				double tl = temp._a[m][j] / temp._a[i][j];
				for (int n = 0; n < _col; n++)
				{
					temp._a[m][n] -= temp._a[i][n] * tl;
				}
			}
		}
	}
	if (_row != _col) //neu so dong khac so cot
		return 0;
	else
	{
		for (int i = 0; i < _row; i++)
		{
			det *= temp._a[i][i]; //dinh thuc bang tich cac so tren duong cheo chinh
		}
	}

	return det * x; //tra ve gia tri cua dinh thuc nhan voi dau
}
int Matrix::rankMatrix() //tim hang ma tran
{
	Matrix temp = this->toEchelon(); //tao ma tran sao chep de khong lam thay doi ma tran this khi tinh toan, sau do dua ma tran vua tao ve dang bac thang
	int rank = 0; //khoi tao hang ma tran = 0
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			if (temp._a[i][j] != 0) 
			{
				rank++; // hang ma tran tang len 1
				break;
			}
		}
	}
	return rank; //tra ve gia tri hang ma tran
}

Matrix Matrix::inverseMatrix()
{
	Matrix temp(*this); //tao 1 ma tran sao chep de khong thay doi ma tran nhap vao ban dau
	double det = temp.detMatrix(); //det = dinh thuc cua ma tran
	Matrix a(_row - 1, _col - 1); //khoi tao ma tran phu hop
	Matrix inverse(_row, _col); //khoi tao ma tran nghich dao
	
	if (det == 0) //neu det = 0
	{
		cout << "KHONG TON TAI MA TRAN NGHICH DAO !" << endl;
		return Matrix();
	}
	else //neu det khac 0
	{
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				//tim ma tran loai bo dong i cot j A(i|j)
				int row = 0;
				for (int k = 0; k < _row; k++)
				{
					int col = 0;
					for (int m = 0; m < _col; m++)
					{
						if (m == j || k == i)
							continue;
						else
						{
							a._a[row][col] = _a[k][m];
							col++;
						}
					}
					if (k != i)
						row++;
				}
				inverse._a[j][i] = pow(-1, i + j) * a.detMatrix() / det; //gia tri tung phan tu cua ma tran nghich dao
			}
		}
		return inverse; //tra ve ma tran nghich dao
	}
}

void Matrix::inputEquation(double*& b) //nhap he phuong trinh tuyen tinh
{
	cout << "nhap so phuong trinh: ";
	cin >> _row; //nhap so dong
	cout << "nhap so an: ";
	cin >> _col;//nhap so an

	b = new double[_row]; //cap phat dong cho con tro b

	//cap phat dong cho mang 2 chieu a
	_a = new double* [_row]; 
	for (int i = 0; i < _row; i++)
	{
		_a[i] = new double[_col];
	}
	for (int i = 0; i < _row; i++)
	{
		cout << endl;
		cout << "PHUONG TRINH THU " << i + 1<<endl;
		for (int j = 0; j < _col; j++) //nhap ma tran he so
		{
			cout << "\tnhap he so thu " << j + 1 << ": ";
			cin >> _a[i][j];
		}
		cout << "\tnhap ket qua cua phuong trinh: ";
		cin >> b[i]; //nhap ma tran ket qua 
	}
}

void Matrix::outputEquation(double* b) //xuat he phuong trinh
{
	cout << "\t\t\tHE PHUONG TRINH CAN GIAI CO DANG" << endl;
	for (int i = 0; i <_row; i++)
	{
		cout << endl;
		for (int j = 0; j < _col; j++)
		{
			cout << _a[i][j] << "*x" << j + 1; //xuat he so cua tung phuong trinh
			if (j < _col - 1)
			{
				cout << " + ";
			}
			else cout << " ";
		}
		cout << " = " << b[i] << endl; //xuat ket qua cua tung phuong trinh
	}
}
void Matrix::Equation(double* b)
{
	//ghep ma tran he so va ma tran tu do de tao thanh ma tran he so mo rong
	double* nghiem = new double[_row];
	Matrix* temp1 = new Matrix(_row, _col + 1);
	for (int i = 0; i < _row; i++)
		for (int j = 0; j < _col + 1; j++)
		{
			temp1->_a[i][j] = _a[i][j];
			if (j == _col)
				temp1->_a[i][j] = b[i];
		}
	//tim nghiem
	Matrix temp = temp1->toEchelon();//chuyen ma tran he so mo rong ve dang bac thang
	int rank = temp1->rankMatrix();
	int rank_a = this->rankMatrix();
	if (rank == rank_a && rank == _col)//dieu kien de phuong trinh co nghiem duy nhat
	{
		cout << endl;
		nghiem[0] = temp._a[temp._row - 1][temp._col - 1] / temp._a[temp._row - 1][temp._row - 1];
		for (int i = 1; i < _row; i++)
		{
			nghiem[i] = temp._a[_row - i - 1][temp._col - 1];
			for (int j = _row - 1; j > _row - i - 1; j--)
			{
				nghiem[i] -= temp._a[_row - i - 1][j] * nghiem[_row - j - 1];
			}
			nghiem[i] = nghiem[i] / temp._a[_row - i - 1][_row - i - 1];
		}
		for (int i = 0; i < _row; i++)//xuat nghiem
		{
			cout << "x" << i + 1 << " = " << nghiem[_row - i - 1] << endl;
		}
	}
	else if (rank != rank_a)//dieu kien de phuong trinh vo nghiem
		cout << "\nHE PHUONG TRINH VO NGHIEM" << endl;
	else if (rank = rank_a && rank < _col)//dieu kien de pt co vo so nghiem 
	{
		cout << "\nHE PHUONG TRINH CO VO SO NGHIEM" << endl;
	}
}

void menu(Matrix* matrix)
{
	int choose; // bien de nguoi dung nhap lua chon
	while (1)
	{
		system("cls"); // xoa man hinh sau moi lan lap
		cout << "\n\t\t=======================================MATRIX========================================"<<endl;
		cout << "\n\t\t\t\t\t\t1. Nhap ma tran";
		cout << "\n\t\t\t\t\t\t2. Xuat ma tran";
		cout << "\n\t\t\t\t\t\t3. Tim dinh thuc ma tran";
		cout << "\n\t\t\t\t\t\t4. Tim nghich dao ma tran";
		cout << "\n\t\t\t\t\t\t5. Tich 2 ma tran";
		cout << "\n\t\t\t\t\t\t6. Hang cua ma tran";
		cout << "\n\t\t\t\t\t\t7. Giai he phuong trinh tuyen tinh";
		cout << "\n\t\t\t\t\t\t0. Ve man hinh chinh"<<endl;
		cout << "\n\t\t======================================================================================" << endl << endl;
		cout << "NHAP LUA CHON CUA BAN: ";
		cin >> choose; //nhap lua chon
		if (choose == 1) // neu nguoi dung nhap 1
		{
			cout << endl;
			matrix = new Matrix(0,0); // khoi tao ma tran
			matrix->input(); //goi phuong thuc nhap ma tran
		}
		else if (choose == 2) // neu nguoi dung nhap 2
		{
			cout << "\n\t";
			matrix->output();//goi phuong thuc xuat ma tran
			cout << endl;
			system("pause"); //dung man hinh de xem ket qua
		}
		else if (choose == 3) //neu nguoi dung nhap 3
		{
			cout << endl;
			Matrix* matrix1(matrix); //tao 1 ma tran sao chep de trong qua trinh thuc thi khong lam thay doi gia tri ma tran nhap ban dau

			cout<<"\tdinh thuc cua ma tran da nhap la: "<<matrix1->detMatrix()<<endl; //xuat ra man hinh dinh thuc cua ma tran
			system("pause");//dung man hinh xem ket qua
		}
		else if (choose == 4) // neu nguoi dung nhap 4
		{
			cout << endl;
			Matrix* matrix1(matrix); //tao 1 ma tran sao chep de trong qua trinh thuc thi khong lam thay doi gia tri ma tran nhap ban dau
			cout << "\n\tma tran nghich dao cua ma tran da nhap\n";
			Matrix inverse = matrix1->inverseMatrix();//ma tran luu ket qua cua phuong thuc nghich dao ma tran
			inverse.output();//xuat ma tran ket qua
			system("pause");//dung ma hinh de xem ket qua
		}
		else if (choose == 5) //neu nguoi dung nhap 5
		{
			cout << endl;
			Matrix* matrix1 = new Matrix(0, 0); //khoi tao ma tran thu 2
			cout << "\tnhap ma tran thu 2" << endl;
			matrix1->input(); // nhap vao ma tran thu 2
			cout << "\t";
			matrix1->output(); //xuat ma tran vua nhap
			cout << endl;

			cout << "\ttich ma tran ban dau voi ma tran ban vua nhap: ";
			if ((matrix->MultiTo(matrix1)) == NULL) // neu phuong thuc nhan ma tran tra ve NULL
			{
				cout << "KHONG THE NHAN 2 MA TRAN!!!" << endl; 
			}
			else // neu khac NULL
			{
				(matrix->MultiTo(matrix1))->output(); //xuat ra ma tran ket qua nhan ma tran ban dau nhap voi ma tran thu 2 vua nhap o tren
			}
			system("pause"); //dung man hinh de xem ket qua
		}
		else if (choose == 6) //neu nguoi dung nhap 6
		{
			cout << endl;
			Matrix* matrix1(matrix); //tao 1 ma tran sao chep de trong qua trinh thuc thi khong lam thay doi gia tri ma tran nhap ban dau

			cout << "\tHang cua ma tran da nhap: "<<matrix1->rankMatrix() << endl; //xuat ra man hinh hang cua ma tran
			system("pause");//dung man hinh de xem
		}
		else if (choose == 7) //neu nguoi dung nhap 7
		{
			cout << endl;
			Matrix* matrix1 = new Matrix(0,0); //tao 1 ma tran de luu cac he so cua phuong trinh
			double* b=new double[matrix1->Row()]; //tao 1 mang de luu cac ket qua cua cac phuong trinh
			matrix1->inputEquation(b); // goi phuong thuc nhap he pt
			
			cout << endl;
			matrix1->outputEquation(b); // xuat he pt vua nhap
			matrix1->Equation(b); //goi phuong thuc giai he pt
			system("pause"); // dung man hinh de xem ket qua
		}
		else if (choose == 0) //nhap 0 de ket thuc
		{
			break; //thoat khoi vong lap
		}
	}
}