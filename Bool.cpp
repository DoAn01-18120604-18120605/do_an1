#include "Bool.h"

Bool::Bool()
{
	_b = ""; //khoi tao chuoi rong
}
Bool::~Bool()
{

}
int Bool:: check() //kiem tra ham bool nhap vao co hop le hay khong
{
	int ch = 1; //bien kiem tra
	int i = 0;
	while (_b[i] != NULL) //khi chuoi chua ket thuc
	{
		//neu b[i] khac a,b,c,d,A,B,C,D,+ va dau cach thi
		if (_b[i] != 'a' && _b[i] != 'b' && _b[i] != 'c' && _b[i] != 'd' && _b[i] != 'A' 
			&& _b[i] != 'B' && _b[i] != 'C' && _b[i] != 'D' && _b[i] != ' ' && _b[i] != '+')
		{
			ch = -1; //bien kiem tra bang -1
			break; //thoat khoi vong lap
		}
		i++; //tang buoc lap len
	}
	return ch; // tra ve gia tri cua bien kiem tra
}
void Bool::input() //nhập hàm bool
{
	do 
	{
		cout << "nhap ham bool: ";
		cin.ignore();
		getline(cin, _b);

		if (check() == -1)
		{
			cout << "nhap khong hop le. Xin nhap lai!!!" << endl;
		}
	} while (check() == -1);
	standardized();
}
void Bool::output() // xuat ham  bool
{
	cout << _b;
}

void Bool:: standardized()
{
	//xoa tat ca khoang trang trong chuoi
	for (int i = 0; i < _b.length(); i++)
	{
		if (_b[i] == ' ')
		{
			_b.erase(_b.begin() + i);
			i--;
		}
	}
	//
	//xoa tat ca cac dau + thua trong chuoi
	while (_b[0] == '+')//xoa dau cong thua dau chuoi
	{
		_b.erase(_b.begin() + 0);
	}
	while (_b[_b.length() - 1] == '+')//xoa dau + thua cuoi chuoi
	{
		_b.erase(_b.begin() + _b.length() - 1);
	}
	for (int i = 0; i < _b.length(); i++) //xoa cac dau + thua trong chuoi
	{
		if (_b[i] == '+' && _b[i + 1] == '+')
		{
			_b.erase(_b.begin() + i);
			i--;
		}
	}
}

int Bool:: countNumberOfWord() //dem so luong tu don trong ham bool
{
	int count = 1; //bien dem = 1
	for (int i = 0; i < _b.length(); i++) //duyet tu dau den cuoi chuoi
	{  
		if (_b[i] == '+') //neu duyet den dau + 
		{
			count++; //bien dem tang len 1 don vi
		}
	}
	return count; //tra ve gia tri cua bien dem
}

string* Bool::separateString() //tach tung tu don ra trong ham bool nhap vao
{
	string b = _b; // gan chuoi nhap vao 1 bien chuoi khac de khong lam thay doi gia tri cua chuoi nhap vao
	char* cstr; // bien luu chuoi chuyen tu kieu string sang char*
	char* p; //luu tung tu don sau moi lan tach
	string* c = new string[countNumberOfWord()]; //cap phat dong cho c - mang luu tung tu don
	cstr = new char[b.size() + 1];  // cap phat dong cho bien con tro cstr
	strcpy(cstr, b.c_str()); //ep kieu tu string sang char*
	p = strtok(cstr, "+"); //tach chuoi con trong cstr
	int i = 0;
	while (p != NULL) //duyet tu dau den cuoi chuoi
	{
		c[i] = p; //mang c duoc gan gia tri la tung chuoi con sau moi lan tach
		i++; //tang buoc lap
		p = strtok(NULL, "+"); //tiep tuc tach cho den khi ket thuc chuoi
	}
	return c; //tra ve mang chua cac tu don da duoc tach tu ham bool
	delete cstr; //giai phong vung nho cho con tro cstr
	delete[] c; //giai phong vung nho cho mang c
}

