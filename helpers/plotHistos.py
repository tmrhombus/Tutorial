#!/usr/bin/env python
'''
 Plots the output of the analyzer in  
 for multiple variables
 Author: T.M.Perry UW-Madison
'''
import ROOT
from ROOT import THStack,TH1F,TFile
from ROOT import TLegend,TCanvas,TPad,TLatex,TLine
from ROOT import gROOT,gStyle
import sys
#import fnmatch as fnm # if you want to match with wildcards
import os
import cmsPrelim as cpr

variables = ["goodJ1_pt","goodMuon_pt","goodJ3J4_mass"]

runname=os.environ['runname']
hdfs=os.environ['hdfs']
runname=os.environ['runname']
plotdir=os.environ['plotdir']

in_fname = "%s/%s-farmoutAnalyzer/farmoutAnalyzer-nTuple_TTbar_SemiLeptonic_01" %(hdfs,runname)
in_file = TFile(in_fname+".root")
 
# rebin factor
rebin = 1
fcolor = ROOT.EColor.kGreen+1
lcolor = ROOT.EColor.kViolet
sf = 1
fillStyle = 1

#canvas size
canx = 900 
cany = 900

tex = ROOT.TLatex()
tex.SetTextSize(0.07)
tex.SetTextAlign(13)
tex.SetNDC(True)
gStyle.SetOptStat('')
gStyle.SetLineWidth(3)
gStyle.SetPadTickY(1)

c = TCanvas('c','Canvas Named c',canx,cany)
c.cd()
for variable in variables: 
 print(variable)
 c.Clear()
 out_fname = "%s/Histograms_%s_TTbar_%s"%(plotdir,runname,variable)
 
 hist = in_file.Get( "h_%s"%(variable) )
 hist.Rebin( rebin )
 hist.SetFillColor( fcolor )
 hist.SetLineColor( lcolor )
 hist.SetLineWidth( 2 ) 
 hist.Scale( sf )
 hist.Draw("GOFF")
 max_hist = hist.GetMaximum()
 title = hist.GetTitle()
 hist.SetTitle("")
 hist.GetYaxis().SetRangeUser(0,1.2*max_hist)

 # set title and axis labels
 hist.GetXaxis().SetLabelSize(0.03)
 hist.GetXaxis().SetTitle( "%s [GeV]"%(title) )
 hist.GetYaxis().SetLabelSize(0.03)
 hist.GetYaxis().SetTitleOffset(1.5)
 hist.GetYaxis().SetTitle( "Events / %s [GeV]"%(hist.GetBinWidth(1)) )
 
 # fill legend
 leg=TLegend(0.7,0.75,0.88,0.88)
 leg.AddEntry(hist,"TTbar","f")
 leg.SetFillColor(0)
 leg.SetBorderSize(0)
 
 # line at W mass
 l = TLine( 80.4, 0, 80.4, 1.05*max_hist )
 l.SetLineStyle(3)

 # and draw
 c.cd()
 hist.Draw('hist')
 leg.Draw('sames')
 if(variable=="goodJ3J4_mass"): l.Draw()
 
 cpr.prelim_alt(19700,0.05)
 tex.SetTextAlign(11) #left, bottom
 tex.DrawLatex(0.1,0.9,title)
 
 c.Update()
 
 c.Print(out_fname+".png")
 print("you just finished with %s.png"%out_fname)
 print("")
 
