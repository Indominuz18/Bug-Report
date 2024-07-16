/// 
// Filename: Request.cpp
// Description: Implementation file for the Request class
// 
// Version History:
// 1.0 2024-07-02 - Initial version
///

#include "Request.h"
#include <stdexcept>
#include <sstream>

// Constructors
Request::Request() : changeRequestID(0), productID(0), releaseID(-1) {}

Request::Request(int changeRequestID, const std::string& description, const std::string& priority, 
                 const std::string& status, const std::string& dateOfRequest, int productID, 
                 const std::string& customerName, int releaseID)
    : changeRequestID(changeRequestID), description(description), priority(priority), status(status), 
      dateOfRequest(dateOfRequest), productID(productID), customerName(customerName), releaseID(releaseID) {}

// Getters
int Request::getRequestID() const {
    return changeRequestID;
}

std::string Request::getDescription() const {
    return description;
}

std::string Request::getPriority() const {
    return priority;
}

std::string Request::getStatus() const {
    return status;
}

std::string Request::getDateOfRequest() const {
    return dateOfRequest;
}

int Request::getProductID() const {
    return productID;
}

std::string Request::getCustomerName() const {
    return customerName;
}

int Request::getReleaseID() const {
    return releaseID;
}

// Setters
bool Request::setRequestID(int requestID) {
    changeRequestID = requestID;
    return true;
}

bool Request::setDescription(const std::string& description) {
    this->description = description;
    return true;
}

bool Request::setPriority(const std::string& priority) {
    this->priority = priority;
    return true;
}

bool Request::setStatus(const std::string& status) {
    this->status = status;
    return true;
}

bool Request::setDateOfRequest(const std::string& dateOfRequest) {
    this->dateOfRequest = dateOfRequest;
    return true;
}

bool Request::setProductID(int productID) {
    this->productID = productID;
    return true;
}

bool Request::setCustomerName(const std::string& customerName) {
    this->customerName = customerName;
    return true;
}

bool Request::setReleaseID(int releaseID) {
    this->releaseID = releaseID;
    return true;
}

// File operations
bool Request::openRequestFile(const std::string& filename) {
    Request::filename = filename;
    file.open(filename, std::ios::in | std::ios::out | std::ios::app);
    return file.is_open();
}

void Request::closeRequestFile() {
    if (file.is_open()) {
        file.close();
    }
}

bool Request::writeRequest(const Request& requestObject) {
    if (!file.is_open()) return false;
    file << requestObject.changeRequestID << " "
         << requestObject.description << " "
         << requestObject.priority << " "
         << requestObject.status << " "
         << requestObject.dateOfRequest << " "
         << requestObject.productID << " "
         << requestObject.customerName << " "
         << requestObject.releaseID << std::endl;
    return true;
}

void Request::seekToBeginningOfFile() {
    if (file.is_open()) {
        file.seekg(0, std::ios::beg);
    }
}

bool Request::getNext(Request& requestObject) {
    if (!file.is_open() || file.eof()) return false;
    file >> requestObject.changeRequestID >> requestObject.description >> requestObject.priority 
         >> requestObject.status >> requestObject.dateOfRequest >> requestObject.productID 
         >> requestObject.customerName >> requestObject.releaseID;
    return !file.fail();
}

bool Request::deleteRequestRecord(int changeRequestID) {
    // Implementation to delete a record
    return false; // Placeholder
}

bool Request::findRequestRecord(int changeRequestID, Request& requestObject) {
    seekToBeginningOfFile();
    while (getNext(requestObject)) {
        if (requestObject.getRequestID() == changeRequestID) {
            return true;
        }
    }
    return false;
}

Bug Request::convertToBug() const {
    if (description.empty() || priority.empty() || status.empty() || productID == 0 || releaseID == -1) {
        throw std::invalid_argument("Insufficient information to convert Request to Bug");
    }
    return Bug(changeRequestID, description, priority, status, releaseID);
}
