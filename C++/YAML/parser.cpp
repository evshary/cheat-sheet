#include <iostream>
#include <yaml-cpp/yaml.h>

int main() {
    YAML::Node yaml_data;

    yaml_data = YAML::LoadFile("test.yaml");

    // print value
    std::cout << "Example: try to print value" << std::endl;
    std::string mytopic = yaml_data["mytopic"].as<std::string>();
    std::cout << "mytopic: " << mytopic << std::endl;

    // print list
    std::cout << std::endl;
    std::cout << "Example: try to print list" << std::endl;
    std::cout << "Print directly" << std::endl;
    std::cout << yaml_data["mylist"] << std::endl;

    std::cout << "Print iteratively" << std::endl;
    for (YAML::const_iterator it = yaml_data["mylist"].begin(); it != yaml_data["mylist"].end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // The difference of using as<std::string>()
    std::cout << std::endl;
    std::cout << "Example: show the difference of using as<std::string>()" << std::endl;
    std::cout << "print directly => item1: " << yaml_data["mylist"]["item 1"] << std::endl;
    std::cout << "print as<std::string>() => item1: " << yaml_data["mylist"]["item 1"].as<std::string>() << std::endl;

    // Output yaml file
    std::cout << std::endl;
    std::cout << "Output YAML string" << std::endl;
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "name";
    out << YAML::Value << "evshary";
    out << YAML::Key << "comment";
    out << YAML::Value << "Hello\nworld";
    out << YAML::EndMap;
    std::cout << "----------------------" << std::endl;
    std::cout << out.c_str() << std::endl;
    std::cout << "----------------------" << std::endl;

    return 0;
}
