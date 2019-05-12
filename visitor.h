class Infantry;
class Tank;
class Artillery;
class FixedFirePoint;
class Observer;

class Visitor{
    public:
        void shootSoldier(Infantry* soldier, Observer* obs);
        void shootTank(Tank* tank, Observer* obs);
        void shootArt(Artillery* art, Observer* obs);
        void shootFfp(FixedFirePoint* ffp, Observer* obs);
};
