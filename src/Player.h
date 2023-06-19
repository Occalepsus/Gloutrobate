#include <SFML/Graphics.hpp>

#include "Engine/GameObject.h"

class Player : public gloutrobate::GameObject {
private:
	sf::Keyboard::Key _upKey;
	sf::Keyboard::Key _downKey;
	sf::Keyboard::Key _leftKey;
	sf::Keyboard::Key _rightKey;

public:
	using GameObject::GameObject;

	void setKeys(sf::Keyboard::Key upKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key downKey, sf::Keyboard::Key rightKey);

	void start() override;
	void update() override;

	virtual void onKeyPressed(sf::Event e) const;
};
