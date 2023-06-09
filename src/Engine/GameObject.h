#pragma once

#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"

namespace gloutobate {
	class GameObject {
	private:
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::Texture const texture;
		b2Body* body{ nullptr };

	public:
		GameObject() = default;
		explicit GameObject(sf::Texture const&);
		GameObject(sf::Vector2f const&, sf::Vector2f const&, sf::Texture const&);

		sf::Vector2f getPosition() const;
		void setPosition(sf::Vector2f);
		void setPosition(float x, float y);

		void move(sf::Vector2f);

		sf::Vector2f getSize() const;
		void setSize(sf::Vector2f);

		sf::Texture const& getTexture() const;

		b2Body* getBody() const;
		void setBody(b2Body*);
	};
}