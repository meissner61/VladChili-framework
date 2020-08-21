#include "Vec2.h"

Vec2::Vec2(float x_in, float y_in)
	:
	x(x_in),
	y(y_in)
{
	//x = x_in;
	//y = y_in;
}

Vec2 Vec2::operator+(const Vec2 & rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 & Vec2::operator+=(const Vec2 & rhs)
{
	//x += rhs.x;
	//y += rhs.y; //this is a viable way to do this but...

	//*this = *this + rhs; // or this...

	return *this = *this + rhs;

	//return *this; //returns a reference to ourselves
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(x*rhs,y*rhs);
}

Vec2 & Vec2::operator*=(float rhs)
{
	return *this = *this  * rhs;
}

Vec2 Vec2::operator-(const Vec2 & rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 & Vec2::operator-=(const Vec2 & rhs)
{
	return *this = *this  - rhs;
}

float Vec2::getLength() const
{
	//return sqrt(x*x + y * 2); //like this or...

	return sqrt(getLengthSq());
}

float Vec2::getLengthSq() const
{

	return x*x + y*2;
}

Vec2& Vec2::Normalize()
{
	return *this = GetNormalized();
}

Vec2 Vec2::GetNormalized() const
{


	const float length = getLength();

	if (length != 0.0f) // Be careful with equality and floating points
	{
		return *this * (1.0f / length);
	}
	return *this;
}
