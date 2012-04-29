/***
 * Brian Hession -- April 13, 2012
 *
 * GUI Implementation
 * Just read the comments in the code to figure
 * everything out.
 *
 */

#include "gui.h"
#include <fstream>


GUI::GUI()
:
	// Defines widgets in constructor
	apply_button( "_Apply", true ),
	close_button( "_Close", true ),
	add_button( "A_dd Class", true ),
	remove_button( "Re_move Class", true )
{
	// Format window
	set_title( "Class Catcher" );
	set_resizable( false );
	set_size_request( 295, 300 );
	set_border_width( 5 );
	
	// TreeView
	m_ScrolledWindow.set_policy( Gtk::POLICY_AUTOMATIC,
			Gtk::POLICY_AUTOMATIC );
	m_ScrolledWindow.add( classtree );
	add_button.set_size_request( 85, 5 );
	remove_button.set_size_request( 85, 5 );
	m_HBox2.pack_end( remove_button, Gtk::PACK_SHRINK );
	m_HBox2.pack_end( add_button, Gtk::PACK_SHRINK );
	secondpage.set_border_width( 5 );
	secondpage.pack_start( m_ScrolledWindow, 
			Gtk::PACK_EXPAND_WIDGET );
	secondpage.pack_start( m_HBox2, Gtk::PACK_SHRINK );
	
	// Notebook
	cred.setfields( this, &error );
	firstpage.set_border_width( 5 );
	firstpage.pack_start( cred, Gtk::PACK_SHRINK );
	firstpage.pack_start( options, Gtk::PACK_SHRINK );
	notebook.append_page( firstpage, "General" );
	notebook.append_page( secondpage, "Classes" );
	
	// Apply and Close button
	close_button.set_size_request( 85, 5 );
	apply_button.set_size_request( 85, 5 );
	m_HBox1.pack_end( close_button, Gtk::PACK_SHRINK );
	m_HBox1.pack_end( apply_button, Gtk::PACK_SHRINK );
	
	// Pack notebook and closing into final frame
	m_VBox.pack_start( notebook, Gtk::PACK_EXPAND_WIDGET );
	m_VBox.pack_start( m_HBox1, Gtk::PACK_SHRINK );
	
	// Signal handling
	close_button.signal_clicked().connect( sigc::mem_fun( *this, 
			&GUI::hide ) );
	remove_button.signal_clicked().connect( sigc::mem_fun( *this,
			&GUI::deleteclass ) );
	add_button.signal_clicked().connect( sigc::mem_fun( *this,
			&GUI::popupwindow ) );
	apply_button.signal_clicked().connect( sigc::mem_fun( *this,
			&GUI::on_apply ) );
			
	// Load file
	loadcredentials();
	loadoptions();
	
	// Add to window
	add( m_VBox );

	// Show everything
	show_all_children();
}

GUI::~GUI() {} // Empty destructor

// Delete class
void GUI::deleteclass() {
	
	// Deletes selected class
	classtree.deleteclass();
}

// Make window popup
void GUI::popupwindow() {

	// Make window popup
	popup.set_values( this, &classtree, &error );
	int x, y;
	get_position( x, y );
	popup.move( x + 15, y + 50 );
	set_sensitive( false );
	popup.show();
}

// When apply button is pressed
void GUI::on_apply() {

	cred.savecredentials();
	c = cred.getcredentials();
	delay = options.getselection();
	
	std::ofstream ofile( "etc/.config" );
	if( ofile.is_open() ) {
		ofile << delay << std::endl;
		ofile.close();
	}
	
	hide();
}

void GUI::loadcredentials() {

	// Open file and read
	std::ifstream credfile( "etc/.cred" );
	if( credfile.is_open() ) {
		credfile >> c.user >> c.pass;
		credfile.close();
		cred.set_text( c );
	}
}

void GUI::loadoptions() {

	// Open file and read
	std::ifstream ifile( "etc/.config" );
	if( ifile.is_open() ) {
		ifile >> delay;
		ifile.close();
		options.setselection( delay );
	}
}

