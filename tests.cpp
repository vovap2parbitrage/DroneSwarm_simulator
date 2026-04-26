#include <iostream>
#include <cassert>
#include <memory>

#include "Battery.h"
#include "GPS.h"
#include "Direction.h"
#include "Map.h"
#include "DroneSpawner.h"
#include "Wall.h"

void test_Battery_discharge() {
    Battery b(26.0);
    b.discharge();

    assert(b.getBatteryLevel() == 1.0);

    std::cout << "[PASS] Discharge test successfully!\n";
}

void test_GPS_relocation() {
    GPS g(5 , 6);
    g.move(Direction::Up);

    assert(g.getX() == 5 and g.getY() == 5);

    std::cout << "[PASS] Relocate test successfully\n";
}

void test_GPS_navigation() {
    GPS g(5 , 6);

    for(int i = 0 ; i < 6 ; i++) {
        g.move(Direction::Left);
    }

    assert(g.getX() == 0);

    std::cout << "[PASS] Relocate test successfully\n";
}

void test_Battery_cannotBeNagative() {
    Battery b(26.0);
    b.discharge();
    b.discharge();

    assert(b.getBatteryLevel() == 0);

    std::cout << "[PASS] Battery level cannot be nagative\n";
}

void test_Drone_movementOnMap() {
    auto m = std::make_shared<Map>(3 , 3);
    DroneSpawner ds(m.get());
    auto d1 = ds.createScout(1 , 1);
    
    m->registerEntity(d1.get());

    auto en = m->getEntity(1 , 1);

    en->setTarget(1 , 2);

    en->update();

    assert(d1->get_X() == 1 and d1->get_Y() == 2);

    std::cout << "[PASS] The drone successfully moved on the map\n";
}

void test_Map_notifyingMove() {
    auto m = std::make_shared<Map>(10 , 10);
    DroneSpawner ds(m.get());
    auto d1 = ds.createDefender(1 , 5);

    auto w1 = std::make_unique<Wall>(2 , 5);
    m->registerEntity(d1.get());
    m->registerEntity(w1.get());

    assert(!m->notifyMove(d1.get() , 2 , 5));

    std::cout << "[PASS] The drone broked successfully and wall has been broken\n";
} 

void test_Drone_tryGoingOutOfBounds() {
    auto m = std::make_shared<Map>(5 , 5);
    DroneSpawner ds(m.get());

    auto d1 = ds.createAttacker(4 , 4);

    assert(!m->notifyMove(d1.get() , 6 , 4));

    std::cout << "[PASS] The mediator blocked the drone from going out of bounds\n";
}

int main_for_tests() {
    std::cout << "===Running unit tests===\n";

    test_Battery_discharge();
    test_GPS_relocation();
    test_GPS_navigation();
    test_Battery_cannotBeNagative();
    test_Drone_movementOnMap();
    test_Map_notifyingMove();
    test_Drone_tryGoingOutOfBounds();

    std::cout << "===All unit tests passed successfully===\n";
    return 0;
}