#pragma once
#include <iostream>
using namespace std;

class Vector
{
private:
	int* _vt; // thành phần của vector
	int _len; // số chiều của vector
public:
	int Len() { return _len; } //  hảm getter điểm cuối
	void SetLen(int len) { _len = len; }// hàm setter điểm cuối của vector
public:
	Vector(int len);//hàm khởi tạo không có tham số
	~Vector();//hàm hủy
public:
	void input();//hàm nhập vector
	void output();//hàm xuất vector
	void addTo(Vector*);//hàm cộng 2 vector
	void multiTo(int);//hàm nhân vector với 1 số alpha
};

void menu(Vector*);
