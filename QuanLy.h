#include "Bool.h"
#include "Matrix.h"
#include "Vector.h"

class QuanLy
{
private:
	Bool *_boole;
	Vector *_vt;
	Matrix *_mt;
public:
	QuanLy();
	QuanLy(const QuanLy&);
	~QuanLy();
public:
    Bool Boole() { return *_boole; }
	Vector VTor() { return *_vt; }
	Matrix Mtrix() { return *_mt; }
	void SetBoole(Bool *boole) { _boole = boole; }
	void SetVector(Vector *vt) {_vt = vt; }
	void SetMtrix(Matrix *mt) { _mt = mt; }
public:
	void control();
};