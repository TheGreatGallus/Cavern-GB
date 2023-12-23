#include "Banks/SetBank2.h"
#include "ZGBMain.h"

#include "..\res\src\tiles.h"
//#include "..\res\src\map.h"
//#include "..\res\src\map2.h"
//#include "..\res\src\map3.h"

// Room loads
#include "..\res\src\room0.h"
#include "..\res\src\room1.h"
#include "..\res\src\room2.h"
#include "..\res\src\room3.h"
#include "..\res\src\room4.h"
#include "..\res\src\room5.h"
#include "..\res\src\room6.h"
#include "..\res\src\room7.h"
#include "..\res\src\room8.h"
#include "..\res\src\room9.h"
#include "..\res\src\room10.h"
#include "..\res\src\room11.h"
#include "..\res\src\room12.h"
#include "..\res\src\room13.h"
#include "..\res\src\room14.h"
#include "..\res\src\room15.h"
#include "..\res\src\room16.h"
#include "..\res\src\room17.h"
#include "..\res\src\room18.h"
#include "..\res\src\room19.h"
#include "..\res\src\room20.h"
#include "..\res\src\room21.h"
#include "..\res\src\room22.h"
#include "..\res\src\room23.h"
#include "..\res\src\room24.h"
#include "..\res\src\room25.h"
#include "..\res\src\room26.h"
#include "..\res\src\room27.h"
#include "..\res\src\room28.h"
#include "..\res\src\room29.h"
#include "..\res\src\room30.h"
#include "..\res\src\room31.h"
#include "..\res\src\room32.h"
#include "..\res\src\room33.h"
#include "..\res\src\room34.h"
#include "..\res\src\room35.h"
#include "..\res\src\room36.h"
#include "..\res\src\room37.h"
#include "..\res\src\room38.h"
#include "..\res\src\room39.h"
#include "..\res\src\room40.h"
#include "..\res\src\room41.h"
#include "..\res\src\room42.h"
#include "..\res\src\room43.h"
#include "..\res\src\room44.h"
#include "..\res\src\room45.h"
#include "..\res\src\room46.h"
#include "..\res\src\room47.h"
#include "..\res\src\room48.h"
#include "..\res\src\room49.h"
#include "..\res\src\room50.h"
#include "..\res\src\room51.h"
#include "..\res\src\room52.h"
#include "..\res\src\room53.h"
#include "..\res\src\room54.h"
#include "..\res\src\room55.h"
#include "..\res\src\room56.h"
#include "..\res\src\room57.h"
#include "..\res\src\room58.h"
#include "..\res\src\room59.h"
#include "..\res\src\room60.h"
#include "..\res\src\room61.h"
#include "..\res\src\room62.h"
#include "..\res\src\room63.h"
#include "..\res\src\room64.h"



#include "..\res\src\enemy.h"
#include "..\res\src\player.h"
#include "..\res\src\hud.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "InfoStructs.h"
#include "BankManager.h"
#include "Sound.h"
#include "Math.h"

#define RAM_START 0xA000
#define RAM_VARS_START 0xA0FF

extern UINT8* test_mod_Data[];

UINT8 collision_tiles[] = { 1, 7, 8, 9, 10, 16, 17, 18, 19, 20, 21, 22, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 
							101, 102, 103, 104, 105, 106, 107, 110, 0 };

//const UINT8 _mapWidth = 5;
//const UINT8 _map[] = 
//	{	2,	0,	0,	0,	0,	
//		2,	1,	1,	3,	3,
//		2,	0,	0,	3,	3	};
//const struct MapInfo* mapLayout[] = { &map, &map2, &map3 };

const UINT8 _mapWidth = 24;
const UINT8 _mapAnimatedTiles[] =	{	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,
										1,	1,	2,	2,	2,	2,	2,	2,	2,	2,
										2,	2,	2,	2,	2,	2,	2,	2,	2,	1,
										1,	1,	1,	3,	3,	3,	3,	3,	3,	3,
										3,	1,	3,	1,	1,	1,	1,	3,	3,	3,
										3,	3,	3,	3,	3,	3,	3,	3,	3,	3,
										2,	2,	1,	1,	1};
