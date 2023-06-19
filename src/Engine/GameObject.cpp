#pragma once

#include "GameObject.h"

gloutrobate::GameObject::GameObject(sf::Texture const& texture) : GameObject(sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ (float)texture.getSize().x, (float)texture.getSize().y }, texture) {};

gloutrobate::GameObject::GameObject(sf::Vector2f const& _pos, sf::Vector2f const& size, sf::Texture const& texture) : _pos{ _pos }, _size{ size }, _texture{ texture } {}

void gloutrobate::GameObject::handleEvent(sf::Event const& event) {
	if (_eventCallbacks.contains(event.type)) {
		_eventCallbacks[event.type](event);
	}
}

void gloutrobate::GameObject::updatePositionFromPhysics() {
	if (_body != nullptr) {
		_pos.x = _body->GetPosition().x - _size.x / 2;
		_pos.y = _body->GetPosition().y + _size.y / 2;
	}
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

sf::Texture const& gloutrobate::GameObject::getTexture() const {
	return _texture;
}

b2Body* gloutrobate::GameObject::getBody() const {
	return _body;
}
void gloutrobate::GameObject::setBody(b2Body* b) {
	_body = b;
}
