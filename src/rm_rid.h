//
// rm_rid.h
//
//   The Record Id interface
//

#ifndef RM_RID_H
#define RM_RID_H

// We separate the interface of RID from the rest of RM because some
// components will require the use of RID but not the rest of RM.

#include "redbase.h"

//
// PageNum: uniquely identifies a page in a file
//
typedef int PageNum;

//
// SlotNum: uniquely identifies a record in a page
//
typedef int SlotNum;

//
// RID: Record id interface
//
class RID {
public:
    RID();                                         // Default constructor
    RID(PageNum pageNum, SlotNum slotNum);
    // Copy constructor
    RID(const RID &rid);

    ~RID();                                        // Destructor
    RID& operator=(const RID &rid);                // Overloaded =
    bool operator==(const RID &rid) const ;        // Overloaded ==

    RC GetPageNum(PageNum &pageNum) const;         // Return page number
    RC GetSlotNum(SlotNum &slotNum) const;         // Return slot number

    PageNum Page() const          // Return page number
    { return pageNum; }
    SlotNum Slot() const          // Return slot number
    { return slotNum; }

private:
    PageNum pageNum;
    SlotNum slotNum;
};

#endif
