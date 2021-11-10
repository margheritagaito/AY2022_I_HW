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


#include "../InterruptRoutine/InterruptRoutine.h"
#include "project.h"


/* **** VARIABLES **** */


int32 raw_data_LDR[MAX_SIZE]; /* raw_data_LDR and raw_data_TS are defined as arrays */
int32 raw_data_TS[MAX_SIZE]; /* so if we want to know the single sample value we can obtain it*/
int32 mean_LDR = 0;
int32 mean_TS = 0;
int32 value_LDR;
int32 value_TS;
int count = 0;




/* **** FUNCTIONS **** */

// Entering in ISR every 4 ms = 250 Hz frequency

CY_ISR (Custom_ISR_ADC){
    
    Timer_ReadStatusRegister();
    
   
    // Sampling LDR
    
    AMux_Select(LDR_CHANNEL);
    raw_data_LDR[count] = ADC_DelSig_Read32();
    
    // To avoid boundaries problems
    
    if(raw_data_LDR[count] < MIN_VALUE) 
        raw_data_LDR[count] = MIN_VALUE;
    if(raw_data_LDR[count] > MAX_VALUE)
        raw_data_LDR[count] = MAX_VALUE;
        
    // Sum up values to do the average
        
    mean_LDR += raw_data_LDR[count];    
        
    // Sampling TS
        
    AMux_Select(TS_CHANNEL);
    raw_data_TS[count] = ADC_DelSig_Read32();
    
    // To avoid boundaries problems

    if(raw_data_TS[count] < MIN_VALUE) 
        raw_data_TS[count] = MIN_VALUE;
    if(raw_data_TS[count] > MAX_VALUE)
        raw_data_TS[count] = MAX_VALUE;
        
    // Sum up values to do the average
        
    mean_TS += raw_data_TS[count];
        
    // Update count value  
    count ++;
    
    if (count == sampling_size){
        
         // Obtain the avarage value of the two signals
    
        mean_LDR = mean_LDR / sampling_size;
        mean_TS = mean_TS / sampling_size;
    
        // Update values
        
        value_LDR = ADC_DelSig_CountsTo_mVolts(mean_LDR);
        value_TS = ADC_DelSig_CountsTo_mVolts(mean_TS);
        
        // Send values to the buffer_I2C
        
        buffer_I2C[2] = 0; 
      
        // Reset values
        
        mean_LDR = 0;
        mean_TS = 0;    
        count = 0;    
    }
        
        
}
    
/* [] END OF FILE */
