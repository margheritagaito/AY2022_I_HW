/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/


/* **** INCLUDES **** */


#include "project.h"
#include "define.h"
#include "InterruptRoutine.h"
#include "cyapicallbacks.h"


/* **** MAIN **** */


int main(void)
{ 
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  
    // Turn on EZI2C
    EZI2C_Start();
    
    // Set up buffer     
    EZI2C_SetBuffer1(BUFFER_SIZE , 2 , buffer_I2C);
    
    // Write on buffer the WAI register with the return value
    buffer_I2C[WHOAMI_ADDR] = WHOAMI_RETVAL;
    
    // Start with LED LOW
    Pin_LED_Write(LOW);

    // Start the timer
    Timer_Start();
    
    // Start ADC
    ADC_DelSig_Start();
    
    // Start ISR
    isr_Timer_StartEx(Custom_ISR_ADC);
    
    
    for(;;)
    {   
        // Turn on the LED if both channels are being sampled
        
        if (device_status == BOTH_ON)
            Pin_LED_Write(HIGH);
        else 
            Pin_LED_Write(LOW);
        
    
    }
}

/* [] END OF FILE */
