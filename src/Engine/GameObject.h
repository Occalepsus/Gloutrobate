#pragma once

#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"

namespace gloutobate {
	class GameObject {
	private:
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::Sprite sprite{};
		sf::Texture texture;

	public:
		GameObject() = default;
		explicit GameObject(sf::Texture const&);
		GameObject(sf::Vector2f const&, sf::Vector2f const&, sf::Texture const&);

		void setPosition(sf::Vector2f);
		void setPosition(float x, float y);
		sf::Vector2f getPosition() const;

		void move(sf::Vector2f);

		void setSize(sf::Vector2f);
		sf::Vector2f getSize() const;

		sf::Sprite getSprite() const;
	};
}