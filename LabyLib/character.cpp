#include "character.h"

#include <cmath>
#include <limits>

Character::Character(
	std::pair<int, int> xy, 
	int health_points, 
	int attack, 
	int defence, 
	const std::string& name) :
		xy_(xy),
		health_points_(health_points),
		attack_(attack),
		defence_(defence),
		name_(name) {}

void Character::Attack(Character& enemy) const
{
	// TODO: Complete me!
	if (Distance(enemy) == 1.0f)
		enemy.SetHealthPoints(std::min(enemy.GetHealthPoints() - attack_ + enemy.GetDefence(), enemy.GetHealthPoints()));
}

bool Character::IsDead() const
{
	// TODO: Complete me!
	if (GetHealthPoints() <= 0)
	{
		return true;
	}
	return false;
	
}

float Character::Distance(const Character& character) const
{
	// TODO: Complete me!

	int x1 = xy_.first;
	int x2 = character.GetPosition().first;
	int y1 = xy_.second;
	int y2 = character.GetPosition().second;
	float d = std::sqrt(std::pow(x1 - x2, 2.0) + std::pow(y1 - y2, 2.0));
	
	return d;
}
