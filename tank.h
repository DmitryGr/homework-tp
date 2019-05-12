class Tank : public Unit{
    friend bool operator !=(const Tank& a, const Tank& b);
    public:
        int lives;
        int speed;
        int gun_power;
        double deviation_percent;
        int ticks_to_next_shoot;
        Tank();
        void go();
        void shoot(Visitor *v);
        Tank* clone() const;
};
