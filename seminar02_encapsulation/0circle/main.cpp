#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "point.h"


using std::cout;
using std::endl;

class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
	Circle(Point aCenter, float aRadius)
	{
		mCenter = aCenter;
		mRadius = aRadius;
		if (mRadius < 0) mRadius = 0;
	}

	Circle()
	{
		mCenter = {0, 0};
		mRadius = 1;
	}

	Circle(const Circle& circle)
	{
		mCenter = circle.mCenter;
		mRadius = circle.mRadius;
	}

	Point getCenter()
	{
		return mCenter;
	}
    float getRadius()
	{
		return mRadius;
	}

	float getArea() const
	{
		return M_PI*mRadius*mRadius;
	}
    float getDistance(const Point& p) const
	{
		return sqrt(pow(p.mx - mCenter.mx, 2) + pow(p.my - mCenter.my, 2)) - mRadius;
	}
	bool isColliding(const Circle& c) const
	{
		if (getDistance(c.mCenter) <= c.mRadius) return 1;
		else return 0;
	}
	void move(const Point& p)
	{
		mCenter.mx += p.mx;
		mCenter.my += p.my;
	}	
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "Point p = " << p << endl;
	cout << "Point q = " << q << endl;
	cout << "p + q = " << p + q << endl;


	Circle a {{4, 1}, 3};
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.getArea() << endl;
	cout << "Distance from point p to circle a = " << a.getDistance(p) << endl;



	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;



	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;



}