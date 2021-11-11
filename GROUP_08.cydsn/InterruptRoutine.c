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


#include "InterruptRoutine.h"
#include "project.h"


/* **** VARIABLES **** */


int32 raw_data_LDR;
int32 raw_data_TS; 
int32 mean_LDR = 0;
int32 mean_TS = 0;
int32 value_LDR;
int32 value_TS;
uint8 count = 0;




/* **** FUNCTIONS **** */

void EZI2C_ISR_ExitCallback(){

        // Update the variables to given values 
    
        //define the number of smaples to be used to compute the average
        sampling_size = (buffer_I2C[CTRL_REG_0_ADDR] & AVG_SAMPLES_MASK) >> 2 ;
        
       
        
        // Set timer period at the one selected
       //Timer_WritePeriod(1/(buffer_I2C[CTRL_REG_1_ADDR]*sampling_size));
        Timer_WritePeriod((buffer_I2C[CTRL_REG_1_ADDR])/sampling_size);
        
        
        //check both devices ON -> from status pins in CTRL REG 0
        device_status = (buffer_I2C[CTRL_REG_0_ADDR] & (STATUS));



}

CY_ISR (Custom_ISR_ADC){
    
    Timer_ReadStatusRegister();
    
     // Sampling TS only if its status bit is ON
    
    if((buffer_I2C[CTRL_REG_0_ADDR] & CH0_ON) == CH0_ON){
        
        AMux_Select(TS_CHANNEL);
        raw_data_TS = ADC_DelSig_Read32();
        
        // To avoid boundaries problems

        if(raw_data_TS < MIN_VALUE) 
            raw_data_TS = MIN_VALUE;
        if(raw_data_TS > MAX_VALUE)
            raw_data_TS = MAX_VALUE;
            
        // Sum up values to do the average
            
        mean_TS += raw_data_TS;
        
     } 
    
    // Sampling LDR only if its status bit is ON
    
    if ((buffer_I2C[CTRL_REG_0_ADDR] & CH1_ON) == CH1_ON){ 
        
        AMux_Select(LDR_CHANNEL);
        raw_data_LDR = ADC_DelSig_Read32();
    
        // To avoid boundaries problems
    
        if(raw_data_LDR < MIN_VALUE) 
            raw_data_LDR = MIN_VALUE;
        if(raw_data_LDR > MAX_VALUE)
            raw_data_LDR = MAX_VALUE;
            
        // Sum up values to do the average
            
        mean_LDR += raw_data_LDR;    
    }
      
    
    // Update count value  
    count ++;
    
    if (count == sampling_size){
        
         // Obtain the avarage value of the two signals
        
        mean_TS = mean_TS / sampling_size;
        mean_LDR = mean_LDR / sampling_size;
    
        // Update values
        
        value_TS = ADC_DelSig_CountsTo_mVolts(mean_TS);
        value_LDR = ADC_DelSig_CountsTo_mVolts(mean_LDR);
        
        
        // Save values to the buffer_I2C
        
        buffer_I2C[CH_0_MSB_ADDR] = (uint8)(value_TS >> 8); // Select the MSB
        buffer_I2C[CH_0_LSB_ADDR] = (uint8)(value_TS & 0xFF); // Select the LSB
        buffer_I2C[CH_1_MSB_ADDR] = (uint8)(value_LDR >> 8); // Select the MSB
        buffer_I2C[CH_1_LSB_ADDR] = (uint8)(value_LDR & 0xFF); // Select the LSB
      
        // Reset values
        
        mean_TS = 0;
        mean_LDR = 0;    
        count = 0;    
    }  
        
}
    
/* [] END OF FILE */