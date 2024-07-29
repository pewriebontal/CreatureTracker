#include "creature.h"

Creature::Creature()
{
    name = "";
    type = "";
    power = 0;
}

Creature::Creature(const std::string& name, const std::string& type, int power)
{
   // TODO: implement this function
}

Creature::~Creature(){

}

const std::string& Creature::get_key() const
{
    return name;
}

const std::string& Creature::get_type() const
{
    return type;
}


int Creature::get_power() const
{
    return power;
}

///////////////////////////overloaded operators///////////////////////////

std::ostream& operator << (std::ostream& os, const Creature& c){

}

bool operator == (const Creature& c1, const Creature& c2){

}

bool operator < (const Creature& c1, const Creature& c2){

}

bool operator > (const Creature& c1, const Creature& c2){
    
}