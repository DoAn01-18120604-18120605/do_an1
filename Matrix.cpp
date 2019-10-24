#include "Matrix.h"
Matrix::Matrix()
{
	_row= 0; _col = 0;
	_a = NULL;
}
Matrix::Matrix(const Matrix& other)
{
	_row = other._row;
	_col = other._col;
	_a = new double*[_row];
	for (int i = 0; i < _row; i++)
		_a[i] = new double[_col];
	for (int i = 0; i < _row;i++)
	for (int j = 0; j < _col; j++)
		_a[i][j] = other._a[i][j];
}
Matrix::Matrix(int row, int col)
{
	_row = row;
	_col = col;
	_a = new double*[_row];
	for (int i = 0; i < _row; i++)
	{
		_a[i] = new double[_col];
	}
	for (int i = 0; i < _row; i++)
		for (int j = 0; j < _col; j++)
			_a[i][j] = 0;
}
Matrix::~Matrix()
{
	for (int i = 0; i < _row; i++)
	{
		delete _a[i];
	}
	delete _a;
}
void Matrix::input()
{
	cout << "\tnhap so hang cua ma tran: ";
	cin >> _row;
	cout << "\tnhap so cot cua ma tran: ";
	cin >> _col;
	_a = new double*[_row];
	for (int i = 0; i < _row; i++)
	{
		_a[i] = new double[_col];
	}

	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			cout << "\t\tnhap a[" << i << "][" << j << "]=";
			cin >> _a[i][j];
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
			cout << _a[i][j] << " ";
		}
	}
}
double Matrix::GetAt(int i, int j)
{
	return _a[i][j];
}
void swap(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}
Matrix Matrix::toEchelon()
{
	Matrix temp(*this);// tao 1 bien sao chep de gia tri this khong thay doi khi tinh toan
	for (int i = 0; i < _row - 1; i++)
	{
		for (int j = i; j < _col; j++)
		{
			if (temp._a[i][j] == 0)
				for (int m = i + 1; m < _row; m++)
					if (temp._a[m][j] != 0)
					{
						for (int n = 0; n < _col; n++)
						{
							swap(temp._a[i][n], temp._a[m][n]);
						}
						break;//có break->tam giac tren//khong co ->tam giac duoi
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
				break;
			}
		}
	}
	return temp;
}
double Matrix::detMatrix()
{
	Matrix temp(*this);
	double det = 1;
	int x = 1;
	for (int i = 0; i < _row - 1; i++)
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
					x = -x;
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
	if (_row != _col)
		return 0;
	else
	{
		for (int i = 0; i < _row; i++)
		{
			det *= temp._a[i][i];
		}
	}

	return det * x;
}

Matrix Matrix::inverseMatrix()
{
	Matrix temp(*this);
	double det = temp.detMatrix();
	Matrix a(_row - 1, _col - 1);
	Matrix inverse(_row, _col);
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
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
			inverse._a[j][i] = pow(-1, i + j) * a.detMatrix() / det;
		}
	}
	if (det == 0)
	{
		cout << "KHONG TON TAI MA TRAN NGHICH DAO !" << endl;
	}
	else
		return inverse;
}

void Matrix::multiTo(Matrix* other)
{
	Matrix* temp = new Matrix(_row, other->_col);
	if (_col != other->_row)
	{
		cout << "khong the nhan 2 ma tran" << endl;
		return;
	}
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < other->_col; j++)
		{
			temp->_a[i][j] = 0;
			for (int k = 0; k < _col; k++)
			{
				temp->_a[i][j] += _a[i][k] * other->_a[k][j];
			}
		}
	}
	temp->output();
}
int Matrix::rankMatrix()
{
	Matrix temp = this->toEchelon();
	int rank = 0;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			if (temp._a[i][j] != 0)
			{
				rank++;
				break;
			}
		}
	}
	return rank;
}

