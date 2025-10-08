/*
 * File:   oled.c
 * Author: matej
 *
 * Created on August 9, 2024, 8:17 AM
 */

#include "i2c.h"
#include "oled.h"
#include "font.h"

void oled_command(unsigned char command) {
    i2c_hold();
    i2c_start();
    i2c_write(OLED_ADDRESS);
    i2c_write(OLED_COMMAND);
    i2c_write(command);
    i2c_stop();
}

void oled_data(unsigned char data) {
    i2c_hold();
    i2c_start();
    i2c_write(OLED_ADDRESS);
    i2c_write(OLED_DATA);
    i2c_write(data);
    i2c_stop();
}

void oled_init() {
    oled_command(0xA8);
    oled_command(0x3F);
    oled_command(0xD3);
    oled_command(0x00);
    oled_command(0x40);
    oled_command(0xA1);
    oled_command(0xC8);
    oled_command(0xDA);
    oled_command(0x02);
    oled_command(0x81);
    oled_command(0x7F);
    oled_command(0xA4);
    oled_command(0xA6);
    oled_command(0xD5);
    oled_command(0x80);
    oled_command(0x8D);
    oled_command(0x14);
    oled_command(0xAF);
}

void oled_set_cursor(unsigned char x, unsigned char y) {
    oled_command(0x21);
    oled_command(x);
    oled_command(127);
    
    oled_command(0x22);
    oled_command(y);
    oled_command(7);
}

void oled_print_char(char c) {
    for(int i = 0; i < 8; i++) {
        char bitmap = font[(c - 32) * 8 + i];
        oled_data(bitmap);
    }
}

void oled_print_string(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        oled_print_char(str[i]);
    }
}