#include <iostream>
#include <cmath>

#include "point.h"
#include "circle.h"

#define M_PI 3.14159265358979323846;


Circle::Circle(Point aCenter, float aRadius)
{
	mCenter = aCenter;
	mRadius = aRadius;
}

Circle::Circle()
{
	mCenter = {0, 0};
	mRadius = 1;
}

Circle::Circle(const Circle& circle)
{
	mCenter = circle.mCenter;
	mRadius = circle.mRadius;
}

void Circle::setCenter(Point X)
{
	mCenter = X;
}

void Circle::setRadius(float x)
{
	mRadius = x;
	if (mRadius < 0) mRadius = 0;
}

Point Circle::getCenter()
{
	return mCenter;
}
float Circle::getRadius()
{
	return mRadius;
}

float Circle::getArea() const
{
	float ans = mRadius * M_PI;
	ans *= mRadius;
	return ans;
}
float Circle::getDistance(const Point& p) const
{
	return mCenter.distance(p) - mRadius;
}
bool Circle::isColliding(const Circle& c) const
{
	if (getDistance(c.mCenter) <= c.mRadius) return 1;
	else return 0;
}
void Circle::move(const Point& p)
{
	this->mCenter = this->mCenter + p;
}	