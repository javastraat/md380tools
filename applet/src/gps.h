/*
 *  gps.h
 * 
 */

#ifndef GPS_H
#define GPS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// ringbuffer 
typedef struct {
    uint8_t buf[100];
    uint16_t rd_idx ; // [100] 0x64
    uint16_t inbuf ; // [102] 0x66 (0...100-1)
    uint16_t wr_idx ; // [104] 0x68 (0...100-1)
} gps_ring_t ;

#if 0 
// defined(FW_S13_020)
// S13 @ 0x2001d950    
extern gps_ring_t gps_ringbuf ;
#endif

typedef struct {
    uint16_t unk0 ;
    uint8_t status ; // [3] 0x3  (0...?)
    uint8_t unk4[10];
    uint16_t off14 ; // [14] 0xe coord lat?
    uint16_t off16 ; // [16] 0x10 coord lon?
        
} gps_t ;

#ifdef __cplusplus
}
#endif

#endif /* GPS_H */

