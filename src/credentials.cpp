/***
 * Brian Hession -- April 14, 2012
 *
 * Credentials class
 *
 */

#include "credentials.h"
#include <fstream>


Credentials::Credentials()
:
	// Initializations
	super( "Credentials" ),
	cred_table( 2, 3, true ),
	user_label( "Username", Gtk::ALIGN_START ),
	pass_label( "Password", Gtk::ALIGN_START ),
	relog_button( "_Relog", true )
{	
	// Add everything
	pass_entry.set_visibility( false );
	cred_table.attach( user_label, 0, 1, 0, 1 );
	cred_table.attach( user_entry, 1, 3, 0, 1 );
	cred_table.attach( pass_label, 0, 1, 1, 2 );
	cred_table.attach( pass_entry, 1, 3, 1, 2 );
	relog_button.set_size_request( 85, 5 );
	m_HBox.pack_end( relog_button, Gtk::PACK_SHRINK );
	m_VBox.set_border_width( 5 );
	m_VBox.pack_start( cred_table, Gtk::PACK_SHRINK );
	m_VBox.pack_start( m_HBox, Gtk::PACK_SHRINK );
	
	// Signal Handlers
	relog_button.signal_clicked().connect( sigc::mem_fun( *this,
			&Credentials::on_relog ) );
	
	// Add to self
	add( m_VBox );
}

Credentials::~Credentials() {}

void Credentials::savecredentials() {

	// Get fields
	Glib::ustring user = user_entry.get_text();
	Glib::ustring pass = pass_entry.get_text();
	
	// Check for error
	if( user.length() <= 0 || pass.length() <= 0 ) {
		error->setlabel( "Invalid username or password" );
		error_message();
		return;
	}
	
	// Open file
	std::ofstream credfile( "etc/.cred" );
	credfile << user << std::endl << pass << std::endl;
	credfile.close();
}

Credentials::Cred Credentials::getcredentials() {

	// Get fields
	Cred c;
	c.user = user_entry.get_text();
	c.pass = pass_entry.get_text();
	
	return c;
}

void Credentials::setfields( Gtk::Window* w, Error* e ) {

	parent = w;
	error = e;
}

void Credentials::on_relog() {

	// Save credentials
	savecredentials();
}

void Credentials::error_message() {

	// Set fields and block parent
	error->setfields( parent );
	parent->set_sensitive( false );
	
	// Get parent location
	int x, y;
	parent->get_position( x, y );
	error->move( x + 45, y + 100 );
	
	// Show error
	error->show();
}

