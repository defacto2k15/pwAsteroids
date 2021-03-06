#include "Display.h"

void Display::drawSceneOnDisplay(Scene *scene)
{
	std::vector<DrawableObject*> objectsToDisplay = scene->getSceneObjects();
	if (objectsToDisplay.size() != 0) {
		for (auto object : objectsToDisplay) {
			if(object->getBitmap() != NULL) {
				al_draw_tinted_scaled_rotated_bitmap(object->getBitmap(), al_map_rgb(object->getTintR(), object->getTintG(), object->getTintB()), 0, 0,
					object->getPozX(), object->getPozY(), object->getZoom(), object->getZoom(), object->getAngle(), 0);
			}
			al_draw_text(font, al_map_rgb(255, 255, 255), object->getPozX()+object->getTextX(), object->getPozY()+object->getTextY(), 0,
							(object->getText()).c_str());
		}
	}
}

void Display::clearDisplay(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) al_clear_to_color(al_map_rgb(255, 255, 255));
	else al_clear_to_color(al_map_rgb(r, g, b));
}

void Display::resizeDisplay(int width, int height)
{
	al_resize_display(display, width, height);
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

	if (!al_install_keyboard()) {
		throw std::runtime_error("Failed to install keyboard!");
	}

	if (!al_install_mouse()) {
		throw std::runtime_error("Failed to install mouse!");
	}

	al_init_font_addon();
	al_init_ttf_addon();
	if (!(font = al_load_ttf_font("../res/arial.ttf", 20, 0))) {
		throw std::runtime_error("Failed to load font!");
	}
	
	al_init_image_addon();
	ALLEGRO_BITMAP* icon = al_load_bitmap("../res/pwAsteroids.bmp");
	if (!icon) std::cout << "Failed to load icon: \"../res/pwAsteroids.bmp\"\n";
	else al_set_display_icon(display, icon);

	al_clear_to_color(al_map_rgb(40, 120, 120));

	std::cout << "Allegro created, current working directory: " << al_get_current_directory() << "\n";
}

Display::~Display()
{
	al_destroy_display(display);
	std::cout << "Allegro display destroyed\n";
}


