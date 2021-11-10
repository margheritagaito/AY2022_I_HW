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

#define BOTH_ON_MASK 0b00000011 //mask, used to select the two status pins in control register 0
#define BOTH_ON 0b00000011 //value used to check both devices connected and visualize that with LED
#define CH0_ON 0b00000001 //only channel 0 on
#define CH1_ON 0b00000010 //only channel 1 on
#define BOTH_OFF 0b00000000 //both channels off 
/*questa cosa può essere fatta un maniera più intelligente probabilmente-> solo con ch0 e ch1 senza both...!!!!!!!!!!*/

#define AVG_SAMPLES_MASK 0b00111100 /*mask, used to access the 4 bits (in control register 0)
that determine the number of samples to be averaged */ 


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
        if (device_status == BOTH_ON)
        {
            Pin_LED_Write(1);
        }
    }
}

/* [] END OF FILE */
