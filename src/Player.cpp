#include "Player.h"

void Player::setKeys(sf::Keyboard::Key upKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key downKey, sf::Keyboard::Key rightKey) {
    _upKey = upKey;
    _downKey = downKey;
    _leftKey = leftKey;
    _rightKey = rightKey;
}

void Player::start() {
    setEventCallback(sf::Event::EventType::KeyPressed, [this](sf::Event e) { onKeyPressed(e); });
    getBody()->SetLinearDamping(1);
    setTag("Player");
}

void Player::update() {
    if (std::abs(getBody()->GetLinearVelocity().x) < 6) {
        if (sf::Keyboard::isKeyPressed(_leftKey)) {
            getBody()->ApplyLinearImpulseToCenter(b2Vec2(-0.4f, 0), true);
        }
        if (sf::Keyboard::isKeyPressed(_rightKey)) {
            getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.4f, 0), true);
        }
    }

    if (getPosition().y < 0 || getPosition().x < -1 || getPosition().x > 33 ) {
        setPosition(_initPos);
        _canJump = true;
        if (_score > 0) {
            _score--;
        }
	}
}

void Player::onCollisionEnter(GameObject* other, b2Contact* contact) {
    if (other->getTag() == "Platform") {
        _canJump = true;
    }
    else if (other->getTag() == "Cake") {
        incrScore();
    }
}

void Player::onCollisionExit(GameObject* other, b2Contact* contact) {
    if (other->getTag() == "Platform") {
		_canJump = false;
	}
}

void Player::onKeyPressed(sf::Event e) {
    if (_canJump && e.key.code == _upKey) {
        getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, 11), true);
        _canJump = false;
    }
}