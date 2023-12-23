#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"
#include "Math.h"
#include "Scroll.h"

//struct EnemyInfo {
//	INT8 vy;
//};
const UINT8 anim_flutterX[] = { 2, 0, 1 };
UINT8 bossItem;

void Start_SpriteBossLamp() {
	UINT8 i;
	struct Sprite* spr;
	bossItem = UPGRADE_LAMP;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if (playerData->bosses & bossItem)
				SpriteManagerRemoveSprite(THIS);
		}
	}
	THIS->coll_x = 2;
	THIS->coll_w = 12;
	THIS->coll_y = 2;
	THIS->coll_h = 12;
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	data->vx = 1;
	data->health = 1;
	SetSpriteAnim(THIS, anim_flutterX, 15);
}

void Update_SpriteBossLamp() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	if(data->health <= 0)
		SpriteManagerRemoveSprite(THIS);
	if (TranslateSprite(THIS, data->vx << delta_time, 0)) {
		data->vx = -data->vx;
	}

	UINT8 i;
	struct Sprite* spr;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			if (CheckCollision(THIS, spr)) {
				struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
				playerData->damaged = 1;
			}
		}
		if (spr->type == SpriteSlash) {
			if (CheckCollision(THIS, spr)) {
				struct AttackInfo* attackData = (struct AttackInfo*)spr->custom_data;
				data->health -= attackData->damage;
				attackData->damage = 0;
				PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
			}
		}
	}
}

void Destroy_SpriteBossLamp() {
	UINT8 i;
	struct Sprite* spr;
	bossItem = UPGRADE_LAMP;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			SET_BIT_MASK(playerData->bosses, bossItem);
			UnlockDoors();
		}
	}
}