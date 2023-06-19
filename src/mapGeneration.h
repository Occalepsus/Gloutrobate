#include <iostream>
#include <string>
#include <random>
#include "Engine/Engine.h"
#include <array>

typedef std::vector<gloutrobate::GameObject> list_platforms;

class Map {
private : 
	list_platforms list;

public : 
	list_platforms generation(int selection);
};