/// 
// Filename: ScenarioControl.cpp
// Description: Implementation file for the ScenarioControl class
// 
// Version History:
// 1.0 2024-07-04 - Initial version
///

#include "ScenarioControl.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

// Vectors to hold the lists of objects
std::vector<Product> products;
std::vector<Bug> bugs;
std::vector<Customer> customers;
std::vector<Request> requests;

// Constructor
ScenarioControl::ScenarioControl() {}

// Product operations
Product ScenarioControl::createProduct(int productID, const std::string& name, const std::string& version) {
    Product product(productID, name, version);
    products.push_back(product);
    return product;
}

bool ScenarioControl::deleteProduct(int productID) {
    auto it = std::remove_if(products.begin(), products.end(), [productID](Product& product) {
        return product.getProductID() == productID;
    });
    if (it != products.end()) {
        products.erase(it, products.end());
        return true;
    }
    return false;
}

// Bug operations
Bug ScenarioControl::createBug(int bugID, const std::string& description, const std::string& severity, const std::string& status) {
    Bug bug(bugID, description, severity, status);
    bugs.push_back(bug);
    return bug;
}

bool ScenarioControl::deleteBug(int bugID) {
    auto it = std::remove_if(bugs.begin(), bugs.end(), [bugID](Bug& bug) {
        return bug.getBugID() == bugID;
    });
    if (it != bugs.end()) {
        bugs.erase(it, bugs.end());
        return true;
    }
    return false;
}

// Customer operations
Customer ScenarioControl::createCustomer(int customerID, const std::string& name, const std::string& contactInfo) {
    Customer customer(customerID, name, contactInfo);
    customers.push_back(customer);
    return customer;
}

bool ScenarioControl::deleteCustomer(int customerID) {
    auto it = std::remove_if(customers.begin(), customers.end(), [customerID](Customer& customer) {
        return customer.getCustomerID() == customerID;
    });
    if (it != customers.end()) {
        customers.erase(it, customers.end());
        return true;
    }
    return false;
}

// Request operations
Request ScenarioControl::createRequest(int requestID, const std::string& description, const std::string& priority, 
                                       const std::string& status, const std::string& dateOfRequest, int productID, 
                                       const std::string& customerName, int releaseID) {
    Request request(requestID, description, priority, status, dateOfRequest, productID, customerName, releaseID);
    requests.push_back(request);
    return request;
}

bool ScenarioControl::deleteRequest(int requestID) {
    auto it = std::remove_if(requests.begin(), requests.end(), [requestID](Request& request) {
        return request.getRequestID() == requestID;
    });
    if (it != requests.end()) {
        requests.erase(it, requests.end());
        return true;
    }
    return false;
}

// Private helper functions to find objects by ID
Product* ScenarioControl::findProduct(int productID) {
    auto it = std::find_if(products.begin(), products.end(), [productID](Product& product) {
        return product.getProductID() == productID;
    });
    return it != products.end() ? &(*it) : nullptr;
}

Bug* ScenarioControl::findBug(int bugID) {
    auto it = std::find_if(bugs.begin(), bugs.end(), [bugID](Bug& bug) {
        return bug.getBugID() == bugID;
    });
    return it != bugs.end() ? &(*it) : nullptr;
}

Customer* ScenarioControl::findCustomer(int customerID) {
    auto it = std::find_if(customers.begin(), customers.end(), [customerID](Customer& customer) {
        return customer.getCustomerID() == customerID;
    });
    return it != customers.end() ? &(*it) : nullptr;
}

Request* ScenarioControl::findRequest(int requestID) {
    auto it = std::find_if(requests.begin(), requests.end(), [requestID](Request& request) {
        return request.getRequestID() == requestID;
    });
    return it != requests.end() ? &(*it) : nullptr;
}
