#include "Engine/GameObject.h"

class Player : public gloutrobate::GameObject {
public:
	using GameObject::GameObject;

	void start() override;
	void update() override;

	void onKeyPressed(sf::Event e) const;
};