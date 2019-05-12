class Unit{
    public:
        int x;
        int y;
        bool is_tank;
        virtual void go() = 0;
        virtual void shoot(Visitor* v) = 0;
        virtual Unit* clone() const = 0;
};
