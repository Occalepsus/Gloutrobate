#include "Platform.h"

sf::Texture Platform::getPlatformTexture() {
	sf::Texture texture_platform;
	if (!texture_platform.loadFromFile("./resources/platform.png")) {
		exit(1);
	}
	return texture_platform;
}
