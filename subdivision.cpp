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

        void shoot_all(Observer *obs){
            for (auto subd: subordinated_subdivisions){
                subd->shoot_all(obs);
            }
            for (auto unit: subordinated_units){
                Visitor* v = new Visitor();
                unit->shoot(v, obs);
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
        void divide(){
            vector<int> division_order;
            for (int i=0; i < subordinated_units.size(); i++) division_order.push_back(i);
            random_shuffle(division_order.begin(), division_order.end());
            if (division_order.size() < GROUPS_IN_ARMY){
                return;
            }
            for (int i=0; i < GROUPS_IN_ARMY;i++) subordinated_subdivisions.push_back(new Subdivision());
            for (int i=0; i < division_order.size(); i++){
                int index = division_order[i];
                if (index + subordinated_tanks_only.size() < division_order.size()){
                    Unit* unit = subordinated_units[index];
                    subordinated_subdivisions[index%GROUPS_IN_ARMY]->add_unit(unit);
                }
            }
            for (int i=0; i < division_order.size(); i++){
                int index = division_order[i];
                if (index + subordinated_tanks_only.size() >= division_order.size()){
                    int index = division_order[i];
                    int other_size = division_order.size() - subordinated_tanks_only.size();
                    Tank* tank = subordinated_tanks_only[index - other_size];
                    subordinated_subdivisions[index%GROUPS_IN_ARMY]->add_tank(tank);
                }
            }
            subordinated_units.clear();
            subordinated_tanks_only.clear();
            for (int i=0;i<subordinated_subdivisions.size();i++) subordinated_subdivisions[i]->divide();
        }
        vector<Unit*> get_all_units(){
            vector<Unit*> result = subordinated_units;
            for (auto subdivision: subordinated_subdivisions){
                vector<Unit*> there = subdivision->get_all_units();
                for (auto element:there) result.push_back(element);
                there.clear();
            }
            return result;
        }
        bool if_battle_lost(){
            if (subordinated_units.size() > 0) return false;
            bool result = false;
            for (auto subdivision: subordinated_subdivisions){
                result |= subdivision->if_battle_lost();
            }
            return result;
        }
        ~Subdivision(){
            subordinated_subdivisions.clear();
            subordinated_tanks_only.clear();
            subordinated_units.clear();
        }
};
