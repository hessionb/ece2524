/***
 * Brian Hession -- April 13, 2012
 *
 * GUI Header.
 * GUI extends Window in the GTK package
 *
 */

#ifndef GUI_H
#define GUI_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/notebook.h>
#include <gtkmm/scrolledwindow.h>
#include <glibmm/ustring.h>
#include <vector>

#include "tree.h"
#include "credentials.h"
#include "options.h"
#include "popup.h"
#include "error.h"


// Create class GUI extending Gtk::Window
class GUI : public Gtk::Window {

	public:
		GUI();
		virtual ~GUI();				// Virtual is "proper"

	protected:							// Notice how it is "protected"
		// Signal handlers
		void deleteclass();
		void popupwindow();
		void on_apply();

		// Formatting
		Gtk::Notebook notebook;
		Gtk::VBox m_VBox;
		Gtk::HBox m_HBox1;
		
		// Credentials
		Credentials cred;
		
		// Options
		Options options;
		
		// First page formatting
		Gtk::VBox firstpage;
		
		// First page widgets
		Gtk::Button apply_button, close_button;
		
		// Second page formatting
		Gtk::VBox secondpage;
		Gtk::HBox m_HBox2;
		
		// Scrolled window
		Gtk::ScrolledWindow m_ScrolledWindow;
		
		// Class list
		Tree classtree;
		
		// Second page widgets
		Gtk::Button add_button, remove_button;
		
		// Test
		Popup popup;
		
		// Error
		Error error;
		
		
		/****************************************************
		* Credentials and Classes / Main functions, etc
		****************************************************/
		Credentials::Cred c;
		std::vector<Tree::Course> courses;
		unsigned int delay;
		
		void loadcredentials();
		void loadoptions();
		
		char cred_file[256];
		char opt_file[256];
		/****************************************************
		*****************************************************/
};

#endif
