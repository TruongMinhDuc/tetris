#pragma once
#ifndef BLOCK_H
#define BLOCK_H
#include <SDL.h>
#include "tile.h"
enum TYPE
{

	O, // RED
	I, // ORANGE
	S, // YELLOW
	Z, // GREEN
	L, // BLUE
	J, // PINK
	T, // PURPLE
};

class Block
{
private:
	int color;

public:
	Block();
	int blockType;
	int rotateType;

	int getColor() { return color; };
	bool isActive;
	Tile blockPiece[4];
	void init();
	void fall();
	void rotate();
	void destroy();
};
#endif /* BLOCK_H */