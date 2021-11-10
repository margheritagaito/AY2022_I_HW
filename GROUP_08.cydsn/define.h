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


#ifndef __DEFINE_H
    
    #define __DEFINE_H
    
    // Define adress of Buffer
    
    #define SLAVE_BUFF_ADDR 0x08            //slave buffer address: 0x08
    #define CTRL_REG_0_ADDR 0x00            //control register 0 address: 0x00
    #define CTRL_REG_1_ADDR 0x01            //control register 1 address: 0x01
    #define WHOAMI_ADDR     0x02            //WhoAmI register address: 0x02
    #define CH_0_MSB_ADDR   0x03            //CH0 bit 15-08 register address: 0x03
    #define CH_0_LSB_ADDR   0x04            //CH0 bit 07-00 register address: 0x04
    #define CH_1_MSB_ADDR   0x05            //CH1 bit 15-08 register address: 0x05
    #define CH_1_LSB_ADDR   0x06            //CH1 bit 07-00 register address: 0x06
    
    //WhoAmI register return value (read only)
    
    #define WHOAMI_RETVAL 0xBC
    
    // Masks
    
    #define STATUS              0b00000011  //mask, used to select the two status pins in control register 0
    #define BOTH_ON             0b00000011  //value used to check both devices connected and visualize that with LED
    #define CH0_ON              0b00000001  //only channel 0 on
    #define CH1_ON              0b00000010  //only channel 1 on
    #define BOTH_OFF            0b00000000  //both channels off 
    #define AVG_SAMPLES_MASK    0b00111100  //mask, used to access the 4 bits (in control register 0) that determine the number of samples to be averaged
    
    // Other defines
    
    #define HIGH        1
    #define LOW         0
    #define MIN_VALUE   0
    #define MAX_VALUE   65535
    #define LDR_CHANNEL 1
    #define TS_CHANNEL  0
    #define BUFFER_SIZE 7
    
#endif

/* [] END OF FILE */
