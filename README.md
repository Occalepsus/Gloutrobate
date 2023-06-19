# Gloutrobate
Gloutrobate is a 2D-platformer in 1v1, with an unique screen. The goal is to eat more cakes or be the last one in the area of the screen.

# Description
The goal of the game is to eat the cakes on the map, by jumping from platforms to others. Be careful, your player should not leave the screen.
To control your player, you have to use the arrows or the QZDS inputs. You can move left and right and jump.
Pay attention, the other player can push you over the edge.

# Tools used
We worked in C++ with SFML.

# Installing and running the project

# Credits
This project has been created by :
- [Victorine Cassé](https://github.com/tihine)
- [Julien Joly](https://github.com/Occalepsus)
# Licence

## Design patterns utilisés

	- Chain of responsibility
	- Bridge
	- Facade
	- Observer (dans une certaine mesure, pour la gestion des événements SFML)
	- Iterator (beaucoup de vectors sont utilisés)

##Game programming patterns
	- Game Loop (le jeu tourne sans attendre les inputs user)
	- State (for the jump)