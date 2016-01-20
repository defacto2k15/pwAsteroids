#ifndef PWASTEROIDS_SCENE_H
#define PWASTEROIDS_SCENE_H

#include <allegro5/allegro.h>
#include <vector>
#include "DrawableObject.h"
/**
 *	Class Scene organises DrawableObjects in one group.
*/
class Scene {
public:
	/**
	 *	Inserts new DrawableObject to the Scene.
	 *	@param x horizontal position on the screen
	 *	@param y vertical position on the screen
	 *	@param path path to the bitmap (default = NULL)
	 *	@param t text (default = NULL)
	 *	@param a angle (default = 0.0f)
	 *	@param z zoom - scale of the bitmap (default = 1.0f)
	 *	@param tx horizontal offset for text (default = 0)
	 *	@param ty vertical offset for text (default = 0)
	 *	@return pointer to the created DrawableObject
	*/
	DrawableObject* addDrawableObject(int x, int y, const char* path = NULL, const char* t = NULL, float a = 0.0f, float z = 1.0f, int tx = 0, int ty = 0);
	/**
	 *	Removes and destroys pointed DrawableObject from the scene.
	 *	@param drawableObject pointer to the object in the class.
	*/
	void removeDrawableObject(DrawableObject *drawableObject);
	/**
	 *	Return vector of pointers to the objects added to scene.
	 *	@return vector of pointers to DrawableObject.
	*/
	std::vector<DrawableObject*> getSceneObjects();
	/**
	 *	Return the number of objects in the scene.
	 *	@return number of objects in the scene.
	*/
	int getNumberOfObjects() { return objects.size(); }
	/**
	 *	Changes the active atribut of the scene (deactivated scenes are not displayed).
	*/
	void changeActiveState();
	/**
	 *	Return the value of active atribut.
	 *	@return active atribut - bool value.
	*/
	bool isActive() { return active; }
	Scene();
	~Scene();
private:
	/**
	 *	Vector of DrawableObjects added to the Screen. 
	*/
	std::vector<DrawableObject*> objects;
	/**
	 *	Tells if Screen is active or not.
	*/
	bool active;
};

#endif