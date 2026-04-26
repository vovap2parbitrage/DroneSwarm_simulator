#include "ArmorDecorator.h"

int ArmorDecorator::getBatteryLevel() const {return wrapee->getBatteryLevel(); }
bool ArmorDecorator::getStatus() const {return wrapee->getStatus(); }
int ArmorDecorator::get_X() const {return wrapee->get_X(); }
int ArmorDecorator::get_Y() const {return wrapee->get_Y(); }

std::string ArmorDecorator::draw() const {
    if(isUnbroken) return "[H]";
    else return wrapee->draw();
}

void ArmorDecorator::toBreak() {
    if(isUnbroken) {
        isUnbroken = false;
        std::cout << "[Armor] was destroyed\n";
    }
    else {
        wrapee->toBreak();
    }
}

void ArmorDecorator::update() {wrapee->update(); }

bool ArmorDecorator::setTarget(int x , int y) {return wrapee->setTarget(x , y); }

std::string ArmorDecorator::serialize() {
    if(isUnbroken) return "Armored " + wrapee->serialize();
    else {return wrapee->serialize(); }
}