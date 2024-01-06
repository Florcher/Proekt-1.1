#pragma once
#include <iostream>
#include <string>

struct Point {

	Point(double = 0, double = 0);
	Point(const Point&);
	const Point& operator=(const Point&);
	~Point() {};
	

	void print() const { std::cout << "(" << x << ", " << y << ")\n"; };

	double x;
	double y;
    

};

class object {

public:

 
	object() {};
	virtual ~object() {};

	virtual void print() const { std::cout << name << "\n" << ind << "\n"; };

	void setName(const std::string& name_) { name = name_; };
	void setIndex(int index_) { ind = index_; };
    std::string getName() const { return name; };
	int getindex() const { return ind; };


private:

	std::string name;
	int ind;

};

class Line : public object{

public:

	Line();
    Line(std::string, int, Point, Point);
	Line(const Line&);
	const Line& operator=(const Line&);
	~Line() {};


	void setStart(Point start) { this->start = start; };
	void setEnd(Point end) { this->end = end; };
	void setKoordinata(Point koord) { this->koordinata = koord; };

	Point getStart() const { return start; };
	Point getEnd() const { return end; };
	Point getKoordinata() const { return koordinata; };

	double getKoordinataX() const { return koordinata.x; };
	double getKoordinataY() const { return koordinata.y; };
	double getModul() const { return modul; };

	void print() const override;

private:

	Point start, end, koordinata;

	double modul;
};


class Rectangle : public object {


public:

	Rectangle() {};
	Rectangle(std::string name_, int index_, Point a, Point b, Point c, Point d);
	~Rectangle() {};

	double getArea() const { return area; };
	double getPerimetr() const { return perimetr; };


	void print() const override;
	

private:

	Point tochki[4];
	Point koordinatyVectorov[4];
	
	double perimetr, area;

	void uporyadochenie(const Point arr[]);
	void set_Koordinati_Vectorov();
	void Area();
	void Perimetr();
};