#pragma once

#include "bactilis.h"

#include "quantum.h"

#ifdef RGBLIGHT_ENABLF
//rgb LFd driver
#include "ws2812.h"
#endif

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif
// ANSI + MACRO + 4x1_5u + BIG_SHIFT
#define LAYOUT_ANSI_MACRO_4x1_5u_BIG_SHIFT( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3,      LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7,      RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4,           RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, KC_NO, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, KC_NO, RE9 }, \
    { RF1, RF2, RF3, RF4, KC_NO, KC_NO, RF7, RF8, RF9 } \
  }
// Layout ANSI + MACRO + 5x1u + BIG SHIFT
#define LAYOUT_75_ANSI_MACRO_5x1u_BIG_SHIFT( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3,      LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7,      RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4, RF5,      RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, KC_NO, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, KC_NO, RE9 }, \
    { RF1, RF2, RF3, RF4, RF5, KC_NO, RF7, RF8, RF9 } \
  }
  
 // ANSI + MACRO + 4x1_5u
 #define LAYOUT_ANSI_MACRO_4x1_5u( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3,      LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7, RE8, RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4,           RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, KC_NO, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, RE8, RE9 }, \
    { RF1, RF2, RF3, RF4, KC_NO, KC_NO, RF7, RF8, RF9 } \
  }
  
 // ANDI + MACRO + 5x1u
#define LAYOUT_75_ANSI_MACRO_5x1u( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3,      LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7, RE8, RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4, RF5,      RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, KC_NO, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, RE8, RE9 }, \
    { RF1, RF2, RF3, RF4, RF5, KC_NO, RF7, RF8, RF9 } \
  }
//ISO+MACRO+4x1_5u+BIG SHIFT
#define LAYOUT_75_ISO_MACRO_4x1_5u_BIG_SHIFT( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7,      RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4,           RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, KC_NO, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, KC_NO, RE9 }, \
    { RF1, RF2, RF3, RF4, KC_NO, KC_NO, RF7, RF8, RF9 } \
  }
 // ISO+MACRO+5x1u+BIG SHIFT
#define LAYOUT_75_ISO_MACRO_5x1u_BIG_SHIFT( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7,      RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4, RF5,      RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, KC_NO, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, KC_NO, RE9 }, \
    { RF1, RF2, RF3, RF4, RF5, KC_NO, RF7, RF8, RF9 } \
  }
 // ISO + MACRO + 4x1_5u
 #define LAYOUT_ISO_MACRO_4x1_5u( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7, RE8, RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4,           RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, RE8, RE9 }, \
    { RF1, RF2, RF3, RF4, KC_NO, KC_NO, RF7, RF8, RF9 } \
  }
 
 // ISO + MACRO + 5x1u
 #define LAYOUT_ISO_MACRO_5x1u( \
            LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8, RD9, \
  LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8, LE9,      RE1, RE2, RE3, RE4, RE5,      RE7, RE8, RE9, \
  LF1, LF2, LF3, LF4, LF5,           LF8, LF9,      RF1, RF2, RF3, RF4, RF5,      RF7, RF8, RF9  \
  ) \
  { \
   	{ KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 },\
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, LB9 }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8, KC_NO }, \
    { LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8, LE9 }, \
    { LF1, LF2, LF3, LF4, LF5, KC_NO, KC_NO, LF8, LF9 }, \
	{ RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, RD9 }, \
    { RE1, RE2, RE3, RE4, RE5, KC_NO, RE7, RE8, RE9 }, \
    { RF1, RF2, RF3, RF4, RF5, KC_NO, RF7, RF8, RF9 } \
  }
 

 
