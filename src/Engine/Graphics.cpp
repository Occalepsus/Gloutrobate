#include "Graphics.h"

gloutrobate::Graphics::Graphics(std::string const& name, int width, int height, unsigned int frameLimit, float _pixelsPerMeter) : _renderWindow{ sf::VideoMode(width, height), name, sf::Style::Titlebar | sf::Style::Close }, _pixelsPerMeter{ _pixelsPerMeter } {
	_renderWindow.setFramerateLimit(frameLimit);
	_renderWindow.setKeyRepeatEnabled(false);
}

bool gloutrobate::Graphics::drawFrame(std::span<std::shared_ptr<GameObject>> const& gameObjects) {
	_renderWindow.clear();
	
	sf::Event rwEvent;
	while (_renderWindow.pollEvent(rwEvent))
	{
		if (rwEvent.type == sf::Event::Closed) {
			_renderWindow.close();
			return false;
		}
		else {
			for (auto it = _eventCallbacks.find(rwEvent.type); it != _eventCallbacks.end(); ++it) {
				it->second(rwEvent);
			}
		}
	}

	for (auto const& gameObject : gameObjects) {
		if (gameObject->isActive()) {
			// TODO: change that
			sf::Sprite sprite;
			sprite.setTexture(gameObject->getTexture());
			sf::Vector2f spriteSize{
				gameObject->getSize().x* _pixelsPerMeter / (float)gameObject->getTexture().getSize().x,
					gameObject->getSize().y* _pixelsPerMeter / (float)gameObject->getTexture().getSize().y
			};
			sprite.setScale(spriteSize);
			sprite.setOrigin(spriteSize / 2.0f);
			sprite.setPosition(gameObject->getPosition().x * _pixelsPerMeter, static_cast<float>(_renderWindow.getSize().y) - gameObject->getPosition().y * _pixelsPerMeter);

			_renderWindow.draw(sprite);
		}
	}
	for (auto const& drawable : _drawables) {
		_renderWindow.draw(*drawable);
	}
	_renderWindow.display();

	_drawables.clear();
	return _renderWindow.isOpen();
}

void gloutrobate::Graphics::addDrawableForOneFrame(sf::Drawable* drawable) {
	_drawables.push_back(drawable);
}
