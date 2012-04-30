/***
 * Brian Hession -- April 14, 2012
 *
 * Credentials class
 *
 */

#include <gtkmm/frame.h>
#include <gtkmm/table.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <glibmm/ustring.h>

#include "error.h"


class Credentials : public Gtk::Frame {

	public:
		Credentials();
		virtual ~Credentials();
		
		// Credentials struct
		struct Cred {
			Glib::ustring user;
			Glib::ustring pass;
		};
		
		void savecredentials();
		Cred getcredentials();
		void setfields( Gtk::Window* w, Error* e );
		void set_text( Cred c );
	
	protected:
		typedef Gtk::Frame super;
		
		// Signal handling
		void on_relog();
		void error_message();
		
		// Formatting
		Gtk::Table cred_table;
		Gtk::HBox m_HBox;
		Gtk::VBox m_VBox;
		
		// Widgets
		Gtk::Label user_label, pass_label;
		Gtk::Entry user_entry, pass_entry;
		
		// Error handling
		Gtk::Window* parent;
		Error* error;
		
		char cred_file[256];
};

