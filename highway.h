#ifndef HIGHWAY_H
#define HIGHWAY_H

#define ZERO_BASED 1 // 1 if number of first segment is 0, 0 if number of first segment is 1

#include "segment.h"
#include <iostream>

class Segment;

extern int N;

class highway{
public:
	highway(const int &i,const int &K); // i is the number of segments, K is argument from command line
	~highway();
	
	
	int return_vehicles()const;					//Returns the numbers of vehicles in the highway
	int return_numofsegments()const{ return numofsegments; }     //Returns number of segments
	Segment *getSegmentByNumber(const int &number)const;
	void operate(); 					//Sunartisi ekfwnisis -> operate tis segment, also prints total cars in highway 

private:
	int numofsegments;	//Number of segments in the highway
	int vehicles;		//Number of vehicles in the highway
	Segment* *segmentarray;  //Array cointaining all segments

};

#endif
