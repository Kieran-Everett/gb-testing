#include <gb/gb.h>
#include <stdio.h>
#include "BirdSprite.c"

void main() {

    UINT8 currentSpriteIndex = 0; // unsigned 8-bit integer

    set_sprite_data(0, 2, Bird); // loads player sprites as sprite '0'
    set_sprite_tile(0, 0); // sets sprite '0' to sprite index '0'
    move_sprite(0, 58, 68); // moves the sprite to roughly the centre of the screen
    
    SHOW_SPRITES; // shows the sprites on the gb screen

    while (1) {
        scroll_sprite(0, 0, 1); // moves the sprite horizontally
        delay(100);
    }

}