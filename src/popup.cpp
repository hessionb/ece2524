/***
 * Brian Hession, Erik Wenkel, James Miller
 *
 * Implementation for Popup
 *
 */

#include <iostream>
#include "popup.h"


Popup::Popup()
:
	// Initializations
	class_table( 5, 3, true ),
	crn_label("CRN", Gtk::ALIGN_START),
	term_label("Term", Gtk::ALIGN_START),
	year_label("Year", Gtk::ALIGN_START),
	subj_label("Subject", Gtk::ALIGN_START),
	crse_label("CRSE", Gtk::ALIGN_START),
	apply_button( "_Add Class", true ),
	close_button( "_Close", true ),
	year_adj(Gtk::Adjustment::create
			(2012.0,2012.0,2100.0,1.0,5.0,0.0)),
	year_spin(year_adj)
{
	// Window properties
	set_title("Pick Class");
	set_size_request( 100, 100 );
	set_resizable( false );
	set_border_width( 5 );
	set_keep_above( true );
	set_decorated( false );
	
	// Term combo
	term_combo.set_id_column( 0 );
	term_combo.append( "Spring" );
	term_combo.append( "Fall" );
	term_combo.set_active( 0 );
	
	// Year spin button
	year_spin.set_wrap();	
	
	// Subject entry completion box
	Glib::RefPtr<Gtk::EntryCompletion> completion = 
			Gtk::EntryCompletion::create();
	subj_entry.set_completion( completion );
	
	Glib::RefPtr<Gtk::ListStore> refCompletionModel =
			Gtk::ListStore::create( m_columns );
	completion->set_model( refCompletionModel );
	
	// Adding all possible values
	Gtk::TreeModel::Row row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AAEC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ACIS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AEE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AFST";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AHRM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AINS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ALHR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ALS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AOE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "APS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "APSC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ARBC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ARCH";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ART";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ASPT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "AT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BCHM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BIOL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BIT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BMES";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BMSP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BMVS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BSE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BTDM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "BUS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "C21S";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CEE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CHE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CHEM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CHN";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CINE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CLA";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CNST";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "COMM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "COS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "CSES";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "DASC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ECE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ECON";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDCI";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDCO";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDCT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDEL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDEP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDHE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDHP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDIT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDRE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "EDTE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ENGE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ENGL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ENGR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ENSC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ENT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ESM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "FA";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "FIN";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "FIW";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "FL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "FOR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "FR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "FST";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "GBCB";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "GEOG";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "GEOS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "GER";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "GIA";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "GR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "GRAD";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "HD";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "HEB";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "HIST";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "HNFE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "HORT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "HTM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "HUM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "IDS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "IDST";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "IS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ISE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ISEP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ITAL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ITDS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "JPN";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "JUD";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "LAHS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "LAR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "LAT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "LDRS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MACR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MASC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MATH";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "ME";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MGT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MINE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MKTG";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MN";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MSE";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "MUS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "NR";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "NSEG";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "NSEP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PAPA";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PHIL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PHS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PHYS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PORT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "POUL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PPWS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PSCI";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PSVP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "PSYC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "REL";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "RUS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "SBIO";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "SOC";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "SPAN";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "SPIA";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "STAT";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "STS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "TA";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "UAP";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "UCCS";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "UH";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "UNIV";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "VM";
	row = *(refCompletionModel->append());
	row[m_columns.m_col_name] = "WS";
	
	completion->set_text_column(m_columns.m_col_name);
	
	// Set up table
	crn_entry.set_max_length( 5 );
	crse_entry.set_max_length( 4 );
	class_table.set_border_width( 5 );
	class_table.attach( crn_label, 0, 1, 0, 1 );
	class_table.attach( term_label, 0, 1, 1, 2 );
	class_table.attach( year_label, 0, 1, 2, 3 );
	class_table.attach( subj_label, 0, 1, 3, 4 );
	class_table.attach( crse_label, 0, 1, 4, 5 );
	class_table.attach( crn_entry, 1, 3, 0, 1 );
	class_table.attach( term_combo, 2, 3, 1, 2 );
	class_table.attach( year_spin, 2, 3, 2, 3 );
	class_table.attach( subj_entry, 1, 3, 3, 4 );
	class_table.attach( crse_entry, 1, 3, 4, 5 );
	
	// Pack closing buttons
	close_button.set_size_request( 85, 5 );
	apply_button.set_size_request( 85, 5 );
	m_HBox.pack_end( close_button, Gtk::PACK_SHRINK );
	m_HBox.pack_end( apply_button, Gtk::PACK_SHRINK );
	
	// Pack into vertical box
	m_VBox.pack_start( class_table, Gtk::PACK_SHRINK );
	m_VBox.pack_start( m_HBox, Gtk::PACK_SHRINK );
	
	// Add to window
	add( m_VBox );
	
	// Signal handling
	close_button.signal_clicked().connect( sigc::mem_fun( *this, 
			&Popup::on_close ) );
	apply_button.signal_clicked().connect( sigc::mem_fun( *this,
			&Popup::on_apply ) );
	
	// Show everything
	show_all_children();
}

// Destructor
Popup::~Popup() {}

// set_tree
void Popup::set_values( Gtk::Window* g, Tree* t, Error* e ) {

	parent = g;
	classlist = t;
	error = e;
}

// Error
void Popup::error_message() {

	error->setfields( this );
	set_sensitive( false );
	
	int x, y;
	get_position( x, y );
	error->move( x + 30, y + 60 );
	
	error->show();
}

// Check if the string is valid length and all numbers
bool isvalid( Glib::ustring s, int len ) {

	if( (int)s.length() != len ) return false;
	for( int i = 0; i < len; ++i )
		if( s[i] < '0' || s[i] > '9' ) return false;
		
	return true;
}

// On apply
void Popup::on_apply() {

	// Take values
	Tree::Course course;
	course.crn = crn_entry.get_text();
	int row = term_combo.get_active_row_number();
	if( row == 1 ) course.term = "09";
	else course.term = "01";
	course.year = year_spin.get_text();
	course.subj = subj_entry.get_text();
	course.crse = crse_entry.get_text();
	
	if(!isvalid(course.crn,5) || !isvalid(course.crse, 4)) {
		error->setlabel( "Invalid Field" );
		error_message();
		return;
	}
	
	// Reset Fields
	crn_entry.delete_text( 0, -1 );
	subj_entry.delete_text( 0, -1 );
	crse_entry.delete_text( 0, -1 );
	term_combo.set_active( 0 );
	year_spin.set_value( 2012 );
	
	// Close window
	classlist->addclass( course );
	parent->set_sensitive( true );
	hide();
}

// On close
void Popup::on_close() {

	// Reset Fields
	crn_entry.delete_text( 0, -1 );
	subj_entry.delete_text( 0, -1 );
	crse_entry.delete_text( 0, -1 );
	term_combo.set_active( 0 );
	year_spin.set_value( 2012 );

	// Close window
	parent->set_sensitive( true );
	hide();
}

