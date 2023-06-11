#ifndef __LORACONF_H__
#define __LORACONF_H__

#if (HAS_LORA)

//#define LORA_ABP

#ifdef LORA_ABP
/************************************************************
 * ABP configuration (for development)
 *
 * Get your
 *   - Network Session Key (NWKSKEY)
 *   - App Session Key and your (APPSKEY)
 *   - Device Address (DEVADDR)
 * from e.g. TTN console and replace the example values below.
 * 
 * NOTE: Use MSB format (as displayed in TTN console, so you can cut & paste
 * from there)
 *
 * NOTE: You may also need to adjust lorawan_abp.cpp in order to configure
 * different channels and data rate channels to match your country's regulations
 * and your network's settings.
 * 
 ************************************************************/

// ID of LoRaAlliance assigned Network (for a list, see e.g. here
// https://www.thethingsnetwork.org/docs/lorawan/prefix-assignments.html)
static const u1_t NETID = 0x13; // TTN
static const u1_t NWKSKEY[16] = {0xCE, 0x77, 0xDE, 0xF3, 0xBC, 0xFC, 0x2B, 0x9A, 0x85, 0xE6, 0x2B, 0x9B, 0xC0, 0x3A, 0x26, 0x67};
static const u1_t APPSKEY[16] = {0x0E, 0x2B, 0xB8, 0xE7, 0x04, 0x2B, 0x15, 0xB7, 0x86, 0x3F, 0x2F, 0x35, 0x92, 0x6D, 0xE9, 0xB8};
static const u4_t DEVADDR =
    0x00000000; // <-- Change this address for every node!

// set additional ABP parameters in loraconf_abp.cpp
void setABPParameters();

#else

/************************************************************
 * OTAA configuration
 * 
 * DEVEUI, APPEUI and APPKEY should all be specified in MSB format as 
 * displayed in TTN console, so you can cut & paste from there. This is different
 * from standard LMIC-Arduino which expects DEVEUI and APPEUI in LSB format.
 * For TTN, APPEUI in MSB format always starts with 0x70, 0xB3, 0xD5.
 * Set your DEVEUI here, if your device has have a fixed one. 
 * If you leave this untouched, then the DEVEUI will be derived from device's 
 * MAC adress during startup and will be displayed on device's screen as well as
 * on serial console, if you set 'verbose 1' in paxcounter.conf and 
 * 'debug_level 3' in platformio.ini.
 * If using a board with Microchip 24AA02E64 Uinique ID for deveui, the DEVEUI 
 * will be overwritten by the one contained in the Microchip module.
 *
 ************************************************************/

//static const u1_t DEVEUI[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//static const u1_t APPEUI[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//static const u1_t APPKEY[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const u1_t APPEUI[8]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
//static const u1_t APPEUI[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const u1_t DEVEUI[8]  = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xE7, 0x7E };
static const u1_t APPKEY[16] = { 0x00, 0x29, 0x2D, 0x42, 0x8E, 0xCE, 0xE9, 0x9E, 0x5A, 0xD7, 0x91, 0xEB, 0x9C, 0x62, 0x39, 0x4F };
                                 
#endif

#endif // HAS_LORA

#endif // __LORACONF_H__
