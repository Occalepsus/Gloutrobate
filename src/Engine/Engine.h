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
		std::function<void()> update;

	public:
		Engine() = delete;
		Engine(std::string const& name, int width, int height, float fps = 60) : graphicEngine{ name, width, height, static_cast<unsigned int>(fps) }, physicEngine{ fps }, millisecondsPerFrame{ static_cast<int>((float)1000 / fps) } {};
		~Engine() = default;

		void addGameObject(gloutobate::GameObject* gameObjectPtr, bool isDynamic = false);
		void drawOnFrame(sf::Drawable* drawablePtr);
		void setUpdate(std::function<void()> const& updateFunc) { update = updateFunc; }

		void start(std::function<void(sf::Event)> const& eventHandler);
	};
}