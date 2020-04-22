/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16LF1618
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "math.h"
#include "Variables.h"
/*
                        ***** CONSTANTES GLOBALES *****
 */
    #define PG_INIC 10.0 // % Porcentaje del gatillo a partir del cual comienza a funcionar el motor
    #define P_GG 40.0 // % Porcentaje del gatillo a partir del cual se produce la inversi�n de giro
    #define P_LL 30.0 // % Porcentaje de las llaves a partir del cual se produce la detenci�n del motor (o cambio de sentido de giro).
    #define PVLIM 20.0 // % Porcentaje de velocidad Limite final.
    #define DELTA_MAX_PWM 25.0 // Diferencia entre PWM a velocidad m�xima y velocidad m�nima
    #define PWM_MIN 31 // Valor m�nimo estable al que puede girar el motor.
    #define TG_x10ms 100 // Tiempo x10 milisegundos usado para espera de inversi�n de giro.
/*
                        ***** VARIABLES GLOBALES *****
 */
    int GAT_GIR_ADC = 512;
    int LL1_GIR_ADC = 0;
    int LL2_GIR_ADC = 512;
    int G_VEL_ADC = 512;
    int C_GG = 399; // Valor calculado para comparaci�n del ADC a partir del cual el Gatillo de giro produce el cambio de sentido del motor.
    int GINIC = 500; // Valor calculado para comparaci�n del ADC a partir del cual el gatillo de velocidad comienza a actuar.
    int CLL1_L = 470; //Valor calculado para comparaci�n del ADC a partir del cual el sensor1 de la llave pasa de el tope izquierdo al centro (para detenci�n de giro).
    int CLL1_H = 425; //Valor calculado para comparaci�n del ADC a partir del cual el sensor1 de la llave pasa de el tope derecho al centro (para detenci�n de giro).
    int CLL2_L = 470; //Valor calculado para comparaci�n del ADC a partir del cual el sensor2 de la llave pasa de el tope derecho al centro (para detenci�n de giro).
    int CLL2_H = 425; //Valor calculado para comparaci�n del ADC a partir del cual el sensor2 de la llave pasa de el tope izquierdo al centro (para detenci�n de giro).
    float M_aux = 0; // Variables auxiliares para realzar la mayor parte del c�lculo del PWM_VEL fuera del Wile.
    float B_aux = 0; // Variables auxiliares para realzar la mayor parte del c�lculo del PWM_VEL fuera del Wile.
    float DELTA_PWM =0; // Variable auxiliar para el calculo de l�mite de velocidad
    int GMAX = 0; //  de EEPROM Valor del ADC que alcanza el gatillo de velocidad presionado al m�ximo (menor valor ADC).
    int GMIN = 512; // de EEPROM Valor del ADC que alcanza el gatillo de velocidad presionado al m�nimo (mayor valor ADC).
    int GG_MAX = 512; // de EEPROM Valor del ADC que alcanza el gatillo de Giro presionado al m�ximo (m�nimo valor ADC).
    int GG_MIN = 0; // de EEPROM Valor del ADC que alcanza el gatillo de Giro presionado al m�nimo (mayor valor ADC).
    int CLL1_MAX = 0; // de EEPROM Valor del ADC tomado en el sensor1 de la llave cuando esa se encuentra en su tope derecho.
    int CLL1_MIN = 512; // de EEPROM Valor del ADC tomado en el sensor1 de la llave cuando esa se encuentra en su tope izquierdo.
    int CLL2_MAX = 0; // de EEPROM Valor del ADC tomado en el sensor2 de la llave cuando esa se encuentra en su tope izquierdo.
    int CLL2_MIN = 512; // de EEPROM Valor del ADC tomado en el sensor2 de la llave cuando esa se encuentra en su tope derecho.
    char STOP = 0; // Bandera de parada del motor.
    char DIRECC = 0; // Indica el estado de la direcci�n de giro del motor en el momento anterior al cambio.
    
    
