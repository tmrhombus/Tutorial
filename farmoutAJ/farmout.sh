#!/bin/bash

farmoutAnalysisJobs --infer-cmssw-path --fwklite --input-file-list=list.txt --extra-inputs="${alzr_dir}/tomsAnalyzer.C,${alzr_dir}/tomsAnalyzer.h" ${runname} farmoutAnalyzer.cc

