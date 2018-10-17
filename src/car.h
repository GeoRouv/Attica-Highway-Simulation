#ifndef CAR_H
#define CAR_H

#include "highway.h"
#include "segment.h"
#include <iostream>
class highway;
class Segment;

class Car {

public:
	Car(const int &whichSegment,const int &exitNode, highway *whichRoad);
	~Car();
	void setSegmentNumber(const int &number) {segmentNumber=number;} //set in which segment the car is moving
	void move();	// increase car's position in the segment by 1
	void move(const int speed); // increase car's position in the segment by <speed>
	int proceed(); // make car belong to the next segment
	bool toExit(const int gate)const; // returns true if the car has <gate> as exit segment number
	bool isReady()const;
	void setPlace(const int &p){segPlace=p;}
	
private:

	int segPlace; // the position of the car inside the segment [values from 0 to segment::length]
	int segmentNumber; // the index of the segment in which the car belongs
	int exitSegNum; // number of segment from which the car will exit
	highway * road; // which highway the car belongs to

};

#endif
