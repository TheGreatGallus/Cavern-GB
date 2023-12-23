#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Scroll.h"
#include "Sound.h"
#include "Math.h"

//struct SlashInfo {
//	INT8 lifespan;
//};

const UINT8 anim_sword[] = { 3, 0, 2, 3 };
const UINT8 anim_beam[] = { 1, 1 };
UINT8 beamCount = 0;

void Start_SpriteSlash() {
	/*struct AttackInfo* data = (struct AttackInfo*)THIS->custom_data;
	data->lifespan = 2;*/
	SetSpriteAnim(THIS, anim_sword, 30);
	THIS->coll_x = 2;
	THIS->coll_w = 12;
	THIS->coll_y = 4;
	THIS->coll_h = 12;
	THIS->flags = S_PALETTE;
}

void Update_SpriteSlash() {
	UINT8 i;
	struct Sprite* spr;
	struct AttackInfo* data = (struct AttackInfo*)THIS->custom_data;
	if (data->lifespan <= 0)
	{
		if (data->hasBeam == 1 && beamCount == 0) {
			SetSpriteAnim(THIS, anim_beam, 15);
			beamCount++;
			data->lifespan = 20;
			data->hasBeam = 0;
			THIS->coll_x = 4;
			THIS->coll_w = 8;
			THIS->coll_y = 4;
			THIS->coll_h = 8;
			THIS->y += 2;
			if (THIS->flags & S_FLIPX)
				data->vx = -2;
			else
				data->vx = 2;
		}
		else {
			SpriteManagerRemoveSprite(THIS);
		}
	}
	UINT8 tile = TranslateSprite(THIS, data->vx, 0);
	if (tile != 0 && data->vx != 0) {
		data->lifespan = 0;
		if (tile == 49)
			UnlockDoors();
	}

	data->lifespan--;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpriteEnemyHorizontal || spr->type == SpriteEnemyThorn || spr->type == SpriteEnemyVertical || spr->type == SpriteEnemyBounce || spr->type == SpriteEnemySwoop) {
			if (CheckCollision(THIS, spr)) {
				struct EnemyInfo* enemyData = (struct EnemyInfo*)spr->custom_data;
				enemyData->health -= data->damage;
				data->damage = 0;
				PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
				if (data->vx != 0)
					data->lifespan = 0;
				//SpriteManagerRemoveSprite(THIS);
				//SpriteManagerRemoveSprite(spr);
			}
		}
		if (spr->type == SpritePlayer && data->vx == 0) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if (playerData->facing > 0)
			{
				THIS->x = spr->x + 12;
				UNSET_BIT_MASK(THIS->flags, S_FLIPX);
			}
			else
			{
				THIS->x = spr->x - 12;
				SET_BIT_MASK(THIS->flags, S_FLIPX);
			}
			THIS->y = spr->y + 2;
		}
	}
}

void Destroy_SpriteSlash() {
	struct AttackInfo* data = (struct AttackInfo*)THIS->custom_data;
	if (data->vx != 0)
		beamCount--;
}