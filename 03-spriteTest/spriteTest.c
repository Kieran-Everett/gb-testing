#include <gb/gb.h>
#include <stdio.h>
#include "PlayerSprites.c"

void main() {

    set_sprite_data(0, 2, Player);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    
    SHOW_SPRITES;

}