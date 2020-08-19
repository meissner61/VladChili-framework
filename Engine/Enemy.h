#pragma once
#include "Graphics.h"
#include "Player.h"

class Enemy
{
public:
	//Enemy(int x_in, int y_in, int vx_in, int vy_in);
	void Init(float x_in, float y_in, float vx_in, float vy_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	bool IsColliding(Player& player)const;
	bool IsEaten()const;


private:

	float speed = 0.25f;
	float x;
	float y;
	float vx;
	float vy;

	bool isEaten = false;

	//Color color;

	

public:

	static constexpr float width = 20;
	static constexpr float height = 20;

};