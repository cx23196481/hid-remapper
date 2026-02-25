#pragma once
#include <stdint.h>

extern const uint8_t our_report_descriptor_xinput[];
void xinput_clear_report(uint8_t* report, uint8_t report_id, uint16_t len);
