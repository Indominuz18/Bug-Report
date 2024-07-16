/// 
// Filename: Release.cpp
// Description: Implementation file for the Release class
// 
// Version History:
// 1.0 2024-07-02 - Initial version
///

#include "Release.h"

// Constructors
Release::Release() : releaseID(0), productID(0), version(""), releaseDate("") {}

Release::Release(int releaseID, int productID, const std::string& version, const std::string& releaseDate)
    : releaseID(releaseID), productID(productID), version(version), releaseDate(releaseDate) {}

// Getters
int Release::getReleaseID() const {
    return releaseID;
}

int Release::getProductID() const {
    return productID;
}

std::string Release::getVersion() const {
    return version;
}

std::string Release::getReleaseDate() const {
    return releaseDate;
}

// Setters
void Release::setReleaseID(int releaseID) {
    this->releaseID = releaseID;
}

void Release::setProductID(int productID) {
    this->productID = productID;
}

void Release::setVersion(const std::string& version) {
    this->version = version;
}

void Release::setReleaseDate(const std::string& releaseDate) {
    this->releaseDate = releaseDate;
}

// File operations
bool Release::openReleaseFile(const std::string& filename) {
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        return false;
    }
    Release::filename = filename;
    return true;
}

void Release::closeReleaseFile() {
    if (file.is_open()) {
        file.close();
    }
}

bool Release::writeRelease(const Release& releaseObject) {
    if (!file.is_open()) {
        return false;
    }
    file.write(reinterpret_cast<const char*>(&releaseObject), sizeof(Release));
    return file.good();
}

void Release::seekToBeginningOfFile() {
    if (file.is_open()) {
        file.seekg(0);
    }
}

bool Release::getNext(Release& releaseObject) {
    if (!file.is_open()) {
        return false;
    }
    file.read(reinterpret_cast<char*>(&releaseObject), sizeof(Release));
    return file.good();
}

bool Release::deleteReleaseRecord(int releaseID) {
    // Implement the logic to delete a specific release record
    // This would typically involve reading all records, skipping the one to delete, and rewriting the file
    return true;
}

bool Release::findReleaseRecord(int releaseID, Release& releaseObject) {
    seekToBeginningOfFile();
    while (getNext(releaseObject)) {
        if (releaseObject.getReleaseID() == releaseID) {
            return true;
        }
    }
    return false;
}
