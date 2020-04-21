/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16LF1618
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set V_MAX aliases
#define V_MAX_TRIS                 TRISAbits.TRISA0
#define V_MAX_LAT                  LATAbits.LATA0
#define V_MAX_PORT                 PORTAbits.RA0
#define V_MAX_WPU                  WPUAbits.WPUA0
#define V_MAX_OD                   ODCONAbits.ODA0
#define V_MAX_ANS                  ANSELAbits.ANSA0
#define V_MAX_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define V_MAX_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define V_MAX_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define V_MAX_GetValue()           PORTAbits.RA0
#define V_MAX_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define V_MAX_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define V_MAX_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define V_MAX_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define V_MAX_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define V_MAX_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define V_MAX_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define V_MAX_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set VREF aliases
#define VREF_TRIS                 TRISAbits.TRISA1
#define VREF_LAT                  LATAbits.LATA1
#define VREF_PORT                 PORTAbits.RA1
#define VREF_WPU                  WPUAbits.WPUA1
#define VREF_OD                   ODCONAbits.ODA1
#define VREF_ANS                  ANSELAbits.ANSA1
#define VREF_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define VREF_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define VREF_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define VREF_GetValue()           PORTAbits.RA1
#define VREF_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define VREF_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define VREF_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define VREF_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define VREF_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define VREF_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define VREF_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define VREF_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set TP3 aliases
#define TP3_TRIS                 TRISAbits.TRISA2
#define TP3_LAT                  LATAbits.LATA2
#define TP3_PORT                 PORTAbits.RA2
#define TP3_WPU                  WPUAbits.WPUA2
#define TP3_OD                   ODCONAbits.ODA2
#define TP3_ANS                  ANSELAbits.ANSA2
#define TP3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define TP3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define TP3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define TP3_GetValue()           PORTAbits.RA2
#define TP3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define TP3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define TP3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define TP3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define TP3_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define TP3_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define TP3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define TP3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set GAT_1_2 aliases
#define GAT_1_2_LAT                  LATAbits.LATA3
#define GAT_1_2_PORT                 PORTAbits.RA3
#define GAT_1_2_WPU                  WPUAbits.WPUA3
#define GAT_1_2_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define GAT_1_2_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define GAT_1_2_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define GAT_1_2_GetValue()           PORTAbits.RA3
#define GAT_1_2_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define GAT_1_2_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set ADC_AUX aliases
#define ADC_AUX_TRIS                 TRISAbits.TRISA4
#define ADC_AUX_LAT                  LATAbits.LATA4
#define ADC_AUX_PORT                 PORTAbits.RA4
#define ADC_AUX_WPU                  WPUAbits.WPUA4
#define ADC_AUX_OD                   ODCONAbits.ODA4
#define ADC_AUX_ANS                  ANSELAbits.ANSA4
#define ADC_AUX_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ADC_AUX_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ADC_AUX_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ADC_AUX_GetValue()           PORTAbits.RA4
#define ADC_AUX_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ADC_AUX_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ADC_AUX_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define ADC_AUX_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define ADC_AUX_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define ADC_AUX_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define ADC_AUX_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define ADC_AUX_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set TP4 aliases
#define TP4_TRIS                 TRISAbits.TRISA5
#define TP4_LAT                  LATAbits.LATA5
#define TP4_PORT                 PORTAbits.RA5
#define TP4_WPU                  WPUAbits.WPUA5
#define TP4_OD                   ODCONAbits.ODA5
#define TP4_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define TP4_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define TP4_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define TP4_GetValue()           PORTAbits.RA5
#define TP4_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define TP4_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define TP4_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define TP4_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define TP4_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define TP4_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set JSET_AUX aliases
#define JSET_AUX_TRIS                 TRISBbits.TRISB4
#define JSET_AUX_LAT                  LATBbits.LATB4
#define JSET_AUX_PORT                 PORTBbits.RB4
#define JSET_AUX_WPU                  WPUBbits.WPUB4
#define JSET_AUX_OD                   ODCONBbits.ODB4
#define JSET_AUX_ANS                  ANSELBbits.ANSB4
#define JSET_AUX_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define JSET_AUX_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define JSET_AUX_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define JSET_AUX_GetValue()           PORTBbits.RB4
#define JSET_AUX_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define JSET_AUX_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define JSET_AUX_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define JSET_AUX_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define JSET_AUX_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define JSET_AUX_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define JSET_AUX_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define JSET_AUX_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set JVEL_MIN aliases
#define JVEL_MIN_TRIS                 TRISBbits.TRISB5
#define JVEL_MIN_LAT                  LATBbits.LATB5
#define JVEL_MIN_PORT                 PORTBbits.RB5
#define JVEL_MIN_WPU                  WPUBbits.WPUB5
#define JVEL_MIN_OD                   ODCONBbits.ODB5
#define JVEL_MIN_ANS                  ANSELBbits.ANSB5
#define JVEL_MIN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define JVEL_MIN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define JVEL_MIN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define JVEL_MIN_GetValue()           PORTBbits.RB5
#define JVEL_MIN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define JVEL_MIN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define JVEL_MIN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define JVEL_MIN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define JVEL_MIN_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define JVEL_MIN_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define JVEL_MIN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define JVEL_MIN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set JVEL_MAX aliases
#define JVEL_MAX_TRIS                 TRISBbits.TRISB6
#define JVEL_MAX_LAT                  LATBbits.LATB6
#define JVEL_MAX_PORT                 PORTBbits.RB6
#define JVEL_MAX_WPU                  WPUBbits.WPUB6
#define JVEL_MAX_OD                   ODCONBbits.ODB6
#define JVEL_MAX_ANS                  ANSELBbits.ANSB6
#define JVEL_MAX_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define JVEL_MAX_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define JVEL_MAX_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define JVEL_MAX_GetValue()           PORTBbits.RB6
#define JVEL_MAX_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define JVEL_MAX_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define JVEL_MAX_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define JVEL_MAX_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define JVEL_MAX_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define JVEL_MAX_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define JVEL_MAX_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define JVEL_MAX_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set JGAT_1_2 aliases
#define JGAT_1_2_TRIS                 TRISBbits.TRISB7
#define JGAT_1_2_LAT                  LATBbits.LATB7
#define JGAT_1_2_PORT                 PORTBbits.RB7
#define JGAT_1_2_WPU                  WPUBbits.WPUB7
#define JGAT_1_2_OD                   ODCONBbits.ODB7
#define JGAT_1_2_ANS                  ANSELBbits.ANSB7
#define JGAT_1_2_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define JGAT_1_2_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define JGAT_1_2_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define JGAT_1_2_GetValue()           PORTBbits.RB7
#define JGAT_1_2_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define JGAT_1_2_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define JGAT_1_2_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define JGAT_1_2_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define JGAT_1_2_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define JGAT_1_2_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define JGAT_1_2_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define JGAT_1_2_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set GAT_GIR aliases
#define GAT_GIR_TRIS                 TRISCbits.TRISC0
#define GAT_GIR_LAT                  LATCbits.LATC0
#define GAT_GIR_PORT                 PORTCbits.RC0
#define GAT_GIR_WPU                  WPUCbits.WPUC0
#define GAT_GIR_OD                   ODCONCbits.ODC0
#define GAT_GIR_ANS                  ANSELCbits.ANSC0
#define GAT_GIR_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define GAT_GIR_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define GAT_GIR_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define GAT_GIR_GetValue()           PORTCbits.RC0
#define GAT_GIR_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define GAT_GIR_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define GAT_GIR_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define GAT_GIR_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define GAT_GIR_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define GAT_GIR_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define GAT_GIR_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define GAT_GIR_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set LL2_GIR aliases
#define LL2_GIR_TRIS                 TRISCbits.TRISC1
#define LL2_GIR_LAT                  LATCbits.LATC1
#define LL2_GIR_PORT                 PORTCbits.RC1
#define LL2_GIR_WPU                  WPUCbits.WPUC1
#define LL2_GIR_OD                   ODCONCbits.ODC1
#define LL2_GIR_ANS                  ANSELCbits.ANSC1
#define LL2_GIR_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LL2_GIR_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LL2_GIR_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LL2_GIR_GetValue()           PORTCbits.RC1
#define LL2_GIR_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LL2_GIR_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LL2_GIR_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LL2_GIR_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LL2_GIR_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define LL2_GIR_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define LL2_GIR_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define LL2_GIR_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LL1_GIR aliases
#define LL1_GIR_TRIS                 TRISCbits.TRISC2
#define LL1_GIR_LAT                  LATCbits.LATC2
#define LL1_GIR_PORT                 PORTCbits.RC2
#define LL1_GIR_WPU                  WPUCbits.WPUC2
#define LL1_GIR_OD                   ODCONCbits.ODC2
#define LL1_GIR_ANS                  ANSELCbits.ANSC2
#define LL1_GIR_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LL1_GIR_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LL1_GIR_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LL1_GIR_GetValue()           PORTCbits.RC2
#define LL1_GIR_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LL1_GIR_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LL1_GIR_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LL1_GIR_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LL1_GIR_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define LL1_GIR_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define LL1_GIR_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LL1_GIR_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set G_VEL aliases
#define G_VEL_TRIS                 TRISCbits.TRISC3
#define G_VEL_LAT                  LATCbits.LATC3
#define G_VEL_PORT                 PORTCbits.RC3
#define G_VEL_WPU                  WPUCbits.WPUC3
#define G_VEL_OD                   ODCONCbits.ODC3
#define G_VEL_ANS                  ANSELCbits.ANSC3
#define G_VEL_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define G_VEL_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define G_VEL_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define G_VEL_GetValue()           PORTCbits.RC3
#define G_VEL_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define G_VEL_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define G_VEL_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define G_VEL_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define G_VEL_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define G_VEL_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define G_VEL_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define G_VEL_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set DIREC aliases
#define DIREC_TRIS                 TRISCbits.TRISC4
#define DIREC_LAT                  LATCbits.LATC4
#define DIREC_PORT                 PORTCbits.RC4
#define DIREC_WPU                  WPUCbits.WPUC4
#define DIREC_OD                   ODCONCbits.ODC4
#define DIREC_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define DIREC_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define DIREC_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define DIREC_GetValue()           PORTCbits.RC4
#define DIREC_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define DIREC_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define DIREC_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define DIREC_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define DIREC_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define DIREC_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)

// get/set TP1 aliases
#define TP1_TRIS                 TRISCbits.TRISC6
#define TP1_LAT                  LATCbits.LATC6
#define TP1_PORT                 PORTCbits.RC6
#define TP1_WPU                  WPUCbits.WPUC6
#define TP1_OD                   ODCONCbits.ODC6
#define TP1_ANS                  ANSELCbits.ANSC6
#define TP1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define TP1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define TP1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define TP1_GetValue()           PORTCbits.RC6
#define TP1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define TP1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define TP1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define TP1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define TP1_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define TP1_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define TP1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define TP1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set TP2 aliases
#define TP2_TRIS                 TRISCbits.TRISC7
#define TP2_LAT                  LATCbits.LATC7
#define TP2_PORT                 PORTCbits.RC7
#define TP2_WPU                  WPUCbits.WPUC7
#define TP2_OD                   ODCONCbits.ODC7
#define TP2_ANS                  ANSELCbits.ANSC7
#define TP2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define TP2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define TP2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define TP2_GetValue()           PORTCbits.RC7
#define TP2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define TP2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define TP2_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define TP2_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define TP2_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define TP2_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define TP2_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define TP2_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/