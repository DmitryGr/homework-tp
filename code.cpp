const int FIELD = 150, SOVIET_SOLDIERS=20, GERMAN_SOLDIERS=16, SOVIET_TANKS=8, GERMAN_TANKS=12, ARTILLERY=4, ZONE=10;
const int LIVES_DEFAULT = 50, GUN_DEFAULT = 5, TANK_DEFAULT = 10, ARTILLERY_DEFAULT=20;
const double GUN_DEVIAFION_DEFAULT = 0.03, ARTILLERY_DISPERSION_FUNCTION = 0.03, DEFAULT_SQUARE = 1;
const int TANK_DURATION = 2, ARTILLERY_DURATION = 10;
const int GROUPS_IN_ARMY = 4;
const int UP=0, LEFT=1, RIGHT=2, DOWN=3;
const int SOVIET=0, GERMANY=1;
const int INF = 1e9;
using namespace std;

#include <bits/stdc++.h>
#include "visitor.h"
#include "unit.h"
#include "infantry.h"
#include "tank.h"
#include "artillery.h"
#include "ffp.h"
#include "visitor.cpp"
#include "infantry.cpp"
#include "tank.cpp"
#include "ffp.cpp"
#include "artillery.cpp"
class Army{
    friend bool operator ==(const Army& a, const Army& b);
    private:
        vector<Infantry*> infantry;
        vector<Tank*> tanks;
        vector<Artillery*> artillery;
        vector<FixedFirePoint*> ffp;
    public:
        //vector<Artillery*> artillery;
        void action(){

        }
        vector<Infantry*> get_infantry(){
            return infantry;
        }
        vector<Tank*> get_tanks(){
            return tanks;
        }
        vector<Artillery*> get_artillery(){
            return artillery;
        }
        vector<FixedFirePoint*> get_ffp(){
            return ffp;
        }
        void add_soldiers(vector<Infantry*> added){
            for (auto soldier: added){
                infantry.push_back(soldier);
            }
        }
        void add_tank(vector<Tank*> added){
            for (auto tank: added){
                tanks.push_back(tank);
            }
        }
        void add_artillery(vector<Artillery*> added){
            for (auto artillery_unit: added){
                artillery.push_back(artillery_unit);
            }
        }
        ~Army(){
            infantry.clear();
            tanks.clear();
            artillery.clear();
            ffp.clear();
        }
};

class Observer{
    public:
        vector<Unit*> soviet_subscribers;
        vector<Unit*> german_subscribers;
        vector<Unit*> closest_to_soviet;
        vector<Unit*> closest_to_german;
        void add_unit(Unit* unit, bool if_soviet){
            if (if_soviet == SOVIET){
                soviet_subscribers.push_back(unit);
                closest_to_soviet.push_back(nullptr);
            }
            else{
                german_subscribers.push_back(unit);
                closest_to_german.push_back(nullptr);
            }
        }
        void remove_unit(Unit* unit, bool if_soviet){
            if (if_soviet == SOVIET){
                remove_from_vector(soviet_subscribers, closest_to_german, unit);
            }
            else remove_from_vector(german_subscribers, closest_to_soviet, unit);
        }
        void recalc_distances(){
            for (int i=0; i < soviet_subscribers.size(); i++){
                int shortest_dist=INF;
                Unit* target = nullptr;
                for (int j=0; j < german_subscribers.size(); j++){
                    int distance = get_dist(soviet_subscribers[i], german_subscribers[j]);
                    if (distance < shortest_dist){
                        shortest_dist = distance;
                        target = german_subscribers[j];
                    }
                }
                closest_to_soviet[i] = target;
            }
            for (int i=0; i < german_subscribers.size(); i++){
                int shortest_dist=INF;
                Unit* target = nullptr;
                for (int j=0; j < soviet_subscribers.size(); j++){
                    int distance = get_dist(soviet_subscribers[j], german_subscribers[i]);
                    if (distance < shortest_dist){
                        shortest_dist = distance;
                        target = soviet_subscribers[j];
                    }
                }
                closest_to_german[i] = target;
            }
        }
        int get_dist(Unit* a, Unit* b){
            return abs(a->x-b->x) + abs(a->y-b->y);
        }
        ~Observer(){
            soviet_subscribers.clear();
            german_subscribers.clear();
            closest_to_german.clear();
            closest_to_soviet.clear();
        }
    private:
        void remove_from_vector(vector<Unit*> &line, vector<Unit*> closest, Unit* unit){
            vector<Unit*> new_vector, new_closest;
            for (int i=0; i < line.size(); i++){
                if (line[i] != unit){
                    new_vector.push_back(line[i]);
                    new_closest.push_back(closest[i]);
                }
            }
            line = new_vector, closest = new_closest;
            new_vector.clear(), new_closest.clear();
        }
};

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


