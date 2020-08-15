#pragma once
#include "Graphics.h"
#include "Player.h"

class Enemy
{
public:
	//Enemy(int x_in, int y_in, int vx_in, int vy_in);
	void Init(int x_in, int y_in, int vx_in, int vy_in);
	void Draw(Graphics& gfx) const;
	void Update();
	bool IsColliding(Player& player)const;
	bool IsEaten()const;


private:

	float speed = 1.0f;
	int x;
	int y;
	int vx;
	int vy;

	bool isEaten = false;

	//Color color;

	

public:

	static constexpr int width = 20;
	static constexpr int height = 20;

};