void Matrix::Equation(double b[100])
{
	double nghiem[10];
	Matrix* temp1 = new Matrix(_row, _col + 1);
	for (int i = 0; i < _row; i++)
		for (int j = 0; j < _col + 1; j++)
		{
			temp1->_a[i][j] = _a[i][j];
			if (j == _col)
				temp1->_a[i][j] = b[i];
		}
	Matrix temp = temp1->toEchelon();
	temp.output();
	int rank = temp1->rankMatrix();
	int rank_a = this->rankMatrix();
	//cout<<rank<<rank_a<<_row<<endl;
	if (rank == rank_a && rank == _row)
	{
		cout << endl;
		nghiem[0] = temp._a[temp._row - 1][temp._col - 1] / temp._a[temp._row - 1][temp._row - 1];
		cout << nghiem[0] << endl;
		for (int i = 1; i < _row; i++)
		{
			nghiem[i] = temp._a[_row - i - 1][temp._col - 1];
			//cout << i << " =" << nghiem[i] << endl;
			for (int j = _row - 1; j > _row - i - 1; j--)
			{
				nghiem[i] -= temp._a[_row - i - 1][j] * nghiem[_row - j - 1];
				//cout << i << "=" << nghiem[i] << endl;
			}
			nghiem[i] = nghiem[i] / temp._a[_row - i - 1][_row - i - 1];
			cout << nghiem[i] << endl;
		}
	}
	else if (rank != rank_a)
		cout << "\nPTVN" << endl;
	else if (rank = rank_a && rank < _col)
		cout << "\nPTVSN" << endl;
}

void menu(Matrix* matrix)
{
	int choose;
	while (1)
	{
		system("cls");
		cout << "\n\t\t=======================================MATRIX========================================" << endl;
		cout << "\n\t\t\t\t\t\t1. Nhap ma tran";
		cout << "\n\t\t\t\t\t\t2. Xuat ma tran";
		cout << "\n\t\t\t\t\t\t3. Tim dinh thuc ma tran";
		cout << "\n\t\t\t\t\t\t4. Tim nghich dao ma tran";
		cout << "\n\t\t\t\t\t\t5. Tich 2 ma tran";
		cout << "\n\t\t\t\t\t\t6. Tim hang ma tran";
		cout << "\n\t\t\t\t\t\t7. Giai he phuong trinh tuyen tinh";
		cout << "\n\t\t\t\t\t\t0. Ve man hinh chinh" << endl;
		cout << "\n\t\t======================================================================================" << endl << endl;
		cout << "nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == 1)
		{
			matrix = new Matrix(0, 0);
			matrix->input();
		}
		else if (choose == 2)
		{
			cout << "\t";
			matrix->output();
			cout << endl;
			system("pause");
		}
		else if (choose == 3)
		{
			cout<<"Dinh thuc cua ma tran vua nhap la: "<< matrix->detMatrix()<<endl;
			system("pause");
		}
		else if (choose == 4)
		{
			Matrix temp = matrix->inverseMatrix();
			cout << "Ma tran nghich dao cua ma tran vua nhap la: " << endl;
			temp.output();
			cout << endl;
			system("pause");
		}
		else if (choose == 5)
		{
			matrix = new Matrix(0, 0);
			cout << "\tnhap ma tran thu 1" << endl;
			matrix->input();
			cout << "\t";
			matrix->output();
			cout << endl;

			Matrix* matrix1 = new Matrix(0, 0);
			cout << "\tnhap ma tran thu 2" << endl;
			matrix1->input();
			cout << "\t";
			matrix1->output();
			cout << endl;

			cout << "\ttich 2 ma tran: ";
			matrix->multiTo(matrix1);

			system("pause");
		}
		else if (choose == 6)
		{
			cout << "Hang cua ma tran vua nhap la: " << matrix->rankMatrix() << endl;
			system("pause");
		}
		else if (choose == 7)
		{
			double b[4] = { 1,2,3,4 };
			matrix->Equation(b);
			system("pause");
		}
		else
		{
			break;
		}
	}
}
