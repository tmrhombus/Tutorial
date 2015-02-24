########################################################
#
# This is the script you call to submit to HTCondor
#
# bash submitthat.sh
# 
# nohup bash submitthat.sh > my_submission.out 2>&1&
#
########################################################

for samplename in \
"TTbar"

do 
 cp template_submitter.sh ${samplename}_submitter.sh
 sed -i "s@THESAMPLE@${samplename}@g" ${samplename}_submitter.sh
 bash ${samplename}_submitter.sh 
 nohup bash ${samplename}_submitter.sh > ${samplename}_submit.out 2>&1&
done
