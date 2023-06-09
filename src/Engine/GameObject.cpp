#pragma once

#include "GameObject.h"

using namespace gloutobate;

GameObject::GameObject(sf::Texture const& texture) : GameObject(sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ (float)texture.getSize().x, (float)texture.getSize().y }, texture) {};

GameObject::GameObject(sf::Vector2f const& pos, sf::Vector2f const& size, sf::Texture const& texture) : pos{ pos }, size{ size }, texture{ texture } {}

sf::Vector2f gloutobate::GameObject::getPosition() const {
	return pos;
}
void GameObject::setPosition(sf::Vector2f p) {
	pos = p;
}
void gloutobate::GameObject::setPosition(float x, float y) {
	pos = sf::Vector2f{ x, y };
}

void GameObject::move(sf::Vector2f p) {
	pos += p;
}

sf::Vector2f gloutobate::GameObject::getSize() const {
	return size;
}
void GameObject::setSize(sf::Vector2f s) {
	size = s;
}

sf::Texture GameObject::getTexture() const {
	return texture;
}

b2Body* gloutobate::GameObject::getBody() const {
	return body;
}
void gloutobate::GameObject::setBody(b2Body* b) {
	body = b;
}
