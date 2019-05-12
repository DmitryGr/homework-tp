FixedFirePoint::FixedFirePoint(){
    is_tank = false;
    projectile_reserve=5;
    ticks_to_next_shoot=0;
    ticks_to_next_supply = 20;
}

void FixedFirePoint::go(){
    assert(0);
}
void FixedFirePoint::shoot(Visitor *v){
    v->shootFfp(this);
}
FixedFirePoint* FixedFirePoint::clone() const{
    return new FixedFirePoint(*this);
}

