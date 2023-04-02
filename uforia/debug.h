#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <chrono>

// Print debug messages
void debug(std::string s, bool b = true){
	if(bool b){
		std::cout << "\033[37m" << s << "\033[0m" << std::endl;
	}else{
		std::cout << "\033[31m" << s << "\033[0m" << std::endl;	
	}
}

// Start the timer
void timer_start(){
	extern auto start = std::chrono::high_resolution_clock::now();
}

// Ends the timer
void timer_end(){
	extern auto end = std::chrono::high_resolution_clock::now();
}

// Prints the time duration
void timer_print(){
	std::chrono::duration<double, std::milli> elapsed = end - start; 
	std::string s = "\033[37mElapsed Time: " + to_string(elapsed.count()) + " seconds\033[0m"; 
	std::cout << s << std::endl;
}
#endif // DEBUG_H
