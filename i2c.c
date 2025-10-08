/*
 * File:   i2c.c
 * Author: matej
 *
 * Created on August 9, 2024, 6:33 AM
 */

#include "i2c.h"

void i2c_init() {
    SSP1STAT = 0b00000000;
    SSP1CON1 = 0b00101000;
    SSP1CON2 = 0b00000000;
    SSP1CON3 = 0b00000000;
    SSP1ADD = (FOSC / (4 * FCLOCK)) - 1; // 39 for 16MHz FOSC and 100kHz FCLOCK
}

void i2c_hold() {
    while((SSP1STAT & 0b00000101) || (SSP1CON2 & 0b00011111));
}

void i2c_start() {
    i2c_hold();
    SSP1CON2bits.SEN = 1;
}

void i2c_stop() {
    i2c_hold();
    SSP1CON2bits.PEN = 1;
}

void i2c_write(unsigned char data) {
    i2c_hold();
    SSPBUF = data;
}

unsigned char i2c_read(unsigned char ack) {
    i2c_hold();
    RCEN = 1;
    i2c_hold();
    unsigned char time = SSPBUF;
    
    ACKDT = ack;
    ACKEN = 1;
    return time;
}