#include "Display.h"

void Display::drawSceneOnDisplay(Scene *scene)
{
	std::vector<DrawableObject*> objectsToDisplay = scene->getSceneObjects();
	if (objectsToDisplay.size() != 0) {
		for (auto object : objectsToDisplay) {
			al_draw_scaled_rotated_bitmap(object->getBitmap(), 0, 0, object->getPozX(), object->getPozY(), 1, 1, object->getAngle(), 0);
		}
	}
	al_flip_display();
}


Display::Display(int width, int height)
{
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

	std::cout << "Allegro created, current working directory: " << al_get_current_directory() << "\n";
}

Display::~Display()
{
	al_destroy_display(display);
	std::cout << "Allegro display destroyed\n";
}


