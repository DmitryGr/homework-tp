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
        Unit* get_closest(Unit* unit){
            for (int i=0; i < soviet_subscribers.size(); i++){
                if (soviet_subscribers[i] == unit) return closest_to_soviet[i];
            }
            for (int i=0; i < soviet_subscribers.size(); i++){
                if (german_subscribers[i] == unit) return closest_to_german[i];
            }
            return nullptr;
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
