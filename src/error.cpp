/***
 * Brian Hession, Erik Wenkel, James Miller
 *
 * Error popup implementation
 *
 */

#include "error.h"

Error::Error()
:
	// Initializing
	errorlabel( "Error: " ),
	close_button( "_Close", true )
{
	// Window properties
	set_title( "Error Message" );
	set_size_request( 200, 5 );
	set_resizable( false );
	set_border_width( 5 );
	set_keep_above( true );
	set_decorated( false );
	
	m_VBox.pack_start( errorlabel, Gtk::PACK_SHRINK );
	m_VBox.pack_start( close_button, Gtk::PACK_SHRINK );
	
	add( m_VBox );
	
	// Add signal
	close_button.signal_clicked().connect( sigc::mem_fun( *this, 
			&Error::on_close ) );
	
	show_all_children();
}

Error::~Error() {}

void Error::setfields( Gtk::Window* w ) {

	parent = w;
}

void Error::setlabel( Glib::ustring s ) {

	errorlabel.set_text( s );
}

void Error::on_close() {

	parent->set_sensitive( true );
	hide();
}

