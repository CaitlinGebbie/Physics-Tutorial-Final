#include "Physics.h"

int main() {
	
	// allocation
	auto app = new Physics();

	// initialise and loop
	app->run("Physics Tutorial", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}