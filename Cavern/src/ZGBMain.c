#include "ZGBMain.h"
#include "Math.h"
#include "BankManager.h"
#include "TilesInfo.h"

UINT8 next_state = StateMainMenu;
const UINT8 WATER1 = 43;
const UINT8 WATER2 = 44;
unsigned char* waterTest;
UINT8 water = 0;

UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
	if(current_state == StateGame) {
		if(U_LESS_THAN(255 - (UINT16)*tile_ptr, N_SPRITE_TYPES)) {
			*tile = 0;
			return 255 - (UINT16)*tile_ptr;
		}

		*tile = *tile_ptr;
	}

	return 255u;
}