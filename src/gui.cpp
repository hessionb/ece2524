/***
 * Brian Hession -- April 13, 2012
 *
 * GUI Implementation
 * Just read the comments in the code to figure
 * everything out.
 *
 */

#include "gui.h"

int clicks = 0; // Global variable counting clicks

GUI::GUI()
:
	// Defines widgets in constructor
	m_VBox( false, 5 ),
	m_Label( "This is an Example" ),
	m_button("Press")
{
	set_title( "Example" );
	set_border_width( 10 );

	// When the button receives the "clicked" signal, it will call
	// the on_button_clicked() method defined below.
	m_button.signal_clicked().connect(sigc::mem_fun(*this,
		        &GUI::on_button_clicked));

	// Pack widgets into vertically aligned box
	m_VBox.pack_start( m_Label, Gtk::PACK_SHRINK );
	m_VBox.pack_start( m_button, Gtk::PACK_SHRINK );

	// Add the VBox to the window
	add(m_VBox);

	// The final step is to display all the widgets
	show_all_children();
}

GUI::~GUI() {} // Empty destructor

void GUI::on_button_clicked() {
	++clicks;
	char str[20] = "";
	sprintf( str, "Num pressed: %i", clicks );
	m_Label.set_text( str ); // Sets text of Label m_Label
}
