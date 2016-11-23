#include<iostream>
#include<Player.h>
#include <map>
#include "../include/Player.h"
#include "../include/Hand.h"

string Player::getName(){
    return name;
}

string Player::toString() {
    return Player::getName()+ ": " + Hand::toString();
}