//void InicializacionControlador(void)
//{
//    PWM3DCH = (24 & 0x03FC)>>2; //inicializando controlador
//    PWM3DCL = (24 & 0x0003)<<6;
//   __delay_ms(3000); // Fin de inicializaci�n controlador   
//}


    void InicializacionControlador(void)
{
    PWM3DCH = (24 & 0x03FC)>>2; //inicializando controlador
    PWM3DCL = (24 & 0x0003)<<6;
    __delay_ms(500); // Fin de inicializaci�n controlador   
}
    
    void InvGiro(void)
{    
    LL1_GIR_ADC = ADC_GetConversion(LL1_GIR);
    LL2_GIR_ADC = ADC_GetConversion(LL2_GIR);
    
    if (LL1_GIR_ADC>CLL1_L &&  LL2_GIR_ADC<CLL2_H) //Ambos sensores indican que la llave esta hacia la derecha?
    {
   //     STOP = 0;
        if (JGAT_1_2_PORT == 1)
        {
            if (DIRECC == 0)
            {   
                if (STOP == 1)
                {
                    if (TEMP_IG >= TMAX)
                    {
                        DIREC_LAT = 1;
                        DIRECC = 1;
                        STOP = 0;
                    }
                }
                else
                {
                    STOP = 1;
                }
            }
            else
            {
                STOP = 0;
            }
            
        }
    }
    else
    {
        if (LL1_GIR_ADC<CLL1_H && LL2_GIR_ADC>CLL2_L) //Ambos sensores indican que la llave esta hacia la izquierda?
        {
//            STOP = 0;
            if (JGAT_1_2_PORT == 1)
            {            
                if (DIRECC == 1)
                {   
                    if (STOP == 1)
                    {
                        if (TEMP_IG >= TMAX)
                        {
                            DIREC_LAT = 0;
                            DIRECC = 0;
                            STOP = 0;
                        }
                    }
                    else
                    {
                        STOP = 1;
                    }
                }
                else
                {
                    STOP = 0;
                }
            }
        }
        else
        {
            STOP = 1;
        }
        if (JGAT_1_2_PORT == 0)
        {
            GAT_GIR_ADC = ADC_GetConversion(GAT_GIR);
                if   (GAT_GIR_ADC < C_GG) // la presi�n del gatillo de inversi�n de giro alcanzo el % de comparaci�n?
                {
                    if (DIRECC == 0)
                    {   
                        if (STOP == 1)
                        {
                            if (TEMP_IG >= TMAX)
                            {
                                DIREC_LAT = 1;
                                DIRECC = 1;
                                STOP = 0;
                            }
                        }
                        else
                        {
                            STOP = 1;
                        }
                    }
                    else
                    {
                        STOP = 0;
                    }
                }
                else
                {
                    if (DIRECC == 1)
                    {   
                        if (STOP == 1)
                        {
                            if (TEMP_IG >= TMAX)
                            {
                                DIREC_LAT = 0;
                                DIRECC = 0;
                                STOP = 0;
                            }
                        }
                        else
                        {
                            STOP = 1;
                        }
                    }
                    else
                    {
                        STOP = 0;
                    }
                }
        }
        else
        {


        }   
     
    }
}   
    
    
void CalculosIniciales(void)
{
   C_GG = (int) (roundf(GG_MIN-(GG_MIN - GG_MAX)*(float)P_GG/100)); // Calculo del porcentaje "P_GG%" leido del ADC de presi�n de gatillo a partir del cual se puede invertir el giro.
   GINIC = (int) (roundf(GMIN-(GMIN-GMAX)*((float)PG_INIC)/100)); // Calculo del porcentaje "PG_INIC%" leido del ADC de presi�n de gatillo a partir del cual comienza a funcionar.
   if (V_MAX_PORT == 0)
   {
       DELTA_PWM = (DELTA_MAX_PWM*(100-PVLIM)/100);
   }
   else
   {
      DELTA_PWM= DELTA_MAX_PWM;
   }
   M_aux = DELTA_PWM/(float) GINIC-GMAX; // c�clulos auxiliares para realzar la mayor parte del c�lculo del PWM_VEL fuera del Wile.
   B_aux = (((GINIC*DELTA_PWM)/(float)(GINIC-GMAX))+PWM_MIN); // c�clulos auxiliares para realzar la mayor parte del c�lculo del PWM_VEL fuera del Wile.
   CLL1_L = (int) (roundf(CLL1_MIN - (CLL1_MIN-CLL1_MAX)*P_LL/100));
   CLL1_H = (int) (roundf(CLL1_MAX + (CLL1_MIN-CLL1_MAX)*P_LL/100));
   CLL2_L = (int) (roundf(CLL2_MIN - (CLL2_MIN-CLL2_MAX)*P_LL/100));
   CLL2_H = (int) (roundf(CLL2_MAX + (CLL2_MIN-CLL2_MAX)*P_LL/100));
   
   
    
}

/*
                         Main application
 */

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    //INICIALIZACI�N DE VARIABLES LOCALES
        
    int PWM_VEL = 24;
    
    
    
    // INICIO DE PROGRAM
    InicializacionControlador();
    CalculosIniciales();
    TMAX = TG_x10ms;
    while (1)
    {
       /*if (TEMP_IG >= TMAX)
        {
           TP1_LAT = 1;
        }
        else
        {
           TP1_LAT = 0; 
        }
        if (TP3_PORT == 0)
        {
            TEMP_IG = 0;
        }*/
       InvGiro();
       G_VEL_ADC = ADC_GetConversion(G_VEL);
       if (G_VEL_ADC<=GINIC && STOP==0)  // el gatillo est� presionado m�s del "PG_INIC%" y la bandera "STOP" est� dsactivada?
            {
            TEMP_IG = 0;
            PWM_VEL = (int) (roundf(B_aux-M_aux*G_VEL_ADC)); // se realiza el c�lculo final para la velocidad
            }
       else
            {
            PWM_VEL = 24; // Se detiene el motor y queda en modo Standby (listo para arrancar);
            }
       PWM3DCH = (PWM_VEL & 0x03FC)>>2;
       PWM3DCL = (PWM_VEL & 0x0003)<<6;
       
        // Add your application code
    }
}



/**
 End of File
*/