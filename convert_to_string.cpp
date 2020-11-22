#include <iostream>
#include <fstream>
#include <string>

const std::string INPUT_PATH = "housepricedata.csv";
const std::string OUTPUT_PATH = "initial_data.h";
const std::string STRING_NAME = "initial_data";

int main() {

  std::string x =
  "dfdmkf"
  "sdsd";

  std::ifstream in(INPUT_PATH);
  std::ofstream out(OUTPUT_PATH);

  std::string str, str2;



  #include <string>
  str2 = "#pragma once\n";
  str2 += "#include <string>\n\n";
  str2 += "std::string ";
  str2 += STRING_NAME;
  str2 += " =";

  std::cout<<str2;
  out << str2;

  while (std::getline(in, str)) {

    str2 = "\n\"";
    str2 += str;
    str2 += "\\n\"";
    std::cout << str2;
    out << str2;
  }
  str2 = ";";
  std::cout<<str2;
  out << str2;

}
