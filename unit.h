class Unit{
    public:
        int x;
        int y;
        bool is_tank;
        virtual void go() = 0;
        virtual void shoot(Visitor* v, Observer *obs) = 0;
        virtual Unit* clone() const = 0;
        virtual bool out_of_field(int new_x, int new_y){
            if (new_x < 0 || new_x >= FIELD || new_y < 0 || new_y >= FIELD) return true;
            return false;
        }
};
