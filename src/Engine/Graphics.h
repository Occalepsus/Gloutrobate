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
		Graphics(std::string const& name, int width, int height, float pixelsPerMeter = 100.0f) : renderWindow{ sf::VideoMode(width, height), name }, pixelsPerMeter{ pixelsPerMeter } {}
		~Graphics() = default;

		bool drawFrame(std::function<void(sf::Event)> const&);

		void addGameObject(gloutobate::GameObject*);

		// Should be called before drawFrame, only for texts or other custom drawables
		void addDrawableForOneFrame(sf::Drawable*);
	};
}
