#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "code.cpp"
using namespace std;
const bool SOVIET = true, GERMAN = false;
Army* hand_create(bool if_soviet){
    if (if_soviet){
        Army* army = new Army();
        vector<Infantry*> inf;
        for (int i=0; i < SOVIET_SOLDIERS; i++){
            inf.push_back(new Infantry());
        }
        army->add_soldiers(inf);
        vector<Tank*> tnk;
        for (int i=0; i < SOVIET_TANKS; i++){
            tnk.push_back(new Tank());
        }
        army->add_tank(tnk);
        vector<Artillery*> art;
        for (int i=0; i < ARTILLERY; i++){
            art.push_back(new Artillery());
        }
        army->add_artillery(art);
        return army;
    }
    else{
        Army* army = new Army();
        vector<Infantry*> inf;
        for (int i=0; i < GERMAN_SOLDIERS; i++){
            inf.push_back(new Infantry());
        }
        army->add_soldiers(inf);
        vector<Tank*> tnk;
        for (int i=0; i < GERMAN_TANKS; i++){
            tnk.push_back(new Tank());
        }
        army->add_tank(tnk);
        vector<Artillery*> art;
        for (int i=0; i < ARTILLERY; i++){
            art.push_back(new Artillery());
        }
        army->add_artillery(art);
        return army;
    }
}

::testing::AssertionResult IsEqual (Army* a, Army* b)
{
	if ((*a) == (*b))
		return ::testing::AssertionSuccess();
	else
		return ::testing::AssertionFailure();
}

::testing::AssertionResult IsEqual (vector<Infantry*> a, vector<Infantry*> b)
{
	if (a==b)
		return ::testing::AssertionSuccess();
	else
		return ::testing::AssertionFailure();
}

::testing::AssertionResult IsEqual (vector<Tank*> a, vector<Tank*> b)
{
	if (a==b)
		return ::testing::AssertionSuccess();
	else
		return ::testing::AssertionFailure();
}

::testing::AssertionResult IsEqual (vector<Artillery*> a, vector<Artillery*> b)
{
	if (a==b)
		return ::testing::AssertionSuccess();
	else
		return ::testing::AssertionFailure();
}


TEST(Test, SA)
{
    Game game;
    SovietArmyFactory s_factory;
    EXPECT_TRUE(IsEqual(game.create_army(s_factory), hand_create(SOVIET)));
}

TEST(Test, GA)
{
    Game game;
    GermanArmyFactory g_factory;
    EXPECT_TRUE(IsEqual(game.create_army(g_factory), hand_create(GERMAN)));
}

TEST(Test, ADD_SOLDIER){
    Army* army = new Army();
    vector<Infantry*> inf;
    Infantry* soldier = new Infantry();
    inf.push_back(soldier);
    army->add_soldiers(inf);
    vector<Infantry*> v = {soldier};
    EXPECT_TRUE(IsEqual(v, army->get_soldiers()));
}

TEST(Test, ADD_TANK){
    Army* army = new Army();
    vector<Tank*> tanks;
    Tank* tank = new Tank();
    tanks.push_back(tank);
    army->add_tank(tanks);
    vector<Tank*> v = {tank};
    EXPECT_TRUE(IsEqual(v, army->get_tanks()));
}

TEST(Test, ADD_ARTILLERY){
    Army* army = new Army();
    vector<Artillery*> art;
    Artillery* gun = new Artillery();
    art.push_back(gun);
    army->add_artillery(art);
    vector<Artillery*> v = {gun};
    EXPECT_TRUE(IsEqual(v, army->get_artillery()));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
