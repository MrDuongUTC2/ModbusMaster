# ModbusMaster

Currently master command sending is working fine, see To do

To do : The error handling for master current is not work, need change form RTT-Thread RTOS to FreeRTOS API
Detail :
  In file "portevent_m.c"
  Reimplement for 
    MBMasterRunResTake()
    vMBMasterRunResRelease()
    MBMasterErrorCBRespondTimeout()
    vMBMasterErrorCBReceiveData()
    vMBMasterErrorCBExecuteFunction()
    vMBMasterCBRequestScuuess()
    eMBMasterWaitRequestFinish()


Project refe:r https://github.com/armink/FreeModbus_Slave-Master-RTT-STM32/tree/master
