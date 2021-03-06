#include "board.h"
#include "texture.h"
#include "game.h"

void Board::init()
{
	borderTexture = TextureLoader::loadTexture("pic/wood.png");
	emptyTexture = TextureLoader::loadTexture("pic/empty.png");
	redBlockTexture = TextureLoader::loadTexture("pic/red.png");
	orangeBlockTexture = TextureLoader::loadTexture("pic/orange.png");
	yellowBlockTexture = TextureLoader::loadTexture("pic/yellow.png");
	greenBlockTexture = TextureLoader::loadTexture("pic/green.png");
	blueBlockTexture = TextureLoader::loadTexture("pic/blue.png");
	pinkBlockTexture = TextureLoader::loadTexture("pic/pink.png");
	purpleBlockTexture = TextureLoader::loadTexture("pic/purple.png");

	srcR.x = 0;
	srcR.y = 0;
	srcR.w = TEXTURE_WIDTH;
	srcR.h = TEXTURE_HEIGHT;
	nextsrc.w = TEXTURE_WIDTH;
	nextsrc.h = TEXTURE_HEIGHT;
	dstR.x = SCREEN_WIDTH / 2 - BOARD_WIDTH / 2;
	dstR.y = 0;
	dstR.w = BOARD_WIDTH;
	dstR.h = BOARD_HEIGHT;
	dst.w = TEXTURE_WIDTH;
	dst.h = TEXTURE_HEIGHT;
	nextdst.w = TEXTURE_WIDTH;
	nextdst.h = TEXTURE_HEIGHT;

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			tileMap[i][j].pos.xpos = j;
			tileMap[i][j].pos.ypos = i;
			landedMap[i][j].pos.xpos = j;
			landedMap[i][j].pos.ypos = i;
			if (i == 0 || i == 21)
			{
				tileMap[i][j].tileType = TILE::BORDER;
				landedMap[i][j].tileType = TILE::BORDER;
			}
			if (j == 0 || j == 11)
			{
				tileMap[i][j].tileType = TILE::BORDER;
				landedMap[i][j].tileType = TILE::BORDER;
			}

		}
	}
}

