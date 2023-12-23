#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"
#include "Math.h"
#include "Palette.h"

void Start_SpriteUpgradeLamp() {
	SET_BIT_MASK(THIS->flags, S_PALETTE);
	UINT8 i;
	struct Sprite* spr;
	struct UpgradeInfo* data = (struct UpgradeInfo*)THIS->custom_data;
	data->upgradeType = UPGRADE_LAMP;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if (playerData->upgrades & data->upgradeType)
				SpriteManagerRemoveSprite(THIS);
		}
	}
}

void Update_SpriteUpgradeLamp() {
	UINT8 i;
	struct Sprite* spr;
	struct UpgradeInfo* data = (struct UpgradeInfo*)THIS->custom_data;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			if (CheckCollision(THIS, spr)) {
				struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
				playerData->upgrades = playerData->upgrades | data->upgradeType;
				PlayFx(CHANNEL_2, 10, 0x81, 0x84, 0xe2, 0x86);
				SpriteManagerRemoveSprite(THIS);
			}
		}
	}
}

void Destroy_SpriteUpgradeLamp() {
	BGP_REG = PAL_DEF(0, 1, 2, 3);
	OBP0_REG = OBP1_REG = PAL_DEF(3, 0, 1, 2);
}