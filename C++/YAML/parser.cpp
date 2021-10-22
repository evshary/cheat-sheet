#include <iostream>
#include <yaml-cpp/yaml.h>

int main() {
    YAML::Node yaml_data;

    yaml_data = YAML::LoadFile("test.yaml");

    std::string mytopic = yaml_data["mytopic"].as<std::string>();
    std::cout << "mytopic: " << mytopic << std::endl;

    std::cout << "Print directly" << std::endl;
    std::cout << yaml_data["mylist"] << std::endl;

    std::cout << "Print iteratively" << std::endl;
    for (YAML::const_iterator it = yaml_data["mylist"].begin(); it != yaml_data["mylist"].end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
