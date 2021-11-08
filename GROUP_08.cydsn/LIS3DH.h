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

/* [] END OF FILE */
#ifndef __LIS3DH_H
    #define __LIS3DH_H

    /**
    *   \brief 7-bit I2C address of the slave device.
    */
    #define LIS3DH_DEVICE_ADDRESS 0x08

    /**
    *   \brief Address of the WHO AM I register
    */
    #define LIS3DH_WHO_AM_I_REG_ADDR 0x02
    
    /**
    *   \brief WHOAMI return value
    */
    #define LIS3DH_WHOAMI_RETVAL     0xBC
    
    /**
    *   \brief Address of the Control register 0
    */
    #define LIS3DH_CTRL_REG0 0x00
    
    /**
    *   \brief Address of the Control register 1
    */
    #define LIS3DH_CTRL_REG1 0x01
    
    /**
    *   \brief Address of Ch0 Bit 15-8  register 
    */
    #define LIS3DH_Ch0_15_8 0x03
    
    /**
    *   \brief Address of Ch0 Bit 7-0  register 
    */
    #define LIS3DH_Ch0_7_0 0x04
    
    /**
    *   \brief Address of Ch1 Bit 15-8  register 
    */
    #define LIS3DH_Ch1_15_8 0x05
    
    /**
    *   \brief Address of Ch1 Bit 7-0  register 
    */
    #define LIS3DH_Ch1_7_0 0x06
    
    

    /**
    *   \brief Address of the Status register
    */
    #define LIS3DH_STATUS_REG 0x27

   

   
    
#endif