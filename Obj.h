
class Obj {
private : 
	Obj(std::string const& label, double x, double y, std::string const& color);
	void draw(SFML_output& out, double x, double y);
};