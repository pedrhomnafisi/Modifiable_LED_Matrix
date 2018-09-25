/*
  Smart LED Project
  COP4331C
  Authors: Pedrhom Nafisi, Bo Williams, Daniel Ohana, Brandon Kessler
*/

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <PxMatrix.h>
#include <Ticker.h>

Ticker display_ticker;

// Pins for LED MATRIX
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_OE 2
#define P_D 12
#define P_E 0

// Hardware configuration using PxMATRIX library
PxMATRIX display(64, 32, P_LAT, P_OE, P_A, P_B, P_C, P_D, P_E);

// Some standard colors that can be used for manual LED configurations
uint16_t Red = display.color565(255, 0, 0);
uint16_t Green = display.color565(0, 255, 0);
uint16_t Blue = display.color565(0, 0, 255);
uint16_t Yellow = display.color565(255, 255, 0);
uint16_t White = display.color565(255, 255, 255);
uint16_t Black = display.color565(0, 0, 0);
uint16_t Cyan = display.color565(0, 255, 255);
uint16_t Magenta = display.color565(255, 0, 255);

uint16 colorArray[8] = {Red, Green, Blue, White, Yellow, Cyan, Magenta, Black};

// Array of RGB565 hex codes
// Code is setup in a manner in which the first 64 hex values represents the first row of LED's in the 64x32 MATRIX
uint16_t static UCF[] = {
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFD, 0xFFFB, 0xFFF8, 0xFFF9, 0xFFFD, 0xFFFE,   // 0x0010 (16) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0040 (64) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFD, 0xFFFC, 0xFFFA, 0xCDF1, 0x9C8C, 0x9CAD, 0x9CF1, 0xFFFF,   // 0x0050 (80) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0060 (96) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0070 (112) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0080 (128) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFC, 0xFFF8, 0xACC8, 0xA487, 0xA489, 0xFFFC, 0xFFFF, 0xFFDE, 0xFFFF,   // 0x0090 (144) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00A0 (160) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00C0 (192) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDD, 0xFFDC, 0xFFF9, 0xA487, 0xB4C6, 0xAC87, 0xFFF8, 0xFFDB, 0xFFFE, 0xFFFF, 0xFFDF,   // 0x00D0 (208) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00F0 (240) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0100 (256) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFD, 0xFFFA, 0xFFD5, 0xACA6, 0xB4A5, 0xACA7, 0xFFFA, 0xFFFB, 0xA4CC, 0xC5F1, 0xFFFC, 0xFFFE,   // 0x0110 (272) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0120 (288) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0130 (304) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0140 (320) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFB, 0xA4CA, 0xACA5, 0xAC83, 0xAC85, 0xFFF6, 0xFFFC, 0xFFFD, 0x8C09, 0xEF35, 0xFFFC, 0xFFFE,   // 0x0150 (336) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0160 (352) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0170 (368) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0180 (384) pixels
0xFFDF, 0xFFFF, 0xFFFF, 0xFFFD, 0x9CAA, 0xFFF3, 0xB482, 0xB4C3, 0xACE7, 0xFFF8, 0xFFFD, 0xFFFF, 0xFFFC, 0xFFDC, 0xFFFE, 0xFFFF,   // 0x0190 (400) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01A0 (416) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01B0 (432) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01C0 (448) pixels
0xFFFF, 0xFFFE, 0xFFFD, 0xFFB8, 0x9CA6, 0xCDC7, 0xBCA1, 0xB4A3, 0xE6D1, 0xFFFA, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFD,   // 0x01D0 (464) pixels
0xFFFD, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01E0 (480) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01F0 (496) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0200 (512) pixels
0xFFFE, 0xFFFD, 0xFFFA, 0x9CA8, 0xACE4, 0xB4C1, 0xBCC0, 0xACA4, 0xFFF9, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFC, 0xFFFA, 0xFFD9,   // 0x0210 (528) pixels
0xFFF9, 0xFFD9, 0xF759, 0xFFFD, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0220 (544) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0230 (560) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0240 (576) pixels
0xFFFF, 0xFFDC, 0xFFF7, 0xA485, 0xB4E2, 0xB4C0, 0xB480, 0xB4A4, 0xFFF9, 0xFFFE, 0xFFFF, 0xFFDD, 0xFFFB, 0xB52C, 0xAC88, 0xAC87,   // 0x0250 (592) pixels
0xA465, 0xACC8, 0x9C69, 0xFFFB, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0260 (608) pixels
0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0270 (624) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF,   // 0x0280 (640) pixels
0xFFFF, 0xFFFC, 0xFF53, 0xBCC4, 0xBCC2, 0xBCC1, 0xBCC0, 0xB4A3, 0x9C88, 0xFFFB, 0xFFFE, 0xFFFC, 0xA487, 0xB4A3, 0xB483, 0xBCA2,   // 0x0290 (656) pixels
0xBCA1, 0xB4C2, 0xACE7, 0xFFF9, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFDF,   // 0x02A0 (672) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02B0 (688) pixels
0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02C0 (704) pixels
0xFFFF, 0xFFFC, 0xB4C8, 0xB483, 0xB482, 0xB4A2, 0xBCA0, 0xB481, 0xA4A6, 0xFFF7, 0xFFFC, 0xFFF9, 0xB4C4, 0xBCA0, 0xBCA0, 0xBCA0,   // 0x02D0 (720) pixels
0xBCA0, 0xB4A1, 0xA4A5, 0xFFF8, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0x0841, 0x0021, 0x0881, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02E0 (736) pixels
0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0841, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x1082, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x02F0 (752) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0x1082, 0x0861, 0x1082, 0x0841, 0x0861, 0x0841, 0x0861, 0x0841, 0x0841, 0x0841, 0x0841, 0xFFDF, 0xFFFF,   // 0x0300 (768) pixels
0xFFFE, 0xFFFB, 0xACA6, 0xB483, 0xB4C5, 0xFFD1, 0xB4A1, 0xBCC1, 0xACA3, 0xFFF4, 0xFFF8, 0xA468, 0xB4A3, 0xBCA0, 0xBCA0, 0xBCA1,   // 0x0310 (784) pixels
0xB4A3, 0xB4C5, 0xA487, 0xFFF9, 0xFFFD, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0x0000, 0x0000, 0x0020, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0320 (800) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,   // 0x0330 (816) pixels
0x0000, 0x0000, 0xF7BE, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0020, 0x0841, 0x0000, 0x1082, 0x0020, 0x0000, 0x0000, 0x9CD3, 0xFFFF,   // 0x0340 (832) pixels
0xFFFC, 0xFF77, 0xB4E7, 0xB4A4, 0xAC84, 0xFFF2, 0xB4A1, 0xB480, 0xBCC2, 0xB4A4, 0xFFF4, 0xACA6, 0xB4A1, 0xBCC1, 0xB4A1, 0xBCE4,   // 0x0350 (848) pixels
0xFFF4, 0xA487, 0xACC9, 0xFFF8, 0xFFFB, 0xFFFD, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0020, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF,   // 0x0360 (864) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFDF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0370 (880) pixels
0x0841, 0x0000, 0xFFDF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF,   // 0x0380 (896) pixels
0xFFF9, 0x9C8A, 0xFFD4, 0xA4A4, 0xB4C3, 0xB4C2, 0xB4C3, 0xBCC3, 0xB460, 0xBCA2, 0xAC83, 0xACA4, 0xB4A1, 0xB481, 0xB4C4, 0xFFF5,   // 0x0390 (912) pixels
0xFFF9, 0xC5D0, 0xA489, 0xFFF5, 0xACC9, 0xFFF8, 0xFFFD, 0xFFFF, 0xFFFF, 0x0020, 0x0000, 0x0000, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x03A0 (928) pixels
0xFFFF, 0xFFDF, 0xFFFF, 0xFFDF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x94B2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x03B0 (944) pixels
0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0x0000, 0xFFFF,   // 0x03C0 (960) pixels
0xFFF8, 0x9C89, 0xFFF5, 0xACC5, 0xB4A1, 0xB4C1, 0xFFF1, 0xB483, 0xBCA1, 0xBC81, 0xB4C2, 0xFFEF, 0xAC82, 0xB4A3, 0xACA4, 0xB509,   // 0x03D0 (976) pixels
0xFFF9, 0xFFF9, 0xFF93, 0xA444, 0xACA5, 0xCDCD, 0xFFFC, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0001, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x03E0 (992) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x03F0 (1008) pixels
0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF,   // 0x0400 (1024) pixels
0xFFF8, 0xA4C9, 0xACC6, 0xACA3, 0xB4A1, 0xBCC2, 0xB4C3, 0xFF6E, 0xBCA2, 0xC4A1, 0xBCC0, 0xB4C1, 0xFFB1, 0xB4E7, 0xB4A3, 0xB4A4,   // 0x0410 (1040) pixels
0xFFF6, 0xFFF6, 0xB4A4, 0xB4A3, 0xACA5, 0xF733, 0xFFFC, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0420 (1056) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0430 (1072) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0020, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0440 (1088) pixels
0xFFFA, 0xDE92, 0xACA5, 0xFFF0, 0xBCA2, 0xB481, 0xACA1, 0xAC81, 0xC4E3, 0xBC81, 0xBCA0, 0xB4C1, 0xACA5, 0xFFF3, 0xB4A3, 0xB482,   // 0x0450 (1104) pixels
0xB4C6, 0xAC85, 0xBCA1, 0xBCA2, 0xAC84, 0xFFF7, 0xFFFC, 0xF7FF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0460 (1120) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0470 (1136) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFDF, 0xFFFF, 0xFFFF,   // 0x0480 (1152) pixels
0xFFFE, 0xFFDA, 0xB485, 0xB481, 0xB481, 0xB4C2, 0xB4C1, 0xB4E1, 0xAC61, 0xFF6D, 0xBCE4, 0xB4A2, 0xAC82, 0xB4A3, 0xFFF0, 0xACA3,   // 0x0490 (1168) pixels
0xACA3, 0xB4A2, 0xBCC1, 0xB4A2, 0xB4C6, 0xFFF7, 0xFFFD, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x04A0 (1184) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x04B0 (1200) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x04C0 (1216) pixels
0xFFFF, 0xFFFB, 0xB485, 0xBCA1, 0xFFEF, 0xB4A2, 0xB4A1, 0xACA1, 0xB4C2, 0xBCC3, 0xFFF0, 0xBCC3, 0xBCC3, 0xB4A3, 0xAC83, 0xB4E3,   // 0x04D0 (1232) pixels
0xACC0, 0xB4E1, 0xBCA2, 0xAC63, 0xB4C7, 0xFFD7, 0xFFDD, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x04E0 (1248) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0020, 0xFFDF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x04F0 (1264) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0020, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xA534, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0500 (1280) pixels
0xFFFF, 0xFFFB, 0xB4C5, 0xAC80, 0xB4A2, 0xFFF0, 0xAC83, 0xB4E3, 0xB4A1, 0xB4A0, 0xBCA1, 0xBCA3, 0xFFB1, 0xB4C5, 0xACA3, 0xF6EA,   // 0x0510 (1296) pixels
0xACC0, 0xB4E0, 0xAC83, 0xF6AE, 0xACA7, 0xFFF8, 0xFFFD, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0520 (1312) pixels
0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0530 (1328) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0540 (1344) pixels
0xFFFF, 0xFFFB, 0xDE4E, 0xB4C4, 0xAC82, 0xB4A2, 0xB4C3, 0xFFF0, 0xB4C2, 0xB4A1, 0xB4A1, 0xBCA2, 0xAC85, 0xFFF3, 0xACA4, 0xB4E3,   // 0x0550 (1360) pixels
0xB4E1, 0xACC2, 0xACA6, 0xFFF6, 0xA4A8, 0xFFF8, 0xFFFD, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0560 (1376) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0570 (1392) pixels
0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0x0000, 0x0000, 0x0020, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0580 (1408) pixels
0xFFDF, 0xFFFE, 0xFFFB, 0xAC88, 0xBCA3, 0xBC80, 0xB4A0, 0xB4C2, 0xB4C5, 0xFFF1, 0xB4C2, 0xB4C2, 0xB484, 0xB4A5, 0xFFF2, 0xAC84,   // 0x0590 (1424) pixels
0xFFF2, 0xACA7, 0xA489, 0xFFF8, 0x9C89, 0xFFF8, 0xFFFD, 0xFFDE, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x05A0 (1440) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0020, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x05B0 (1456) pixels
0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0x0020, 0x0000, 0x0000, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x05C0 (1472) pixels
0xFFFF, 0xFFFF, 0xFFFE, 0xFFF9, 0xB464, 0xBCA1, 0xB4A1, 0xB4A2, 0xB4A4, 0xB4C4, 0xB4C2, 0xFEEA, 0xFFF1, 0xAC84, 0xB4E6, 0xACA6,   // 0x05D0 (1488) pixels
0xFFF5, 0xA48A, 0xFFFA, 0xC5D2, 0xA4ED, 0xFFFA, 0xFFFD, 0xFFFF, 0xFFFF, 0x0020, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x05E0 (1504) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xEF7D, 0xFFDF, 0xFFFF, 0xFFDF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x05F0 (1520) pixels
0xFFFF, 0x0020, 0xA514, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0600 (1536) pixels
0xFFFF, 0xFFFF, 0xFFFE, 0xFFFA, 0xFF92, 0xCDA7, 0xB4A5, 0xB484, 0xB482, 0xBCA1, 0xBCC1, 0xB4A1, 0xB4A4, 0xFFF2, 0xACA6, 0xFFF4,   // 0x0610 (1552) pixels
0xFFF6, 0x9C6B, 0xFFFD, 0xFFDE, 0xFFFD, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0001, 0x0001, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0620 (1568) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0630 (1584) pixels
0xF7BE, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0640 (1600) pixels
0xFFDF, 0xFFFF, 0xFFFF, 0xFFFC, 0xA4EA, 0xA4C6, 0xFFF3, 0xFFF1, 0xBCA2, 0xBCA1, 0xBCA1, 0xB4A2, 0xACA4, 0xACC7, 0x9C87, 0xFFF7,   // 0x0650 (1616) pixels
0xA4EC, 0xFFFB, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0001, 0x0001, 0x0000, 0xFFBF, 0xFFFF, 0xFFFE,   // 0x0660 (1632) pixels
0xFFFF, 0xFFDF, 0x0020, 0x2104, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0861, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFDF,   // 0x0670 (1648) pixels
0x0000, 0x0000, 0x5AEB, 0xFFDF, 0x0000, 0x0020, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0680 (1664) pixels
0xFFFF, 0xFFFF, 0xFFDE, 0xFFFE, 0xFFFA, 0x9CA8, 0xACA4, 0xBCE2, 0xB4A1, 0xCD64, 0xF6EC, 0xFF90, 0xFFF4, 0xA488, 0xFFF6, 0x9CAC,   // 0x0690 (1680) pixels
0xFFFC, 0xFFFD, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020,   // 0x06A0 (1696) pixels
0x0000, 0x0000, 0x0861, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x06B0 (1712) pixels
0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x06C0 (1728) pixels
0xFFFF, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFD, 0xFFF9, 0xACE7, 0xB4C3, 0xB4A3, 0xAC83, 0xACC5, 0xACC7, 0xA488, 0xFFF8, 0xFFF9, 0xFFFB,   // 0x06D0 (1744) pixels
0xFFFE, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB5B6, 0xB595,   // 0x06E0 (1760) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB5B6, 0xB5B6, 0xFFFF, 0xFFFF,   // 0x06F0 (1776) pixels
0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0700 (1792) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFD, 0xFFFA, 0xA4AA, 0xACC9, 0xACA7, 0xAC85, 0xA486, 0x9C8A, 0xFFFB, 0xFFFD, 0xFFFE,   // 0x0710 (1808) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0720 (1824) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0730 (1840) pixels
0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0740 (1856) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFE, 0xFFFD, 0xFFF9, 0xFFF8, 0xFF54, 0xFF95, 0xFFFB, 0xFFFC, 0xFFFE, 0xFFFF,   // 0x0750 (1872) pixels
0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0760 (1888) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF,   // 0x0770 (1904) pixels
0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0780 (1920) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFD, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0790 (1936) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x07A0 (1952) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x07B0 (1968) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x07C0 (1984) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x07D0 (2000) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x07E0 (2016) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x07F0 (2032) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0800 (2048) pixels
};


// ISR for display refresh
void display_updater()
{

  display.display(70);

}

// Hardware configuration and console outputting for debug use provided by Brian Lough
void setup() {
  Serial.begin(9600);
  display.begin(16);
  display.clearDisplay();
  Serial.print("Pixel draw latency in us: ");
  unsigned long start_timer = micros();
  display.drawPixel(1, 1, 0);
  unsigned long delta_timer = micros() - start_timer;
  Serial.println(delta_timer);

  Serial.print("Display update latency in us: ");
  start_timer = micros();
  display.display(0);
  delta_timer = micros() - start_timer;
  Serial.println(delta_timer);

  display_ticker.attach(0.002, display_updater);
  yield();
  display.clearDisplay();
  drawImage(0, 0);
  delay(500);
}


// Simple method for traversing the UCF hex code array
void drawImage(int x, int y)
{
  int imageHeight = 32;
  int imageWidth = 64;
  int counter = 0;
  for (int yy = 0; yy < imageHeight; yy++)
  {
    for (int xx = 0; xx < imageWidth; xx++)
    {
      display.drawPixel(xx + x , yy + y, UCF[counter]);
      counter++;
    }
  }
}

void loop() {
}