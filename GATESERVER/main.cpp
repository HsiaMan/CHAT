#include <boost/filesystem.hpp>
#include <iostream>

int main() {
    boost::filesystem::path p = "/opt/homebrew";
    std::cout << "Exists? " << boost::filesystem::exists(p) << std::endl;
}
