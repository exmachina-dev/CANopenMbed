#ifndef MFE_HELPERS_
#define MFE_HELPERS_

#include "CO_helpers.h"

enum MFE_errors {
    MFE_ERROR_NONE,
    MFE_ERROR_NODE_UNAVAILABLE,
    MFE_ERROR_NODE_TIMEOUT,
    MFE_ERROR_NODE_TYPE
};

enum MFE_index_enum {
    MFE_index_DeviceType                          = 0x1000,
    MFE_index_ErrorRegister                       = 0x1001,
    MFE_index_ManufacturerStatusRegister          = 0x1002,
    MFE_index_PredefinedErrorRegister             = 0x1003,
    MFE_index_COBIDSYNC                           = 0x1005,
    MFE_index_CommunicationCyclePeriod            = 0x1006,
    MFE_index_ManufacturerDeviceName              = 0x1008,
    MFE_index_ManufacturerHardwareVersion         = 0x1009,
    MFE_index_ManufacturerSoftwareVersion         = 0x100A,
    MFE_index_NodeID                              = 0x100B,
    MFE_index_GuardTime                           = 0x100C,
    MFE_index_LifeTimeFactor                      = 0x100D,
    MFE_index_NoSDO                               = 0x100F,
    MFE_index_COBIDEMCY                           = 0x1014,
    MFE_index_InhibitTimeEMCY                     = 0x1015,
    MFE_index_ConsumerHeartbeatTime               = 0x1016,
    MFE_index_ProducerHeartbeatTime               = 0x1017,
    MFE_index_Identity                            = 0x1018,
    // SDO
    MFE_index_SDOServerParameter_1                = 0x1200,
    MFE_index_SDOServerParameter_2                = 0x1201,
    MFE_index_SDOServerParameter_3                = 0x1202,
    MFE_index_SDOServerParameter_4                = 0x1204, // 128 max
    MFE_index_SDO_ClientParameter_1               = 0x1280,
    MFE_index_SDO_ClientParameter_2               = 0x1281,
    MFE_index_SDO_ClientParameter_3               = 0x1282,
    MFE_index_SDO_ClientParameter_4               = 0x1283, // 128 max
    // Rx PDO
    MFE_index_RxPDOParameter_1                    = 0x1400,
    MFE_index_RxPDOParameter_2                    = 0x1401,
    MFE_index_RxPDOParameter_3                    = 0x1402,
    MFE_index_RxPDOParameter_4                    = 0x1403, // 256 max
    MFE_index_RxCommsParameter_1                  = 0x1500,
    MFE_index_RxCommsParameter_2                  = 0x1501,
    MFE_index_RxCommsParameter_3                  = 0x1502,
    MFE_index_RxCommsParameter_4                  = 0x1503, // 10 max
    MFE_index_RxPDOMapping_1                      = 0x1600,
    MFE_index_RxPDOMapping_2                      = 0x1601,
    MFE_index_RxPDOMapping_3                      = 0x1602,
    MFE_index_RxPDOMapping_4                      = 0x1603, // 256 max
    // Tx PDO
    MFE_index_TxPDOParameter_1                    = 0x1800,
    MFE_index_TxPDOParameter_2                    = 0x1801,
    MFE_index_TxPDOParameter_3                    = 0x1802,
    MFE_index_TxPDOParameter_4                    = 0x1803, // 256 max
    MFE_index_TxCommsParameter_1                  = 0x1900,
    MFE_index_TxCommsParameter_2                  = 0x1901,
    MFE_index_TxCommsParameter_3                  = 0x1902,
    MFE_index_TxCommsParameter_4                  = 0x1903, // 10 max
    MFE_index_TxPDOMapping_1                      = 0x1a00,
    MFE_index_TxPDOMapping_2                      = 0x1a01,
    MFE_index_TxPDOMapping_3                      = 0x1a02,
    MFE_index_TxPDOMapping_4                      = 0x1a03, // 256 max
    // Manufacturer specific
    MFE_index_CommsArray                          = 0x2000,
    MFE_index_InitErrorRegister                   = 0x2001,
    MFE_index_InitWarningRegister                 = 0x2002,
    MFE_index_DriveErrorRegister                  = 0x2003,
    MFE_index_AxisErrorRegister                   = 0x2004,
    MFE_index_AxisWarningRegister                 = 0x2005,
    MFE_index_AxisStatusRegister                  = 0x2006,
    MFE_index_MiscErrorRegister                   = 0x2007,
    MFE_index_RemoteNodeType                      = 0x2100,
    MFE_index_RemoteNodeTXPDO_1                   = 0x2101,
    MFE_index_RemoteNodeRXPDO_1                   = 0x2102,
    MFE_index_RemoteNodeTXPDO_2                   = 0x2103,
    MFE_index_RemoteNodeRXPDO_2                   = 0x2104,
    MFE_index_RemoteNodeServerSDO                 = 0x2105,
    MFE_index_RemoteNodeClientSDO                 = 0x2106,
    MFE_index_RemoteDigitalOutputBytes            = 0x2107,
    MFE_index_RemoteDigitalInputBytes             = 0x2108,
    MFE_index_NetDataArray_1                      = 0x3F00,
    MFE_index_NetDataArray_2                      = 0x3F01,
    MFE_index_NetDataArray_3                      = 0x3F02,
    MFE_index_NetDataArray_4                      = 0x3F03
};

typedef struct {
    uint8_t  nodeId;
    uint32_t deviceType;
    uint32_t vendorID;
    uint32_t revNo;  
    uint32_t serialNo;  
} MFEnode_t;

uint8_t MFE_scan(uint8_t remoteNodeId, MFEnode_t *node, uint16_t timeoutTime);

uint8_t MFE_connect(MFEnode_t *remoteNodeId, uint16_t timeoutTime);

#endif // MFE_HELPERS_
