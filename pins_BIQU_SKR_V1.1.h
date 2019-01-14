/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * Copyright (C) 2017 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef TARGET_LPC1768
  #error "Oops!  Make sure you have the LPC1768 environment selected in your IDE."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "BIQU SKR V1.1"
#endif

//
// Servos
//
//#define SERVO0_PIN         P1_29
//
// Limit Switches
//
//#define X_MIN_PIN          P1_29
#define X_MAX_PIN          P1_28
//#define Y_MIN_PIN          P1_27
#define Y_MAX_PIN          P1_26
#define Z_MIN_PIN          P1_25
#define Z_MAX_PIN          P1_24

//
// Steppers
//
#define X_STEP_PIN         P0_04   //
#define X_DIR_PIN          P0_05   //
#define X_ENABLE_PIN       P4_28   //
#ifndef X_CS_PIN
  #define X_CS_PIN         P4_28    // ETH
#endif

#define Y_STEP_PIN         P2_01   //
#define Y_DIR_PIN          P2_02   //
#define Y_ENABLE_PIN       P2_00   //
#ifndef Y_CS_PIN
  #define Y_CS_PIN         P2_00   // ETH
#endif

#define Z_STEP_PIN         P0_20   //
#define Z_DIR_PIN          P0_21   //
#define Z_ENABLE_PIN       P0_19   //
#ifndef Z_CS_PIN
  #define Z_CS_PIN         P0_19   // ETH
#endif

#define E0_STEP_PIN        P0_11
#define E0_DIR_PIN         P2_13
#define E0_ENABLE_PIN      P2_12
#ifndef E0_CS_PIN
  #define E0_CS_PIN        P2_12   // ETH
#endif

#define E1_STEP_PIN        P0_01
#define E1_DIR_PIN         P0_00
#define E1_ENABLE_PIN      P0_10
#ifndef E1_CS_PIN
  #define E1_CS_PIN        P0_10   // ETH
#endif


//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #define TMC_SW_MOSI      P0_02   // ETH
  #define TMC_SW_MISO      P0_03   // ETH
  #define TMC_SW_SCK       P0_15   // ETH
#endif


//
// Temperature Sensors
//  3.3V max when defined as an analog input
//
#define TEMP_BED_PIN       0   // A0 (T0) - (67) - TEMP_BED_PIN
#define TEMP_0_PIN         1   // A1 (T1) - (68) - TEMP_0_PIN
#define TEMP_1_PIN         2   // A2 (T2) - (69) - TEMP_1_PIN



#define HEATER_0_PIN     P2_07
#define HEATER_1_PIN     P2_04
#define FAN_PIN          P2_03
#define HEATER_BED_PIN   P2_05

#define SDSS           P1_23





/**
 * LCD / Controller
 *
 * All controllers can use J3 and J5 on the Re-ARM board.  Custom cabling will be required.
 */

/**
 * Smart LCD adapter
 *
 * The Smart LCD adapter can be used for the two 10 pin LCD controllers such as
 * REPRAP_DISCOUNT_SMART_CONTROLLER.  It can't be used for controllers that use
 * DOGLCD_A0, DOGLCD_CS, LCD_PINS_D5, LCD_PINS_D6 or LCD_PINS_D7. A custom cable
 * is needed to pick up 5V for the EXP1 connection.
 *
 * SD card on the LCD uses the same SPI signals as the LCD. This results in garbage/lines
 * on the LCD display during accesses of the SD card. The menus/code has been arranged so
 * that the garbage/lines are erased immediately after the SD card accesses are completed.
 */


  #define BEEPER_PIN          P1_30
  #define BTN_EN1             P3_25   // (31) J3-2 & AUX-4
  #define BTN_EN2             P3_26   // (33) J3-4 & AUX-4
  #define BTN_ENC             P2_11
  #define SD_DETECT_PIN       P1_31

  #define DOGLCD_CS           P2_06   // (16)
  #define DOGLCD_A0           P0_16   // (59) J3-8 & AUX-2
  #define DOGLCD_SCK          SCK_PIN
  #define DOGLCD_MISO         MISO_PIN
  #define DOGLCD_MOSI         MOSI_PIN
  #define LCD_PINS_D4         SCK_PIN
  #define LCD_PINS_ENABLE     MOSI_PIN
  //#define LPC_SD_LCD          // Marlin uses the SD drive attached to the LCD
  //#define LPC_SD_ONBOARD        // Marlin uses the SD drive on the control board
  // GLCD features
  //#define LCD_CONTRAST   190
  // Uncomment screen orientation
  //#define LCD_SCREEN_ROT_90
  //#define LCD_SCREEN_ROT_180
  //#define LCD_SCREEN_ROT_270


  //
  // SD Support (as with the AZTEEG_X5_MINI_WIFI)
  //
  //#define USB_SD_DISABLED     // Disable host access to SD card as mass storage device through USB
  #define USB_SD_ONBOARD        // Enable host access to SD card as mass storage device through USB

  #define LPC_SD_LCD          // Marlin uses the SD drive attached to the LCD
  //#define LPC_SD_ONBOARD        // Marlin uses the SD drive on the control board.  There is no SD detect pin
                                // for the onboard card.  Init card from LCD menu or send M21 whenever printer
                                // is powered on to enable SD access.

  #if ENABLED(LPC_SD_LCD)

    #define SCK_PIN            P0_15
    #define MISO_PIN           P0_17
    #define MOSI_PIN           P0_18
    #define SS_PIN             P1_23   // Chip select for SD card used by Marlin
    #define ONBOARD_SD_CS      P0_06   // Chip select for "System" SD card

  #elif ENABLED(LPC_SD_ONBOARD)

    #if ENABLED(USB_SD_ONBOARD)
      // When sharing the SD card with a PC we want the menu options to
      // mount/unmount the card and refresh it. So we disable card detect.
      #define SHARED_SD_CARD
      #undef SD_DETECT_PIN // there is also no detect pin for the onboard card
    #endif
    #define SCK_PIN            P0_07
    #define MISO_PIN           P0_08
    #define MOSI_PIN           P0_09
    #define SS_PIN             P0_06   // Chip select for SD card used by Marlin
    #define ONBOARD_SD_CS      P0_06   // Chip select for "System" SD card

  #endif
