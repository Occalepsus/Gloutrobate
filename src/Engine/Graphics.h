#pragma once

#include <string>
#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

namespace gloutobate {
	class Graphics {
	private:
		sf::RenderWindow renderWindow;
		float pixelsPerMeter;

		std::vector<gloutobate::GameObject*> gameObjects{};
		std::vector<sf::Drawable*> drawables{};

		Graphics();

	public:
		Graphics(std::string const& name, int width, int height, unsigned int frameLimit, float pixelsPerMeter = 100.0f);
		~Graphics() = default;

		bool drawFrame(std::function<void(sf::Event)> const& eventHandler);

		void addGameObject(gloutobate::GameObject* gameObjectPtr);

		// Should be called before drawFrame, only for texts or other custom drawables
		void addDrawableForOneFrame(sf::Drawable* drawablePtr);
	};
}
