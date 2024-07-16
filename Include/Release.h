/// 
 // Filename: Release.h
 // Description: Header file for the Release class
 // 
 // Version History:
 // 1.0 2024-07-02 - Initial version
 ///
#pragma once
#include <string>
#include <fstream>

#pragma once
#include <string>
#include <fstream>

class Release {
public:
    // Constructors

    // Default constructor initializes an empty release object
    Release();

    // Parameterized constructor initializes a release object with specific details
    // @param releaseID - The ID of the release
    // @param version - The version of the release
    // @param releaseDate - The release date
    Release(int releaseID, const std::string& version, const std::string& releaseDate);

    // Getters

    // Gets the release ID
    // @return The release ID
    int getReleaseID() const;

    // Gets the associated Product ID
    // @return The Product ID
    int getReleaseID() const;

    // Gets the version of the release
    // @return The version string
    std::string getVersion() const;

    // Gets the release date
    // @return - The release date string
    std::string getReleaseDate() const;

    // Setters

    // Sets the release ID
    // @param releaseID - The release ID
    void setReleaseID(int releaseID);

    // Sets the associated Product ID
    // @param productID - The Product ID
    void setReleaseID(int productID);

    // Sets the version of the release
    // @param version - The version string
    void setVersion(const std::string& version);

    // Sets the release date
    // @param releaseDate - The release date string
    void setReleaseDate(const std::string& releaseDate);

    // File operations

    // Opens the file for reading and writing
    // @param filename - The name of the file to open
    // @return - True if the file was successfully opened, false otherwise
    static bool openReleaseFile(const std::string& filename);

    // Closes the currently open file
    static void closeReleaseFile();

    // Writes a Release object to the file
    // @param - releaseObject The Release object to write
    // @return - True if the write operation was successful, false otherwise
    static bool writeRelease(const Release& releaseObject);

    // Moves the file cursor to the beginning of the file
    static void seekToBeginningOfFile();

    // Reads the next Release object from the file
    // @param releaseObject - The Release object to fill with data from the file
    // @return - True if a record was successfully read, false if the end of the file was reached
    static bool getNext(Release& releaseObject);

    // Deletes a specific Release record from the file
    // @param releaseID - The ID of the release to delete
    // @return - True if the record was successfully deleted, false otherwise
    static bool deleteReleaseRecord(int releaseID);

    // Finds a specific Release record in the file
    // @param releaseID - The ID of the release to find
    // @param releaseObject - The Release object to fill with data if found
    // @return - True if the record was found, false otherwise
    static bool findReleaseRecord(int releaseID, Release& releaseObject);

private:
    int releaseID;                // The release ID (PK)
    int productID;                // Associated Product ID (FK)
    std::string version;          // The version of the release
    std::string releaseDate;      // The release date

    static std::fstream file;     // The file stream used for file operations
    static std::string filename;  // The name of the currently open file
};

// Static member definitions
std::fstream Release::file;
std::string Release::filename;