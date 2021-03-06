#include "block.h"
#include "texture.h"
#include "game.h"
#include "board.h"

Block::Block()
{
	int randomBlock = std::rand() % 7;
	int randomColor = std::rand() % 3;
	blockType = randomBlock;
	color = randomColor;
	rotateType = 0;
}

void Block::init()
{

	for (int i = 0; i < 4; i++)
	{
		blockPiece[i].tileType = TILE::BLOCK;
	}
	isActive = true;
	switch (blockType)
	{
	case O:
		/*
		*  10  O block
		*  23
		*/

		blockPiece[0].pos.xpos = 6;
		blockPiece[0].pos.ypos = 1;
		blockPiece[1].pos.xpos = 5;
		blockPiece[1].pos.ypos = 1;
		blockPiece[2].pos.xpos = 5;
		blockPiece[2].pos.ypos = 2;
		blockPiece[3].pos.xpos = 6;
		blockPiece[3].pos.ypos = 2;
		break;
	case I:
		/*
		*	0123	0	I block
		*			1
		*			2
		*			3
		*/
		blockPiece[0].pos.xpos = 4;
		blockPiece[0].pos.ypos = 1;
		blockPiece[1].pos.xpos = 5;
		blockPiece[1].pos.ypos = 1;
		blockPiece[2].pos.xpos = 6;
		blockPiece[2].pos.ypos = 1;
		blockPiece[3].pos.xpos = 7;
		blockPiece[3].pos.ypos = 1;
		break;
	case S:
		/*
		*	 23		0	 S block
		*	01		12
		*			 3
		*
		*
		*/
		blockPiece[0].pos.xpos = 5;
		blockPiece[0].pos.ypos = 2;
		blockPiece[1].pos.xpos = 6;
		blockPiece[1].pos.ypos = 2;
		blockPiece[2].pos.xpos = 6;
		blockPiece[2].pos.ypos = 1;
		blockPiece[3].pos.xpos = 7;
		blockPiece[3].pos.ypos = 1;
		break;
	case Z:
		/*
		*	01		0
		*	 23	   12	 Z block
		*		   3
		*
		*/
		blockPiece[0].pos.xpos = 5;
		blockPiece[0].pos.ypos = 1;
		blockPiece[1].pos.xpos = 6;
		blockPiece[1].pos.ypos = 1;
		blockPiece[2].pos.xpos = 6;
		blockPiece[2].pos.ypos = 2;
		blockPiece[3].pos.xpos = 7;
		blockPiece[3].pos.ypos = 2;
		break;
	case L:
		/*
		*	123  3	   0	01	L block
		*	0	 2	 321	 2
		*		 10			 3
		*/
		blockPiece[0].pos.xpos = 5;
		blockPiece[0].pos.ypos = 2;
		blockPiece[1].pos.xpos = 5;
		blockPiece[1].pos.ypos = 1;
		blockPiece[2].pos.xpos = 6;
		blockPiece[2].pos.ypos = 1;
		blockPiece[3].pos.xpos = 7;
		blockPiece[3].pos.ypos = 1;
		break;
	case J:
		/*
		*	012	  10	0		0	J block
		*	  3	  2		123		1
		*		  3			   32
		*/
		blockPiece[0].pos.xpos = 5;
		blockPiece[0].pos.ypos = 1;
		blockPiece[1].pos.xpos = 6;
		blockPiece[1].pos.ypos = 1;
		blockPiece[2].pos.xpos = 7;
		blockPiece[2].pos.ypos = 1;
		blockPiece[3].pos.xpos = 7;
		blockPiece[3].pos.ypos = 2;
		break;
	case T:
		/*
		*	012		0		0		0	T block
		*	 3		12	   123	   12
		*			3				3
		*
		*/
		blockPiece[0].pos.xpos = 5;
		blockPiece[0].pos.ypos = 1;
		blockPiece[1].pos.xpos = 6;
		blockPiece[1].pos.ypos = 1;
		blockPiece[2].pos.xpos = 7;
		blockPiece[2].pos.ypos = 1;
		blockPiece[3].pos.xpos = 6;
		blockPiece[3].pos.ypos = 2;
		break;
	}
	isActive = true;
}

void Block::fall()
{
	if (isActive)
	{
		for (int i = 0; i < 4; i++)
		{
			blockPiece[i].pos.ypos++;
		}
	}
}

void Block::rotate()
{
	switch (blockType)
	{
	case I:
		if (rotateType == 0)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos + 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos - 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos + 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos + 1;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos - 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos + 2;
			rotateType = 1;
		}
		else if (rotateType == 1)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos - 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos + 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos - 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos - 1;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos + 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos - 2;
			rotateType = 0;
		}
		break;
	case S:
		if (rotateType == 0)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos + 1;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos - 2;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos - 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos + 1;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos + 1;
			rotateType = 1;
		}
		else if (rotateType == 1)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos - 1;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos + 2;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos + 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos - 1;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos - 1;
			rotateType = 0;
		}
		break;
	case Z:
		if (rotateType == 0)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos + 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos - 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos + 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos - 1;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos - 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos;
			rotateType = 1;

		}
		else if (rotateType == 1)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos - 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos + 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos - 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos + 1;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos + 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos;
			rotateType = 0;
		}
		break;
	case L:
		if (rotateType == 0)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos + 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos + 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos + 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos - 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos - 1;
			rotateType = 1;
		}
		else if (rotateType == 1)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos - 2;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos + 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos - 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos - 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos + 1;
			rotateType = 2;
		}
		else if (rotateType == 2)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos - 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos - 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos - 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos + 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos + 1;
			rotateType = 3;
		}
		else if (rotateType == 3)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos + 2;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos - 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos + 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos + 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos - 1;
			rotateType = 0;
		}
		break;
	case J:
		if (rotateType == 0)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos + 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos - 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos - 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos - 1;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos - 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos;
			rotateType = 1;
		}
		else if (rotateType == 1)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos - 2;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos - 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos + 1;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos + 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos - 1;
			rotateType = 2;
		}
		else if (rotateType == 2)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos + 1;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos + 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos + 1;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos - 2;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos + 1;
			rotateType = 3;
		}
		else if (rotateType == 3)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos - 1;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos + 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos + 1;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos - 1;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos + 2;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos;
			rotateType = 0;
		}
		break;
	case T:
		if (rotateType == 0)
		{

			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos + 1;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos - 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos;
			rotateType = 1;
		}
		else if (rotateType == 1)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos - 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos - 1;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos + 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos - 1;
			rotateType = 2;
		}
		else if (rotateType == 2)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos - 1;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos + 1;

			rotateType = 3;
		}
		else if (rotateType == 3)
		{
			blockPiece[0].pos.xpos = blockPiece[0].pos.xpos - 1;
			blockPiece[0].pos.ypos = blockPiece[0].pos.ypos + 1;
			blockPiece[1].pos.xpos = blockPiece[1].pos.xpos + 1;
			blockPiece[1].pos.ypos = blockPiece[1].pos.ypos;
			blockPiece[2].pos.xpos = blockPiece[2].pos.xpos + 1;
			blockPiece[2].pos.ypos = blockPiece[2].pos.ypos;
			blockPiece[3].pos.xpos = blockPiece[3].pos.xpos;
			blockPiece[3].pos.ypos = blockPiece[3].pos.ypos;

			rotateType = 0;
		}
		break;
	}
}

void Block::destroy()
{

}