/*
 * File:   rtc.c
 * Author: matej
 *
 * Created on August 9, 2024, 8:12 AM
 */

#include "i2c.h"
#include "rtc.h"

void rtc_write(unsigned char reg) {
    i2c_start();
    i2c_write(RTC_WRITE);
    i2c_write(reg);
    i2c_stop();
}

void rtc_write_data(unsigned char reg, unsigned char data) {
    i2c_start();
    i2c_write(RTC_WRITE);
    i2c_write(reg);
    i2c_write(data);
    i2c_stop();
}

unsigned char rtc_read(void) {
    i2c_start();
    i2c_write(RTC_READ);
    unsigned char value = 0;
    if(!ACKSTAT) {
        value = i2c_read(0);
        i2c_read(1);
    }
    i2c_stop();
    
    return value;
}