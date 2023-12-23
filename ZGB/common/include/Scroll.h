#ifndef SCROLL_H
#define SCROLL_H

#include <gb/gb.h>
#include "TilesInfo.h"
#include "MapInfo.h"

#define SPRITE_UNIQUE_ID(TILE_X, TILE_Y) ((0x00FF & TILE_X) | ((0xFF00 & (TILE_Y << 8))))

extern unsigned char* scroll_map;
extern INT16 scroll_x;
extern INT16 scroll_y;
extern UINT16 scroll_w;
extern UINT16 scroll_h;
extern UINT16 scroll_tiles_w;
extern UINT16 scroll_tiles_h;
extern UINT8  scroll_collisions[128];
extern UINT8  scroll_collisions_down[128];
extern UINT8 scroll_tile_info[256];
extern UINT8  scroll_bank;
extern UINT8 scroll_offset_x;
extern UINT8 scroll_offset_y;

extern struct Sprite* scroll_target;
extern UINT8 clamp_enabled;

extern UINT8 scroll_top_movement_limit;
extern UINT8 scroll_bottom_movement_limit;

//void InitScrollTilesLEGACY(UINT8 first_tile, UINT8 n_tiles, UINT8* tile_data, UINT8 tile_bank);
//void ScrollSetMapLEGACY(UINT16 map_w, UINT16 map_h, unsigned char* map, UINT8 bank, unsigned char* color_map);
//void InitScrollLEGACY(UINT16 map_w, UINT16 map_h, unsigned char* map, const UINT8* coll_list, const UINT8* coll_list_down, UINT8 bank, unsigned char* color_map);

#define InitScrollTiles(FIRST_TILE, TILE_DATA) 
void ScrollSetTiles(UINT8 first_tile, const struct TilesInfo* tile_data);
void ScrollSetMap(const struct MapInfo* map_data);
void InitScroll(const struct MapInfo* map_data, const UINT8* coll_list, const UINT8* coll_list_down);
void InitScrollWithTiles(const struct MapInfo* map_data, const struct TilesInfo* tiles_info, const UINT8* coll_list, const UINT8* coll_list_down);

void InitWindow(UINT8 x, UINT8 y, struct MapInfo* map);
//void InitWindow(UINT8 x, UINT8 y, UINT8 w, UINT8 h, struct MapInfo* map);
void ScrollUpdateRow(INT16 x, INT16 y);
void ScrollUpdateColumn(INT16 x, INT16 y);
void MoveScroll(INT16 x, INT16 y);
void RefreshScroll();
void FinishPendingScrollUpdates();

void GetMapSize(const struct MapInfo* map, UINT8* tiles_w, UINT8* tiles_h);
UINT8* GetScrollTilePtr(UINT16 x, UINT16 y);
UINT8 GetScrollTile(UINT16 x, UINT16 y);
UINT8 ScrollFindTile(const struct MapInfo* map, UINT8 tile,
	UINT8 start_x, UINT8 start_y, UINT8 w, UINT8 h,
	UINT16* x, UINT16* y);
//void ScrollSetWaterfallTiles(UINT8 first_tile, const struct TilesInfo* tiles);
void UpdateWaterfallTiles();
void UpdateMushroomGlowTiles();
void UpdateTorchTiles();
void UnlockDoors();
//void InitWaterfallScrollWithTiles(const struct MapInfo* map_data, const struct TilesInfo* tiles_info, const UINT8* coll_list, const UINT8* coll_list_down);


#endif