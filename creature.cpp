#include "creature.h"

#pragma region Constructors
Creature::Creature()
{
	name = "";
	type = "";
	power = 0;
}

Creature::Creature(const std::string& name, const std::string& type, int power)
	: name(name)
	, type(type)
	, power(power)
{ }

Creature::~Creature()
{
	name = "";
	type = "";
	power = 0;
}

#pragma endregion

#pragma region Accessors

const std::string& Creature::get_key() const
{
	return (name);
}

const std::string& Creature::get_type() const
{
	return (type);
}

int Creature::get_power() const
{
	return (power);
}

#pragma endregion

#pragma region Operator Overloads

std::ostream& operator<<(std::ostream& os, const Creature& c)
{
	os << "(" << c.get_key() << ", " << c.get_type() << ", " << c.get_power() << ")";
	return (os);
}

bool operator==(const Creature& c1, const Creature& c2)
{
	return (c1.get_key() == c2.get_key());
}

bool operator<(const Creature& c1, const Creature& c2)
{
	return (c1.get_key() < c2.get_key());
}

bool operator>(const Creature& c1, const Creature& c2)
{
	return (c1.get_key() > c2.get_key());
}

#pragma endregion