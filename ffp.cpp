FixedFirePoint::FixedFirePoint(){
    is_tank = false;
    projectile_reserve=5;
    ticks_to_next_shoot=0;
    ticks_to_next_supply = 20;
}

void FixedFirePoint::go(){
    assert(1);
}
void FixedFirePoint::shoot(Visitor *v, Observer *obs){
    v->shootFfp(this, obs);
}
FixedFirePoint* FixedFirePoint::clone() const{
    return new FixedFirePoint(*this);
}

