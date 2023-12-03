#include <string>
#include <iostream>
#pragma once
class Location {
    public:
        Location();
        Location(std::string location, bool visit, std::string locationType);
        std::string getLocation();
        void setLocation(std::string location);
        bool getVisitStatus();
        void setVisitStatus(bool status);
        void toString();
        std::string getType();
        void setType(std::string locationType);
        std::string obfuscateLocation();
    private:
        std::string locationName;
        bool visitStatus;
        std::string type;
};