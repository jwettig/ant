#pragma once

#include "physics/Physics.h"
#include "plot/Histogram.h"
#include <string>
#include "TLorentzVector.h"

namespace ant {
namespace analysis {
namespace physics {

class RarePionTest: public Physics{

    TH1D* IM_gg;
    TH1D* IM_ggexact;
    TH1D* IM_ggg;
    TH1D* IM_gggg;
    TH1D* hNgamma;
    TH1D* hNgamma_cut;



public:
    RarePionTest(PhysOptPtr opts);
    virtual void ProcessEvent(const data::Event& event);
    virtual void Finish();
    virtual void ShowResult();
};


}
}
}
