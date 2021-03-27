#include <gb/gb.h>
#include <stdio.h>
#include "PlayerSprites.c"

void main() {

    UINT8 currentSpriteIndex = 0; // unsigned 8-bit integer

    set_sprite_data(0, 2, Player); // loads player sprites as sprite '0'
    set_sprite_tile(0, 0); // sets sprite '0' to sprite index '0'
    move_sprite(0, 88, 78); // moves the sprite to roughly the centre of the screen
    
    SHOW_SPRITES; // shows the sprites on the gb screen

    while (1) {
        // simple animation to swap between the two sprites
        if (currentSpriteIndex == 0) {
            currentSpriteIndex = 1;
        }
        else {
            currentSpriteIndex = 0;
        }
        set_sprite_tile(0, currentSpriteIndex); // updates the '0' sprite to the current sprite index
        delay(1000); // an actual game would use something like a deltaTime check to wait because this hangs the entire program

        scroll_sprite(0, 10, 0); // moves the sprite horizontally
    }

}