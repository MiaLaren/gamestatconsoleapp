//*** 
//Author*****:Mia Santos
//Assignment*:GameStat Console App
//Description:Console app will generate characters, caluculate combat stats, and navigate through a menu system.
//***


#include <iostream>
using namespace std;

// Constants for maximum stats
const int MIN_STAT = 1;
const int MAX_STAT = 20;
const int MAX_LEVEL = 10;

int main() {
    int choice;
    bool created = false;

    string name, className;
    int classChoice;
    int level = 1;

    // Base stats
    int strBase, intBase, dexBase, conBase;

    // Class bonuses
    int strBonus = 0, intBonus = 0, dexBonus = 0, conBonus = 0;

    do {
        cout << "\n=== GAMESTAT CHARACTER MANAGER ===\n";
        cout << "1. Create New Character\n";
        cout << "2. View Character Profile\n";
        cout << "3. Level Up Character\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid choice. Enter 1-4: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (choice) {

        case 1: // Create character
            cout << "Enter character name: ";
            cin >> name;

            cout << "\nChoose class:\n";
            cout << "1. Warrior\n";
            cout << "2. Mage\n";
            cout << "3. Rogue\n";
            cout << "4. Cleric\n";
            cout << "Enter choice: ";
            cin >> classChoice;

            strBonus = intBonus = dexBonus = conBonus = 0;

            switch (classChoice) {
                case 1: className = "Warrior"; strBonus = 2; conBonus = 2; break;
                case 2: className = "Mage"; intBonus = 4; break;
                case 3: className = "Rogue"; dexBonus = 3; break;
                case 4: className = "Cleric"; intBonus = 2; conBonus = 2; break;
            }

            // Input base stats with validation
            cout << "Enter Strength (" << MIN_STAT << "-" << MAX_STAT << "): ";
            cin >> strBase;
            while (strBase < MIN_STAT || strBase > MAX_STAT) {
                cout << "Invalid. Enter " << MIN_STAT << "-" << MAX_STAT << ": ";
                cin >> strBase;
            }

            cout << "Enter Intelligence (" << MIN_STAT << "-" << MAX_STAT << "): ";
            cin >> intBase;
            while (intBase < MIN_STAT || intBase > MAX_STAT) {
                cout << "Invalid. Enter " << MIN_STAT << "-" << MAX_STAT << ": ";
                cin >> intBase;
            }

            cout << "Enter Dexterity (" << MIN_STAT << "-" << MAX_STAT << "): ";
            cin >> dexBase;
            while (dexBase < MIN_STAT || dexBase > MAX_STAT) {
                cout << "Invalid. Enter " << MIN_STAT << "-" << MAX_STAT << ": ";
                cin >> dexBase;
            }

            cout << "Enter Constitution (" << MIN_STAT << "-" << MAX_STAT << "): ";
            cin >> conBase;
            while (conBase < MIN_STAT || conBase > MAX_STAT) {
                cout << "Invalid. Enter " << MIN_STAT << "-" << MAX_STAT << ": ";
                cin >> conBase;
            }

            level = 1;
            created = true;
            cout << "Character created successfully!\n";
            break;

        case 2: // View character profile
            if (!created) {
                cout << "No character created yet.\n";
            } else {
                int strength = strBase + strBonus;
                int intelligence = intBase + intBonus;
                int dexterity = dexBase + dexBonus;
                int constitution = conBase + conBonus;

                string statNames[4] = {
                    "Health Points",
                    "Mana Points",
                    "Attack Power",
                    "Defense"
                };

                double statValues[4];

                for (int i = 0; i < 4; i++) {
                    switch (i) {
                        case 0: // HP
                            statValues[i] = (constitution * 10) + (level * 5);
                            if (classChoice == 1) statValues[i] += 20;
                            break;
                        case 1: // MP
                            statValues[i] = (intelligence * 10) + (level * 3);
                            if (classChoice == 2) statValues[i] += 30;
                            break;
                        case 2: // Attack Power
                            if (classChoice == 1) statValues[i] = strength * 1.5;
                            else if (classChoice == 2) statValues[i] = intelligence * 1.3;
                            else if (classChoice == 3) statValues[i] = dexterity * 1.4;
                            else statValues[i] = (strength + intelligence) * 0.8;
                            break;
                        case 3: // Defense
                            statValues[i] = (constitution + dexterity) / 2.0;
                            break;
                    }
                }

                cout << "\n=== CHARACTER PROFILE ===\n";
                cout << "Name: " << name << endl;
                cout << "Class: " << className << endl;
                cout << "Level: " << level << endl;

                cout << "\nBase Stats:\n";
                cout << "  Strength:     " << strBase << " (+" << strBonus << ") = " << strength << endl;
                cout << "  Intelligence: " << intBase << " (+" << intBonus << ") = " << intelligence << endl;
                cout << "  Dexterity:    " << dexBase << " (+" << dexBonus << ") = " << dexterity << endl;
                cout << "  Constitution: " << conBase << " (+" << conBonus << ") = " << constitution << endl;

                cout << "\nCombat Stats:\n";
                for (int i = 0; i < 4; i++) {
                    cout << "  " << statNames[i] << ": " << statValues[i] << endl;
                }
            }
            break;

        case 3: // Level up character
            if (!created) {
                cout << "No character created yet.\n";
            }
            else if (level >= MAX_LEVEL) {
                cout << "Character is already at MAX LEVEL (" << MAX_LEVEL << ").\n";
            }
            else {
                int levelBefore = level;
                int strBefore = strBase;
                int intBefore = intBase;
                int dexBefore = dexBase;
                int conBefore = conBase;

                level++;
                strBase++;
                intBase++;
                dexBase++;
                conBase++;

                cout << "\n=== LEVEL UP! ===\n";
                cout << "Level: " << levelBefore << " -> " << level << endl;

                cout << "\nBase Stats (Before -> After):\n";
                cout << "  Strength:     " << strBefore << " -> " << strBase << endl;
                cout << "  Intelligence: " << intBefore << " -> " << intBase << endl;
                cout << "  Dexterity:    " << dexBefore << " -> " << dexBase << endl;
                cout << "  Constitution: " << conBefore << " -> " << conBase << endl;

                cout << "\nCombat stats updated!\n";
            }
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        }

    } while (choice != 4);

    return 0;
}
