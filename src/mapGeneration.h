#pragma once

#include <iostream>
#include <string>
#include <random>
#include "Engine/Engine.h"
#include "Platform.h"
#include <array>

using list_platforms = std::vector<Platform>;

class Map {
private : 
	list_platforms list;

public : 
	list_platforms generation(int selection);
};