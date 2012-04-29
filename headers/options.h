/***
 * Brian Hession -- April 14, 2012
 *
 * Options class
 *
 */

#include <gtkmm/frame.h>
#include <gtkmm/table.h>
#include <gtkmm/label.h>
#include <gtkmm/comboboxtext.h>


class Options : public Gtk::Frame {

	public:
		Options();
		virtual ~Options();
		
		unsigned int getselection();
		void setselection( unsigned int d );
	
	protected:
		typedef Gtk::Frame super;
		
		Gtk::Table opt_table;
		Gtk::Label occurance_label;
		Gtk::ComboBoxText select_time;
};

