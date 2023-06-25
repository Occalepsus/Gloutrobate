#include <gtest/gtest.h>

#include <chrono>
#include <list>
#include <SFML/Graphics.hpp>

#include "Engine/Engine.h"
#include "TestPlayer.h"
#include "Player.h"
#include "Platform.h"
#include "Cake.h"

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
		return true;
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
		return true;
		});

	for (auto const& delta : player->deltas) {
		std::cout << delta << std::endl;
	}
}

TEST(Player, Player_movement) {
	sf::Vector2f initialPosition(0.f, 0.f);
	sf::Texture text{};
	text.loadFromFile("./resources/Player.png");
	Player player(initialPosition,sf::Vector2f(1,1),text);
	sf::Vector2f move(100.f, 0.f);
	player.move(move);
	ASSERT_EQ(player.getPosition(), move);

}

TEST(Player, Players_body_moves) {
	auto game = std::make_unique<Engine>("Test", 800, 600, 60);
	sf::Vector2f initialPosition(0.f, 0.f);
	sf::Vector2f move(100.f, 0.f);
	sf::Texture text{};
	ASSERT_TRUE(text.loadFromFile("./resources/Player.png"));
	auto player = std::make_shared<Player>(initialPosition, sf::Vector2f(1, 1), text);
	game->addGameObject(player, true);
	player->move(move);
	game->start([&player]() {
		std::cout << player->getBody()->GetTransform().p.x << " " << player->getBody()->GetTransform().p.y << "\n";
		});
}

TEST(GameObject, GameObjectCreation) {
	auto game = std::make_unique<Engine>("Test", 800, 600, 60);

	sf::Texture text{};
	ASSERT_TRUE(text.loadFromFile("./resources/Player.png"));
	auto player{ std::make_shared<Player>(sf::Vector2f(0, 2), sf::Vector2f(1, 1), text) };
	player->setKeys(sf::Keyboard::Z, sf::Keyboard::Q, sf::Keyboard::S, sf::Keyboard::D);

	game->addGameObject(player, true);

	std::vector<std::shared_ptr<Platform>> gameObjects{
		std::make_shared<Platform>(sf::Vector2f(0, 0))
	};
	game->addGameObject(gameObjects[0]);

	game->start([]() { return true; });
}