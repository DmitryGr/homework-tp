Tank::Tank(){
    x = rand()%ZONE + 1;
    y = rand()%(FIELD+1);
    lives = LIVES_DEFAULT;
    gun_power = TANK_DEFAULT;
    deviation_percent = GUN_DEVIAFION_DEFAULT*2.;
    ticks_to_next_shoot=0;
}
void Tank::go(){
    int R = rand() % DIRECTIONS.size();
    pair<int, int> mv = DIRECTIONS[R];
    int new_x = x+TANK_SPEED*mv.first, new_y = y+TANK_SPEED*mv.second;
    if (!out_of_field(new_x, new_y)){
        x = new_x;
        y = new_y;
    }
}
void Tank::shoot(Visitor *v, Observer *obs){
    v->shootTank(this, obs);
}
Tank* Tank::clone() const{
    return new Tank(*this);
}
