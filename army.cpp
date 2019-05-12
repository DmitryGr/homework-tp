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
