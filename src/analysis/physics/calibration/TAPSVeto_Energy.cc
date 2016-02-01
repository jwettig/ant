#include "TAPSVeto_Energy.h"

#include "expconfig/ExpConfig.h"

using namespace std;
using namespace ant;
using namespace ant::analysis::physics;



TAPSVeto_Energy::TAPSVeto_Energy(const string& name, OptionsPtr opts) :
    Physics(name, opts)
{
    auto detector = ExpConfig::Setup::GetDetector(Detector_t::Type_t::TAPSVeto);
    const BinSettings tapsveto_channels(detector->GetNChannels());

    h_pedestals = HistFac.makeTH2D(
                      "TAPSVeto Pedestals",
                      "Raw ADC value",
                      "#",
                      BinSettings(300),
                      tapsveto_channels,
                      "Pedestals");
    h_bananas =
            HistFac.makeTH3D(
                "TAPSVeto Bananas",
                "TAPS LG Energy / MeV",
                "TAPSVeto Energy / MeV",
                "Channel",
                BinSettings(400,0,800),
                BinSettings(200,0,18),
                tapsveto_channels,
                "Bananas"
                );
}

void TAPSVeto_Energy::ProcessEvent(const TEvent& event, manager_t&)
{
    const auto& cands = event.Reconstructed->Candidates;

    // pedestals
    for(const TClusterPtr& cluster : event.Reconstructed->Clusters) {
        if(cluster->DetectorType != Detector_t::Type_t::TAPSVeto)
            continue;
        for(const TClusterHit& clusterhit : cluster->Hits) {
            /// \todo check for timing hit?
            for(const TClusterHitDatum& datum : clusterhit.Data) {
                if(datum.GetType() != Channel_t::Type_t::Pedestal)
                    continue;
                h_pedestals->Fill(datum.Value, clusterhit.Channel);
            }
        }
    }

    // bananas
    for(const auto& candidate : cands) {
        if(candidate->Clusters.size() != 2)
            continue;
        if(candidate->Detector & Detector_t::Type_t::TAPS &&
           candidate->Detector & Detector_t::Type_t::TAPSVeto
           )
        {
            // search for TAPSVeto cluster
            auto tapsveto_cluster = candidate->FindFirstCluster(Detector_t::Type_t::TAPSVeto);
            h_bananas->Fill(candidate->CaloEnergy,
                            candidate->VetoEnergy,
                            tapsveto_cluster->CentralElement);
        }
    }
}

void TAPSVeto_Energy::ShowResult()
{
    canvas(GetName())
            << drawoption("colz") << h_pedestals
            << drawoption("colz") << h_bananas->Project3D("zy")
            << endc;
}


AUTO_REGISTER_PHYSICS(TAPSVeto_Energy)