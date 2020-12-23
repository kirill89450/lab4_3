#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class figure
{
public:
	figure()
	{

	}
	virtual ~figure()
	{

	}

	virtual double calcArea() = 0;
	virtual void show() = 0;
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
};
class rectangle :public figure
{
private: double* h, * w;
public:
	rectangle() 
	{
		h = new double;
		*h = 1;
		w = new double;
		*w = 1;
	};
	rectangle(double h2, double w2) 
	{
		h = new double;
		*h = h2;
		w = new double;
		*w = w2;
	};
	~rectangle() { delete h, w; };
	double calcArea() { return (*h) * (*w); };
	void show() { cout << "Rectangle" << endl << "Size: " << *h << "x" << *w << endl << "Area: " << calcArea() << endl; };
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
	rhombus(double getSide,double gethight) {
		side = new double;
		*side = getSide;
		hight = new double;
		*hight = gethight;
	};
	~rhombus() { delete side; };
	double calcArea() { return (*side**hight); };
	void show() { cout << "rhombus" << endl << "Side: " << *side << endl << "Hight: " << *hight << endl << "Area: " << calcArea() << endl; };
};

double cilindre(figure* fig, double v) { return fig->calcArea() * v; }
int main()
{
	cout << "Hello!\nWhat figure do you want?\nWrite a number: " << endl << "1 - circle\n2 - rectangle\n3 - rhombus\n0 - Exit!\n";
	int choise;
	cin >> choise;
	switch (choise) {
	case 1:
	{
		int radius;
		cout << "You picked a circle! Enter his radius: ";
		cin >> radius;
		figure* num1 = new circle(radius);
		num1->show();
		cout << "Object volume: " << cilindre(num1, 5) << endl;
		delete num1;
	}
	break;
	case 2:
	{
		int side1, side2;
		cout << "You picked a rectangle! Enter his sides:\n";
		cin >> side1 >> side2;
		figure* num2 = new rectangle(side1, side2);
		num2->show();
		cout << "Object: " << cilindre(num2, 5) << endl;
		delete num2;
	}
	break;
	case 3:
	{
		double side,hight;
		cout << "You picked a rhombus! Enter his side: ";
		cin >> side;
		cout << "Enter hight:";
		cin >> hight;
		figure* num3 = new rhombus(side,hight);
		num3->show();
		cout << "Object: " << cilindre(num3, 5) << endl;
		delete num3;
	}
	break;
	default:
		cout << "HEY Goodbye\n";
		exit(0);
	}
	return 0;
}