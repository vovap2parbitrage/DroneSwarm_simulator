#pragma once

class IMediator {
    public:
    virtual ~IMediator() = default;
    virtual bool notifyMove(class IEntity* d , int target_X , int target_Y) = 0;
};