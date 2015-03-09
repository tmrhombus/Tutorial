#!/bin/bash

# Makes a list of files in tutorial directory
# and counts total number of events 

for samplename in \
 "TTbar"
do
# make a list of all the samples in hdfs_in_dir
find ${hdfs_in_dir}/${samplename}/*root >  ${listdir}/hdfs_list_${samplename}.txt

cp "${listdir}/hdfs_list_${samplename}.txt" \
   "${listdir}/ez_list_${samplename}.txt"  
cp "${listdir}/hdfs_list_${samplename}.txt" \
   "${listdir}/xrd_list_${samplename}.txt"  

ezlist="${listdir}/ez_list_${samplename}.txt"
# cut path (up to "nTuple") and .root from filenames 
sed -i 's/^.*\(\/nTuple\)/nTuple/g' $ezlist
sed -i 's/.root//g' $ezlist

xrdlist="${listdir}/xrd_list_${samplename}.txt"
# cut /hdfs, replace with ...xrootd... 
sed -i 's@/hdfs/@root://cmsxrootd.hep.wisc.edu//@g' $xrdlist

# count the total number of events, not strictly necessary here, but useful
python ./eventCounter.py ${samplename} \
   ${listdir}/hdfs_list_${samplename}.txt \
   ${listdir}/initialEvents.txt

done
