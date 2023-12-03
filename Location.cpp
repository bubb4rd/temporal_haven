#include "Location.h"
Location::Location() : locationName(""), visitStatus(false), type("") {}
Location::Location(std::string location, bool visit, std::string locationType) : locationName(location), visitStatus(visit), type(locationType) {}
std::string Location::getLocation() {
    return locationName;
}
void Location::setLocation(std::string location) {
    locationName = location;
}

bool Location::getVisitStatus() {
    return visitStatus;
}

void Location::setVisitStatus(bool status) {
    visitStatus = status;
}
void Location::toString() {
    std::string v = "Unvisited";
    if (visitStatus) v = "Visited";
    std::cout << locationName << " | " << v << std::endl;
}
std::string Location::getType() {
    return type;
}
void Location::setType(std::string locationType) {
    type = locationType;
}
std::string Location::obfuscateLocation() {
    std::string result = locationName;
    for (char& c : result) {
        c = (c + 1) % 128;
    }
    return result;
}