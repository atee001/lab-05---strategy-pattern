#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <cstring>

class Select
{
public:
    virtual ~Select() = default;

    // Return true if the specified row should be selected.
    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

// A common type of criterion for selection is to perform a comparison based on
// the contents of one column.  This class contains contains the logic needed
// for dealing with columns. Note that this class is also an abstract base
// class, derived from Select.  It introduces a new select function (taking just
// a string) and implements the original interface in terms of this.  Derived
// classes need only implement the new select function.  You may choose to
// derive from Select or Select_Column at your convenience.
class Select_Column: public Select
{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* sheet, const std::string& name)
    {
        column = sheet->get_column_by_name(name);
    }

    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        return select(sheet->cell_data(row, column));
    }

    // Derived classes can instead implement this simpler interface.
    virtual bool select(const std::string& s) const = 0;
};


#endif //__SELECT_HPP


class Select_Contains : public Select_Column{

private:

  string str;

public:

  Select_Contains(const Spreadsheet* sheet, const string& name, const string& str){

    column = sheet->get_column_by_name(name);

    this->str = str;

  }

  bool select(const Spreadsheet* sheet, const string& s){
	
	return column != -1 && (sheet->cell_data(row, column)).find(str) != std::string::npos;
  }


};



class Select_And: public Select {
	
	private:
		Select* l;
		Select* r;

	public:

		~Select_And() {
			delete l;
			delete r;
		}

		Select_And(Select* left, Select* right) {
			l = left;
			r = right;
		}

		bool select(const Spreadsheet* sheet, int row) const {
			if(l->select(sheet, row) && r->select(sheet, row)) {
				return true;
			}
			else {
				return false;
			}
		}

};

class Select_Or: public Select {
	
	private:
		Select* l;
		Select* r;

	public: 
		~Select_Or() {
			delete l;
			delete r;
		}

		Select_Or(Select* left, Select* right) {
			l = left;
			r = right;
		}

		bool select(const Spreadsheet* sheet, int row) const {
			if(l->select(sheet, row) || r->select(sheet, row)) {
				return true;
			}
			else {
				return false;
			}
		}
};

class Select_Not : public Select{

private:
  Select* one;

public:
  ~Select_Not() {
    delete one;
  }

  Select_Not(Select* one) {
    this->one = one;
  }

  bool select(const Spreadsheet* sheet, int row) const {

    return !one->select(sheet,row)

  }

};


#endif //__SELECT_HPP__

