#ifndef genMassHypo_h
#define genMassHypo_h

#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include "string.h"
#include <TH1D.h>
#include <TH2D.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include "type.h"

using namespace std;

class event;
class hit;
class material;
class Utility;

class genMassHypo
{
 public:
  genMassHypo(string numoflist, string date);
  ~genMassHypo();
  
  int Init();
  int initChain();
  int initHistoMap();

  int Make();

  int Finish();
  int writeHistoMap();
  
  bool isPhoton(hit *ahit, int i);
  bool isReflection(hit *ahit, int i);
  bool isOnAerogel(hit *ahit, int i);
  bool isOnPhotonSensor(hit *ahit, int i);

  void Smearing2D(double inx, double iny, double& outx, double& outy);
  
 private:
  material *mat;
  Utility *utility;
  string mNumOfList;
  string mDate;
  string mOutPutFile;
  TFile *File_mOutPut;

  // key: pid | indexSpaceX | indexSpaceY | indexMomentumP | indexMomentumTheta | indexMomentumPhi
  TH1DMap h_mNumOfEvents; // number of total events
  TH2DMap h_mPhotonDist; // x: photon out_x | y: photon out_y 

  TChain *mChainInPut_Events;
  TChain *mChainInPut_Tracks;
};
#endif
