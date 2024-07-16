/// 
 // Filename: Product.h
 // Description: Header file for the Product class
 // 
 // Version History:
 // 1.0 2024-07-02 - Initial version
 ///

#pragma once

#include <string>
#include "Release.h"

class Product {
public:
    // Constructor
    // Default - initializes empty Product instance
    Product();

    // Parameterized Constructor - initializes Product instance with given parameters
    // @param productID - Product ID number (of the Product to create)
    // @param name - Name of Product (taken by reference)
    // @param releaseDate - String of the release date to use (taken by reference)
    Product(int productID, const std::string &name, const std::string &releaseDate);

    // Getters - all const as they do not change anything

    // Gets Product ID of a particular instance
    // @return - returns associated integer Product ID 
    int getProductID() const;
    
    // Gets Product name of a particular instance
    // @return - returns associated string of Product name 
    std::string getName() const;

    // Gets Product release date of a particular instance
    // @return - returns associated string of Product release date from Release instance
    std::string getReleaseDate() const;

    // Gets whether or not the Product has an anticipated release
    // @return - returns true if anticipated release, false otherwise
    bool isAnticipatedRelease() const;

    // Gets Product Release of a particular instance
    // @return - return a reference to the associated Release instance of the Product instance
    Release& getReleases() const;

    // Setters - no const promise because sets different attributes

    // Sets Product ID of a particular instance
    // @return - returns true if successful, false otherwise
    bool setProductID();

    // Sets Product name of a particular instance
    // @return - returns true if successful, false otherwise
    bool setName();

    // Sets Product associated Release with a new Release object
    // Note: Cannot change the date of the Release (of a Product), without changing the whole relase
    // @return - returns true if successful, false otherwise
    bool setRelease(Release& releaseToSet);

    // Sets Product anticipated release
    // @param isAnticipatedRelease - bool representing whether or not Product has an anticipated release
    // @return - returns true if successful, false otherwise
    bool setAnticipatedRelease(bool isAnticipatedRelease);

    // File operations

    // Opens the file for reading and writing
    // @param filename - The name of the file to open
    // @return True if the file was successfully opened, false otherwise
    static bool openReleaseFile(const std::string& filename);

    // Closes the currently open file
    static void closeProductFile();

    // Writes a Product object to the file
    // @param - productObject - The Product object to write
    // @return - True if the write operation was successful, false otherwise
    static bool writeProduct();

    // Moves the file cursor to the beginning of the file
    static void seekToBeginningOfFile();

    // Reads the next Product object from the file
    // @param productObject - The Product object to fill with data from the file
    // @return - True if a record was successfully read, false if the end of the file was reached
    static bool getNext(Release& productObject);

    // Deletes a specific Product record from the file
    // @param productID - The ID of the release to delete
    // @return - True if the record was successfully deleted, false otherwise
    static bool deleteProductRecord(int productID);

    // Finds a specific Product record in the file
    // @param productID - The ID of the release to find
    // @param productObject - The Product object to fill with data if found
    // @return - True if the record was found, false otherwise
    static bool findProductRecord(int productID, Release& productObject);

private:
    int productID;
    std::string name;
    Release productRelease; // if a future Release, then this is the anticipatedRelease
    bool isAnticipatedRelease; // represents whether the Product Release is in the future or not

    static std::fstream file;  // The file stream used for file operations
    static std::string filename;  // The name of the currently open file
};

