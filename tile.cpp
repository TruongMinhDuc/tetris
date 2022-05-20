#include "Tile.h"
#include <SDL.h>
#include "game.h"
#include "texture.h"

Tile::Tile()
{
	tileType = EMPTY;
	pos.xpos = 0;
	pos.ypos = 0;
}

void Tile::render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst)
{
	SDL_RenderCopy(Game::renderer, texture, src, dst);
}
