#pragma once

#include "GameObject.h"
#include "Engine.h"

gloutrobate::GameObject::GameObject(sf::Texture const& texture) : GameObject(sf::Vector2f(), sf::Vector2f{ texture.getSize() }, texture) {};

gloutrobate::GameObject::GameObject(sf::Vector2f const& pos, sf::Vector2f const& size, sf::Texture const& texture) : _pos{ pos }, _size{ size }, _sprite{ texture } {
	_sprite.setOrigin(size.x / 2, size.y / 2);
	_sprite.setPosition(pos);
	_sprite.setScale(
		size.x / (float)texture.getSize().x,
		size.y / (float)texture.getSize().y
	);
}

void gloutrobate::GameObject::setGameEngine(Engine* enginePtr) {
	_enginePtr = enginePtr;
}

void gloutrobate::GameObject::setEventCallback(sf::Event::EventType eventType, std::function<void(sf::Event)> const& callback) {
	_enginePtr->setEventCallback(eventType, callback);
}

void gloutrobate::GameObject::updatePositionFromPhysics() {
	if (_body != nullptr) {
		_pos.x = _body->GetPosition().x - _size.x / 2;
		_pos.y = _body->GetPosition().y + _size.y / 2;
	}
	_sprite.setPosition(_pos);
}

sf::Vector2f gloutrobate::GameObject::getPosition() const {
	return _pos;
}
void gloutrobate::GameObject::setPosition(sf::Vector2f const& p) {
	setPosition(p.x, p.y);
}
void gloutrobate::GameObject::setPosition(float x, float y) {
	_pos = sf::Vector2f{ x, y };
	
	if (_body != nullptr) {
		_body->SetTransform(b2Vec2{ x + _size.x / 2, y - _size.y / 2 }, _body->GetAngle());
	}
}

void gloutrobate::GameObject::move(sf::Vector2f const& dv) {
	setPosition(_pos + dv);
}
void gloutrobate::GameObject::move(float dx, float dy) {
	setPosition(_pos.x + dx, _pos.y + dy);
}

sf::Vector2f gloutrobate::GameObject::getSize() const {
	return _size;
}

sf::Sprite gloutrobate::GameObject::getSprite() const {
	return _sprite;
}

b2Body* gloutrobate::GameObject::getBody() const {
	return _body;
}
void gloutrobate::GameObject::setBody(b2Body* b) {
	_body = b;
	_body->GetUserData().pointer = std::bit_cast<uintptr_t>(this);
}

void gloutrobate::GameObject::setActive(bool active) {
	this->_active = active;
	_body->SetAwake(active);
}
bool gloutrobate::GameObject::isActive() const {
	return _active;
}
