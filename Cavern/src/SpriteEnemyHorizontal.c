#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"

//struct EnemyInfo {
//	INT8 vy;
//};
const UINT8 anim_flutter[] = { 2, 0, 1 };

void Start_SpriteEnemyHorizontal() {
	THIS->coll_y = 1;
	THIS->coll_w = 8;
	THIS->coll_h = 6;
	THIS->lim_x = 432;
	//THIS->lim_y = 432;
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	data->vx = 1;
	data->health = 1;
	SetSpriteAnim(THIS, anim_flutter, 15);
}

void Update_SpriteEnemyHorizontal() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	if(data->health <= 0)
		SpriteManagerRemoveSprite(THIS);
	if (TranslateSprite(THIS, data->vx << delta_time, 0)) {
		data->vx = -data->vx;
	}

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
				attackData->damage = 0;
				PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
			}
		}
	}*/
}

void Destroy_SpriteEnemyHorizontal() {

}