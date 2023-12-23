#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"

//struct EnemyInfo {
//	INT8 vy;
//};
const UINT8 anim_ground[] = { 1, 0 };
const UINT8 anim_hop[] = { 1, 1 };

void Start_SpriteEnemyBounce() {
	THIS->coll_y = 8;
	THIS->coll_h = 8;
	//THIS->lim_x = 432;
	//THIS->lim_y = 432;
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	data->vx = 1;
	data->health = 1;
	data->timer = 0;
	SetSpriteAnim(THIS, anim_ground, 15);
}

void Update_SpriteEnemyBounce() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	if(data->health <= 0)
		SpriteManagerRemoveSprite(THIS);
	UINT8 tile = TranslateSprite(THIS, 0, data->vy << delta_time);
	if (data->timer > 0)
	{
		SetSpriteAnim(THIS, anim_hop, 15);
		if (data->timer >= 0) {
			data->vy = 2;
		}
		if (data->timer > 4) {
			data->vy = 1;
		}
		if (data->timer > 11) {
			data->vy = 0;
		}
		if (data->timer > 18) {
			data->vy = -1;
		}
		if (data->timer > 24) {
			data->vy = -2;
		}
		//data->vy = 2 - jumpTimer / 4;
		UINT8 tileX = TranslateSprite(THIS, data->vx << delta_time, 0);
		if (tileX != 0)
			data->vx = -data->vx;
	}
	else {
		if (tile == 0) {
			/*data->vy = 3;*/
			data->timer = 13;
		}
		else
			SetSpriteAnim(THIS, anim_ground, 15);
	}
	data->timer--;
	if (data->timer <= -31)
		data->timer = 31;
	if (data->playerPosX > THIS->x / 8 + 1 && data->timer <= -1) {
		data->vx = 1;
		//data->timer = 42;
	}
	if (data->playerPosX < THIS->x / 8 - 1 && data->timer <= -1) {
		data->vx = -1;
		//data->timer = 42;
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

void Destroy_SpriteEnemyBounce() {

}