#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"

void Start_SpriteHeart() {
	THIS->coll_y = 8;
	THIS->lim_x = 432;
	THIS->lim_y = 432;
}

void Update_SpriteHeart() {
	/*UINT8 i;
	struct Sprite* spr;
	struct UpgradeInfo* data = (struct UpgradeInfo*)THIS->custom_data;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			if (CheckCollision(THIS, spr)) {
				struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
				playerData->healthUpgrades = playerData->upgrades | data->upgradeType;
				playerData->maxHealth++;
				SpriteManagerRemoveSprite(THIS);
			}
		}
	}*/
}

void Destroy_SpriteHeart() {

}