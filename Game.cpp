#include "Game.h"
#include "GameState.h"

#include <iostream>

Game::Game()
{
	_oldTime = 0;
	_newTime = 0;

	_quit = false;
}
bool Game::init(GameState* state)
{
	_window.init();
	_stats = new Stats();
	_stats->SetStateGameplayEnd(EndMode::NOT_STARTED);

	pushState(state);

	return true;
}

void Game::thread()
{
	while (false == _quit) {
		update();
		render();
	}
	quit();
}
void Game::pushState(GameState* state)
{
	_states.push_back(state);

	if (_states.back()->Init(this) == false) {
		_quit = true;
	}
}
void Game::popState()
{
	_states.back()->Quit();
	delete _states.back();
	_states.pop_back();

	if (_states.size() == 0) {
		_quit = true;
	}
}
void Game::setQuit()
{
	_quit = true;
}
SDL_Renderer* Game::getRenderer()
{
	return _window.getRenderer();
}
void Game::update()
{
	while (SDL_PollEvent(&_event)) {
		if (_states.size() > 0) {
			_states.back()->HandleEvents(&_event);
		}
	}

	if (_states.size() > 0) {
		_oldTime = _newTime;
		_newTime = SDL_GetTicks();

		if (_newTime > _oldTime) {
			float deltaTime = (float)(_newTime - _oldTime) / 1000.0f;

			_states.back()->Update(deltaTime);
			//std::cout << deltaTime << std::endl;
		}
	}
}
void Game::render()
{
	SDL_RenderClear(_window.getRenderer());

	if (_states.size() > 0) {
		_states.back()->Render();
	}

	SDL_RenderPresent(_window.getRenderer());
}
void Game::quit()
{
	while (_states.size() > 0) {
		popState();
	}
	
	delete _stats;
	_stats = NULL;

	_window.quit();
	//SDL_DestroyWindow(_window);
	SDL_Quit();
}
int Game::getWidth()
{
	return   _window.getWidth();
}
int Game::getHeight()
{
	return _window.getHeight();
}
GameState* Game::getState()
{
	return _states.back();
}
Stats* Game::getStats()
{
	return _stats;
}