#ifndef TOLL_H
#define TOLL_H

#include "car.h"
#include "segment.h"
#include "highway.h"

#include <stdlib.h>
#include <time.h>
#include <list>
using namespace std;

class Car;
class Segment;
class highway;


class Toll{
public:
	Toll(Segment *whichSeg, highway *whichRoad);
	~Toll();
	
	Car* passNextCar(); // removes and returns the first car waiting in its queue
	void insertCar(); // insert 1 car waiting in its queue.
	bool isEmpty()const {return queue.size()==0;}

	static const int capacity=10;
	
private:
	list <Car*> queue; // waiting list of cars to enter the segment
	Segment* seg;
	highway* road;

};

class E_Toll: public Toll{
public:
	E_Toll(Segment* whichSeg, highway* whichRoad):Toll(whichSeg, whichRoad){}
	~E_Toll(){}
	
};

class C_Toll: public Toll{
public:
	C_Toll(Segment* whichSeg, highway* whichRoad):Toll(whichSeg, whichRoad){}
	~C_Toll(){}
	
};

#endif
