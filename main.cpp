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

    int choice;
    string name;

    do {
        cout << "\n1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // increase friendship
                cout << "Enter villager name: ";
                cin >> name;

                auto it = villagerInfo.find(name);
                if (it != villagerInfo.end()) {
                    if (get<0>(it->second) < 10) {
                        ++get<0>(it->second);
                        cout << name << "'s friendship inreased." << endl;
                    } else {
                        cout << "Friendship is already maxed out." << endl;
                    }
                } else {
                    cout << "Villager not found." << endl;
                }
                break;
            }
            case 2: {
                // decrease friendship
                cout << "Enter villager name: ";
                cin >> name;

                auto it = villagerInfo.find(name);

                if (it != villagerInfo.end()) {
                    if (get<0>(it->second) > 0) {
                        --get<0>(it->second);
                        cout << name << "'s friendship decreased." << endl;
                    } else {
                        cout << "Friendship is already at minimum level." << endl;
                    }
                } else {
                    cout << "Villager not found." << endl;
                }
                break;
            }
        }

        case 3: 
    }

    return 0;
}