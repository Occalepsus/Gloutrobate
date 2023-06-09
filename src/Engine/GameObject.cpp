#pragma once

#include "GameObject.h"

using namespace gloutobate;

GameObject::GameObject(sf::Texture const& texture) : GameObject(sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ (float)texture.getSize().x, (float)texture.getSize().y }, texture) {};

GameObject::GameObject(sf::Vector2f const& pos, sf::Vector2f const& size, sf::Texture const& texture) : pos{ pos }, size{ size }, texture{ texture } {
	sprite.setTexture(texture);
	sprite.setScale(size.x / (float)texture.getSize().x, size.y / (float)texture.getSize().y);
	sprite.setOrigin(size / 2.0f);
	sprite.setPosition(pos);
}

void GameObject::setPosition(sf::Vector2f p) {
	pos = p;
	sprite.setPosition(pos);
}
void gloutobate::GameObject::setPosition(float x, float y) {
	pos = sf::Vector2f{ x, y };
	sprite.setPosition(pos);
}
sf::Vector2f gloutobate::GameObject::getPosition() const {
	return pos;
}

void GameObject::move(sf::Vector2f p) {
	pos += p;
	sprite.move(p);
}

void GameObject::setSize(sf::Vector2f s) {
	size = s;
	sprite.setScale(s.x / (float)texture.getSize().x, s.y / (float)texture.getSize().y);
}
sf::Vector2f gloutobate::GameObject::getSize() const {
	return size;
}

sf::Sprite GameObject::getSprite() const {
	return sprite;
}