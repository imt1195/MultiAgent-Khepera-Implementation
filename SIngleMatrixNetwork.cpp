// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	double input[6];
	int i;
	
	Network khepera(4,12,2,"Ian_Tobin__Test1.txt");

	khepera.PrintNetworkState();

	khepera.writeNetworkOutputStateToFile("Ian_Tobin_OutputTest1.txt");

	i = 0;
	while (i < 1000) {


		input[0] = input[1] = input[2] = 0.0;			// Set all inputs off
		if (i> 300 && i < 700)	input[0] = 1.0;		// Command jaw close 
		if (i> 600 && i < 800) input[1] = 1.0;		// command LEFT jaw open
		if (i> 650 && i < 850) input[2] = 1.0;		// command RIGHT jaw open
													// Vary duration of command 
													// Get offset to work - correct resting state
													// close and then sensory input
													// approach close, then before it's closed get sensory input to see if it stops



		khepera.setNetworkInput(input);

		khepera.cycleNetwork();
		khepera.printNetworkOutputState();

		khepera.writeNetworkOutputStateToFile("Ian_Tobin_OutputTest1.txt");
		++i;
	}

	return 0;
}