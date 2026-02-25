#include <string.h>
#include "xinput_device.h"

void xinput_clear_report(uint8_t* report, uint8_t report_id, uint16_t len) {
    memset(report, 0, len);
    report[0] = 0x00;
    report[1] = 0x14;
}
