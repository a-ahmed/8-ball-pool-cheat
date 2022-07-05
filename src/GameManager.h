#pragma once

#include <basetsd.h>


// all you need to update its these i cant find the offsets anywere :bruh:


struct GameManager
{
	static bool   is9BallGame();
	static bool   isPlayerTurn();
	static int    getGameMode();
	static int    getState(), playerClassification();
	static SIZE_T getTable();

private:
	struct Offsets
	{
		static constexpr SIZE_T Rules        = 0x5CUL; // not quite sure its this one too :face_palm:
		static constexpr SIZE_T StateManager = 0x4UL; // not quite sure its the right one
		static constexpr SIZE_T Table        = 0x2ACUL; // didn`t found this btw you should search it
		static constexpr SIZE_T GameMode     = 0x370UL; // didn`t found this
        //static constexpr SIZE_T buffer = 0xCUL; u will see why i put this here soon........
	};
};

