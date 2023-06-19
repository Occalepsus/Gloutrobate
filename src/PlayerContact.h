#pragma once

#include <memory>
#include "box2d/box2d.h"

#include "Player.h"
#include "Platform.h"
#include "Cake.h"

#include <iostream>

class PlayerContact : public b2ContactListener {
private:
	std::shared_ptr<Player> _player1;
	std::shared_ptr<Player> _player2;

	std::vector<std::shared_ptr<Platform>> platforms;
	std::vector<std::shared_ptr<Cake>> cakes;

public:
	void setPlayer1(std::shared_ptr<Player> p) { _player1 = p; }
	std::shared_ptr<Player> getPlayer1() { return _player1; }
	void setPlayer2(std::shared_ptr<Player> p) { _player2 = p; }
	std::shared_ptr<Player> getPlayer2() { return _player2; }

	void setPlatforms(std::vector<std::shared_ptr<Platform>> const& p) { platforms = p; }
	std::vector<std::shared_ptr<Platform>> getPlatforms() const { return platforms; }
	void setCakes(std::vector<std::shared_ptr<Cake>> const& c) { cakes = c; }
	std::vector<std::shared_ptr<Cake>> getCakes() const { return cakes; }


	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;
};