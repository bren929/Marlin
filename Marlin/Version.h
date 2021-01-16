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
#define COMPILE_VERSION "80(3)" 

#define SHORT_BUILD_VERSION "bugfix-2.0.7.2-" COMPILE_VERSION
#define STRING_CONFIG_H_AUTHOR "BDM"                // Who made the changes.
#define CUSTOM_MACHINE_NAME "SKR PRO 1.1 tmc-2209"  // Name displayed in the LCD "Ready" message and Info menu
#define MACHINE_NAME "JAM-ENG Ender3pro"

/*******************************************************************************************************
 * 
 * Vvv MM/DD/2021 HH:MM
 * 
 * V80(3) 01/16/2021 05:39
 *      #define FAST_PWM_FAN_FREQUENCY  977  
 *      #define FAN_MIN_PWM 0
 *      #define FAN_MAX_PWM 128
 *      #define TMC_HOME_PHASE { 896, 896, 896 }
 *      
 * 
 * V80(2) 01/16/2021 04:55
 * V80    01/16/2021 02:12
 *      UPDATES: MARLIN upstream bugfix-2.0.x  01/16/2021
 *      REMOVED: TMC_HOME_PHASE
 *      REMOVED: #define HYBRID_THRESHOLD
 *      REMOVED: #define SQUARE_WAVE_STEPPING
 *      M92 X1282.00 Y1283.00 Z6450.00
 *      M203 X150.00 Y150.00 Z8.00
 *      M201 X800.00 Y800.00 Z50.00
 *      M204 P550.00 R550.00 T700.00
 *      M906 X706 ( ALL )
 *      M900 T0 K0.02
 *      
 * 
 * V79c 01/09/2021 10:53
 *      UPDATES: MARLIN upstream bugfix-2.0.x  01/08/2021
 *      #define HOMING_FEEDRATE_MM_M { (75*60), (75*60), (6*60) }     
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT  { 1282.00, 1282.00, 6460.00, 6220.00, 6220.00 }
 *      #define DEFAULT_MAX_FEEDRATE          { 150.00, 135.00, 12, 500, 500 }
 *      #define DEFAULT_MAX_ACCELERATION      { 700, 700, 50, 5000, 5000 }
 *      M710 S102 I51 A1 D30 ; (40% 20%)
 *      #define Z_CURRENT        850
 *      #define Z2_CURRENT       850
 *      #define E0_CURRENT      720
 *      #define E1_CURRENT      720
 *      #define BACKLASH_COMPENSATION
 *      #define HYBRID_THRESHOLD
 *      #define TMC_HOME_PHASE { 896, 896, 896 }
 *      #define FAST_PWM_FAN_FREQUENCY  14706  // ( 14.706KHz )
 *      E0 and E-1 ( bed ) PID RE-TUNE
 * 
 *      !!! MANUAL_FEEDRATE !!!
 *      #define MANUAL_FEEDRATE { 70 * 60, 70 * 60, 8 * 60, 2 * 60 } // (mm/min) Feedrates for manual moves along X, Y, Z, E from panel
 * 
 * V78 01/08/2021 12:19
 *      UPDATES: MARLIN upstream bugfix-2.0.x  01/08/2021
 * 
 * V77h 01/07/2021 16:27
 *      UPDATES: MARLIN upstream bugfix-2.0.x  01/06/2021
 *        #define LCD_TIMEOUT_TO_STATUS 1200000    // 20 mins
 * 
 * 
 *      FAN_MIN_PWM 30 | FAN_MAX_PWM 128
 *        VER 77.a Tried 29412 (29.412Khz) w/ OCR2A ** works but Part Fan not fully controllable full sweep 0 - 100 ( eg: runs about 50% at 25% ) **
 *        VER 77.b Disabled OCR2A -- ?? no difference.. 
 *        VER 77.c Tied 1220 (1.22KHz) - slightly better - less noise - not fully controllable.. still in the 1 -10 with a max of maybe 15-20 range
 *        VER 77.d ** 488 (488Hz)  - slowed part fan down.. 100% seems slower, we have noticable 25% - feels to sluggish and not full power.
 * 
 *      FAN_MIN_PWM 0 | FAN_MAX_PWM 255
 *        VER 77.e ** 305 (305Hz)  - PF normal - same results on cont fan and case light pwm
 * 
 *      FAN_MIN_PWM 0 | FAN_MAX_PWM 64
 *        VER 77.f ** 31400 (31.4KHz)  - same w/ CF and CL - PF limited range - not good on 25%
 * 
 *      FAN_MIN_PWM 192 | FAN_MAX_PWM 255
 *        VER 77.g ** 31400 (31.4KHz)  - same CF CL - PF only full range.
 * 
 *      FAN_MIN_PWM 0 | FAN_MAX_PWM 255
 *        VER 77.h ** 30 (30Hz)  -
 * 
 * 
 * 
 * 
 * V76 01/05/2021 15:19
 *      UPDATES: MARLIN upstream bugfix-2.0.x  01/05/2021
 * 
 * V75 01/05/2021 14:57
 *      ** RESTORED to GIT release 74 - failed updates (76 and 77) caused homing Halts, and strange bed leveling issues => incorrect SERIAL settings.
 *      ADDED: 
 *          #define EMERGENCY_PARSER
 *          #define NOZZLE_CLEAN_FEATURE
 * 
 * V74 12/29/2020 10:55
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/29/2020
 * 
 * V73 12/28/2020 18:31
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/28/2020
 * 
 *      ** ** ** ** **
 *      ** REMOVED  **
 *          //#define EMERGENCY_PARSER
 *      ** ** ** ** **
 *      ** ** ** ** **
 * 
 * 
 * V72 12/28/2020 09:08
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/28/2020
 *      RE-ENABLED: //#define THERMAL_PROTECTION_CHAMBER
 *      #define HOMING_FEEDRATE_MM_M { (785*60), (85*60), (8*60) }
 *      Stepper Current: 
 *          M906 X600 Y620 Z620
 *          M906 I1 Z620
 *          M906 T0 E620
 *          M906 T1 E620
 *      #define DEFAULT_ACCELERATION          500    // X, Y, Z and E acceleration for printing moves
 *      #define DEFAULT_RETRACT_ACCELERATION  500    // E acceleration for retracts
 *      #define DEFAULT_TRAVEL_ACCELERATION   650    // X, Y, Z acceleration for travel (non printing) moves
 *      #define BACKLASH_COMPENSATION
 *      REMOVED: #define DIRECT_STEPPING
 * 
 * V71 12/19/2020 09:39
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/19/2020
 *      DISABLED: //#define THERMAL_PROTECTION_CHAMBER
 *      ADDED: #define SOUND_MENU_ITEM ( re-enable when heater unit temp sensor removed (disables at 150F))
 * 
 * V70 12/17/2020 10:53
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/16/2020
 *      #define HOMING_FEEDRATE_MM_M { (75*60), (75*60), (7*60) }
 *      Disabled Stealth Chop on E0 and E1
 *      Stepper Current: 
 *          M906 X580 Y580 Z600
 *          M906 I1 Z600
 *          M906 T0 E600
 *          M906 T1 E600
 *      CHAMBER_FAN_MODE == 1
 *       #define CHAMBER_FAN_BASE    0     // Base chamber fan PWM (0-255); turns on when chamber temperature is above the target
 *       #define CHAMBER_FAN_FACTOR  20    // PWM increase per °C above target

 * V69 12/16/2020 16:51
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/16/2020
 *      #define XY_FREQUENCY_LIMIT      10 
 *      REMOVED: //#define AUTOTEMP, and //#define LIN_ADVANCE
 *      #define DIRECT_STEPPING
 *      #define FAN_SOFT_PWM
 *      #define SOFT_PWM_SCALE 1
 *      #define SOFT_PWM_DITHER
 *      #define FAN2_PIN                              PG11   // Fan2 CHAMBER COOLING FAN       CHAMBER_AUTO_FAN_PIN (WAS PC4)
 * 
 * V68 12/15/2020 16:04
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/15/2020
 *      CASE_FAN: narrow the 'close enough' setting.
 *      #define TEMP_CHAMBER_HYSTERESIS     1  
 *      ENABLED(LED_COLOR_PRESETS)
 *      REMOVED: //#define S_CURVE_ACCELERATION
 * 
 * V67 12/13/2020 17:24
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/11/2020
 * 
 * V66 12/11/2020 10:31 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/11/2020
 * 
 * V65 12/08/2020 08:28 
 *      #define NEO_PIN             PF8     // ( PC9 Blown 12/07/2020 )
 * 
 * V64 12/07/2020 18:42 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/07/2020
 *      NEW: Case lights, NEO PIXELS (135 LEDS in 3 rows: 144pixels/meter)
 *      #define NEOPIXEL_PIXELS     135
 * 
 *      M92 X1282.00 Y1282.00 Z6451.00
 *      M203 X150.00 Y150.00 Z12.00
 *      M203 T0 E350.00
 *      M203 T1 E100.00
 * 
 *      M201 X1000.00 Y1000.00 Z100.00     
 *      M201 T0 E5000.00
 *      M201 T1 E5000.00
 * 
 *      M204 P750.00 R300.00 T750.00
 *      M205 B20000.00 S0.00 T0.00 J0.08
 * 
 *      M906 X500 Y500 Z540
 *      M906 I1 Z540
 *      M906 T0 E700
 *      M906 T1 E700      
 *  
 *      M145 S0 H195 B55 F0
 *      M145 S1 H245 B110 F0
 *      M145 S2 H285 B132 F0
 *      M145 S3 H255 B105 F0
 *      M145 S4 H270 B130 F0

 * V63 12/01/2020 13:37 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  12/01/2020
 *      Temperature settings, adjusting extruder steps ( flow ), sync printer settings to firmware defaults.
 *      #define LIN_ADVANCE_K 0.04 
 * 
 * V62 11/29/2020 09:06 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/29/2020
 *      #define X_MICROSTEPS     256  // ( x, y, z1,z z2, e0, e1 ) ** need to multiple STEPS * 16
 *      *!* @ 256 STEPS == #define DEFAULT_AXIS_STEPS_PER_UNIT  { 1280.00, 1280.00, 6400.00, 6384.00, 6384.00 }
 *      *!* @ 16 STEPS == #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.00, 80.00, 400.00, 399.00, 399.00 }

 *      #define LIN_ADVANCE_K 0.06
 * 
 * V61 11/28/2020 10:50
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/26/2020
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.00, 80.00, 400.00, 400.0, 400.0 }
 *      REMOVED: DIRECT_STEPPING   -- Can only use one or the other.
 *      RE-ADDED: #define LIN_ADVANCE_K 0.00
 * 
 * V60 11/27/2020 12:31 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/26/2020
 *      #define NEO_PIN                             PC9
 *      Dual Z Stepper Driver setup. 2nd Z uses E2 port. Make sure Primary Z "Buddy" Port is Jumped.
 *      #define ADAPTIVE_STEP_SMOOTHING
 * 
 * V59 11/26/2020 17:35 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/26/2020
 * 
 * V58 11/25/2020 15:51 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/25/2020
 *      #define NEO_PIN                             PF8  - blown 5v buck converter - PC9 may be ok though
 *      removed: //#define HOMING_BACKOFF_POST_MM
 * 
 * V57 11/22/2020 09:43 
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/22/2020
 *      M204 P400.00 R400.00 T500.00
 *      M906 T0 / T1 E700
 *      S_CURVE_ACCELERATION
 *      //#define STEALTHCHOP_E
 *      CHAMBER_AUTO_FAN_TEMPERATURE 60
 * 
 * V56 11/21/2020 08:10   
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/21/2020
 *      M906 T0 / T1 E680
 * 
 * V55 11/12/2020 12:47   
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/20/2020
 *      M92 X80.33 Y80.30 Z403.10
 *      M92 T0 E396.00
 *      M92 T1 E396.00
 *      M204 P600.00 R600.00 T900.00
 *      M203 T0 E750.00
 *      M203 T1 E750.00
 *      #define DEFAULT_ACCELERATION          600    // X, Y, Z and E acceleration for printing moves
 *      #define DEFAULT_RETRACT_ACCELERATION  600    // E acceleration for retracts
 *      #define DEFAULT_TRAVEL_ACCELERATION   900    // X, Y, Z acceleration for travel (non printing) moves
 *      CASE_LIGHT_DEFAULT_BRIGHTNESS 128  
 *      #define LIN_ADVANCE_K 0.01
 *      #define E0_CURRENT      600
 *      #define Eq_CURRENT      600
 * 
 * V54 11/15/2020 12:15
 *      UPDATED: To Python 3.9.0
 *      MOVED: from \\MORDOR UNC to local C drive.
 *      #define CONTROLLERFAN_SPEED_ACTIVE 255 
 *      M301 E0 P16.33 I1.28 D52.26
 *      #define Z_AFTER_HOMING  5
 *      #define Y_BED_SIZE 235
 *      #define Y_MAX_POS Y_BED_SIZE - 11
 *      M92 T0 E396.80
 * 
 * V53 11/15/2020 08:44s
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/15/2020
 *      DEFAULT_AXIS_STEPS_PER_UNIT   { 80.30, 80.30, 402.60, 397.00, 397.00 }
 *      #define STARTUP_COMMANDS "M150 R255 U255 B255 P255"
 *      #define PREHEAT_5_LABEL         "PC"
 *      #define PREHEAT_5_TEMP_HOTEND   290
 *      #define PREHEAT_5_TEMP_BED      140
 *      
 * V52 11/14/2020 09:40
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/14/2020 (SKR_PRO MOTOR_EXPANSION ?)
 *      M301 E0 P19.49 I1.47 D64.64
 *      M304 P101.30 I19.22 D355.92
 *      M92 X80.30 Y80.30 Z402.60
 *      M92 T0/T1 E398.65
 *      M906 T0/T1 E640
 * 
 * V51 11/13/2020 12:27
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/13/2020
 *       -- M304 P13.04 I0.07 D1725.88
 *       -- M301 E0 P19.49 I1.47 D64.64
 *      #define FAN_KICKSTART_TIME 300
 *      #define CHAMBER_AUTO_FAN_TEMPERATURE 65
 *      CHAMBER_FAN_MODE == 1    
 *        #define CHAMBER_FAN_BASE  30  
 *        #define CHAMBER_FAN_FACTOR 10  
 *      #define THERMAL_PROTECTION_BED_PERIOD        300 // Seconds
 *      #define THERMAL_PROTECTION_BED_HYSTERESIS     10 // Degrees Celsius
 *      #define WATCH_BED_TEMP_PERIOD                420 // Seconds
 *      #define WATCH_BED_TEMP_INCREASE               2 // Degrees Celsius
 *           
 * 
 * V50 11/12/2020 11:54
 *      #define TEMP_CHAMBER_HYSTERESIS     3
 *      #define CHAMBER_FAN_FACTOR 20
 *      #define PREHEAT_5_LABEL         "PC"
 *      #define PREHEAT_5_TEMP_HOTEND   290
 *      #define PREHEAT_5_TEMP_BED      128
 *      #define WATCH_BED_TEMP_PERIOD                300 // Seconds
 *      #define THERMAL_PROTECTION_BED_PERIOD        60 // Seconds
 * 
 * 
 * V49 11/12/2020 08:38
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/12/2020
 *      #define CHAMBER_FAN_FACTOR 40
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.30, 80.30, 402.50, 398.70, 398.70 }
 *      #define DEFAULT_ACCELERATION          700
 *      #define DEFAULT_RETRACT_ACCELERATION  1000
 *      #define DEFAULT_TRAVEL_ACCELERATION   1000
 *      
 * 
 * V48 11/06/2020 17:20
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/06/2020
 *      #define CHAMBER_FAN_FACTOR 20
 *      
 * V47 11/05/2020 09:18
 *      CHAMBER_FAN_MODE == 2
 *          #define CHAMBER_FAN_BASE  0
 *          #define CHAMBER_FAN_FACTOR 20
 *          removed: #define XY_FREQUENCY_LIMIT 
 *          removed: #define S_CURVE_ACCELERATION
 * 
 * V46  11/05/2020 07:40
 *      READD: #define FAN_SOFT_PWM -- part fan and chassis fan running at 100%
 *      #define LIN_ADVANCE_K 0.02 
 *      #define FAST_PWM_FAN_FREQUENCY 31400
 *      #define CHAMBER_AUTO_FAN_TEMPERATURE    51
 *      #define CHAMBER_AUTO_FAN_SPEED          255     
 *      
 * V45  11/04/2020 17:14
 *      REMOVED: #define FAN_SOFT_PWM
 *      #define PREHEAT_5_LABEL         "PC" ( 295/129 )
 *  
 * V44  11/04/2020 16:56
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/02/2020
 *      #define FAST_PWM_FAN ( COMPILED !)
 *      #define E0_CURRENT      800
 *      #define E1_CURRENT      800
 *      #define Z1_CURRENT      1000
 *      #define Z2_CURRENT      1000
 *      #define TEMP_BED_RESIDENCY_TIME 5  ( 10 def)
 *      #define TEMP_RESIDENCY_TIME     5 ( 10 def )     
 *      
 * 
 * V43  11/03/2020 14:23
 *      #define BAUDRATE 250000
 *      #define WATCH_BED_TEMP_PERIOD                180 // Seconds
 *          ^^ and a few others changed to 180
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.385, 80.385, 400.35, 401.70, 401.70 }
 *      M906 X600 Y640 Z600
 *      M906 I1 Z600
 *      M906 T0 E600
 *      M906 T1 E600
 *      
 * V42  11/02/2020 10:04
 *      UPDATES: MARLIN upstream bugfix-2.0.x  11/02/2020
 *      CHAMBER_FAN_MODE == 2
 *          CHAMBER_FAN_BASE  0
 *          CHAMBER_FAN_FACTOR 64
 *      #define WATCH_BED_TEMP_PERIOD                120 // Seconds     
 * 
 * V41  11/01/20 17:40
 *      #define XY_FREQUENCY_LIMIT      10 
 *          #define XY_FREQUENCY_MIN_PERCENT 5
 * 
 *      #define CASE_LIGHT_DEFAULT_BRIGHTNESS 255
 *      #define HOMING_BACKOFF_POST_MM { 5, 0, 10 } 
 * 
 *      FIXED: #define CUSTOM_USER_MENUS  (poorly formatted syntax)
 *          #define PREHEAT_3_LABEL         "PLA PRO-3"
 *          #define PREHEAT_3_TEMP_HOTEND   205
 *          #define PREHEAT_3_TEMP_BED      55
 *          #define PREHEAT_3_FAN_SPEED     0 // Value from 0 to 255
 *          #define PREHEAT_4_LABEL         "PETG"
 *          #define PREHEAT_4_TEMP_HOTEND   235
 *          #define PREHEAT_4_TEMP_BED      70
 *          #define PREHEAT_4_FAN_SPEED     0 // Value from 0 to 255
 *          #define PREHEAT_5_LABEL         "HIPS"
 *          #define PREHEAT_5_TEMP_HOTEND   255
 *          #define PREHEAT_5_TEMP_BED      105
 *          #define PREHEAT_5_FAN_SPEED     0 // Value from 0 to 255
 *          #define PREHEAT_6_LABEL         "PC"
 *          #define PREHEAT_6_TEMP_HOTEND   295
 *          #define PREHEAT_6_TEMP_BED      120
 *          #define PREHEAT_6_FAN_SPEED     0 // Value from 0 to 255
 *          #define PREHEAT_7_LABEL         "NYLON"
 *          #define PREHEAT_7_TEMP_HOTEND   275
 *          #define PREHEAT_7_TEMP_BED      85
 *          #define PREHEAT_7_FAN_SPEED     0 // Value from 0 to 255
 * 
 * V40  11/01/20 16:09
 *   
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.37, 80.37, 400.25, 401.70, 401.70 }
 *      SuperSlicer Setting - XY Compensation - Inner: -0.070, Holes: -0.070
 *      #define E1_CURRENT      570
 *      #define E1_CURRENT      570
 *      #define WATCH_CHAMBER_TEMP_PERIOD            120 // Seconds
 *      #define THERMAL_PROTECTION_CHAMBER_PERIOD    120 // Seconds
 *      #elif CHAMBER_FAN_MODE == 1
 *          #define CHAMBER_FAN_BASE  32   // Base chamber fan PWM (0-255); turns on when chamber temperature is above the target
 *          #define CHAMBER_FAN_FACTOR 32   // PWM increase per °C above target
 *       #define NEOPIXEL_PIXELS 90    
 *      #define NEOPIXEL_BRIGHTNESS 255 
 *      //#define USE_SMALL_INFOFONT
 *      #define CUSTOM_USER_MENUS  
 * 
 * V39  10/31/20 09:44
 *      UPDATES: MARLIN upstream bugfix-2.0.x 
 * 
 *      #define HEATER_0_MAXTEMP 315
 *      #define HEATER_1_MAXTEMP 315
 * 
 *      #define LIN_ADVANCE_K 0.02 
 *      M906 X550 Y550 Z550
 *      M906 I1 Z550, M906 T0 E550, M906 T1 E550
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.375, 80.375, 400.0, 401.70, 401.70 }
 *      #define DEFAULT_MAX_FEEDRATE          { 500, 500, 10, 650, 650 }
 *      #define DEFAULT_MAX_ACCELERATION      { 1000, 1000, 150, 9000, 9000 }
 *      #define JUNCTION_DEVIATION_MM 0.013
 *      M204 P500.00 R500.00 T500.00
 *      M205 B20000.00 S0.00 T0.00 J0.013
 * 
 * 
 * V38  10/20/28 17:06
 *      UPDATES: MARLIN upstream bugfix-2.0.x 
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.375, 80.375, 400.0, 401.90, 401.90 }
 *      #define X_BED_SIZE 245
 *      #define Y_BED_SIZE 230
 * 
 *      M900 T0/T1 K0.02
 * 
 *      M906 X550 Y550 Z640
 *      M906 I1 Z640
 *      M906 T0 E640
 *      M906 T1 E640
 * 
 *      M201 X1000.00 Y1000.00 Z150.00
 *      M201 T0 E9000.00
 *      M201 T1 E9000.00
 * 
 *      M203 X500.00 Y500.00 Z10.00
 *      M203 T0 E650.00
 *      M203 T1 E650.00
 * 
 *      M204 P500.00 R500.00 T500.00
 *      M205 B20000.00 S0.00 T0.00 J0.01
 *      
 * V37  10/20/26 18:27
 *      re-homed build plate
 *      installed new Y end-stop switch (broken)
 *      reset x,y build plate dimensions
 *          #define X_MAX_POS X_BED_SIZE
 *          #define Y_MAX_POS Y_BED_SIZE
 *      #define X_BED_SIZE 240
 *      #define Y_BED_SIZE 230
 *      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.40, 80.35, 400.0, 401.90, 401.90 }
 * 8
 * V36  10/20/21 14:05
 * 		firmware sync of settings
 *      UPDATES: MARLIN upstream bugfix-2.0.x 
 * V35  10/20/20 11:56
 * 		firmware sync of settings
 *		READDED: #define S_CURVE_ACCELERATION
 *      UPDATES: MARLIN upstream bugfix-2.0.x 
 *		
 * V34  10/17/20 08:16
 *      UPDATES: MARLIN upstream bugfix-2.0.x 
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
 *      UPDATES: MARLIN upstream bugfix-2.0.x     pulled latest updates from bugfix-2.0.x GIT
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
#define SOURCE_CODE_URL "github.com/MarlinFirmware/Marlin"

/**
 * Default generic printer UUID.
 */
//#define DEFAULT_MACHINE_UUID "cede2a2f-41a2-4748-9b12-c55c62f367ff"

/**
 * The WEBSITE_URL is the location where users can get more information such as
 * documentation about a specific Marlin release.
 */
#define WEBSITE_URL "marlinfw.org"

/**
 * Set the vendor info the serial USB interface, if changable
 * Currently only supported by DUE platform
 */
//#define  USB_DEVICE_VENDOR_ID           0x0000
//#define  USB_DEVICE_PRODUCT_ID          0x0000
//#define  USB_DEVICE_MANUFACTURE_NAME    WEBSITE_URL
