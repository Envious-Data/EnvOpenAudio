#include "tusb.h"
#include "usb_descriptors.h"
#include "class/audio/audio.h"  // Add this include for audio class definitions

// Define missing constants
#define AUDIO_SUBCLASS_AUDIOCONTROL     0x01
#define AUDIO_SUBCLASS_AUDIOSTREAMING   0x02
#define AUDIO_PROTOCOL_V1               0x00
#define AUDIO_CS_AS_GENERAL             0x01
#define AUDIO_CS_AS_FORMAT_TYPE         0x02
#define AUDIO_FORMAT_TYPE_I             0x01
#define AUDIO_EP_GENERAL                0x01

// Device Descriptor
tusb_desc_device_t const desc_device = {
  .bLength            = sizeof(tusb_desc_device_t),
  .bDescriptorType    = TUSB_DESC_DEVICE,
  .bcdUSB             = 0x0200,
  .bDeviceClass       = TUSB_CLASS_MISC,
  .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
  .bDeviceProtocol    = MISC_PROTOCOL_IAD,
  .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,

  .idVendor           = 0xCafe,
  .idProduct          = 0x4000,
  .bcdDevice          = 0x0100,

  .iManufacturer      = 0x01,
  .iProduct           = 0x02,
  .iSerialNumber      = 0x03,

  .bNumConfigurations = 1
};

// Configuration Descriptor
uint8_t const desc_fs_configuration[] = {
  // Configuration Descriptor
  9, TUSB_DESC_CONFIGURATION, 
  0x6B, 0x00, // Total length
  ITF_NUM_TOTAL, 1, CONFIG_NUM, 0x00, 0x80, 0xFA,

  // Audio Control Interface Descriptor
  9, TUSB_DESC_INTERFACE, ITF_NUM_AUDIO_CONTROL, 0x00, 0x00, TUSB_CLASS_AUDIO, AUDIO_SUBCLASS_AUDIOCONTROL, AUDIO_PROTOCOL_V1, 0x00,

  // Audio Streaming Interface Descriptor
  9, TUSB_DESC_INTERFACE, ITF_NUM_AUDIO_STREAMING, 0x00, 0x02, TUSB_CLASS_AUDIO, AUDIO_SUBCLASS_AUDIOSTREAMING, AUDIO_PROTOCOL_V1, 0x00,

  // Standard AS Interface Descriptor
  7, TUSB_DESC_CS_INTERFACE, AUDIO_CS_AS_GENERAL, 0x01, 0x01, 0x01, 0x00,

  // Audio Streaming Format Type Descriptor
  11, TUSB_DESC_CS_INTERFACE, AUDIO_CS_AS_FORMAT_TYPE, AUDIO_FORMAT_TYPE_I, 0x02, 0x02, 16, 1, 0x44, 0xAC, 0x00,

  // Endpoint Descriptor
  9, TUSB_DESC_ENDPOINT, EP_NUM_AUDIO_OUT, 0x09, 0x40, 0x00, 1, 0, 0,

  // Audio Data Endpoint Descriptor
  7, TUSB_DESC_CS_ENDPOINT, AUDIO_EP_GENERAL, 0x00, 0x00, 0x00, 0x00
};

char const* string_desc_arr[] = {
  (const char[]) { 0x09, 0x04 }, // Supported language is English (0x0409)
  "TinyUSB",                      // Manufacturer
  "TinyUSB Audio Device",         // Product
  "123456",                       // Serial number
};

uint8_t const* tud_descriptor_device_cb(void) {
  return (uint8_t const*) &desc_device;
}

uint8_t const* tud_descriptor_configuration_cb(uint8_t index) {
  (void) index;
  return desc_fs_configuration;
}

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
  (void) langid;
  return (uint16_t const*) string_desc_arr[index];
}