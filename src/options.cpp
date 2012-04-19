/***
 * Brian Hession -- April 14, 2012
 *
 * Options class
 *
 */

#include "options.h"
#include <iostream>


Options::Options()
:
	super( "Options" ),
	opt_table( 1, 3, true ),
	occurance_label( "Check every", Gtk::ALIGN_START )
{
	// Format combo box
	select_time.append( "30 Sec" );
	select_time.append( "1 Min" );
	select_time.append( "2 Min" );
	select_time.append( "5 Min" );
	select_time.append( "10 Min" );
	select_time.append( "15 Min" );
	select_time.append( "30 Min" );
	select_time.append( "1 Hour" );
	select_time.set_active_text( "5 Min" ); // Select 5 min
	
	// Add to table
	opt_table.set_border_width( 5 );
	opt_table.attach( occurance_label, 0, 1, 0, 1 );
	opt_table.attach( select_time, 2, 3, 0, 1 );
	
	// Add to frame
	add( opt_table );
}

Options::~Options() {}

unsigned int Options::getselection() {

	int row = select_time.get_active_row_number();
	int time;
	switch( row ) {
		case 0:
			time = 30;
			break;
		case 1:
			time = 60;
			break;
		case 2:
			time = 120;
			break;
		case 3:
			time = 300;
			break;
		case 4:
			time = 600;
			break;
		case 5:
			time = 900;
			break;
		case 6:
			time = 1800;
			break;
		case 7:
			time = 3600;
			break;
		default:
			time = 300;
			break;
	}
	
	return time;
}

