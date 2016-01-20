#ifndef PWASTEROIDS_VIEWMANAGER_H
#define PWASTEROIDS_VIEWMANAGER_H

#include <Game.h>
#include <vector>
#include "Scene.h"
#include "Screen.h"
#include "Display.h"
#include "Sound/SoundModule.h"
#include <boost/thread/thread.hpp>
#include <string>
#include <Controller/AbstractAllegroEventListener.h>
#include <Controller/GameScreenEventInterpreter.h>
#include <Controller/AllegroEventInterpreter.h>
#include <Controller/MenuScreenEventInterpreter.h>
/**
 *	Frames Per Second
*/
const float FPS = 60;

/**
 *	Organises screens and sound in the game. Also handles Allegro main loop, which fires events.
*/
class ViewManager {
public:
	/**
	 *	Constructor for the ViewManager class.
	 *	@param game reference to the game object
	 *	@param allegroEventListeners vector of pointers to the AbstractAllegroEventListener objects
	 *	@param display display object
	 *	@param screenEventInterpreters vector of pointers to the ScreenEventInterpreter objects
	 *	@param screens vector of pointers to the Screen objects
	 *	@param initialScreen name of the first displayed screen
	 *	@param soundModule reference to the SoundModule object
	*/
	ViewManager(Game &game, std::vector<AbstractAllegroEventListener *> allegroEventListeners,
                    Display *display, std::vector<ScreenEventInterpreter *> screenEventInterpreters,
                    std::vector<Screen *> screens, std::string initialScreen, SoundModule &soundModule);
	/**
	 *	Changes active screen for the other with the given name. Do nothing if other screen doesn't exist.
	 *	@param name title of the other screen
	*/
	void changeActiveScreen(std::string );
	/**
	 *	Calls playSample method from soundModule_ to play the sample with the given name.
	 *	@param sampleName name of the sample
	 *	@param volume volume
	 *	@param playOnce defines if the sample should be played once or continuosly
	*/
	void playSample(std::string sampleName, float volume, bool playOnce = true) { soundModule_.playSample(sampleName, volume, playOnce); }
	/**
	 *	Calls initializeScreenElements method for every screen added to screens. Sets the first screen as the activeScreen.
	*/
	void initializeScreens();
	/**
	 *	Calls updateScreenAfterDisplayChange method for every screen added to screens.
	*/
	void updateScreensAfterDisplayChanges();
	/**
	 * Realizes Allegro loop which fires events.
	*/
	void start();
	/**
	 *	Calls resizeDisplay method from the display setResolution from the game.
	 *	@param newWidth width of the screen after resize
	 *	@param newHeight height of the screen after resize
	*/
	void resizeDisplay( int newWidth, int newHeight );
	/**
	 *	Sets the variable isExit to true, which will finish infinite loop from the start() method.
	*/
	void exit() { isExit = true; }
	/**
	 *	Gives current display.
	 *	@return pointer to display object 
	*/
	Display* getDisplay() { return display; }
	~ViewManager();

private:
	AllegroEventInterpreter allegroEventInterpreter_;
	std::vector<Screen*> screens;
	std::vector<Screen*>::iterator activeScreen, it;
	Display* display;
	SoundModule &soundModule_;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	boost::thread* timerThread;
	bool isExit = false;
	Game &game;
	std::vector<AbstractAllegroEventListener *> eventsListeners_;
	std::vector<ScreenEventInterpreter *> screenEventInterpreters_;
	ScreenEventInterpreter *activeInterpreter;
};

#endif