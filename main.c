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
 */ #define T_INIC 500 // Tiempo en milisegundos de Inicializacion del Controlador.
    #define PG_INIC 10.0 // % Porcentaje del gatillo a partir del cual comienza a funcionar el motor
    #define P_GG 40.0 // % Porcentaje del gatillo a partir del cual se produce la inversión de giro
    #define P_LL 30.0 // % Porcentaje de las llaves a partir del cual se produce la detención del motor (o cambio de sentido de giro).
    #define PVLIM 20.0 // % Porcentaje de velocidad Limite final.
    #define DELTA_MAX_PWM 25.0 // Diferencia entre PWM a velocidad máxima y velocidad mínima
    #define PWM_MIN 31 // Valor mínimo estable al que puede girar el motor.
    #define TG_x10ms 150 // Tiempo x10 milisegundos usado para espera de inversión de giro.
/*
                        ***** VARIABLES GLOBALES *****
 */
    short GAT_GIR_ADC = 512;
    short LL1_GIR_ADC = 0;
    short LL2_GIR_ADC = 512;
    short G_VEL_ADC = 512;
    short C_GG = 399; // Valor calculado para comparación del ADC a partir del cual el Gatillo de giro produce el cambio de sentido del motor.
    short GINIC = 500; // Valor calculado para comparación del ADC a partir del cual el gatillo de velocidad comienza a actuar.
    short CLL1_L = 470; //Valor calculado para comparación del ADC a partir del cual el sensor1 de la llave pasa de el tope izquierdo al centro (para detención de giro).
    short CLL1_H = 425; //Valor calculado para comparación del ADC a partir del cual el sensor1 de la llave pasa de el tope derecho al centro (para detención de giro).
    short CLL2_L = 470; //Valor calculado para comparación del ADC a partir del cual el sensor2 de la llave pasa de el tope derecho al centro (para detención de giro).
    short CLL2_H = 425; //Valor calculado para comparación del ADC a partir del cual el sensor2 de la llave pasa de el tope izquierdo al centro (para detención de giro).
 //   float M_aux = 0; // Variables auxiliares para realzar la mayor parte del cálculo del PWM_VEL fuera del Wile.
 //   float B_aux = 0; // Variables auxiliares para realzar la mayor parte del cálculo del PWM_VEL fuera del Wile.
    char DELTA_PWM =0; // Variable auxiliar para el calculo de límite de velocidad
    short GMAX = 0; //  de EEPROM Valor del ADC que alcanza el gatillo de velocidad presionado al máximo (menor valor ADC).
    short GMIN = 512; // de EEPROM Valor del ADC que alcanza el gatillo de velocidad presionado al mínimo (mayor valor ADC).
    short GG_MAX = 512; // de EEPROM Valor del ADC que alcanza el gatillo de Giro presionado al máximo (mínimo valor ADC).
    short GG_MIN = 0; // de EEPROM Valor del ADC que alcanza el gatillo de Giro presionado al mínimo (mayor valor ADC).
    short CLL1_MAX = 0; // de EEPROM Valor del ADC tomado en el sensor1 de la llave cuando esa se encuentra en su tope derecho.
    short CLL1_MIN = 512; // de EEPROM Valor del ADC tomado en el sensor1 de la llave cuando esa se encuentra en su tope izquierdo.
    short CLL2_MAX = 0; // de EEPROM Valor del ADC tomado en el sensor2 de la llave cuando esa se encuentra en su tope izquierdo.
    short CLL2_MIN = 512; // de EEPROM Valor del ADC tomado en el sensor2 de la llave cuando esa se encuentra en su tope derecho.
    char STOP = 0; // Bandera de parada del motor.
    char DIRECC = 0; // Indica el estado de la dirección de giro del motor en el momento anterior al cambio.
    char BAND_MEM = 0; // Bandera utilizada para saber si se debe grabar en la memo flash (ex eeprom).
    uint16_t ADRESS = 0x0F80;
    uint16_t BUFFER = 0;
    uint16_t WORD = 0;
    uint16_t BLOQUE_MEM [32];
    
   
    void Autocalibracon(void)
    {
        while (!GAT_1_2_PORT)
        {
            BAND_MEM = 1;
            G_VEL_ADC = ADC_GetConversion(G_VEL);
            if (G_VEL_ADC<GMAX)
            {
              //  GMAX = G_VEL_ADC;
            }
            if (G_VEL_ADC>GMIN)
            {
               // GMIN = G_VEL_ADC;
            }
            GAT_GIR_ADC = ADC_GetConversion(GAT_GIR);
            if (GAT_GIR_ADC<GG_MAX)
            {
              //  GG_MAX = GAT_GIR_ADC;
            }
            if (GAT_GIR_ADC>GG_MIN)
            {
              //  GG_MIN = GAT_GIR_ADC;
            }
            LL1_GIR_ADC = ADC_GetConversion(LL1_GIR);
            if (LL1_GIR_ADC<CLL1_MAX)
            {
              //  CLL1_MAX = LL1_GIR_ADC;
            }
            if (LL1_GIR_ADC>CLL1_MIN)
            {
              //  CLL1_MIN = LL1_GIR_ADC;
            }
            LL2_GIR_ADC = ADC_GetConversion(LL2_GIR);
            if (LL2_GIR_ADC<CLL2_MAX)
            {
              //  CLL2_MAX = LL2_GIR_ADC;
            }
            if (LL2_GIR_ADC>CLL2_MIN)
            {
             //   CLL2_MIN = LL2_GIR_ADC;
            }
            
        }
                        
            if (BAND_MEM == 1)
            {
                BLOQUE_MEM [1] = GMAX;
                BLOQUE_MEM [2] = GMIN;
                BLOQUE_MEM [3] = GG_MAX;
                BLOQUE_MEM [4] = GG_MIN;
                BLOQUE_MEM [5] = CLL1_MAX;
                BLOQUE_MEM [6] = CLL1_MIN;
                BLOQUE_MEM [7] = CLL2_MAX;
                //   FLASH_WriteWord(ADRESS, ADRESSP, TG_x10ms);
                FLASH_WriteBlock(ADRESS, BLOQUE_MEM);
                
                //TMAX = FLASH_ReadWord(ADRESS);
                     
            }
        
         
        
        
        
            // leer en EEPOM cada uno de las 8 variables en variables auxiliares y si estan en FF reemplazarlas por los valores que contienen originales.
            // si los valores de EEPROM son distintos de FF colocar el valor leido en cada una de las variables
        
    }
    
    void InicializacionControlador(void)
{
    PWM3DCH = (24 & 0x03FC)>>2; //inicializando controlador
    PWM3DCL = (24 & 0x0003)<<6;
    __delay_ms(T_INIC); // Fin de inicialización controlador   
}
    
    void InvGiro(void)
{    
    LL1_GIR_ADC = ADC_GetConversion(LL1_GIR);
    LL2_GIR_ADC = ADC_GetConversion(LL2_GIR);
    
    if ((LL1_GIR_ADC<CLL1_H && LL2_GIR_ADC>CLL2_L) || (LL1_GIR_ADC>CLL1_L &&  LL2_GIR_ADC<CLL2_H))
    {
        if (JGAT_1_2_PORT == 1)
        {
            if (LL1_GIR_ADC>CLL1_L &&  LL2_GIR_ADC<CLL2_H) //Ambos sensores indican que la llave esta hacia la derecha?
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
            if (LL1_GIR_ADC<CLL1_H && LL2_GIR_ADC>CLL2_L) //Ambos sensores indican que la llave esta hacia la izquierda?
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
            GAT_GIR_ADC = ADC_GetConversion(GAT_GIR);
            if   (GAT_GIR_ADC < C_GG) // la presión del gatillo de inversión de giro alcanzo el % de comparación?
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
    }
    else
    {
        STOP = 1;
    }
}   
    
    
void CalculosIniciales(void)
{
   C_GG = (int) (roundf(GG_MIN-(GG_MIN - GG_MAX)*(float)P_GG/100)); // Calculo del porcentaje "P_GG%" leido del ADC de presión de gatillo a partir del cual se puede invertir el giro.
   GINIC = (int) (roundf(GMIN-(GMIN-GMAX)*((float)PG_INIC)/100)); // Calculo del porcentaje "PG_INIC%" leido del ADC de presión de gatillo a partir del cual comienza a funcionar.
/*   if (V_MAX_PORT == 0)
   {
       DELTA_PWM = (char) roundf(DELTA_MAX_PWM*(100-PVLIM)/100);
   }
   else
   {
      DELTA_PWM= DELTA_MAX_PWM;
   }*/
 //  M_aux = DELTA_PWM/(float) GINIC-GMAX; // cáclulos auxiliares para realzar la mayor parte del cálculo del PWM_VEL fuera del Wile.
 //  B_aux = (((GINIC*DELTA_PWM)/(float)(GINIC-GMAX))+PWM_MIN); // cáclulos auxiliares para realzar la mayor parte del cálculo del PWM_VEL fuera del Wile.
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

    //INICIALIZACIÓN DE VARIABLES LOCALES
        
    int PWM_VEL = 24;
        
    // INICIO DE PROGRAM
    InicializacionControlador();
    CalculosIniciales();

    TMAX = TG_x10ms;
    while (1)
    {
       InvGiro();
       G_VEL_ADC = ADC_GetConversion(G_VEL);
         if (V_MAX_PORT == 0)
    {
       DELTA_PWM = (char) roundf(DELTA_MAX_PWM*(100-PVLIM)/100);
    }
    else
    {
       DELTA_PWM= DELTA_MAX_PWM;
    }
       if (G_VEL_ADC<=GINIC && STOP==0)  // el gatillo está presionado más del "PG_INIC%" y la bandera "STOP" está dsactivada?
            {
            TEMP_IG = 0;
            PWM_VEL = (int) roundf(((GINIC-G_VEL_ADC)*DELTA_PWM/(GINIC-GMAX))+31);
            //  PWM_VEL = (int) (roundf(B_aux-M_aux*G_VEL_ADC)); // se realiza el cálculo final para la velocidad
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