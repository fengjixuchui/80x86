#ifndef __REGISTERFILE_H__
#define __REGISTERFILE_H__

#include <stdint.h>

enum GPR {
    AX,
    CX,
    DX,
    BX,
    SP,
    BP,
    SI,
    DI,
    IP,
    ES,
    CS,
    SS,
    DS,
    NUM_16BIT_REGS,
    AL = NUM_16BIT_REGS,
    CL,
    DL,
    BL,
    AH,
    CH,
    DH,
    BH,
    NUM_REGS
};

enum FlagBitPos {
    CF_OFFS = 0,
    PF_OFFS = 2,
    AF_OFFS = 4,
    ZF_OFFS = 6,
    SF_OFFS = 7,
    TF_OFFS = 8,
    IF_OFFS = 9,
    DF_OFFS = 10,
    OF_OFFS = 11
};

enum Flag {
    CF = (1 << CF_OFFS),
    PF = (1 << PF_OFFS),
    AF = (1 << AF_OFFS),
    ZF = (1 << ZF_OFFS),
    SF = (1 << SF_OFFS),
    TF = (1 << TF_OFFS),
    IF = (1 << IF_OFFS),
    DF = (1 << DF_OFFS),
    OF = (1 << OF_OFFS),
};

// Bit 15 is always 1 on 8086
enum { FLAGS_STUCK_BITS = (1 << 15) };

class RegisterFile {
public:
    RegisterFile();
    virtual void reset();
    virtual void set(GPR regnum, uint16_t value);
    virtual uint16_t get(GPR regnum) const;
    virtual uint16_t get_flags() const;
    virtual void set_flags(uint16_t val);
private:
    uint16_t registers[NUM_16BIT_REGS];
    uint16_t flags;
};

#endif /* __REGISTERFILE_H__ */
