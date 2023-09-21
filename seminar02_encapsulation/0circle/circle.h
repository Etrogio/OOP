#pragma once

class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
	Circle(Point aCenter, float aRadius);
	Circle();
	Circle(const Circle& circle);

	void setCenter(Point X);
	void setRadius(float x);

	Point getCenter();
    float getRadius();

	float getArea() const;
    float getDistance(const Point& p) const;
	bool isColliding(const Circle& c) const;
	void move(const Point& p);
};