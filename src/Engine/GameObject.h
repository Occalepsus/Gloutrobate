#pragma once

#include <unordered_map>
#include <functional>
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"

namespace gloutrobate {
	class GameObject {
	private:
		sf::Vector2f _pos;
		sf::Vector2f _size;
		sf::Texture const _texture;
		b2Body* _body{ nullptr };

		std::unordered_map<sf::Event::EventType, std::function<void(sf::Event)>> _eventCallbacks;

	public:
		GameObject() = default;
		explicit GameObject(sf::Texture const& gameObjectTexture);
		GameObject(sf::Vector2f const& initialPosition, sf::Vector2f const& size, sf::Texture const& gameObjectTexture);
		virtual ~GameObject() = default;

		template <typename T>
		void setEventCallback(sf::Event::EventType eventType, T callback) {
			_eventCallbacks[eventType] = callback;
		}
		void handleEvent(sf::Event const& event);

		void updatePositionFromPhysics();
		virtual void start() { /* Default GameObject does start nothing */ };
		virtual void update() { /* Default GameObject does update nothing */ };

		sf::Vector2f getPosition() const;
		void setPosition(sf::Vector2f const& newPosition);
		void setPosition(float newX, float newY);

		void move(sf::Vector2f const& dv);
		void move(float dx, float dy);

		sf::Vector2f getSize() const;

		sf::Texture const& getTexture() const;

		b2Body* getBody() const;
		void setBody(b2Body* physicBodyPtr);
	};
}