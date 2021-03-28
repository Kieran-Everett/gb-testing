#include <gb/gb.h>
#include <stdio.h>
#include "BirdSprite.c"
#include "PipeSprite.c"

void performantDelay(UINT8 numLoops) { // more efficient delay method
    UINT8 i;
    for (i = 0; i < numLoops; i++) {
        wait_vbl_done(); // waits until the frame has been drawn, ie frames
    }
}

void main() {

    UINT8 playerSprite = 0;
    INT8 playerLocation[2]; // stores two INT8, x and y of player

    UINT8 numberOfPipeSprites = 20; // The number of top sprites, the screen is 19/20 sprites long
    UINT8 pipeLocation[2];

    INT8 gravity = -1;
    INT16 currentSpeedY;

    playerLocation[0] = 58;
    playerLocation[1] = 68;
    currentSpeedY = 0;

    pipeLocation[0] = 170;
    pipeLocation[1] = 0;

    set_sprite_data(0, 1, Bird); // loads player sprites as sprite '0'
    set_sprite_tile(0, 0); // sets sprite '0' to sprite index '0'
    move_sprite(playerSprite, playerLocation[0], playerLocation[1]); // moves the sprite to roughly the centre of the screen

    set_sprite_data(1, 1, Pipe); // (Location in memory to write, number of tiles to write, where to get the tiles from)
    //set_sprite_tile(1, 1); // set sprite number 1 to memory location 1
    //move_sprite(1, pipeLocation[0], pipeLocation[1]);

    UINT8 i;
    for (i = 1; i < numberOfPipeSprites; i++) {
        set_sprite_tile(i, 1);
        move_sprite(i, pipeLocation[0], pipeLocation[1] + i * 8);
    }
    
    DISPLAY_ON;
    SHOW_SPRITES; // shows the sprites on the gb screen

    while(1) {

        // Player controls
        if (joypad() & J_A) {
            currentSpeedY = 5;
        }

        currentSpeedY = currentSpeedY + gravity;

        // Player movement
        if (!(playerLocation[1] - currentSpeedY > 160)) {
            playerLocation[1] = playerLocation[1] - currentSpeedY;
            move_sprite(playerSprite, playerLocation[0], playerLocation[1]);
        }

        pipeLocation[0] = pipeLocation[0] - 8;

        for (i = 1; i < numberOfPipeSprites; i++) {
            move_sprite(i, pipeLocation[0], pipeLocation[1] + i * 8);
        }

        performantDelay(5);
        //delay(100);

    }

}