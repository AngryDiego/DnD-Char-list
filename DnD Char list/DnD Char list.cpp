#include <iostream>

using namespace std;

int main() {
    string name, classPlayer;
    int points = 27;
    const int MAX_POINTS = 15;

    const int STATS_SIZE = 6;
    int stats[STATS_SIZE] = { 8,8,8,8,8,8 };
    int add_stats[STATS_SIZE] = { 0,0,0,0,0,0};

    string statsNames[STATS_SIZE] = { "STR", "DEX", "CON", "INT", "WIS", "CHA" };

    const int CLASSPLAYER_SIZE = 12;
    string classPlayer2[CLASSPLAYER_SIZE] = { "Bard", "Barbarian", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard" };

    const int RACE_SIZE = 9;
    string Race[RACE_SIZE] = { "Human", "Half Elf", "Half Orc", "Dwarf", "Gnome", "Elf", "Dragonborn", "Halfling", "Tiefling" };

    const int SUBRACE_SIZE = 15;
    string SubRace[SUBRACE_SIZE] = { "Human", "Human variant","Half Elf", "Half Orc", "Mountain Dwarf", "Hill Dwarf", "Forest Gnome", "Rock Gnome", "High Elf", "Wood elf", "Drow", "Dragonborn", "Light-foot Halfling", "Stout Halfling", "Tiefling" };

    int race_bonus[SUBRACE_SIZE][STATS_SIZE] = {
        {1,1,1,1,1,1}, // Human
        {0,0,0,0,0,0}, // AltHuman
        {0,0,0,0,0,2}, // Half Elf
        {2,0,1,0,0,0}, // Half Orc
        {0,0,2,0,0,0}, // Dwarf Mountain
        {0,0,2,0,0,0}, // Dwarf Hill
        {0,1,0,2,0,0}, // Gnome Forest
        {0,0,1,2,0,0}, // Gnome Rock
        {0,2,0,1,0,0}, // Elf high
        {0,2,0,0,1,0}, // Elf WooD
        {0,2,0,0,0,1}, // Drow
        {2,0,0,0,0,1}, // Dragonborn
        {0,2,0,0,0,1}, // Halfling Light-foot
        {0,2,1,0,0,0}, // Halfling Stout
        {0,0,0,1,0,2}  // Tiefling
    };

    int choice = 0;
    int choiceCount;
    int choiceClass;
    int choiceRace;
    int choiceSubRace;
    int SpecialPlus[STATS_SIZE] = {0,0,0,0,0,0};
    

    cout << "Enter your character name : ";
    cin >> name;

    cout << "Choose your character class :" << endl;
    for (int i = 0; i < CLASSPLAYER_SIZE; i++) {
        cout << i + 1 << ": " << classPlayer2[i] << endl;
    }
    cin >> choiceClass;
    choiceClass --;
    //cout << "Your character is : " << classPlayer2[choiceClass] << endl; (optional code)

    cout << "Choose your character race :" << endl;
    for (int i = 0; i < RACE_SIZE; i++) {
        cout << i+1 << ": " << Race[i] << endl;
    }
    cin >> choiceRace;
    choiceRace--;


    cout << "Choose your character race options : ";
    switch (choiceRace)
    {
    case 0:
        cout << "Choose your sub-Race :\n1. Standart human\n2. Human variant" << endl;
        cin >> choiceSubRace;
        choiceSubRace--;
        if (choiceSubRace == 1) {
            cout << "Choose your plus to your characteristic :" << endl;
            cout << "How did you want to distribute points?\n1. STR\n2. DEX\n3. CON\n4. INT\n5. WIS\n6. CHA\n";
            cin >> SpecialPlus[choice];
            SpecialPlus[choice] ++;
            cout << "Choose your plus to your characteristic (cant be same):" << endl;
            cout << "How did you want to distribute points?\n1. STR\n2. DEX\n3. CON\n4. INT\n5. WIS\n6. CHA\n";
            cin >> SpecialPlus[choice];
            SpecialPlus[choice] ++;
        }
        break;
    case 1:
        cout << "Choose your plus to your characteristic :" << endl;
        cout << "How did you want to distribute points?\n1. STR\n2. DEX\n3. CON\n4. INT\n5. WIS\n";
        cin >> SpecialPlus[choice];
        SpecialPlus[choice] ++;
        cout << "Choose your plus to your characteristic (cant be same):" << endl;
        cout << "How did you want to distribute points?\n1. STR\n2. DEX\n3. CON\n4. INT\n5. WIS\n";
        cin >> SpecialPlus[choice];
        SpecialPlus[choice] ++;
        break;
    case 2 :
        cout << "No options" << endl;
        choiceSubRace = 4;
        break;
    case 3 :
        cout << "Choose your sub-Race :\n1. Mountain dwarf\n2. Hill dwarf" << endl;
        cin >> choiceSubRace;
        choiceSubRace += 3;
        break;
    case 4 :
        cout << "Choose your sub-Race :\n1. Forest gnome\n2. Rock gnome" << endl;
        cin >> choiceSubRace;
        choiceSubRace += 5;
        break;
    case 5 :
        cout << "Choose your sub-Race :\n1. High elf\n2. Wood elf\n3. Drow" << endl;
        cin >> choiceSubRace;
        choiceSubRace += 7;
        break;
    case 6 :
        cout << "No options" << endl;
        choiceSubRace = 11;
        break;
    case 7 :
        cout << "Choose your sub-Race :\n1. Light-foot Halfling\n2. Stout halfling" << endl;
        cin >> choiceSubRace;
        choiceSubRace += 11;
        break;
    case 8 :
        cout << "No options" << endl;
        choiceSubRace = 14;
        break;
    default:
        break;
    }

    cout << "How did you want to distribute points?\n1. STR\n2. DEX\n3. CON\n4. INT\n5. WIS\n6. CHA\n" ;

    while (points > 0) {
        cin >> choice;
        choice = choice - 1;
        cout << "How much points?";
        cin >> choiceCount;

        for (int i = 1; i <= choiceCount; i++) {
            if (stats[choice] <= 12) {
                stats[choice]++;
                points--;
                cout << "added 1 pont to " << statsNames[choice] << ". Now " << statsNames[choice] << ": " << stats[choice] << endl;
            }
            else if (stats[choice] <= MAX_POINTS) {
                stats[choice]++;
                points -= 2;
                cout << "added 1 pont to " << statsNames[choice] << ". Now " << statsNames[choice] << ": !!!" << stats[choice] << endl;
            }
            else {
                cout << "MAX " << statsNames[choice] << endl;
            }
        }
        for (int i = 0; i < STATS_SIZE; i++) {
            cout << statsNames[i] << ":" << stats[i] << " ";
        }
        cout << "Points :" << points << endl;
    }

    for (int i = 0; i < STATS_SIZE; i++) {
        stats[i] += add_stats[i];
    }

    for (int i = 0; i < STATS_SIZE; i++) {
        stats[i] += race_bonus[choiceSubRace - 1][i];
    }

    cout << name << endl << classPlayer2[choiceClass] << endl << SubRace[choiceSubRace] << endl;
    cout << "STR: " << stats[0] << " DEX: " << stats[1] << " CON: " << stats[2] << " INT: " << stats[3] << " WIS: " << stats[4] << " CHA: " << stats[5] << endl;
// Diego loves Dnd

}
