//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%62497FBA023F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%62497FBA023F.cm

//## begin module%62497FBA023F.cp preserve=no
//## end module%62497FBA023F.cp

//## Module: DataReceiver%62497FBA023F; Pseudo Package specification
//## Source file: C:\_proj\eaton\04_code\DataReceiver.h

#ifndef DataReceiver_h
#define DataReceiver_h 1

//## begin module%62497FBA023F.additionalIncludes preserve=no
// #include <condition_variable>
#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <functional>
#include <stop_token>
#include <condition_variable>
//## end module%62497FBA023F.additionalIncludes

//## begin module%62497FBA023F.includes preserve=yes
//## end module%62497FBA023F.includes

// messagesThreading
//#include "messagesThreading.h"
//## begin module%62497FBA023F.additionalDeclarations preserve=yes
//## end module%62497FBA023F.additionalDeclarations


//## begin DataReceiver%62497FBA023F.preface preserve=yes
//## end DataReceiver%62497FBA023F.preface

//## Class: DataReceiver%62497FBA023F
//## Category: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%6249BBCA0216;messagesThreading { -> }

class DataReceiver 
{
  //## begin DataReceiver%62497FBA023F.initialDeclarations preserve=yes
  //## end DataReceiver%62497FBA023F.initialDeclarations

  public:
    //## Constructors (generated)
      DataReceiver();

    //## Destructor (generated)
      ~DataReceiver();


    //## Assignment Operation (generated)

    //## Equality Operations (generated)


    //## Other Operations (specified)
      //## Operation: ReceiveNewData%6249B637005A
      void ReceiveNewData ();

      //## Operation: DataReceive%6249C80B00BC
      void DataReceive ();

      //## Operation: DataStore%6249C8120024
      void DataStore ();

    // Additional Public Declarations
      //## begin DataReceiver%62497FBA023F.public preserve=yes
      //## end DataReceiver%62497FBA023F.public

  protected:
    // Additional Protected Declarations
      //## begin DataReceiver%62497FBA023F.protected preserve=yes
      //## end DataReceiver%62497FBA023F.protected

  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: mesTr%6249BE6A01CA
    // Additional Private Declarations
      //## begin DataReceiver%62497FBA023F.private preserve=yes
      //## end DataReceiver%62497FBA023F.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin DataReceiver::mesTr%6249BE6A01CA.attr preserve=no  private: messagesThreading {U} 
       std::mutex mutex_;
      std::condition_variable_any condVar;
      //## end DataReceiver::mesTr%6249BE6A01CA.attr
public :
    bool dataReady;

    // Additional Implementation Declarations
      //## begin DataReceiver%62497FBA023F.implementation preserve=yes
      //## end DataReceiver%62497FBA023F.implementation

};

//## begin DataReceiver%62497FBA023F.postscript preserve=yes
//## end DataReceiver%62497FBA023F.postscript

// Class DataReceiver 

//## Get and Set Operations for Class Attributes (inline)

//## begin module%62497FBA023F.epilog preserve=yes
//## end module%62497FBA023F.epilog


#endif
