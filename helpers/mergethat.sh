########################################################
#
# This is the script you call to merge your output
#
# bash mergethat.sh
# 
# nohup bash mergethat.sh > my_merging.out 2>&1&
#
########################################################

for samplename in \
"TTbar"

do
 hadd ${rootdir}/Analyzed_${samplename}.root ${hdfs}/${runname}-farmoutAnalyzer/*root
done

