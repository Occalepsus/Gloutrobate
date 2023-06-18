#include "Graphics.h"

gloutrobate::Graphics::Graphics(std::string const& name, int width, int height, unsigned int frameLimit, float pixelsPerMeter) : renderWindow{ sf::VideoMode(width, height), name, sf::Style::Titlebar | sf::Style::Close }, pixelsPerMeter{ pixelsPerMeter } {
	renderWindow.setFramerateLimit(frameLimit);
	renderWindow.setKeyRepeatEnabled(false);
}

bool gloutrobate::Graphics::drawFrame(std::span<GameObject*> const& gameObjects, std::function<void(sf::Event)> const& eventHandler) {
	renderWindow.clear();

	sf::Event rwEvent;
	while (renderWindow.pollEvent(rwEvent))
	{
		if (rwEvent.type == sf::Event::Closed) {
			renderWindow.close();
			return false;
		}
		else {
			eventHandler(rwEvent);
		}
	}

	for (auto const& gameObject : gameObjects) {
		sf::Sprite sprite;
		sprite.setTexture(gameObject->getTexture());
		sf::Vector2f spriteSize{
			gameObject->getSize().x * pixelsPerMeter / (float)gameObject->getTexture().getSize().x,
			gameObject->getSize().y * pixelsPerMeter / (float)gameObject->getTexture().getSize().y
		};
		sprite.setScale(spriteSize);
		sprite.setOrigin(spriteSize / 2.0f);
		sprite.setPosition(gameObject->getPosition().x * pixelsPerMeter, static_cast<float>(renderWindow.getSize().y) - gameObject->getPosition().y * pixelsPerMeter);

		renderWindow.draw(sprite);
	}
	for (auto const& drawable : drawables) {
		renderWindow.draw(*drawable);
	}
	renderWindow.display();

	drawables.clear();
	return renderWindow.isOpen();
}

void gloutrobate::Graphics::addDrawableForOneFrame(sf::Drawable* drawable) {
	drawables.push_back(drawable);
}
