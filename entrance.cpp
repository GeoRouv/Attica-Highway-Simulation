#include "entrance.h"

using namespace std;

Entrance::Entrance(Segment * whichSeg, highway * whichRoad, int k)
	: seg(whichSeg),road(whichRoad), K(k)
{
	for (int i=0; i<numOfTolls; i++){ // create numOfTolls E_Tolls and C_Tolls
		E_Toll *newToll=new E_Toll(seg, road);
		eTolls.push_back(newToll); // push pointers into vector

		C_Toll *newToll2=new C_Toll(seg, road);
		cTolls.push_back(newToll2);	
	}
}

Entrance::~Entrance(){
	for (int i=0; i<numOfTolls; i++){
		delete eTolls[i],cTolls[i]; // clear tolls data (cars waiting in tolls)
	}
}



bool Entrance::operate(){ // passes to segment K cars from C_Tolls and 2*K from E_Tolls if able, else passes as many as it can (same from all tolls)

	if (seg->getRemainingSpace()>= numOfTolls*K + numOfTolls*2*K){ // if the segment has space for 3*K cars
		for (int i=0; i<numOfTolls; i++){ // for each toll (C_ or E_ )
			for (int j=0; j<K; j++){ // repeat K times

				if (!cTolls[i]->isEmpty()) // if cars are waiting in the toll
					seg->enterCar(cTolls[i]->passNextCar()); // pass next car to segment
				
				if (!eTolls[i]->isEmpty()) // the process is  done twice for E_Tolls in order to pass 2*K cars
					seg->enterCar(eTolls[i]->passNextCar());
				if (!eTolls[i]->isEmpty())
					seg->enterCar(eTolls[i]->passNextCar());

			}
		}

		K++; // 3*K cars able to be inserted, so K is increased
		
	}else{ // no space for 3*K cars in segment
	
		int J=seg->getRemainingSpace()/(numOfTolls*2); // calculate how many cars can enter
				
		for (int i=0; i<numOfTolls; i++){ // for each toll

			for (int j=0; j<J; j++){ // repeat J times

				if (!cTolls[i]->isEmpty()) // if cars waiting
					seg->enterCar(cTolls[i]->passNextCar()); // pass next car
				if (!eTolls[i]->isEmpty())
					seg->enterCar(eTolls[i]->passNextCar());		
			}
		}
		if (K>0) {K--;} // reduce K in this case, but negative values have no meaning
		
	}
		bool flag=true;// value to be returned. if true, it means all waiting cars passed to segment

		for (int i=0; i<numOfTolls; i++){ // for each toll
			flag=(flag && cTolls[i]->isEmpty()); // if cars waiting make flag false and dont change it again
			flag=(flag && eTolls[i]->isEmpty());
			/* if find at leas one not empty, make flag false and never change it again */
			
		}

		if(!seg->isLast()){
			for (int i=0; i<numOfTolls; i++){ // "refill" tolls waiting lines with a random number of cars
				int repeatC=rand()%3;
				int repeatE=rand()%3; // waiting cars to be [0,2] makes sense
			
				for (int j=0; j<repeatC; j++) // repeat random times
					cTolls[i]->insertCar(); // insert cars into toll waiting line
				
				for (int k=0; k<repeatE; k++)
					eTolls[i]->insertCar();
			}
		}
		
		return flag;
}



