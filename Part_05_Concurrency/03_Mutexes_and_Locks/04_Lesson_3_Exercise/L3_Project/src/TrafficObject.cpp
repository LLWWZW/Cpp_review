#include "TrafficObject.h"
#include <algorithm>
#include <chrono>
#include <iostream>

// init static variable
int TrafficObject::_idCnt = 0;
std::mutex TrafficObject::_mtx; // lw

// L3.2 : Add a static mutex to the base class TrafficObject (called _mtxCout) and properly instantiate it in the source
// file. This mutex will be used in the next task to protect standard-out.

void TrafficObject::setPosition(double x, double y)
{
    _posX = x;
    _posY = y;
}

void TrafficObject::getPosition(double &x, double &y)
{
    x = _posX;
    y = _posY;
}

TrafficObject::TrafficObject()
{
    _type = ObjectType::noObject;
    _id = _idCnt++;
}

TrafficObject::~TrafficObject()
{
    // set up thread barrier before this object is destroyed
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) { t.join(); });
}