const UINT8 _map[] =
  {	0,	0,	0,	0,	64,	63,	62,	62,	1,	0,	0,	0,	0,	0,	32,	32,	33,	33,	34,	35,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	30,	31,	31,	32,	32,	0,	38,	34,	52,	52,	0,	0,	0,
	0,	0,	0,	0,	0,	3,	2,	2,	1,	29,	29,	30,	43,	0,	0,	0,	0,	38,	0,	0,	0,	0,	0,	0,
	0,	0,	6,	5,	5,	3,	4,	0,	0,	0,	0,	30,	44,	44,	44,	46,	0,	38,	39,	55,	0,	0,	0,	0,
	0,	0,	6,	5,	5,	3,	7,	7,	0,	28,	28,	30,	42,	42,	41,	41,	41,	40,	39,	0,	0,	0,	0,	0,
	0,	0,	6,	8,	8,	9,	10,	0,	12,	28,	28,	26,	27,	0,	0,	0,	0,	58,	39,	47,	47,	47,	48,	0,
	0,	0,	0,	0,	0,	9,	11,	11,	12,	0,	21,	26,	61,	60,	57,	0,	0,	58,	0,	0,	0,	49,	48,	0,
	0,	17,	15,	15,	14,	14,	13,	13,	12,	20,	21,	0,	0,	0,	57, 56,	56,	58,	51,	51,	50,	50,	48,	0,
	0,	0,	0,	18,	14,	14,	19, 19,	19,	20,	22,	0,	0,	0,	0,	0,	0,	0,	51,	51,	37,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	20,	23,	23,	25,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0  };
const struct MapInfo* mapLayout[] = {	&room0,		&room1,		&room2,		&room3,		&room4,		&room5,		&room6,		&room7,		&room8,		&room9,		
										&room10,	&room11,	&room12,	&room13,	&room14,	&room15,	&room16,	&room17,	&room18,	&room19,	
										&room20,	&room21,	&room22,	&room23,	&room24,	&room25,	&room26,	&room27,	&room28,	&room29,	
										&room30,	&room31,	&room32,	&room33,	&room34,	&room35,	&room36,	&room37,	&room38,	&room39,	
										&room40,	&room41,	&room42,	&room43,	&room44,	&room45,	&room46,	&room47,	&room48,	&room49,	
										&room50,	&room51,	&room52,	&room53,	&room54,	&room55,	&room56,	&room57,	&room58,	&room59,	
										&room60,	&room61,	&room62,	&room63,	&room64	};

// START ROOM
UINT16 playerX = 72;
UINT16 playerY = 288;
UINT16 roomNumber = 1;
UINT8 roomX = 8;
UINT8 roomY = 0;
UINT8 roomWidth = 1;

// MVM ROOM
//UINT16 playerX = 72;
//UINT16 playerY = 72;
//UINT16 roomNumber = 33;
//UINT8 roomX = 16;
//UINT8 roomY = 0;
//UINT8 roomWidth = 2;

// TEST ROOM
//UINT16 roomNumber = 0;
//UINT8 roomX = 16;
//UINT8 roomY = 0;
//UINT8 roomWidth = 2;
//UINT16 playerX = 36;
//UINT16 playerY = 256;

//UINT16 playerY = 72;

UINT8 saveRoomNumber = 0;
UINT8 saveRoomX = 0;
UINT8 saveRoomY = 0;
UINT8 saveRoomWidth = 0;
UINT16 savePointX = 0;
UINT16 savePointY = 0;
UINT8 hasloaded = 0;

//UINT8 roomHeight = 1; 
//unsigned char* water1;
//unsigned char* water2; 
//const UINT8 WATER1 = 43;
//const UINT8 WATER2 = 44;

