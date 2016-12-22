#include "MFE_helpers.h"

#include "CO_helpers.h"

extern "C" {
#include "CO_driver.h"
#include "CO_CAN.h"
}

uint8_t MFE_scan(uint8_t remoteNodeId, MFEnode_t *node, uint16_t timeoutTime) {
    uint8_t err = 0;

    uint8_t _err = 0;
    uint8_t _dataRx[4];
    uint8_t _dataTx[4];
    uint32_t _abortCode = 0;
    uint32_t _readSize = 0;

    // Read device type
    _err = CO_SDO_read(remoteNodeId, MFE_index_DeviceType, 0x00, _dataRx, sizeof(_dataRx), &_abortCode, &_readSize, timeoutTime);
    if (!_err && _abortCode == 0) {
        if (_readSize == 4) {
            node->deviceType = (_dataRx[0] << 24 || _dataRx[2] << 16 || _dataRx[1] << 8 || _dataRx[3]);
        } else {
            return MFE_ERROR_NODE_TYPE;
        }
    } else if (_abortCode == 0x405) {
        return MFE_ERROR_NODE_TIMEOUT;
    } else {
        return MFE_ERROR_NODE_UNAVAILABLE;
    }

    // Read vendor ID
    _err = CO_SDO_read(remoteNodeId, MFE_index_Identity, 0x01, _dataRx, sizeof(_dataRx), &_abortCode, &_readSize, timeoutTime);
    if (!_err && _abortCode == 0) {
        if (_readSize == 4) {
            node->vendorID = (_dataRx[0] << 24 || _dataRx[2] << 16 || _dataRx[1] << 8 || _dataRx[3]);
        } else {
            return MFE_ERROR_NODE_TYPE;
        }
    } else if (_abortCode == 0x405) {
        return MFE_ERROR_NODE_TIMEOUT;
    } else {
        return MFE_ERROR_NODE_UNAVAILABLE;
    }

    _dataTx[0] = 0x00; _dataTx[1] = 0x04; // 0x0400
    _err = CO_SDO_write(remoteNodeId, MFE_index_ProducerHeartbeatTime, 0x0, _dataTx, 2, &_abortCode, timeoutTime);

    _dataTx[0] = 0x25;
    _err = CO_SDO_write(remoteNodeId, MFE_index_RemoteNodeType, 0x0, _dataTx, 1, &_abortCode, timeoutTime);

    _dataTx[0] = 0x25;
    _err = CO_SDO_write(remoteNodeId, MFE_index_RemoteNodeServerSDO, 0x0, _dataTx, 1, &_abortCode, timeoutTime);

    _dataTx[0] = 0x01;
    _err = CO_SDO_write(remoteNodeId, MFE_index_RemoteNodeClientSDO, 0x0, _dataTx, 1, &_abortCode, timeoutTime);

    _dataTx[0] = 0x01;
    _err = CO_SDO_write(remoteNodeId, MFE_index_RemoteNodeTXPDO_1, 0x1, _dataTx, 1, &_abortCode, timeoutTime);

    _dataTx[0] = 0x01;
    _err = CO_SDO_write(remoteNodeId, MFE_index_RemoteNodeRXPDO_1, 0x1, _dataTx, 1, &_abortCode, timeoutTime);

    node->nodeId = remoteNodeId;

    return err;
}

uint8_t MFE_connect(MFEnode_t *node, uint16_t timeoutTime) {
    uint8_t err = 0;

    uint8_t _err = 0;
    uint8_t _nodeId = node->nodeId;
    uint8_t _dataRx[4];
    uint8_t _dataTx[4];
    uint32_t _abortCode = 0;
    uint32_t _readSize = 0;

    _dataTx[0] = 0x01; _dataTx[1] = 0x05; _dataTx[2] = 0x00; _dataTx[3] = 0x00; // COB-ID: 501
    _err = CO_SDO_write(_nodeId, MFE_index_SDO_ClientParameter_2, 0x01, _dataTx, 4, &_abortCode, timeoutTime);

    _dataTx[0] = 0x81; _dataTx[1] = 0x04; _dataTx[2] = 0x00; _dataTx[3] = 0x00; // COB-ID: 481
    _err = CO_SDO_write(_nodeId, MFE_index_SDO_ClientParameter_2, 0x01, _dataTx, 4, &_abortCode, timeoutTime);

    _dataTx[0] = 0x01; // Node-ID of the SDO server
    _err = CO_SDO_write(_nodeId, MFE_index_SDO_ClientParameter_2, 0x01, _dataTx, 1, &_abortCode, timeoutTime);

    _dataTx[0] = 0x25; // NodeType of the master
    _err = CO_SDO_write(_nodeId, MFE_index_RemoteNodeType, 0x01, _dataTx, 1, &_abortCode, timeoutTime);

    _dataTx[0] = 0x01; // Node-ID of the SDO server
    _err = CO_SDO_write(_nodeId, MFE_index_RemoteNodeClientSDO, 0x01, _dataTx, 1, &_abortCode, timeoutTime);

    CO_sendNMTcommand(CO, CO_NMT_ENTER_OPERATIONAL, _nodeId);

    return _err;
}
