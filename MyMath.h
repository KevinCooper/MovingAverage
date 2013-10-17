/*
 * MyMath.h
 *
 *  Created on: Oct 16, 2013
 *      Author: C15Kevin.Cooper
 */

#ifndef MYMATH_H_
#define MYMATH_H_

#define INITIAL_RANDOM_SEED 0
#define MEM_SIZE 2  //The size of an integer

typedef struct{
	int * startAvg;
	int location;
	int numOfSamples;
} avgArray_t;
avgArray_t buildMovingAverage(int numOfSamples);
void addSample(avgArray_t *array, int sample);
int maxValue(avgArray_t *array);
int minValue(avgArray_t *array);
int maxValueArray(int *array, int size);
int minValueArray(int *array, int size);
int range(avgArray_t *array);
unsigned long int randInt(void);
int movingAverage(avgArray_t *array);

#endif /* MYMATH_H_ */
