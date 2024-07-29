#include "creature_type_stats.h"

CreatureTypeStats::CreatureTypeStats()
{
    type = "";
    count = 0;
    total_power = 0;
}

CreatureTypeStats::CreatureTypeStats(const std::string &new_type)
{
    type = new_type;
    count = 0;
    total_power = 0;
}

CreatureTypeStats::~CreatureTypeStats()
{
    type = "";
    count = 0;
    total_power = 0;
}

const std::string &CreatureTypeStats::get_key() const
{
    return type;
}

int CreatureTypeStats::get_count() const
{
    return count;
}

int CreatureTypeStats::get_total_power() const
{
    return total_power;
}

void CreatureTypeStats::increment_count()
{
    count++;
}

void CreatureTypeStats::decrement_count()
{
    count--;
}

void CreatureTypeStats::add_power(int power)
{
    total_power += power;
}

void CreatureTypeStats::subtract_power(int power)
{
    total_power -= power;
}

///////////////////////////////overloaded operators///////////////////////////////

std::ostream &operator<<(std::ostream &os, const CreatureTypeStats &c)
{
    // TODO: Implement this function
}

bool operator==(const CreatureTypeStats &c1, const CreatureTypeStats &c2)
{

    // TODO: Implement this function
}

bool operator<(const CreatureTypeStats &c1, const CreatureTypeStats &c2)
{
    // TODO: Implement this function
}

bool operator>(const CreatureTypeStats &c1, const CreatureTypeStats &c2)
{
    // TODO: Implement this function
}