#ifndef RECORD_STATUS_H
#define RECORD_STATUS_H

namespace dummy {

    enum RecordStatus
            {
                RecordStatus_Open = 0,
                RecordStatus_InProgress,
                RecordStatus_Closed,
                RecordStatus_Unknown
            };
};

#endif