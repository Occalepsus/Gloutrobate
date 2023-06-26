#pragma once

#include <string_view>
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
		sf::Sprite _sprite;
		b2Body* _body{ nullptr };

		std::string_view _tag{ "GameObject" };

	public:
		GameObject() = delete;
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

		sf::Sprite getSprite() const;

		b2Body* getBody() const;
		void setBody(b2Body* physicBodyPtr);

		// TODO: Fix inactive objects still being triggered by collisions
		void setActive(bool active);
		bool isActive() const;

		void setTag(std::string_view const& tag);
		std::string_view getTag() const;
	};
}