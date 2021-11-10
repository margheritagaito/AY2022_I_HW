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
    #include "define.h"
    
    CY_ISR_PROTO (Custom_ISR_ADC);
    
    //create buffer for I2C slave
    uint8 buffer_I2C[BUFFER_SIZE];
    uint8 sampling_size;
    
#endif

/* [] END OF FILE */

