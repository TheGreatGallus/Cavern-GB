#include "Banks/SetBank2.h"
#include "ZGBMain.h"

#include "..\res\src\tiles.h"
//#include "..\res\src\map.h"
//#include "..\res\src\map2.h"
//#include "..\res\src\map3.h"

// Room loads
#include "..\res\src\endscreen.h"

//#include "..\res\src\playerMenu.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "InfoStructs.h"
#include "BankManager.h"
#include "Sound.h"
#include "Keys.h"
#include "Math.h"

#define RAM_START 0xA000
#define RAM_VARS_START 0xA0FF

UINT8 collision_tiles[] = { 1, 7, 8, 9, 10, 16, 17, 18, 19, 20, 21, 22, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
							101, 102, 103, 104, 105, 106, 107, 110, 0 };



void Start_StateEndScreen() {
	NR52_REG = 0x80; //Enables sound, you should always setup this first
	NR51_REG = 0xFF; //Enables all channels (left and right)
	NR50_REG = 0x77; //Max volume

	UINT8 i;
	HIDE_WIN;

	// Light up room
	//BGP_REG = OBP0_REG =/* OBP1_REG =*/ PAL_DEF(0, 1, 2, 3);
	BGP_REG = PAL_DEF(0, 1, 2, 3);
	OBP0_REG = OBP1_REG = PAL_DEF(3, 0, 1, 2);

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	//scroll_target = SpriteManagerAdd(SpritePlayerMenu, 15, 72);
	//SET_BIT_MASK(scroll_target->flags, S_FLIPX);
	

	InitScroll(&endscreen, collision_tiles, 0);

	SHOW_BKG;
}


void Update_StateEndScreen() {
	
}