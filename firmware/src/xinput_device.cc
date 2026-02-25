#include <stdint.h>
#include <string.h>


// XInput 报告结构（固定20字节）
typedef struct __attribute__((packed)) {
    uint8_t  report_id;   // 0x00
    uint8_t  length;      // 0x14 (20)
    uint16_t buttons;
    uint8_t  lt;
    uint8_t  rt;
    int16_t  lx;
    int16_t  ly;
    int16_t  rx;
    int16_t  ry;
    uint8_t  reserved[6];
} xinput_report_t;

// 伪 HID 描述符（让框架能解析 usage 映射）
// 实际 XInput 走 Vendor class，这里只用于内部映射
const uint8_t our_report_descriptor_xinput[] = {
    0x05, 0x01,        // Usage Page (Generic Desktop)
    0x09, 0x05,        // Usage (Gamepad)
    0xA1, 0x01,        // Collection (Application)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x10,        //   Report Count (16)
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (1)
    0x29, 0x10,        //   Usage Maximum (16)
    0x81, 0x02,        //   Input (buttons)
    0x05, 0x01,        //   Usage Page (Generic Desktop)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x02,        //   Report Count (2)
    0x15, 0x00,        //   Logical Minimum (0)
    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x09, 0x33,        //   Usage (Rx) -> LT
    0x09, 0x34,        //   Usage (Ry) -> RT
    0x81, 0x02,        //   Input (triggers)
    0x75, 0x10,        //   Report Size (16)
    0x95, 0x04,        //   Report Count (4)
    0x16, 0x00, 0x80,  //   Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,  //   Logical Maximum (32767)
    0x09, 0x30,        //   Usage (X)  -> LX
    0x09, 0x31,        //   Usage (Y)  -> LY
    0x09, 0x32,        //   Usage (Z)  -> RX
    0x09, 0x35,        //   Usage (Rz) -> RY
    0x81, 0x02,        //   Input (sticks)
    0xC0,              // End Collection
};

static const int16_t xinput_stick_neutral = 0;
static const uint8_t xinput_trigger_neutral = 0;

void xinput_clear_report(uint8_t* report, uint8_t report_id, uint16_t len) {
    memset(report, 0, len);
    // 报告头固定值
    report[0] = 0x00;
    report[1] = 0x14;
}

const uint32_t our_report_descriptor_xinput_length = sizeof(our_report_descriptor_xinput);
