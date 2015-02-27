cmsenv
export runname="Shmootorial"
export xrootd="root://cmsxrootd.hep.wisc.edu//store/user/${USER}"
export hdfs="/hdfs/store/user/${USER}" 
export nfs="/nfs_scratch/${USER}"
    
# where we eventually accesss the files from
export base_in_dir="root://cmsxrootd.hep.wisc.edu//store/user/tperry/Tutorial/"
export hdfs_in_dir="/hdfs/store/user/tperry/Tutorial/" # needed for find
# where we'll we submit from with condor_submit
export base_submit_dir="/nfs_scratch/${USER}/${runname}/"

