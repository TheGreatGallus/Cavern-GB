#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"

//struct EnemyInfo {
//	INT8 vy;
//};

void Start_SpriteEnemyThorn() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	data->vy = 0;
	data->health = 1;
	THIS->coll_y = 8;
}

void Update_SpriteEnemyThorn() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	if (data->health <= 0)
		SpriteManagerRemoveSprite(THIS);

	/*UINT8 i;
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
				PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
			}
		}
	}*/
}

void Destroy_SpriteEnemyThorn() {
	
}