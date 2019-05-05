# Attica Highway Simulation
A simulation of Attica Highway(one direction)

## Compilation:
	
	$ g++ -o virtualHighway ./client.cpp ./highway.cpp ./segment.cpp ./entrance.cpp ./toll.cpp ./car.cpp
 
## Run:

	$ ./virtualHighway <N> <Nsegs> <K>

	where:
		<N>		: (int) number of simulation cycles
		<Nsegs>	: (int) number of highway segments
		<K>		: (int) Max number of vehicles that can enter to a node from a toll station
	
	Note: 
		
		For a smooth program run, make sure <N> is at least twice as much as <Nsegs>
