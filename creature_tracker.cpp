#include "creature_tracker.h"

CreatureTracker::CreatureTracker()
{
}

CreatureTracker::~CreatureTracker()
{
}

void CreatureTracker::add_creature(const std::string &name, const std::string &type, int power)
{
}

void CreatureTracker::remove_creature(const std::string &name)
{
}

bool CreatureTracker::creature_exists(const std::string &name)
{
    return false;
}

Creature *CreatureTracker::get_creature(const std::string &name)
{
    return nullptr;
}

int CreatureTracker::type_count(const std::string &type)
{
    return 0;
}

int CreatureTracker::type_power(const std::string &type)
{
    return 0;
}

CreatureTypeStats *CreatureTracker::get_stats(const std::string &type)
{
    return nullptr;
}

void CreatureTracker::clear()
{
}

void CreatureTracker::print(std::ostream &os) const
{
}


// ///////////////////////////overloaded operators///////////////////////////

std::ostream& operator<<(std::ostream& out, const CreatureTracker& tracker){
    
}