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

#define BOTH_ON 0b00000011 //to check both devices connected and visualize that with LED




//create buffer for I2C slave
uint8 buffer_I2C[7];

int main(void)
{
    
    uint8 device_status;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    //turn on EZI2C
    EZI2C_Start();
    //set up buffer     
    EZI2C_SetBuffer1(7 , 2 , (void*) buffer_I2C);
    
    //start with LED OFF
    Pin_LED_Write(0);
    

    for(;;)
    {
        /* Place your application code here. */
        
        
        //check both devices ON -> from status pins in CTRL REG 0
        device_status = buffer_I2C[0] | (0x00111100);
        if (device_status == BOTH_ON)
        {
            Pin_LED_Write(1);
        }
    }
}

/* [] END OF FILE */
