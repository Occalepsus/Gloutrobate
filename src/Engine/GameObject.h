#pragma once

#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"

namespace gloutrobate {
	class GameObject {
	private:
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::Texture const texture;
		b2Body* body{ nullptr };

	public:
		GameObject() = default;
		explicit GameObject(sf::Texture const& gameObjectTexture);
		GameObject(sf::Vector2f const& initialPosition, sf::Vector2f const& size, sf::Texture const& gameObjectTexture);

		sf::Vector2f getPosition() const;
		void setPosition(sf::Vector2f newPosition);
		void setPosition(float newX, float newY);

		sf::Vector2f getSize() const;
		void setSize(sf::Vector2f newSize);

		sf::Texture const& getTexture() const;

		b2Body* getBody() const;
		void setBody(b2Body* physicBodyPtr);
	};
}