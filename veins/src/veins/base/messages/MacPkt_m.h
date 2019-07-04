//
// Generated file, do not edit! Created by nedtool 5.4 from veins/base/messages/MacPkt.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __VEINS_MACPKT_M_H
#define __VEINS_MACPKT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#endif

// cplusplus {{
#include "veins/base/utils/SimpleAddress.h"
// }}


namespace Veins {

/**
 * Class generated from <tt>veins/base/messages/MacPkt.msg:38</tt> by nedtool.
 * <pre>
 * // A basic MAC (Media Access Control) packet format definition
 * // 
 * // subclass if you want to create your own MAC layer packet class
 * //
 * // The basic MAC packet only provides source and destination address
 * //
 * // \@author Daniel Willkomm
 * packet MacPkt
 * {
 *     LAddress::L2Type destAddr; // destination mac address
 *     LAddress::L2Type srcAddr;  // source mac address
 *     long sequenceId; // Sequence Number to detect duplicate messages
 * }
 * </pre>
 */
class MacPkt : public ::omnetpp::cPacket
{
  protected:
    LAddress::L2Type destAddr;
    LAddress::L2Type srcAddr;
    long sequenceId;

  private:
    void copy(const MacPkt& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MacPkt&);

  public:
    MacPkt(const char *name=nullptr, short kind=0);
    MacPkt(const MacPkt& other);
    virtual ~MacPkt();
    MacPkt& operator=(const MacPkt& other);
    virtual MacPkt *dup() const override {return new MacPkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual LAddress::L2Type& getDestAddr();
    virtual const LAddress::L2Type& getDestAddr() const {return const_cast<MacPkt*>(this)->getDestAddr();}
    virtual void setDestAddr(const LAddress::L2Type& destAddr);
    virtual LAddress::L2Type& getSrcAddr();
    virtual const LAddress::L2Type& getSrcAddr() const {return const_cast<MacPkt*>(this)->getSrcAddr();}
    virtual void setSrcAddr(const LAddress::L2Type& srcAddr);
    virtual long getSequenceId() const;
    virtual void setSequenceId(long sequenceId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MacPkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MacPkt& obj) {obj.parsimUnpack(b);}

} // namespace Veins

#endif // ifndef __VEINS_MACPKT_M_H

