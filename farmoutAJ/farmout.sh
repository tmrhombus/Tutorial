#!/bin/bash

farmoutAnalysisJobs --infer-cmssw-path --fwklite --input-file-list=list.txt --extra-inputs=/afs/hep.wisc.edu/cms/tperry/Tutorial_CMSSW_5_3_24/src/Tutorial/farmouttests/tomsAnalyzer.C,/afs/hep.wisc.edu/cms/tperry/Tutorial_CMSSW_5_3_24/src/Tutorial/farmouttests/tomsAnalyzer.h DumbiaInfinity callAnalyzer.cc

