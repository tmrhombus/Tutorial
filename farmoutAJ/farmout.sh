#!/bin/bash

#######################################################
#
#  This is the script you call to submit jobs
#
#  bash farmout.sh
#
#  nohup bash farmout.sh > submit_${runname}.out 2>&1&
#
#######################################################

farmoutAnalysisJobs \
 --infer-cmssw-path \
 --fwklite \
 --use-hdfs \
 --input-files-per-job=30 \
 --input-file-list="${alzr_dir}/Output/Lists/xrd_list_TTbar.txt" \
 --extra-inputs="${alzr_dir}/tomsAnalyzer.C,${alzr_dir}/tomsAnalyzer.h" \
 ${runname} farmoutAnalyzer.cc

