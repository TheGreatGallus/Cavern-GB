#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Palette.h"
#include "Sound.h"
#include "Math.h"
#include "Scroll.h"

const UINT8 anim_idle[] = { 1, 0 };
const UINT8 anim_walk [] = { 4, 0, 1, 0, 2 };
const UINT8 anim_shrunk[] = { 1, 7 };
const UINT8 anim_jump[] = { 1, 3 };
const UINT8 anim_fall[] = { 1, 4 };

// This value is the position in the tile table for the image
const UINT8 FULL_HEALTH = 2;
const UINT8 EMPTY_HEALTH = 5;

const UINT8 FULL_BOOT = 2;
const UINT8 TWOTHIRD_BOOT = 3;
const UINT8 THIRD_BOOT = 4;
const UINT8 EMPTY_BOOT = 5;

INT8 iframes = 0;
INT8 jumpTimer = -1;
INT8 jumpCount = 0;
INT8 facing = 1;
INT8 chargeTimer = 0;
INT8 waterTimer = 1;

void Start_SpritePlayer() {
	THIS->coll_x = 2;
	THIS->coll_y = 2;
	THIS->coll_w = 12;
	THIS->coll_h = 14;
	THIS->lim_x = 8;
	THIS->lim_y = 8;
	struct PlayerInfo* data = (struct PlayerInfo*)THIS->custom_data;
	data->vy = 2;
	if(data->health == 0)
		data->health = 3;
	//data->facing = 1;
	SET_BIT_MASK(THIS->flags, S_PALETTE);
	if (data->facing < 0)
		SET_BIT_MASK(THIS->flags, S_FLIPX);
	//THIS->flags = S_PALETTE;
	data->damaged = 0;
	chargeTimer = 0;

	/*SET_BIT_MASK(data->upgrades, UPGRADE_SWORD);
	SET_BIT_MASK(data->upgrades, UPGRADE_LAMP);
	SET_BIT_MASK(data->upgrades, UPGRADE_DASH);
	SET_BIT_MASK(data->upgrades, UPGRADE_BEAM);
	SET_BIT_MASK(data->upgrades, UPGRADE_SHRINK);
	SET_BIT_MASK(data->upgrades, UPGRADE_WING);
	SET_BIT_MASK(data->upgrades, UPGRADE_GRIP);*/
	

	SetLifeHUD();
	SetBootHUD();
}


//#define	UPGRADE_WING		0x80U		// Check
//#define	UPGRADE_GRIP		0x40U		// 
//#define	UPGRADE_DASH		0x20U		// Check
//#define	UPGRADE_BEAM		0x10U		// Check
//#define	UPGRADE_SHRINK		0x08U		// Check
//#define	UPGRADE_BLOCK		0x04U		// 
//#define	UPGRADE_LAMP		0x02U		// Check
//#define	UPGRADE_SWORD		0x01U		// Check

void SetLifeHUD()
{
	struct PlayerInfo* data = (struct PlayerInfo*)THIS->custom_data;
	UINT8 j;
	for (j = 0; j < data->maxHealth; j++)
	{
		if (data->health > j)
			set_win_tiles(2 + j, 0, 1, 1, &FULL_HEALTH);
		else
			set_win_tiles(2 + j, 0, 1, 1, &EMPTY_HEALTH);
	}
}

void SetBootHUD()
{
	struct PlayerInfo* data = (struct PlayerInfo*)THIS->custom_data;
	UINT8 j;
	for (j = 0; j < 3; j++)
	{
		if (chargeTimer / 9 >= j) {
			if (chargeTimer / 9 == j) {
				if (chargeTimer % 9 < 3)
					set_win_tiles(16 + j, 0, 1, 1, &EMPTY_BOOT);
				else {
					if (chargeTimer % 9 < 6)
						set_win_tiles(16 + j, 0, 1, 1, &THIRD_BOOT);
					else
						set_win_tiles(16 + j, 0, 1, 1, &TWOTHIRD_BOOT);
				}
			}
			else
				set_win_tiles(16 + j, 0, 1, 1, &FULL_BOOT);
		}
		else
			set_win_tiles(16 + j, 0, 1, 1, &EMPTY_BOOT);
	}
}

