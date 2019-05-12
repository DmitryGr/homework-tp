Artillery::Artillery(){
    is_tank = false;
    x = 0;
    y = rand()%(FIELD+1);
    lives = LIVES_DEFAULT;
    gun_power = ARTILLERY_DEFAULT;
    square = DEFAULT_SQUARE;
    dispersion = ARTILLERY_DISPERSION_FUNCTION;
    ticks_to_next_shoot=0;
}
void Artillery::shoot(Visitor *v){
    v->shootArt(this);
}
void Artillery::go(){
    assert(0);
}
Artillery* Artillery::clone() const{
    return new Artillery(*this);
}
