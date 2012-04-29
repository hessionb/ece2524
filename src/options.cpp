/***
 * Brian Hession -- April 14, 2012
 *
 * Options class
 *
 */

#include "options.h"
#include <fstream>


Options::Options()
:
	// Initializations
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
	select_time.set_active( 3 ); // Select 5 min
	
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

void Options::setselection( unsigned int d ) {

	int row;
	switch( d ) {
		case 30:
			row = 0;
			break;
		case 60:
			row = 1;
			break;
		case 120:
			row = 2;
			break;
		case 300:
			row = 3;
			break;
		case 600:
			row = 4;
			break;
		case 900:
			row = 5;
			break;
		case 1800:
			row = 6;
			break;
		case 3600:
			row = 7;
			break;
		default:
			row = 3;
			{
				std::ofstream ofile( "etc/.config" );
				if( ofile.is_open() ) {
					ofile << 300 << std::endl;
					ofile.close();
				}
			}
			break;
	}
	select_time.set_active( row );
}

