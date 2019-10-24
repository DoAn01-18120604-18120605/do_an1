#pragma once
#include<iostream>
using namespace std;
#define MAX 100
class Matrix
{
private:
	double** _a;//ma trận 2 chiều
	int _row;//số hàng của ma trận
	int _col;//số cột của ma trận
public:
	int Row() { return _row; }//hàm getter số hàng của ma trận
	int Col() { return _col; }//hàm getter so cột của ma trận
	void SetRow(int row) { _row = row; }//hàm setter số hàng
	void SetCol(int col) { _col = col; }//hàm setter số cột
public:
	Matrix();
	Matrix(int, int);
	~Matrix();
	Matrix(const Matrix&);
public:
	void input();//hàm nhập ma trận
	void output();//hàm xuất ma trận
	double GetAt(int, int);
	void multiTo(Matrix*);
	Matrix toEchelon();
	double detMatrix();
	int rankMatrix();
	Matrix inverseMatrix();
	void Equation(double b[100]);
};
void menu(Matrix*);
