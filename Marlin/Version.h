/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
#pragma once


/*************************************
 * Marlin bugfix-2.0.x
 * Compiled version identifier
 ************************************/
#define COMPILE_VERSION "34" 

#define SHORT_BUILD_VERSION "bugfix-2.0.7.2-" COMPILE_VERSION
#define STRING_CONFIG_H_AUTHOR "BDM"                // Who made the changes.
#define CUSTOM_MACHINE_NAME "SKR PRO 1.1 tmc-2209"  // Name displayed in the LCD "Ready" message and Info menu
#define MACHINE_NAME "JAM-ENG Ender3pro"

/*******************************************************************************************************
 * Vx  mm/dd/YY HH:mm 24HR
 * 
 * V35  10/17/20 xx:xx
 * 
 * V34  10/17/20 08:16
 *      upstream merges
 *      CONFIGURATION_H_VERSION 020008
 *      Tag 2.0.7.2
 * 
 * V33  10/13/20 17:01
 * 
 *    #elif CHAMBER_FAN_MODE == 1
 *        #define CHAMBER_FAN_BASE  64   // Base chamber fan PWM (0-255); turns on when chamber temperature is above the target
 *        #define CHAMBER_FAN_FACTOR 64   // PWM increase per °C above target
 *        
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.25, 80.25, 400, 402, 402 }
 * 
 * V32  10/13/20 14:53
 * 
 *          ** WORKING ONBOARD SD CARD **
 * 
 *      #define FLASH_EEPROM_EMULATION
 *      //#define PRINTCOUNTER
 * 
 *      #elif SD_CONNECTION_IS(ONBOARD)
 * 
 *      // The SKR Pro's ONBOARD SD interface is on SPI1.
 *      // Due to a pull resistor on the clock line, it needs to use SPI Data Mode 3 to
 *      // function with Hardware SPI. This is not currently configurable in the HAL,
 *      // so force Software SPI to work around this issue.
 *      #define SOFTWARE_SPI
 *      #define SDSS                              PA4
 *      #define SCK_PIN                           PA5
 *      #define MISO_PIN                          PA6
 *      #define MOSI_PIN                          PB5
 *      #define SD_DETECT_PIN                     PB11
 * 
 * 
 * 
 * 
 * V31  10/13/20 14:10
 * 
 *          ** DIDNT WORK **
 * 
 *      EEPROM Changes. -  
 *      #define SRAM_EEPROM_EMULATION
 *      #define EEPROM_AUTO_INIT
 *           
 * 
 * V30  10/12/20 18:04
 * 
 *      CORRECTED: bugfix display version to 2.0.7
 *      #define X_CURRENT       820
 *      #define DEFAULT_MAX_ACCELERATION      { 4000, 4000, 50, 9000, 9000 }
 *      #define DEFAULT_ACCELERATION          3000    // X, Y, Z and E acceleration for printing moves
 *      #define DEFAULT_RETRACT_ACCELERATION  3000    // E acceleration for retracts
 *      #define DEFAULT_TRAVEL_ACCELERATION   4000    // X, Y, Z acceleration for travel (non printing) moves
 *      #define THERMAL_PROTECTION_CHAMBER_PERIOD    60 // Seconds
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.15, 80.15, 400, 402, 402 }
 *      #define SDCARD_CONNECTION                  ONBOARD   // ( pins_BTT_SKR_PRO_common.h )
 * 
 *      #elif CHAMBER_FAN_MODE == 2
 *        #define CHAMBER_FAN_BASE  32   // Minimum chamber fan PWM (0-255)
 *        #define CHAMBER_FAN_FACTOR 64   // PWM increase per °C difference from target
 *      #endif
 * 
 *      #define PRINTCOUNTER
 *      #define HOMING_FEEDRATE_XY (50*60)
 *      #define HOMING_FEEDRATE_Z  (4*60)
 *      #define SDCARD_CONNECTION ONBOARD
 *      #define XYZ_NO_FRAME
 *      //#define MENU_HOLLOW_FRAME
 *      #define USE_SMALL_INFOFONT
 *      #define BOOT_MARLIN_LOGO_ANIMATED

 * V29  10/12/20 12:36
 *      REMOVED: #define REPORT_FAN_CHANGE   // Report the new fan speed when changed by M106 (and others)
 *      FIXED: if SD_CONNECTION_IS(ONBOARD) // needs ONBOARD !
 *      ADDED: #define PE_LEDS_COMPLETED_TIME  (10*60)  // 10 minutes before returning to normal NEO color after print completes.
 * 
 * 
 * V28  10/12/20 12:15
 *      CHANGED: #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.1, 80.1, 400, 402, 402 }
 *      #define X_BED_SIZE 235
 *      #define Y_BED_SIZE 235
 *      #define STARTUP_COMMANDS "G28"
 * 
 * V27  10/12/20 11:48
 *      SYNC:   Sync'd with github/Marlin/bugfix-2.0.x ( date 10/12/2020 ).
 *      LOST: Config files got over-written by git. ( on or around 10/10/2020)
 *      RESTORED: Settings from V26 backup files ( 10/08/2020 )
 *      FIXED: Heated Chamber Options in configuration_adv.h ( some options were missing 06 config file? )
 *      ENABLED: #define CHAMBER_FAN (this was missing and not working)
 * 
 * 
 * V26  09/27/20 10:56
 * 
 *      *** FORKED marlin/bugfix-2.0.x to KamikazeBDM/Marlin ***
 * 
 *      ** SYNC: true-up PID tuning and other settings to firmware
 *      Recv: echo:  M301 E0 P22.68 I1.94 D66.19
 *      Recv: echo:  M301 E1 P32.83 I2.83 D95.09
 *      Recv: echo:  M304 P177.32 I34.68 D604.47
 *      REMOVED: define NEOPIXEL_IS_SEQUENTIAL
 *      REMOVED: #define S_CURVE_ACCELERATION
 *      #define LIN_ADVANCE_K 0.07
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 402, 402 }
 *      ADDED: #define JUNCTION_DEVIATION_MM 0.05 
 *          // Marlin Junction Deviation Calibration toolkit for Cura (https://www.thingiverse.com/thing:3463159)
 *      REMOVED: #define CLASSIC_JERK
 * 
 * V25  09/27/20 13:39
 *      UPDATES:    pulled latest updates from bugfix-2.0.x GIT
 * 
 * V24  09/27/20 13:20
 *      #define LCD_TIMEOUT_TO_STATUS 300000  ( ms == 5 mins )
 *      FIXED:  Wiring error on E0 and E1 - rewired - fixed broken wire E0
 *              E0 Now needs to be NOT inverted - #define INVERT_E0_DIR false                 
 * 
 * V23  09/26/20 10:42
 *      FIXED:  moved CHAMBER AUTO COOLING FAN ( FAN2_PIN ) to PC4
 *                  #define FAN2_PIN                            PC4   // Fan2       CHAMBER_AUTO_FAN_PIN
 * 
 * V22  09/25/20 16:41
 *      #define FAN_SOFT_PWM
 *      #define SOFT_PWM_SCALE 0
 * 
 * V21  09/25/20 16:10
 *      #define FAN_SOFT_PWM
 *      #define SOFT_PWM_SCALE 1
 *      #define SOFT_PWM_DITHER
 * 
 * V20  09/25/20 14:44
 *      CHANGED: REPOSITORY: to bug-fix-2.0.6.1 ( cloned with GitHub Desktop )
 *      #define CHAMBER_AUTO_FAN_TEMPERATURE 25
 *      #define CHAMBER_AUTO_FAN_SPEED 63  // half power - 12v fan - need to reduce 24v down via pwm
 * 
 * V19  09/24/20 14:30
 *      CHANGED: 
 *          #define HEATER_CHAMBER_INVERTING false    
 *          #define CHAMBER_MAXTEMP            58
 *          #define MAX_CHAMBER_POWER 255
 *          #define HEATER_CHAMBER_PIN       PD0    // Extsion-2  ( top row, pin 2 )
 * 
 * V18  09/24/20 17:33
 *      REMOVED:
 *          #define FAN_SOFT_PWM
 *          #define SOFT_PWM_DITHER
 *          #define CHAMBER_LIMIT_SWITCHING
 *      
 * V17  09/24/20 16:18
 *      CHANGED: #define HEATER_CHAMBER_INVERTING true    
 * 
 * V16  09/24/20 16:12
 *      #define MAX_CHAMBER_POWER 127 // sets max PWM to 1/2 power 127/255. i.e. 12v instead of 24+
 *      REMOVED: #define NUM_M106_FANS 1
 *      #define SOFT_PWM_SCALE 1
 *      #define SOFT_PWM_DITHER
 *      #define CHAMBER_AUTO_FAN_TEMPERATURE 28
 *      #define HEATER_CHAMBER_INVERTING false    
 * 
 * V15  09/24/20 14:20
 *      #define MAX_CHAMBER_POWER 127 // sets max PWM to 1/2 power 127/255. i.e. 12v instead of 24+
 *      #define FAN_SOFT_PWM
 *      #define NUM_M106_FANS 1
 *      #define TEMP_CHAMBER_HYSTERESIS     1
 *      define CHAMBER_LIMIT_SWITCHING
 *      #define HEATER_CHAMBER_PIN       PF9   // Chamber heater on/off pin
 * 
 * 
 * V14  09/24/20 13:22
 *      #define TEMP_CHAMBER_HYSTERESIS     2
 *      #define CHASSIS_HEATER_PIN          PF9   // Extension-1 header pin 3 top row.
 *  
 * V13  09/24/20 11:52
 *      ADDED:  #define THERMAL_PROTECTION_CHAMBER // Enable thermal protection for the heated chamber.
 * 
 * V12  09/24/20 11:02
 *      CHANGED:  Re-wired wire harnesses, installed SKR PRO 1.1 board in lengthened control box.
 *      removed BM#280 temp/humidity sensor from case. 
 *      added creality thermistor on TH2 for SKR PRO 1.1 temp control of case
 *      added #define TEMP_CHAMBER_PIN TEMP_2_PIN
 * 
 * V11  08/31/20 10:01
 *      CHANGED:  
 *                  DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 400, 400 }  
 *                  DEFAULT_ACCELERATION          350    // X, Y, Z and E acceleration for printing moves
 *                  DEFAULT_RETRACT_ACCELERATION  350    // E acceleration for retracts
 *                  DEFAULT_TRAVEL_ACCELERATION   1500    // X, Y, Z acceleration for travel (non printing) moves
 *                  DEFAULT_MAX_FEEDRATE          { 500, 500, 15, 999, 999 }
 *                  DEFAULT_MAX_ACCELERATION      { 1500, 1500, 50, 9000, 9000 }
 *                  TRAVEL_EXTRA_XYJERK 1.0    
 *                  MAX_JERK_EDIT_VALUES { 30, 30, 0.6, 10 }
 *                  #define EXPERIMENTAL_SCURVE
 *                  #define Z_HOMING_HEIGHT  5 
 *                  X_BED_SIZE 235
 *                  SENSORLESS_BACKOFF_MM  { 5, 5 }
 *                  HOMING_BUMP_MM      { 5, 5, 5 } 
 *                  CODEPENDENT_XY_HOMING 
 *                  
 * 
 * V10  08/27/20 19:02
 *      CHANGED:    
 *                  X_CURRENT           700
 *                  Y_CURRENT           700
 *                  Z_CURRENT           700
 *                  Z2_CURRENT          700
 *                  E0_CURRENT          700
 *                  E0_CURRENT          700

 *                  DEFAULT_AXIS_STEPS_PER_UNIT   { 80.1, 80.1, 400, 199.0**, 199.0** }
 *                      // ** E0/E1 = BMG direct drive steppers ( pancake ) with volumetric setting in PrusaSlicer ( 397.5 normal steps )

 *                  removed S_CURVE_ACCELERATION
 *                  removed SENSORLESS_HOMING - STALLGUARD - use endtop switches for X,Y,Z **NOTE** PIN bent under stepper driver to enable endstop switch mode.
 *                  removed HYBRID_THRESHOLD
 *                  added ENDSTOP_NOISE_THRESHOLD 2
 *                  added DETECT_BROKEN_ENDSTOP
 * 
 * 
* V9  08/26/20 16:45
 *      CHANGED:    
 *                  X_CURRENT           640
 *                  Y_CURRENT           640
 *                  X_STALL_SENSITIVITY  60
 *                  Y_STALL_SENSITIVITY  60
 *                  FILAMENT_CHANGE_FAST_LOAD_LENGTH     25
 *                  Added PID tuning defaults for Ender 3/ E3D Chimera Dual head
 *                          M301 E0 P21.75 I1.74 D67.82
 *                          M301 E1 P28.33 I2.20 D91.17
 *                          M304 P90.13 I15.02 D360.42
 *                  #define DEFAULT_ACCELERATION          700    // X, Y, Z and E acceleration for printing moves
 *                  #define DEFAULT_RETRACT_ACCELERATION  700    // E acceleration for retracts
 *                  #define DEFAULT_TRAVEL_ACCELERATION   700    // X, Y, Z acceleration for travel (non printing) moves
 *                  #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.1, 80.1, 400, 398.0, 398.0 }
 *                  #define LIN_ADVANCE_K 07    // Unit: mm compression per 1mm/s extruder speed
 *                  #define X_HYBRID_THRESHOLD     135  // [mm/s]
 *                  #define Y_HYBRID_THRESHOLD     135
 *                  #define Z_HYBRID_THRESHOLD      10
 *                  #define Z2_HYBRID_THRESHOLD     10
 *                  #define E0_HYBRID_THRESHOLD     50
 *                  #define E1_HYBRID_THRESHOLD     50
 *
 * 
 * V8  08/26/20 15:05
 *      CHANGED:    X_STALL_SENSITIVITY  70
 *                  Y_STALL_SENSITIVITY  70
 *                  X_CURRENT           700
 *                  Y_CURRENT           700
 *                  DEFAULT_AXIS_STEPS_PER_UNIT   { 80.1, 80.1, 400, 397.0, 397.0 }
 *                  #define EEPROM_CHITCHAT 
 *                  #define Z_HYBRID_THRESHOLD       5
 *                  #define Z2_HYBRID_THRESHOLD      5
 *                  //#define PRINTCOUNTER - #error "Disable PRINTCOUNTER or choose another EEPROM emulation." 
 *                  EEPROM_EMULATION  - REMOVED
 * 
 * V7  08/26/20 14:12
 *      CHANGED:    INVERT_E1_DIR true
 *                  X_STALL_SENSITIVITY  70
 * 
 * V6  08/26/20 13:55   *** WORKING SENSORLESS HOMING *** BASE_LINE SETTINGS!
 *      CHANGED:    Settings from kackebike's settings for sensorless homing.
 *                  https://github.com/hackebike/3dprinter
 *                  https://www.youtube.com/watch?v=UJwzSTcQslo
 * 
 * V5  08/26/20 12:40
 *     CHANGED:     Removed HOMING_BUMP_MM ( set to 0.0.0 ) to get sensorless homing to work
 * 
 * V4  08/26/20 09:35
 *     CHANGED:     Changed TMCStepper to use use bigtreetech github source
 * 
 * V3  08/25/20 19:30
 *     CHANGED:     Swapped X, Y, Z as they move backwards
 * 
 * V2  08/25/20 15:33
 *     CHANGED:     Serial port to -1 ( for bootloader/Main USB Port ), second serial to 3 ( UART3 / octoprint ) 
 * 
 * V1  08/25/20 09:55
 *     INITIAL:    New Board replacing SKR 1.4 Turbo ( given to nphs 3863 pantherbotics )
 * 
 *******************************************************************************************************/








