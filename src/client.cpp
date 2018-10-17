#include <iostream>
#include "highway.h"
using namespace std;

int N;

int main(int args, char* argv[]){

	if (args!=4){
		cout<<"Error: Expected arguments N, NSegs, K."<<endl;
		exit(1);
	}else{
	
		::N=atoi(argv[1]);
		int Nsegs=atoi(argv[2]);
		int K=atoi(argv[3]);
	
		while (::N<2*Nsegs){
			cout<<"For realistic results, please enter a value for N which is at least twice as Nsegs: "<<endl;
			cin>>::N;
		}
	
	
		highway attikiOdos(Nsegs, K);
		
		for (int i=0; i<N; i++){
			cout<<"\n->Simulation cycle "<<i+1<<":"<<endl;
			attikiOdos.operate();
		}
		
	}
	exit(0);
}
	
