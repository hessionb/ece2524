/***
 * Brian Hession -- April 14, 2012
 *
 * Tree class extending Tree/View to 
 * add/drop classes
 *
 */

#ifndef TREE_H
#define TREE_H

#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include <glibmm/ustring.h>
#include <vector>

 
class Tree : public Gtk::TreeView {

	public:
		Tree();
		virtual ~Tree();
		
		struct Course {
			Glib::ustring crn;
			Glib::ustring term;
			Glib::ustring year;
			Glib::ustring subj;
			Glib::ustring crse;
		};
		
		virtual void addclass( Course& course );
		virtual void deleteclass();
		
	protected:
		void addtotree( Course& course );
		void loadfromfile();
		
		// Column format
		class ModelColumns : public Gtk::TreeModel::ColumnRecord {
		
			public:
				ModelColumns() {
					add(m_col_crn);
					add(m_col_term);
					add(m_col_year);
					add(m_col_subj);
					add(m_col_crse);
				}
				
				Gtk::TreeModelColumn<Glib::ustring> m_col_crn;
				Gtk::TreeModelColumn<Glib::ustring> m_col_term;
				Gtk::TreeModelColumn<Glib::ustring> m_col_year;
				Gtk::TreeModelColumn<Glib::ustring> m_col_subj;
				Gtk::TreeModelColumn<Glib::ustring> m_col_crse;
		};
		ModelColumns m_Columns;
		
		// List Store
		Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
		Gtk::TreeModel::Row row;
		
		// Course handlers
		std::vector<Course> courses;
		
		char course_file[256];
		char course_temp[256];
};

#endif

