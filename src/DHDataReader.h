////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Name: DHDataReader.h                                                      //
//  Class: DHDataReader.cxx                                                   //
//  Creator: Andrew Hard                                                      //
//  Email: ahard@cern.ch                                                      //
//  Date: 21/11/2015                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef DHDataReader_h
#define DHDataReader_h

// C++ includes:
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

// ROOT includes:
#include "TFile.h"
#include "TH1F.h"
#include "TString.h"
#include "TTree.h"

// Package includes:
#include "Config.h"
#include "DHAnalysis.h"
#include "RooFitHead.h"

class DHDataReader {

 public:
  
  // Constructor and destructor:
  DHDataReader(TString configFile);
  virtual ~DHDataReader() {};
  
  // Mutators:
  void loadMxAOD(TString sampleName);
  RooDataSet* getDataSet(TString sampleName, TString cateName);
  
 private:
  void varData(TString varForm, TString& varName, double& varMin,
	       double& varMax);
  
  Config *m_config;
  
  std::map<TString,TTree*> m_storedMxAODTrees;
};

#endif
