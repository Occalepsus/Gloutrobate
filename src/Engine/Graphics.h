#pragma once

#include <string>
#include <vector>
#include <span>
#include <functional>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

namespace gloutrobate {
	class Graphics {
	private:
		sf::RenderWindow _renderWindow;
		const float _pixelsPerMeter;

		std::vector<sf::Drawable*> _drawables{};

	public:
		Graphics() = delete;
		Graphics(std::string const& name, int width, int height, unsigned int frameLimit, float _pixelsPerMeter = 1000.0f);
		~Graphics() = default;

		bool drawFrame(std::span<GameObject*> const& gameObjects);

		// Should be called before drawFrame, only for texts or other custom drawables
		void addDrawableForOneFrame(sf::Drawable* drawablePtr);
	};
}
