#pragma once

#include <string>
#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

namespace gloutrobate {
	class Graphics {
	private:
		sf::RenderWindow renderWindow;
		float pixelsPerMeter;

		std::vector<sf::Drawable*> drawables{};

		Graphics();

	public:
		Graphics(std::string const& name, int width, int height, unsigned int frameLimit, float pixelsPerMeter = 1000.0f);
		~Graphics() = default;

		bool drawFrame(std::vector<GameObject*> const& gameObjects, std::function<void(sf::Event)> const& eventHandler);

		// Should be called before drawFrame, only for texts or other custom drawables
		void addDrawableForOneFrame(sf::Drawable* drawablePtr);
	};
}
