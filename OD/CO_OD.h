/*******************************************************************************

   File: CO_OD.h
   CANopen Object Dictionary.

   Copyright (C) 2004-2008 Janez Paternoster

   License: GNU Lesser General Public License (LGPL).

   <http://canopennode.sourceforge.net>

   (For more information see <CO_SDO.h>.)
*/
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 2.1 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.


   Author: Janez Paternoster


   This file was automatically generated with CANopenNode Object
   Dictionary Editor. DON'T EDIT THIS FILE MANUALLY !!!!

*******************************************************************************/

#ifndef CO_OD_H
#define CO_OD_H


/*******************************************************************************
   CANopen DATA DYPES
*******************************************************************************/
   typedef uint8_t      UNSIGNED8;
   typedef uint16_t     UNSIGNED16;
   typedef uint32_t     UNSIGNED32;
   typedef uint64_t     UNSIGNED64;
   typedef int8_t       INTEGER8;
   typedef int16_t      INTEGER16;
   typedef int32_t      INTEGER32;
   typedef int64_t      INTEGER64;
   typedef float32_t    REAL32;
   typedef float64_t    REAL64;
   typedef char_t       VISIBLE_STRING;
   typedef oChar_t      OCTET_STRING;
   typedef domain_t     DOMAIN_T;


/*******************************************************************************
   FILE INFO:
      FileName:     Mbed
      FileVersion:  3.0
      CreationTime: 20:03:50
      CreationDate: 2016-11-23
      CreatedBy:    WillyKaze
*******************************************************************************/


/*******************************************************************************
   DEVICE INFO:
      VendorName:     Paternoster
      VendorNumber:   0
      ProductName:    CANopenNode
      ProductNumber:  0
*******************************************************************************/


/*******************************************************************************
   FEATURES
*******************************************************************************/
   #define CO_NO_SYNC                     1   //Associated objects: 1005, 1006, 1007, 2103, 2104
   #define CO_NO_EMERGENCY                1   //Associated objects: 1014, 1015
   #define CO_NO_SDO_SERVER               10  //Associated objects: 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208, 1209
   #define CO_NO_SDO_CLIENT               10  //Associated objects: 1280, 1281, 1282, 1283, 1284, 1285, 1286, 1287, 1288, 1289
   #define CO_NO_RPDO                     4   //Associated objects: 1400, 1401, 1402, 1403, 1600, 1601, 1602, 1603
   #define CO_NO_TPDO                     4   //Associated objects: 1800, 1801, 1802, 1803, 1A00, 1A01, 1A02, 1A03
   #define CO_NO_NMT_MASTER               1   


/*******************************************************************************
   OBJECT DICTIONARY
*******************************************************************************/
   #define CO_OD_NoOfElements             76


/*******************************************************************************
   TYPE DEFINITIONS FOR RECORDS
*******************************************************************************/
/*1018      */ typedef struct{
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     vendorID;
               UNSIGNED32     productCode;
               UNSIGNED32     revisionNumber;
               UNSIGNED32     serialNumber;
               }              OD_identity_t;

/*1200[10]  */ typedef struct{
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDClientToServer;
               UNSIGNED32     COB_IDServerToClient;
               }              OD_SDOServerParameter_t;

/*1280[10]  */ typedef struct{
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDClientToServer;
               UNSIGNED32     COB_IDServerToClient;
               UNSIGNED8      nodeIDOfTheSDOServer;
               }              OD_SDOClientParameter_t;

/*1400[4]   */ typedef struct{
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDUsedByRPDO;
               UNSIGNED8      transmissionType;
               }              OD_RPDOCommunicationParameter_t;

/*1600[4]   */ typedef struct{
               UNSIGNED8      numberOfMappedObjects;
               UNSIGNED32     mappedObject1;
               UNSIGNED32     mappedObject2;
               UNSIGNED32     mappedObject3;
               UNSIGNED32     mappedObject4;
               UNSIGNED32     mappedObject5;
               UNSIGNED32     mappedObject6;
               UNSIGNED32     mappedObject7;
               UNSIGNED32     mappedObject8;
               }              OD_RPDOMappingParameter_t;

/*1800[4]   */ typedef struct{
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDUsedByTPDO;
               UNSIGNED8      transmissionType;
               UNSIGNED16     inhibitTime;
               UNSIGNED8      compatibilityEntry;
               UNSIGNED16     eventTimer;
               UNSIGNED8      SYNCStartValue;
               }              OD_TPDOCommunicationParameter_t;

/*1A00[4]   */ typedef struct{
               UNSIGNED8      numberOfMappedObjects;
               UNSIGNED32     mappedObject1;
               UNSIGNED32     mappedObject2;
               UNSIGNED32     mappedObject3;
               UNSIGNED32     mappedObject4;
               UNSIGNED32     mappedObject5;
               UNSIGNED32     mappedObject6;
               UNSIGNED32     mappedObject7;
               UNSIGNED32     mappedObject8;
               }              OD_TPDOMappingParameter_t;


/*******************************************************************************
   STRUCTURES FOR VARIABLES IN DIFFERENT MEMORY LOCATIONS
*******************************************************************************/
#define  CO_OD_FIRST_LAST_WORD     0x55 //Any value from 0x01 to 0xFE. If changed, EEPROM will be reinitialized.

/***** Structure for RAM variables ********************************************/
struct sCO_OD_RAM{
               UNSIGNED32     FirstWord;

/*1001      */ UNSIGNED8      errorRegister;
/*1002      */ UNSIGNED32     manufacturerStatusRegister;
/*1003      */ UNSIGNED32     preDefinedErrorField[8];
/*1010      */ UNSIGNED32     storeParameters[1];
/*1011      */ UNSIGNED32     restoreDefaultParameters[1];
/*1280[10]  */ OD_SDOClientParameter_t SDOClientParameter[10];
/*6000      */ UNSIGNED8      readInput8Bit[8];
/*6200      */ UNSIGNED8      writeOutput8Bit[8];
/*6401      */ INTEGER16      readAnalogueInput16Bit[12];
/*6411      */ INTEGER16      writeAnalogueOutput16Bit[8];

               UNSIGNED32     LastWord;
};

/***** Structure for EEPROM variables *****************************************/
struct sCO_OD_EEPROM{
               UNSIGNED32     FirstWord;



               UNSIGNED32     LastWord;
};


/***** Structure for ROM variables ********************************************/
struct sCO_OD_ROM{
               UNSIGNED32     FirstWord;

/*1000      */ UNSIGNED32     deviceType;
/*1005      */ UNSIGNED32     COB_ID_SYNCMessage;
/*1006      */ UNSIGNED32     communicationCyclePeriod;
/*1007      */ UNSIGNED32     synchronousWindowLength;
/*1008      */ VISIBLE_STRING manufacturerDeviceName[11];
/*1009      */ VISIBLE_STRING manufacturerHardwareVersion[4];
/*100A      */ VISIBLE_STRING manufacturerSoftwareVersion[4];
/*100B      */ UNSIGNED8      CANNodeID;
/*1014      */ UNSIGNED32     COB_ID_EMCY;
/*1015      */ UNSIGNED16     inhibitTimeEMCY;
/*1016      */ UNSIGNED32     consumerHeartbeatTime[4];
/*1017      */ UNSIGNED16     producerHeartbeatTime;
/*1018      */ OD_identity_t  identity;
/*1019      */ UNSIGNED8      synchronousCounterOverflowValue;
/*1029      */ UNSIGNED8      errorBehavior[6];
/*1200[10]  */ OD_SDOServerParameter_t SDOServerParameter[10];
/*1400[4]   */ OD_RPDOCommunicationParameter_t RPDOCommunicationParameter[4];
/*1600[4]   */ OD_RPDOMappingParameter_t RPDOMappingParameter[4];
/*1800[4]   */ OD_TPDOCommunicationParameter_t TPDOCommunicationParameter[4];
/*1A00[4]   */ OD_TPDOMappingParameter_t TPDOMappingParameter[4];
/*1F80      */ UNSIGNED32     NMTStartup;
/*2100      */ UNSIGNED8      remoteNodeArray[127];
/*2101      */ UNSIGNED8      remoteNodeTX_PDO1Array[127];
/*2102      */ UNSIGNED8      remoteNodeRX_PDO1Array[127];
/*2103      */ UNSIGNED8      remoteNodeTX_PDO2Array[127];
/*2104      */ UNSIGNED8      remoteNodeRX_PDO2Array[127];
/*2105      */ UNSIGNED8      remoteNodeServerSDOArray[127];
/*2106      */ UNSIGNED8      remoteNodeClientSDOArray[127];
/*2107      */ UNSIGNED8      remoteNodeDigitalOutputBytesArray[127];
/*2108      */ UNSIGNED8      remoteNodeInputBytesArray[127];
/*2109      */ UNSIGNED8      remoteNodeTX_PDO3Array[127];
/*210A      */ UNSIGNED8      remoteNodeRX_PDO3Array[127];
/*210B      */ UNSIGNED8      remoteNodeRX_PDO5Array[127];
/*210C      */ UNSIGNED8      remoteNodeTX_PDO4Array[127];
/*210D      */ UNSIGNED8      remoteNodeRX_PDO4Array[127];
/*2200      */ OCTET_STRING   errorStatusBits[10];

               UNSIGNED32     LastWord;
};


/***** Declaration of Object Dictionary variables *****************************/
extern struct sCO_OD_RAM CO_OD_RAM;

extern struct sCO_OD_EEPROM CO_OD_EEPROM;

extern struct sCO_OD_ROM CO_OD_ROM;


/*******************************************************************************
   ALIASES FOR OBJECT DICTIONARY VARIABLES
*******************************************************************************/
/*1000, Data Type: UNSIGNED32 */
      #define OD_deviceType                              CO_OD_ROM.deviceType

/*1001, Data Type: UNSIGNED8 */
      #define OD_errorRegister                           CO_OD_RAM.errorRegister

/*1002, Data Type: UNSIGNED32 */
      #define OD_manufacturerStatusRegister              CO_OD_RAM.manufacturerStatusRegister

/*1003, Data Type: UNSIGNED32, Array[8] */
      #define OD_preDefinedErrorField                    CO_OD_RAM.preDefinedErrorField
      #define ODL_preDefinedErrorField_arrayLength       8

/*1005, Data Type: UNSIGNED32 */
      #define OD_COB_ID_SYNCMessage                      CO_OD_ROM.COB_ID_SYNCMessage

/*1006, Data Type: UNSIGNED32 */
      #define OD_communicationCyclePeriod                CO_OD_ROM.communicationCyclePeriod

/*1007, Data Type: UNSIGNED32 */
      #define OD_synchronousWindowLength                 CO_OD_ROM.synchronousWindowLength

/*1008, Data Type: VISIBLE_STRING, Array[11] */
      #define OD_manufacturerDeviceName                  CO_OD_ROM.manufacturerDeviceName
      #define ODL_manufacturerDeviceName_stringLength    11

/*1009, Data Type: VISIBLE_STRING, Array[4] */
      #define OD_manufacturerHardwareVersion             CO_OD_ROM.manufacturerHardwareVersion
      #define ODL_manufacturerHardwareVersion_stringLength 4

/*100A, Data Type: VISIBLE_STRING, Array[4] */
      #define OD_manufacturerSoftwareVersion             CO_OD_ROM.manufacturerSoftwareVersion
      #define ODL_manufacturerSoftwareVersion_stringLength 4

/*100B, Data Type: UNSIGNED8 */
      #define OD_CANNodeID                               CO_OD_ROM.CANNodeID

/*1010, Data Type: UNSIGNED32, Array[1] */
      #define OD_storeParameters                         CO_OD_RAM.storeParameters
      #define ODL_storeParameters_arrayLength            1
      #define ODA_storeParameters_saveAllParameters      0

/*1011, Data Type: UNSIGNED32, Array[1] */
      #define OD_restoreDefaultParameters                CO_OD_RAM.restoreDefaultParameters
      #define ODL_restoreDefaultParameters_arrayLength   1
      #define ODA_restoreDefaultParameters_restoreAllDefaultParameters 0

/*1014, Data Type: UNSIGNED32 */
      #define OD_COB_ID_EMCY                             CO_OD_ROM.COB_ID_EMCY

/*1015, Data Type: UNSIGNED16 */
      #define OD_inhibitTimeEMCY                         CO_OD_ROM.inhibitTimeEMCY

/*1016, Data Type: UNSIGNED32, Array[4] */
      #define OD_consumerHeartbeatTime                   CO_OD_ROM.consumerHeartbeatTime
      #define ODL_consumerHeartbeatTime_arrayLength      4

/*1017, Data Type: UNSIGNED16 */
      #define OD_producerHeartbeatTime                   CO_OD_ROM.producerHeartbeatTime

/*1018, Data Type: OD_identity_t */
      #define OD_identity                                CO_OD_ROM.identity

/*1019, Data Type: UNSIGNED8 */
      #define OD_synchronousCounterOverflowValue         CO_OD_ROM.synchronousCounterOverflowValue

/*1029, Data Type: UNSIGNED8, Array[6] */
      #define OD_errorBehavior                           CO_OD_ROM.errorBehavior
      #define ODL_errorBehavior_arrayLength              6
      #define ODA_errorBehavior_communication            0
      #define ODA_errorBehavior_communicationOther       1
      #define ODA_errorBehavior_communicationPassive     2
      #define ODA_errorBehavior_generic                  3
      #define ODA_errorBehavior_deviceProfile            4
      #define ODA_errorBehavior_manufacturerSpecific     5

/*1200[10], Data Type: OD_SDOServerParameter_t, Array[10] */
      #define OD_SDOServerParameter                      CO_OD_ROM.SDOServerParameter

/*1280[10], Data Type: OD_SDOClientParameter_t, Array[10] */
      #define OD_SDOClientParameter                      CO_OD_RAM.SDOClientParameter

/*1400[4], Data Type: OD_RPDOCommunicationParameter_t, Array[4] */
      #define OD_RPDOCommunicationParameter              CO_OD_ROM.RPDOCommunicationParameter

/*1600[4], Data Type: OD_RPDOMappingParameter_t, Array[4] */
      #define OD_RPDOMappingParameter                    CO_OD_ROM.RPDOMappingParameter

/*1800[4], Data Type: OD_TPDOCommunicationParameter_t, Array[4] */
      #define OD_TPDOCommunicationParameter              CO_OD_ROM.TPDOCommunicationParameter

/*1A00[4], Data Type: OD_TPDOMappingParameter_t, Array[4] */
      #define OD_TPDOMappingParameter                    CO_OD_ROM.TPDOMappingParameter

/*1F80, Data Type: UNSIGNED32 */
      #define OD_NMTStartup                              CO_OD_ROM.NMTStartup

