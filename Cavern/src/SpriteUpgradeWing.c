#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Sound.h"

void Start_SpriteUpgradeWing() {
	UINT8 i;
	struct Sprite* spr;
	struct UpgradeInfo* data = (struct UpgradeInfo*)THIS->custom_data;
	data->upgradeType = UPGRADE_WING;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if (playerData->upgrades & data->upgradeType)
				SpriteManagerRemoveSprite(THIS);
		}
	}
}

void Update_SpriteUpgradeWing() {
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

void Destroy_SpriteUpgradeWing() {

}