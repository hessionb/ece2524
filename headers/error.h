/***
 * Brian Hession, Erik Wenkel, James Miller
 *
 * Error window
 *
 * Error window that pops up when something
 * bad happens.
 *
 */

#ifndef ERROR_H
#define ERROR_H
 
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <glibmm/ustring.h>


class Error : public Gtk::Window {

	public:
		Error();
		virtual ~Error();
		
		void setfields( Gtk::Window* w );
		void setlabel( Glib::ustring s );
		
	protected:
		// Signal handlers
		void on_close();
		
		// Formatting
		Gtk::VBox m_VBox;
		
		// Widgets
		Gtk::Label errorlabel;
		Gtk::Button close_button;
		
		// Parent
		Gtk::Window* parent;
};

#endif
	
