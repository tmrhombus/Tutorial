#!/bin/bash

cat > submit <<EOF
Executable = SUBMITDIR/SAMPLE_runCallAnalyzer.sh
GetEnv = True
should_transfer_files = yes
transfer_executable = yes
when_to_transfer_output = on_exit
Requirements = TARGET.Arch == "x86_64" && HasAFS_OSG && TARGET.UWCMS_CVMFS_Exists && TARGET.CMS_CVMFS_Exists
transfer_input_files = 
log = condor_job.log.\$(Cluster).\$(Process)
notification = never
EOF
cat >>submit <<EOF
Output = stdout.\$(Cluster).\$(Process)
Error = stderr.\$(Cluster).\$(Process)
Queue 1
EOF
