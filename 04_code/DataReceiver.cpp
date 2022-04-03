//## begin module%1.10%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.10%.codegen_version

//## begin module%62497FBA023F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%62497FBA023F.cm

//## begin module%62497FBA023F.cp preserve=no
//## end module%62497FBA023F.cp

//## Module: DataReceiver%62497FBA023F; Pseudo Package body
//## Source file: C:\_proj\eaton\04_code\DataReceiver.cpp

//## begin module%62497FBA023F.additionalIncludes preserve=no
//## end module%62497FBA023F.additionalIncludes

//## begin module%62497FBA023F.includes preserve=yes
//## end module%62497FBA023F.includes

// DataReceiver
#include "DataReceiver.h"
//## begin module%62497FBA023F.additionalDeclarations preserve=yes
//## end module%62497FBA023F.additionalDeclarations


// Class DataReceiver 

DataReceiver::DataReceiver()
  //## begin DataReceiver::DataReceiver%62497FBA023F_const.hasinit preserve=no
  //## end DataReceiver::DataReceiver%62497FBA023F_const.hasinit
  //## begin DataReceiver::DataReceiver%62497FBA023F_const.initialization preserve=yes
  //## end DataReceiver::DataReceiver%62497FBA023F_const.initialization
{
  //## begin DataReceiver::DataReceiver%62497FBA023F_const.body preserve=yes
  //## end DataReceiver::DataReceiver%62497FBA023F_const.body
}


DataReceiver::~DataReceiver()
{
  //## begin DataReceiver::~DataReceiver%62497FBA023F_dest.body preserve=yes

  //## end DataReceiver::~DataReceiver%62497FBA023F_dest.body
}




//## Other Operations (implementation)
void DataReceiver::ReceiveNewData ()
{
  //## begin DataReceiver::ReceiveNewData%6249B637005A.body preserve=yes
    std::jthread t1(DataStore);
    std::jthread t2(DataReceive);


    t1.join();
    t2.join();
  //## end DataReceiver::ReceiveNewData%6249B637005A.body
}

void DataReceiver::DataReceive ()
{
  //## begin DataReceiver::DataReceive%6249C80B00BC.body preserve=yes
       __int64 receivedMessages{ 0 };
    while (1)
    {
        std::this_thread::sleep_for(5ms);
        {
            std::lock_guard<std::mutex> lck(mutex_);

            dataReady = true;
            std::cout << "Data Received :" << receivedMessages++ << '\n';
        }
        mesTr.condVar.notify_one();                                  // (3)
  //## end DataReceiver::DataReceive%6249C80B00BC.body
}

void DataReceiver::DataStore ()
{
  //## begin DataReceiver::DataStore%6249C8120024.body preserve=yes
    __int64 recordedMessages{0};
    std::cout << "Waiting" << '\n';
    std::unique_lock<std::mutex> lck(mutex_);

    while (1) {


        mesTr.condVar.wait(lck, [] {return dataReady; });
        dataReady = false;
        std::cout << "DataSendToDatabase: " << recordedMessages++ << '\n';
    }

  //## end DataReceiver::DataStore%6249C8120024.body
}

// Additional Declarations
  //## begin DataReceiver%62497FBA023F.declarations preserve=yes
  //## end DataReceiver%62497FBA023F.declarations

//## begin module%62497FBA023F.epilog preserve=yes
//## end module%62497FBA023F.epilog
