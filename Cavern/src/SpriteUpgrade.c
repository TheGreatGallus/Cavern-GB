#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"
#include "InfoStructs.h"

const UINT8 anim_swordUpgrade[] = { 1, 0 };
const UINT8 anim_lanternUpgrade[] = { 1, 1 };
const UINT8 anim_dashUpgrade[] = { 1, 2 };
const UINT8 anim_beamUpgrade[] = { 1, 3 };
const UINT8 anim_shrinkUpgrade[] = { 1, 4 };
const UINT8 anim_wingUpgrade[] = { 1, 5 };
const UINT8 anim_gripUpgrade[] = { 1, 6 };
const UINT8 anim_otherUpgrade[] = { 1, 7 };

void Start_SpriteUpgrade() {
	/*UINT8 i;
	struct Sprite* spr;
	struct UpgradeInfo* data = (struct UpgradeInfo*)THIS->custom_data;
	data->upgradeType = UPGRADE_SHRINK;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if(playerData->upgrades & (data->upgradeType))
				SpriteManagerRemoveSprite(THIS);
		}
	}*/
	/*if ((data->upgradeType & (UPGRADE_SHRINK)))
			SetSpriteAnim(THIS, anim_doublejump, 15);*/

}

void Update_SpriteUpgrade() {
	UINT8 i;
	struct Sprite* spr;
	struct UpgradeInfo* data = (struct UpgradeInfo*)THIS->custom_data;
	if (data->upgradeType == UPGRADE_SWORD)
		SetSpriteAnim(THIS, anim_swordUpgrade, 15);
	if (data->upgradeType == UPGRADE_LAMP)
		SetSpriteAnim(THIS, anim_lanternUpgrade, 15);
	if (data->upgradeType == UPGRADE_DASH)
		SetSpriteAnim(THIS, anim_dashUpgrade, 15);
	if (data->upgradeType == UPGRADE_BEAM)
		SetSpriteAnim(THIS, anim_beamUpgrade, 15);
	if (data->upgradeType == UPGRADE_SHRINK)
		SetSpriteAnim(THIS, anim_shrinkUpgrade, 15);
	if (data->upgradeType == UPGRADE_WING)
		SetSpriteAnim(THIS, anim_wingUpgrade, 15);
	if (data->upgradeType == UPGRADE_GRIP)
		SetSpriteAnim(THIS, anim_gripUpgrade, 15);
	if (data->upgradeType == UPGRADE_SWORD)
		SetSpriteAnim(THIS, anim_swordUpgrade, 15);
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SpritePlayer) {
			struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
			if (playerData->upgrades & (data->upgradeType))
				SpriteManagerRemoveSprite(THIS);
			if (CheckCollision(THIS, spr)) {
				//struct PlayerInfo* playerData = (struct PlayerInfo*)spr->custom_data;
				playerData->upgrades = playerData->upgrades | data->upgradeType;
				SpriteManagerRemoveSprite(THIS);
			}
		}
	}
}

void Destroy_SpriteUpgrade() {

}