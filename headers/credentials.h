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


class Credentials : public Gtk::Frame {

	public:
		Credentials();
		virtual ~Credentials();
	
	protected:
		typedef Gtk::Frame super;
		
		// Formatting
		Gtk::Table cred_table;
		Gtk::HBox m_HBox;
		Gtk::VBox m_VBox;
		
		// Widgets
		Gtk::Label user_label, pass_label;
		Gtk::Entry user_entry, pass_entry;
		Gtk::Button relog_button;
};

