#include "Display.h"

void Display::drawSceneOnDisplay(Scene *scene)
{
	std::vector<DrawableObject*> objectsToDisplay = scene->getSceneObjects();
	for (auto object : objectsToDisplay) {
		al_draw_bitmap(object->getBitmap(), object->getPozX(), object->getPozY(), 0);
	}
	al_flip_display();
}

Display::Display(int width, int height)
{
	//ALLEGRO example for test - works :D
	display = NULL;

	if (!al_init()) {
		throw std::runtime_error("Failed to init Allegro!");
	}

	display = al_create_display(width, height);
	if (!display) {
		throw std::runtime_error("Failed to create display!");
	}

	al_init_image_addon();

	al_clear_to_color(al_map_rgb(255, 120, 0));

	al_flip_display();

	//al_rest(3.0);
}

Display::~Display()
{
	al_destroy_display(display);
	std::cout << "Allegro display destroyed\n";
}


