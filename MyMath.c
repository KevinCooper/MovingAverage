/*
 * MyMath.c
 *
 *  Created on: Oct 16, 2013
 *      Author: C15Kevin.Cooper
 */

#include "MyMath.h"
#include <stdlib.h>
/*
 * Input: Integer number of samples that this data structure will be calculating the rolling average for
 * Output: avgArray_t data structure that allows for addSample() and movingAverage()
 */
avgArray_t buildMovingAverage(int numOfSamples)
{
	avgArray_t temp;
	temp.startAvg = malloc(numOfSamples * MEM_SIZE);
	temp.numOfSamples = numOfSamples;
	temp.location = 0;
	return temp;
}
/*
 * Input: Takes a avgArray data structure and adds the int sample onto the end
 * Output: None
 */
void addSample(avgArray_t *array, int sample)
{
	if (array->location == array->numOfSamples) {
		array->location = 0;
	}

	*(array->startAvg + array->location) = sample;

	array->location++;
}

/*
 * Input: avgArray structure to get rolling average from
 * Output: Returns the average of the number of most recent samples
 */
int movingAverage(avgArray_t *array)
{
	int i;
	int sum = 0;
	for (i = 0; i < array->numOfSamples; i++) {
		sum += *(array->startAvg + i);
	}
	return sum / array->numOfSamples;
}

/*
 * Input: avgArray structure to get max Value
 * Output: Returns the largest integer value from the last N samples added
 */
int maxValue(avgArray_t *array)
{
	int i, max = -15488;
	for (i = 0; i < array->numOfSamples; i++) {
		if (*(array->startAvg + i) > max)
			max = *(array->startAvg + i);
	}
	return max;
}
/*
 * Input: Array of integers and size of array
 * Output: Returns the largest integer value from the array
 */
int maxValueArray(int *array, int size)
{
	int i, max = -15488;
	for (i = 0; i < size; i++) {
		if (*(array + i) > max)
			max = *(array + i);
	}
	return max;
}
/*
 * Input: avgArray structure to get min Value
 * Output: Returns the smallest integer value from the last N samples added
 */
int minValue(avgArray_t *array)
{
	int i, min = 15487;
	for (i = 0; i < array->numOfSamples; i++) {
		if (*(array->startAvg + i) < min)
			min = *(array->startAvg + i);
	}
	return min;
}
/*
 * Input: Array of integers and size of array
 * Output: Returns the smallest integer value from the array
 */
int minValueArray(int *array, int size)
{
	int i, min = 15487;
	for (i = 0; i < size; i++) {
		if (*(array + i) < min)
			min = *(array + i);
	}
	return min;
}
/*
 * Input: avgArray structure to get range Value
 * Output: Returns the difference between the largest and smallest value from N most recent samples
 */
int range(avgArray_t *array)
{
	return (maxValue(array) - minValue(array));
}
/*
 * Input: None
 * Output: Returns a random unsigned long integer
 */
unsigned long int randInt(void)
{
	static unsigned long int random_seed = INITIAL_RANDOM_SEED;
	random_seed = random_seed * 1103515245 + 12345;
	return (unsigned long int) (random_seed / 65536) % 32768;
}
