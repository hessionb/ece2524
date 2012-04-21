/***
 * Brian Hession, Erik Wenkel, James Miller
 *
 * Popup for adding a class
 *
 */

#ifndef POPUP_H
#define POPUP_H

#include <gtkmm/window.h>
#include <gtkmm/table.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/entrycompletion.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/button.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/liststore.h>
#include <glibmm/ustring.h>

#include "tree.h"
#include "error.h"


class Popup : public Gtk::Window {

	public:
		Popup();
		virtual ~Popup();
		
		void set_values( Gtk::Window* parent, Tree* t, Error* e );

	protected:
		// Signal handlers
		void on_apply();
		void on_close();
		void error_message();
		
		// Entry model
		class ModelColumns : public Gtk::TreeModel::ColumnRecord {
		
			public:
				ModelColumns() {
					add(m_col_name);
				}
				
				Gtk::TreeModelColumn<Glib::ustring> m_col_name;
		} m_columns;
		
		// For entry completion
		typedef std::map<int, Glib::ustring> type_actions_map;
		type_actions_map completion_actions;
		
		// Formatting
		Gtk::Table class_table;
		Gtk::VBox m_VBox;
		Gtk::HBox m_HBox;
		
		// Widgets
		Gtk::Label crn_label, term_label, year_label, 
					  subj_label, crse_label;
		Gtk::Entry crn_entry, subj_entry, crse_entry;
		Gtk::ComboBoxText term_combo;
		Gtk::Button apply_button, close_button;
		Glib::RefPtr<Gtk::Adjustment> year_adj;
		Gtk::SpinButton year_spin;
		
		// Pointers to Parent widgets
		Gtk::Window* parent;
		Tree* classlist;
		Error* error;
};

#endif

