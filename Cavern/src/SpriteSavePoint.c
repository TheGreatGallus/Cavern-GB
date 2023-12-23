#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Keys.h"

//struct SlashInfo {
//	INT8 lifespan;
//};

void Start_SpriteSavePoint() {
	THIS->coll_x = 8;
	THIS->coll_w = 16;
	THIS->coll_y = 0;
	THIS->coll_h = 16;
	THIS->flags = S_PALETTE;
	struct SaveInfo* data = (struct SaveInfo*)THIS->custom_data;
	data->hasSaved = 0;
	data->soundPlayed = 0;
}

void Update_SpriteSavePoint() {
	//UINT8 i;
	//struct Sprite* spr;
	//struct SaveInfo* data = (struct SaveInfo*)THIS->custom_data;
	//SPRITEMANAGER_ITERATE(i, spr) {
	//	if (spr->type == SpritePlayer) {
	//		if (CheckCollision(THIS, spr)) {
	//			if (KEY_TICKED(J_DOWN)) {
	//				struct PlayerInfo* playerData = (struct PlayerInfo*)THIS->custom_data;
	//				playerData->health = 3;
	//				data->hasSaved = 1;
	//			}
	//		}
	//	}
	//}
}

void Destroy_SpriteSavePoint() {

}