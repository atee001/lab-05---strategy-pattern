#include "spreadsheet.hpp"
#include "gtest/gtest.h"
using namespace std;
#include "select.hpp"


TEST(SelectTest, Contains){

  Spreadsheet sheet;
  sheet.set_column_names({"First","Last","Age","Major"});
  sheet.add_row({"Amanda","Andrews","22","business"});
  sheet.add_row({"Brian","Becker","21","computer science"});
  sheet.add_row({"Carol","Conners","21","computer science"});
  sheet.add_row({"Joe","Jackson","21","mathematics"});
  sheet.add_row({"Sarah","Summers","21","computer science"});
  sheet.add_row({"Diane","Dole","20","computer engineering"});
  sheet.add_row({"David","Dole","22","electrical engineering"});
  sheet.add_row({"Dominick","Dole","22","communications"});
  sheet.add_row({"George","Genius","9","astrophysics"});
  
  string one = "Diane Dole 20 computer engineering \n";
  string two = "David Dole 22 electrical engineering \n";
  string three = "Dominick Dole 22 communications \n";
  string ans = one + two + three;

  stringstream ss;
  sheet.set_selection(new Select_Contains(&sheet, "First", "D"));
  sheet.print_selection(ss);

  EXPECT_EQ(ss.str(), ans);

}

TEST(SelectTest, Contains_Empty_Str) {

        Spreadsheet testing;

        testing.set_column_names({"First", "Last", "Animal"});
        testing.add_row({"Ash", "Pixie", "Cat"});

        string one = "Ash Pixie Cat \n";

        stringstream ss;
        testing.set_selection(new Select_Contains(&testing, "Animal", ""));
        testing.print_selection(ss);

        EXPECT_EQ(ss.str(), one);


}

TEST(SelectTest, Check_apple_app) {

        Spreadsheet testing;

        testing.set_column_names({"Word"});
        testing.add_row({"Snapple"});
        testing.add_row({"app"});

        string one = "Snapple \n";

        stringstream ss;
        testing.set_selection(new Select_Contains(&testing, "Word", "apple"));
        testing.print_selection(ss);

        EXPECT_EQ(ss.str(), one);

}

TEST(SelectTest, Contains_Empty_Str_Mult) {
	
	Spreadsheet testing;

	testing.set_column_names({"First", "Last", "Age", "Major"});

	testing.add_row({"Amanda","Andrews","22","business"});
	testing.add_row({"Brian","Becker","21","computer science"});
  	testing.add_row({"Carol","Conners","21","computer science"});
  	testing.add_row({"Joe","Jackson","21","mathematics"});

	string one = "Amanda Andrews 22 business \n";
	string two = "Brian Becker 21 computer science \n";
	string three = "Carol Conners 21 computer science \n";
	string four = "Joe Jackson 21 mathematics \n";

	string ans = one + two + three + four;

	stringstream ss;
	testing.set_selection(new Select_Contains(&testing, "First", ""));
	testing.print_selection(ss);

	EXPECT_EQ(ss.str(), ans);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
