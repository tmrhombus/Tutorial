# Tutorial
MakeClass Analyzer and condor_submit Submission 

To check out

```
scram pro -n Tutorial_CMSSW_5_3_24 CMSSW CMSSW_5_3_24
cd Tutorial_CMSSW_5_3_24/src
cmsenv
git clone https://github.com/tmrhombus/Tutorial_analysisSubmission.git
cd Tutorial_analysisSubmission
source setup.sh
```

You need to ``source setup.sh`` each time you log on

To test changes you make to tomsAnalyzer you can run ``root -l -b -q callAnalyzer.cc``

To submit jobs run ``bash submitthat.sh``

To merge the output run ``bash mergethat.sh``

To plot the merged output run ``bash plotthat.sh``
