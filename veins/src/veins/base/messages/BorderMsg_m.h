//
// Generated file, do not edit! Created by nedtool 5.4 from veins/base/messages/BorderMsg.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __VEINS_BORDERMSG_M_H
#define __VEINS_BORDERMSG_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#endif

// cplusplus {{
#include "veins/base/utils/Coord.h"
// }}


namespace Veins {

/**
 * Class generated from <tt>veins/base/messages/BorderMsg.msg:33</tt> by nedtool.
 * <pre>
 * // used as a self packet containing the position, direction and BorderPolicy
 * //
 * // \@author Daniel Willkomm
 * //
 * packet BorderMsg
 * {
 *     int policy;    // border policy to use for the host
 *     Coord startPos; // new start position of the host
 *     Coord direction; // new direction of the host
 * }
 * </pre>
 */
class BorderMsg : public ::omnetpp::cPacket
{
  protected:
    int policy;
    Coord startPos;
    Coord direction;

  private:
    void copy(const BorderMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BorderMsg&);

  public:
    BorderMsg(const char *name=nullptr, short kind=0);
    BorderMsg(const BorderMsg& other);
    virtual ~BorderMsg();
    BorderMsg& operator=(const BorderMsg& other);
    virtual BorderMsg *dup() const override {return new BorderMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getPolicy() const;
    virtual void setPolicy(int policy);
    virtual Coord& getStartPos();
    virtual const Coord& getStartPos() const {return const_cast<BorderMsg*>(this)->getStartPos();}
    virtual void setStartPos(const Coord& startPos);
    virtual Coord& getDirection();
    virtual const Coord& getDirection() const {return const_cast<BorderMsg*>(this)->getDirection();}
    virtual void setDirection(const Coord& direction);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BorderMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BorderMsg& obj) {obj.parsimUnpack(b);}

} // namespace Veins

#endif // ifndef __VEINS_BORDERMSG_M_H

