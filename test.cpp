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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
