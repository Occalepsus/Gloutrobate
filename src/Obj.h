#include <string>

class Obj {
private : 
	Obj(std::string const& label, double x, double y, std::string const& color);
	// TODO: what is that SFML_output?
	//void draw(SFML_output& out, double x, double y);
};