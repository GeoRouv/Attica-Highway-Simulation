#include "car.h"


Car::Car(const int &whichSegment,const int &exitNode, highway * whichRoad)
	:segPlace(0), segmentNumber(whichSegment), exitSegNum(exitNode), road(whichRoad)
{}

Car::~Car(){}

void Car::move(){
	Segment * currSeg=road->getSegmentByNumber(segmentNumber); // get segment object
	if (segPlace<currSeg->getLength()){	// if has not moved to the whole length
		segPlace++; // increase its position in the segment
	}
}

void Car::move(const int speed){ // same as Car::move, but its position is increased by <speed>
	Segment * currSeg=road->getSegmentByNumber(segmentNumber);
	if (segPlace<currSeg->getLength()){
		segPlace+=speed;

		if (segPlace>currSeg->getLength()){ //if its current position+<speed> exceeds segment::length, current position is just segment::length
			segPlace=currSeg->getLength();
		}
	}
}

int Car::proceed(){
	if (road->return_numofsegments()>segmentNumber){ //if there is next segment

		Segment *currSeg=road->getSegmentByNumber(segmentNumber); //get curr segment
		if (isReady()){ //if car is ready(is at the end of seg)
			segPlace=0;		// car is at the beginning (of the next)
			segmentNumber++; // car is in the next
			return 0;
		}else{
			return 1; // error: not ready
		}
	}else{
		return 2; // error: there is no next segment to proceed
	}	
}

bool Car::toExit(int exit)const{
	return exit==exitSegNum; // if <exit> is the number of segment the car wants to exit
}

bool Car::isReady()const{
	return segPlace==road->getSegmentByNumber(segmentNumber)->getLength();
} 

