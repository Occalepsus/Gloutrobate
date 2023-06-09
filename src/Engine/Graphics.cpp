#include "Graphics.h"

using namespace gloutobate;

bool Graphics::drawFrame(std::function<void(sf::Event)> const& eventHandler) {
	renderWindow.clear();

	for (auto const& gameObject : gameObjects) {
		sf::Sprite sprite;
		sprite.setTexture(gameObject->getTexture());
		sf::Vector2f spriteSize{
			gameObject->getSize().x * pixelsPerMeter / (float)gameObject->getTexture().getSize().x,
			gameObject->getSize().y * pixelsPerMeter / (float)gameObject->getTexture().getSize().y
		};
		sprite.setScale(spriteSize);
		sprite.setOrigin(spriteSize / 2.0f);
		sprite.setPosition(gameObject->getPosition() * pixelsPerMeter);

		renderWindow.draw(sprite);
	}
	for (auto const& drawable : drawables) {
		renderWindow.draw(*drawable);
	}
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
	renderWindow.display();

	drawables.clear();
	return renderWindow.isOpen();
}

void gloutobate::Graphics::addGameObject(gloutobate::GameObject* gameObject) {
	gameObjects.push_back(gameObject);
}

void Graphics::addDrawableForOneFrame(sf::Drawable* drawable) {
	drawables.push_back(drawable);
}
