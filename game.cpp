/*********************************************************************
 ** Program Filename: game.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: main game
 ** Input: None
 ** Output: None
 *********************************************************************/

#include <iostream>
#include "advent.hpp"
#include "treasure.hpp"
#include "hero.hpp"
#include "creature.hpp"
#include "goblin.hpp"
#include "doorSpace.hpp"
#include "restSpace.hpp"
#include "enemySpace.hpp"
#include "controlSpace.hpp"
#include "treasureSpace.hpp"
#include "finalSpace.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*********************************************************************
 ** Function: victory
 ** Description: displays victory text
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void victory(){
    cout << endl << "You emerge into the blinding light of day.  The same tribunal that was so quick to toss you into the abyss is now standing around you, happy and cheering.  You made it.  You can now start your journey into the great studies of magic!" << endl;
    cout << endl <<"CONGRATULATONS!  YOU WIN!" << endl;
    return;
}

/*********************************************************************
 ** Function: failure
 ** Description: displays failure text
 ** Parameters: int
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void failure(int version){
    
    //Time runs out
    if(version == 1){
        cout << endl << "You hear the last granual of sand strike the bottom of the hourglass, like a crack of thunder.  The darkness surrounds you.  You were warned the test would have consequences for failure." << endl;
    }
    //Out of strength
    if(version == 2){
        cout << endl << "With the goblin standing over the top of you, you realize this may not have been the best choice." << endl;
    }
    
    cout << endl << "GAME OVER" << endl;
}

/*********************************************************************
 ** Function: main
 ** Description: runs program
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/

int main(){
    char entry;

    system ("clear");
    
    
    //Introduction text
    cout << endl << "WELCOME TO THE WIZARD'S TRIAL!" << endl;
    cout << "Do you have what it takes to pass the wizard's trial?" << endl;
    cout << "Let's find out!" << endl;
    
    
    cout << endl << "You stand before a tribunal of old men and women.  A older male approaches, adorned in robes.  He provides you with a map scroll and a basic wand." << endl << endl;
    cout << "The old man states this is your final trial before being accepted as an apprentice wizard.  The reward for success is great, but the penalty for failure severe.  He tells you to retrieve the four lost wizard's artifacts from the dungeon." << endl << endl <<"Out of his sleeve comes an ornate hourglass, which is placed on a table so the sand can begin to flow." << endl << "After a second, the male gestures to a well in the middle of the room.  Looking inside, you see a swirling vortex of energy some 15 or 20 feet below.  The old man gestures for you to jump in...." << endl << endl;
    cout << "Do you jump? (Y or N)" << endl;
    cin >> entry;
    
    if(entry == 'Y' || entry == 'y'){
        cout << "Pushing aside all fear, you grab your belongings tightly and make a leap of faith.  After falling for what seems like an impossible amount of time, you slowly touch down on a hard surface." << endl;
    }
    else {
        cout << "After a short pause, you feel a solid push as the old man grew impatient.  You fumble head over heels into the vortex, and quickly smack a hard surface, hearing your belongings rattle onto the floor beside you." << endl;
    }
    
    //CREATE DUNGEON
    static string treasDesc = "This room contains a treasure chest, on a pedestal.";
    static string emptyDesc = "This room is empty.";
    static string enemyDesc = "This room looks occupied and well used.  Small animal bones adorn the floor.";
    static string controDesc = "This room is empty except for a large lever in the center of the floor.";
    static string doorDesc = "This room is divided by a doorway with a large stone door.";
    static string startDesc = "The portal you arrived through lies in the ceiling of this room.";
    static string finishDesc = "The light of the staff glows as you succeed in your mission!";
    
    Space* ab = new DoorSpace("ab", doorDesc);
    Space* ae = new EnemySpace("ae", enemyDesc);
    Space* ba = new EnemySpace("ba", enemyDesc);
    Space* bb = new EnemySpace("bb", enemyDesc);
    Space* bc = new TreasureSpace("bc", treasDesc);
    Space* bd = new RestSpace("bd", emptyDesc);
    Space* be = new DoorSpace("be", doorDesc);
    Space* bf = new TreasureSpace("bf", treasDesc);
    Space* ca = new EnemySpace("ca", enemyDesc);
    Space* cb = new RestSpace("cb", startDesc);
    Space* cc = new DoorSpace("cc", doorDesc);
    Space* cd = new EnemySpace("cd", enemyDesc);
    Space* ce = new TreasureSpace("ce", treasDesc);
    Space* cf = new EnemySpace("cf", enemyDesc);
    Space* da = new TreasureSpace("da", treasDesc);
    Space* db = new EnemySpace("db", enemyDesc);
    Space* dc = new RestSpace("dc", emptyDesc);
    Space* dd = new RestSpace("dd", emptyDesc);
    Space* de = new DoorSpace("de", doorDesc);
    Space* df = new EnemySpace("df", enemyDesc);
    Space* eb = new ControlSpace("eb", controDesc, cc);
    Space* ed = new ControlSpace("ed", controDesc, de);
    Space* ef = new ControlSpace("ef", controDesc, be);
    Space* fin = new FinalSpace("fin", finishDesc);
    
    //Sets alternate pointers when doors open
    fin->setSpecial(fin, fin, fin, fin);
    cc->setSpecial(cc, cc, cd, cb);
    de->setSpecial(de, de, df, dd);
    be->setSpecial(ae, be, bf, be);
    ab->setSpecial(fin, bb, ab, ab);
    
    //Set main pointers for each room
    ab->setPath(ab, bb, ab, ab);
    ae->setPath(ae, be, ae, ae);
    ba->setPath(ba, ba, bb, ba);
    bb->setPath(ab, cb, bc, bb);
    bc->setPath(bc, bc, bc, bb);
    bd->setPath(bd, cd, bd, bd);
    be->setPath(be, be, bf, be);
    bf->setPath(bf, cf, bf, be);
    ca->setPath(ca, ca, cb, ca);
    cb->setPath(bb, db, cc, ca);
    cc->setPath(cc, cc, cc, cb);
    cd->setPath(bd, dd, ce, cc);
    ce->setPath(ce, ce, ce, cd);
    cf->setPath(bf, df, cf, cf);
    da->setPath(da, da, db, da);
    db->setPath(cb, eb, dc, da);
    dc->setPath(dc, dc, dc, db);
    dd->setPath(cd, ed, de, dd);
    de->setPath(de, de, de, dd);
    df->setPath(cf, ef, df, de);
    eb->setPath(db, eb, eb, eb);
    ed->setPath(dd, ed, ed, ed);
    ef->setPath(df, ef, ef, ef);
    
    //Sets map location for each space
    ab->setMap(0, 1);
    ae->setMap(0, 4);
    ba->setMap(1, 0);
    bb->setMap(1, 1);
    bc->setMap(1, 2);
    bd->setMap(1, 3);
    be->setMap(1, 4);
    bf->setMap(1, 5);
    ca->setMap(2, 0);
    cb->setMap(2, 1);
    cc->setMap(2, 2);
    cd->setMap(2, 3);
    ce->setMap(2, 4);
    cf->setMap(2, 5);
    da->setMap(3, 0);
    db->setMap(3, 1);
    dc->setMap(3, 2);
    dd->setMap(3, 3);
    de->setMap(3, 4);
    df->setMap(3, 5);
    eb->setMap(4, 1);
    ed->setMap(4, 3);
    ef->setMap(4, 5);
    
    //Creatures adventurer, and passing Hero creaure to specific spaces for battle
    Adventurer* user = new Adventurer(cb);
    dynamic_cast<EnemySpace*>(ae)->setHero(user->getWiz());
    dynamic_cast<EnemySpace*>(ba)->setHero(user->getWiz());
    dynamic_cast<EnemySpace*>(bb)->setHero(user->getWiz());
    dynamic_cast<EnemySpace*>(ca)->setHero(user->getWiz());
    dynamic_cast<EnemySpace*>(cd)->setHero(user->getWiz());
    dynamic_cast<EnemySpace*>(cf)->setHero(user->getWiz());
    dynamic_cast<EnemySpace*>(db)->setHero(user->getWiz());
    dynamic_cast<EnemySpace*>(df)->setHero(user->getWiz());
    
    //Four treasures created
    Treasure* robe = new Treasure("Mage's Robe", "As you don the robe, the runes lining the neck and sleeves begin sequentially to glow.  With each one, you feel your power increase!");
    Treasure* wand = new Treasure("Mage's Hat", "Upon placing the pointed hat on your head, your ability to focus magical energy dramatically increases!");
    Treasure* tome = new Treasure("Mage's Tome", "Becoming one with the tome, the knowledge of past wizards fills your mind!");
    Treasure* staff = new Treasure("Mage's Staff", "Upon wielding, the imbedded gems detach from their sockets and begin orbiting the staff, pulsing with an unknown power!");
    
    dynamic_cast<TreasureSpace*>(bc)->setTreasure(robe);
    dynamic_cast<TreasureSpace*>(bf)->setTreasure(wand);
    dynamic_cast<TreasureSpace*>(ce)->setTreasure(tome);
    dynamic_cast<TreasureSpace*>(da)->setTreasure(staff);
    
    
    //Sets starting turn count
    int turns = 50;
    
    //Loop to run game
    while(turns > 0){
        //If player dead
        if(user->getWiz()->isDead(0)){
            failure(2);
            return 0;
        }
        
        //Main display
        cout << endl << "*****************************" << endl;
        user->seeSpace();
        
        //Checks if winning
        if(user->didIWin()){
            victory();
            
            delete ab;
            delete ae;
            delete ba;
            delete bb;
            delete bc;
            delete bd;
            delete be;
            delete bf;
            delete ca;
            delete cb;
            delete cc;
            delete cd;
            delete ce;
            delete cf;
            delete da;
            delete db;
            delete dc;
            delete dd;
            delete de;
            delete df;
            delete eb;
            delete ed;
            delete ef;
            delete fin;
            
            ab = NULL;
            ae = NULL;
            ba = NULL;
            bb = NULL;
            bc = NULL;
            bd = NULL;
            be = NULL;
            bf = NULL;
            ca = NULL;
            cb = NULL;
            cc = NULL;
            cd = NULL;
            ce = NULL;
            cf = NULL;
            da = NULL;
            db = NULL;
            dc = NULL;
            dd = NULL;
            de = NULL;
            df = NULL;
            eb = NULL;
            ed = NULL;
            ef = NULL;
            fin = NULL;
            
            return 0;
        }
        
        //Shows turns left
        cout << endl << "Turns left: " << turns << endl;
        cout << endl << "*****************************" << endl;
        user->list();
        
        turns--;
        
        //If all treasure taken, final door unlocked
        if(!dynamic_cast<TreasureSpace*>(bc)->isAvail()){
            if(!dynamic_cast<TreasureSpace*>(bf)->isAvail()){
                if(!dynamic_cast<TreasureSpace*>(ce)->isAvail()){
                    if(!dynamic_cast<TreasureSpace*>(da)->isAvail()){
                        ab->special();
                    }
                        
                }
            }
        }
        

        
    }
    
    
    failure(1);
    
    delete ab;
    delete ae;
    delete ba;
    delete bb;
    delete bc;
    delete bd;
    delete be;
    delete bf;
    delete ca;
    delete cb;
    delete cc;
    delete cd;
    delete ce;
    delete cf;
    delete da;
    delete db;
    delete dc;
    delete dd;
    delete de;
    delete df;
    delete eb;
    delete ed;
    delete ef;
    delete fin;
    
    ab = NULL;
    ae = NULL;
    ba = NULL;
    bb = NULL;
    bc = NULL;
    bd = NULL;
    be = NULL;
    bf = NULL;
    ca = NULL;
    cb = NULL;
    cc = NULL;
    cd = NULL;
    ce = NULL;
    cf = NULL;
    da = NULL;
    db = NULL;
    dc = NULL;
    dd = NULL;
    de = NULL;
    df = NULL;
    eb = NULL;
    ed = NULL;
    ef = NULL;
    fin = NULL;

    return 0;
}
