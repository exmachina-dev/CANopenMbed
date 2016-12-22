#include "CO_helpers.h"

uint32_t swapBytes(uint32_t from) {
    uint32_t to;
    uint8_t b0, b1, b2, b3;

    b0 = (from & 0xff);
    b1 = (from & 0xff00) >> 8u;
    b2 = (from & 0xff0000) >> 16u;
    b3 = (from & 0xff000000) >> 24u;

    to = (b3) | (b2 << 8u) | (b1 << 16u) | (b0 << 24u);

    return to;
}
int CO_SDO_write(
        uint8_t     remoteNodeId,
        uint16_t    index,      uint8_t     subIndex,
        uint8_t    *dataTx,     uint32_t    dataSize,
        uint32_t   *SDOabortCode,
        uint16_t    SDOtimeoutTime) {
    uint8_t err = 0;

    if (CO_SDOclient_setup(CO->SDOclient, 0, 0, remoteNodeId) != CO_SDOcli_ok_communicationEnd) err = 1;

    if (err == 0) {
        if (CO_SDOclientDownloadInitiate(CO->SDOclient, index, subIndex, dataTx, dataSize, 0)) err = 2;
    }

    if (err == 0) {
        CO_SDOclient_return_t ret;
        uint16_t timer1msPrev;

        timer1msPrev = CO_timer1ms;

        do {
            uint16_t timer1ms, timer1msDiff;

            timer1ms = CO_timer1ms;
            timer1msDiff = timer1ms - timer1msPrev;
            timer1msPrev = timer1ms;

            ret = CO_SDOclientDownload(CO->SDOclient, timer1msDiff, SDOtimeoutTime, SDOabortCode);
            Thread::wait(5);
        } while (ret > 0);

        CO_SDOclientClose(CO->SDOclient);
    }

    return err;
}

int CO_SDO_read(
        uint8_t     remoteNodeId,
        uint16_t    index,          uint8_t     subIndex,
        uint8_t    *dataRx,         uint32_t    dataSize,
        uint32_t   *SDOabortCode,   uint32_t   *dataReadSize,
        uint16_t    SDOtimeoutTime) {
    uint8_t err = 0;

    uint32_t dataRxSize = sizeof(dataRx);

    if (CO_SDOclient_setup(CO->SDOclient, 0, 0, remoteNodeId) != CO_SDOcli_ok_communicationEnd) err = 1;

    if (!err) {
        if (CO_SDOclientUploadInitiate(CO->SDOclient, index, subIndex, dataRx, dataRxSize, 0)) err = 2;
    }

    if (!err) {
        CO_SDOclient_return_t ret;
        uint16_t timer1msPrev;

        timer1msPrev = CO_timer1ms;

        do {
            uint16_t timer1ms, timer1msDiff;

            timer1ms = CO_timer1ms;
            timer1msDiff = timer1ms - timer1msPrev;
            timer1msPrev = timer1ms;

            ret = CO_SDOclientUpload(CO->SDOclient, timer1msDiff, SDOtimeoutTime, dataReadSize, SDOabortCode);
            Thread::wait(5);
        } while (ret > CO_SDOcli_ok_communicationEnd);

        CO_SDOclientClose(CO->SDOclient);
    }

    return err;
}
