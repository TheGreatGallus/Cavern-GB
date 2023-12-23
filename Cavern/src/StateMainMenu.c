#include "Banks/SetBank2.h"
#include "ZGBMain.h"

#include "..\res\src\tiles.h"
//#include "..\res\src\map.h"
//#include "..\res\src\map2.h"
//#include "..\res\src\map3.h"

// Room loads
#include "..\res\src\mainmenu.h"

//#include "..\res\src\playerMenu.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "InfoStructs.h"
#include "BankManager.h"
#include "Sound.h"
#include "Keys.h"

#define RAM_START 0xA000
#define RAM_VARS_START 0xA0FF


//const UINT8 _mapWidth = 5;
//const UINT8 _map[] = 
//	{	2,	0,	0,	0,	0,	
//		2,	1,	1,	3,	3,
//		2,	0,	0,	3,	3	};
//const struct MapInfo* mapLayout[] = { &map, &map2, &map3 };
UINT8 collision_tiles[] = { 1, 7, 8, 9, 10, 16, 17, 18, 19, 20, 21, 22, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
							101, 102, 103, 104, 105, 106, 107, 110, 0 };



void Start_StateMainMenu() {
	NR52_REG = 0x80; //Enables sound, you should always setup this first
	NR51_REG = 0xFF; //Enables all channels (left and right)
	NR50_REG = 0x77; //Max volume

	UINT8 i;

	// Light up room
	//BGP_REG = OBP0_REG =/* OBP1_REG =*/ PAL_DEF(0, 1, 2, 3);
	BGP_REG = PAL_DEF(0, 1, 2, 3);
	OBP0_REG = OBP1_REG = PAL_DEF(3, 0, 1, 2);

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	

	/*WX_REG = 7;
	WY_REG = (144 - (1 << 3));*/
	//scroll_h_border = 2 << 3;

	//InitWindow(0, 0, &hud);
	/*InitWindow(0, 0, 22, 2, &hud);*/
	//SHOW_WIN;
	//scroll_target = SpriteManagerAdd(SpritePlayer, 0, 0);
	//scroll_target = SpriteManagerAdd(SpriteCursor, 31, 63);
	//SpriteManagerAdd(SpriteCursor, 0, 0);
	//struct PlayerInfo* playerData = (struct PlayerInfo*)scroll_target->custom_data;

	//// LOAD TEST
	ENABLE_RAM_MBC5;
	SWITCH_RAM_MBC5(0);
	UBYTE* RAM_Pointer = (UBYTE*)RAM_START;
	if (*RAM_Pointer == TRUE) 
		SpriteManagerAdd(SpritePlayerMenu, 32, 88);
	else
		SpriteManagerAdd(SpritePlayerMenu, 32, 72);
	DISABLE_RAM_MBC5;

	SpriteManagerAdd(SpritePlayerMenu, 15, 104);
	//SpriteManagerAdd(SpritePlayerMenu, 39, 104);
	

	
	//ScrollSetTiles(2, &tiles);
	InitScroll(&mainmenu, collision_tiles, 0);
	//UpdateAnimatedTiles();
	//FadeInDMG();

	//Blackout room, used in SpriteDarkRoom now
	//BGP_REG = OBP0_REG =/* OBP1_REG =*/ PAL_DEF(3, 3, 3, 3);

	//S_PALETTE

	SHOW_BKG;
}


void Update_StateMainMenu() {
	//BankTest(tiles.data->data);
	//BankTest(tiles.data->data);
	/*UdateAnimatedTiles(mapLayout[roomNumber - 1], collision_tiles, 0);*/
	UpdateWaterfallTiles();
	UINT8 i;
	struct Sprite* spr;
	//scroll_win(0, -1);
	
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayerMenu && spr->x == 32) {
			if (KEY_TICKED(J_A)) {
				if (spr->y == 72) {
					// SAVE TEST
					ENABLE_RAM_MBC5;
					SWITCH_RAM_MBC5(0);
					UBYTE* RAM_Pointer = (UBYTE*)RAM_START;
					// New File
					RAM_Pointer[0] = TRUE;
					RAM_Pointer[1] = 1;
					RAM_Pointer[2] = 2;
					RAM_Pointer[3] = 8;
					RAM_Pointer[4] = 0;
					//RAM_Pointer[5] = 26-1;
					RAM_Pointer[5] = 2-1;
					//RAM_Pointer[6] = 15-1;
					RAM_Pointer[6] = 15-1;
					RAM_Pointer[7] = 0;
					RAM_Pointer[8] = 0;

					// GB JAM END
					/*RAM_Pointer[0] = TRUE;
					RAM_Pointer[1] = 33;
					RAM_Pointer[2] = 2;
					RAM_Pointer[3] = 16;
					RAM_Pointer[4] = 0;
					RAM_Pointer[5] = 88/8-1;
					RAM_Pointer[6] = 72/8-1;
					RAM_Pointer[7] = 0;
					RAM_Pointer[8] = 0;
					RAM_Pointer[9] = 0;*/
					DISABLE_RAM_MBC5;

					/*RAM_Pointer[1] = saveRoomNumber;
					RAM_Pointer[2] = saveRoomWidth;
					RAM_Pointer[3] = saveRoomX;
					RAM_Pointer[4] = saveRoomY;
					RAM_Pointer[5] = (savePointX + 1) / 8;
					RAM_Pointer[6] = (savePointY + 1) / 8;
					RAM_Pointer[7] = saveData->upgrades;
					RAM_Pointer[8] = saveData->healthUpgrades;*/
					//UINT16 playerX = 72;
					//UINT16 playerY = 72;
					//UINT16 roomNumber = 33;
					//UINT8 roomX = 16;
					//UINT8 roomY = 0;
					//UINT8 roomWidth = 2;
				}

				SetState(StateGame);
			}
		}
	}
}