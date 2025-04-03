#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

//------------- General Config -------------//
#define TUSB_CFG_DEVICE_ENABLED             1
#define TUSB_CFG_HOST_ENABLED               0

#define TUSB_CFG_DEVICE_CDC_ENABLED         0
#define TUSB_CFG_DEVICE_MSC_ENABLED         0
#define TUSB_CFG_DEVICE_HID_ENABLED         0
#define TUSB_CFG_DEVICE_AUDIO_ENABLED       1
#define TUSB_CFG_DEVICE_DFU_ENABLED         0
#define TUSB_CFG_DEVICE_VENDOR_ENABLED      0

#define TUSB_CFG_HOST_CDC_ENABLED           0
#define TUSB_CFG_HOST_MSC_ENABLED           0
#define TUSB_CFG_HOST_HID_ENABLED           0
#define TUSB_CFG_HOST_AUDIO_ENABLED         0
#define TUSB_CFG_HOST_HUB_ENABLED           0
#define TUSB_CFG_HOST_VENDOR_ENABLED        0

#define TUSB_CFG_ATTR_POWERED               1
#define TUSB_CFG_ATTR_SELF_POWERED          0
#define TUSB_CFG_ATTR_REMOTE_WAKEUP         1

#define TUSB_CFG_ENDPOINT_MAX               6   // Max number of endpoints (including EP0)
#define TUSB_CFG_ENDPOINT0_SIZE             64

#define TUSB_CFG_DEVICE_TASK_STACK_SIZE     256
#define TUSB_CFG_DEVICE_TASK_PRIO           1
#define TUSB_CFG_DEVICE_TASK_AFFINITY       0 // Core 0

#define TUSB_CFG_RHPORT0_MODE               OPT_MODE_DEVICE

//------------- Class Driver Config -------------//

// Audio Class Driver
#define TUD_AUDIO_EP_BUFSIZE                512 // Size of the audio endpoint buffer
#define TUD_AUDIO_FUNC_1_N_CHANNELS         2   // Number of channels for function 1 (stereo)
#define TUD_AUDIO_FUNC_1_SAMPLE_RATE        44100 // Default sample rate for function 1
#define TUD_AUDIO_FUNC_1_BIT_DEPTH          16  // Bit depth for function 1

//------------- MCU Specific Config -------------//
#ifdef PICO_BOARD
  #define TUSB_CFG_OS                       TUSB_OS_NONE
  #define TUSB_CFG_PICO_USB_DMA_CHANNEL     0 // Or 1, depending on your setup
  #define TUSB_CFG_PICO_USB_DMA_IRQ_PRIORITY 0x80
#endif

#endif /* _TUSB_CONFIG_H_ */
