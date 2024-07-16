/// 
 // Filename: Request.h
 // Description: Header file for the Request class
 // 
 // Version History:
 // 1.0 2024-07-02 - Initial version
 ///
#pragma once

#include <string>
#include <fstream>
#include "Bug.h"

class Request {
public:
    // Constructor
    // Default constructor initializes an empty Request object
    Request();

    // Parameterized constructor initializes a Request object with specific details
    // @param requestID - The ID of the request
    // @param description - Description of the request
    // @param priority - Priority of the request
    // @param status - Status of the request
    // @param dateOfRequest - Date the request was made
    // @param productID - ID of the related product
    // @param customerName - Name of the customer making the request
    // @param releaseID - ID of the Release associated with the product (nullable)
    Request(int changeRequestID, const std::string& description, const std::string& priority, 
            const std::string& status, const std::string& dateOfRequest, int productID, 
            const std::string& customerName, int releaseID);

    // Getters - all const as they do not change anything

    // Gets the change request ID
    // @return - returns the associated integer request ID
    int getRequestID() const;
    
    // Gets the description of the request
    // @return - returns the associated string description
    std::string getDescription() const;

    // Gets the priority of the request
    // @return - returns the associated string priority
    std::string getPriority() const;

    // Gets the status of the request
    // @return - returns the associated string status
    std::string getStatus() const;

    // Gets the date of the request
    // @return - returns the associated string date of request
    std::string getDateOfRequest() const;

    // Gets the product ID related to the request
    // @return - returns the associated integer product ID
    int getProductID() const;

    // Gets the name of the customer making the request
    // @return - returns the associated string customer name
    std::string getCustomerName() const;

    // Gets the release ID related to the request
    // @return - returns the associated integer release ID, or -1 if not set
    int getReleaseID() const;

    // Setters - no const promise because they change attributes

    // Sets the change request ID
    // @param changeRequestID - The change request ID to set
    // @return - returns true if successful, false otherwise
    bool setRequestID(int requestID);

    // Sets the description of the request
    // @param description - The description to set
    // @return - returns true if successful, false otherwise
    bool setDescription(const std::string& description);

    // Sets the priority of the request
    // @param priority - The priority to set
    // @return - returns true if successful, false otherwise
    bool setPriority(const std::string& priority);

    // Sets the status of the request
    // @param status - The status to set
    // @return - returns true if successful, false otherwise
    bool setStatus(const std::string& status);

    // Sets the date of the request
    // @param dateOfRequest - The date of request to set
    // @return - returns true if successful, false otherwise
    bool setDateOfRequest(const std::string& dateOfRequest);

    // Sets the product ID related to the request
    // @param productID - The product ID to set
    // @return - returns true if successful, false otherwise
    bool setProductID(int productID);

    // Sets the name of the customer making the request
    // @param customerName - The customer name to set
    // @return - returns true if successful, false otherwise
    bool setCustomerName(const std::string& customerName);

    // Sets the release ID related to the request
    // @param releaseID - The release ID to set
    // @return - returns true if successful, false otherwise
    bool setReleaseID(int releaseID);

    // File operations

    // Opens the file for reading and writing
    // @param filename - The name of the file to open
    // @return True if the file was successfully opened, false otherwise
    static bool openRequestFile(const std::string& filename);

    // Closes the currently open file
    static void closeRequestFile();

    // Writes a Request object to the file
    // @param requestObject - The Request object to write
    // @return - True if the write operation was successful, false otherwise
    static bool writeRequest(const Request& requestObject);

    // Moves the file cursor to the beginning of the file
    static void seekToBeginningOfFile();

    // Reads the next Request object from the file
    // @param requestObject - The Request object to fill with data from the file
    // @return - True if a record was successfully read, false if the end of the file was reached
    static bool getNext(Request& requestObject);

    // Deletes a specific Request record from the file
    // @param changeRequestID - The ID of the request to delete
    // @return - True if the record was successfully deleted, false otherwise
    static bool deleteRequestRecord(int changeRequestID);

    // Finds a specific Request record in the file
    // @param changeRequestID - The ID of the request to find
    // @param requestObject - The Request object to fill with data if found
    // @return - True if the record was found, false otherwise
    static bool findRequestRecord(int changeRequestID, Request& requestObject);

    // Converts the request into a bug if sufficient information is available
    // Preconditions:
    //  - The request must have a valid description, priority, status, product ID, and a release ID
    //  - The bug ID must be unique
    // Postconditions:
    //  - If all preconditions are met, returns a Bug object with the corresponding information from the request
    //  - If any precondition is not met, throws a std::invalid_argument exception
    // @return - A Bug object with information copied from the request
    // @throws std::invalid_argument if any required information is missing
    Bug convertToBug() const;

private:
    int changeRequestID;  // The change request ID
    std::string description;  // The description of the request
    std::string priority;  // The priority of the request
    std::string status;  // The status of the request
    std::string dateOfRequest;  // The date the request was made
    int productID;  // The ID of the related product
    std::string customerName;  // The name of the customer making the request
    int releaseID;  // The ID of the related release, or -1 if not set

    static std::fstream file;  // The file stream used for file operations
    static std::string filename;  // The name of the currently open file
};

// Static member definitions
std::fstream Request::file;
std::string Request::filename;
