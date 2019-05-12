Infantry::Infantry(){
    x = rand()%ZONE + 1;
    y = rand()%(FIELD+1);
    is_tank = false;
    lives = LIVES_DEFAULT;
    gun_power = GUN_DEFAULT;
    gun_deviation_percent = GUN_DEVIAFION_DEFAULT;
}

void Infantry::go(){

}

void Infantry::shoot(Visitor *v){
    v->shootSoldier(this);
}

Infantry* Infantry::clone() const{
    return new Infantry(*this);
}
