#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/audio_i2s.h"
#include "tusb.h"
#include "usb_descriptors.h"

// I2S Configuration
#define I2S_BCK_PIN   5
#define I2S_WS_PIN    3
#define I2S_DATA_PIN  4

static struct audio_buffer_pool *producer_pool;

void init_i2s() {
    static audio_format_t audio_format = {
        .format = AUDIO_BUFFER_FORMAT_PCM_S16,
        .sample_freq = 44100,
        .channel_count = 2
    };

    static struct audio_buffer_format buffer_format = {
        .format = &audio_format,
        .sample_stride = 4
    };

    struct audio_i2s_config config = {
        .data_pin = I2S_DATA_PIN,
        .clock_pin_base = I2S_BCK_PIN,
        .dma_channel = 0,
        .pio_sm = 0
    };

    const audio_format_t *result = audio_i2s_setup(&audio_format, &config);
    if (!result) {
        printf("Failed to set up I2S\n");
        return;
    }

    producer_pool = audio_new_producer_pool(&buffer_format, 3, 256);
    audio_i2s_connect(producer_pool);
    audio_i2s_set_enabled(true);
}

// TinyUSB Callback
void tud_audio_tx_done_cb(uint8_t rhport) {
    // Handle USB audio transmission completion
}

void tud_audio_rx_done_cb(uint8_t rhport) {
    // Handle USB audio reception
    uint8_t audio_buffer[192];
    tud_audio_read(audio_buffer, sizeof(audio_buffer));
    audio_buffer_t *buffer = take_audio_buffer(producer_pool, true);
    memcpy(buffer->buffer->bytes, audio_buffer, sizeof(audio_buffer));
    buffer->sample_count = sizeof(audio_buffer) / 4;
    give_audio_buffer(producer_pool, buffer);
}

int main() {
    stdio_init_all();
    printf("Starting USB I2S DAC\n");

    // Initialize TinyUSB
    tusb_init();

    // Initialize I2S
    init_i2s();

    while (true) {
        tud_task(); // TinyUSB device task
    }

    return 0;
}