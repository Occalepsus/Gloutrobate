#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"

namespace gloutrobate {
	class Engine;

	class GameObject {
	private:
		Engine* _enginePtr{ nullptr };
		bool _active{ true };
		sf::Vector2f _pos;
		sf::Vector2f _size;
		sf::Texture const _texture;
		b2Body* _body{ nullptr };

	public:
		GameObject() = default;
		explicit GameObject(sf::Texture const& gameObjectTexture);
		GameObject(sf::Vector2f const& initialPosition, sf::Vector2f const& size, sf::Texture const& gameObjectTexture);
		virtual ~GameObject() = default;

		void setGameEngine(Engine* enginePtr);
		void setEventCallback(sf::Event::EventType eventType, std::function<void(sf::Event)> const& callback);

		void updatePositionFromPhysics();
		virtual void start() { /* Default GameObject does start nothing */ };
		virtual void update() { /* Default GameObject does update nothing */ };

		virtual void onCollisionEnter(GameObject* other, b2Contact* contact) { /* Default GameObject does nothing on collision enter */ };
		virtual void onCollisionExit(GameObject* other, b2Contact* contact) { /* Default GameObject does nothing on collision exit */ };

		sf::Vector2f getPosition() const;
		void setPosition(sf::Vector2f const& newPosition);
		void setPosition(float newX, float newY);

		void move(sf::Vector2f const& dv);
		void move(float dx, float dy);

		sf::Vector2f getSize() const;

		sf::Texture const& getTexture() const;

		b2Body* getBody() const;
		void setBody(b2Body* physicBodyPtr);

		void setActive(bool active);
		bool isActive() const;
	};
}