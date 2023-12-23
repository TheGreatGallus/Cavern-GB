#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"
#include "Math.h"

//struct EnemyInfo {
//	INT8 vy;
//};
const UINT8 anim_roof[] = { 1, 0 };
const UINT8 anim_swoop[] = { 1, 1 };

void Start_SpriteEnemySwoop() {
	THIS->coll_h = 8;
	THIS->coll_w = 8;
	/*THIS->lim_x = 432;
	THIS->lim_y = 432;*/
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	data->vx = 1;
	data->vy = 0;
	data->health = 1;
	data->playerPosX = 0;
	data->timer = -1;
	//SetSpriteAnim(THIS, anim_swoop, 15);

}

void Update_SpriteEnemySwoop() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	if(data->health <= 0)
		SpriteManagerRemoveSprite(THIS);
	UINT8 tile = TranslateSprite(THIS, 0, data->vy << delta_time);
	if (data->timer > 0)
	{
		SetSpriteAnim(THIS, anim_swoop, 15);
		if (data->timer >= 0) {
			//SET_BIT_MASK(THIS->flags, S_FLIPY);
			data->vy = -3;
		}
		if (data->timer > 4) {
			//SET_BIT_MASK(THIS->flags, S_FLIPY);
			data->vy = -2;
		}
		if (data->timer > 11) {
			//UNSET_BIT_MASK(THIS->flags, S_FLIPY);
			data->vy = -1;
		}
		if (data->timer > 18) {
			//UNSET_BIT_MASK(THIS->flags, S_FLIPY);
			data->vy = 0;
		}
		if (data->timer > 24) {
			//UNSET_BIT_MASK(THIS->flags, S_FLIPY);
			data->vy = 1;
		}
		if (data->timer > 31) {
			//UNSET_BIT_MASK(THIS->flags, S_FLIPY);
			data->vy = 2;
		}
		if (data->timer > 38) {
			//UNSET_BIT_MASK(THIS->flags, S_FLIPY);
			data->vy = 3;
		}
		//data->vy = 2 - jumpTimer / 4;
		if (data->timer % 2 == 0) {
			UINT8 tileX = TranslateSprite(THIS, data->vx << delta_time, 0);
			if (tileX != 0)
				data->vx = -data->vx;
		}
	}
	else {
		if (tile == 0) {
			/*data->vy = 3;*/
			
			data->timer = 0;
		}
		else {
			SetSpriteAnim(THIS, anim_roof, 15);
			data->vx = 0;
			//UNSET_BIT_MASK(THIS->flags, S_FLIPY);
		}
	}
	if (data->timer > -1)
		data->timer--;
	//playerPosX = data->playerPosX;
	if ((data->playerPosX == THIS->x / 8 + 1 || data->playerPosX == THIS->x / 8 + 2)&& data->timer == -1) {
		data->vx = 1;
		data->timer = 42;
	}
	if ((data->playerPosX == THIS->x / 8 - 1 || data->playerPosX == THIS->x / 8 - 2) && data->timer == -1) {
		data->vx = -1;
		data->timer = 42;
	}

		//SetSpriteAnim(THIS, anim_swoop, 10);
	

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

void Destroy_SpriteEnemySwoop() {

}