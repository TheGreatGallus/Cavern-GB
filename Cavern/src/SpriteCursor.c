#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Palette.h"
#include "Sound.h"
#include "Math.h"
#include "Scroll.h"

const UINT8 anim_cursor[] = { 1, 0 };

void Start_SpriteCursor() {
	SetSpriteAnim(THIS, anim_cursor, 10);
}

void Update_SpriteCursor() {
	
}

void Destroy_SpriteCursor() {
}