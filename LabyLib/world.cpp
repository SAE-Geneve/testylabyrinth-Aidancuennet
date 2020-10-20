#include "world.h"
#include "character.h"
#include "hero.h"
#include "enemy.h"
#include <cassert>
#include <iostream>
#include <limits>
#include <algorithm>

World::World(const std::string& map, int length) : hero_({0, 0})
{
	int i = 0;
	for(auto cell : map)
	{
		std::pair<int, int> pos = { i % length, i / length };
		if (cell == 'P')
		{
			hero_.SetPosition(pos);
			map_[pos] = '.';
		}
		if(cell == 'E')
		{
			Enemy enemy(pos);
			enemies_.push_back(enemy);
			map_[pos] = '.';
		}
		if(cell == '.')
		{
			map_[pos] = '.';
		}
		if(cell == '#')
		{
			map_[pos] = '#';
		}
		i++;
	}
	// TODO: Complete me!
}

void World::EraseDead()
{
	// TODO: Complete me!
	enemies_.erase
	(std::remove_if(
		enemies_.begin(),
		enemies_.end(),
		[](Enemy enemy)
		{	
			return enemy.IsDead();
		}), 
		enemies_.end());
}

bool World::HasEnemies() const
{
	// TODO: Complete me
	return enemies_.size();
}

std::pair<int, int> World::North(const Character& character) const
{
	if (GetTile({ character.GetPosition().first, character.GetPosition().second - 1}) != '.')
	{
		return character.GetPosition();
	}
	return { character.GetPosition().first, character.GetPosition().second - 1 };
	// TODO: Complete me!
}

std::pair<int, int> World::South(const Character& character) const
{
	if (GetTile({ character.GetPosition().first, character.GetPosition().second + 1}) != '.')
	{
		return character.GetPosition();
	}
	return { character.GetPosition().first, character.GetPosition().second + 1 };
	// TODO: Complete me!
}

std::pair<int, int> World::East(const Character& character) const
{
	if (GetTile({ character.GetPosition().first + 1, character.GetPosition().second}) != '.')
	{
		return character.GetPosition();
	}
	return { character.GetPosition().first + 1, character.GetPosition().second };
	// TODO: Complete me!
}

std::pair<int, int> World::West(const Character& character) const
{
	if (GetTile({ character.GetPosition().first - 1, character.GetPosition().second }) != '.')
	{
		return character.GetPosition();
	}
	return { character.GetPosition().first - 1, character.GetPosition().second };
	// TODO: Complete me!
}

void World::HeroAttack()
{
	// TODO: Complete me!
	for (auto& enemy : enemies_)
	{
		hero_.Attack(enemy);
	}
}

void World::ShowMap() const
{
	// Show the maze to the user.
	std::cout << "Maze :\n";
	for (int i = -1; i < 2; ++i)
	{
		std::cout << "\t +---+---+---+\n\t";
		for (int j = -1; j < 2; ++j)
		{
			auto pair = std::pair<int, int>(
				hero_.GetPosition().first + j,
				hero_.GetPosition().second + i);
			std::cout << " | " << GetTile(pair);
		}
		std::cout << " |\n";
	}
	std::cout << "\t +---+---+---+\n\n";
}

void World::ShowHero() const
{
	// Show the player info the user.
	std::cout 
		<< "Player(" 
		<< hero_.GetPosition().first 
		<< ", " 
		<< hero_.GetPosition().second 
		<< ") :\n";
	std::cout << "\tname       : " << hero_.GetName() << "\n";
	std::cout << "\thit points : " << hero_.GetHealthPoints() << "\n";
	std::cout << "\n";
}

void World::ShowEnemies() const
{
	// Show the enemy that are within view of the user.
	for (const auto& enemy : enemies_)
	{
		float dist = enemy.Distance(hero_);
		if (std::abs(dist - 1.0f) < std::numeric_limits<float>::epsilon()) 
		{
			std::cout
				<< "Enemy(" 
				<< enemy.GetPosition().first 
				<< ", " 
				<< enemy.GetPosition().second 
				<< ")\n";
			std::cout << "\tname       : " << enemy.GetName() << "\n";
			std::cout << "\thit points : " << enemy.GetHealthPoints() << "\n";
			std::cout << "\n";
		}
	}
}

void World::EnemyAttack()
{
	// TODO: Complete me!
	for (auto& enemy : enemies_)
	{
		enemy.Attack(hero_);
	}
}

std::pair<int, int> World::CheckPosition(
	std::pair<int, int> begin, 
	std::pair<int, int> end) const
{
	
	// TODO: Complete me!
	return { 0, 0 };
}

char World::GetTile(std::pair<int, int> xy) const
{
	// TODO: Complete me!
	return map_.at(xy);
}
