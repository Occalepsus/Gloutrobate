#include "TestPlayer.h"

void TestPlayer::start() {
    auto f = [&](sf::Event e) {
        if (e.key.code == sf::Keyboard::A) {
            i++;
            deltas.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - timer));
            timer = std::chrono::steady_clock::now();
        }
    };
    setEventCallback(sf::Event::EventType::KeyPressed, f);
}

void TestPlayer::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        getBody()->SetLinearVelocity(b2Vec2(-0.1f, getBody()->GetLinearVelocity().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        getBody()->SetLinearVelocity(b2Vec2(0.1f, getBody()->GetLinearVelocity().y));
    }
}
