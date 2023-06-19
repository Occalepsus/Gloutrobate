#include "PlayerContact.h"

void PlayerContact::BeginContact(b2Contact* contact) {
	// Contact with player 1
	if (contact->GetFixtureA()->GetBody() == getPlayer1()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureB()->GetBody() == p->getBody()) {
				this->getPlayer1()->resetJump();
				return false;
			}
			return true;
			});
		std::ranges::for_each(cakes.begin(), cakes.end(), [&contact, this](std::shared_ptr<Cake> const& c) {
			if (contact->GetFixtureB()->GetBody() == c->getBody()) {
				c->eat();
				this->getPlayer1()->incrScore();
				return false;
			}
			return true;
			});
	}
	if (contact->GetFixtureB()->GetBody() == getPlayer1()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureA()->GetBody() == p->getBody()) {
				this->getPlayer1()->resetJump();
				return false;
			}
			return true;
			});
		std::ranges::for_each(cakes.begin(), cakes.end(), [&contact, this](std::shared_ptr<Cake> const& c) {
			if (contact->GetFixtureA()->GetBody() == c->getBody()) {
				c->eat();
				this->getPlayer1()->incrScore();
				return false;
			}
			return true;
			});
	}
	// Contact with player 2
	if (contact->GetFixtureA()->GetBody() == getPlayer2()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureB()->GetBody() == p->getBody()) {
				this->getPlayer2()->resetJump();
				return false;
			}
			return true;
			});
		std::ranges::for_each(cakes.begin(), cakes.end(), [&contact, this](std::shared_ptr<Cake> const& c) {
			if (contact->GetFixtureB()->GetBody() == c->getBody()) {
				c->eat();
				this->getPlayer2()->incrScore();
				return false;
			}
			return true;
			});
	}
	if (contact->GetFixtureB()->GetBody() == getPlayer2()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureA()->GetBody() == p->getBody()) {
				this->getPlayer2()->resetJump();
				return false;
			}
			return true;
			});
		std::ranges::for_each(cakes.begin(), cakes.end(), [&contact, this](std::shared_ptr<Cake> const& c) {
			if (contact->GetFixtureA()->GetBody() == c->getBody()) {
				c->eat();
				this->getPlayer2()->incrScore();
				return false;
			}
			return true;
			});
	}
}

void PlayerContact::EndContact(b2Contact* contact) {
	// Contact with player 1
	if (contact->GetFixtureA()->GetBody() == getPlayer1()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureB()->GetBody() == p->getBody()) {
				this->getPlayer1()->resetJump(false);
				return false;
			}
			return true;
			});
	}
	if (contact->GetFixtureB()->GetBody() == getPlayer1()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureA()->GetBody() == p->getBody()) {
				this->getPlayer1()->resetJump(false);
				return false;
			}
			return true;
			});
	}
	// Contact with player 2
	if (contact->GetFixtureA()->GetBody() == getPlayer2()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureB()->GetBody() == p->getBody()) {
				this->getPlayer2()->resetJump(false);
				return false;
			}
			return true;
			});
	}
	if (contact->GetFixtureB()->GetBody() == getPlayer2()->getBody()) {
		std::ranges::for_each(platforms.begin(), platforms.end(), [&contact, this](std::shared_ptr<Platform> const& p) {
			if (contact->GetFixtureA()->GetBody() == p->getBody()) {
				this->getPlayer2()->resetJump(false);
				return false;
			}
			return true;
			});
	}
	
}