void Start_StateGame() {
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

	

	WX_REG = 7;
	WY_REG = (144 - (1 << 3));
	//scroll_h_border = 2 << 3;

	InitWindow(0, 0, &hud);
	/*InitWindow(0, 0, 22, 2, &hud);*/
	SHOW_WIN;
	scroll_target = SpriteManagerAdd(SpritePlayer, 72, 72);
	struct PlayerInfo* playerData = (struct PlayerInfo*)scroll_target->custom_data;
	//if (roomNumber == 64 || (roomNumber == 62 && !(playerData->upgrades & (UPGRADE_BLOCK))))
	if (roomNumber == 63) {
		if (playerData->upgrades & (UPGRADE_BLOCK))
			SetState(StateTrueScreen);
		else
			SetState(StateEndScreen);
	}

	// LOAD TEST
	ENABLE_RAM_MBC5;
	SWITCH_RAM_MBC5(0);
	UBYTE* RAM_Pointer = (UBYTE*)RAM_START;
	if (*RAM_Pointer == TRUE && hasloaded == 0) {
		//PlayFx(CHANNEL_2, 10, 0x81, 0x84, 0xd7, 0x86);
		RAM_Pointer++;
		saveRoomNumber = *RAM_Pointer;
		RAM_Pointer++;
		saveRoomWidth = *RAM_Pointer;
		RAM_Pointer++;
		saveRoomX = *RAM_Pointer;
		RAM_Pointer++;
		saveRoomY = *RAM_Pointer;
		RAM_Pointer++;
		savePointX = (*RAM_Pointer)*8-1;
		RAM_Pointer++;
		savePointY = (*RAM_Pointer)*8-1;
		RAM_Pointer++;
		playerData->upgrades = *RAM_Pointer;
		RAM_Pointer++;
		playerData->healthUpgrades = *RAM_Pointer;
		playerData->maxHealth = 3;
		if ((playerData->healthUpgrades & (UPGRADE_GRIP)))
			playerData->maxHealth++;
		if ((playerData->healthUpgrades & (UPGRADE_BEAM)))
			playerData->maxHealth++;
		if ((playerData->healthUpgrades & (UPGRADE_SHRINK)))
			playerData->maxHealth++;
		if ((playerData->healthUpgrades & (UPGRADE_WING)))
			playerData->maxHealth++;
		playerData->health = playerData->maxHealth;
		hasloaded = 1;
		playerX = savePointX;
		playerY = savePointY;
		roomNumber = saveRoomNumber;
		roomX = saveRoomX;
		roomY = saveRoomY;
		roomWidth = saveRoomWidth;
	}
	DISABLE_RAM_MBC5;

	scroll_target->x = playerX;
	scroll_target->y = playerY;

	struct Sprite* heart;
	struct UpgradeInfo* heartData;		

	if (roomNumber == 6 && !(playerData->healthUpgrades & (UPGRADE_GRIP))) {
		heart = SpriteManagerAdd(SpriteHeart, 7*8, 7*8);
		heartData = (struct UpgradeInfo*)heart->custom_data;
		SET_BIT_MASK(heartData->upgradeType, UPGRADE_GRIP);
	}
	if (roomNumber == 7 && !(playerData->healthUpgrades & (UPGRADE_BEAM))) {
		heart = SpriteManagerAdd(SpriteHeart, 26*8, 14*8);
		heartData = (struct UpgradeInfo*)heart->custom_data;
		SET_BIT_MASK(heartData->upgradeType, UPGRADE_BEAM);
	}
	if (roomNumber == 52 && !(playerData->healthUpgrades & (UPGRADE_SHRINK))) {
		heart = SpriteManagerAdd(SpriteHeart, 16*8, 2*8);
		heartData = (struct UpgradeInfo*)heart->custom_data;
		SET_BIT_MASK(heartData->upgradeType, UPGRADE_SHRINK);
	}
	if (roomNumber == 48 && !(playerData->healthUpgrades & (UPGRADE_WING))) {
		heart = SpriteManagerAdd(SpriteHeart, 6*8, 6*8);
		heartData = (struct UpgradeInfo*)heart->custom_data;
		SET_BIT_MASK(heartData->upgradeType, UPGRADE_WING);
	}
	/*struct Sprite* upgrade;
	struct UpgradeInfo* upgradeData;
	if (roomNumber == 4) {
		upgrade = SpriteManagerAdd(SpriteUpgrade, 64, 64);
		upgradeData = (struct UpgradeInfo*)upgrade->custom_data;
		SET_BIT_MASK(upgradeData->upgradeType, UPGRADE_SWORD);
	}*/


	//SpriteManagerAdd(SpriteEnemy, 70, 50);

	//ScrollSetTiles(2, &tiles);
	InitScroll(mapLayout[roomNumber], collision_tiles, 0);
	//UpdateAnimatedTiles();
	//FadeInDMG();

	//Blackout room, used in SpriteDarkRoom now
	//BGP_REG = OBP0_REG =/* OBP1_REG =*/ PAL_DEF(3, 3, 3, 3);

	//S_PALETTE

	SHOW_BKG;
	
	//PlayMusic(test_mod_Data, 7, 1);

}

