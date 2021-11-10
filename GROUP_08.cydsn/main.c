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

#include "project.h"
#include "I2C_Slave_Buffer.h"
#include "../InterruptRoutine/InterruptRoutine.h"

int main(void)
{ 
    
    uint8 device_status;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    //turn on EZI2C
    EZI2C_Start();
    //set up buffer     
    EZI2C_SetBuffer1(7 , 2 , (void*) buffer_I2C);
    //write on buffer the WAI register with the return value
    buffer_I2C[WHOAMI_ADDR] = WHOAMI_RETVAL;
    
    //start with LED OFF
    Pin_LED_Write(0);
    
    for(;;)
    {
        //define the number of smaples to be used to compute the average
        sampling_size = buffer_I2C[CTRL_REG_0_ADDR] | AVG_SAMPLES_MASK ;
        
        
        //check both devices ON -> from status pins in CTRL REG 0
        device_status = buffer_I2C[0] | (BOTH_ON_MASK);
        
        // Set timer period at the one selected 
        
        Timer_WritePeriod(buffer_I2C[CTRL_REG_1_ADDR]); 
        
        // Turn on the LED if both channels are being sampled
        
        if (device_status == BOTH_ON)
            Pin_LED_Write(1);
    }
}

/* [] END OF FILE */
