Infantry::Infantry(){
    x = rand()%ZONE + 1;
    y = rand()%(FIELD+1);
    is_tank = false;
    lives = LIVES_DEFAULT;
    gun_power = GUN_DEFAULT;
    gun_deviation_percent = GUN_DEVIAFION_DEFAULT;
}

void Infantry::go(){
    int R = rand() % DIRECTIONS.size();
    pair<int, int> mv = DIRECTIONS[R];
    int new_x = x+mv.first, new_y = y+mv.second;
    if (!out_of_field(new_x, new_y)){
        x = new_x;
        y = new_y;
    }
}

void Infantry::shoot(Visitor *v, Observer *obs){
    v->shootSoldier(this, obs);
}

Infantry* Infantry::clone() const{
    return new Infantry(*this);
}
