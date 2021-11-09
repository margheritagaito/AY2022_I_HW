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
    
    #include "cytypes.h"
    #include "stdio.h"
    
    /* **** DEFINE **** */
    
    
    #define TRANSMIT_BUFFER_SIZE 16 // Credo vada modificata per l'I2C
    #define MIN_VALUE 0
    #define MAX_VALUE 65535
    #define MAX_SIZE 100 // Sample fatto al massimo su 100 valori
    #define LDR_CHANNEL 0
    #define TS_CHANNEL 1
    
    CY_ISR_PROTO (Custom_ISR_ADC);
    
    char DataBuffer[TRANSMIT_BUFFER_SIZE];
    volatile uint8 PacketReadyFlag;
    
#endif

/* [] END OF FILE */
