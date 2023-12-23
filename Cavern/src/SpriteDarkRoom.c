#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Palette.h"

void Start_SpriteDarkRoom() {
	UINT8 i;
	struct Sprite* spr;
	struct UpgradeInfo* data = (struct UpgradeInfo*)THIS->custom_data;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if (playerData->upgrades & UPGRADE_LAMP)
			{

			}
			else
				BGP_REG = OBP0_REG =/* OBP1_REG =*/ PAL_DEF(3, 3, 3, 3);
			SpriteManagerRemoveSprite(THIS);
		}
	}
}

void Update_SpriteDarkRoom() {
}

void Destroy_SpriteDarkRoom() {

}