/**
 * Verbose version identifier which should contain a reference to the location
 * from where the binary was downloaded or the source code was compiled.
 */
#define DETAILED_BUILD_VERSION SHORT_BUILD_VERSION " (Github/kamikazebdm/marlin)"

/**
 * The STRING_DISTRIBUTION_DATE represents when the binary file was built,
 * here we define this default string as the date where the latest release
 * version was tagged.
 */
#define STRING_DISTRIBUTION_DATE  __DATE__ " " __TIME__


/**
 * The SOURCE_CODE_URL is the location where users will find the Marlin Source
 * Code which is installed on the device. In most cases —unless the manufacturer
 * has a distinct Github fork— the Source Code URL should just be the main
 * Marlin repository.
 */
#define SOURCE_CODE_URL "https://github.com/MarlinFirmware/Marlin"

/**
 * Default generic printer UUID.
 */
//#define DEFAULT_MACHINE_UUID "cede2a2f-41a2-4748-9b12-c55c62f367ff"

/**
 * The WEBSITE_URL is the location where users can get more information such as
 * documentation about a specific Marlin release.
 */
#define WEBSITE_URL "http://marlinfw.org"

/**
 * Set the vendor info the serial USB interface, if changable
 * Currently only supported by DUE platform
 */
//#define  USB_DEVICE_VENDOR_ID           0x0000
//#define  USB_DEVICE_PRODUCT_ID          0x0000
//#define  USB_DEVICE_MANUFACTURE_NAME    WEBSITE_URL
