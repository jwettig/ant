#pragma once

#include "physics/Physics.h"
#include "plot/Histogram.h"
#include "plot/SmartHist.h"

#include <map>

namespace ant {
namespace analysis {
namespace physics {

class ParticleCombinatoricsTest: public Physics {
protected:
    SmartHist1<double> ggim;
    SmartHist1<double> gggim;
    SmartHist1<int>    nphotons;
    SmartHist1<int>    nprotons;

    std::map<const ant::ParticleTypeDatabase::Type*, SmartHist1<const TParticlePtr&>> EHists;

public:
    ParticleCombinatoricsTest(const std::string& name, OptionsPtr opts);
    virtual ~ParticleCombinatoricsTest() {}

    virtual void ProcessEvent(const TEvent& event, manager_t& manager) override;
    virtual void Finish() override;
    virtual void ShowResult() override;
};

}
}
}
