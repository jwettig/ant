#include "detail/taggEffClasses.cc"

#include "base/CmdLine.h"
#include "base/Logger.h"

#include "TGraph.h"
#include "TRint.h"

#include <algorithm>

static TGraph* graph2d(nullptr);
void initGraph(const string& xtitle, const string& ytitle)
{
    graph2d = new TGraph();
    graph2d->GetXaxis()->SetTitle(xtitle.c_str());
    graph2d->GetYaxis()->SetTitle(ytitle.c_str());
    string title = std_ext::formatter() << xtitle << " vs " << ytitle;
    graph2d->SetTitle(title.c_str());
}


auto failExit = [] (const string& message)
{
    LOG(ERROR) << message;
    exit(EXIT_FAILURE);
};

void plotLiveTimes(const vector<string>& fileList);
void plotRates(const vector<string>& fileList);


int main( int argc, char** argv )

{
    SetupLogger();
    TCLAP::CmdLine cmd("taggEffPlot", ' ', "0.1");

    auto plot_Lt       = cmd.add<TCLAP::SwitchArg>("","livetime", "plot livetime for bkg1 and bkg2");
    auto plot_rate     = cmd.add<TCLAP::SwitchArg>("","rate", "plot livetime for bkg1 and bkg2");

    auto modes = {&plot_Lt,&plot_rate};

    auto cmd_filelist   = cmd.add<TCLAP::UnlabeledMultiArg<string>>("inputfiles","inputfiles to read from",true,"inputfiles");

    cmd.parse(argc,argv);

    auto inputCount = 0u;
    for ( auto m: modes )
        inputCount+=m->get()->isSet();
    if (inputCount!=1)
    {
        string msg = "Exactly one mode is allowed:  ";
        for ( auto m: modes)
            msg += std_ext::formatter() << "--" << m->get()->getName() << "  ";
        failExit(msg);
    }
    auto fileList = cmd_filelist->getValue();

    if (plot_Lt->isSet())
    {
        if (fileList.size() < 1)
            failExit("Provide files");
        plotLiveTimes(fileList);
    }
    if (plot_rate->isSet())
    {
        if (fileList.size() < 1)
            failExit("Provide files");
        plotRates(fileList);
    }

    argc=1; // prevent TRint to parse any cmdline except prog name
    auto app = std_ext::make_unique<TRint>("Ant-makeSigmas",&argc,argv,nullptr,0,true);

    if(app) {
        canvas c("TaggEff");
        if (graph2d)
            c << drawoption("AP") << graph2d;
        c << endc;

        app->Run(kTRUE); // really important to return...
    }


    return EXIT_SUCCESS;
}



void plotLiveTimes(const vector<string>& fileList)
{
    vector<unique_ptr<treeLoader_t>> tContainers;
    for (const auto& fN: fileList)
        tContainers.emplace_back(new treeLoader_t(fN));

    if ( graph2d )
        throw runtime_error("graph already exists, this should never happen");

    initGraph("time [s]","tivelime [%]");
    graph2d->SetObjectStat(false);

    for (const auto& tc: tContainers)
        for ( const auto& timeLT: tc->getLiveTimes() )
            graph2d->SetPoint(graph2d->GetN(),timeLT.first,timeLT.second);
}

void plotRates(const vector<string>& fileList)
{
    initGraph("time","rate");
    vector<unique_ptr<treeLoader_t>> tContainers;

    LOG(INFO) << "Loading files:";

    for (const auto& fN: fileList)
    {
        cout << fN << "  ";
        tContainers.emplace_back(new treeLoader_t(fN));
    }
    cout << endl;


    for ( const auto& t: tContainers)
    {
        double timeInRun =  0;
        for ( auto en = 0u ; en < t->Tree()->GetEntries() ; ++en)
        {
            t->Tree()->GetEntry(en);

            timeInRun += t->wrapTree.Clock() / 1.0e6;

            auto evTime = (  timeInRun
                             + t->wrapTree.EvID.Value->Timestamp );

            std_ext::RMS rmsRate;
            for ( auto ch = 0u ; ch < t->nchannels ; ++ ch)
                rmsRate.Add(t->wrapTree.TaggRates().at(ch));

            graph2d->SetPoint(graph2d->GetN(),
                              evTime,
                              rmsRate.GetMean());
        }
    }
}
