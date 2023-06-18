#include "Player.h"

void Player::start() {
    setEventCallback(sf::Event::EventType::KeyPressed, [*this](sf::Event e) { onKeyPressed(e); });
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        getBody()->SetLinearVelocity(b2Vec2(-0.1f, getBody()->GetLinearVelocity().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        getBody()->SetLinearVelocity(b2Vec2(0.1f, getBody()->GetLinearVelocity().y));
    }
}

void Player::onKeyPressed(sf::Event e) const {
    if (e.key.code == sf::Keyboard::Up || e.key.code == sf::Keyboard::Z) {
        getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, 0.005f), true);
    }
    if (e.key.code == sf::Keyboard::Down || e.key.code == sf::Keyboard::S) {
        getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -0.005f), true);
    }
}