#include <msp430.h> 
#include "MyMath.h"

#define N_AVG_SAMPLES 4

/*
 * main.c
 * Author: Kevin Cooper
 * Date: 16 Oct 13
 * Description: Tests the MyMath functions to simulate the rolling average of several data points
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    int i ;
    avgArray_t test = buildMovingAverage(N_AVG_SAMPLES);
    int array[10] = {45, 42, 41, 40, 43, 45, 46, 47, 49, 45};
    volatile int junk=0;
    for( i =0;i < 10;i++){
    	addSample(&test, array[i]);
    	junk = movingAverage(&test);
    }
    junk = maxValue(&test);
    junk = minValue(&test);
    junk = range(&test);

	return 0;
}
