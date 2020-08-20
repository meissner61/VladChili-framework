#pragma once
#include "Graphics.h"
#include "Player.h"
#include "Vec2.h"

class Enemy
{
public:
	//Enemy(int x_in, int y_in, int vx_in, int vy_in);
	void Init(const Vec2 position_in, const Vec2 velocity_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	bool IsColliding(Player& player)const;
	bool IsEaten()const;


private:

	float speed = 0.25f;
	Vec2 position;
	Vec2 velocity;

	bool isEaten = false;

	//Color color;

	

public:

	static constexpr float width = 20;
	static constexpr float height = 20;

};