class Subdivision{
    private:
        vector<Subdivision*> subordinated_subdivisions;
        vector<Unit*> subordinated_units;
        vector<Tank*> subordinated_tanks_only;

    public:
        Subdivision(Army* army){
            vector<Infantry*> infantry = army->get_infantry();
            vector<Tank*> tanks = army->get_tanks();
            vector<Artillery*> artillery = army->get_artillery();
            vector<FixedFirePoint*> ffp = army->get_ffp();
            for (int i=0; i < infantry.size(); i++) subordinated_units.push_back(infantry[i]);
            for (int i=0; i < artillery.size(); i++) subordinated_units.push_back(artillery[i]);
            for (int i=0; i < ffp.size(); i++) subordinated_units.push_back(ffp[i]);
            for (int i=0; i < tanks.size(); i++){
                subordinated_units.push_back(tanks[i]);
                subordinated_tanks_only.push_back(tanks[i]);
            }
        }
        Subdivision(){

        }
        void add_unit(Unit* unit){
            subordinated_units.push_back(unit);
        }

        void add_tank(Tank* unit){
            subordinated_units.push_back(unit);
            subordinated_tanks_only.push_back(unit);
        }

        void add_subdivision(Subdivision* subdivision){
            subordinated_subdivisions.push_back(subdivision);
        }

        void remove_unit(Unit* unit){
            vector<Unit*> new_units_list;
            for (auto element: subordinated_units){
                if (element != unit) new_units_list.push_back(element);
            }
            subordinated_units = new_units_list;
        }

        void remove_tank(Tank* unit){
            remove_unit(unit);
            vector<Tank*> new_tanks_list;
            for (auto element: subordinated_tanks_only){
                if (element != unit) new_tanks_list.push_back(element);
            }
            subordinated_tanks_only = new_tanks_list;
        }

        void remove_subdivision(Subdivision* subdivision){
            vector<Subdivision*> new_subd_list;
            for (auto element: subordinated_subdivisions){
                if (element != subdivision) new_subd_list.push_back(element);
            }
            subordinated_subdivisions = new_subd_list;
        }

        void shoot_all(){
            for (auto subd: subordinated_subdivisions){
                subd->shoot_all();
            }
            for (auto unit: subordinated_units){
                Visitor* v = new Visitor();
                unit->shoot(v);
            }
        }

        void go_all(){
            for (auto subd: subordinated_subdivisions){
                subd->go_all();
            }
            for (auto unit: subordinated_units){
                unit->go();
            }
        }

        void transform_all_tanks(){
            for (auto subd: subordinated_subdivisions){
                subd->transform_all_tanks();
            }
            vector<Unit*> new_units_list;
            vector<Tank*> new_tanks_list;
            for (auto unit: subordinated_units){
                if (unit->is_tank){
                    continue;
                }
                else new_units_list.push_back(unit);
            }
            for (auto tank: subordinated_tanks_only){
                if (tank->lives > 0){
                    new_tanks_list.push_back(tank);
                    new_units_list.push_back(tank);
                }
                else{
                    TankAdapter* adapter = new TankAdapter(tank);
                    new_units_list.push_back(adapter->transform_to_ffp());
                }
            }
            subordinated_units = new_units_list;
            subordinated_tanks_only = new_tanks_list;
        }
        ~Subdivision(){
            subordinated_subdivisions.clear();
            subordinated_tanks_only.clear();
            subordinated_units.clear();
        }
};

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
    return 0;
}

