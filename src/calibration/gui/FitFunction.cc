#include "FitFunction.h"

#include "base/interval.h"
#include "TF1Knobs.h"

#include "TF1.h"
#include "TH1.h"

using namespace ant;
using namespace ant::calibration;
using namespace ant::calibration::gui;


ant::interval<double> FitFunction::getRange(const TF1* func)
{
    interval<double> i;
    func->GetRange(i.Start(), i.Stop());
    return i;
}

void FitFunction::setRange(TF1* func, const ant::interval<double>& i)
{
    func->SetRange(i.Start(), i.Stop());
}

FitFunction::~FitFunction()
{}


FitFunctionGaus::FitFunctionGaus(double A, double x0, double sigma, interval<double> range):
    func(new TF1("","gaus", range.Start(), range.Stop()))
{
    func->SetParameter(0,A);
    func->SetParameter(1,x0);
    func->SetParameter(2,sigma);
    func->SetNpx(1000);

    Addknob<KnobsTF1::ParameterKnob>("A",     func, 0, GUIElementDescription::GUI_Type::slider_horizontal, kBlue, 3);
    Addknob<KnobsTF1::ParameterKnob>("x_{0}", func, 1, GUIElementDescription::GUI_Type::slider_vertical,   kBlue, 3);
    Addknob<MyWKnob>("#sigma",func);
    Addknob<KnobsTF1::RangeKnob>("Min", func, KnobsTF1::RangeKnob::RangeEndType::lower);
    Addknob<KnobsTF1::RangeKnob>("Max", func, KnobsTF1::RangeKnob::RangeEndType::upper);
}

FitFunctionGaus::~FitFunctionGaus()
{
}

void FitFunctionGaus::Draw()
{
    func->Draw("same");
}

void FitFunctionGaus::Fit(TH1 *hist)
{
    hist->Fit(func,"RBQN");
}

void FitFunctionGaus::SetRange(ant::interval<double> i)
{
    setRange(func, i);
}

ant::interval<double> FitFunctionGaus::GetRange() const
{
    return getRange(func);
}

void FitFunctionGaus::SetPoints(int n)
{
    func->SetNpx(n);
}

std::vector<double> FitFunctionGaus::Save() const
{
    auto range = GetRange();

    std::vector<double> params = {
        range.Start(),
        range.Stop()
    };

    return params;
}

void FitFunctionGaus::Load(const std::vector<double> &data)
{
    //@todo IMPLEMENT
}

FitFunctionGaus::MyWKnob::MyWKnob(const std::string &n, TF1 *Func):
    VirtualKnob(n,{GUIElementDescription::GUI_Type::slider_vertical,kBlue,3}),
    func(Func)
{
}

double FitFunctionGaus::MyWKnob::get() const
{
    return func->GetParameter(1) + func->GetParameter(2);
}

void FitFunctionGaus::MyWKnob::set(double a)
{
    auto v = a - func->GetParameter(1);
    func->SetParameter(2,v);
}
