#include <stdio.h>

#include <gb/gb.h>

#include "Cursor.c"


UINT8 cursorSprite = 0;
UINT8 cursorLocation[2];


void performantDelay(UINT8 numLoops) {
    UINT8 i;
    for (i = 0; i < numLoops; i++) {
        wait_vbl_done();
    }
}

void main() {
    
    // Default cursor location
    cursorLocation[0] = 21; // Left max = 5, Right max = 163
    cursorLocation[1] = 21; // Up max = 13, Down max = 155

    set_sprite_data(0, 1, cursor);
    set_sprite_tile(cursorSprite, 0);
    move_sprite(cursorSprite, cursorLocation[0], cursorLocation[1]);

    SHOW_SPRITES;
    DISPLAY_ON;

    while(1) {

        switch(joypad()) {
            case J_LEFT:
                if (cursorLocation[0] != 5) {
                    cursorLocation[0] -= 2;
                    move_sprite(cursorSprite, cursorLocation[0], cursorLocation[1]);
                    break;
                }
                break;
            case J_RIGHT:
                if (cursorLocation[0] != 163) {
                    cursorLocation[0] += 2;
                    move_sprite(cursorSprite, cursorLocation[0], cursorLocation[1]);
                    break;
                }
                break;
            case J_UP:
                if (cursorLocation[1] != 13) {
                    cursorLocation[1] -= 2;
                    move_sprite(cursorSprite, cursorLocation[0], cursorLocation[1]);
                    break;
                }
                break;
            case J_DOWN:
                if (cursorLocation[1] != 155) {
                    cursorLocation[1] += 2;
                    move_sprite(cursorSprite, cursorLocation[0], cursorLocation[1]);
                    break;
                }
                break;
        }

        performantDelay(1);
    }

}