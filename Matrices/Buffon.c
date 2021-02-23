#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES
typedef struct
{
	double y;
	double theta;
}Buffon;

Buffon throw(void);

int main()
{
	int i,k,N;
	double y,pi;
	float sum = 0;
	Buffon needle;


	N = 10000;

	srand((unsigned int)time(NULL));

    k = 0;
    for(i = 0; i < N; i++)
    {
    	needle = throw();
    	y = needle.y;
    	if(y <= 0.5 * cos(needle.theta))
    	{	
    		k++;
    		sum += pi;
    	}
    	pi = (i+1) / (double)k;
    	
		printf("throw %d times,interset %d times pi is %f\n" ,i+1,k+1,pi);

	}
	printf("sss %f",sum/k);
	return 0;
}

Buffon throw()
{
	Buffon needle;
	needle.y = (double)rand()/RAND_MAX;
	
	needle.theta = ((double)rand()/RAND_MAX) * M_PI * 0.5;
	
	return needle;
}