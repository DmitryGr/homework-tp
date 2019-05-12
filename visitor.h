class Infantry;
class Tank;
class Artillery;
class FixedFirePoint;

class Visitor{
    public:
        void shootSoldier(Infantry* soldier);
        void shootTank(Tank* tank);
        void shootArt(Artillery* art);
        void shootFfp(FixedFirePoint* ffp);
};