void ChangeRoom(INT8 direction, UINT8 Y)
{
	//OBP0_REG = OBP1_REG = PAL_DEF(3, 0, 1, 2);
	roomY += Y;
	// Can probably condense
	if (direction == 0) {
		roomWidth = 1;
		roomNumber = saveRoomNumber;
		roomX = saveRoomX;
		roomY = saveRoomY;
		playerX = savePointX;
		playerY = savePointY;
	}
	else {
		if (direction == -1)
			roomX -= 1;
		if (direction == 1)
			roomX += roomWidth;
		UINT8 currentIndex = roomX + (roomY * _mapWidth);
		UINT8 xShift = 0;
		UINT8 yShift = 0;
		roomNumber = _map[currentIndex];

		// iterate X
		while (_map[currentIndex - 1] == roomNumber)
		{
			roomX--;
			currentIndex--;
			xShift++;
		}

		// iterate Y
		while (_map[currentIndex - _mapWidth] == roomNumber)
		{
			roomY--;
			currentIndex -= _mapWidth;
			yShift++;
		}

		roomWidth = 1;
		// iterate roomWidth
		while (_map[currentIndex + 1] == roomNumber)
		{
			roomWidth++;
			currentIndex++;
		}

		playerX = xShift * SCREENWIDTH;
		playerY = yShift * SCREENHEIGHT;
	}
}

void FindRoomOrigin()
{

}

void Update_StateGame() {
	//BankTest(tiles.data->data);
	//BankTest(tiles.data->data);
	/*UdateAnimatedTiles(mapLayout[roomNumber - 1], collision_tiles, 0);*/
	if (_mapAnimatedTiles[roomNumber] == 1)
		UpdateWaterfallTiles();
	if (_mapAnimatedTiles[roomNumber] == 2)
		UpdateMushroomGlowTiles();
	if (_mapAnimatedTiles[roomNumber] == 3)
		UpdateTorchTiles();
	UINT8 i;
	struct Sprite* spr;
	//scroll_win(0, -1);
	
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if (playerData->health <= 0)
			{				
				roomNumber = saveRoomNumber;
				ChangeRoom(0, 0);
				//playerX = 72;
				spr->x = playerX;
				spr->y = playerY;
				SetState(StateGame);
			}
			//INT8 screenX = spr->x / SCREENWIDTH;
			UINT8 screenY = spr->y / SCREENHEIGHT;
			UINT8 screenYMod = spr->y % SCREENHEIGHT;

			if (spr->x < 4)
			{
				ChangeRoom(-1, screenY);
				playerX += SCREENWIDTH - 18;
				playerY += screenYMod;
				SetState(StateGame);
			}
			if (spr->x > roomWidth* SCREENWIDTH - 17)
			{
				ChangeRoom(1, screenY);
				playerX += 4;
				playerY += screenYMod;
				SetState(StateGame);
			}	
		}
		if (spr->type == SpriteSavePoint) {
			struct SaveInfo* saveData = (struct SaveInfo*)spr->custom_data;
			if (saveData->hasSaved == 1)
			{
				saveData->hasSaved = 0;
				saveRoomNumber = roomNumber;
				saveRoomWidth = roomWidth;
				saveRoomX = roomX;
				saveRoomY = roomY;
				savePointX = spr->x;
				savePointY = spr->y;

				// SAVE TEST
				ENABLE_RAM_MBC5;
				SWITCH_RAM_MBC5(0);
				UBYTE* RAM_Pointer = (UBYTE*)RAM_START;
				RAM_Pointer[0] = TRUE;

				RAM_Pointer[1] = saveRoomNumber;
				RAM_Pointer[2] = saveRoomWidth;
				RAM_Pointer[3] = saveRoomX;
				RAM_Pointer[4] = saveRoomY;
				RAM_Pointer[5] = (savePointX+1)/8;
				RAM_Pointer[6] = (savePointY+1)/8;
				RAM_Pointer[7] = saveData->upgrades;
				RAM_Pointer[8] = saveData->healthUpgrades;
				DISABLE_RAM_MBC5;
			}
		}
	}
}