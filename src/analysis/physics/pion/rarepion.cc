#include "rarepion.h"
#include "data/Particle.h"
#include "utils/combinatorics.h"


using namespace ant;
using namespace ant::analysis;
using namespace ant::analysis::physics;
using namespace ant::analysis::data;
using namespace std;

RarePionTest::RarePionTest(PhysOptPtr opts) : Physics("RarePionTest", opts)
{
    BinSettings bs  = BinSettings(500);
    IM_gg  = HistFac.makeTH1D("gg IM","2 #gamma IM [MeV]","events",bs,"IM_gg");
    IM_ggexact = HistFac.makeTH1D("exact gg IM"," 2 #gamma IM [MeV]","events",bs,"IM_ggexact");
    IM_ggg  = HistFac.makeTH1D("ggg IM","3 #gamma IM [MeV]","events",bs,"IM_ggg");
    IM_gggg  = HistFac.makeTH1D("gggg IM","4 #gamma IM [MeV]","events",bs,"IM_gggg");
    hNgamma  = HistFac.makeTH1D("# gammas","# #gamma","events",10,"hNgamma");
    hNgamma_cut  = HistFac.makeTH1D("# gammas after cut","# #gamma","events",10,"hNgamma");


}

void RarePionTest::ProcessEvent(const Event &event)
{
    // put all rec. events into data
    const auto& data = event.Reconstructed();
    // get photons
    const auto& photons = data.Particles().Get(ParticleTypeDatabase::Photon);
    // how many photons are there?
    hNgamma->Fill(photons.size());

    // stop if there aren't exactly two photons.
    if ( photons.size() < 2)
        return;

    // how many photons are still there?
    hNgamma_cut->Fill(photons.size());

    if ( photons.size() == 2){
        // combinations of exact two photons
        auto combinationexact2 = utils::makeCombination(photons,2);
        do {
            TLorentzVector v;
            for ( auto& i: combinationexact2){
                v += *i;
            }
            IM_ggexact->Fill(v.M());
        } while (combinationexact2.next());
    }

    // combinations of two photons
    auto combination2 = utils::makeCombination(photons,2);
    do {
        TLorentzVector v;
        for ( auto& i: combination2){
            v += *i;
        }
        IM_gg->Fill(v.M());
    } while (combination2.next());

    if ( photons.size() > 2){
        // combinations of three photons
        auto combination3 = utils::makeCombination(photons,3);
        do {
            TLorentzVector v;
            for ( auto& i: combination3){
                v += *i;
            }
            IM_ggg->Fill(v.M());
        } while (combination3.next());
    }

    if ( photons.size() > 4){
        // combinations of four photons
        auto combination4 = utils::makeCombination(photons,4);
        do {
            TLorentzVector v;
            for ( auto& i: combination4){
                v += *i;
            }
            IM_gggg->Fill(v.M());
        } while (combination4.next());
    }


}

void RarePionTest::Finish()
{

}

void RarePionTest::ShowResult()
{
    canvas cc("rarePionTest");
    cc
            //<< hNgamma_cut
            << IM_gg
            << IM_ggexact
            //<< IM_ggg
           // << IM_gggg
            << endc;
}

AUTO_REGISTER_PHYSICS(RarePionTest,"RarePionTest")
