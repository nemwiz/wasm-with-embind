#ifndef RAW_RECORD_HPP
#define RAW_RECORD_HPP

#include "common.h"
#include "record-status.hpp"

namespace dummy
{
    struct RawRecord;
    typedef std::vector<RawRecord> RawRecordArray;

    struct RawRecord
    {
        int32t order;
        String recordId;
        RecordStatus status;

        RawRecord()
        {
            order = 0;
            status = RecordStatus_Open;
        }

        RawRecord(int32t order, const String &recordId, RecordStatus status)
        {
            this->order = order;
            this->recordId = recordId;
            this->status = status;
        }

        friend std::ostream &operator<<(std::ostream &os, const RawRecord &record)
        {
            os << "RawRecord ("
               << "order: [" << record.order << "]"
               << " recordId: [" << record.recordId << "]"
               << " status: [" << record.status << "]"
               << ")";
            return os;
        }
    };
};

#endif