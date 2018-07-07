#include "toll.h"

Toll::Toll(Segment * whichSeg, highway* whichRoad)
	:seg(whichSeg), road(whichRoad)
{
	srand(time(NULL));
	int tmp = rand()%capacity; if (tmp==0) tmp=capacity/2;
	for (int i=0; i<tmp; i++){ // create a random number of cars with random exit node and add them to the queue
	
		int randExit=rand()%(road->return_numofsegments()-seg->getNumber())+seg->getNumber();//create an exit node number between the index of this segment and the total number of segments
		if (randExit==0) randExit++; //first segment has no exit
		
		Car* tmpCar = new Car(-1, randExit, road);
		queue.push_back(tmpCar);
	}

}

Toll::~Toll(){
	for (list<Car *>::iterator it = queue.begin(); it!=queue.end(); it++){
		delete *it;
	}
}

Car* Toll::passNextCar(){
	Car* ingoing = queue.front();					// get first car
	queue.pop_front();								// remove it from list
	ingoing->setSegmentNumber(seg->getNumber());	// set to it correct segment number
	return ingoing;
}

void Toll::insertCar(){ // inserts next car in its queue
	if (queue.size()>= capacity)// if already full, exit
		return;
	int randExit=rand()%(road->return_numofsegments()-seg->getNumber())+seg->getNumber();//create an exit node number between the index of this segment and the total number of segments
	if (randExit==0) randExit++; //first segment has no exit
	Car* tmpCar = new Car(-1, randExit, road);
	queue.push_back(tmpCar);
}
