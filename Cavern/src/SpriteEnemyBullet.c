#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"

//struct EnemyInfo {
//	INT8 vy;
//};
//const UINT8 anim_flutter[] = { 2, 0, 1 };

void Start_SpriteEnemyBullet() {
	THIS->coll_w = 8;
	THIS->coll_h = 8;
	//THIS->lim_x = 432;
	THIS->lim_y = 432;
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	if(THIS->x > 80)
		data->vx = -1;
	else
		data->vx = 1;
	data->startX = THIS->x / 8;
	//data->timer = 0;
	//data->health = THIS->y / 8 % 4;
	//THIS->x = 320;
	//SetSpriteAnim(THIS, anim_flutter, 15);
}

void Update_SpriteEnemyBullet() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	/*if(data->health <= 0)
		SpriteManagerRemoveSprite(THIS);*/
	if (TranslateSprite(THIS, data->vx << delta_time, 0)) {
		//SpriteManagerRemoveSprite(THIS);
		//THIS->x = data->startX * 8;
		THIS->x = data->startX * 8;
	}
	/*data->timer++;
	if (data->timer == 4) {
		data->timer = 0;
		if(data->health < 4)
			data->health++;
	}
	if (data->health == 4) {
		THIS->x = data->startX * 8;
		data->health = 5;
	}*/
	/*if (THIS->x == 320 && data->timer == data->health)
		THIS->x = data->startX * 8;*/

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

void Destroy_SpriteEnemyBullet() {

}