class FixedFirePoint: public Unit{
    public:
        int gun_power;
        int projectile_reserve;
        double deviation_percent;
        int ticks_to_next_supply;
        int ticks_to_next_shoot;
        FixedFirePoint();
        void go();
        void shoot(Visitor *v);
        FixedFirePoint* clone() const;
};
