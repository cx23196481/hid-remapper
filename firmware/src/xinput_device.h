#pragma once
#include <stdint.h>

#define XINPUT_VID 0x045E
#define XINPUT_PID 0x028E

extern const uint8_t our_report_descriptor_xinput[];
extern const uint32_t our_report_descriptor_xinput_length;

void xinput_clear_report(uint8_t* report, uint8_t report_id, uint16_t len);
