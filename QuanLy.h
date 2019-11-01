#include "Bool.h"
#include "Matrix.h"
#include "Vector.h"

class QuanLy
{
private:
	Bool *_boole; //ham bool
	Vector *_vt; //vector
	Matrix *_mt;//ma tran
public:
	QuanLy(); // khoi tao khong co tham so
	QuanLy(const QuanLy&); // khoi tao sao chep
	~QuanLy(); // huy
public:
    Bool Boole() { return *_boole; } // getter ham bool
	Vector VTor() { return *_vt; } // getter vector
	Matrix Mtrix() { return *_mt; } //getter ma tran
	void SetBoole(Bool *boole) { _boole = boole; } // setter ham bool
	void SetVector(Vector *vt) {_vt = vt; } // setter vector
	void SetMtrix(Matrix *mt) { _mt = mt; } //setter ma tran
public:
	void control(); // menu quan li chuong trinh
};