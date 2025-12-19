#include <gba.h>


int elixir = 0;
int frame_counter = 0;

int main(void) {

    REG_DISPCNT = MODE_0 | OBJ_1D_MAP | OBJ_ENABLE;

    while (1) {
        VBlankIntrWait();
        frame_counter++;


        if (frame_counter >= 120) {
            if (elixir < 10) elixir++;
            frame_counter = 0;
        }

        scanKeys();
        uint16 keys = keysDown();

     
        if ((keys & KEY_A) && elixir >= 3) {
            elixir -= 3;
        }
    }
}
