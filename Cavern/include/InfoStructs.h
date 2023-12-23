#ifndef INFO_STRUCTS_H
#define INFO_STRUCTS_H


// Updgrade Defs
#define	UPGRADE_WING		0x80U		// 6
#define	UPGRADE_GRIP		0x40U		// 7
#define	UPGRADE_DASH		0x20U		// 3
#define	UPGRADE_BEAM		0x10U		// 4
#define	UPGRADE_SHRINK		0x08U		// 5
#define	UPGRADE_BLOCK		0x04U		// x
#define	UPGRADE_LAMP		0x02U		// 2
#define	UPGRADE_SWORD		0x01U		// 1

// NOTE: Only 8 bytes per struct
struct AttackInfo {
	INT8 lifespan;
	INT8 damage;
	INT8 hasBeam;
	INT8 vx;




};

struct PlayerInfo {
	INT8 vy;
	INT8 health;
	INT8 maxHealth;
	INT8 healthUpgrades;
	INT8 facing;
	INT8 upgrades;
	INT8 bosses;
	INT8 damaged;
};

struct EnemyInfo {
	INT8 vx;
	INT8 vy;
	INT8 playerPosX;
	INT8 health;
	INT8 timer;
	INT8 startX;


};

struct UpgradeInfo {
	INT8 upgradeType;







};

struct SaveInfo {
	INT8 hasSaved;
	INT8 soundPlayed;
	INT8 upgrades;
	INT8 bosses;
	INT8 healthUpgrades;
};

#include <asm\gbz80\types.h>

#endif