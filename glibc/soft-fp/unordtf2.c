/* Software floating-point emulation.
   Return 1 iff a or b is a NaN, 0 otherwise.
   Copyright (C) 2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Joseph Myers (joseph@codesourcery.com).

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

#include "soft-fp.h"
#include "quad.h"

int
__unordtf2(TFtype a, TFtype b)
{
  FP_DECL_Q(A);
  FP_DECL_Q(B);
  int r;

  FP_UNPACK_RAW_Q(A, a);
  FP_UNPACK_RAW_Q(B, b);
  FP_CMP_UNORD_Q(r, A, B);

  return r;
}
