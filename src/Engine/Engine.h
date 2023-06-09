#pragma once

#include <string>
#include <thread>
#include <functional>
#include <chrono>

#include <SFML/Graphics.hpp>

#include "Graphics.h"
#include "Physics.h"

namespace gloutobate {
	class Engine {
	private:
		Graphics graphicEngine;
		Physics physicEngine{};
		std::chrono::milliseconds millisecondsPerFrame;
		std::jthread gameThread{};
		std::function<void(sf::Event)> update;

	public:
		Engine() = delete;
		Engine(std::string const& name, int width, int height, float fps = 60) : graphicEngine{ name, width, height }, physicEngine{ fps }, millisecondsPerFrame{ static_cast<int>((float)1000 / fps) } {};

		void addGameObject(gloutobate::GameObject*, bool = false);
		void drawOnFrame(sf::Drawable*);
		void setUpdate(std::function<void(sf::Event)> const& updateFunc) { update = updateFunc; }

		void start();
	};
}