#include <iostream>
#include <map>
#include <tuple>
#include <limits>
#include <string>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerInfo;

    // insert elements into the map
    // note how the right-hand side contains the tuple elements
    villagerInfo["Audie"] = {5, "Deer", "That's Cool"};
    villagerInfo["Raymond"] = {8, "Turtle", "Patience"};
    villagerInfo.insert({"Marshal", {7, "Squirrel", "Nuts"}});

    // access the map using a range-based for loop
    cout << "Villagers and their information (range-based for loop):" << endl;
    for (auto pair : villagerInfo) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their information(iterators):" << endl;
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
        cout << "Friendship: " << get<0>(it->second) << endl;
        cout << "Species: " <<  get<1>(it->second) << endl;
        cout << "Catchphrase: " << get<2>(it->second) << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    int choice;
    string name;

    do {
        cout << "\n1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                // add villager
                int friendship;
                string species, catchphrase;

                cout << "Enter villager name: ";
                cin >> name;

                auto it = villagerInfo.find(name);

                if (it != villagerInfo.end()) {
                    cout << "Villager already exists." << endl;
                    break;
                }

                cout << "Enter friendship level (0-10): ";
                cin >> friendship;

                if (!cin || friendship < 0 || friendship > 10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid friendship level." << endl;
                    break;
                }

                cout << "Enter species: ";
                cin >> species;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter catchphrase: ";
                getline(cin, catchphrase);

                villagerInfo.insert({name, {friendship, species, catchphrase}});

                cout << name << " added successfully!" << endl;
                break;
            }

            case 2: {
                // delete villager
                cout << "Enter villager name: ";
                cin >> name;

                auto it = villagerInfo.find(name);

                if (it != villagerInfo.end()) {
                    villagerInfo.erase(it);
                    cout << name << " deleted successfully." << endl;
                } else {
                    cout << "Villager not found." << endl;
                }
                break;
            }
            case 3: {
                // increase friendship
                cout << "Enter villager name: ";
                cin >> name;

                auto it = villagerInfo.find(name);
                if (it != villagerInfo.end()) {
                    if (get<0>(it->second) < 10) {
                        ++get<0>(it->second);
                        cout << name << "'s friendship increased." << endl;
                    } else {
                        cout << "Friendship is already maximum level." << endl;
                    }
                } else {
                    cout << "Villager not found." << endl;
                }
                break;
            }
            case 4: {
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

            case 5: {
                // search for villager
                cout << "Enter villager name: ";
                cin >> name;

                auto it = villagerInfo.find(name);

                if (it != villagerInfo.end()) {
                    cout << "Found " << name << "'s information:" << endl;
                    cout << "Friendship: " << get<0>(it->second) << endl;
                    cout << "Species: " << get<1>(it->second) << endl;
                    cout << "Catchphrase: " << get<2>(it->second) << endl;
                } else {
                    cout << "Villager not found." << endl;
                }
                break;
            }

            case 6: {
                // exit program
                cout << "Exiting program. Goodbye!" << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }

        }

        // display updated map after each operation
        if (choice != 6) {
            cout << "\nVillager details: " << endl;

            for (const auto& pair : villagerInfo) {
                cout << pair.first << " ["
                     << get<0>(pair.second) << ", "
                     << get<1>(pair.second) << ", "
                     << get<2>(pair.second) << "]" << endl;
            }
        }
    } while (choice != 6);

    return 0;
}