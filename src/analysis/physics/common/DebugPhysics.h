#pragma once

#include "analysis/physics/Physics.h"

namespace ant {
namespace analysis {
namespace physics {


class DebugPhysics: public Physics {
protected:
    const bool writeEvents;
    const bool requestSlowControl;
public:
    DebugPhysics(const std::string& name, PhysOptPtr opts=nullptr);
    virtual ~DebugPhysics();

    virtual void ProcessEvent(const TEvent& event, manager_t& manager) override;
    virtual void Finish() override;
    virtual void ShowResult() override;
    virtual void Initialize(input::SlowControl& slowcontrol) override;
};

class DebugPIDAlignment: public Physics {
protected:
    TH2D* angles = nullptr;
public:
    DebugPIDAlignment(const std::string& name, PhysOptPtr opts=nullptr);
    virtual ~DebugPIDAlignment();

    virtual void ProcessEvent(const TEvent& event, manager_t& manager) override;
    virtual void ShowResult() override;
};

}}} // namespace ant::analysis::physics
