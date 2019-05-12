Tank::Tank(){
    x = rand()%ZONE + 1;
    y = rand()%(FIELD+1);
    lives = LIVES_DEFAULT;
    gun_power = TANK_DEFAULT;
    deviation_percent = GUN_DEVIAFION_DEFAULT*2.;
    ticks_to_next_shoot=0;
}
void Tank::go(){};
void Tank::shoot(Visitor *v){
    v->shootTank(this);
}
Tank* Tank::clone() const{
    return new Tank(*this);
}
