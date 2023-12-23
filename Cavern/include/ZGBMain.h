#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateGame)\
_STATE(StateMainMenu)\
_STATE(StateEndScreen)\
_STATE(StateTrueScreen)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteUpgradeBeam, upgradeBeam)\
_SPRITE_DMG(SpriteUpgradeBlock, upgradeBlock)\
_SPRITE_DMG(SpriteUpgradeDash, upgradeDash)\
_SPRITE_DMG(SpriteUpgradeGrip, upgradeGrip)\
_SPRITE_DMG(SpriteUpgradeLamp, upgradeLamp)\
_SPRITE_DMG(SpriteUpgradeShrink, upgradeShrink)\
_SPRITE_DMG(SpriteUpgradeSword, upgradeSword)\
_SPRITE_DMG(SpriteUpgradeWing, upgradeWing)\
_SPRITE_DMG(SpriteSlash, slash)\
_SPRITE_DMG(SpriteHeart, heart)\
_SPRITE_DMG(SpriteDarkRoom, darkroom)\
_SPRITE_DMG(SpriteSavePoint, savepoint)\
_SPRITE_DMG(SpriteEnemyThorn, thorn)\
_SPRITE_DMG(SpriteEnemyVertical, enemyvertical)\
_SPRITE_DMG(SpriteEnemyHorizontal, enemyhorizontal)\
_SPRITE_DMG(SpriteEnemyBounce, enemybounce)\
_SPRITE_DMG(SpriteEnemySwoop, enemyswoop)\
_SPRITE_DMG(SpriteEnemyBullet, enemybullet)\
_SPRITE_DMG(SpritePlayerMenu, menu)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"
void BankTest(unsigned char* tiles);

#endif