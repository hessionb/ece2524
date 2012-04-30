/***
 * Brian Hession -- April 14, 2012
 *
 * TreeView class to add/drop classes
 *
 */

#include "tree.h"
#include <fstream>
#include <cstdio>


Tree::Tree() {

	// Initializing everything
	char DIR[256] = "ABSDIR";
	
	sprintf( course_file, "%s/etc/.courses", DIR );
	sprintf( course_temp, "%s/etc/.courses.tmp", DIR );

	m_refTreeModel = Gtk::ListStore::create( m_Columns );
	set_model( m_refTreeModel );
	
	append_column( "CRN", m_Columns.m_col_crn );
	append_column( "Term", m_Columns.m_col_term );
	append_column( "Year", m_Columns.m_col_year );
	append_column( "Subject", m_Columns.m_col_subj );
	append_column( "CRSE", m_Columns.m_col_crse );
	
	loadfromfile();
}

Tree::~Tree() {}

void Tree::loadfromfile() {

	// Read from text file
	std::ifstream coursefile( course_file );
	if( coursefile.is_open() ) {
		while( true ) {
			Tree::Course c;
			coursefile >> c.crn >> c.term >> c.year >> c.subj >> c.crse;
			if( coursefile.eof() ) break;
			courses.push_back( c ); // Populate vector
			addtotree( c ); // Populate tree
		}
		coursefile.close();
	}
}

void Tree::addtotree( Tree::Course& course ) {

	// Add class to tree
	row = *(m_refTreeModel->append());
	row[m_Columns.m_col_crn]  = course.crn;
	row[m_Columns.m_col_term] = course.term;
	row[m_Columns.m_col_year] = course.year;
	row[m_Columns.m_col_subj] = course.subj;
	row[m_Columns.m_col_crse] = course.crse;
}

void Tree::addclass( Tree::Course& course ) {

	// Add class to text file
	std::ofstream coursefile( course_file, 
			std::fstream::out | std::fstream::app );
	if( coursefile.is_open() ) {
		coursefile << course.crn << " "
					  << course.term << " "
					  << course.year << " "
					  << course.subj << " "
					  << course.crse << std::endl;
		coursefile.close();
	}
	addtotree( course );
}

void Tree::deleteclass() {

	Gtk::TreeModel::iterator iter = get_selection()->get_selected();
	if( *iter ) {
	
		Glib::ustring str = (*iter)[m_Columns.m_col_crn];
		std::ifstream coursefile( course_file );
		std::ofstream tempfile( course_temp );
		if( coursefile.is_open() && tempfile.is_open() ) {
			while( true ) {
				char buf[10], line[256];
				coursefile >> buf; // Get crn
				coursefile.getline( line, 255 ); // Get rest of line
				if( coursefile.eof() ) break;
				if( str.compare( buf ) == 0 ) // Skip if crns are equal
					continue;
				tempfile << buf << line << std::endl; // Write to temp
			}
			coursefile.close();
			tempfile.close();
			std::remove( course_file ); // Remove and rename file
			std::rename( course_temp, course_file );
		}
		m_refTreeModel->erase( iter ); // Erase from tree
	}
}

