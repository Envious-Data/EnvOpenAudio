#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/audio_i2s.h"
#include "tusb.h"
#include "usb_descriptors.h"

#include <pico/stdio.h>

// I2S Configuration
#define I2S_BCK_PIN   5
#define I2S_WS_PIN    3
#define I2S_DATA_PIN  4

int main() {
    stdio_init_all();
    printf("\n || Starting USB I2S DAC|| \n");

    // Initialize TinyUSB
    tusb_init();
	printf("tud_init() called");


    while (true) {
        tud_task(); // TinyUSB device task
		printf("tud_task() called\n");
    }

    return 0;
}