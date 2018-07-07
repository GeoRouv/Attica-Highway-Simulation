#include "highway.h"
#include "segment.h"

using namespace std;

highway::highway(const int &i,const int &K) // i is the number of segments of the highway
	:numofsegments(i)
{
	Segment * temp;
	segmentarray = new Segment*[numofsegments]; // create an array of segment *
	
	for(int j=0;j<numofsegments; j++){ // repeat <number of segment> times

		int length=rand()%(N/i)+1; // each car may need <length-of-segment>*<number-of-segments> cycles to exit the highway
 
		temp=new Segment(j,this,K,length);  // create a new pointer to segment
		segmentarray[j]=temp; // insert it into array
	}
	
	vehicles=return_vehicles(); // set number of current vehicles
	
	cout<<"Aytokinhtodromos se leitourgia!!"<<endl;

}

highway::~highway(){

	for(int i=0;i<numofsegments; i++){	
		delete segmentarray[i];
	}
	
	delete[] segmentarray;	
}

void highway::operate(){

	int total=0;
	for (int i=numofsegments-1; i>=0; i--){ // for each segment (in reverse order)
	
		total+=segmentarray[i]->getNumberOfVehicles(); // add its vehicles to sum
		segmentarray[i]->operate(); // operate the segment

	}
	cout<<"->Total number of vehicles in this state is "<<total<<endl;

	
}


int highway::return_vehicles()const{
	int sum=0;

	for(int i=0;i<numofsegments; i++){
		sum+=segmentarray[i]->getNumberOfVehicles();
	}
	
	return sum;

}

Segment* highway::getSegmentByNumber(const int &number)const{
	
	for(int i=0;i<numofsegments; i++){ // for each segment
		if(number==i) return segmentarray[i]; // if this is the one, return it
	}
	return NULL; // invalid number
}