/*2100, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeArray                         CO_OD_ROM.remoteNodeArray
      #define ODL_remoteNodeArray_arrayLength            127
      #define ODA_remoteNodeArray_node01Type             0
      #define ODA_remoteNodeArray_node02Type             1
      #define ODA_remoteNodeArray_node03Type             2
      #define ODA_remoteNodeArray_node04Type             3
      #define ODA_remoteNodeArray_node05Type             4
      #define ODA_remoteNodeArray_node06Type             5
      #define ODA_remoteNodeArray_node07Type             6
      #define ODA_remoteNodeArray_node08Type             7
      #define ODA_remoteNodeArray_node09Type             8
      #define ODA_remoteNodeArray_node0AType             9
      #define ODA_remoteNodeArray_node0BType             10
      #define ODA_remoteNodeArray_node0CType             11
      #define ODA_remoteNodeArray_node0DType             12
      #define ODA_remoteNodeArray_node0EType             13
      #define ODA_remoteNodeArray_node0FType             14
      #define ODA_remoteNodeArray_node10Type             15
      #define ODA_remoteNodeArray_node11Type             16
      #define ODA_remoteNodeArray_node12Type             17
      #define ODA_remoteNodeArray_node13Type             18
      #define ODA_remoteNodeArray_node14Type             19
      #define ODA_remoteNodeArray_node15Type             20
      #define ODA_remoteNodeArray_node16Type             21
      #define ODA_remoteNodeArray_node17Type             22
      #define ODA_remoteNodeArray_node18Type             23
      #define ODA_remoteNodeArray_node19Type             24
      #define ODA_remoteNodeArray_node1AType             25
      #define ODA_remoteNodeArray_node1BType             26
      #define ODA_remoteNodeArray_node1CType             27
      #define ODA_remoteNodeArray_node1DType             28
      #define ODA_remoteNodeArray_node1EType             29
      #define ODA_remoteNodeArray_node1FType             30
      #define ODA_remoteNodeArray_node20Type             31
      #define ODA_remoteNodeArray_node21Type             32
      #define ODA_remoteNodeArray_node22Type             33
      #define ODA_remoteNodeArray_node23Type             34
      #define ODA_remoteNodeArray_node24Type             35
      #define ODA_remoteNodeArray_node25Type             36
      #define ODA_remoteNodeArray_node26Type             37
      #define ODA_remoteNodeArray_node27Type             38
      #define ODA_remoteNodeArray_node28Type             39
      #define ODA_remoteNodeArray_node29Type             40
      #define ODA_remoteNodeArray_node2AType             41
      #define ODA_remoteNodeArray_node2BType             42
      #define ODA_remoteNodeArray_node2CType             43
      #define ODA_remoteNodeArray_node2DType             44
      #define ODA_remoteNodeArray_node2EType             45
      #define ODA_remoteNodeArray_node2FType             46
      #define ODA_remoteNodeArray_node30Type             47
      #define ODA_remoteNodeArray_node31Type             48
      #define ODA_remoteNodeArray_node32Type             49
      #define ODA_remoteNodeArray_node33Type             50
      #define ODA_remoteNodeArray_node34Type             51
      #define ODA_remoteNodeArray_node35Type             52
      #define ODA_remoteNodeArray_node36Type             53
      #define ODA_remoteNodeArray_node37Type             54
      #define ODA_remoteNodeArray_node38Type             55
      #define ODA_remoteNodeArray_node39Type             56
      #define ODA_remoteNodeArray_node3AType             57
      #define ODA_remoteNodeArray_node3BType             58
      #define ODA_remoteNodeArray_node3CType             59
      #define ODA_remoteNodeArray_node3DType             60
      #define ODA_remoteNodeArray_node3EType             61
      #define ODA_remoteNodeArray_node3FType             62
      #define ODA_remoteNodeArray_node40Type             63
      #define ODA_remoteNodeArray_node41Type             64
      #define ODA_remoteNodeArray_node42Type             65
      #define ODA_remoteNodeArray_node43Type             66
      #define ODA_remoteNodeArray_node44Type             67
      #define ODA_remoteNodeArray_node45Type             68
      #define ODA_remoteNodeArray_node46Type             69
      #define ODA_remoteNodeArray_node47Type             70
      #define ODA_remoteNodeArray_node48Type             71
      #define ODA_remoteNodeArray_node49Type             72
      #define ODA_remoteNodeArray_node4AType             73
      #define ODA_remoteNodeArray_node4BType             74
      #define ODA_remoteNodeArray_node4CType             75
      #define ODA_remoteNodeArray_node4DType             76
      #define ODA_remoteNodeArray_node4EType             77
      #define ODA_remoteNodeArray_node4FType             78
      #define ODA_remoteNodeArray_node50Type             79
      #define ODA_remoteNodeArray_node51Type             80
      #define ODA_remoteNodeArray_node52Type             81
      #define ODA_remoteNodeArray_node53Type             82
      #define ODA_remoteNodeArray_node54Type             83
      #define ODA_remoteNodeArray_node55Type             84
      #define ODA_remoteNodeArray_node56Type             85
      #define ODA_remoteNodeArray_node57Type             86
      #define ODA_remoteNodeArray_node58Type             87
      #define ODA_remoteNodeArray_node59Type             88
      #define ODA_remoteNodeArray_node5AType             89
      #define ODA_remoteNodeArray_node5BType             90
      #define ODA_remoteNodeArray_node5CType             91
      #define ODA_remoteNodeArray_node5DType             92
      #define ODA_remoteNodeArray_node5EType             93
      #define ODA_remoteNodeArray_node5FType             94
      #define ODA_remoteNodeArray_node60Type             95
      #define ODA_remoteNodeArray_node61Type             96
      #define ODA_remoteNodeArray_node62Type             97
      #define ODA_remoteNodeArray_node63Type             98
      #define ODA_remoteNodeArray_node64Type             99
      #define ODA_remoteNodeArray_node65Type             100
      #define ODA_remoteNodeArray_node66Type             101
      #define ODA_remoteNodeArray_node67Type             102
      #define ODA_remoteNodeArray_node68Type             103
      #define ODA_remoteNodeArray_node69Type             104
      #define ODA_remoteNodeArray_node6AType             105
      #define ODA_remoteNodeArray_node6BType             106
      #define ODA_remoteNodeArray_node6CType             107
      #define ODA_remoteNodeArray_node6DType             108
      #define ODA_remoteNodeArray_node6EType             109
      #define ODA_remoteNodeArray_node6FType             110
      #define ODA_remoteNodeArray_node70Type             111
      #define ODA_remoteNodeArray_node71Type             112
      #define ODA_remoteNodeArray_node72Type             113
      #define ODA_remoteNodeArray_node73Type             114
      #define ODA_remoteNodeArray_node74Type             115
      #define ODA_remoteNodeArray_node75Type             116
      #define ODA_remoteNodeArray_node76Type             117
      #define ODA_remoteNodeArray_node77Type             118
      #define ODA_remoteNodeArray_node78Type             119
      #define ODA_remoteNodeArray_node79Type             120
      #define ODA_remoteNodeArray_node7AType             121
      #define ODA_remoteNodeArray_node7BType             122
      #define ODA_remoteNodeArray_node7CType             123
      #define ODA_remoteNodeArray_node7DType             124
      #define ODA_remoteNodeArray_node7EType             125
      #define ODA_remoteNodeArray_node7FType             126

/*2101, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeTX_PDO1Array                  CO_OD_ROM.remoteNodeTX_PDO1Array
      #define ODL_remoteNodeTX_PDO1Array_arrayLength     127
      #define ODA_remoteNodeTX_PDO1Array_node01Type      0
      #define ODA_remoteNodeTX_PDO1Array_node02Type      1
      #define ODA_remoteNodeTX_PDO1Array_node03Type      2
      #define ODA_remoteNodeTX_PDO1Array_node04Type      3
      #define ODA_remoteNodeTX_PDO1Array_node05Type      4
      #define ODA_remoteNodeTX_PDO1Array_node06Type      5
      #define ODA_remoteNodeTX_PDO1Array_node07Type      6
      #define ODA_remoteNodeTX_PDO1Array_node08Type      7
      #define ODA_remoteNodeTX_PDO1Array_node09Type      8
      #define ODA_remoteNodeTX_PDO1Array_node0AType      9
      #define ODA_remoteNodeTX_PDO1Array_node0BType      10
      #define ODA_remoteNodeTX_PDO1Array_node0CType      11
      #define ODA_remoteNodeTX_PDO1Array_node0DType      12
      #define ODA_remoteNodeTX_PDO1Array_node0EType      13
      #define ODA_remoteNodeTX_PDO1Array_node0FType      14
      #define ODA_remoteNodeTX_PDO1Array_node10Type      15
      #define ODA_remoteNodeTX_PDO1Array_node11Type      16
      #define ODA_remoteNodeTX_PDO1Array_node12Type      17
      #define ODA_remoteNodeTX_PDO1Array_node13Type      18
      #define ODA_remoteNodeTX_PDO1Array_node14Type      19
      #define ODA_remoteNodeTX_PDO1Array_node15Type      20
      #define ODA_remoteNodeTX_PDO1Array_node16Type      21
      #define ODA_remoteNodeTX_PDO1Array_node17Type      22
      #define ODA_remoteNodeTX_PDO1Array_node18Type      23
      #define ODA_remoteNodeTX_PDO1Array_node19Type      24
      #define ODA_remoteNodeTX_PDO1Array_node1AType      25
      #define ODA_remoteNodeTX_PDO1Array_node1BType      26
      #define ODA_remoteNodeTX_PDO1Array_node1CType      27
      #define ODA_remoteNodeTX_PDO1Array_node1DType      28
      #define ODA_remoteNodeTX_PDO1Array_node1EType      29
      #define ODA_remoteNodeTX_PDO1Array_node1FType      30
      #define ODA_remoteNodeTX_PDO1Array_node20Type      31
      #define ODA_remoteNodeTX_PDO1Array_node21Type      32
      #define ODA_remoteNodeTX_PDO1Array_node22Type      33
      #define ODA_remoteNodeTX_PDO1Array_node23Type      34
      #define ODA_remoteNodeTX_PDO1Array_node24Type      35
      #define ODA_remoteNodeTX_PDO1Array_node25Type      36
      #define ODA_remoteNodeTX_PDO1Array_node26Type      37
      #define ODA_remoteNodeTX_PDO1Array_node27Type      38
      #define ODA_remoteNodeTX_PDO1Array_node28Type      39
      #define ODA_remoteNodeTX_PDO1Array_node29Type      40
      #define ODA_remoteNodeTX_PDO1Array_node2AType      41
      #define ODA_remoteNodeTX_PDO1Array_node2BType      42
      #define ODA_remoteNodeTX_PDO1Array_node2CType      43
      #define ODA_remoteNodeTX_PDO1Array_node2DType      44
      #define ODA_remoteNodeTX_PDO1Array_node2EType      45
      #define ODA_remoteNodeTX_PDO1Array_node2FType      46
      #define ODA_remoteNodeTX_PDO1Array_node30Type      47
      #define ODA_remoteNodeTX_PDO1Array_node31Type      48
      #define ODA_remoteNodeTX_PDO1Array_node32Type      49
      #define ODA_remoteNodeTX_PDO1Array_node33Type      50
      #define ODA_remoteNodeTX_PDO1Array_node34Type      51
      #define ODA_remoteNodeTX_PDO1Array_node35Type      52
      #define ODA_remoteNodeTX_PDO1Array_node36Type      53
      #define ODA_remoteNodeTX_PDO1Array_node37Type      54
      #define ODA_remoteNodeTX_PDO1Array_node38Type      55
      #define ODA_remoteNodeTX_PDO1Array_node39Type      56
      #define ODA_remoteNodeTX_PDO1Array_node3AType      57
      #define ODA_remoteNodeTX_PDO1Array_node3BType      58
      #define ODA_remoteNodeTX_PDO1Array_node3CType      59
      #define ODA_remoteNodeTX_PDO1Array_node3DType      60
      #define ODA_remoteNodeTX_PDO1Array_node3EType      61
      #define ODA_remoteNodeTX_PDO1Array_node3FType      62
      #define ODA_remoteNodeTX_PDO1Array_node40Type      63
      #define ODA_remoteNodeTX_PDO1Array_node41Type      64
      #define ODA_remoteNodeTX_PDO1Array_node42Type      65
      #define ODA_remoteNodeTX_PDO1Array_node43Type      66
      #define ODA_remoteNodeTX_PDO1Array_node44Type      67
      #define ODA_remoteNodeTX_PDO1Array_node45Type      68
      #define ODA_remoteNodeTX_PDO1Array_node46Type      69
      #define ODA_remoteNodeTX_PDO1Array_node47Type      70
      #define ODA_remoteNodeTX_PDO1Array_node48Type      71
      #define ODA_remoteNodeTX_PDO1Array_node49Type      72
      #define ODA_remoteNodeTX_PDO1Array_node4AType      73
      #define ODA_remoteNodeTX_PDO1Array_node4BType      74
      #define ODA_remoteNodeTX_PDO1Array_node4CType      75
      #define ODA_remoteNodeTX_PDO1Array_node4DType      76
      #define ODA_remoteNodeTX_PDO1Array_node4EType      77
      #define ODA_remoteNodeTX_PDO1Array_node4FType      78
      #define ODA_remoteNodeTX_PDO1Array_node50Type      79
      #define ODA_remoteNodeTX_PDO1Array_node51Type      80
      #define ODA_remoteNodeTX_PDO1Array_node52Type      81
      #define ODA_remoteNodeTX_PDO1Array_node53Type      82
      #define ODA_remoteNodeTX_PDO1Array_node54Type      83
      #define ODA_remoteNodeTX_PDO1Array_node55Type      84
      #define ODA_remoteNodeTX_PDO1Array_node56Type      85
      #define ODA_remoteNodeTX_PDO1Array_node57Type      86
      #define ODA_remoteNodeTX_PDO1Array_node58Type      87
      #define ODA_remoteNodeTX_PDO1Array_node59Type      88
      #define ODA_remoteNodeTX_PDO1Array_node5AType      89
      #define ODA_remoteNodeTX_PDO1Array_node5BType      90
      #define ODA_remoteNodeTX_PDO1Array_node5CType      91
      #define ODA_remoteNodeTX_PDO1Array_node5DType      92
      #define ODA_remoteNodeTX_PDO1Array_node5EType      93
      #define ODA_remoteNodeTX_PDO1Array_node5FType      94
      #define ODA_remoteNodeTX_PDO1Array_node60Type      95
      #define ODA_remoteNodeTX_PDO1Array_node61Type      96
      #define ODA_remoteNodeTX_PDO1Array_node62Type      97
      #define ODA_remoteNodeTX_PDO1Array_node63Type      98
      #define ODA_remoteNodeTX_PDO1Array_node64Type      99
      #define ODA_remoteNodeTX_PDO1Array_node65Type      100
      #define ODA_remoteNodeTX_PDO1Array_node66Type      101
      #define ODA_remoteNodeTX_PDO1Array_node67Type      102
      #define ODA_remoteNodeTX_PDO1Array_node68Type      103
      #define ODA_remoteNodeTX_PDO1Array_node69Type      104
      #define ODA_remoteNodeTX_PDO1Array_node6AType      105
      #define ODA_remoteNodeTX_PDO1Array_node6BType      106
      #define ODA_remoteNodeTX_PDO1Array_node6CType      107
      #define ODA_remoteNodeTX_PDO1Array_node6DType      108
      #define ODA_remoteNodeTX_PDO1Array_node6EType      109
      #define ODA_remoteNodeTX_PDO1Array_node6FType      110
      #define ODA_remoteNodeTX_PDO1Array_node70Type      111
      #define ODA_remoteNodeTX_PDO1Array_node71Type      112
      #define ODA_remoteNodeTX_PDO1Array_node72Type      113
      #define ODA_remoteNodeTX_PDO1Array_node73Type      114
      #define ODA_remoteNodeTX_PDO1Array_node74Type      115
      #define ODA_remoteNodeTX_PDO1Array_node75Type      116
      #define ODA_remoteNodeTX_PDO1Array_node76Type      117
      #define ODA_remoteNodeTX_PDO1Array_node77Type      118
      #define ODA_remoteNodeTX_PDO1Array_node78Type      119
      #define ODA_remoteNodeTX_PDO1Array_node79Type      120
      #define ODA_remoteNodeTX_PDO1Array_node7AType      121
      #define ODA_remoteNodeTX_PDO1Array_node7BType      122
      #define ODA_remoteNodeTX_PDO1Array_node7CType      123
      #define ODA_remoteNodeTX_PDO1Array_node7DType      124
      #define ODA_remoteNodeTX_PDO1Array_node7EType      125
      #define ODA_remoteNodeTX_PDO1Array_node7FType      126

/*2102, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeRX_PDO1Array                  CO_OD_ROM.remoteNodeRX_PDO1Array
      #define ODL_remoteNodeRX_PDO1Array_arrayLength     127
      #define ODA_remoteNodeRX_PDO1Array_node01Type      0
      #define ODA_remoteNodeRX_PDO1Array_node02Type      1
      #define ODA_remoteNodeRX_PDO1Array_node03Type      2
      #define ODA_remoteNodeRX_PDO1Array_node04Type      3
      #define ODA_remoteNodeRX_PDO1Array_node05Type      4
      #define ODA_remoteNodeRX_PDO1Array_node06Type      5
      #define ODA_remoteNodeRX_PDO1Array_node07Type      6
      #define ODA_remoteNodeRX_PDO1Array_node08Type      7
      #define ODA_remoteNodeRX_PDO1Array_node09Type      8
      #define ODA_remoteNodeRX_PDO1Array_node0AType      9
      #define ODA_remoteNodeRX_PDO1Array_node0BType      10
      #define ODA_remoteNodeRX_PDO1Array_node0CType      11
      #define ODA_remoteNodeRX_PDO1Array_node0DType      12
      #define ODA_remoteNodeRX_PDO1Array_node0EType      13
      #define ODA_remoteNodeRX_PDO1Array_node0FType      14
      #define ODA_remoteNodeRX_PDO1Array_node10Type      15
      #define ODA_remoteNodeRX_PDO1Array_node11Type      16
      #define ODA_remoteNodeRX_PDO1Array_node12Type      17
      #define ODA_remoteNodeRX_PDO1Array_node13Type      18
      #define ODA_remoteNodeRX_PDO1Array_node14Type      19
      #define ODA_remoteNodeRX_PDO1Array_node15Type      20
      #define ODA_remoteNodeRX_PDO1Array_node16Type      21
      #define ODA_remoteNodeRX_PDO1Array_node17Type      22
      #define ODA_remoteNodeRX_PDO1Array_node18Type      23
      #define ODA_remoteNodeRX_PDO1Array_node19Type      24
      #define ODA_remoteNodeRX_PDO1Array_node1AType      25
      #define ODA_remoteNodeRX_PDO1Array_node1BType      26
      #define ODA_remoteNodeRX_PDO1Array_node1CType      27
      #define ODA_remoteNodeRX_PDO1Array_node1DType      28
      #define ODA_remoteNodeRX_PDO1Array_node1EType      29
      #define ODA_remoteNodeRX_PDO1Array_node1FType      30
      #define ODA_remoteNodeRX_PDO1Array_node20Type      31
      #define ODA_remoteNodeRX_PDO1Array_node21Type      32
      #define ODA_remoteNodeRX_PDO1Array_node22Type      33
      #define ODA_remoteNodeRX_PDO1Array_node23Type      34
      #define ODA_remoteNodeRX_PDO1Array_node24Type      35
      #define ODA_remoteNodeRX_PDO1Array_node25Type      36
      #define ODA_remoteNodeRX_PDO1Array_node26Type      37
      #define ODA_remoteNodeRX_PDO1Array_node27Type      38
      #define ODA_remoteNodeRX_PDO1Array_node28Type      39
      #define ODA_remoteNodeRX_PDO1Array_node29Type      40
      #define ODA_remoteNodeRX_PDO1Array_node2AType      41
      #define ODA_remoteNodeRX_PDO1Array_node2BType      42
      #define ODA_remoteNodeRX_PDO1Array_node2CType      43
      #define ODA_remoteNodeRX_PDO1Array_node2DType      44
      #define ODA_remoteNodeRX_PDO1Array_node2EType      45
      #define ODA_remoteNodeRX_PDO1Array_node2FType      46
      #define ODA_remoteNodeRX_PDO1Array_node30Type      47
      #define ODA_remoteNodeRX_PDO1Array_node31Type      48
      #define ODA_remoteNodeRX_PDO1Array_node32Type      49
      #define ODA_remoteNodeRX_PDO1Array_node33Type      50
      #define ODA_remoteNodeRX_PDO1Array_node34Type      51
      #define ODA_remoteNodeRX_PDO1Array_node35Type      52
      #define ODA_remoteNodeRX_PDO1Array_node36Type      53
      #define ODA_remoteNodeRX_PDO1Array_node37Type      54
      #define ODA_remoteNodeRX_PDO1Array_node38Type      55
      #define ODA_remoteNodeRX_PDO1Array_node39Type      56
      #define ODA_remoteNodeRX_PDO1Array_node3AType      57
      #define ODA_remoteNodeRX_PDO1Array_node3BType      58
      #define ODA_remoteNodeRX_PDO1Array_node3CType      59
      #define ODA_remoteNodeRX_PDO1Array_node3DType      60
      #define ODA_remoteNodeRX_PDO1Array_node3EType      61
      #define ODA_remoteNodeRX_PDO1Array_node3FType      62
      #define ODA_remoteNodeRX_PDO1Array_node40Type      63
      #define ODA_remoteNodeRX_PDO1Array_node41Type      64
      #define ODA_remoteNodeRX_PDO1Array_node42Type      65
      #define ODA_remoteNodeRX_PDO1Array_node43Type      66
      #define ODA_remoteNodeRX_PDO1Array_node44Type      67
      #define ODA_remoteNodeRX_PDO1Array_node45Type      68
      #define ODA_remoteNodeRX_PDO1Array_node46Type      69
      #define ODA_remoteNodeRX_PDO1Array_node47Type      70
      #define ODA_remoteNodeRX_PDO1Array_node48Type      71
      #define ODA_remoteNodeRX_PDO1Array_node49Type      72
      #define ODA_remoteNodeRX_PDO1Array_node4AType      73
      #define ODA_remoteNodeRX_PDO1Array_node4BType      74
      #define ODA_remoteNodeRX_PDO1Array_node4CType      75
      #define ODA_remoteNodeRX_PDO1Array_node4DType      76
      #define ODA_remoteNodeRX_PDO1Array_node4EType      77
      #define ODA_remoteNodeRX_PDO1Array_node4FType      78
      #define ODA_remoteNodeRX_PDO1Array_node50Type      79
      #define ODA_remoteNodeRX_PDO1Array_node51Type      80
      #define ODA_remoteNodeRX_PDO1Array_node52Type      81
      #define ODA_remoteNodeRX_PDO1Array_node53Type      82
      #define ODA_remoteNodeRX_PDO1Array_node54Type      83
      #define ODA_remoteNodeRX_PDO1Array_node55Type      84
      #define ODA_remoteNodeRX_PDO1Array_node56Type      85
      #define ODA_remoteNodeRX_PDO1Array_node57Type      86
      #define ODA_remoteNodeRX_PDO1Array_node58Type      87
      #define ODA_remoteNodeRX_PDO1Array_node59Type      88
      #define ODA_remoteNodeRX_PDO1Array_node5AType      89
      #define ODA_remoteNodeRX_PDO1Array_node5BType      90
      #define ODA_remoteNodeRX_PDO1Array_node5CType      91
      #define ODA_remoteNodeRX_PDO1Array_node5DType      92
      #define ODA_remoteNodeRX_PDO1Array_node5EType      93
      #define ODA_remoteNodeRX_PDO1Array_node5FType      94
      #define ODA_remoteNodeRX_PDO1Array_node60Type      95
      #define ODA_remoteNodeRX_PDO1Array_node61Type      96
      #define ODA_remoteNodeRX_PDO1Array_node62Type      97
      #define ODA_remoteNodeRX_PDO1Array_node63Type      98
      #define ODA_remoteNodeRX_PDO1Array_node64Type      99
      #define ODA_remoteNodeRX_PDO1Array_node65Type      100
      #define ODA_remoteNodeRX_PDO1Array_node66Type      101
      #define ODA_remoteNodeRX_PDO1Array_node67Type      102
      #define ODA_remoteNodeRX_PDO1Array_node68Type      103
      #define ODA_remoteNodeRX_PDO1Array_node69Type      104
      #define ODA_remoteNodeRX_PDO1Array_node6AType      105
      #define ODA_remoteNodeRX_PDO1Array_node6BType      106
      #define ODA_remoteNodeRX_PDO1Array_node6CType      107
      #define ODA_remoteNodeRX_PDO1Array_node6DType      108
      #define ODA_remoteNodeRX_PDO1Array_node6EType      109
      #define ODA_remoteNodeRX_PDO1Array_node6FType      110
      #define ODA_remoteNodeRX_PDO1Array_node70Type      111
      #define ODA_remoteNodeRX_PDO1Array_node71Type      112
      #define ODA_remoteNodeRX_PDO1Array_node72Type      113
      #define ODA_remoteNodeRX_PDO1Array_node73Type      114
      #define ODA_remoteNodeRX_PDO1Array_node74Type      115
      #define ODA_remoteNodeRX_PDO1Array_node75Type      116
      #define ODA_remoteNodeRX_PDO1Array_node76Type      117
      #define ODA_remoteNodeRX_PDO1Array_node77Type      118
      #define ODA_remoteNodeRX_PDO1Array_node78Type      119
      #define ODA_remoteNodeRX_PDO1Array_node79Type      120
      #define ODA_remoteNodeRX_PDO1Array_node7AType      121
      #define ODA_remoteNodeRX_PDO1Array_node7BType      122
      #define ODA_remoteNodeRX_PDO1Array_node7CType      123
      #define ODA_remoteNodeRX_PDO1Array_node7DType      124
      #define ODA_remoteNodeRX_PDO1Array_node7EType      125
      #define ODA_remoteNodeRX_PDO1Array_node7FType      126

/*2103, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeTX_PDO2Array                  CO_OD_ROM.remoteNodeTX_PDO2Array
      #define ODL_remoteNodeTX_PDO2Array_arrayLength     127
      #define ODA_remoteNodeTX_PDO2Array_node01Type      0
      #define ODA_remoteNodeTX_PDO2Array_node02Type      1
      #define ODA_remoteNodeTX_PDO2Array_node03Type      2
      #define ODA_remoteNodeTX_PDO2Array_node04Type      3
      #define ODA_remoteNodeTX_PDO2Array_node05Type      4
      #define ODA_remoteNodeTX_PDO2Array_node06Type      5
      #define ODA_remoteNodeTX_PDO2Array_node07Type      6
      #define ODA_remoteNodeTX_PDO2Array_node08Type      7
      #define ODA_remoteNodeTX_PDO2Array_node09Type      8
      #define ODA_remoteNodeTX_PDO2Array_node0AType      9
      #define ODA_remoteNodeTX_PDO2Array_node0BType      10
      #define ODA_remoteNodeTX_PDO2Array_node0CType      11
      #define ODA_remoteNodeTX_PDO2Array_node0DType      12
      #define ODA_remoteNodeTX_PDO2Array_node0EType      13
      #define ODA_remoteNodeTX_PDO2Array_node0FType      14
      #define ODA_remoteNodeTX_PDO2Array_node10Type      15
      #define ODA_remoteNodeTX_PDO2Array_node11Type      16
      #define ODA_remoteNodeTX_PDO2Array_node12Type      17
      #define ODA_remoteNodeTX_PDO2Array_node13Type      18
      #define ODA_remoteNodeTX_PDO2Array_node14Type      19
      #define ODA_remoteNodeTX_PDO2Array_node15Type      20
      #define ODA_remoteNodeTX_PDO2Array_node16Type      21
      #define ODA_remoteNodeTX_PDO2Array_node17Type      22
      #define ODA_remoteNodeTX_PDO2Array_node18Type      23
      #define ODA_remoteNodeTX_PDO2Array_node19Type      24
      #define ODA_remoteNodeTX_PDO2Array_node1AType      25
      #define ODA_remoteNodeTX_PDO2Array_node1BType      26
      #define ODA_remoteNodeTX_PDO2Array_node1CType      27
      #define ODA_remoteNodeTX_PDO2Array_node1DType      28
      #define ODA_remoteNodeTX_PDO2Array_node1EType      29
      #define ODA_remoteNodeTX_PDO2Array_node1FType      30
      #define ODA_remoteNodeTX_PDO2Array_node20Type      31
      #define ODA_remoteNodeTX_PDO2Array_node21Type      32
      #define ODA_remoteNodeTX_PDO2Array_node22Type      33
      #define ODA_remoteNodeTX_PDO2Array_node23Type      34
      #define ODA_remoteNodeTX_PDO2Array_node24Type      35
      #define ODA_remoteNodeTX_PDO2Array_node25Type      36
      #define ODA_remoteNodeTX_PDO2Array_node26Type      37
      #define ODA_remoteNodeTX_PDO2Array_node27Type      38
      #define ODA_remoteNodeTX_PDO2Array_node28Type      39
      #define ODA_remoteNodeTX_PDO2Array_node29Type      40
      #define ODA_remoteNodeTX_PDO2Array_node2AType      41
      #define ODA_remoteNodeTX_PDO2Array_node2BType      42
      #define ODA_remoteNodeTX_PDO2Array_node2CType      43
      #define ODA_remoteNodeTX_PDO2Array_node2DType      44
      #define ODA_remoteNodeTX_PDO2Array_node2EType      45
      #define ODA_remoteNodeTX_PDO2Array_node2FType      46
      #define ODA_remoteNodeTX_PDO2Array_node30Type      47
      #define ODA_remoteNodeTX_PDO2Array_node31Type      48
      #define ODA_remoteNodeTX_PDO2Array_node32Type      49
      #define ODA_remoteNodeTX_PDO2Array_node33Type      50
      #define ODA_remoteNodeTX_PDO2Array_node34Type      51
      #define ODA_remoteNodeTX_PDO2Array_node35Type      52
      #define ODA_remoteNodeTX_PDO2Array_node36Type      53
      #define ODA_remoteNodeTX_PDO2Array_node37Type      54
      #define ODA_remoteNodeTX_PDO2Array_node38Type      55
      #define ODA_remoteNodeTX_PDO2Array_node39Type      56
      #define ODA_remoteNodeTX_PDO2Array_node3AType      57
      #define ODA_remoteNodeTX_PDO2Array_node3BType      58
      #define ODA_remoteNodeTX_PDO2Array_node3CType      59
      #define ODA_remoteNodeTX_PDO2Array_node3DType      60
      #define ODA_remoteNodeTX_PDO2Array_node3EType      61
      #define ODA_remoteNodeTX_PDO2Array_node3FType      62
      #define ODA_remoteNodeTX_PDO2Array_node40Type      63
      #define ODA_remoteNodeTX_PDO2Array_node41Type      64
      #define ODA_remoteNodeTX_PDO2Array_node42Type      65
      #define ODA_remoteNodeTX_PDO2Array_node43Type      66
      #define ODA_remoteNodeTX_PDO2Array_node44Type      67
      #define ODA_remoteNodeTX_PDO2Array_node45Type      68
      #define ODA_remoteNodeTX_PDO2Array_node46Type      69
      #define ODA_remoteNodeTX_PDO2Array_node47Type      70
      #define ODA_remoteNodeTX_PDO2Array_node48Type      71
      #define ODA_remoteNodeTX_PDO2Array_node49Type      72
      #define ODA_remoteNodeTX_PDO2Array_node4AType      73
      #define ODA_remoteNodeTX_PDO2Array_node4BType      74
      #define ODA_remoteNodeTX_PDO2Array_node4CType      75
      #define ODA_remoteNodeTX_PDO2Array_node4DType      76
      #define ODA_remoteNodeTX_PDO2Array_node4EType      77
      #define ODA_remoteNodeTX_PDO2Array_node4FType      78
      #define ODA_remoteNodeTX_PDO2Array_node50Type      79
      #define ODA_remoteNodeTX_PDO2Array_node51Type      80
      #define ODA_remoteNodeTX_PDO2Array_node52Type      81
      #define ODA_remoteNodeTX_PDO2Array_node53Type      82
      #define ODA_remoteNodeTX_PDO2Array_node54Type      83
      #define ODA_remoteNodeTX_PDO2Array_node55Type      84
      #define ODA_remoteNodeTX_PDO2Array_node56Type      85
      #define ODA_remoteNodeTX_PDO2Array_node57Type      86
      #define ODA_remoteNodeTX_PDO2Array_node58Type      87
      #define ODA_remoteNodeTX_PDO2Array_node59Type      88
      #define ODA_remoteNodeTX_PDO2Array_node5AType      89
      #define ODA_remoteNodeTX_PDO2Array_node5BType      90
      #define ODA_remoteNodeTX_PDO2Array_node5CType      91
      #define ODA_remoteNodeTX_PDO2Array_node5DType      92
      #define ODA_remoteNodeTX_PDO2Array_node5EType      93
      #define ODA_remoteNodeTX_PDO2Array_node5FType      94
      #define ODA_remoteNodeTX_PDO2Array_node60Type      95
      #define ODA_remoteNodeTX_PDO2Array_node61Type      96
      #define ODA_remoteNodeTX_PDO2Array_node62Type      97
      #define ODA_remoteNodeTX_PDO2Array_node63Type      98
      #define ODA_remoteNodeTX_PDO2Array_node64Type      99
      #define ODA_remoteNodeTX_PDO2Array_node65Type      100
      #define ODA_remoteNodeTX_PDO2Array_node66Type      101
      #define ODA_remoteNodeTX_PDO2Array_node67Type      102
      #define ODA_remoteNodeTX_PDO2Array_node68Type      103
      #define ODA_remoteNodeTX_PDO2Array_node69Type      104
      #define ODA_remoteNodeTX_PDO2Array_node6AType      105
      #define ODA_remoteNodeTX_PDO2Array_node6BType      106
      #define ODA_remoteNodeTX_PDO2Array_node6CType      107
      #define ODA_remoteNodeTX_PDO2Array_node6DType      108
      #define ODA_remoteNodeTX_PDO2Array_node6EType      109
      #define ODA_remoteNodeTX_PDO2Array_node6FType      110
      #define ODA_remoteNodeTX_PDO2Array_node70Type      111
      #define ODA_remoteNodeTX_PDO2Array_node71Type      112
      #define ODA_remoteNodeTX_PDO2Array_node72Type      113
      #define ODA_remoteNodeTX_PDO2Array_node73Type      114
      #define ODA_remoteNodeTX_PDO2Array_node74Type      115
      #define ODA_remoteNodeTX_PDO2Array_node75Type      116
      #define ODA_remoteNodeTX_PDO2Array_node76Type      117
      #define ODA_remoteNodeTX_PDO2Array_node77Type      118
      #define ODA_remoteNodeTX_PDO2Array_node78Type      119
      #define ODA_remoteNodeTX_PDO2Array_node79Type      120
      #define ODA_remoteNodeTX_PDO2Array_node7AType      121
      #define ODA_remoteNodeTX_PDO2Array_node7BType      122
      #define ODA_remoteNodeTX_PDO2Array_node7CType      123
      #define ODA_remoteNodeTX_PDO2Array_node7DType      124
      #define ODA_remoteNodeTX_PDO2Array_node7EType      125
      #define ODA_remoteNodeTX_PDO2Array_node7FType      126

/*2104, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeRX_PDO2Array                  CO_OD_ROM.remoteNodeRX_PDO2Array
      #define ODL_remoteNodeRX_PDO2Array_arrayLength     127
      #define ODA_remoteNodeRX_PDO2Array_node01Type      0
      #define ODA_remoteNodeRX_PDO2Array_node02Type      1
      #define ODA_remoteNodeRX_PDO2Array_node03Type      2
      #define ODA_remoteNodeRX_PDO2Array_node04Type      3
      #define ODA_remoteNodeRX_PDO2Array_node05Type      4
      #define ODA_remoteNodeRX_PDO2Array_node06Type      5
      #define ODA_remoteNodeRX_PDO2Array_node07Type      6
      #define ODA_remoteNodeRX_PDO2Array_node08Type      7
      #define ODA_remoteNodeRX_PDO2Array_node09Type      8
      #define ODA_remoteNodeRX_PDO2Array_node0AType      9
      #define ODA_remoteNodeRX_PDO2Array_node0BType      10
      #define ODA_remoteNodeRX_PDO2Array_node0CType      11
      #define ODA_remoteNodeRX_PDO2Array_node0DType      12
      #define ODA_remoteNodeRX_PDO2Array_node0EType      13
      #define ODA_remoteNodeRX_PDO2Array_node0FType      14
      #define ODA_remoteNodeRX_PDO2Array_node10Type      15
      #define ODA_remoteNodeRX_PDO2Array_node11Type      16
      #define ODA_remoteNodeRX_PDO2Array_node12Type      17
      #define ODA_remoteNodeRX_PDO2Array_node13Type      18
      #define ODA_remoteNodeRX_PDO2Array_node14Type      19
      #define ODA_remoteNodeRX_PDO2Array_node15Type      20
      #define ODA_remoteNodeRX_PDO2Array_node16Type      21
      #define ODA_remoteNodeRX_PDO2Array_node17Type      22
      #define ODA_remoteNodeRX_PDO2Array_node18Type      23
      #define ODA_remoteNodeRX_PDO2Array_node19Type      24
      #define ODA_remoteNodeRX_PDO2Array_node1AType      25
      #define ODA_remoteNodeRX_PDO2Array_node1BType      26
      #define ODA_remoteNodeRX_PDO2Array_node1CType      27
      #define ODA_remoteNodeRX_PDO2Array_node1DType      28
      #define ODA_remoteNodeRX_PDO2Array_node1EType      29
      #define ODA_remoteNodeRX_PDO2Array_node1FType      30
      #define ODA_remoteNodeRX_PDO2Array_node20Type      31
      #define ODA_remoteNodeRX_PDO2Array_node21Type      32
      #define ODA_remoteNodeRX_PDO2Array_node22Type      33
      #define ODA_remoteNodeRX_PDO2Array_node23Type      34
      #define ODA_remoteNodeRX_PDO2Array_node24Type      35
      #define ODA_remoteNodeRX_PDO2Array_node25Type      36
      #define ODA_remoteNodeRX_PDO2Array_node26Type      37
      #define ODA_remoteNodeRX_PDO2Array_node27Type      38
      #define ODA_remoteNodeRX_PDO2Array_node28Type      39
      #define ODA_remoteNodeRX_PDO2Array_node29Type      40
      #define ODA_remoteNodeRX_PDO2Array_node2AType      41
      #define ODA_remoteNodeRX_PDO2Array_node2BType      42
      #define ODA_remoteNodeRX_PDO2Array_node2CType      43
      #define ODA_remoteNodeRX_PDO2Array_node2DType      44
      #define ODA_remoteNodeRX_PDO2Array_node2EType      45
      #define ODA_remoteNodeRX_PDO2Array_node2FType      46
      #define ODA_remoteNodeRX_PDO2Array_node30Type      47
      #define ODA_remoteNodeRX_PDO2Array_node31Type      48
      #define ODA_remoteNodeRX_PDO2Array_node32Type      49
      #define ODA_remoteNodeRX_PDO2Array_node33Type      50
      #define ODA_remoteNodeRX_PDO2Array_node34Type      51
      #define ODA_remoteNodeRX_PDO2Array_node35Type      52
      #define ODA_remoteNodeRX_PDO2Array_node36Type      53
      #define ODA_remoteNodeRX_PDO2Array_node37Type      54
      #define ODA_remoteNodeRX_PDO2Array_node38Type      55
      #define ODA_remoteNodeRX_PDO2Array_node39Type      56
      #define ODA_remoteNodeRX_PDO2Array_node3AType      57
      #define ODA_remoteNodeRX_PDO2Array_node3BType      58
      #define ODA_remoteNodeRX_PDO2Array_node3CType      59
      #define ODA_remoteNodeRX_PDO2Array_node3DType      60
      #define ODA_remoteNodeRX_PDO2Array_node3EType      61
      #define ODA_remoteNodeRX_PDO2Array_node3FType      62
      #define ODA_remoteNodeRX_PDO2Array_node40Type      63
      #define ODA_remoteNodeRX_PDO2Array_node41Type      64
      #define ODA_remoteNodeRX_PDO2Array_node42Type      65
      #define ODA_remoteNodeRX_PDO2Array_node43Type      66
      #define ODA_remoteNodeRX_PDO2Array_node44Type      67
      #define ODA_remoteNodeRX_PDO2Array_node45Type      68
      #define ODA_remoteNodeRX_PDO2Array_node46Type      69
      #define ODA_remoteNodeRX_PDO2Array_node47Type      70
      #define ODA_remoteNodeRX_PDO2Array_node48Type      71
      #define ODA_remoteNodeRX_PDO2Array_node49Type      72
      #define ODA_remoteNodeRX_PDO2Array_node4AType      73
      #define ODA_remoteNodeRX_PDO2Array_node4BType      74
      #define ODA_remoteNodeRX_PDO2Array_node4CType      75
      #define ODA_remoteNodeRX_PDO2Array_node4DType      76
      #define ODA_remoteNodeRX_PDO2Array_node4EType      77
      #define ODA_remoteNodeRX_PDO2Array_node4FType      78
      #define ODA_remoteNodeRX_PDO2Array_node50Type      79
      #define ODA_remoteNodeRX_PDO2Array_node51Type      80
      #define ODA_remoteNodeRX_PDO2Array_node52Type      81
      #define ODA_remoteNodeRX_PDO2Array_node53Type      82
      #define ODA_remoteNodeRX_PDO2Array_node54Type      83
      #define ODA_remoteNodeRX_PDO2Array_node55Type      84
      #define ODA_remoteNodeRX_PDO2Array_node56Type      85
      #define ODA_remoteNodeRX_PDO2Array_node57Type      86
      #define ODA_remoteNodeRX_PDO2Array_node58Type      87
      #define ODA_remoteNodeRX_PDO2Array_node59Type      88
      #define ODA_remoteNodeRX_PDO2Array_node5AType      89
      #define ODA_remoteNodeRX_PDO2Array_node5BType      90
      #define ODA_remoteNodeRX_PDO2Array_node5CType      91
      #define ODA_remoteNodeRX_PDO2Array_node5DType      92
      #define ODA_remoteNodeRX_PDO2Array_node5EType      93
      #define ODA_remoteNodeRX_PDO2Array_node5FType      94
      #define ODA_remoteNodeRX_PDO2Array_node60Type      95
      #define ODA_remoteNodeRX_PDO2Array_node61Type      96
      #define ODA_remoteNodeRX_PDO2Array_node62Type      97
      #define ODA_remoteNodeRX_PDO2Array_node63Type      98
      #define ODA_remoteNodeRX_PDO2Array_node64Type      99
      #define ODA_remoteNodeRX_PDO2Array_node65Type      100
      #define ODA_remoteNodeRX_PDO2Array_node66Type      101
      #define ODA_remoteNodeRX_PDO2Array_node67Type      102
      #define ODA_remoteNodeRX_PDO2Array_node68Type      103
      #define ODA_remoteNodeRX_PDO2Array_node69Type      104
      #define ODA_remoteNodeRX_PDO2Array_node6AType      105
      #define ODA_remoteNodeRX_PDO2Array_node6BType      106
      #define ODA_remoteNodeRX_PDO2Array_node6CType      107
      #define ODA_remoteNodeRX_PDO2Array_node6DType      108
      #define ODA_remoteNodeRX_PDO2Array_node6EType      109
      #define ODA_remoteNodeRX_PDO2Array_node6FType      110
      #define ODA_remoteNodeRX_PDO2Array_node70Type      111
      #define ODA_remoteNodeRX_PDO2Array_node71Type      112
      #define ODA_remoteNodeRX_PDO2Array_node72Type      113
      #define ODA_remoteNodeRX_PDO2Array_node73Type      114
      #define ODA_remoteNodeRX_PDO2Array_node74Type      115
      #define ODA_remoteNodeRX_PDO2Array_node75Type      116
      #define ODA_remoteNodeRX_PDO2Array_node76Type      117
      #define ODA_remoteNodeRX_PDO2Array_node77Type      118
      #define ODA_remoteNodeRX_PDO2Array_node78Type      119
      #define ODA_remoteNodeRX_PDO2Array_node79Type      120
      #define ODA_remoteNodeRX_PDO2Array_node7AType      121
      #define ODA_remoteNodeRX_PDO2Array_node7BType      122
      #define ODA_remoteNodeRX_PDO2Array_node7CType      123
      #define ODA_remoteNodeRX_PDO2Array_node7DType      124
      #define ODA_remoteNodeRX_PDO2Array_node7EType      125
      #define ODA_remoteNodeRX_PDO2Array_node7FType      126

/*2105, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeServerSDOArray                CO_OD_ROM.remoteNodeServerSDOArray
      #define ODL_remoteNodeServerSDOArray_arrayLength   127
      #define ODA_remoteNodeServerSDOArray_node01Type    0
      #define ODA_remoteNodeServerSDOArray_node02Type    1
      #define ODA_remoteNodeServerSDOArray_node03Type    2
      #define ODA_remoteNodeServerSDOArray_node04Type    3
      #define ODA_remoteNodeServerSDOArray_node05Type    4
      #define ODA_remoteNodeServerSDOArray_node06Type    5
      #define ODA_remoteNodeServerSDOArray_node07Type    6
      #define ODA_remoteNodeServerSDOArray_node08Type    7
      #define ODA_remoteNodeServerSDOArray_node09Type    8
      #define ODA_remoteNodeServerSDOArray_node0AType    9
      #define ODA_remoteNodeServerSDOArray_node0BType    10
      #define ODA_remoteNodeServerSDOArray_node0CType    11
      #define ODA_remoteNodeServerSDOArray_node0DType    12
      #define ODA_remoteNodeServerSDOArray_node0EType    13
      #define ODA_remoteNodeServerSDOArray_node0FType    14
      #define ODA_remoteNodeServerSDOArray_node10Type    15
      #define ODA_remoteNodeServerSDOArray_node11Type    16
      #define ODA_remoteNodeServerSDOArray_node12Type    17
      #define ODA_remoteNodeServerSDOArray_node13Type    18
      #define ODA_remoteNodeServerSDOArray_node14Type    19
      #define ODA_remoteNodeServerSDOArray_node15Type    20
      #define ODA_remoteNodeServerSDOArray_node16Type    21
      #define ODA_remoteNodeServerSDOArray_node17Type    22
      #define ODA_remoteNodeServerSDOArray_node18Type    23
      #define ODA_remoteNodeServerSDOArray_node19Type    24
      #define ODA_remoteNodeServerSDOArray_node1AType    25
      #define ODA_remoteNodeServerSDOArray_node1BType    26
      #define ODA_remoteNodeServerSDOArray_node1CType    27
      #define ODA_remoteNodeServerSDOArray_node1DType    28
      #define ODA_remoteNodeServerSDOArray_node1EType    29
      #define ODA_remoteNodeServerSDOArray_node1FType    30
      #define ODA_remoteNodeServerSDOArray_node20Type    31
      #define ODA_remoteNodeServerSDOArray_node21Type    32
      #define ODA_remoteNodeServerSDOArray_node22Type    33
      #define ODA_remoteNodeServerSDOArray_node23Type    34
      #define ODA_remoteNodeServerSDOArray_node24Type    35
      #define ODA_remoteNodeServerSDOArray_node25Type    36
      #define ODA_remoteNodeServerSDOArray_node26Type    37
      #define ODA_remoteNodeServerSDOArray_node27Type    38
      #define ODA_remoteNodeServerSDOArray_node28Type    39
      #define ODA_remoteNodeServerSDOArray_node29Type    40
      #define ODA_remoteNodeServerSDOArray_node2AType    41
      #define ODA_remoteNodeServerSDOArray_node2BType    42
      #define ODA_remoteNodeServerSDOArray_node2CType    43
      #define ODA_remoteNodeServerSDOArray_node2DType    44
      #define ODA_remoteNodeServerSDOArray_node2EType    45
      #define ODA_remoteNodeServerSDOArray_node2FType    46
      #define ODA_remoteNodeServerSDOArray_node30Type    47
      #define ODA_remoteNodeServerSDOArray_node31Type    48
      #define ODA_remoteNodeServerSDOArray_node32Type    49
      #define ODA_remoteNodeServerSDOArray_node33Type    50
      #define ODA_remoteNodeServerSDOArray_node34Type    51
      #define ODA_remoteNodeServerSDOArray_node35Type    52
      #define ODA_remoteNodeServerSDOArray_node36Type    53
      #define ODA_remoteNodeServerSDOArray_node37Type    54
      #define ODA_remoteNodeServerSDOArray_node38Type    55
      #define ODA_remoteNodeServerSDOArray_node39Type    56
      #define ODA_remoteNodeServerSDOArray_node3AType    57
      #define ODA_remoteNodeServerSDOArray_node3BType    58
      #define ODA_remoteNodeServerSDOArray_node3CType    59
      #define ODA_remoteNodeServerSDOArray_node3DType    60
      #define ODA_remoteNodeServerSDOArray_node3EType    61
      #define ODA_remoteNodeServerSDOArray_node3FType    62
      #define ODA_remoteNodeServerSDOArray_node40Type    63
      #define ODA_remoteNodeServerSDOArray_node41Type    64
      #define ODA_remoteNodeServerSDOArray_node42Type    65
      #define ODA_remoteNodeServerSDOArray_node43Type    66
      #define ODA_remoteNodeServerSDOArray_node44Type    67
      #define ODA_remoteNodeServerSDOArray_node45Type    68
      #define ODA_remoteNodeServerSDOArray_node46Type    69
      #define ODA_remoteNodeServerSDOArray_node47Type    70
      #define ODA_remoteNodeServerSDOArray_node48Type    71
      #define ODA_remoteNodeServerSDOArray_node49Type    72
      #define ODA_remoteNodeServerSDOArray_node4AType    73
      #define ODA_remoteNodeServerSDOArray_node4BType    74
      #define ODA_remoteNodeServerSDOArray_node4CType    75
      #define ODA_remoteNodeServerSDOArray_node4DType    76
      #define ODA_remoteNodeServerSDOArray_node4EType    77
      #define ODA_remoteNodeServerSDOArray_node4FType    78
      #define ODA_remoteNodeServerSDOArray_node50Type    79
      #define ODA_remoteNodeServerSDOArray_node51Type    80
      #define ODA_remoteNodeServerSDOArray_node52Type    81
      #define ODA_remoteNodeServerSDOArray_node53Type    82
      #define ODA_remoteNodeServerSDOArray_node54Type    83
      #define ODA_remoteNodeServerSDOArray_node55Type    84
      #define ODA_remoteNodeServerSDOArray_node56Type    85
      #define ODA_remoteNodeServerSDOArray_node57Type    86
      #define ODA_remoteNodeServerSDOArray_node58Type    87
      #define ODA_remoteNodeServerSDOArray_node59Type    88
      #define ODA_remoteNodeServerSDOArray_node5AType    89
      #define ODA_remoteNodeServerSDOArray_node5BType    90
      #define ODA_remoteNodeServerSDOArray_node5CType    91
      #define ODA_remoteNodeServerSDOArray_node5DType    92
      #define ODA_remoteNodeServerSDOArray_node5EType    93
      #define ODA_remoteNodeServerSDOArray_node5FType    94
      #define ODA_remoteNodeServerSDOArray_node60Type    95
      #define ODA_remoteNodeServerSDOArray_node61Type    96
      #define ODA_remoteNodeServerSDOArray_node62Type    97
      #define ODA_remoteNodeServerSDOArray_node63Type    98
      #define ODA_remoteNodeServerSDOArray_node64Type    99
      #define ODA_remoteNodeServerSDOArray_node65Type    100
      #define ODA_remoteNodeServerSDOArray_node66Type    101
      #define ODA_remoteNodeServerSDOArray_node67Type    102
      #define ODA_remoteNodeServerSDOArray_node68Type    103
      #define ODA_remoteNodeServerSDOArray_node69Type    104
      #define ODA_remoteNodeServerSDOArray_node6AType    105
      #define ODA_remoteNodeServerSDOArray_node6BType    106
      #define ODA_remoteNodeServerSDOArray_node6CType    107
      #define ODA_remoteNodeServerSDOArray_node6DType    108
      #define ODA_remoteNodeServerSDOArray_node6EType    109
      #define ODA_remoteNodeServerSDOArray_node6FType    110
      #define ODA_remoteNodeServerSDOArray_node70Type    111
      #define ODA_remoteNodeServerSDOArray_node71Type    112
      #define ODA_remoteNodeServerSDOArray_node72Type    113
      #define ODA_remoteNodeServerSDOArray_node73Type    114
      #define ODA_remoteNodeServerSDOArray_node74Type    115
      #define ODA_remoteNodeServerSDOArray_node75Type    116
      #define ODA_remoteNodeServerSDOArray_node76Type    117
      #define ODA_remoteNodeServerSDOArray_node77Type    118
      #define ODA_remoteNodeServerSDOArray_node78Type    119
      #define ODA_remoteNodeServerSDOArray_node79Type    120
      #define ODA_remoteNodeServerSDOArray_node7AType    121
      #define ODA_remoteNodeServerSDOArray_node7BType    122
      #define ODA_remoteNodeServerSDOArray_node7CType    123
      #define ODA_remoteNodeServerSDOArray_node7DType    124
      #define ODA_remoteNodeServerSDOArray_node7EType    125
      #define ODA_remoteNodeServerSDOArray_node7FType    126

/*2106, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeClientSDOArray                CO_OD_ROM.remoteNodeClientSDOArray
      #define ODL_remoteNodeClientSDOArray_arrayLength   127
      #define ODA_remoteNodeClientSDOArray_node01Type    0
      #define ODA_remoteNodeClientSDOArray_node02Type    1
      #define ODA_remoteNodeClientSDOArray_node03Type    2
      #define ODA_remoteNodeClientSDOArray_node04Type    3
      #define ODA_remoteNodeClientSDOArray_node05Type    4
      #define ODA_remoteNodeClientSDOArray_node06Type    5
      #define ODA_remoteNodeClientSDOArray_node07Type    6
      #define ODA_remoteNodeClientSDOArray_node08Type    7
      #define ODA_remoteNodeClientSDOArray_node09Type    8
      #define ODA_remoteNodeClientSDOArray_node0AType    9
      #define ODA_remoteNodeClientSDOArray_node0BType    10
      #define ODA_remoteNodeClientSDOArray_node0CType    11
      #define ODA_remoteNodeClientSDOArray_node0DType    12
      #define ODA_remoteNodeClientSDOArray_node0EType    13
      #define ODA_remoteNodeClientSDOArray_node0FType    14
      #define ODA_remoteNodeClientSDOArray_node10Type    15
      #define ODA_remoteNodeClientSDOArray_node11Type    16
      #define ODA_remoteNodeClientSDOArray_node12Type    17
      #define ODA_remoteNodeClientSDOArray_node13Type    18
      #define ODA_remoteNodeClientSDOArray_node14Type    19
      #define ODA_remoteNodeClientSDOArray_node15Type    20
      #define ODA_remoteNodeClientSDOArray_node16Type    21
      #define ODA_remoteNodeClientSDOArray_node17Type    22
      #define ODA_remoteNodeClientSDOArray_node18Type    23
      #define ODA_remoteNodeClientSDOArray_node19Type    24
      #define ODA_remoteNodeClientSDOArray_node1AType    25
      #define ODA_remoteNodeClientSDOArray_node1BType    26
      #define ODA_remoteNodeClientSDOArray_node1CType    27
      #define ODA_remoteNodeClientSDOArray_node1DType    28
      #define ODA_remoteNodeClientSDOArray_node1EType    29
      #define ODA_remoteNodeClientSDOArray_node1FType    30
      #define ODA_remoteNodeClientSDOArray_node20Type    31
      #define ODA_remoteNodeClientSDOArray_node21Type    32
      #define ODA_remoteNodeClientSDOArray_node22Type    33
      #define ODA_remoteNodeClientSDOArray_node23Type    34
      #define ODA_remoteNodeClientSDOArray_node24Type    35
      #define ODA_remoteNodeClientSDOArray_node25Type    36
      #define ODA_remoteNodeClientSDOArray_node26Type    37
      #define ODA_remoteNodeClientSDOArray_node27Type    38
      #define ODA_remoteNodeClientSDOArray_node28Type    39
      #define ODA_remoteNodeClientSDOArray_node29Type    40
      #define ODA_remoteNodeClientSDOArray_node2AType    41
      #define ODA_remoteNodeClientSDOArray_node2BType    42
      #define ODA_remoteNodeClientSDOArray_node2CType    43
      #define ODA_remoteNodeClientSDOArray_node2DType    44
      #define ODA_remoteNodeClientSDOArray_node2EType    45
      #define ODA_remoteNodeClientSDOArray_node2FType    46
      #define ODA_remoteNodeClientSDOArray_node30Type    47
      #define ODA_remoteNodeClientSDOArray_node31Type    48
      #define ODA_remoteNodeClientSDOArray_node32Type    49
      #define ODA_remoteNodeClientSDOArray_node33Type    50
      #define ODA_remoteNodeClientSDOArray_node34Type    51
      #define ODA_remoteNodeClientSDOArray_node35Type    52
      #define ODA_remoteNodeClientSDOArray_node36Type    53
      #define ODA_remoteNodeClientSDOArray_node37Type    54
      #define ODA_remoteNodeClientSDOArray_node38Type    55
      #define ODA_remoteNodeClientSDOArray_node39Type    56
      #define ODA_remoteNodeClientSDOArray_node3AType    57
      #define ODA_remoteNodeClientSDOArray_node3BType    58
      #define ODA_remoteNodeClientSDOArray_node3CType    59
      #define ODA_remoteNodeClientSDOArray_node3DType    60
      #define ODA_remoteNodeClientSDOArray_node3EType    61
      #define ODA_remoteNodeClientSDOArray_node3FType    62
      #define ODA_remoteNodeClientSDOArray_node40Type    63
      #define ODA_remoteNodeClientSDOArray_node41Type    64
      #define ODA_remoteNodeClientSDOArray_node42Type    65
      #define ODA_remoteNodeClientSDOArray_node43Type    66
      #define ODA_remoteNodeClientSDOArray_node44Type    67
      #define ODA_remoteNodeClientSDOArray_node45Type    68
      #define ODA_remoteNodeClientSDOArray_node46Type    69
      #define ODA_remoteNodeClientSDOArray_node47Type    70
      #define ODA_remoteNodeClientSDOArray_node48Type    71
      #define ODA_remoteNodeClientSDOArray_node49Type    72
      #define ODA_remoteNodeClientSDOArray_node4AType    73
      #define ODA_remoteNodeClientSDOArray_node4BType    74
      #define ODA_remoteNodeClientSDOArray_node4CType    75
      #define ODA_remoteNodeClientSDOArray_node4DType    76
      #define ODA_remoteNodeClientSDOArray_node4EType    77
      #define ODA_remoteNodeClientSDOArray_node4FType    78
      #define ODA_remoteNodeClientSDOArray_node50Type    79
      #define ODA_remoteNodeClientSDOArray_node51Type    80
      #define ODA_remoteNodeClientSDOArray_node52Type    81
      #define ODA_remoteNodeClientSDOArray_node53Type    82
      #define ODA_remoteNodeClientSDOArray_node54Type    83
      #define ODA_remoteNodeClientSDOArray_node55Type    84
      #define ODA_remoteNodeClientSDOArray_node56Type    85
      #define ODA_remoteNodeClientSDOArray_node57Type    86
      #define ODA_remoteNodeClientSDOArray_node58Type    87
      #define ODA_remoteNodeClientSDOArray_node59Type    88
      #define ODA_remoteNodeClientSDOArray_node5AType    89
      #define ODA_remoteNodeClientSDOArray_node5BType    90
      #define ODA_remoteNodeClientSDOArray_node5CType    91
      #define ODA_remoteNodeClientSDOArray_node5DType    92
      #define ODA_remoteNodeClientSDOArray_node5EType    93
      #define ODA_remoteNodeClientSDOArray_node5FType    94
      #define ODA_remoteNodeClientSDOArray_node60Type    95
      #define ODA_remoteNodeClientSDOArray_node61Type    96
      #define ODA_remoteNodeClientSDOArray_node62Type    97
      #define ODA_remoteNodeClientSDOArray_node63Type    98
      #define ODA_remoteNodeClientSDOArray_node64Type    99
      #define ODA_remoteNodeClientSDOArray_node65Type    100
      #define ODA_remoteNodeClientSDOArray_node66Type    101
      #define ODA_remoteNodeClientSDOArray_node67Type    102
      #define ODA_remoteNodeClientSDOArray_node68Type    103
      #define ODA_remoteNodeClientSDOArray_node69Type    104
      #define ODA_remoteNodeClientSDOArray_node6AType    105
      #define ODA_remoteNodeClientSDOArray_node6BType    106
      #define ODA_remoteNodeClientSDOArray_node6CType    107
      #define ODA_remoteNodeClientSDOArray_node6DType    108
      #define ODA_remoteNodeClientSDOArray_node6EType    109
      #define ODA_remoteNodeClientSDOArray_node6FType    110
      #define ODA_remoteNodeClientSDOArray_node70Type    111
      #define ODA_remoteNodeClientSDOArray_node71Type    112
      #define ODA_remoteNodeClientSDOArray_node72Type    113
      #define ODA_remoteNodeClientSDOArray_node73Type    114
      #define ODA_remoteNodeClientSDOArray_node74Type    115
      #define ODA_remoteNodeClientSDOArray_node75Type    116
      #define ODA_remoteNodeClientSDOArray_node76Type    117
      #define ODA_remoteNodeClientSDOArray_node77Type    118
      #define ODA_remoteNodeClientSDOArray_node78Type    119
      #define ODA_remoteNodeClientSDOArray_node79Type    120
      #define ODA_remoteNodeClientSDOArray_node7AType    121
      #define ODA_remoteNodeClientSDOArray_node7BType    122
      #define ODA_remoteNodeClientSDOArray_node7CType    123
      #define ODA_remoteNodeClientSDOArray_node7DType    124
      #define ODA_remoteNodeClientSDOArray_node7EType    125
      #define ODA_remoteNodeClientSDOArray_node7FType    126

/*2107, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeDigitalOutputBytesArray       CO_OD_ROM.remoteNodeDigitalOutputBytesArray
      #define ODL_remoteNodeDigitalOutputBytesArray_arrayLength 127
      #define ODA_remoteNodeDigitalOutputBytesArray_node01Type 0
      #define ODA_remoteNodeDigitalOutputBytesArray_node02Type 1
      #define ODA_remoteNodeDigitalOutputBytesArray_node03Type 2
      #define ODA_remoteNodeDigitalOutputBytesArray_node04Type 3
      #define ODA_remoteNodeDigitalOutputBytesArray_node05Type 4
      #define ODA_remoteNodeDigitalOutputBytesArray_node06Type 5
      #define ODA_remoteNodeDigitalOutputBytesArray_node07Type 6
      #define ODA_remoteNodeDigitalOutputBytesArray_node08Type 7
      #define ODA_remoteNodeDigitalOutputBytesArray_node09Type 8
      #define ODA_remoteNodeDigitalOutputBytesArray_node0AType 9
      #define ODA_remoteNodeDigitalOutputBytesArray_node0BType 10
      #define ODA_remoteNodeDigitalOutputBytesArray_node0CType 11
      #define ODA_remoteNodeDigitalOutputBytesArray_node0DType 12
      #define ODA_remoteNodeDigitalOutputBytesArray_node0EType 13
      #define ODA_remoteNodeDigitalOutputBytesArray_node0FType 14
      #define ODA_remoteNodeDigitalOutputBytesArray_node10Type 15
      #define ODA_remoteNodeDigitalOutputBytesArray_node11Type 16
      #define ODA_remoteNodeDigitalOutputBytesArray_node12Type 17
      #define ODA_remoteNodeDigitalOutputBytesArray_node13Type 18
      #define ODA_remoteNodeDigitalOutputBytesArray_node14Type 19
      #define ODA_remoteNodeDigitalOutputBytesArray_node15Type 20
      #define ODA_remoteNodeDigitalOutputBytesArray_node16Type 21
      #define ODA_remoteNodeDigitalOutputBytesArray_node17Type 22
      #define ODA_remoteNodeDigitalOutputBytesArray_node18Type 23
      #define ODA_remoteNodeDigitalOutputBytesArray_node19Type 24
      #define ODA_remoteNodeDigitalOutputBytesArray_node1AType 25
      #define ODA_remoteNodeDigitalOutputBytesArray_node1BType 26
      #define ODA_remoteNodeDigitalOutputBytesArray_node1CType 27
      #define ODA_remoteNodeDigitalOutputBytesArray_node1DType 28
      #define ODA_remoteNodeDigitalOutputBytesArray_node1EType 29
      #define ODA_remoteNodeDigitalOutputBytesArray_node1FType 30
      #define ODA_remoteNodeDigitalOutputBytesArray_node20Type 31
      #define ODA_remoteNodeDigitalOutputBytesArray_node21Type 32
      #define ODA_remoteNodeDigitalOutputBytesArray_node22Type 33
      #define ODA_remoteNodeDigitalOutputBytesArray_node23Type 34
      #define ODA_remoteNodeDigitalOutputBytesArray_node24Type 35
      #define ODA_remoteNodeDigitalOutputBytesArray_node25Type 36
      #define ODA_remoteNodeDigitalOutputBytesArray_node26Type 37
      #define ODA_remoteNodeDigitalOutputBytesArray_node27Type 38
      #define ODA_remoteNodeDigitalOutputBytesArray_node28Type 39
      #define ODA_remoteNodeDigitalOutputBytesArray_node29Type 40
      #define ODA_remoteNodeDigitalOutputBytesArray_node2AType 41
      #define ODA_remoteNodeDigitalOutputBytesArray_node2BType 42
      #define ODA_remoteNodeDigitalOutputBytesArray_node2CType 43
      #define ODA_remoteNodeDigitalOutputBytesArray_node2DType 44
      #define ODA_remoteNodeDigitalOutputBytesArray_node2EType 45
      #define ODA_remoteNodeDigitalOutputBytesArray_node2FType 46
      #define ODA_remoteNodeDigitalOutputBytesArray_node30Type 47
      #define ODA_remoteNodeDigitalOutputBytesArray_node31Type 48
      #define ODA_remoteNodeDigitalOutputBytesArray_node32Type 49
      #define ODA_remoteNodeDigitalOutputBytesArray_node33Type 50
      #define ODA_remoteNodeDigitalOutputBytesArray_node34Type 51
      #define ODA_remoteNodeDigitalOutputBytesArray_node35Type 52
      #define ODA_remoteNodeDigitalOutputBytesArray_node36Type 53
      #define ODA_remoteNodeDigitalOutputBytesArray_node37Type 54
      #define ODA_remoteNodeDigitalOutputBytesArray_node38Type 55
      #define ODA_remoteNodeDigitalOutputBytesArray_node39Type 56
      #define ODA_remoteNodeDigitalOutputBytesArray_node3AType 57
      #define ODA_remoteNodeDigitalOutputBytesArray_node3BType 58
      #define ODA_remoteNodeDigitalOutputBytesArray_node3CType 59
      #define ODA_remoteNodeDigitalOutputBytesArray_node3DType 60
      #define ODA_remoteNodeDigitalOutputBytesArray_node3EType 61
      #define ODA_remoteNodeDigitalOutputBytesArray_node3FType 62
      #define ODA_remoteNodeDigitalOutputBytesArray_node40Type 63
      #define ODA_remoteNodeDigitalOutputBytesArray_node41Type 64
      #define ODA_remoteNodeDigitalOutputBytesArray_node42Type 65
      #define ODA_remoteNodeDigitalOutputBytesArray_node43Type 66
      #define ODA_remoteNodeDigitalOutputBytesArray_node44Type 67
      #define ODA_remoteNodeDigitalOutputBytesArray_node45Type 68
      #define ODA_remoteNodeDigitalOutputBytesArray_node46Type 69
      #define ODA_remoteNodeDigitalOutputBytesArray_node47Type 70
      #define ODA_remoteNodeDigitalOutputBytesArray_node48Type 71
      #define ODA_remoteNodeDigitalOutputBytesArray_node49Type 72
      #define ODA_remoteNodeDigitalOutputBytesArray_node4AType 73
      #define ODA_remoteNodeDigitalOutputBytesArray_node4BType 74
      #define ODA_remoteNodeDigitalOutputBytesArray_node4CType 75
      #define ODA_remoteNodeDigitalOutputBytesArray_node4DType 76
      #define ODA_remoteNodeDigitalOutputBytesArray_node4EType 77
      #define ODA_remoteNodeDigitalOutputBytesArray_node4FType 78
      #define ODA_remoteNodeDigitalOutputBytesArray_node50Type 79
      #define ODA_remoteNodeDigitalOutputBytesArray_node51Type 80
      #define ODA_remoteNodeDigitalOutputBytesArray_node52Type 81
      #define ODA_remoteNodeDigitalOutputBytesArray_node53Type 82
      #define ODA_remoteNodeDigitalOutputBytesArray_node54Type 83
      #define ODA_remoteNodeDigitalOutputBytesArray_node55Type 84
      #define ODA_remoteNodeDigitalOutputBytesArray_node56Type 85
      #define ODA_remoteNodeDigitalOutputBytesArray_node57Type 86
      #define ODA_remoteNodeDigitalOutputBytesArray_node58Type 87
      #define ODA_remoteNodeDigitalOutputBytesArray_node59Type 88
      #define ODA_remoteNodeDigitalOutputBytesArray_node5AType 89
      #define ODA_remoteNodeDigitalOutputBytesArray_node5BType 90
      #define ODA_remoteNodeDigitalOutputBytesArray_node5CType 91
      #define ODA_remoteNodeDigitalOutputBytesArray_node5DType 92
      #define ODA_remoteNodeDigitalOutputBytesArray_node5EType 93
      #define ODA_remoteNodeDigitalOutputBytesArray_node5FType 94
      #define ODA_remoteNodeDigitalOutputBytesArray_node60Type 95
      #define ODA_remoteNodeDigitalOutputBytesArray_node61Type 96
      #define ODA_remoteNodeDigitalOutputBytesArray_node62Type 97
      #define ODA_remoteNodeDigitalOutputBytesArray_node63Type 98
      #define ODA_remoteNodeDigitalOutputBytesArray_node64Type 99
      #define ODA_remoteNodeDigitalOutputBytesArray_node65Type 100
      #define ODA_remoteNodeDigitalOutputBytesArray_node66Type 101
      #define ODA_remoteNodeDigitalOutputBytesArray_node67Type 102
      #define ODA_remoteNodeDigitalOutputBytesArray_node68Type 103
      #define ODA_remoteNodeDigitalOutputBytesArray_node69Type 104
      #define ODA_remoteNodeDigitalOutputBytesArray_node6AType 105
      #define ODA_remoteNodeDigitalOutputBytesArray_node6BType 106
      #define ODA_remoteNodeDigitalOutputBytesArray_node6CType 107
      #define ODA_remoteNodeDigitalOutputBytesArray_node6DType 108
      #define ODA_remoteNodeDigitalOutputBytesArray_node6EType 109
      #define ODA_remoteNodeDigitalOutputBytesArray_node6FType 110
      #define ODA_remoteNodeDigitalOutputBytesArray_node70Type 111
      #define ODA_remoteNodeDigitalOutputBytesArray_node71Type 112
      #define ODA_remoteNodeDigitalOutputBytesArray_node72Type 113
      #define ODA_remoteNodeDigitalOutputBytesArray_node73Type 114
      #define ODA_remoteNodeDigitalOutputBytesArray_node74Type 115
      #define ODA_remoteNodeDigitalOutputBytesArray_node75Type 116
      #define ODA_remoteNodeDigitalOutputBytesArray_node76Type 117
      #define ODA_remoteNodeDigitalOutputBytesArray_node77Type 118
      #define ODA_remoteNodeDigitalOutputBytesArray_node78Type 119
      #define ODA_remoteNodeDigitalOutputBytesArray_node79Type 120
      #define ODA_remoteNodeDigitalOutputBytesArray_node7AType 121
      #define ODA_remoteNodeDigitalOutputBytesArray_node7BType 122
      #define ODA_remoteNodeDigitalOutputBytesArray_node7CType 123
      #define ODA_remoteNodeDigitalOutputBytesArray_node7DType 124
      #define ODA_remoteNodeDigitalOutputBytesArray_node7EType 125
      #define ODA_remoteNodeDigitalOutputBytesArray_node7FType 126

/*2108, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeInputBytesArray               CO_OD_ROM.remoteNodeInputBytesArray
      #define ODL_remoteNodeInputBytesArray_arrayLength  127
      #define ODA_remoteNodeInputBytesArray_node01Type   0
      #define ODA_remoteNodeInputBytesArray_node02Type   1
      #define ODA_remoteNodeInputBytesArray_node03Type   2
      #define ODA_remoteNodeInputBytesArray_node04Type   3
      #define ODA_remoteNodeInputBytesArray_node05Type   4
      #define ODA_remoteNodeInputBytesArray_node06Type   5
      #define ODA_remoteNodeInputBytesArray_node07Type   6
      #define ODA_remoteNodeInputBytesArray_node08Type   7
      #define ODA_remoteNodeInputBytesArray_node09Type   8
      #define ODA_remoteNodeInputBytesArray_node0AType   9
      #define ODA_remoteNodeInputBytesArray_node0BType   10
      #define ODA_remoteNodeInputBytesArray_node0CType   11
      #define ODA_remoteNodeInputBytesArray_node0DType   12
      #define ODA_remoteNodeInputBytesArray_node0EType   13
      #define ODA_remoteNodeInputBytesArray_node0FType   14
      #define ODA_remoteNodeInputBytesArray_node10Type   15
      #define ODA_remoteNodeInputBytesArray_node11Type   16
      #define ODA_remoteNodeInputBytesArray_node12Type   17
      #define ODA_remoteNodeInputBytesArray_node13Type   18
      #define ODA_remoteNodeInputBytesArray_node14Type   19
      #define ODA_remoteNodeInputBytesArray_node15Type   20
      #define ODA_remoteNodeInputBytesArray_node16Type   21
      #define ODA_remoteNodeInputBytesArray_node17Type   22
      #define ODA_remoteNodeInputBytesArray_node18Type   23
      #define ODA_remoteNodeInputBytesArray_node19Type   24
      #define ODA_remoteNodeInputBytesArray_node1AType   25
      #define ODA_remoteNodeInputBytesArray_node1BType   26
      #define ODA_remoteNodeInputBytesArray_node1CType   27
      #define ODA_remoteNodeInputBytesArray_node1DType   28
      #define ODA_remoteNodeInputBytesArray_node1EType   29
      #define ODA_remoteNodeInputBytesArray_node1FType   30
      #define ODA_remoteNodeInputBytesArray_node20Type   31
      #define ODA_remoteNodeInputBytesArray_node21Type   32
      #define ODA_remoteNodeInputBytesArray_node22Type   33
      #define ODA_remoteNodeInputBytesArray_node23Type   34
      #define ODA_remoteNodeInputBytesArray_node24Type   35
      #define ODA_remoteNodeInputBytesArray_node25Type   36
      #define ODA_remoteNodeInputBytesArray_node26Type   37
      #define ODA_remoteNodeInputBytesArray_node27Type   38
      #define ODA_remoteNodeInputBytesArray_node28Type   39
      #define ODA_remoteNodeInputBytesArray_node29Type   40
      #define ODA_remoteNodeInputBytesArray_node2AType   41
      #define ODA_remoteNodeInputBytesArray_node2BType   42
      #define ODA_remoteNodeInputBytesArray_node2CType   43
      #define ODA_remoteNodeInputBytesArray_node2DType   44
      #define ODA_remoteNodeInputBytesArray_node2EType   45
      #define ODA_remoteNodeInputBytesArray_node2FType   46
      #define ODA_remoteNodeInputBytesArray_node30Type   47
      #define ODA_remoteNodeInputBytesArray_node31Type   48
      #define ODA_remoteNodeInputBytesArray_node32Type   49
      #define ODA_remoteNodeInputBytesArray_node33Type   50
      #define ODA_remoteNodeInputBytesArray_node34Type   51
      #define ODA_remoteNodeInputBytesArray_node35Type   52
      #define ODA_remoteNodeInputBytesArray_node36Type   53
      #define ODA_remoteNodeInputBytesArray_node37Type   54
      #define ODA_remoteNodeInputBytesArray_node38Type   55
      #define ODA_remoteNodeInputBytesArray_node39Type   56
      #define ODA_remoteNodeInputBytesArray_node3AType   57
      #define ODA_remoteNodeInputBytesArray_node3BType   58
      #define ODA_remoteNodeInputBytesArray_node3CType   59
      #define ODA_remoteNodeInputBytesArray_node3DType   60
      #define ODA_remoteNodeInputBytesArray_node3EType   61
      #define ODA_remoteNodeInputBytesArray_node3FType   62
      #define ODA_remoteNodeInputBytesArray_node40Type   63
      #define ODA_remoteNodeInputBytesArray_node41Type   64
      #define ODA_remoteNodeInputBytesArray_node42Type   65
      #define ODA_remoteNodeInputBytesArray_node43Type   66
      #define ODA_remoteNodeInputBytesArray_node44Type   67
      #define ODA_remoteNodeInputBytesArray_node45Type   68
      #define ODA_remoteNodeInputBytesArray_node46Type   69
      #define ODA_remoteNodeInputBytesArray_node47Type   70
      #define ODA_remoteNodeInputBytesArray_node48Type   71
      #define ODA_remoteNodeInputBytesArray_node49Type   72
      #define ODA_remoteNodeInputBytesArray_node4AType   73
      #define ODA_remoteNodeInputBytesArray_node4BType   74
      #define ODA_remoteNodeInputBytesArray_node4CType   75
      #define ODA_remoteNodeInputBytesArray_node4DType   76
      #define ODA_remoteNodeInputBytesArray_node4EType   77
      #define ODA_remoteNodeInputBytesArray_node4FType   78
      #define ODA_remoteNodeInputBytesArray_node50Type   79
      #define ODA_remoteNodeInputBytesArray_node51Type   80
      #define ODA_remoteNodeInputBytesArray_node52Type   81
      #define ODA_remoteNodeInputBytesArray_node53Type   82
      #define ODA_remoteNodeInputBytesArray_node54Type   83
      #define ODA_remoteNodeInputBytesArray_node55Type   84
      #define ODA_remoteNodeInputBytesArray_node56Type   85
      #define ODA_remoteNodeInputBytesArray_node57Type   86
      #define ODA_remoteNodeInputBytesArray_node58Type   87
      #define ODA_remoteNodeInputBytesArray_node59Type   88
      #define ODA_remoteNodeInputBytesArray_node5AType   89
      #define ODA_remoteNodeInputBytesArray_node5BType   90
      #define ODA_remoteNodeInputBytesArray_node5CType   91
      #define ODA_remoteNodeInputBytesArray_node5DType   92
      #define ODA_remoteNodeInputBytesArray_node5EType   93
      #define ODA_remoteNodeInputBytesArray_node5FType   94
      #define ODA_remoteNodeInputBytesArray_node60Type   95
      #define ODA_remoteNodeInputBytesArray_node61Type   96
      #define ODA_remoteNodeInputBytesArray_node62Type   97
      #define ODA_remoteNodeInputBytesArray_node63Type   98
      #define ODA_remoteNodeInputBytesArray_node64Type   99
      #define ODA_remoteNodeInputBytesArray_node65Type   100
      #define ODA_remoteNodeInputBytesArray_node66Type   101
      #define ODA_remoteNodeInputBytesArray_node67Type   102
      #define ODA_remoteNodeInputBytesArray_node68Type   103
      #define ODA_remoteNodeInputBytesArray_node69Type   104
      #define ODA_remoteNodeInputBytesArray_node6AType   105
      #define ODA_remoteNodeInputBytesArray_node6BType   106
      #define ODA_remoteNodeInputBytesArray_node6CType   107
      #define ODA_remoteNodeInputBytesArray_node6DType   108
      #define ODA_remoteNodeInputBytesArray_node6EType   109
      #define ODA_remoteNodeInputBytesArray_node6FType   110
      #define ODA_remoteNodeInputBytesArray_node70Type   111
      #define ODA_remoteNodeInputBytesArray_node71Type   112
      #define ODA_remoteNodeInputBytesArray_node72Type   113
      #define ODA_remoteNodeInputBytesArray_node73Type   114
      #define ODA_remoteNodeInputBytesArray_node74Type   115
      #define ODA_remoteNodeInputBytesArray_node75Type   116
      #define ODA_remoteNodeInputBytesArray_node76Type   117
      #define ODA_remoteNodeInputBytesArray_node77Type   118
      #define ODA_remoteNodeInputBytesArray_node78Type   119
      #define ODA_remoteNodeInputBytesArray_node79Type   120
      #define ODA_remoteNodeInputBytesArray_node7AType   121
      #define ODA_remoteNodeInputBytesArray_node7BType   122
      #define ODA_remoteNodeInputBytesArray_node7CType   123
      #define ODA_remoteNodeInputBytesArray_node7DType   124
      #define ODA_remoteNodeInputBytesArray_node7EType   125
      #define ODA_remoteNodeInputBytesArray_node7FType   126

/*2109, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeTX_PDO3Array                  CO_OD_ROM.remoteNodeTX_PDO3Array
      #define ODL_remoteNodeTX_PDO3Array_arrayLength     127
      #define ODA_remoteNodeTX_PDO3Array_node01Type      0
      #define ODA_remoteNodeTX_PDO3Array_node02Type      1
      #define ODA_remoteNodeTX_PDO3Array_node03Type      2
      #define ODA_remoteNodeTX_PDO3Array_node04Type      3
      #define ODA_remoteNodeTX_PDO3Array_node05Type      4
      #define ODA_remoteNodeTX_PDO3Array_node06Type      5
      #define ODA_remoteNodeTX_PDO3Array_node07Type      6
      #define ODA_remoteNodeTX_PDO3Array_node08Type      7
      #define ODA_remoteNodeTX_PDO3Array_node09Type      8
      #define ODA_remoteNodeTX_PDO3Array_node0AType      9
      #define ODA_remoteNodeTX_PDO3Array_node0BType      10
      #define ODA_remoteNodeTX_PDO3Array_node0CType      11
      #define ODA_remoteNodeTX_PDO3Array_node0DType      12
      #define ODA_remoteNodeTX_PDO3Array_node0EType      13
      #define ODA_remoteNodeTX_PDO3Array_node0FType      14
      #define ODA_remoteNodeTX_PDO3Array_node10Type      15
      #define ODA_remoteNodeTX_PDO3Array_node11Type      16
      #define ODA_remoteNodeTX_PDO3Array_node12Type      17
      #define ODA_remoteNodeTX_PDO3Array_node13Type      18
      #define ODA_remoteNodeTX_PDO3Array_node14Type      19
      #define ODA_remoteNodeTX_PDO3Array_node15Type      20
      #define ODA_remoteNodeTX_PDO3Array_node16Type      21
      #define ODA_remoteNodeTX_PDO3Array_node17Type      22
      #define ODA_remoteNodeTX_PDO3Array_node18Type      23
      #define ODA_remoteNodeTX_PDO3Array_node19Type      24
      #define ODA_remoteNodeTX_PDO3Array_node1AType      25
      #define ODA_remoteNodeTX_PDO3Array_node1BType      26
      #define ODA_remoteNodeTX_PDO3Array_node1CType      27
      #define ODA_remoteNodeTX_PDO3Array_node1DType      28
      #define ODA_remoteNodeTX_PDO3Array_node1EType      29
      #define ODA_remoteNodeTX_PDO3Array_node1FType      30
      #define ODA_remoteNodeTX_PDO3Array_node20Type      31
      #define ODA_remoteNodeTX_PDO3Array_node21Type      32
      #define ODA_remoteNodeTX_PDO3Array_node22Type      33
      #define ODA_remoteNodeTX_PDO3Array_node23Type      34
      #define ODA_remoteNodeTX_PDO3Array_node24Type      35
      #define ODA_remoteNodeTX_PDO3Array_node25Type      36
      #define ODA_remoteNodeTX_PDO3Array_node26Type      37
      #define ODA_remoteNodeTX_PDO3Array_node27Type      38
      #define ODA_remoteNodeTX_PDO3Array_node28Type      39
      #define ODA_remoteNodeTX_PDO3Array_node29Type      40
      #define ODA_remoteNodeTX_PDO3Array_node2AType      41
      #define ODA_remoteNodeTX_PDO3Array_node2BType      42
      #define ODA_remoteNodeTX_PDO3Array_node2CType      43
      #define ODA_remoteNodeTX_PDO3Array_node2DType      44
      #define ODA_remoteNodeTX_PDO3Array_node2EType      45
      #define ODA_remoteNodeTX_PDO3Array_node2FType      46
      #define ODA_remoteNodeTX_PDO3Array_node30Type      47
      #define ODA_remoteNodeTX_PDO3Array_node31Type      48
      #define ODA_remoteNodeTX_PDO3Array_node32Type      49
      #define ODA_remoteNodeTX_PDO3Array_node33Type      50
      #define ODA_remoteNodeTX_PDO3Array_node34Type      51
      #define ODA_remoteNodeTX_PDO3Array_node35Type      52
      #define ODA_remoteNodeTX_PDO3Array_node36Type      53
      #define ODA_remoteNodeTX_PDO3Array_node37Type      54
      #define ODA_remoteNodeTX_PDO3Array_node38Type      55
      #define ODA_remoteNodeTX_PDO3Array_node39Type      56
      #define ODA_remoteNodeTX_PDO3Array_node3AType      57
      #define ODA_remoteNodeTX_PDO3Array_node3BType      58
      #define ODA_remoteNodeTX_PDO3Array_node3CType      59
      #define ODA_remoteNodeTX_PDO3Array_node3DType      60
      #define ODA_remoteNodeTX_PDO3Array_node3EType      61
      #define ODA_remoteNodeTX_PDO3Array_node3FType      62
      #define ODA_remoteNodeTX_PDO3Array_node40Type      63
      #define ODA_remoteNodeTX_PDO3Array_node41Type      64
      #define ODA_remoteNodeTX_PDO3Array_node42Type      65
      #define ODA_remoteNodeTX_PDO3Array_node43Type      66
      #define ODA_remoteNodeTX_PDO3Array_node44Type      67
      #define ODA_remoteNodeTX_PDO3Array_node45Type      68
      #define ODA_remoteNodeTX_PDO3Array_node46Type      69
      #define ODA_remoteNodeTX_PDO3Array_node47Type      70
      #define ODA_remoteNodeTX_PDO3Array_node48Type      71
      #define ODA_remoteNodeTX_PDO3Array_node49Type      72
      #define ODA_remoteNodeTX_PDO3Array_node4AType      73
      #define ODA_remoteNodeTX_PDO3Array_node4BType      74
      #define ODA_remoteNodeTX_PDO3Array_node4CType      75
      #define ODA_remoteNodeTX_PDO3Array_node4DType      76
      #define ODA_remoteNodeTX_PDO3Array_node4EType      77
      #define ODA_remoteNodeTX_PDO3Array_node4FType      78
      #define ODA_remoteNodeTX_PDO3Array_node50Type      79
      #define ODA_remoteNodeTX_PDO3Array_node51Type      80
      #define ODA_remoteNodeTX_PDO3Array_node52Type      81
      #define ODA_remoteNodeTX_PDO3Array_node53Type      82
      #define ODA_remoteNodeTX_PDO3Array_node54Type      83
      #define ODA_remoteNodeTX_PDO3Array_node55Type      84
      #define ODA_remoteNodeTX_PDO3Array_node56Type      85
      #define ODA_remoteNodeTX_PDO3Array_node57Type      86
      #define ODA_remoteNodeTX_PDO3Array_node58Type      87
      #define ODA_remoteNodeTX_PDO3Array_node59Type      88
      #define ODA_remoteNodeTX_PDO3Array_node5AType      89
      #define ODA_remoteNodeTX_PDO3Array_node5BType      90
      #define ODA_remoteNodeTX_PDO3Array_node5CType      91
      #define ODA_remoteNodeTX_PDO3Array_node5DType      92
      #define ODA_remoteNodeTX_PDO3Array_node5EType      93
      #define ODA_remoteNodeTX_PDO3Array_node5FType      94
      #define ODA_remoteNodeTX_PDO3Array_node60Type      95
      #define ODA_remoteNodeTX_PDO3Array_node61Type      96
      #define ODA_remoteNodeTX_PDO3Array_node62Type      97
      #define ODA_remoteNodeTX_PDO3Array_node63Type      98
      #define ODA_remoteNodeTX_PDO3Array_node64Type      99
      #define ODA_remoteNodeTX_PDO3Array_node65Type      100
      #define ODA_remoteNodeTX_PDO3Array_node66Type      101
      #define ODA_remoteNodeTX_PDO3Array_node67Type      102
      #define ODA_remoteNodeTX_PDO3Array_node68Type      103
      #define ODA_remoteNodeTX_PDO3Array_node69Type      104
      #define ODA_remoteNodeTX_PDO3Array_node6AType      105
      #define ODA_remoteNodeTX_PDO3Array_node6BType      106
      #define ODA_remoteNodeTX_PDO3Array_node6CType      107
      #define ODA_remoteNodeTX_PDO3Array_node6DType      108
      #define ODA_remoteNodeTX_PDO3Array_node6EType      109
      #define ODA_remoteNodeTX_PDO3Array_node6FType      110
      #define ODA_remoteNodeTX_PDO3Array_node70Type      111
      #define ODA_remoteNodeTX_PDO3Array_node71Type      112
      #define ODA_remoteNodeTX_PDO3Array_node72Type      113
      #define ODA_remoteNodeTX_PDO3Array_node73Type      114
      #define ODA_remoteNodeTX_PDO3Array_node74Type      115
      #define ODA_remoteNodeTX_PDO3Array_node75Type      116
      #define ODA_remoteNodeTX_PDO3Array_node76Type      117
      #define ODA_remoteNodeTX_PDO3Array_node77Type      118
      #define ODA_remoteNodeTX_PDO3Array_node78Type      119
      #define ODA_remoteNodeTX_PDO3Array_node79Type      120
      #define ODA_remoteNodeTX_PDO3Array_node7AType      121
      #define ODA_remoteNodeTX_PDO3Array_node7BType      122
      #define ODA_remoteNodeTX_PDO3Array_node7CType      123
      #define ODA_remoteNodeTX_PDO3Array_node7DType      124
      #define ODA_remoteNodeTX_PDO3Array_node7EType      125
      #define ODA_remoteNodeTX_PDO3Array_node7FType      126

/*210A, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeRX_PDO3Array                  CO_OD_ROM.remoteNodeRX_PDO3Array
      #define ODL_remoteNodeRX_PDO3Array_arrayLength     127
      #define ODA_remoteNodeRX_PDO3Array_node01Type      0
      #define ODA_remoteNodeRX_PDO3Array_node02Type      1
      #define ODA_remoteNodeRX_PDO3Array_node03Type      2
      #define ODA_remoteNodeRX_PDO3Array_node04Type      3
      #define ODA_remoteNodeRX_PDO3Array_node05Type      4
      #define ODA_remoteNodeRX_PDO3Array_node06Type      5
      #define ODA_remoteNodeRX_PDO3Array_node07Type      6
      #define ODA_remoteNodeRX_PDO3Array_node08Type      7
      #define ODA_remoteNodeRX_PDO3Array_node09Type      8
      #define ODA_remoteNodeRX_PDO3Array_node0AType      9
      #define ODA_remoteNodeRX_PDO3Array_node0BType      10
      #define ODA_remoteNodeRX_PDO3Array_node0CType      11
      #define ODA_remoteNodeRX_PDO3Array_node0DType      12
      #define ODA_remoteNodeRX_PDO3Array_node0EType      13
      #define ODA_remoteNodeRX_PDO3Array_node0FType      14
      #define ODA_remoteNodeRX_PDO3Array_node10Type      15
      #define ODA_remoteNodeRX_PDO3Array_node11Type      16
      #define ODA_remoteNodeRX_PDO3Array_node12Type      17
      #define ODA_remoteNodeRX_PDO3Array_node13Type      18
      #define ODA_remoteNodeRX_PDO3Array_node14Type      19
      #define ODA_remoteNodeRX_PDO3Array_node15Type      20
      #define ODA_remoteNodeRX_PDO3Array_node16Type      21
      #define ODA_remoteNodeRX_PDO3Array_node17Type      22
      #define ODA_remoteNodeRX_PDO3Array_node18Type      23
      #define ODA_remoteNodeRX_PDO3Array_node19Type      24
      #define ODA_remoteNodeRX_PDO3Array_node1AType      25
      #define ODA_remoteNodeRX_PDO3Array_node1BType      26
      #define ODA_remoteNodeRX_PDO3Array_node1CType      27
      #define ODA_remoteNodeRX_PDO3Array_node1DType      28
      #define ODA_remoteNodeRX_PDO3Array_node1EType      29
      #define ODA_remoteNodeRX_PDO3Array_node1FType      30
      #define ODA_remoteNodeRX_PDO3Array_node20Type      31
      #define ODA_remoteNodeRX_PDO3Array_node21Type      32
      #define ODA_remoteNodeRX_PDO3Array_node22Type      33
      #define ODA_remoteNodeRX_PDO3Array_node23Type      34
      #define ODA_remoteNodeRX_PDO3Array_node24Type      35
      #define ODA_remoteNodeRX_PDO3Array_node25Type      36
      #define ODA_remoteNodeRX_PDO3Array_node26Type      37
      #define ODA_remoteNodeRX_PDO3Array_node27Type      38
      #define ODA_remoteNodeRX_PDO3Array_node28Type      39
      #define ODA_remoteNodeRX_PDO3Array_node29Type      40
      #define ODA_remoteNodeRX_PDO3Array_node2AType      41
      #define ODA_remoteNodeRX_PDO3Array_node2BType      42
      #define ODA_remoteNodeRX_PDO3Array_node2CType      43
      #define ODA_remoteNodeRX_PDO3Array_node2DType      44
      #define ODA_remoteNodeRX_PDO3Array_node2EType      45
      #define ODA_remoteNodeRX_PDO3Array_node2FType      46
      #define ODA_remoteNodeRX_PDO3Array_node30Type      47
      #define ODA_remoteNodeRX_PDO3Array_node31Type      48
      #define ODA_remoteNodeRX_PDO3Array_node32Type      49
      #define ODA_remoteNodeRX_PDO3Array_node33Type      50
      #define ODA_remoteNodeRX_PDO3Array_node34Type      51
      #define ODA_remoteNodeRX_PDO3Array_node35Type      52
      #define ODA_remoteNodeRX_PDO3Array_node36Type      53
      #define ODA_remoteNodeRX_PDO3Array_node37Type      54
      #define ODA_remoteNodeRX_PDO3Array_node38Type      55
      #define ODA_remoteNodeRX_PDO3Array_node39Type      56
      #define ODA_remoteNodeRX_PDO3Array_node3AType      57
      #define ODA_remoteNodeRX_PDO3Array_node3BType      58
      #define ODA_remoteNodeRX_PDO3Array_node3CType      59
      #define ODA_remoteNodeRX_PDO3Array_node3DType      60
      #define ODA_remoteNodeRX_PDO3Array_node3EType      61
      #define ODA_remoteNodeRX_PDO3Array_node3FType      62
      #define ODA_remoteNodeRX_PDO3Array_node40Type      63
      #define ODA_remoteNodeRX_PDO3Array_node41Type      64
      #define ODA_remoteNodeRX_PDO3Array_node42Type      65
      #define ODA_remoteNodeRX_PDO3Array_node43Type      66
      #define ODA_remoteNodeRX_PDO3Array_node44Type      67
      #define ODA_remoteNodeRX_PDO3Array_node45Type      68
      #define ODA_remoteNodeRX_PDO3Array_node46Type      69
      #define ODA_remoteNodeRX_PDO3Array_node47Type      70
      #define ODA_remoteNodeRX_PDO3Array_node48Type      71
      #define ODA_remoteNodeRX_PDO3Array_node49Type      72
      #define ODA_remoteNodeRX_PDO3Array_node4AType      73
      #define ODA_remoteNodeRX_PDO3Array_node4BType      74
      #define ODA_remoteNodeRX_PDO3Array_node4CType      75
      #define ODA_remoteNodeRX_PDO3Array_node4DType      76
      #define ODA_remoteNodeRX_PDO3Array_node4EType      77
      #define ODA_remoteNodeRX_PDO3Array_node4FType      78
      #define ODA_remoteNodeRX_PDO3Array_node50Type      79
      #define ODA_remoteNodeRX_PDO3Array_node51Type      80
      #define ODA_remoteNodeRX_PDO3Array_node52Type      81
      #define ODA_remoteNodeRX_PDO3Array_node53Type      82
      #define ODA_remoteNodeRX_PDO3Array_node54Type      83
      #define ODA_remoteNodeRX_PDO3Array_node55Type      84
      #define ODA_remoteNodeRX_PDO3Array_node56Type      85
      #define ODA_remoteNodeRX_PDO3Array_node57Type      86
      #define ODA_remoteNodeRX_PDO3Array_node58Type      87
      #define ODA_remoteNodeRX_PDO3Array_node59Type      88
      #define ODA_remoteNodeRX_PDO3Array_node5AType      89
      #define ODA_remoteNodeRX_PDO3Array_node5BType      90
      #define ODA_remoteNodeRX_PDO3Array_node5CType      91
      #define ODA_remoteNodeRX_PDO3Array_node5DType      92
      #define ODA_remoteNodeRX_PDO3Array_node5EType      93
      #define ODA_remoteNodeRX_PDO3Array_node5FType      94
      #define ODA_remoteNodeRX_PDO3Array_node60Type      95
      #define ODA_remoteNodeRX_PDO3Array_node61Type      96
      #define ODA_remoteNodeRX_PDO3Array_node62Type      97
      #define ODA_remoteNodeRX_PDO3Array_node63Type      98
      #define ODA_remoteNodeRX_PDO3Array_node64Type      99
      #define ODA_remoteNodeRX_PDO3Array_node65Type      100
      #define ODA_remoteNodeRX_PDO3Array_node66Type      101
      #define ODA_remoteNodeRX_PDO3Array_node67Type      102
      #define ODA_remoteNodeRX_PDO3Array_node68Type      103
      #define ODA_remoteNodeRX_PDO3Array_node69Type      104
      #define ODA_remoteNodeRX_PDO3Array_node6AType      105
      #define ODA_remoteNodeRX_PDO3Array_node6BType      106
      #define ODA_remoteNodeRX_PDO3Array_node6CType      107
      #define ODA_remoteNodeRX_PDO3Array_node6DType      108
      #define ODA_remoteNodeRX_PDO3Array_node6EType      109
      #define ODA_remoteNodeRX_PDO3Array_node6FType      110
      #define ODA_remoteNodeRX_PDO3Array_node70Type      111
      #define ODA_remoteNodeRX_PDO3Array_node71Type      112
      #define ODA_remoteNodeRX_PDO3Array_node72Type      113
      #define ODA_remoteNodeRX_PDO3Array_node73Type      114
      #define ODA_remoteNodeRX_PDO3Array_node74Type      115
      #define ODA_remoteNodeRX_PDO3Array_node75Type      116
      #define ODA_remoteNodeRX_PDO3Array_node76Type      117
      #define ODA_remoteNodeRX_PDO3Array_node77Type      118
      #define ODA_remoteNodeRX_PDO3Array_node78Type      119
      #define ODA_remoteNodeRX_PDO3Array_node79Type      120
      #define ODA_remoteNodeRX_PDO3Array_node7AType      121
      #define ODA_remoteNodeRX_PDO3Array_node7BType      122
      #define ODA_remoteNodeRX_PDO3Array_node7CType      123
      #define ODA_remoteNodeRX_PDO3Array_node7DType      124
      #define ODA_remoteNodeRX_PDO3Array_node7EType      125
      #define ODA_remoteNodeRX_PDO3Array_node7FType      126

/*210B, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeRX_PDO5Array                  CO_OD_ROM.remoteNodeRX_PDO5Array
      #define ODL_remoteNodeRX_PDO5Array_arrayLength     127
      #define ODA_remoteNodeRX_PDO5Array_node01Type      0
      #define ODA_remoteNodeRX_PDO5Array_node02Type      1
      #define ODA_remoteNodeRX_PDO5Array_node03Type      2
      #define ODA_remoteNodeRX_PDO5Array_node04Type      3
      #define ODA_remoteNodeRX_PDO5Array_node05Type      4
      #define ODA_remoteNodeRX_PDO5Array_node06Type      5
      #define ODA_remoteNodeRX_PDO5Array_node07Type      6
      #define ODA_remoteNodeRX_PDO5Array_node08Type      7
      #define ODA_remoteNodeRX_PDO5Array_node09Type      8
      #define ODA_remoteNodeRX_PDO5Array_node0AType      9
      #define ODA_remoteNodeRX_PDO5Array_node0BType      10
      #define ODA_remoteNodeRX_PDO5Array_node0CType      11
      #define ODA_remoteNodeRX_PDO5Array_node0DType      12
      #define ODA_remoteNodeRX_PDO5Array_node0EType      13
      #define ODA_remoteNodeRX_PDO5Array_node0FType      14
      #define ODA_remoteNodeRX_PDO5Array_node10Type      15
      #define ODA_remoteNodeRX_PDO5Array_node11Type      16
      #define ODA_remoteNodeRX_PDO5Array_node12Type      17
      #define ODA_remoteNodeRX_PDO5Array_node13Type      18
      #define ODA_remoteNodeRX_PDO5Array_node14Type      19
      #define ODA_remoteNodeRX_PDO5Array_node15Type      20
      #define ODA_remoteNodeRX_PDO5Array_node16Type      21
      #define ODA_remoteNodeRX_PDO5Array_node17Type      22
      #define ODA_remoteNodeRX_PDO5Array_node18Type      23
      #define ODA_remoteNodeRX_PDO5Array_node19Type      24
      #define ODA_remoteNodeRX_PDO5Array_node1AType      25
      #define ODA_remoteNodeRX_PDO5Array_node1BType      26
      #define ODA_remoteNodeRX_PDO5Array_node1CType      27
      #define ODA_remoteNodeRX_PDO5Array_node1DType      28
      #define ODA_remoteNodeRX_PDO5Array_node1EType      29
      #define ODA_remoteNodeRX_PDO5Array_node1FType      30
      #define ODA_remoteNodeRX_PDO5Array_node20Type      31
      #define ODA_remoteNodeRX_PDO5Array_node21Type      32
      #define ODA_remoteNodeRX_PDO5Array_node22Type      33
      #define ODA_remoteNodeRX_PDO5Array_node23Type      34
      #define ODA_remoteNodeRX_PDO5Array_node24Type      35
      #define ODA_remoteNodeRX_PDO5Array_node25Type      36
      #define ODA_remoteNodeRX_PDO5Array_node26Type      37
      #define ODA_remoteNodeRX_PDO5Array_node27Type      38
      #define ODA_remoteNodeRX_PDO5Array_node28Type      39
      #define ODA_remoteNodeRX_PDO5Array_node29Type      40
      #define ODA_remoteNodeRX_PDO5Array_node2AType      41
      #define ODA_remoteNodeRX_PDO5Array_node2BType      42
      #define ODA_remoteNodeRX_PDO5Array_node2CType      43
      #define ODA_remoteNodeRX_PDO5Array_node2DType      44
      #define ODA_remoteNodeRX_PDO5Array_node2EType      45
      #define ODA_remoteNodeRX_PDO5Array_node2FType      46
      #define ODA_remoteNodeRX_PDO5Array_node30Type      47
      #define ODA_remoteNodeRX_PDO5Array_node31Type      48
      #define ODA_remoteNodeRX_PDO5Array_node32Type      49
      #define ODA_remoteNodeRX_PDO5Array_node33Type      50
      #define ODA_remoteNodeRX_PDO5Array_node34Type      51
      #define ODA_remoteNodeRX_PDO5Array_node35Type      52
      #define ODA_remoteNodeRX_PDO5Array_node36Type      53
      #define ODA_remoteNodeRX_PDO5Array_node37Type      54
      #define ODA_remoteNodeRX_PDO5Array_node38Type      55
      #define ODA_remoteNodeRX_PDO5Array_node39Type      56
      #define ODA_remoteNodeRX_PDO5Array_node3AType      57
      #define ODA_remoteNodeRX_PDO5Array_node3BType      58
      #define ODA_remoteNodeRX_PDO5Array_node3CType      59
      #define ODA_remoteNodeRX_PDO5Array_node3DType      60
      #define ODA_remoteNodeRX_PDO5Array_node3EType      61
      #define ODA_remoteNodeRX_PDO5Array_node3FType      62
      #define ODA_remoteNodeRX_PDO5Array_node40Type      63
      #define ODA_remoteNodeRX_PDO5Array_node41Type      64
      #define ODA_remoteNodeRX_PDO5Array_node42Type      65
      #define ODA_remoteNodeRX_PDO5Array_node43Type      66
      #define ODA_remoteNodeRX_PDO5Array_node44Type      67
      #define ODA_remoteNodeRX_PDO5Array_node45Type      68
      #define ODA_remoteNodeRX_PDO5Array_node46Type      69
      #define ODA_remoteNodeRX_PDO5Array_node47Type      70
      #define ODA_remoteNodeRX_PDO5Array_node48Type      71
      #define ODA_remoteNodeRX_PDO5Array_node49Type      72
      #define ODA_remoteNodeRX_PDO5Array_node4AType      73
      #define ODA_remoteNodeRX_PDO5Array_node4BType      74
      #define ODA_remoteNodeRX_PDO5Array_node4CType      75
      #define ODA_remoteNodeRX_PDO5Array_node4DType      76
      #define ODA_remoteNodeRX_PDO5Array_node4EType      77
      #define ODA_remoteNodeRX_PDO5Array_node4FType      78
      #define ODA_remoteNodeRX_PDO5Array_node50Type      79
      #define ODA_remoteNodeRX_PDO5Array_node51Type      80
      #define ODA_remoteNodeRX_PDO5Array_node52Type      81
      #define ODA_remoteNodeRX_PDO5Array_node53Type      82
      #define ODA_remoteNodeRX_PDO5Array_node54Type      83
      #define ODA_remoteNodeRX_PDO5Array_node55Type      84
      #define ODA_remoteNodeRX_PDO5Array_node56Type      85
      #define ODA_remoteNodeRX_PDO5Array_node57Type      86
      #define ODA_remoteNodeRX_PDO5Array_node58Type      87
      #define ODA_remoteNodeRX_PDO5Array_node59Type      88
      #define ODA_remoteNodeRX_PDO5Array_node5AType      89
      #define ODA_remoteNodeRX_PDO5Array_node5BType      90
      #define ODA_remoteNodeRX_PDO5Array_node5CType      91
      #define ODA_remoteNodeRX_PDO5Array_node5DType      92
      #define ODA_remoteNodeRX_PDO5Array_node5EType      93
      #define ODA_remoteNodeRX_PDO5Array_node5FType      94
      #define ODA_remoteNodeRX_PDO5Array_node60Type      95
      #define ODA_remoteNodeRX_PDO5Array_node61Type      96
      #define ODA_remoteNodeRX_PDO5Array_node62Type      97
      #define ODA_remoteNodeRX_PDO5Array_node63Type      98
      #define ODA_remoteNodeRX_PDO5Array_node64Type      99
      #define ODA_remoteNodeRX_PDO5Array_node65Type      100
      #define ODA_remoteNodeRX_PDO5Array_node66Type      101
      #define ODA_remoteNodeRX_PDO5Array_node67Type      102
      #define ODA_remoteNodeRX_PDO5Array_node68Type      103
      #define ODA_remoteNodeRX_PDO5Array_node69Type      104
      #define ODA_remoteNodeRX_PDO5Array_node6AType      105
      #define ODA_remoteNodeRX_PDO5Array_node6BType      106
      #define ODA_remoteNodeRX_PDO5Array_node6CType      107
      #define ODA_remoteNodeRX_PDO5Array_node6DType      108
      #define ODA_remoteNodeRX_PDO5Array_node6EType      109
      #define ODA_remoteNodeRX_PDO5Array_node6FType      110
      #define ODA_remoteNodeRX_PDO5Array_node70Type      111
      #define ODA_remoteNodeRX_PDO5Array_node71Type      112
      #define ODA_remoteNodeRX_PDO5Array_node72Type      113
      #define ODA_remoteNodeRX_PDO5Array_node73Type      114
      #define ODA_remoteNodeRX_PDO5Array_node74Type      115
      #define ODA_remoteNodeRX_PDO5Array_node75Type      116
      #define ODA_remoteNodeRX_PDO5Array_node76Type      117
      #define ODA_remoteNodeRX_PDO5Array_node77Type      118
      #define ODA_remoteNodeRX_PDO5Array_node78Type      119
      #define ODA_remoteNodeRX_PDO5Array_node79Type      120
      #define ODA_remoteNodeRX_PDO5Array_node7AType      121
      #define ODA_remoteNodeRX_PDO5Array_node7BType      122
      #define ODA_remoteNodeRX_PDO5Array_node7CType      123
      #define ODA_remoteNodeRX_PDO5Array_node7DType      124
      #define ODA_remoteNodeRX_PDO5Array_node7EType      125
      #define ODA_remoteNodeRX_PDO5Array_node7FType      126

/*210C, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeTX_PDO4Array                  CO_OD_ROM.remoteNodeTX_PDO4Array
      #define ODL_remoteNodeTX_PDO4Array_arrayLength     127
      #define ODA_remoteNodeTX_PDO4Array_node01Type      0
      #define ODA_remoteNodeTX_PDO4Array_node02Type      1
      #define ODA_remoteNodeTX_PDO4Array_node03Type      2
      #define ODA_remoteNodeTX_PDO4Array_node04Type      3
      #define ODA_remoteNodeTX_PDO4Array_node05Type      4
      #define ODA_remoteNodeTX_PDO4Array_node06Type      5
      #define ODA_remoteNodeTX_PDO4Array_node07Type      6
      #define ODA_remoteNodeTX_PDO4Array_node08Type      7
      #define ODA_remoteNodeTX_PDO4Array_node09Type      8
      #define ODA_remoteNodeTX_PDO4Array_node0AType      9
      #define ODA_remoteNodeTX_PDO4Array_node0BType      10
      #define ODA_remoteNodeTX_PDO4Array_node0CType      11
      #define ODA_remoteNodeTX_PDO4Array_node0DType      12
      #define ODA_remoteNodeTX_PDO4Array_node0EType      13
      #define ODA_remoteNodeTX_PDO4Array_node0FType      14
      #define ODA_remoteNodeTX_PDO4Array_node10Type      15
      #define ODA_remoteNodeTX_PDO4Array_node11Type      16
      #define ODA_remoteNodeTX_PDO4Array_node12Type      17
      #define ODA_remoteNodeTX_PDO4Array_node13Type      18
      #define ODA_remoteNodeTX_PDO4Array_node14Type      19
      #define ODA_remoteNodeTX_PDO4Array_node15Type      20
      #define ODA_remoteNodeTX_PDO4Array_node16Type      21
      #define ODA_remoteNodeTX_PDO4Array_node17Type      22
      #define ODA_remoteNodeTX_PDO4Array_node18Type      23
      #define ODA_remoteNodeTX_PDO4Array_node19Type      24
      #define ODA_remoteNodeTX_PDO4Array_node1AType      25
      #define ODA_remoteNodeTX_PDO4Array_node1BType      26
      #define ODA_remoteNodeTX_PDO4Array_node1CType      27
      #define ODA_remoteNodeTX_PDO4Array_node1DType      28
      #define ODA_remoteNodeTX_PDO4Array_node1EType      29
      #define ODA_remoteNodeTX_PDO4Array_node1FType      30
      #define ODA_remoteNodeTX_PDO4Array_node20Type      31
      #define ODA_remoteNodeTX_PDO4Array_node21Type      32
      #define ODA_remoteNodeTX_PDO4Array_node22Type      33
      #define ODA_remoteNodeTX_PDO4Array_node23Type      34
      #define ODA_remoteNodeTX_PDO4Array_node24Type      35
      #define ODA_remoteNodeTX_PDO4Array_node25Type      36
      #define ODA_remoteNodeTX_PDO4Array_node26Type      37
      #define ODA_remoteNodeTX_PDO4Array_node27Type      38
      #define ODA_remoteNodeTX_PDO4Array_node28Type      39
      #define ODA_remoteNodeTX_PDO4Array_node29Type      40
      #define ODA_remoteNodeTX_PDO4Array_node2AType      41
      #define ODA_remoteNodeTX_PDO4Array_node2BType      42
      #define ODA_remoteNodeTX_PDO4Array_node2CType      43
      #define ODA_remoteNodeTX_PDO4Array_node2DType      44
      #define ODA_remoteNodeTX_PDO4Array_node2EType      45
      #define ODA_remoteNodeTX_PDO4Array_node2FType      46
      #define ODA_remoteNodeTX_PDO4Array_node30Type      47
      #define ODA_remoteNodeTX_PDO4Array_node31Type      48
      #define ODA_remoteNodeTX_PDO4Array_node32Type      49
      #define ODA_remoteNodeTX_PDO4Array_node33Type      50
      #define ODA_remoteNodeTX_PDO4Array_node34Type      51
      #define ODA_remoteNodeTX_PDO4Array_node35Type      52
      #define ODA_remoteNodeTX_PDO4Array_node36Type      53
      #define ODA_remoteNodeTX_PDO4Array_node37Type      54
      #define ODA_remoteNodeTX_PDO4Array_node38Type      55
      #define ODA_remoteNodeTX_PDO4Array_node39Type      56
      #define ODA_remoteNodeTX_PDO4Array_node3AType      57
      #define ODA_remoteNodeTX_PDO4Array_node3BType      58
      #define ODA_remoteNodeTX_PDO4Array_node3CType      59
      #define ODA_remoteNodeTX_PDO4Array_node3DType      60
      #define ODA_remoteNodeTX_PDO4Array_node3EType      61
      #define ODA_remoteNodeTX_PDO4Array_node3FType      62
      #define ODA_remoteNodeTX_PDO4Array_node40Type      63
      #define ODA_remoteNodeTX_PDO4Array_node41Type      64
      #define ODA_remoteNodeTX_PDO4Array_node42Type      65
      #define ODA_remoteNodeTX_PDO4Array_node43Type      66
      #define ODA_remoteNodeTX_PDO4Array_node44Type      67
      #define ODA_remoteNodeTX_PDO4Array_node45Type      68
      #define ODA_remoteNodeTX_PDO4Array_node46Type      69
      #define ODA_remoteNodeTX_PDO4Array_node47Type      70
      #define ODA_remoteNodeTX_PDO4Array_node48Type      71
      #define ODA_remoteNodeTX_PDO4Array_node49Type      72
      #define ODA_remoteNodeTX_PDO4Array_node4AType      73
      #define ODA_remoteNodeTX_PDO4Array_node4BType      74
      #define ODA_remoteNodeTX_PDO4Array_node4CType      75
      #define ODA_remoteNodeTX_PDO4Array_node4DType      76
      #define ODA_remoteNodeTX_PDO4Array_node4EType      77
      #define ODA_remoteNodeTX_PDO4Array_node4FType      78
      #define ODA_remoteNodeTX_PDO4Array_node50Type      79
      #define ODA_remoteNodeTX_PDO4Array_node51Type      80
      #define ODA_remoteNodeTX_PDO4Array_node52Type      81
      #define ODA_remoteNodeTX_PDO4Array_node53Type      82
      #define ODA_remoteNodeTX_PDO4Array_node54Type      83
      #define ODA_remoteNodeTX_PDO4Array_node55Type      84
      #define ODA_remoteNodeTX_PDO4Array_node56Type      85
      #define ODA_remoteNodeTX_PDO4Array_node57Type      86
      #define ODA_remoteNodeTX_PDO4Array_node58Type      87
      #define ODA_remoteNodeTX_PDO4Array_node59Type      88
      #define ODA_remoteNodeTX_PDO4Array_node5AType      89
      #define ODA_remoteNodeTX_PDO4Array_node5BType      90
      #define ODA_remoteNodeTX_PDO4Array_node5CType      91
      #define ODA_remoteNodeTX_PDO4Array_node5DType      92
      #define ODA_remoteNodeTX_PDO4Array_node5EType      93
      #define ODA_remoteNodeTX_PDO4Array_node5FType      94
      #define ODA_remoteNodeTX_PDO4Array_node60Type      95
      #define ODA_remoteNodeTX_PDO4Array_node61Type      96
      #define ODA_remoteNodeTX_PDO4Array_node62Type      97
      #define ODA_remoteNodeTX_PDO4Array_node63Type      98
      #define ODA_remoteNodeTX_PDO4Array_node64Type      99
      #define ODA_remoteNodeTX_PDO4Array_node65Type      100
      #define ODA_remoteNodeTX_PDO4Array_node66Type      101
      #define ODA_remoteNodeTX_PDO4Array_node67Type      102
      #define ODA_remoteNodeTX_PDO4Array_node68Type      103
      #define ODA_remoteNodeTX_PDO4Array_node69Type      104
      #define ODA_remoteNodeTX_PDO4Array_node6AType      105
      #define ODA_remoteNodeTX_PDO4Array_node6BType      106
      #define ODA_remoteNodeTX_PDO4Array_node6CType      107
      #define ODA_remoteNodeTX_PDO4Array_node6DType      108
      #define ODA_remoteNodeTX_PDO4Array_node6EType      109
      #define ODA_remoteNodeTX_PDO4Array_node6FType      110
      #define ODA_remoteNodeTX_PDO4Array_node70Type      111
      #define ODA_remoteNodeTX_PDO4Array_node71Type      112
      #define ODA_remoteNodeTX_PDO4Array_node72Type      113
      #define ODA_remoteNodeTX_PDO4Array_node73Type      114
      #define ODA_remoteNodeTX_PDO4Array_node74Type      115
      #define ODA_remoteNodeTX_PDO4Array_node75Type      116
      #define ODA_remoteNodeTX_PDO4Array_node76Type      117
      #define ODA_remoteNodeTX_PDO4Array_node77Type      118
      #define ODA_remoteNodeTX_PDO4Array_node78Type      119
      #define ODA_remoteNodeTX_PDO4Array_node79Type      120
      #define ODA_remoteNodeTX_PDO4Array_node7AType      121
      #define ODA_remoteNodeTX_PDO4Array_node7BType      122
      #define ODA_remoteNodeTX_PDO4Array_node7CType      123
      #define ODA_remoteNodeTX_PDO4Array_node7DType      124
      #define ODA_remoteNodeTX_PDO4Array_node7EType      125
      #define ODA_remoteNodeTX_PDO4Array_node7FType      126

/*210D, Data Type: UNSIGNED8, Array[127] */
      #define OD_remoteNodeRX_PDO4Array                  CO_OD_ROM.remoteNodeRX_PDO4Array
      #define ODL_remoteNodeRX_PDO4Array_arrayLength     127
      #define ODA_remoteNodeRX_PDO4Array_node01Type      0
      #define ODA_remoteNodeRX_PDO4Array_node02Type      1
      #define ODA_remoteNodeRX_PDO4Array_node03Type      2
      #define ODA_remoteNodeRX_PDO4Array_node04Type      3
      #define ODA_remoteNodeRX_PDO4Array_node05Type      4
      #define ODA_remoteNodeRX_PDO4Array_node06Type      5
      #define ODA_remoteNodeRX_PDO4Array_node07Type      6
      #define ODA_remoteNodeRX_PDO4Array_node08Type      7
      #define ODA_remoteNodeRX_PDO4Array_node09Type      8
      #define ODA_remoteNodeRX_PDO4Array_node0AType      9
      #define ODA_remoteNodeRX_PDO4Array_node0BType      10
      #define ODA_remoteNodeRX_PDO4Array_node0CType      11
      #define ODA_remoteNodeRX_PDO4Array_node0DType      12
      #define ODA_remoteNodeRX_PDO4Array_node0EType      13
      #define ODA_remoteNodeRX_PDO4Array_node0FType      14
      #define ODA_remoteNodeRX_PDO4Array_node10Type      15
      #define ODA_remoteNodeRX_PDO4Array_node11Type      16
      #define ODA_remoteNodeRX_PDO4Array_node12Type      17
      #define ODA_remoteNodeRX_PDO4Array_node13Type      18
      #define ODA_remoteNodeRX_PDO4Array_node14Type      19
      #define ODA_remoteNodeRX_PDO4Array_node15Type      20
      #define ODA_remoteNodeRX_PDO4Array_node16Type      21
      #define ODA_remoteNodeRX_PDO4Array_node17Type      22
      #define ODA_remoteNodeRX_PDO4Array_node18Type      23
      #define ODA_remoteNodeRX_PDO4Array_node19Type      24
      #define ODA_remoteNodeRX_PDO4Array_node1AType      25
      #define ODA_remoteNodeRX_PDO4Array_node1BType      26
      #define ODA_remoteNodeRX_PDO4Array_node1CType      27
      #define ODA_remoteNodeRX_PDO4Array_node1DType      28
      #define ODA_remoteNodeRX_PDO4Array_node1EType      29
      #define ODA_remoteNodeRX_PDO4Array_node1FType      30
      #define ODA_remoteNodeRX_PDO4Array_node20Type      31
      #define ODA_remoteNodeRX_PDO4Array_node21Type      32
      #define ODA_remoteNodeRX_PDO4Array_node22Type      33
      #define ODA_remoteNodeRX_PDO4Array_node23Type      34
      #define ODA_remoteNodeRX_PDO4Array_node24Type      35
      #define ODA_remoteNodeRX_PDO4Array_node25Type      36
      #define ODA_remoteNodeRX_PDO4Array_node26Type      37
      #define ODA_remoteNodeRX_PDO4Array_node27Type      38
      #define ODA_remoteNodeRX_PDO4Array_node28Type      39
      #define ODA_remoteNodeRX_PDO4Array_node29Type      40
      #define ODA_remoteNodeRX_PDO4Array_node2AType      41
      #define ODA_remoteNodeRX_PDO4Array_node2BType      42
      #define ODA_remoteNodeRX_PDO4Array_node2CType      43
      #define ODA_remoteNodeRX_PDO4Array_node2DType      44
      #define ODA_remoteNodeRX_PDO4Array_node2EType      45
      #define ODA_remoteNodeRX_PDO4Array_node2FType      46
      #define ODA_remoteNodeRX_PDO4Array_node30Type      47
      #define ODA_remoteNodeRX_PDO4Array_node31Type      48
      #define ODA_remoteNodeRX_PDO4Array_node32Type      49
      #define ODA_remoteNodeRX_PDO4Array_node33Type      50
      #define ODA_remoteNodeRX_PDO4Array_node34Type      51
      #define ODA_remoteNodeRX_PDO4Array_node35Type      52
      #define ODA_remoteNodeRX_PDO4Array_node36Type      53
      #define ODA_remoteNodeRX_PDO4Array_node37Type      54
      #define ODA_remoteNodeRX_PDO4Array_node38Type      55
      #define ODA_remoteNodeRX_PDO4Array_node39Type      56
      #define ODA_remoteNodeRX_PDO4Array_node3AType      57
      #define ODA_remoteNodeRX_PDO4Array_node3BType      58
      #define ODA_remoteNodeRX_PDO4Array_node3CType      59
      #define ODA_remoteNodeRX_PDO4Array_node3DType      60
      #define ODA_remoteNodeRX_PDO4Array_node3EType      61
      #define ODA_remoteNodeRX_PDO4Array_node3FType      62
      #define ODA_remoteNodeRX_PDO4Array_node40Type      63
      #define ODA_remoteNodeRX_PDO4Array_node41Type      64
      #define ODA_remoteNodeRX_PDO4Array_node42Type      65
      #define ODA_remoteNodeRX_PDO4Array_node43Type      66
      #define ODA_remoteNodeRX_PDO4Array_node44Type      67
      #define ODA_remoteNodeRX_PDO4Array_node45Type      68
      #define ODA_remoteNodeRX_PDO4Array_node46Type      69
      #define ODA_remoteNodeRX_PDO4Array_node47Type      70
      #define ODA_remoteNodeRX_PDO4Array_node48Type      71
      #define ODA_remoteNodeRX_PDO4Array_node49Type      72
      #define ODA_remoteNodeRX_PDO4Array_node4AType      73
      #define ODA_remoteNodeRX_PDO4Array_node4BType      74
      #define ODA_remoteNodeRX_PDO4Array_node4CType      75
      #define ODA_remoteNodeRX_PDO4Array_node4DType      76
      #define ODA_remoteNodeRX_PDO4Array_node4EType      77
      #define ODA_remoteNodeRX_PDO4Array_node4FType      78
      #define ODA_remoteNodeRX_PDO4Array_node50Type      79
      #define ODA_remoteNodeRX_PDO4Array_node51Type      80
      #define ODA_remoteNodeRX_PDO4Array_node52Type      81
      #define ODA_remoteNodeRX_PDO4Array_node53Type      82
      #define ODA_remoteNodeRX_PDO4Array_node54Type      83
      #define ODA_remoteNodeRX_PDO4Array_node55Type      84
      #define ODA_remoteNodeRX_PDO4Array_node56Type      85
      #define ODA_remoteNodeRX_PDO4Array_node57Type      86
      #define ODA_remoteNodeRX_PDO4Array_node58Type      87
      #define ODA_remoteNodeRX_PDO4Array_node59Type      88
      #define ODA_remoteNodeRX_PDO4Array_node5AType      89
      #define ODA_remoteNodeRX_PDO4Array_node5BType      90
      #define ODA_remoteNodeRX_PDO4Array_node5CType      91
      #define ODA_remoteNodeRX_PDO4Array_node5DType      92
      #define ODA_remoteNodeRX_PDO4Array_node5EType      93
      #define ODA_remoteNodeRX_PDO4Array_node5FType      94
      #define ODA_remoteNodeRX_PDO4Array_node60Type      95
      #define ODA_remoteNodeRX_PDO4Array_node61Type      96
      #define ODA_remoteNodeRX_PDO4Array_node62Type      97
      #define ODA_remoteNodeRX_PDO4Array_node63Type      98
      #define ODA_remoteNodeRX_PDO4Array_node64Type      99
      #define ODA_remoteNodeRX_PDO4Array_node65Type      100
      #define ODA_remoteNodeRX_PDO4Array_node66Type      101
      #define ODA_remoteNodeRX_PDO4Array_node67Type      102
      #define ODA_remoteNodeRX_PDO4Array_node68Type      103
      #define ODA_remoteNodeRX_PDO4Array_node69Type      104
      #define ODA_remoteNodeRX_PDO4Array_node6AType      105
      #define ODA_remoteNodeRX_PDO4Array_node6BType      106
      #define ODA_remoteNodeRX_PDO4Array_node6CType      107
      #define ODA_remoteNodeRX_PDO4Array_node6DType      108
      #define ODA_remoteNodeRX_PDO4Array_node6EType      109
      #define ODA_remoteNodeRX_PDO4Array_node6FType      110
      #define ODA_remoteNodeRX_PDO4Array_node70Type      111
      #define ODA_remoteNodeRX_PDO4Array_node71Type      112
      #define ODA_remoteNodeRX_PDO4Array_node72Type      113
      #define ODA_remoteNodeRX_PDO4Array_node73Type      114
      #define ODA_remoteNodeRX_PDO4Array_node74Type      115
      #define ODA_remoteNodeRX_PDO4Array_node75Type      116
      #define ODA_remoteNodeRX_PDO4Array_node76Type      117
      #define ODA_remoteNodeRX_PDO4Array_node77Type      118
      #define ODA_remoteNodeRX_PDO4Array_node78Type      119
      #define ODA_remoteNodeRX_PDO4Array_node79Type      120
      #define ODA_remoteNodeRX_PDO4Array_node7AType      121
      #define ODA_remoteNodeRX_PDO4Array_node7BType      122
      #define ODA_remoteNodeRX_PDO4Array_node7CType      123
      #define ODA_remoteNodeRX_PDO4Array_node7DType      124
      #define ODA_remoteNodeRX_PDO4Array_node7EType      125
      #define ODA_remoteNodeRX_PDO4Array_node7FType      126

/*2200, Data Type: OCTET_STRING, Array[10] */
      #define OD_errorStatusBits                         CO_OD_ROM.errorStatusBits
      #define ODL_errorStatusBits_stringLength           10

/*6000, Data Type: UNSIGNED8, Array[8] */
      #define OD_readInput8Bit                           CO_OD_RAM.readInput8Bit
      #define ODL_readInput8Bit_arrayLength              8

/*6200, Data Type: UNSIGNED8, Array[8] */
      #define OD_writeOutput8Bit                         CO_OD_RAM.writeOutput8Bit
      #define ODL_writeOutput8Bit_arrayLength            8

/*6401, Data Type: INTEGER16, Array[12] */
      #define OD_readAnalogueInput16Bit                  CO_OD_RAM.readAnalogueInput16Bit
      #define ODL_readAnalogueInput16Bit_arrayLength     12

/*6411, Data Type: INTEGER16, Array[8] */
      #define OD_writeAnalogueOutput16Bit                CO_OD_RAM.writeAnalogueOutput16Bit
      #define ODL_writeAnalogueOutput16Bit_arrayLength   8


#endif

