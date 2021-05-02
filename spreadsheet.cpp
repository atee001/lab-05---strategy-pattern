#include "spreadsheet.hpp"
#include "select.hpp"

#include <algorithm>
#include <iostream>

Spreadsheet::~Spreadsheet()
{
    delete select;
}

void Spreadsheet::set_selection(Select* new_select)
{
    delete select;
    select = new_select;
}

void Spreadsheet::clear()
{
    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names)
{
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const
{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    return -1;
}


void print_selection(ostream& out) const){
	

	if(select == nullptr){

	for(auto it : data){
	
		for(auto jt : it){

			out << jt << " ";


		}
		
		out << '\n';


	}	
	
	}
	
	else{



}

}

	
class Select_Contains : public Select_Column{

private:

  string str;

public:

  Select_Contains(const Spreadsheet* sheet, const string& name, const string& str){

    column = sheet->get_column_by_name(name);

    this->str = str;

  }

  bool select(const Spreadsheet* sheet, const string& s){

    if(column == -1) return false;

    for(auto it : sheet->data){ //rows

      for(auto jt : it->data.at(column)){ //column

        if(jt.find(s) != std::string::npos) return true;

      }

      return false;

    }

  }


};

}	

}	







}
