#include <vector>
#include <chrono>

#include "Engine/GameObject.h"

class TestPlayer : public gloutrobate::GameObject {
public:
	int i{ 0 };
	std::list<std::chrono::milliseconds> deltas{};
	std::chrono::steady_clock::time_point timer{ std::chrono::steady_clock::now() };

	using GameObject::GameObject;

	void start() override;
	void update() override;
};