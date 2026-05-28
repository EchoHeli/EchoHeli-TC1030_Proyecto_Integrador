#include <iostream>

using namespace std;

class Character{
    protected:
        string characterName;
        int characterStocks;
        int characterPercentage;
        bool isAirborne;
        bool isShielding;
    public:
        Character(string name){
            characterName = name;
            characterStocks = 4;
            characterPercentage = 0;
            isAirborne = false;
            isShielding = false;
        }
        void jump(){
            isAirborne = true;
        }
        virtual void attack(string MoveName, Character &target){
            cout << characterName << " used " << MoveName << " on " << target.getName() << endl;
        }
        virtual void specialAttack(string MoveName, Character &target){
            cout << characterName << " used " << MoveName << " on " << target.getName() << endl;
        }
        virtual void shield(){
            isShielding = true;
            cout << characterName << "shielded" << endl;
        }
        virtual void grab(Character &target){
            cout << characterName << " grabbed " << target.getName() << endl;
        }
        void selectCharacter(string name){
            characterName = name;
        }
        string getName(){
            return characterName;
        }
};
class Move {
    private:  
        string moveName;
        int damage;
        int baseKnockback;
        int knockbackScaling;
        int angle;
        int startupFrames;
    public:
        Move(string name, int dmg, int baseKB, int kbScaling, int ang, int startup){
            moveName = name;
            damage = dmg;
            baseKnockback = baseKB;
            knockbackScaling = kbScaling;
            angle = ang;
            startupFrames = startup;
        }
        virtual void doMove(){
            cout << "Performing move: " << moveName << endl;
        }
        string getMoveName(){
            return moveName;
        }
        int getDamage(){
            return damage;
        }
        int getBaseKnockback(){
            return baseKnockback;
        }
        int getKnockbackScaling(){
            return knockbackScaling;
        }
        int getAngle(){
            return angle;
        }
        int getStartupFrames(){
            return startupFrames;
        }
};

class Moveset {
    private:
        Move* moves[20];
    public:
        void addMove(Move* move, int index){
            if(index >= 0 && index < 20){
                moves[index] = move;
            }
        }
        Move* getMove(int index){
            if(index >= 0 && index < 20){
                return moves[index];
            }
            return nullptr;
        }
};

class Luigi : public Character {
    private:
        Moveset luigiMoveset;
        int greenMissleCharge;
        const double misfireProbability = 0.125;
    public:
        Luigi() : Character("Luigi") {
            luigiMoveset.addMove(new Move("Forward tilt", 10, 2, 100, 45, 3), 0);
            luigiMoveset.addMove(new Move("Up tilt", 9, 30, 127,100,3), 1);
            luigiMoveset.addMove(new Move("Down tilt",9,10,80,80,4), 2);
            luigiMoveset.addMove(new Move("Forward smash",13,20,135,65,11), 3);
            luigiMoveset.addMove(new Move("Up smash",17,35,98,110,8), 4);
            luigiMoveset.addMove(new Move("Down smash",17,40,80,90,4), 5);
            luigiMoveset.addMove(new Move("Neutral aerial", 15, 20, 100, 90, 2), 6);
            luigiMoveset.addMove(new Move("Forward aerial", 12, 43, 100, 45, 6), 7);
            luigiMoveset.addMove(new Move("Back aerial", 11, 12, 100, 45, 5), 8);
            luigiMoveset.addMove(new Move("Up aerial", 13, 0, 100, 55, 4), 9);
            luigiMoveset.addMove(new Move("Down aerial", 16, 20, 100, 45, 9), 10);
            luigiMoveset.addMove(new Move("Neutral special", 6, 5, 25, 45, 16), 11);
            luigiMoveset.addMove(new Move("Side special", 10, 20, 80, 45, 21), 12);
            luigiMoveset.addMove(new Move("Misfire", 25, 20, 80, 45, 21), 13);
            luigiMoveset.addMove(new Move("Up special", 25, 70, 73, 90, 4),14);
            luigiMoveset.addMove(new Move("Down special", 8, 50, 80, 90, 5),15);
        }
        void attack(string MoveName, Character &target) override {
            cout << characterName << " used " << MoveName << " on " << target.getName() << endl;
        }
        void specialAttack(string MoveName, Character &target) override {
            cout << characterName << " used " << MoveName << " on " << target.getName() << endl;
        }
        bool calculateMisfire() {
            double randomValue = static_cast<double>(rand()) / RAND_MAX;
            return randomValue < misfireProbability;
        }
};

class DonkeyKong : public Character {
    private:
        Moveset dkMoveset;
        int giantPunchCharge;
    public:
        DonkeyKong() : Character("Donkey Kong") {
            dkMoveset.addMove(new Move("Forward tilt", 12, 10, 100, 45, 4), 0);
            dkMoveset.addMove(new Move("Up tilt", 11, 20, 127,100,4), 1);
            dkMoveset.addMove(new Move("Down tilt",10,15,80,80,5), 2);
            dkMoveset.addMove(new Move("Forward smash",15,30,135,65,12), 3);
            dkMoveset.addMove(new Move("Up smash",18,40,98,110,9), 4);
            dkMoveset.addMove(new Move("Down smash",17,35,80,90,5), 5);
            dkMoveset.addMove(new Move("Neutral aerial", 14, 25, 100, 90, 3), 6);
            dkMoveset.addMove(new Move("Forward aerial", 13, 50, 100, 45, 7), 7);
            dkMoveset.addMove(new Move("Back aerial", 12, 15, 100, 45, 6), 8);
            dkMoveset.addMove(new Move("Up aerial", 14, 5, 100, 55, 5), 9);
            dkMoveset.addMove(new Move("Down aerial", 17, 30, 100, 45,10),10);
            dkMoveset.addMove(new Move("Neutral special",8 ,10 ,25 ,45 ,18),11);
            dkMoveset.addMove(new Move("Side special",14 ,25 ,80 ,45 ,22),12);
            dkMoveset.addMove(new Move("Up special",20 ,60 ,73 ,90 ,5),13);
            dkMoveset.addMove(new Move("Down special",10 ,40 ,80 ,90 ,6),14);
        }
        void attack(string MoveName, Character &target) override {
            cout << characterName << " used " << MoveName << " on " << target.getName() << endl;
        }
        void specialAttack(string MoveName, Character &target) override {
            cout << characterName << " used " << MoveName << " on " << target.getName() << endl;
        }
};