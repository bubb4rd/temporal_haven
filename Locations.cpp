#include "Locations.h"
Locations::Locations(std::string name) {
    locationsName = name;
}
void Locations::addLocation(Location place) {
    locations.push_back(place);
}
void Locations::displayLocations() {
    std::cout << "LOCATIONS" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    for (auto i : locations) {
        if (i.getType() == "SECRET") {
            std::string v;
            if (i.getVisitStatus() == false) v = "Unvisited";
            else v = "Visited";
             std::cout << i.obfuscateLocation() << " | " + v << std::endl;
        }
        else i.toString();
    }
}
void Locations::changeVisitStatus(Location location) {
   for (int i = 0; i < locations.size(); i++) {
        if (locations[i].getLocation() == location.getLocation()) {
            if (!locations[i].getVisitStatus()) locations[i].setVisitStatus(true);
            else locations[i].setVisitStatus(false);
        }
    }
}
void Locations::setLocationType(Location location, std::string type) {
    for (int i = 0; i < locations.size(); i++) {
        if (locations[i].getLocation() == location.getLocation()) locations[i].setType(type);
    }
}
Location Locations::getLocation(std::string name) {
    Location place(name, false, "PUBLIC");
    for (int i = 0; i < locations.size(); i++) {
        if (locations[i].getLocation() == name) place = locations[i];
    }
    return place;
}
void Locations::removeLocation(Location location) {
    for (int i = 0; i < locations.size(); i++) {
            if (locations[i].getLocation() == location.getLocation()) locations.erase(locations.begin() + i);
    }   
}