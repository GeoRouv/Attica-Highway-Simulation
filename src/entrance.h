#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "toll.h"
#include "segment.h"
#include "highway.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>



class highway;
class Segment;
class Toll;
class C_Toll;
class E_Toll;

class Entrance{
public:
	Entrance(Segment *whichSeg, highway *whichRoad, int k);
	~Entrance();
	
	bool operate(); // Passes to segment K cars from C_Tolls and 2*K from E_Tolls if able, else passes max number possible cars, same for E and C tolls. Returns true if all vehicles of tolls are inserted into the corresponding segment.
	
	static const int numOfTolls=1; // 2 tolls seem to be enough

private:

	std::vector <E_Toll*> eTolls; // array of electronic tolls
	std::vector <C_Toll*> cTolls; // array of clerk tolls
	
	int K; // variable for passing rate
	
	Segment * seg; // which segment the entrance refers to
	highway * road; // which road the entrance belongs to (to be passed as argument to cars created in its tolls)

};

#endif
