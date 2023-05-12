#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "../draw/draw.hpp"
#include "../physics/body.hpp"
#include "../physics/point.hpp"
#include "../physics/vector.hpp"


class Game
{
	private:
		Draw screen;
		Draw stats_scr;
		int current_chunk = 0;
		int jump = 0;
		int coins = 0;
		int heart = 10;
#ifdef USE_HACK
		bool fly = false;
#endif
		Map map;
		phy::Body player;
#ifdef USE_HACK
		void hack();
		int setCustom(Draw hack);
#endif
	public:
		Game();
		~Game();
		void run();
		void start();
		void play();
		void resume();
		bool exitGame();

		// Funzione che chiede all'utente di scegliere la dificoltà e ritorna: 0 per facile, 1 per medio, 2 per difficile
		int setDifficulty();
		void stats();
		void updateStats();
		bool pauseGame();

};

#endif
