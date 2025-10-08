/*
 * File:   main.c
 * Author: matej
 *
 * Created on August 8, 2024, 4:46 AM
 */

#include "config_bits.h"
#include "i2c.h"
#include "rtc.h"
#include "oled.h"

void main(void) {
    TRISDbits.RD0 = 0; 
    LATDbits.LATD0 = 1;
    
    OSCCONbits.IRCF = 0b111; // 16MHz
    
    i2c_init();
    oled_init();
    
//    oled_print_string("23/02/1976");
    
    unsigned char time = 0;

//    // Set seconds register (0x00) to 00 seconds
//    rtc_write_data(0x00, 0x00);  // Set seconds to 00 (BCD)
//
//    // Set minutes register (0x01) to 00 minutes
//    rtc_write_data(0x01, 0x15);  // Set minutes to 00 (BCD)
//
//    // Set hours register (0x02) to 07 hours (7:00 AM)
//    rtc_write_data(0x02, 0x07);  // Set hours to 07 (BCD) in 24-hour format
//
//    // Set day register (0x03) to 2 (Monday)
//    rtc_write_data(0x03, 0x02);  // Set day to 2 (BCD for Monday)
//
//    // Set date register (0x04) to 12th day of the month
//    rtc_write_data(0x04, 0x12);  // Set date to 12 (BCD)
//
//    // Set month register (0x05) to August (08)
//    rtc_write_data(0x05, 0x08);  // Set month to August (08 in BCD)
//
//    // Set year register (0x06) to 2024 (last two digits = 24)
//    rtc_write_data(0x06, 0x24);  // Set year to 24 (BCD)

    
    
    while(1) {
        oled_set_cursor(32, 3);
        rtc_write(0x02);
        unsigned char hours = rtc_read();
        unsigned char hours_ones = (hours & 0b00001111);
        unsigned char hours_tens = (hours & 0b00010000) >> 4;
        oled_print_char(hours_tens + '0');
        oled_print_char(hours_ones + '0');
        oled_print_char(':');
        
        rtc_write(0x01);
        unsigned char minutes = rtc_read();
        unsigned char minutes_ones = (minutes & 0b00001111);
        unsigned char minutes_tens = (minutes & 0b01110000) >> 4;
        oled_print_char(minutes_tens + '0');
        oled_print_char(minutes_ones + '0');
        oled_print_char(':');
        
        rtc_write(0x00);
        unsigned char seconds = rtc_read();
        unsigned char seconds_ones = (seconds & 0b00001111);
        unsigned char seconds_tens = (seconds & 0b01110000) >> 4;
        oled_print_char(seconds_tens + '0');
        oled_print_char(seconds_ones + '0');
        
        oled_set_cursor(32, 4);
        rtc_write(0x04);
        unsigned char date = rtc_read();
        unsigned char date_ones = (date & 0b00001111);
        unsigned char date_tens = (date & 0b00110000) >> 4;
        oled_print_char(date_tens + '0');
        oled_print_char(date_ones + '0');
        oled_print_char('/');
        
        rtc_write(0x05);
        unsigned char month = rtc_read();
        unsigned char month_ones = (month & 0b00001111);
        unsigned char month_tens = (month & 0b00010000) >> 4;
        oled_print_char(month_tens + '0');
        oled_print_char(month_ones + '0');
        oled_print_char('/');
        
        rtc_write(0x06);
        unsigned char year = rtc_read();
        unsigned char year_ones = (year & 0b00001111);
        unsigned char year_tens = (year & 0b11110000) >> 4;
        oled_print_char(year_tens + '0');
        oled_print_char(year_ones + '0');
        __delay_ms(2000);
    };
    
    return;
}
