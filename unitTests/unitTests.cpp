#include <gtest/gtest.h>

#include <chrono>
#include <list>
#include <SFML/Graphics.hpp>

#include "Engine/Engine.h"
#include "TestPlayer.h"

using namespace gloutrobate;

TEST(GameEngine, KeyPressFromKeyBoard) {
	std::list<std::chrono::milliseconds> deltas{};
	auto timer = std::chrono::steady_clock::now();

	auto game = std::make_unique<Engine>("Test", 800, 600, 60);

	uint32_t i{ 0 };
	sf::Font font{};
	ASSERT_TRUE(font.loadFromFile("./resources/ARIAL.TTF"));

	sf::Text text{};
	text.setFont(font);
	text.setPosition(100, 100);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Blue);

	std::string str{ "Press A. Count: " };
	game->start([&i, &deltas, &timer, &game, &str, &text]() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			i++;
			deltas.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - timer));
			timer = std::chrono::steady_clock::now();
		}
		std::string temp{ str };
		temp.append(std::to_string(i));
		text.setString(temp);
		game->drawOnFrame(&text);
	});

	for (auto const& delta : deltas) {
		std::cout << delta << std::endl;
	}
}

TEST(GameEngine, KeyPressFromKeyEvent) {
	auto game = std::make_unique<Engine>("Test", 800, 600, 60);

	auto player{ std::make_shared<TestPlayer>() };
	game->addGameObject(player);

	sf::Font font{};
	ASSERT_TRUE(font.loadFromFile("./resources/ARIAL.TTF"));

	sf::Text text{};
	text.setFont(font);
	text.setPosition(100, 100);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Blue);

	std::string str{ "Press A. Count: " };
	
	game->start([&game, &str, &text, &player]() {
		std::string temp{ str };
		temp.append(std::to_string(player->i));
		text.setString(temp);
		game->drawOnFrame(&text);
		});

	for (auto const& delta : player->deltas) {
		std::cout << delta << std::endl;
	}
}

