/***
 * Brian Hession -- April 13, 2012
 *
 * GTK example to build off of.
 *
 */

#include "gui.h"
#include <gtkmm/main.h>


int main( int argc, char *argv[] ) {

	// Do not know what it does but is necessary
	Gtk::Main kit(argc, argv);

	// Declare GUI object gui
	GUI gui;
	
	//Shows the window and returns when it is closed.
	Gtk::Main::run( gui );

  return 0;
}
