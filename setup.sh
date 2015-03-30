cmsenv

# General
export runname="Shmootorial"
export xrootd="root://cmsxrootd.hep.wisc.edu//store/user/${USER}"
export hdfs="/hdfs/store/user/${USER}" 
export nfs="/nfs_scratch/${USER}"
 
# Input
# our base directory (where we have the analyzer)
export alzr_dir="${CMSSW_BASE}/src/Tutorial_analysisSubmission"
# where we accesss the files from
export base_in_dir="root://cmsxrootd.hep.wisc.edu//store/user/tperry/Tutorial"
export hdfs_in_dir="/hdfs/store/user/tperry/Tutorial" # needed for find
# where we'll we submit from with condor_submit
export base_submit_dir="/nfs_scratch/${USER}/${runname}"

# Output
mkdir -p "${alzr_dir}/Output/test"
mkdir -p "${alzr_dir}/Output/Lists"
mkdir -p "${alzr_dir}/Output/Plots"
# local running 
export testdir="${alzr_dir}/Output/test"
# lists of input files
export listdir="${alzr_dir}/Output/Lists"
# analyzed .root files
export plotdir="${alzr_dir}/Output/Plots"
