#ifndef MONTH_H_INC
#define MONTH_H_INC

#include <iostream>
#include <cctype>
#include <string>

class Month { 
	private: 
		
		// Private variable
		unsigned short monthNumber;
		
		// Member function to convert string to number
		unsigned short getMonthNumberFromName(std::string name){
			std::string months[12] = {"jan", "feb", "mar", "apr", "may",
			"jun", "jul", "aug", "sep", "oct", "nov", 
			"dec"};
			for(char &s : name) {
				s = static_cast<char>(tolower(static_cast<char>(s)));
			}
			for(unsigned short i= 0;i < 12; i++){
				if(static_cast<std::string>(name.substr(0,3)) == months[i]){
					return static_cast<unsigned short>(i+1);
				}
				else{ 
				}
			}
			return 1;
		}
		
	public: 
		
		// Constructors
		Month(void);
		Month(std::string monthInput);
		Month(unsigned short monthNumber);
		Month(const Month & m);
		
		Month & operator = (const Month &) = default;
		
		// Getters and Setters
		unsigned short get_month(void);
		void set_month(unsigned short monthInput);
		void set_month(std::string monthInput);
	
		// Input and Output
		void output(void);
		void input(void);
	
		// Methods to traverse months
		inline void advance(unsigned short months);
		void before(std::string monthInput);
		inline void before(unsigned short months);
		
		// Comparison of months
		inline bool same(const Month & other) const;
		
};

#endif