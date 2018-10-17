#include "segment.h"

Segment::Segment(const int& number, highway * whichRoad,const int& k,const int& l)
	:numberPosition(number), road(whichRoad), K(k), currVehicles(0), maxVehicles(rand()%(20-10+1)+10), length(l)
{
	payToll= new Entrance(this, road, k); // create an entrance

	int x=rand()%maxVehicles+1; // determine how many cars are to be pre-inserted
	
	for (int i=0; i<x; i++){ // repeat x times
	
		int exitLocation=rand()%(road->return_numofsegments()-number)+number;//create an exit node number between the index of this segment and the total number of segments
		if(exitLocation==0) exitLocation++; //First segment doesn't exit cars,changing exit location
		Car *temp = new Car(number, exitLocation, road); // create a car in this segment, with that exit node number
		temp->setPlace(rand()%length);
		traffic.push_back(temp); // push it into array
	}
	currVehicles=x; // how many vehicles are currently in the segment
}

Segment::~Segment()
{
	delete payToll;

	for (int i=0; i<currVehicles; i++){
		delete traffic[i];
	}

}

void Segment::operate(){
/*	1. moves inside cars so as to make them ready
	2. passes ready cars that don't want to exit here into next segment. Prints corresponding message
	3. exits ready cars that have this segment as exit segment
	4. inserts a number of cars from its entrance tolls. Prints corresponding message
	5. if no other messages are printed, prints default message
*/

	/* 1 *//////////////////////////////////////////////////
	for (int i=0; i<currVehicles; i++){ // move all cars
		if (!traffic[i]->isReady()){
			traffic[i]->move(rand()%(2)+1); //each car moves with a random speed between 1 and 3
		}
	}
	
	bool notDelay=true, delayHappened=false;
	
	/* 2 *//////////////////////////////////////////////////
	if (!isLast()){
		notDelay = passCars();//pass ready cars to next segment, return true if all cars passed, false else (delay)
	}
	if (!notDelay){ // if delays are occuring
		cout<<"Kathysterhseis meta ton komvo " <<numberPosition<<endl;
		delayHappened=true;
	}
	
	/* 3 */////////////////////////////////////////////////
	exitCars();//exit ready cars with this node as exit
	
	/* 4 */////////////////////////////////////////////////
	notDelay=payToll->operate(); // insert cars from tolls to segment and insert new cars at tolls
	if (!notDelay){ // if delays are occuring
		cout<<"Kathysterhseis sthn eisodo tou komvou " <<numberPosition<<endl;
		delayHappened=true;
	}
	
	/* 5 */////////////////////////////////////////////////
	if (!delayHappened){ // if everything is OK
		cout<<"Threite tis apostaseis asfaleias sto tmhma meta ton komvo " <<numberPosition<<endl;
	}
}

/* Getter methods and some boolean ones */
int Segment::getNumber()const{
	return numberPosition;
}

int Segment::getRemainingSpace()const{
	return maxVehicles-currVehicles;
}

int Segment::getLength()const{
	return length;
}

int Segment::getNumberOfVehicles()const{
	return currVehicles;
}

bool Segment::isFull()const{
	return maxVehicles==currVehicles;
}

bool Segment::isFirst()const{
	return numberPosition==0; 
}

bool Segment::isLast()const{
	return numberPosition==road->return_numofsegments()-1;
}

/* Functions needed for operate() */
void Segment::enterCar(Car * aCar){

	if (getRemainingSpace()>0){ // if there is space to enter that car
		traffic.push_back(aCar); // push it back into array
		currVehicles++;
	}
}

void Segment::exitCars(){

	for (int i=0; i<currVehicles; i++){ // for each vehicle
	
		if (traffic[i]->toExit(numberPosition) && traffic[i]->isReady()){ //if is to exit here and is ready
		
			delete traffic[i]; // delete the actual car
			traffic.erase(traffic.begin()+i); // remove its pointer for the array
			currVehicles--;
		}
	}
}

bool Segment::passCars(){

	for (int i=0; i<currVehicles; i++){ // for each car

		if ( ! traffic[i]->toExit(numberPosition) ){ // if its exit node is not this one

			if (traffic[i]->isReady()){ // if is ready

				if (!isLast()){ // if this is not the last segment

					Segment *nextSegment = road->getSegmentByNumber(numberPosition+1); // get next segment

					if (nextSegment->isFull()) // if next segment is not full
						return false;

					traffic[i]->proceed(); // car proceed (changes appropriate car members)
					nextSegment->enterCar(traffic[i]); // enter car's pointer in next segment
					traffic.erase(traffic.begin()+i); // delete car's pointer from this segment				
					currVehicles--;
				}
			}
		}
	}
	return true;
}
