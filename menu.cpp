#include "menu.h"
#include <iostream>
#include "game.h"

bool Menu::init()
{
	bool success = true;
	if (TTF_Init() < 0)
	{
		printf("SDL_ttf could not initialize! %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Linear texture filltering not enabled!\n");
			success = false;
			return success;
		}
		//mau
		
			int r = rand() % (255 - 1 + 1) + 1;
			int g = rand() % (255 - 1 + 1) + 1;
			int b = rand() % (255 - 1 + 1) + 1;
		
		startText = new Text("font/novem___.ttf", "START", 30, 255, 255, 255);

		closeText = new Text("font/novem___.ttf", "EXIT", 30, 255, 255, 255);

		tetrisText = new Text("font/novem___.ttf", "T E T R I S", 80, r, g, b);

		arrowText = new Text("font/novem___.ttf", "+", 30, 255, 255, 255);

		textList[0] = tetrisText;
		textList[1] = startText;
		textList[2] = closeText;

		for (int i = 0; i < TEXT_COUNT; i++)
		{
			if (textList[i] == NULL)
			{
				success = false;
				return success;
			}
		}
		menu = MENU::START;
	}


	return success;
}

int Menu::run()
{
	int choose = MENU::NONE;
	while (choose == MENU::NONE)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					choose = menu;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					menu == MENU::START ? menu = MENU::CLOSE : menu = MENU::START;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					menu == MENU::START ? menu = MENU::CLOSE : menu = MENU::START;
				}
			}
			else if (event.type == SDL_QUIT)
				choose = MENU::CLOSE;
			
		}
		SDL_RenderClear(Game::renderer);
		renderText();
		SDL_RenderPresent(Game::renderer);
		SDL_Delay(10);
	}
	return choose;
}

void Menu::renderText()
{
	arrowDst.h = arrowText->getHeight();
	arrowDst.w = arrowText->getWidth();
	for (int i = 0; i < TEXT_COUNT; i++)
	{
		dst.h = textList[i]->getHeight();
		dst.w = textList[i]->getWidth();
		dst.x = SCREEN_WIDTH / 2 - dst.w / 2;
		dst.y = SCREEN_HEIGHT / 3 + dst.h / 2 + i * 100;
		if (textList[i] == tetrisText) {

			dst.h = textList[i]->getHeight();
			dst.w = textList[i]->getWidth();
			dst.x = SCREEN_WIDTH / 2 - dst.w / 2;
			dst.y = SCREEN_HEIGHT / 5 + dst.h / 2 + i * 100;

		}
		//chọn 
		if (menu == MENU::START && textList[i] == startText)
		{
			arrowDst.x = dst.x - 20;
			arrowDst.y = dst.y;
			arrowText->render(&arrowDst);
		}
		else if (menu == MENU::CLOSE && textList[i] == closeText)
		{
			arrowDst.x = dst.x - 20;
			arrowDst.y = dst.y;
			arrowText->render(&arrowDst);
		}
		textList[i]->render(&dst);
	}
}

void Menu::close()
{
	for (int i = 0; i < TEXT_COUNT; i++)
	{
		textList[i]->destroy();
	}

}

bool Menu::gameOver()
{
	Text* endText = new Text("font/novem___.ttf", "G A M E 0 V E R", 40, 255, 0, 0);
	SDL_Rect endDst;
	endDst.h = endText->getHeight();
	endDst.w = endText->getWidth();
	endDst.x = SCREEN_WIDTH / 2 - endDst.w / 2;
	endDst.y = SCREEN_HEIGHT / 2 - endDst.h / 2;
	bool gameContinue = true;
	while (1)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					break;
				}
			}
			
			else if (event.type == SDL_QUIT)
			{
				gameContinue = false;
				break;
			}

		}
		SDL_RenderClear(Game::renderer);
		endText->render(&endDst);
		SDL_RenderPresent(Game::renderer);
		SDL_Delay(10);
	}
	return gameContinue;
}



