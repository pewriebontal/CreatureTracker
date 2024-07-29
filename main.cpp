/*
* main.cpp
* Written by : SENG1120 Staff (c1234567)
* Modified : 17/05/2024
*
* This file is a simple demonstration of a creature tracker application.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "creature_tracker.h"

/**
 * Tokenise a string,separating by commas ",".
 */ 
std::vector<std::string> tokenise(const std::string& line)
{
	std::vector<std::string> tokens;

    std::istringstream iss(line);
    std::string token;

    while (std::getline(iss, token, ',')) 
    {
        tokens.push_back(token);
    }

    return tokens;
}

/**
 * Populates the creature tracker with the entries from the text file named "creatures.txt"
 */ 
void populate_tracker(CreatureTracker& ct)
{
	std::ifstream infile("creatures.txt");
	std::string line;

	while(std::getline(infile, line))
    {
        //remove the newline character(s) from the line
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.cend());
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.cend());
        
        std::vector<std::string> tokens = tokenise(line);
		if (tokens.size() != 3)
		{
			throw std::runtime_error("Error when reading the creature file.");
		} 

		//line format is name,type,power
		std::string name = tokens[0];
		std::string type = tokens[1];
		int power = std::stoi(tokens[2]); //convert 3rd token to integer

		ct.add_creature(name, type, power);
    }

}

/*
* The main function, which runs a few simple tests on the CreatureTracker object.
*/ 
int main()
{	
	// Construct and populate with initial creature list
	CreatureTracker ct;
	populate_tracker(ct);

	//manipulate std::cout to print booleans as true/false, instead of 1/0.
	std::cout << std::boolalpha; 

	//check creature that exists
	std::cout << "Calling check_exists on creature that exists: " << ct.creature_exists("Swarmstrike") << std::endl << std::endl;

	//check creature that does not exist
	std::cout << "Calling check_exists on creature that does not exist: " << ct.creature_exists("Random") << std::endl << std::endl;

	//get creature that exists
	Creature* c = ct.get_creature("Swarmstrike");
	std::cout << "Retrieving and printing a creature: " << *c << std::endl << std::endl;

	std::vector<std::string> types = {"Fire", "Water", "Electric", "Grass", "Ice", 
									"Fighting", "Poison", "Ground", "Flying", "Psychic", "Bug", 
									"Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy"};

	//loop through each type and print statistics
	std::cout << "Printing statistics for each type:" << std::endl;
	for(std::string& type : types)
	{
		std::cout << "\t" << *ct.get_stats(type) << std::endl;
	}
	std::cout << std::endl;
	
	//remove creature that exists
	ct.remove_creature("Swarmstrike");
	std::cout << "Checking removed creature does not exist: " << ct.creature_exists("Swarmstrike") << std::endl << std::endl;

	std::cout << ct << std::endl;

	//clear the tracker's data
	/*ct.clear();
	c = ct.get_creature("Blazefox");
	std::cout << "Checking creature does not exist after clear (i.e., c is nullptr): " << !c << std::endl << std::endl;
	CreatureTypeStats* ts = ct.get_stats(types[0]);
	std::cout << "Checking creature_type_stats does not exist after clear (i.e., ts is nullptr): " << !ts << std::endl;
	*/
}