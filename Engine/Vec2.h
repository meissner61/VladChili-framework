#pragma once
class Vec2
{

public:
	Vec2() = default;
	Vec2(float x_in, float y_in);
	Vec2 operator+(const Vec2& rhs) const; // lhs + rhs left hand side + righ hand side
	Vec2& operator+=(const Vec2& rhs); //addition assignment operators are strange because they SHOULD return a refernce to the LHS in order to chain more assignments
	Vec2 operator*(float rhs)const;
	Vec2& operator*=(float rhs);

private:
	float x;
	float y;
};