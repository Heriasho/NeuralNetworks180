#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <iomanip>

const int NUM_CASES = 20;

//prototypes
float getRand();
float getAverage(float num[5]);
float getMedian(float num[5]);

int main(){
	
	float num[5];
	
	srand (time(NULL));
	
	ofstream myfile;
	myfile.open("newTesting.dat");
	
	for(int i = 0; i < NUM_CASES; i++){
		
		num[0] = getRand();
		num[1] = getRand();
		num[2] = getRand();
		num[3] = getAverage(num);
		num[4] = getMedian(num);
		
		myfile << setprecision(4) << num[0] << " " << setprecision(4) << num[1] << " " << setprecision(4) << num[2] << " " << setprecision(4) << num[3] << " " << setprecision(4) << num[4] << "\n";

	}
	myfile.close();
	
}

float getRand(){
	
	return -10 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(20)));
}

float getAverage(float num[5]){
	
	float counter = 0;
	
	for(int i = 0; i < 3; i++)
		counter += num[i];
	
	return counter / 3.0;
}

float getMedian(float num[5]){
	
	
	sort(num, num+3);
	
	return num[1];
	
}