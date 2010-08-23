/* Copyright (c) 2010 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Utility functions that need to be built as part of the firmware.
 */

#include "utility.h"

void* Memset(void* d, const uint8_t c, uint64_t n) {
  uint8_t* dest = d; /* the only way to keep both cl and gcc happy */
  while (n--) {
    *dest++ = c;
  }
  return dest;
}

int SafeMemcmp(const void* s1, const void* s2, size_t n) {
  int result = 0;
  if (0 == n)
    return 1;

  const unsigned char* us1 = s1;
  const unsigned char* us2 = s2;
  /* Code snippet without data-dependent branch due to
   * Nate Lawson (nate@root.org) of Root Labs. */
  while (n--)
    result |= *us1++ ^ *us2++;

  return result != 0;
}