void Board::draw()
{
	for (int i = 0; i < 22; i++)
	{
		dst.y = 32 + i * TEXTURE_HEIGHT;
		for (int j = 0; j < 12; j++)
		{
			dst.x = SCREEN_WIDTH / 2 - BOARD_WIDTH / 2 + j * TEXTURE_WIDTH;
			if (tileMap[i][j].tileType == TILE::BORDER)
			{
				tileMap[i][j].render(borderTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::EMPTY)
			{
				tileMap[i][j].render(emptyTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::RED)
			{
				tileMap[i][j].render(redBlockTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::ORANGE)
			{
				tileMap[i][j].render(orangeBlockTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::YELLOW)
			{
				tileMap[i][j].render(yellowBlockTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::GREEN)
			{
				tileMap[i][j].render(greenBlockTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::BLUE)
			{
				tileMap[i][j].render(blueBlockTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::PINK)
			{
				tileMap[i][j].render(pinkBlockTexture, &srcR, &dst);
			}
			else if (tileMap[i][j].tileType == TILE::PURPLE)
			{
				tileMap[i][j].render(purpleBlockTexture, &srcR, &dst);
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		nextdst.y = SCREEN_HEIGHT / 4 + i * TEXTURE_HEIGHT;
		for (int j = 0; j < 6; j++)
		{
			nextdst.x = 3 * SCREEN_WIDTH / 4 + j * TEXTURE_WIDTH;
			if (nextMap[i][j] == TILE::BORDER)
			{
				SDL_RenderCopy(Game::renderer, borderTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::EMPTY)
			{
				SDL_RenderCopy(Game::renderer, emptyTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::RED)
			{
				SDL_RenderCopy(Game::renderer, redBlockTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::ORANGE)
			{
				SDL_RenderCopy(Game::renderer, orangeBlockTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::YELLOW)
			{
				SDL_RenderCopy(Game::renderer, yellowBlockTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::GREEN)
			{
				SDL_RenderCopy(Game::renderer, greenBlockTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::BLUE)
			{
				SDL_RenderCopy(Game::renderer, blueBlockTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::PINK)
			{
				SDL_RenderCopy(Game::renderer, pinkBlockTexture, &srcR, &nextdst);
			}
			else if (nextMap[i][j] == TILE::PURPLE)
			{
				SDL_RenderCopy(Game::renderer, purpleBlockTexture, &srcR, &nextdst);
			}
		}
	}

}


void Board::setBlockOnMap(Block* block)
{
	for (int i = 0; i < 4; i++)
	{
		tileMap[block->blockPiece[i].pos.ypos][block->blockPiece[i].pos.xpos].tileType = TILE::BLOCK + block->blockType + 1;
	}
}

void Board::drawBlockOnNext(Block* block)
{
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			nextMap[i][j] = TILE::EMPTY;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		nextMap[block->blockPiece[i].pos.ypos + 1][block->blockPiece[i].pos.xpos - 3] = TILE::BLOCK + block->blockType + 1;
	}

}

void Board::clearBlockOnMap(Block* block)
{
	for (int i = 0; i < 4; i++)
	{
		tileMap[block->blockPiece[i].pos.ypos][block->blockPiece[i].pos.xpos].tileType = TILE::EMPTY;
	}
}

void Board::moveBlock(Block* block, int key)
{
	Block* temp = block;
	switch (key)
	{
	case SDLK_LEFT:
		for (int i = 0; i < 4; i++)
		{
			tileMap[temp->blockPiece[i].pos.ypos][temp->blockPiece[i].pos.xpos].tileType = TILE::EMPTY;
			temp->blockPiece[i].pos.xpos--;
		}
		break;
	case SDLK_RIGHT:
		for (int i = 0; i < 4; i++)
		{
			tileMap[temp->blockPiece[i].pos.ypos][temp->blockPiece[i].pos.xpos].tileType = TILE::EMPTY;
			temp->blockPiece[i].pos.xpos++;
		}
		break;
	}
}

void Board::rotateBlock(Block* block)
{
	for (int i = 0; i < 4; i++)
	{
		tileMap[block->blockPiece[i].pos.ypos][block->blockPiece[i].pos.xpos].tileType = EMPTY;
	}
	block->rotate();
}

bool Board:: checkLine(int& score)
{
	int count;
	bool gameOver = false;
	for (int i = 1; i < 11; i++)
	{
		if (landedMap[1][i].tileType >= TILE::BLOCK)
		{
			gameOver = true;
			return gameOver;
		}
	}
	for (int i = 1; i < 21; i++)
	{
		count = 0;
		for (int j = 1; j < 11; j++)
		{
			if (landedMap[i][j].tileType >= TILE::BLOCK)
			{
				count++;
				if (count == 10)
				{
					removeLine(i);
					score += 10;
					for (int k = i; k > 1; k--)
					{
						collapseLine(k);
					}
				}
			}
			else
				break;
		}
	}
	return gameOver;
}

void Board::removeLine(int line)
{
	for (int i = 1; i < 11; i++)
	{
		landedMap[line][i].tileType = TILE::EMPTY;
		tileMap[line][i].tileType = TILE::EMPTY;
	}
}

void Board::collapseLine(int line)
{
	for (int i = 1; i < 11; i++)
	{
		if (landedMap[line - 1][i].tileType >= TILE::BLOCK)
		{
			landedMap[line][i].tileType = landedMap[line - 1][i].tileType;
			landedMap[line - 1][i].tileType = TILE::EMPTY;

			tileMap[line][i].tileType = tileMap[line - 1][i].tileType;
			tileMap[line - 1][i].tileType = TILE::EMPTY;
		}
	}
}


void Board::destroy()
{
	SDL_DestroyTexture(borderTexture);
	SDL_DestroyTexture(emptyTexture);
	SDL_DestroyTexture(blockTexture);
}

