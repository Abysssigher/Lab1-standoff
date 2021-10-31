#ifndef __IR_CODES_H
#define __IR_CODES_H

/**
 * THESE CODES DO NOT WORK FOR THE REMOTE THAT COMES WITH THE ROMI.
 * 
 * They are for an old TV remote that I use to test code.
 */

// #define CHplus      8
// #define CHminus     9

// #define VOLplus     6
// #define VOLminus    7

// #define NUM_0       16
// #define NUM_9       25

// #define MUTE        40

// #define PREV        32
// #define BACK        29


    const uint16_t remoteAdressByte0 = 0x00;
    const uint16_t remoteAdressByte1 = 0xBF;
    const uint8_t remoteVolMinus = 0x00;
    const uint8_t remotePlayPause = 0x01;
    const uint8_t remoteVolPlus = 0x02;
    const uint8_t remoteSetup = 0x04;
    const uint8_t remoteUp = 0x05;
    const uint8_t remoteStopMode = 0x06;
    const uint8_t remoteLeft = 0x08;
    const uint8_t remoteEntersave = 0x09;
    const uint8_t remoteRight = 0x0A; 
    const uint8_t remote0 = 0x10;
    const uint8_t remoteDown = 0x0D;
    const uint8_t remoteBack = 0x0E;
    const uint8_t remote1 = 0x11;
    const uint8_t remote2 = 0x12;
    const uint8_t remote3 = 0x13;
    const uint8_t remote4 = 0x14;
    const uint8_t remote5 = 0x15;
    const uint8_t remote6 = 0x16;
    const uint8_t remote7 = 0x17;
    const uint8_t remote8 = 0x18;
    const uint8_t remote9 = 0x19;

#endif