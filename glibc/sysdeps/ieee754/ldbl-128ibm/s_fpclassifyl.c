/* Return classification value corresponding to argument.
   Copyright (C) 1997,1999,2002,2004,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997 and
   		  Jakub Jelinek <jj@ultra.linux.cz>, 1999.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <math.h>

#include "math_private.h"
#include <math_ldbl_opt.h>

  /*
   *		hx                  lx
   * +NaN	7ffn nnnn nnnn nnnn xxxx xxxx xxxx xxxx
   * -NaN	fffn nnnn nnnn nnnn xxxx xxxx xxxx xxxx
   * +Inf	7ff0 0000 0000 0000 xxxx xxxx xxxx xxxx
   * -Inf	fff0 0000 0000 0000 xxxx xxxx xxxx xxxx
   * +0		0000 0000 0000 0000
   * -0		8000 0000 0000 0000
   * +normal	001n nnnn nnnn nnnn (smallest)
   * -normal	801n nnnn nnnn nnnn (smallest)
   * +normal	7fen nnnn nnnn nnnn (largest)
   * -normal	ffen nnnn nnnn nnnn (largest)
   * +denorm	000n nnnn nnnn nnnn
   * -denorm	800n nnnn nnnn nnnn
   */

int
___fpclassifyl (long double x)
{
  u_int64_t hx, lx;
  int retval = FP_NORMAL;

  GET_LDOUBLE_WORDS64 (hx, lx, x);
  if ((hx & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) {
      /* +/-NaN or +/-Inf */
      if (hx & 0x000fffffffffffffULL) {
	  /* +/-NaN */
	  retval = FP_NAN;
      } else {
	  retval = FP_INFINITE;
      }
  } else {
      /* +/-zero or +/- normal or +/- denormal */
      if (hx & 0x7fffffffffffffffULL) {
	  /* +/- normal or +/- denormal */
	  if ((hx & 0x7ff0000000000000ULL) >= 0x0360000000000000ULL) {
	      /* +/- normal */
	      retval = FP_NORMAL;
	  } else {
	      /* +/- denormal */
	      retval = FP_SUBNORMAL;
	  }
      } else {
	  /* +/- zero */
	  retval = FP_ZERO;
      }
  }

  return retval;
}
long_double_symbol (libm, ___fpclassifyl, __fpclassifyl);
#ifdef __LONG_DOUBLE_MATH_OPTIONAL
libm_hidden_ver (___fpclassifyl, __fpclassifyl)
#else
libm_hidden_def (__fpclassifyl)
#endif
