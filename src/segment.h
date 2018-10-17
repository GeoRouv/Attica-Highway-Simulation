#ifndef SEGMENT_H
#define SEGMENT_H

#include "car.h"
#include "entrance.h"
#include "highway.h"

#include <vector>
using namespace std;

class Car;
class Entrance;
class highway;

class Segment{
public:

	Segment(const int &number, highway *whichRoad,const int &k,const int &l);
	~Segment();

	int getNumber()const;			// returns the position of this segment inside Attiki Odos
	int getRemainingSpace()const;	// returns how many more cars can be inserted
	int getLength()const;			// returns the (private member) length
	int getNumberOfVehicles()const; // returns current number of vehicles
	
	bool isFull()const;				// checks if any more vehicles can be added
	bool isFirst()const;			// checks if it is the first segment of Attiki Odos
	bool isLast()const;				// checks if it is the last segment of Attiki Odos
	
	void enterCar(Car *);			//inserts specified car into list
	void exitCars();				//checks which cars are about to exit and make them exit
	bool passCars();				//checks which cars are "ready" and makes them pass to next segment
	
	void operate();					//apo ekfwnhsh
									 /* -bgazei osa theloun na vgoun kai einai se etoimothta
	 									-pernaei sto epomeno segment osa einai se etoimothta
	 									-vazei amaksia apo ta diodia
	 									-ektypwnei mhnymata
	 								*/
	
private:

	int length;						//after this length number, every car enters "ready mode"
	int currVehicles;				//num of cars this moment
	int maxVehicles; 
	int numberPosition;				//position of this segment inside highway

	highway* road;
 	Entrance *payToll;				//pointer to its inner entrance with tolls
	vector<Car*> traffic;
	
	int K;
};

#endif
