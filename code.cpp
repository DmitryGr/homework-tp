const int FIELD = 150, SOVIET_SOLDIERS=20, GERMAN_SOLDIERS=16, SOVIET_TANKS=8, GERMAN_TANKS=12, ARTILLERY=4, ZONE=10;
const int LIVES_DEFAULT = 50, GUN_DEFAULT = 5, TANK_DEFAULT = 10, ARTILLERY_DEFAULT=20, TANK_SPEED=2;
const double GUN_DEVIAFION_DEFAULT = 0.03, ARTILLERY_DISPERSION_FUNCTION = 0.03, DEFAULT_SQUARE = 1;
const int TANK_DURATION = 2, ARTILLERY_DURATION = 10;
const int GROUPS_IN_ARMY = 4;
const int UP=0, LEFT=1, RIGHT=2, DOWN=3;
const int SOVIET=1, GERMANY=0;
const int INF = 1e9;
using namespace std;
#include <bits/stdc++.h>
std::vector<pair<int, int> > DIRECTIONS = {{0,1}, {1,0}, {-1,0}, {0,-1}};
#include "visitor.h"
#include "unit.h"
#include "observer.cpp"
#include "infantry.h"
#include "tank.h"
#include "artillery.h"
#include "ffp.h"
#include "infantry.cpp"
#include "tank.cpp"
#include "ffp.cpp"
#include "artillery.cpp"
#include "army.cpp"
#include "visitor.cpp"
bool operator !=(const Infantry& a, const Infantry& b){
    if (a.lives != b.lives || a.gun_deviation_percent != b.gun_deviation_percent || a.gun_power != b.gun_power) return true;
    return false;
}

bool operator !=(const Tank& a, const Tank& b){
    if (a.lives != b.lives || a.deviation_percent != b.deviation_percent || a.gun_power != b.gun_power || a.ticks_to_next_shoot != b.ticks_to_next_shoot) return true;
    return false;
}

bool operator !=(const Artillery& a, const Artillery& b){
    if (a.lives != b.lives || a.dispersion != b.dispersion || a.square!=b.square || a.gun_power != b.gun_power || a.ticks_to_next_shoot != b.ticks_to_next_shoot) return true;
    return false;
}

bool operator ==(const Army& a, const Army& b)
{
    if (a.infantry.size() != b.infantry.size() || a.tanks.size() != b.tanks.size() || a.artillery.size() != b.artillery.size()) return false;
    vector<Infantry*> inf_a, inf_b;
    for (auto unit : a.infantry) inf_a.push_back(unit);
    for (auto unit : b.infantry) inf_b.push_back(unit);
    for (int i=0; i < inf_a.size(); i++){
        if ((*inf_a[i]) != (*inf_b[i])) return false;
    }
    vector<Tank*> tank_a, tank_b;
    for (auto unit : a.tanks) tank_a.push_back(unit);
    for (auto unit : b.tanks) tank_b.push_back(unit);
    for (int i=0; i < tank_a.size(); i++){
        if ((*tank_a[i]) != (*tank_b[i])) return false;
    }
    vector<Artillery*> art_a, art_b;
    for (auto unit : a.artillery) art_a.push_back(unit);
    for (auto unit : b.artillery) art_b.push_back(unit);
    for (int i=0; i < art_a.size(); i++){
        if ((*art_a[i]) != (*art_b[i])) return false;
    }
    return true;
}

class ArmyFactory{
    public:
        virtual vector<Infantry*> create_infantry() = 0;
        virtual vector<Tank*> create_tanks() = 0;
        virtual vector<Artillery*> create_artillery() = 0;
        //virtual ~ArmyFactory() = 0;
};

class SovietArmyFactory : public ArmyFactory{
    public:
        vector<Infantry*> create_infantry(){
            vector<Infantry*> arr;
            for (int i=0; i < SOVIET_SOLDIERS; i++){
                arr.push_back(new Infantry());
            }
            return arr;
        }
        vector<Tank*> create_tanks(){
            vector<Tank*> arr;
            for (int i=0; i < SOVIET_TANKS; i++){
                arr.push_back(new Tank());
            }
            return arr;
        }
        vector<Artillery*> create_artillery(){
            vector<Artillery*> arr;
            for (int i=0; i < ARTILLERY; i++){
                arr.push_back(new Artillery());
            }
            return arr;
        }
};

class GermanArmyFactory : public ArmyFactory{
    public:
        vector<Infantry*> create_infantry(){
            vector<Infantry*> arr;
            for (int i=0; i < GERMAN_SOLDIERS; i++){
                arr.push_back(new Infantry());
                arr.back()->x = FIELD-arr.back()->x;
            }
            return arr;
        }
        vector<Tank*> create_tanks(){
            vector<Tank*> arr;
            for (int i=0; i < GERMAN_TANKS; i++){
                arr.push_back(new Tank());
                arr.back()->x = FIELD-arr.back()->x;
            }
            return arr;
        }
        vector<Artillery*> create_artillery(){
            vector<Artillery*> arr;
            for (int i=0; i < ARTILLERY; i++){
                arr.push_back(new Artillery());
                arr.back()->x = FIELD-arr.back()->x;
            }
            return arr;
        }
};

class TankAdapter{
    private:
        Tank* destroyed_tank;
    public:
        TankAdapter(Tank* given_tank){
            destroyed_tank = given_tank;
        }
        FixedFirePoint* transform_to_ffp(){
            FixedFirePoint* ffp = new FixedFirePoint();
            ffp->x = destroyed_tank->x;
            ffp->y = destroyed_tank->y;
            ffp->gun_power = destroyed_tank->gun_power / 2.;
            ffp->deviation_percent = destroyed_tank->deviation_percent / 2.;
            return ffp;
        }
};

#include "subdivision.cpp"

class Game{
    public:
        Army* create_army(ArmyFactory &factory){
            Army* new_army = new Army();
            new_army->add_soldiers(factory.create_infantry());
            new_army->add_tank(factory.create_tanks());
            new_army->add_artillery(factory.create_artillery());
            return new_army;
        }
};

int run(){
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    cout << "Armies are created" << endl;
    Subdivision* whole_soviet_army = new Subdivision(soviet_army);
    Subdivision* whole_german_army = new Subdivision(german_army);
    whole_soviet_army->divide(), whole_german_army->divide();
    cout << "Armies are divided and ready to battle" << endl;
    Observer* global_observer = new Observer();
    vector<Unit*> all_soviet = whole_soviet_army->get_all_units(), all_german = whole_german_army->get_all_units();
    for (auto unit: all_soviet){
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german){
        global_observer->add_unit(unit, GERMANY);
    }
    while (true){
        string mv;
        cin >> mv;
        if (mv == "shoot") whole_soviet_army->shoot_all(global_observer);
        else if (mv == "go") whole_soviet_army->go_all();
        int R = rand()%2;
        if (R==0) whole_german_army->shoot_all(global_observer);
        else whole_german_army->go_all();
        if (whole_soviet_army->if_battle_lost()){
            cout << "You Lose!";
            return 0;
        }
        if (whole_german_army->if_battle_lost()){
            cout << "You Win!";
            return 0;
        }
    }
    return 0;
}

