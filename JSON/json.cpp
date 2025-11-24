#include <iostream>
#include <json/json.h>
#include <string>
int main(){
    Json::Value root;
    root["id"] = 1001;
    root["data"] = root.toStyledString();
    std::string request = root.toStyledString();
    std::cout << request << std::endl;
    
    Json::Value root2;
    Json::Reader reader;
    reader.parse(request, root2);
    std::cout << "msg id is " << root2["id"]<< "msg is " << root2["data"] << std::endl;

}
