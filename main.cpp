#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerInfo;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerInfo["Audie"] = {5, "Deer", "That's Cool"};
    villagerInfo["Raymond"] = {8, "Turtle", "Patience"};
    villagerInfo.insert({"Marshal", {7, "Squirrel", "Nuts"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerInfo) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerInfo.begin(); 
                                               it != villagerInfo.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << endl;                                   
                                                
    }

    // delete an element
    villagerInfo.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s information:\n";
        cout << "Friendships: " << get<0>(it->second) << endl;
        cout << "Species: " <<  get<1>(it->second) << endl;
        cout << "Catchphrase: " << get<2>(it->second) << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerInfo.size() << endl;
    villagerInfo.clear();
    cout << "Size after clear: " << villagerInfo.size() << endl;

    return 0;
}