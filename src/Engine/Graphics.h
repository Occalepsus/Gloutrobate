#pragma once

#include <string>
#include <vector>
#include <span>
#include <functional>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

namespace gloutrobate {
	class Graphics {
	private:
		sf::RenderWindow _renderWindow;
		const float _pixelsPerMeter;

		std::vector<sf::Drawable*> _drawables{};

		std::unordered_multimap<sf::Event::EventType, std::function<void(sf::Event)>> _eventCallbacks;

	public:
		Graphics() = delete;
		Graphics(std::string const& name, int width, int height, unsigned int frameLimit, float _pixelsPerMeter = 1000.0f);
		~Graphics() = default;

		template <typename T>
		void setEventCallback(sf::Event::EventType eventType, T const& callback) {
			_eventCallbacks.insert(std::make_pair(eventType, callback));
		}

		bool drawFrame(std::span<std::shared_ptr<GameObject>> const& gameObjects);

		// Should be called before drawFrame, only for texts or other custom drawables
		void addDrawableForOneFrame(sf::Drawable* drawablePtr);
	};
}
