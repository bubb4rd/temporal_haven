#include <vector>
#include "Location.h"
class Locations {
    public:
        Locations(std::string name);
        void addLocation(Location place);
        void displayLocations();
        Location getLocation(std::string name);
        void changeVisitStatus(Location location);
        void setLocationType(Location location, std::string type);
        void removeLocation(Location location);
    private:
        std::vector<Location> locations;
        std::string locationsName;
};