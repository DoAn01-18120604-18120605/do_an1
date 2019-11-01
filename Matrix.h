#pragma once
#include<iostream>
#include <iomanip>
using namespace std;
#define MAX 100
class Matrix
{
private:
	double **_a;//ma tran 2 chieu
	int _row;//so hang cua ma tran
	int _col;//số cot ma tran
public:
	int Row() { return _row; }// getter so hang cua ma tran
	int Col() { return _col; }//getter so cot cua ma tran
	void SetRow(int row) { _row = row; }//setter so hang
	void SetCol(int col) { _col = col; }// setter so cot
public:
	Matrix(); //ham tao khong co tham so
	Matrix(int,int); //ham tao co tham so truyen vao
	Matrix(const Matrix&); //ham tao sao chep
	~Matrix();//ham huy
public:
	void input();//phuong thuc nhap ma tran
	void output();//xuat ma tran
	double GetAt(int, int); // lay gia tri cua ma tran tai phan tu thu i,j
	void multiTo(Matrix*);//nhan 2 ma tran
	Matrix* MultiTo(Matrix*); //nhan 2 ma tran
	Matrix toEchelon();//dua ma tran ve dang bac thang
	double detMatrix();// dinh thuc ma tran
	int rankMatrix();// hang cua ma tran
	Matrix inverseMatrix(); //tim nghich dao ma tran
	
	void inputEquation(double*&);//nhap he phuong trinh tuyen tinh
	void outputEquation(double*);// xuat he phuong trinh tuyen tinh
	void Equation(double*);//giai he phuong trinh tuyen tinh
};

void menu(Matrix*); //quản lí các thao tác trên ma trận