#include "ZGBMain.h"
#include "Banks/SetBank2.h"
#include "SpriteManager.h"

struct EnemyInfo {
	INT8 vy;
};

void Start_SpriteEnemy() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	data->vy = 1;
}

void Update_SpriteEnemy() {
	struct EnemyInfo* data = (struct EnemyInfo*)THIS->custom_data;
	if (TranslateSprite(THIS, 0, data->vy)) {
		data->vy = -data->vy;
	}
}

void Destroy_SpriteEnemy() {

}