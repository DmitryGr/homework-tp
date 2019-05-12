class Artillery: public Unit{
    friend bool operator !=(const Artillery& a, const Artillery& b);
    public:
        int lives;
        int gun_power;
        double dispersion;
        double square;
        int ticks_to_next_shoot;
        Artillery();
        void shoot(Visitor *v, Observer *obs);
        void go();
        Artillery* clone() const;
};
