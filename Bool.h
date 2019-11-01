#pragma once
#include<iostream>
#include<sstream>
#include<string.h>
#include<vector>
#include<string>
using namespace std;

class Bool
{
private:
	string _b; //xau ki tu chua ham bool
public:
	string B() { return _b; } //getter ham bool
public:
	Bool(); //ham tao khong co tham so
	~Bool();//ham huy
public:
	
	void input();//nhap ham bool
	void output();//xuat ham bool
	int check(); //kiem tra tinh hop le cua ham bool
	void standardized();//chuan hoa ham bool nhap vao
	int countNumberOfWord();//dem so luong tu don nhap vao
	string* separateString(); //tach tung tu don trong ham bool
	string* encode();//ma hoa chuoi chu sang chuoi so, vd abcd -> 1111, aBcD -> 1010, aBc -> 101-
};

void menu(Bool*);// quan li cac thao tac tren ham bool