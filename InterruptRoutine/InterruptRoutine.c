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
int32 mean_LDR;
int32 mean_TS;
int32 value_LDR;
int32 value_TS;


/* **** FUNCTIONS **** */

// Entering in ISR every 20 ms = 50 Hz frequency

CY_ISR (Custom_ISR_ADC){
    
    Timer_ReadStatusRegister();
    
    // Reset values
    
    mean_LDR = 0;
    mean_TS = 0;
    
    for(int i = 0; i < SIZE ; i++){
        
        // Sampling both LDR and TS
        
        AMux_Select(LDR_CHANNEL);
        raw_data_LDR = ADC_DelSig_Read32();
        AMux_Select(TS_CHANNEL);
        raw_data_TS = ADC_DelSig_Read32();
        
        // To avoid boundaries problems
        
        if(raw_data_LDR < MIN_VALUE) 
            raw_data_LDR = MIN_VALUE;
        if(raw_data_LDR > MAX_VALUE)
            raw_data_LDR = MAX_VALUE;
            
        if(raw_data_TS < MIN_VALUE) 
            raw_data_TS = MIN_VALUE;
        if(raw_data_TS > MAX_VALUE)
            raw_data_TS = MAX_VALUE;
            
        // Save the new aquired sample
            
        mean_LDR += raw_data_LDR;
        mean_TS += raw_data_TS;
        
        
    }
    
    // Obtain the avarage value of the two signals
    
    mean_LDR = mean_LDR / SIZE;
    mean_TS = mean_TS / SIZE;
    
    /* **** FINE PARTE FATTA **** */
    
    /*
    @daniele (e margherita) del futuro:
    - value_LDR e TS vanno trasformate da mV all'effettivo valore di resistenza
    - bisogna prima dimensionare la resistenza del partitore per LDR
    - trovare la formula inversa per entrambi i sensori
    */
    
    value_LDR = ADC_DelSig_CountsTo_mVolts(mean_LDR);
    
    // Display what ADC read
 
    sprintf(DataBuffer,"Sample: %ld mV\r\n", value_LDR);
    PacketReadyFlag = 1;
    
}
/* [] END OF FILE */
