# Tutorial
MakeClass Analyzer and condor_submit Submission 

To check out

```
scram pro -n Tutorial_CMSSW_5_3_24 CMSSW CMSSW_5_3_24
cd Tutorial_CMSSW_5_3_24/src
cmsenv
git clone https://github.com/tmrhombus/Tutorial_analysisSubmission.git
cd Tutorial_analysisSubmission
source setup.sh
```

You need to ``source setup.sh`` each time you log on
This ensures you have a directory structure ``Output/(test,Lists,${runname}/roots)`` and sets up environment variables

From the box, you can run tomsAnalyzer using ``root -l -b -q callAnalyzer.cc``
and the output is stored in ``output/test``

For farming out, you'll need a list of relevant files. Run ``bash makeLists.sh`` to generate the same list formatted three different ways: ``/hdfs, xrootd, <filename only>``. Also, calling ``bash makeLists.sh`` runs ``eventCounter.py`` which loops through all the files you just listed and searches for ``summary/results``. Finding that, it adds up the first bin to give a total generated event count. This isn't used in this analysis demonstration, but is useful for weighting in a real analysis.

### farmoutAnalysisJobs for submission
 ```cd farmoutAJ```

The script we use for job submission is ``bash farmout.sh`` which submits farmout jobs using ``--fwklite``.
You'll notice that there are two submits being made in here. The first one submits ``say_hi.cc`` and the second submits ``farmoutAnalyzer.cc``. 

About the flags being used:
``--input-file-list`` is the ``xrootd`` list we generated with ``makeLists.sh``
`` afa ``


To submit jobs run ``bash submitthat.sh``

To merge the output run ``bash mergethat.sh``

To plot the merged output run ``bash plotthat.sh``
