#include <gtest/gtest.h>

#include <chrono>
#include <array>
#include <list>
#include <numeric>
#include <SFML/Graphics.hpp>

#include "Engine/Engine.h"
#include "TestPlayer.h"
#include "Player.h"
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

	sf::Texture texture{};
	auto player{ std::make_unique<TestPlayer>(texture) };
	game->addGameObject(player.get());

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

TEST(GameEngine, FrameLimiter) {
	const size_t measuresCount{ 50 };

	auto game15 = std::make_unique<Engine>("Test15", 800, 600, 1, 15);
	auto game30 = std::make_unique<Engine>("Test30", 800, 600, 1, 30);
	auto game60 = std::make_unique<Engine>("Test60", 800, 600, 1, 60);
	auto game120 = std::make_unique<Engine>("Test120", 800, 600, 1, 120);

	std::array<long long, measuresCount> measures{};

	int counter{ 0 };

	std::cout << "Starting 15 FPS\n";

	auto timer = std::chrono::steady_clock::now();
	game15->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures[counter] = std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count();
		timer = now;

		return ++counter < measuresCount;
		});

	long long sum{ std::accumulate(measures.begin(), measures.end(), 0) };

	std::cout << "15 FPS measured: " << 1000 * measuresCount / sum << '\n';

	counter = 0;

	std::cout << "Starting 30 FPS\n";

	timer = std::chrono::steady_clock::now();
	game30->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures[counter] = std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count();
		timer = now;

		return ++counter < measuresCount;
		});

	sum = std::accumulate(measures.begin(), measures.end(), 0);

	std::cout << "30 FPS measured: " << 1000 * measuresCount / sum << '\n';

	counter = 0;

	std::cout << "Starting 60 FPS\n";

	timer = std::chrono::steady_clock::now();

	game60->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures[counter] = std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count();
		timer = now;

		return ++counter < measuresCount;
		});

	sum = std::accumulate(measures.begin(), measures.end(), 0);

	std::cout << "60 FPS measured: " << 1000 * measuresCount / sum << '\n';

	counter = 0;

	std::cout << "Starting 120 FPS\n";

	timer = std::chrono::steady_clock::now();

	game120->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures[counter] = std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count();
		timer = now;

		return ++counter < measuresCount;
		});

	sum = std::accumulate(measures.begin(), measures.end(), 0);

	std::cout << "120 FPS measured: " << 1000 * measuresCount / sum << '\n';
}

TEST(GameEngine, FrameLimiterWithPhysics) {
	auto game120 = std::make_unique<Engine>("Test120", 2000, 1000, 60, 120);
	auto game60 = std::make_unique<Engine>("Test60", 2000, 1000, 60, 60);
	auto game30 = std::make_unique<Engine>("Test30", 2000, 1000, 60, 30);
	auto game15 = std::make_unique<Engine>("Test15", 2000, 1000, 60, 15);

	sf::Texture texture{};
	sf::Texture texture2{};
	ASSERT_TRUE(texture.loadFromFile("./resources/Player.png"));
	ASSERT_TRUE(texture2.loadFromFile("./resources/platform.png"));
	auto playerPosInit{ sf::Vector2f(10, 4) };
	auto platformPosInit{ sf::Vector2f(100, 2) };
	auto player{ std::make_unique<Player>(playerPosInit, sf::Vector2f(1, 1.5f), texture) };
	player->setKeys(sf::Keyboard::Z, sf::Keyboard::Q, sf::Keyboard::S, sf::Keyboard::D);
	auto platform{ std::make_unique<GameObject>(platformPosInit, sf::Vector2f(1000, 1), texture2) };

	std::vector<long long> measures{};

	game15->addGameObject(player.get(), true);
	game15->addGameObject(platform.get(), false);

	std::cout << "Starting 15 FPS\n";

	auto timer = std::chrono::steady_clock::now();
	game15->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count());
		timer = now;

		return true;
		});

	long long sum{ std::accumulate(measures.begin(), measures.end(), 0) };

	std::cout << "15 FPS measured: " << 1000 * measures.size() / sum << '\n';

	measures.clear();

	player->setPosition(playerPosInit);
	platform->setPosition(platformPosInit);
	game30->addGameObject(player.get(), true);
	game30->addGameObject(platform.get(), false);

	std::cout << "Starting 30 FPS\n";

	timer = std::chrono::steady_clock::now();
	game30->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count());
		timer = now;

		return true;
		});

	sum = std::accumulate(measures.begin(), measures.end(), 0);

	std::cout << "30 FPS measured: " << 1000 * measures.size() / sum << '\n';

	measures.clear();

	player->setPosition(playerPosInit);
	platform->setPosition(platformPosInit);
	game60->addGameObject(player.get(), true);
	game60->addGameObject(platform.get(), false);

	std::cout << "Starting 60 FPS\n";

	timer = std::chrono::steady_clock::now();

	game60->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count());
		timer = now;

		return true;
		});

	sum = std::accumulate(measures.begin(), measures.end(), 0);

	std::cout << "60 FPS measured: " << 1000 * measures.size() / sum << '\n';

	measures.clear();

	player->setPosition(playerPosInit);
	platform->setPosition(platformPosInit);
	game120->addGameObject(player.get(), true);
	game120->addGameObject(platform.get(), false);

	std::cout << "Starting 120 FPS\n";

	timer = std::chrono::steady_clock::now();

	game120->start([&]() {
		auto now = std::chrono::steady_clock::now();
		measures.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count());
		timer = now;

		return true;
		});

	sum = std::accumulate(measures.begin(), measures.end(), 0);

	std::cout << "120 FPS measured: " << 1000 * measures.size() / sum << '\n';
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
	auto player = std::make_unique<Player>(initialPosition, sf::Vector2f(1, 1), text);
	game->addGameObject(player.get(), true);
	player->move(move);
	game->start([&player]() {
		std::cout << player->getBody()->GetTransform().p.x << " " << player->getBody()->GetTransform().p.y << "\n";
		return true;
		});
}

TEST(GameObject, GameObjectCreation) {
	auto game = std::make_unique<Engine>("Test", 800, 600, 60);

	sf::Texture text{};
	ASSERT_TRUE(text.loadFromFile("./resources/Player.png"));
	auto player{ std::make_unique<Player>(sf::Vector2f(0, 2), sf::Vector2f(1, 1), text) };
	player->setKeys(sf::Keyboard::Z, sf::Keyboard::Q, sf::Keyboard::S, sf::Keyboard::D);

	game->addGameObject(player.get(), true);

	std::unique_ptr<GameObject> gameObjects{
		std::make_unique<GameObject>(sf::Vector2f(0, 0), sf::Vector2f(3, 1), text),
	};
	game->addGameObject(gameObjects.get());

	game->start([]() { return true; });
}