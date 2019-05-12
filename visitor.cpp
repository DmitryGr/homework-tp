void Visitor::shootSoldier(Infantry *soldier, Observer* obs){
    Unit* opponent_unit = obs->get_closest(soldier);
    if (opponent_unit == nullptr) return;
}

void Visitor::shootTank(Tank *tank, Observer* obs){
    Unit* opponent_unit = obs->get_closest(tank);
    if (opponent_unit == nullptr) return;
}

void Visitor::shootArt(Artillery* art, Observer* obs){
    Unit* opponent_unit = obs->get_closest(art);
    if (opponent_unit == nullptr) return;
}

void Visitor::shootFfp(FixedFirePoint* ffp, Observer* obs){
    Unit* opponent_unit = obs->get_closest(ffp);
    if (opponent_unit == nullptr) return;
}
