#!/bin/sh

# just to get rid of annoying output from pushing/popping
pushd () { 
 command pushd "$@" > /dev/null 
}
popd () {
 command popd "$@" > /dev/null
}

samplename=THESAMPLE
 
# for each file from list... submit
mylist="${alzr_dir}/Output/Lists/ez_list_${samplename}.txt" 
while read filename
do

 # get the right filename and submission directory matched
 inputFileName="${base_in_dir}${samplename}/${filename}.root"
 submit_dir="${base_submit_dir}${samplename}/${filename}"
 
 #
 # get everything named correctly and moved to submit_dir
 #

 # callAnalyzer.cc
 cp template_callAnalyzer.cc           "${samplename}_callAnalyzer.cc"
 sed -i "s@SAMPLE@${samplename}@g"     "${samplename}_callAnalyzer.cc"
 sed -i "s@FILENAME@${filename}@g"     "${samplename}_callAnalyzer.cc"
 sed -i "s@THEFILE@${inputFileName}@g" "${samplename}_callAnalyzer.cc"

 # runCallAnalyzer.sh (executable)
 touch     "${samplename}_runCallAnalyzer.sh"
 chmod a+x "${samplename}_runCallAnalyzer.sh"
 cat     >>"${samplename}_runCallAnalyzer.sh" <<EOF
#!/bin/sh
EOF
 # add running _callAnalyzer.cc to _runCallAnalyzer.sh
 cat >>"${samplename}_runCallAnalyzer.sh" <<EOF
root -l -b -q ${samplename}_callAnalyzer.cc
EOF
 
 # runCondor.sh
 cp template_runCondor.sh $samplename"_runCondor.sh"
 # add files to be passed to condor node
 sed -i "s@transfer_input_files =@transfer_input_files = ${alzr_dir}/tomsAnalyzer.C@g" \
  $samplename'_runCondor.sh'
 sed -i "s@transfer_input_files =@transfer_input_files = ${alzr_dir}/tomsAnalyzer.h,@g" \
  $samplename'_runCondor.sh'
 sed -i "s@transfer_input_files =@transfer_input_files = ${submit_dir}/${samplename}_callAnalyzer.cc,@g" \
  $samplename'_runCondor.sh'
 # for locating executable (runCallAnalyzer.sh)
 sed -i "s@SUBMITDIR@${submit_dir}@g" "${samplename}_runCondor.sh"
 sed -i "s@SAMPLE@${samplename}@g"    "${samplename}_runCondor.sh"

 # move everything to $submit_dir
 mkdir -p $submit_dir 
 mv "${samplename}_callAnalyzer.cc"    $submit_dir
 mv "${samplename}_runCallAnalyzer.sh" $submit_dir
 mv "${samplename}_runCondor.sh"       $submit_dir
 
 # go there and submit
 pushd $submit_dir
  source "$samplename"'_runCondor.sh'
  condor_submit submit > submit.log
 popd

 done < $mylist #filename
