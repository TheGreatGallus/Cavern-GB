#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "InfoStructs.h"
#include "Palette.h"
#include "Sound.h"
#include "Math.h"
#include "Scroll.h"

const UINT8 anim_menucursor[] = { 1, 0 };
const UINT8 anim_menusit[] = { 1, 1 };
const UINT8 anim_menufire[] = { 2, 2, 3 };
UINT8 state = 0;

void Start_SpritePlayerMenu() {
	if (THIS->x == 39)
		SetSpriteAnim(THIS, anim_menufire, 10);
	if (THIS->x == 15)
		SetSpriteAnim(THIS, anim_menusit, 10);
	if (THIS->y == 88)
		state = 1;
}

void Update_SpritePlayerMenu() {
	if (THIS->x == 32) {
		if (KEY_TICKED(J_DOWN) || KEY_TICKED(J_UP)) {
			if (state == 0)
				state = 1;
			else
				state = 0;
		}
		if (state == 0)
			THIS->y = 72;
		else
			THIS->y = 88;
	}
	
}

void Destroy_SpritePlayerMenu() {
}