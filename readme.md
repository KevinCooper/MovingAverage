##Moving Average by Kevin cooper

###Description
This is the implementation of a data structure that keeps a moving average.  To use the following file, create the data structure by using buildMovingAverage(N), where N is the number of samples that you want it to average.  The results of the average cannot be guaranteed until you enter in as many value as your moving average is supposed to keep track of.

`avgArray_t buildMovingAverage(int numOfSamples)`

Adds a new sample to be kept in the Moving average MovingAverage 
`void addSample(avgArray_t *array, int sample)`

Returns the smallest value in the MovingAverage 
`int maxValue(avgArray_t *array)`

Returns the largest value in the MovingAverage 
`int minValue(avgArray_t *array)`

Returns the max value in the array passed.
`int maxValueArray(int *array, int size)`

Returns the smallest value in the array passed
`int minValueArray(int *array, int size)`

Returns the range of values in the MovingAverage 
`int range(avgArray_t *array)`

Returns a random unsigned long integer
`unsigned long int randInt(void)`

Returns the average of the values in the MovingAverage 
`int movingAverage(avgArray_t *array)`