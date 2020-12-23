#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class figure
{
public:
	figure() {}
	virtual ~figure() {}
	virtual double calcArea() = 0;
	virtual void show() = 0;
	virtual figure* copyFigure() = 0;
	virtual double calcPerim() = 0;
};

class circle :public figure
{
private: double* R;
public:
	circle() {
		R = new double;
		*R = 1;
	};
	circle(double R2) {
		R = new double;
		*R = R2;
	};
	~circle() { delete R; };
	double calcArea() { return M_PI * *R * *R; };
	void show() { cout << "Circle" << endl << "Radius: " << *R << endl << "Area: " << calcArea() << endl; };
	double calcPerim() { return M_PI * (*R) * 2; };
	figure* copyFigure() { return new circle(*R); };
};

class rectangle :public figure {
private: double* h, * w;
public:
	rectangle()
	{
		h = new double;
		*h = 1;
		w = new double;
		*w = 1;
	};
	rectangle(double h2, double w2) {
		h = new double;
		*h = h2;
		w = new double;
		*w = w2;
	};
	~rectangle() { delete h, w; };
	double calcArea() { return (*h) * (*w); };
	void show() { cout << "Rectangle" << endl << "Size: " << *h << "x" << *w << endl << "Area: " << calcArea() << endl; };
	figure* copyFigure() { return new rectangle(*h, *w); };
	double calcPerim() { return ((*h) + (*w)) * 2; };
};

class rhombus :public figure {
private: double* side, *hight;
public:
	rhombus() 
	{
		side = new double;
		*side = 1;
		hight = new double;
		*hight = 1;
	};
	rhombus(double getSide,double gethight) 
	{
		side = new double;
		*side = getSide;
		hight = new double;
		*hight = gethight;
	};
	~rhombus() { delete side; };
	double calcArea() { return (*side * *hight); };
	void show() { cout << "rhombus" << endl << "Side: " << *side << endl << "Hight: " << *hight << endl << "Area: " << calcArea() << endl; };
	figure* copyFigure() { return new rhombus(*side,*hight); };
	double calcPerim() { return 4 * (*side); };
};

class сylinder {
private: figure* osn; int h;
public:
	сylinder() 
	{
		osn = NULL;
		h = NULL;
	};
	сylinder(figure* osn1, int h1) {
		osn = osn1->copyFigure();
		h = h1;
	};
	~сylinder() {};
	double calcVolume() { return osn->calcArea() * h; };
	double calcSquare() { return osn->calcPerim() * h + 2 * osn->calcArea(); };
};

int main()
{
	cout << "Hello!\nWhat figure do you want?\nWrite a number: " << endl << "1 - circle\n2 - rectangle\n3 - rhombus\n0 - Exit!\n";
	figure* lateBind = nullptr;
	int choise;
	cin >> choise;
	switch (choise) {
	case 1:
	{
		int radius;
		cout << "You picked a circle!\nEnter his radius: ";
		cin >> radius;
		lateBind = new circle(radius);
		lateBind->show();
		сylinder* num1_c = new сylinder(lateBind, 5);
		cout << "Cylinder volume: " << num1_c->calcVolume() << endl;
		cout << "Cylinder square: " << num1_c->calcSquare() << endl;
		delete lateBind;
		delete num1_c;
	}
	break;
	case 2:
	{
		int side1, side2;
		cout << "You picked a rectangle!\nEnter his sides:\n";
		cin >> side1 >> side2;
		lateBind = new rectangle(side1, side2);
		lateBind->show();
		сylinder* num2_c = new сylinder(lateBind, 5);
		cout << "Cylinder volume: " << num2_c->calcVolume() << endl;
		cout << "Cylinder square: " << num2_c->calcSquare() << endl;
		delete lateBind;
		delete num2_c;
	}
	break;
	case 3:
	{
		double side, hight;
		cout << "You picked a rhombus!\nEnter his side: ";
		cin >> side;
		cout << "Enter hight:";
		cin >> hight;
		lateBind = new rhombus(side,hight);
		lateBind->show();
		сylinder* num3_c = new сylinder(lateBind, 5);
		cout << "Cylinder volume: " << num3_c->calcVolume() << endl;
		cout << "Cylinder square: " << num3_c->calcSquare() << endl;
		delete lateBind;
		delete num3_c;
	}
	break;
	default:
		cout << "HEY Goodbye\n";
		exit(0);
	}
	return 0;
}