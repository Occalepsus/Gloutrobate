#include "Player.h"

void Player::start() {
    setEventCallback(sf::Event::EventType::KeyPressed, [*this](sf::Event e) { onKeyPressed(e); });
    getBody()->SetLinearDamping(1);
}

void Player::setKeys(sf::Keyboard::Key upKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key downKey, sf::Keyboard::Key rightKey) {
    _upKey = upKey;
    _downKey = downKey;
    _leftKey = leftKey;
    _rightKey = rightKey;
}

void Player::update() {
    if (std::abs(getBody()->GetLinearVelocity().x) < 6) {
        if (sf::Keyboard::isKeyPressed(_leftKey)) {
            getBody()->ApplyLinearImpulseToCenter(b2Vec2(-0.5, 0), true);
        }
        if (sf::Keyboard::isKeyPressed(_rightKey)) {
            getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.5, 0), true);
        }
    }
}

void Player::onKeyPressed(sf::Event e) const {
    if (e.key.code == _upKey) {
        getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, 16), true);
    }
}