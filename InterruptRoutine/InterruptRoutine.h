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

#ifndef __INTERRUPT_ROUTINE_H
    
    #define __INTERRUPT_ROUTINE_H
    
    /* **** INCLUDE **** */
    
    #include "cytypes.h"
    #include "stdio.h"
    #include "I2C_Slave_Buffer.h"
    
    /* **** DEFINE **** */
    
    #define MIN_VALUE 0
    #define MAX_VALUE 65535
    #define MAX_SIZE 100 // Sample fatto al massimo su 100 valori
    #define LDR_CHANNEL 1
    #define TS_CHANNEL 0
    
    CY_ISR_PROTO (Custom_ISR_ADC);
    
    //create buffer for I2C slave
    uint8 buffer_I2C[7];
    int sampling_size;
    
#endif

/* [] END OF FILE */
