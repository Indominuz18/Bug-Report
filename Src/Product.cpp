/// 
// Filename: Product.cpp
// Description: Implementation file for the Product class
// 
// Version History:
// 1.0 2024-07-02 - Initial version
///

#include "Product.h"
#include <fstream>
#include <iostream>
#include <iomanip>

// Initialize static members
std::fstream Product::file;
std::string Product::filename = "";

// Default constructor
Product::Product() : productID(0), name(""), productRelease(), isAnticipatedRelease(false) {}

// Parameterized constructor
Product::Product(int productID, const std::string &name, const std::string &releaseDate)
    : productID(productID), name(name), productRelease(releaseDate), isAnticipatedRelease(false) {}

// Getter for Product ID
int Product::getProductID() const {
    return productID;
}

// Getter for Product name
std::string Product::getName() const {
    return name;
}

// Getter for Product release date
std::string Product::getReleaseDate() const {
    return productRelease.getReleaseDate();
}

// Getter for anticipated release
bool Product::isAnticipatedRelease() const {
    return isAnticipatedRelease;
}

// Getter for Product Release
Release& Product::getReleases() const {
    return const_cast<Release&>(productRelease);
}

// Setter for Product ID
bool Product::setProductID(int newProductID) {
    if (newProductID > 0) {
        productID = newProductID;
        return true;
    }
    return false;
}

// Setter for Product name
bool Product::setName(const std::string& newName) {
    if (!newName.empty()) {
        name = newName;
        return true;
    }
    return false;
}

// Setter for Product Release
bool Product::setRelease(Release& releaseToSet) {
    productRelease = releaseToSet;
    return true;
}

// Setter for anticipated release
bool Product::setAnticipatedRelease(bool isAnticipated) {
    isAnticipatedRelease = isAnticipated;
    return true;
}

// Opens the file for reading and writing
bool Product::openReleaseFile(const std::string& filename) {
    Product::filename = filename;
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::app);
    return file.is_open();
}

// Closes the currently open file
void Product::closeProductFile() {
    if (file.is_open()) {
        file.close();
    }
}

// Writes a Product object to the file
bool Product::writeProduct(const Product& productObject) {
    if (file.is_open()) {
        file.seekp(0, std::ios::end);
        file.write(reinterpret_cast<const char*>(&productObject), sizeof(Product));
        return file.good();
    }
    return false;
}

// Moves the file cursor to the beginning of the file
void Product::seekToBeginningOfFile() {
    if (file.is_open()) {
        file.seekg(0, std::ios::beg);
    }
}

// Reads the next Product object from the file
bool Product::getNext(Product& productObject) {
    if (file.is_open() && !file.eof()) {
        file.read(reinterpret_cast<char*>(&productObject), sizeof(Product));
        return file.good();
    }
    return false;
}

// Deletes a specific Product record from the file
bool Product::deleteProductRecord(int productID) {
    if (file.is_open()) {
        std::fstream tempFile("temp.dat", std::ios::out | std::ios::binary);
        Product tempProduct;
        bool found = false;

        seekToBeginningOfFile();
        while (getNext(tempProduct)) {
            if (tempProduct.getProductID() != productID) {
                tempFile.write(reinterpret_cast<const char*>(&tempProduct), sizeof(Product));
            } else {
                found = true;
            }
        }

        file.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.dat", filename.c_str());

        openReleaseFile(filename);
        return found;
    }
    return false;
}

// Finds a specific Product record in the file
bool Product::findProductRecord(int productID, Product& productObject) {
    if (file.is_open()) {
        seekToBeginningOfFile();
        while (getNext(productObject)) {
            if (productObject.getProductID() == productID) {
                return true;
            }
        }
    }
    return false;
}