void Update_SpritePlayer() {
	UINT8 i;
	struct Sprite* spr;
	struct PlayerInfo* data = (struct PlayerInfo*)THIS->custom_data;

	if (data->damaged == 1) {
		data->damaged = 0;
		if (iframes == 0) {
			data->health--;
			PlayFx(CHANNEL_1, 10, 0x4f, 0xc7, 0xf3, 0x73, 0x86);
			iframes = 40;
			SetLifeHUD();
		}
	}

	if (iframes > 0)
	{
		if(iframes % 4 == 2 || iframes % 4 == 3)
			/*BGP_REG = OBP0_REG =*/ OBP1_REG = PAL_DEF(3, 3, 3, 3);
		else
			/*BGP_REG = OBP0_REG =*/ OBP1_REG = PAL_DEF(3, 0, 1, 2);
	}

	if (KEY_TICKED(J_SELECT) && (data->upgrades & (UPGRADE_SHRINK))) {
		if (THIS->coll_h == 6)
		{
			UINT16 currX = THIS->x;
			UINT16 currY = THIS->y;
			THIS->coll_w = 12;
			THIS->coll_x = 2;
			UINT8 unmorphtile = TranslateSprite(THIS, 0, -8);
			THIS->x = currX;
			THIS->y = currY;
			if (unmorphtile == 0)
			{
				THIS->coll_y = 2;
				THIS->coll_h = 14;
				THIS->lim_x = 8;
				THIS->lim_y = 8;
				SetSpriteAnim(THIS, anim_idle, 15);

			}
			else {
				THIS->coll_x = 6;
				THIS->coll_w = 6;
			}
		}
		else {
			THIS->coll_x = 6;
			THIS->coll_y = 10;
			THIS->coll_w = 6;
			THIS->coll_h = 6;
			THIS->lim_x = 8;
			THIS->lim_y = 8;
			SetSpriteAnim(THIS, anim_shrunk, 15);
		}
	}
	UINT16 currX;
	UINT16 currY;
	UINT8 unmorphtile;

	/*if (KEY_PRESSED(J_UP))
	{
		TranslateSprite(THIS, 0, -3);
	}*/

	if (KEY_TICKED(J_A)) {
		if (jumpTimer == -1 || ((data->upgrades & (UPGRADE_WING) && jumpCount < 2))) {
			SetSpriteAnim(THIS, anim_jump, 10);
			if (THIS->coll_h == 6)
				SetSpriteAnim(THIS, anim_shrunk, 15);
			jumpCount++;
			jumpTimer = 42;
			data->vy = -2;
		}
	}
	if (KEY_RELEASED(J_A) && jumpTimer > 18) {
		jumpTimer = 18;
	}
	if ((data->upgrades & (UPGRADE_DASH)))
	{
		if (KEY_PRESSED(J_B))
		{
			if (chargeTimer < 27 && chargeTimer >= 0) {
				chargeTimer++;
				SetBootHUD();
			}
		}
		if (KEY_RELEASED(J_B))
		{
			if (chargeTimer >= 27) {
				chargeTimer = -20;
				SetBootHUD();
			}
			else {
				chargeTimer = 0;
				SetBootHUD();
			}
		}
	}
	
	UINT8 effectTile = 0;
	if (chargeTimer >= 0)
	{
		/*effectTile = GetScrollTile(THIS->x, THIS->y);
		if (&effectTile == 11u || &effectTile == 12u) 
			waterTimer++;
		else
			waterTimer = 1;*/
		if (KEY_PRESSED(J_LEFT)) {
			//data->facing = -1;
			data->facing = -1;
			SET_BIT_MASK(THIS->flags, S_FLIPX);
			if (jumpTimer == -1)
				SetSpriteAnim(THIS, anim_walk, 10);
			if (THIS->coll_h == 6)
				SetSpriteAnim(THIS, anim_shrunk, 15);
			//TranslateSprite(THIS, (waterTimer % 2)  * -1 << delta_time, 0);
			effectTile = TranslateSprite(THIS, -1 << delta_time, 0);
		}
		if (KEY_PRESSED(J_RIGHT)) {
			data->facing = 1;
			//data->facing = 1;
			UNSET_BIT_MASK(THIS->flags, S_FLIPX);
			if (jumpTimer == -1)
				SetSpriteAnim(THIS, anim_walk, 10);
			if (THIS->coll_h == 6)
				SetSpriteAnim(THIS, anim_shrunk, 15);
			/*TranslateSprite(THIS, (waterTimer % 2) * 1 << delta_time, 0);*/
			effectTile = TranslateSprite(THIS, 1 << delta_time, 0);
		}
		if (effectTile != 0 && (data->upgrades & (UPGRADE_GRIP)) && jumpTimer <= 18)
			jumpCount = 0;
		/*if (!KEY_PRESSED(J_LEFT) && !KEY_PRESSED(J_RIGHT))
			SetSpriteAnim(THIS, anim_idle, 15);*/
	}
	else {
		//TranslateSprite(THIS, data->facing * 3 << delta_time, 0);
		TranslateSprite(THIS, data->facing * 3 << delta_time, 0);
		chargeTimer++;
		if (chargeTimer == -1)
			jumpTimer = 18;
	}
	
	if (KEY_TICKED(J_B) && (data->upgrades & (UPGRADE_SWORD))) {
		if (THIS->coll_h == 14)
		{
			struct Sprite* slash;
			/*if (data->facing > 0)*/
			if (data->facing > 0)
			{
				slash = SpriteManagerAdd(SpriteSlash, THIS->x + 12, THIS->y+2);
			}
			else
			{
				slash = SpriteManagerAdd(SpriteSlash, THIS->x - 12, THIS->y+2);
				slash->flags = slash->flags | S_FLIPX;
			}
			struct AttackInfo* attackData = (struct AttackInfo*)slash->custom_data;
			attackData->lifespan = 4;
			attackData->damage = 1;
			if ((data->upgrades & (UPGRADE_BEAM)))
				attackData->hasBeam = 1;
			else
				attackData->hasBeam = 0;
			attackData->vx = 0;
		}
	}
	if (chargeTimer >= 0)
	{
		UINT8 tile = TranslateSprite(THIS, 0, data->vy << delta_time);
		if (jumpTimer > 0)
		{
			if (jumpTimer >= 0) {
				if (jumpTimer < 19)
					SetSpriteAnim(THIS, anim_fall, 10);
				if (THIS->coll_h == 6)
					SetSpriteAnim(THIS, anim_shrunk, 15);
				data->vy = 3;
			}
			if (jumpTimer > 4) {
				data->vy = 2;
			}
			if (jumpTimer > 11) {
				data->vy = 1;
			}
			if (jumpTimer > 18) {
				if (jumpTimer < 25)
					SetSpriteAnim(THIS, anim_idle, 10);
				if (THIS->coll_h == 6)
					SetSpriteAnim(THIS, anim_shrunk, 15);
				data->vy = 0;
			}
			if (jumpTimer > 24) {
				SetSpriteAnim(THIS, anim_jump, 10);
				if (THIS->coll_h == 6)
					SetSpriteAnim(THIS, anim_shrunk, 15);
				data->vy = -1;
			}
			if (jumpTimer > 31) {
				data->vy = -2;
			}
			if (jumpTimer > 38) {
				data->vy = -3;
			}

			//data->vy = 2 - jumpTimer / 4;
			jumpTimer--;
		}
		else {
			if (tile == 0) {
				/*data->vy = 3;*/
				jumpTimer = 13;
			}
		}
		if (tile != 0 && data->vy > 0) {
			jumpCount = 0;
			jumpTimer = -1;
		}
	}
	if (keys == 0) {
		
	}
	if (iframes > 0)
		iframes--;
	if (!KEY_PRESSED(J_LEFT) && !KEY_PRESSED(J_RIGHT) && jumpTimer == -1)
			SetSpriteAnim(THIS, anim_idle, 15);
	if (THIS->coll_h == 6)
		SetSpriteAnim(THIS, anim_shrunk, 15);
	//playerPosX = THIS->x;

	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpriteEnemyHorizontal || spr->type == SpriteEnemyThorn || spr->type == SpriteEnemyBounce || spr->type == SpriteEnemyVertical || spr->type == SpriteEnemySwoop || 
			spr->type == SpriteEnemyBullet) {
			struct EnemyInfo* enemyData = (struct EnemyInfo*)spr->custom_data;
			enemyData->playerPosX = THIS->x/8;
			//enemyData->playerPosX = 42;
			if (CheckCollision(THIS, spr) && iframes == 0) {
				data->health--;
				/*if (data->health <= 0)
					SetState(StateGame);*/
				if (data->health > 0)
				{
					/*PlayFx(CHANNEL_2, 10, 0x81, 0x84, 0xd7, 0x86);*/
					PlayFx(CHANNEL_1, 10, 0x4f, 0xc7, 0xf3, 0x73, 0x86);
					//PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
					iframes = 40;
					SetLifeHUD();
				}
			}
		}
		if (spr->type == SpriteSavePoint) {
			if (CheckCollision(THIS, spr)) {
				struct SaveInfo* saveData = (struct SaveInfo*)spr->custom_data;
				if (saveData->soundPlayed == 0) {
					PlayFx(CHANNEL_2, 10, 0x81, 0x84, 0xd7, 0x86);
					saveData->soundPlayed = 1;
				}
				saveData->hasSaved = 1;
				saveData->upgrades = data->upgrades;
				saveData->bosses = data->bosses;
				saveData->healthUpgrades = data->healthUpgrades;
				data->health = data->maxHealth;
				SetLifeHUD();
			}
		}
		if (spr->type == SpriteHeart) {
			if (CheckCollision(THIS, spr)) {
				struct UpgradeInfo* upgradeData = (struct UpgradeInfo*)spr->custom_data;
				SET_BIT_MASK(data->healthUpgrades, upgradeData->upgradeType);
				data->maxHealth++;
				data->health = data->maxHealth;
				PlayFx(CHANNEL_2, 10, 0x81, 0x84, 0xe2, 0x86);
				SpriteManagerRemoveSprite(spr);
				SetLifeHUD();
			}
		}
	}
}

void Destroy_SpritePlayer() {
}
