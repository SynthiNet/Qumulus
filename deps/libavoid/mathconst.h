/*
 * Author: Frank Erens
 */

#ifndef AVOID_MATHCONST_H
#define AVOID_MATHCONST_H

// <Frank Erens> For some reason, MinGW does not define M_PI while 
//               GCC does. I guess MinGW simply uses the MSFT C library
//               which somehow does not have M_PI. So we use this workaround.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#endif
