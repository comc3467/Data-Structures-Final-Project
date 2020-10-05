#include <iostream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <fstream>
#include "HashQuad.hpp"
#include "HashQuad.cpp"

using namespace std;

// C++ program to find the execution time of code
int main()
{
	using namespace std::chrono;
	srand (time(NULL));
	ifstream dataA("dataSetA.csv");
	if(!(dataA.is_open())){
		cout << "ERROR" << endl;
	}
	string placeHolder;
	int allValues[40009];
	int index = 0;
	while(dataA.good()){
		getline(dataA, placeHolder, ',');
		int value = stoi(placeHolder);
		allValues[index] = value;
		index++;
	}
	HashTable HT = HashTable();
	for(int i = 0; i < 40009; i++){
		HT.insertItem(allValues[i]);
	}

	int total = 40000;
	
	auto start = steady_clock::now();

	for(int i = 0; i < total; i++){
		HT.searchItem(allValues[i]);
	}

	this_thread::sleep_for (seconds(2));
	sleep(2);

	auto end = steady_clock::now();

	cout << "Elapsed time in nanoseconds : " 
		<< duration_cast<nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds : " 
		<< duration_cast<microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds : " 
		<< duration_cast<milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds : " 
		<< duration_cast<seconds>(end - start).count()
		<< " sec";
	cout<<endl;
	return 0;
}