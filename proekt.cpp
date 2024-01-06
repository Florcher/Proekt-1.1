#include <math.h>
#include "proekt.h"
#include <string>
#include <iostream>

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point& point_) :x(point_.x), y(point_.y) {

}

const Point& Point::operator=(const Point& rhs) {

	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;

		return *this;
	}

	return 1;
}


Line::Line() {
	start.x = start.y = 0;
	end.x = end.y = 0;
	koordinata.x = koordinata.y = 0;
	modul = 0;
}


Line::Line(std::string name_, int index_, Point start, Point end) :  start(start), end(end) {

	object::setName(name_);
	object::setIndex(index_);

	koordinata.x = end.x - start.x;
	koordinata.y = end.y - start.y;

	modul = sqrt(pow(koordinata.x, 2) + pow(koordinata.y, 2));

}

Line::Line(const Line& rhs) {

	this->setName(rhs.getName());
	this->setIndex(rhs.getindex());
	this->setKoordinata(rhs.getKoordinata());
	this->start = rhs.getStart();
	this->end = rhs.getEnd();
	
}
const Line& Line::operator= (const Line& rhs) {

	if (this != &rhs) {

		this->setName(rhs.getName());
		this->setIndex(rhs.getindex());
		this->start = rhs.getStart();
		this->end = rhs.getEnd();
		this->setKoordinata(rhs.getKoordinata());

		return *this;
	}

}

void Line::print() const {

	object::print();
	std::cout << "(" << koordinata.x << ", " << koordinata.y << ")" << "\n";
	std::cout << "modul = " << this->modul << "\n";
}



Rectangle::Rectangle(std::string name_, int index_, Point a, Point b, Point c, Point d) : object() {

	object::setName(name_);
	object::setIndex(index_);

	Point tochkitmp[4] = { a, b, c, d };

	uporyadochenie(tochkitmp);
	set_Koordinati_Vectorov();
	Area();
	Perimetr();
}

void Rectangle::uporyadochenie(const Point arr[]) {

	int iterator = 0;

	double xmin = arr[0].x;
	double ymin = arr[0].y;
	for (int i = 1; i < 4; i++) {
		if (arr[i].x < xmin && arr[i].y < ymin) {
			iterator = i;
		}
	}

	tochki[0].x = arr[iterator].x;
	tochki[0].y = arr[iterator].y;

	for (int i = 0; i < 4; i++) {
		if (arr[i].x == tochki[0].x && arr[i].y > tochki[0].y) {
			iterator = i;
		}
	}

	tochki[1].x = arr[iterator].x;
	tochki[1].y = arr[iterator].y;

	for (int i = 0; i < 4; i++) {
		if ((arr[i].x != tochki[0].x) && (arr[i].y != tochki[0].y)) {
			iterator = i;
		}
	}

	tochki[2].x = arr[iterator].x;
	tochki[2].y = arr[iterator].y;

	for (int i = 0; i < 4; i++) {
		if (arr[i].y == tochki[0].y && arr[i].x > tochki[0].x) {
			iterator = i;
		}
	}

	tochki[3].x = arr[iterator].x;
	tochki[3].y = arr[iterator].y;

}

void Rectangle::set_Koordinati_Vectorov() {

	Line line_of_storoni[4];
	Line AB{ "AB", 1, tochki[0], tochki[1] };
	Line BC{ "BC", 2, tochki[1], tochki[2] };
	Line CD{ "CD", 3, tochki[2], tochki[3] };
	Line DA{ "DA", 4, tochki[3], tochki[0] };

	line_of_storoni[0] = AB;
	line_of_storoni[1] = BC;
	line_of_storoni[2] = CD;
	line_of_storoni[3] = DA;

	for (int i = 0; i < 4; i++) {
		koordinatyVectorov[i].x = line_of_storoni[i].getKoordinataX();
		koordinatyVectorov[i].y = line_of_storoni[i].getKoordinataY();
	}

}

void Rectangle::Area() {

	Line shirina{ "AB", 1, tochki[0], tochki[1] };
	Line dlina{ "BC", 2, tochki[0], tochki[1] };

	area = dlina.getModul() * shirina.getModul();
}

void Rectangle::Perimetr() {

	Line shirina{ "AB", 1, tochki[0], tochki[1] };
	Line dlina{ "BC", 2, tochki[0], tochki[1] };

	perimetr = 2 * dlina.getModul() + 2 * shirina.getModul();
}

void Rectangle::print() const {

	object::print();
	for (int i = 0; i < 4; i++) {
		koordinatyVectorov[i].print();
	}

	std::cout << "perimetr = " << this->perimetr << "\n";
	std::cout << "area = " << this->area << "\n";
	

}
