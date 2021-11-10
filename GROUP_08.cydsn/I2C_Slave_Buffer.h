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


#ifndef __I2C_Slave_Buffer_H
    
    #define __I2C_Slave_Buffer_H
    
    
    
    //slave buffer address: 0x08
    #define SLAVE_BUFF_ADDR 0x08 //NON SO SE SERVE VERAMENTE
    
    //control register 0 address: 0x00
    #define CTRL_REG_0_ADDR 0x00
    
     //control register 1 address: 0x01
    #define CTRL_REG_1_ADDR 0x01
    
     //WhoAmI register address: 0x02
    #define WHOAMI_ADDR 0x02
    
    //WhoAmI register return value (read only)
    #define WHOAMI_RETVAL 0xBC
    
    
    //CH0 bit 15-08 register address: 0x03
    #define CH_0_MSB_ADDR 0x03
    
    //CH0 bit 07-00 register address: 0x04
    #define CH_0_LSB_ADDR 0x04
    
     //CH1 bit 15-08 register address: 0x05
    #define CH_1_MSB_ADDR 0x05
    
    //CH1 bit 07-00 register address: 0x06
    #define CH_1_LSB_ADDR 0x06
    
    // adesso i valori dei registri read only come li setto? posso usare buffer_I2C? mi sa di no, mi pare sia solo per fare la comunicazione con il master...no?
#endif

/* [] END OF FILE */
