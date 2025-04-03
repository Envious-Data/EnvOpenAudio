#ifndef USB_DESCRIPTORS_H_
#define USB_DESCRIPTORS_H_

#include "tusb.h"

// Configuration number
enum {
  CONFIG_NUM = 1,
  INTERFACE_NUM_TOTAL
};

// Interface number
enum {
  ITF_NUM_AUDIO_CONTROL = 0,
  ITF_NUM_AUDIO_STREAMING,
  ITF_NUM_TOTAL
};

// Endpoint numbers
enum {
  EP_NUM_AUDIO_OUT = 0x01,
  EP_NUM_AUDIO_IN = 0x81
};

// Audio control interface descriptor
extern tusb_desc_device_t const desc_device;
extern uint8_t const desc_fs_configuration[];
extern uint8_t const desc_hs_configuration[];
extern char const* string_desc_arr[];

#endif /* USB_DESCRIPTORS_H_ */
