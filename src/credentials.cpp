/***
 * Brian Hession -- April 14, 2012
 *
 * Credentials class
 *
 */

#include "credentials.h"

Credentials::Credentials()
:
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
	
	// Add to self
	add( m_VBox );
}

Credentials::~Credentials() {}

