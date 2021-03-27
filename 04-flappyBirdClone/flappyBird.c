#include <gb/gb.h>
#include <stdio.h>
#include "BirdSprite.c"

#define MOVESPEED 10

void main() {

    // UINT8 currentSpriteIndex = 0; // unsigned 8-bit integer

    set_sprite_data(0, 2, Bird); // loads player sprites as sprite '0'
    set_sprite_tile(0, 0); // sets sprite '0' to sprite index '0'
    move_sprite(0, 58, 68); // moves the sprite to roughly the centre of the screen
    
    DISPLAY_ON;
    SHOW_SPRITES; // shows the sprites on the gb screen

    while(1) {
        switch(joypad()){
            case J_LEFT:
                scroll_sprite(0, -MOVESPEED, 0);
                break;
            case J_RIGHT:
                scroll_sprite(0, MOVESPEED, 0);
                break;
            case J_UP:
                scroll_sprite(0, 0, -MOVESPEED);
                break;
            case J_DOWN:
                scroll_sprite(0, 0, MOVESPEED);
                break;
        }

        delay(100);
    }

}