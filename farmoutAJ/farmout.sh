#!/bin/bash

farmoutAnalysisJobs --infer-cmssw-path --fwklite --input-file-list=list.txt --extra-inputs="${CMSSW_BASE}/src/Tutorial/farmoutAJ/tomsAnalyzer.C,${CMSSW_BASE}/src/Tutorial/farmoutAJ/tomsAnalyzer.h" ${runname} farmoutAnalyzer.cc

