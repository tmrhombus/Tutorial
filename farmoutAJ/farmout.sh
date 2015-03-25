#!/bin/bash

farmoutAnalysisJobs \
 --infer-cmssw-path \
 --fwklite \
 --use-hdfs \
 --input-files-per-job=30 \
 --input-file-list="${alzr_dir}/Output/Lists/xrd_list_TTbar.txt" \
 --extra-inputs="${alzr_dir}/tomsAnalyzer.C,${alzr_dir}/tomsAnalyzer.h" \
 ${runname} farmoutAnalyzer.cc

