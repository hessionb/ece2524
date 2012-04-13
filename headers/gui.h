/***
 * Brian Hession -- April 13, 2012
 *
 * GUI Header.
 * GUI extends Window in the GTK package
 *
 */

#ifndef GUI_H
#define GUI_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

// Create class GUI extending Gtk::Window
class GUI : public Gtk::Window {

	public:
		GUI();
		virtual ~GUI();				// Virtual is "proper"

	protected:							// Notice how it is "protected"
		// Signal handlers
		void on_button_clicked();

		// Widgets
		Gtk::VBox m_VBox;				// Vertical box
		Gtk::Label m_Label;			// Label
		Gtk::Button m_button;		// Button
};

#endif
