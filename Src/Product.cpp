/// 
// Filename: Product.cpp
// Description: Implementation file for the Product class
// 
// Version History:
// 1.0 2024-07-02 - Initial version
///

#include "Product.h"
#include <fstream>

// Initialize static members
std::fstream Product::file;
std::string Product::filename;

// Constructor - default
Product::Product()
    : productID(0), name(""), productRelease(), isAnticipatedRelease(false) {}

// Parameterized Constructor
Product::Product(int productID, const std::string &name, const std::string &releaseDate)
    : productID(productID), name(name), productRelease(releaseDate), isAnticipatedRelease(false) {}

// Getters
int Product::getProductID() const {
    return productID;
}

std::string Product::getName() const {
    return name;
}

std::string Product::getReleaseDate() const {
    return productRelease.getReleaseDate();
}

bool Product::isAnticipatedRelease() const {
    return isAnticipatedRelease;
}

Release& Product::getReleases() const {
    return const_cast<Release&>(productRelease);
}

// Setters
bool Product::setProductID(int newProductID) {
    productID = newProductID;
    return true;
}

bool Product::setName(const std::string &newName) {
    name = newName;
    return true;
}

bool Product::setRelease(Release& releaseToSet) {
    productRelease = releaseToSet;
    return true;
}

bool Product::setAnticipatedRelease(bool anticipatedRelease) {
    isAnticipatedRelease = antici
