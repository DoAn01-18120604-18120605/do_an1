#pragma once
#include <iostream>
using namespace std;

class Vector
{
private:
	int *_vt; // mang chua cac thanh phan cua vector
	int _len; // so chieu cua vector
public:
	int Len() { return _len; } //  lay so chieu cua vector
	void SetLen(int len) { _len = len; }// setter so chieu cua vector
public:
	Vector(); // ham tao khong co tham so
	Vector(int len);// ham tao co tham so truyen vao
	~Vector();//ham huy
public:
	void input();//phuong thuc nhap vector
	void output();//phuong thuc xuat vector
	void addTo(Vector*);// phuong thuc cong 2 vector
	void multiTo(int); // phuong thuc nhan 2 vector
};

void menu(Vector*); //quan li cac thao tac tren vector
