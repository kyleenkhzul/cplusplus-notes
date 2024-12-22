#ifndef INPUT_PROT_H_INC
#define INPUT_PROT_H_INC

#include <iostream>
#include <string>
#include <ios>

template < typename InputT >
void input_protect(InputT & lower, InputT & upper, const std::string & lowerPrompt, 
	const std::string & upperPrompt, const std::string & error) { 
	
	std::cout << "Validating bounds...\n";
	
	while(lower > upper) {
		std::cerr << error;
		std::cout << lowerPrompt;
		std::cin >> lower;
	}
	while(upper < lower) {
		std::cerr << error;
		std::cout << upperPrompt;
		std::cin >> upper;
	}
	
	std::cout << "Your lower bound is " << lower << " and your upper bound is " 
		<< upper << "\n";
	}
	
template < typename InputT >
void getLowerBound(InputT & oldLowerBound, InputT & newLowerBound, 
	const std::string & promptLower, const std::string & error) {

	std::cout << "Validating lower bounds...\n";

	while(newLowerBound > oldLowerBound) {
		std::cerr << error;
		std::cout << promptLower;
		std::cin >> newLowerBound;
	}
	
	std::cout << "Your new lower bound is now " << newLowerBound << "\n";
}
	
template <typename InputT>
void getUpperBound(InputT & oldUpperBound, InputT & newUpperBound, 
	const std::string & promptUpper, const std::string & error) {
		
	std::cout << "Validating upper bounds...\n";
	
	while(newUpperBound < oldUpperBound) {
		std::cerr << error;
		std::cout << promptUpper;
		std::cin >> newUpperBound;
	}
	
	std::cout << "Your new upper bound is now " << newUpperBound << "\n";
}

template <typename InputT>
void input_protect(InputT & value, const std::string & prompt, const std::string & errormsg, 
	const std::initializer_list<InputT> & myList) {
	
	bool valueFound = false;
	std::cout << "Validating choice...\n";
	
	while(!valueFound) {
		for(auto i = myList.begin(); i != myList.end(); ++i) {
			if(*i == value) {
				std::cout << "Value found! \n";
				valueFound = true;
				break;
			}
		}
		if(!valueFound) {
		std::cout << errormsg;
		std::cout << prompt;
		std::cin >> value;
		}
	}
	std::cout << value;
}

#endif