string* Bool::encode() //ma hoa tung tu don sang chuoi so VD aBc -> 101- , Bd -> -0-1
{
	int n = this->countNumberOfWord(); //bien n luu so luong tu don
	string* temp1 = new string[countNumberOfWord()]; //mang luu tung tu don da duoc ma hoa sang so
	string* temp2 = new string[countNumberOfWord()]; //mang luu tung tu don duoc tach ra tu chuoi
	int j = 0;

	temp2 = this->separateString(); //tach chuoi
	for (int i = 0; i < n; i++) //duyet tu dau mang den cuoi mang
	{
			if (temp2[i].size() == 1) // do dai chuoi i == 1
			{
				if (temp2[i][j] == 'a')
					temp1[i] = "1---";
				else if (temp2[i][j] == 'b')
					temp1[i] = "-1--";
				else if (temp2[i][j] == 'c')
					temp1[i] = "--1-";
				else if (temp2[i][j] == 'd')
					temp1[i] = "---1";
				else if (temp2[i][j] == 'A')
					temp1[i] = "0---";
				else if (temp2[i][j] == 'B')
					temp1[i] = "-0--";
				else if (temp2[i][j] == 'C')
					temp1[i] = "--0-";
				else if(temp2[i][j] == 'D')
					temp1[i] = "---0";
			}
			else if (temp2[i].size() == 2) //do dai chuoi i == 2
			{
				if (temp2[i][j] == 'a')
				{
					if (temp2[i][j + 1] == 'b')
						temp1[i] = "11--";
					else if (temp2[i][j + 1] == 'c')
						temp1[i] = "1-1-";
					else if (temp2[i][j + 1] == 'd')
						temp1[i] = "1--1";
					else if (temp2[i][j + 1] == 'B')
						temp1[i] = "10--";
					else if (temp2[i][j + 1] == 'C')
						temp1[i] = "1-0-";
					else if (temp2[i][j + 1] == 'D')
						temp1[i] = "1--0";
				}
				else if (temp2[i][j] == 'A')
				{
					if (temp2[i][j + 1] == 'b')
						temp1[i] = "01--";
					else if (temp2[i][j + 1] == 'c')
						temp1[i] = "0-1-";
					else if (temp2[i][j + 1] == 'd')
						temp1[i] = "0--1";
					else if (temp2[i][j + 1] == 'B')
						temp1[i] = "00--";
					else if (temp2[i][j + 1] == 'C')
						temp1[i] = "0-0-";
					else if(temp2[i][j+1]=='D')
						temp1[i] = "0--0";
				}
				else if (temp2[i][j] == 'b')
				{
					if (temp2[i][j + 1] == 'c')
						temp1[i] = "-11-";
					else if (temp2[i][j + 1] == 'd')
						temp1[i] = "-1-1";
					else if (temp2[i][j + 1] == 'C')
						temp1[i] = "-10-";
					else if (temp2[i][j + 1] == 'D')
						temp1[i] = "-1-0";
				}
				else if (temp2[i][j] == 'B')
				{
					if (temp2[i][j + 1] == 'c')
						temp1[i] = "-11-";
					else if (temp2[i][j + 1] == 'd')
						temp1[i] = "-1-1";
					else if (temp2[i][j + 1] == 'C')
						temp1[i] = "-00-";
					else if (temp1[i][j + 1] == 'D')
						temp1[i] = "-0-0";
				}
				else if (temp2[i][j] == 'c')
				{
					if (temp2[i][j + 1] == 'd')
						temp1[i] = "--11";
					else if (temp2[i][j + 1] == 'D')
						temp1[i] = "--10";
				}
				else if (temp2[i][j] == 'C')
				{
					if (temp2[i][j + 1] == 'd')
						temp1[i] = "--01";
					else if (temp2[i][j + 1] == 'D')
						temp1[i] = "--00";
				}
			}
			else if (temp2[i].size() == 3) //do dai chuoi i == 3
			{
				if (temp2[i][j] == 'a')
				{
					if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'c')
						temp1[i] = "111-";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'C')
						temp1[i] = "110-";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'd')
						temp1[i] = "11-1";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'D')
						temp1[i] = "11-0";
					else if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'd')
						temp1[i] = "1-11";
					else if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'D')
						temp1[i] = "1-10";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'c')
						temp1[i] = "101-";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'C')
						temp1[i] = "100-";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'd')
						temp1[i] = "10-1";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'D')
						temp1[i] = "10-0";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'd')
						temp1[i] = "1-01";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'D')
						temp1[i] = "1-00";
				}
				else if (temp2[i][j] == 'b')
				{
					if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'd')
						temp1[i] = "-111";
					else if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'D')
						temp1[i] = "-110";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'd')
						temp1[i] = "-101";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'D')
						temp1[i] = "-100";
				}
				else if (temp2[i][j] == 'A')
				{
					if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'c')
						temp1[i] = "011-";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'C')
						temp1[i] = "010-";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'd')
						temp1[i] = "01-1";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'D')
						temp1[i] = "01-0";
					else if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'd')
						temp1[i] = "0-11";
					else if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'D')
						temp1[i] = "0-10";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'c')
						temp1[i] = "001-";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'C')
						temp1[i] = "000-";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'd')
						temp1[i] = "00-1";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'D')
						temp1[i] = "00-0";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'd')
						temp1[i] = "1-01";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'D')
						temp1[i] = "0-00";
				}
				else if (temp2[i][j] == 'B')
				{
					if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'd')
						temp1[i] = "-011";
					else if (temp2[i][j + 1] == 'c' && temp2[i][j + 2] == 'D')
						temp1[i] = "-010";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'd')
						temp1[i] = "-001";
					else if (temp2[i][j + 1] == 'C' && temp2[i][j + 2] == 'D')
						temp1[i] = "-000";
				}
			}
			else if (temp2[i].size() == 4) //do dai chuoi i == 4
			{
				if (temp2[i][j] == 'a')
				{
					if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'd')
						temp1[i] == "1111";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'd')
						temp1[i] == "1011";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'd')
						temp1[i] == "1101";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'D')
						temp1[i] == "1110";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'd')
						temp1[i] == "1001";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'D')
						temp1[i] == "1010";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'D')
						temp1[i] == "1100";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'D')
						temp1[i] == "1000";
				}
				else if (temp2[i][j] == 'A')
				{
					if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'd')
						temp1[i] == "0111";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'd')
						temp1[i] == "0011";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'd')
						temp1[i] == "0101";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'D')
						temp1[i] == "0110";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'd')
						temp1[i] == "0001";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'c' && temp2[i][j + 3] == 'D')
						temp1[i] == "0010";
					else if (temp2[i][j + 1] == 'b' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'D')
						temp1[i] == "0100";
					else if (temp2[i][j + 1] == 'B' && temp2[i][j + 2] == 'C' && temp2[i][j + 3] == 'D')
						temp1[i] == "0000";
				}
			}
	}
	return temp1; // tra ve mang chua cac tu don da duoc ma hoa
	delete[] temp1; //giai phong mang temp1
	delete[] temp2; //giai phong mang temp2
}
void menu(Bool* boole) //quan li cac thao tac tren ham bool
{
	int choose; //bien de nguoi dung nhap lua chon
	while (1)
	{
		system("cls"); //xoa man hinh sau moi lan lap
		cout << "\n\t\t=======================================BOOL========================================" << endl;
		cout << "\n\t\t\t\t\t\t1. Nhap ham bool";
		cout << "\n\t\t\t\t\t\t2. Xuat ham bool";
		cout << "\n\t\t\t\t\t\t0. Ve man hinh chinh" << endl;
		cout << "\n\tQuy uoc: bien thuong la bu cua bien in hoa. VD: A la phan bu cua a, tuong tu cho nhung bien khac";
		cout << "\n\t\t======================================================================================" << endl << endl;
		cout << "NHAP LUA CHON CUA BAN: ";
		cin >> choose; // nhap lua chon
		if (choose == 1) //nhap 1 de nhap ham bool
		{
			boole->input(); 
		}
		else if (choose == 2) //nhap 2 de xuat ham bool
		{
			cout << "\t";
			boole->output(); // xuat bool
			cout << endl;
			cout << "\ntach\n ";
			
			//cout << "\nma hoa\n";
			string* d = boole->encode();
			for (int i = 0; i < d->size(); i++)
			{
				cout << d[i] << endl;
			}
			delete[] d;
			system("pause"); // dung man hinh de xem ket qua
		}
		else if (choose == 0) // nhap 0 de ket thuc
		{
			break; // thoat vong lap
		}
	}
}