/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>

#include <cpuinfo.h>
#include <rmax-microkernel-tester.h>
#include <qnnpack/u8rmax.h>


#if CPUINFO_ARCH_ARM || CPUINFO_ARCH_ARM64
TEST(U8RMAX__NEON, n_lt_16) {
  for (size_t n = 1; n < 16; n++) {
    RMaxMicrokernelTester()
      .n(n)
      .test(u8rmax_ukernel__neon);
  }
}

TEST(U8RMAX__NEON, n_eq_16) {
  RMaxMicrokernelTester()
    .n(16)
    .test(u8rmax_ukernel__neon);
}

TEST(U8RMAX__NEON, n_div_16) {
  for (size_t n = 16; n < 128; n += 16) {
    RMaxMicrokernelTester()
      .n(n)
      .test(u8rmax_ukernel__neon);
  }
}

TEST(U8RMAX__NEON, n_gt_16) {
  for (size_t n = 16; n < 32; n++) {
    RMaxMicrokernelTester()
      .n(n)
      .test(u8rmax_ukernel__neon);
  }
}
#endif /* CPUINFO_ARCH_ARM || CPUINFO_ARCH_ARM64 */

#if CPUINFO_ARCH_X86 || CPUINFO_ARCH_X86_64
TEST(U8RMAX__SSE2, n_lt_16) {
  for (size_t n = 1; n < 16; n++) {
    RMaxMicrokernelTester()
      .n(n)
      .test(u8rmax_ukernel__sse2);
  }
}

TEST(U8RMAX__SSE2, n_eq_16) {
  RMaxMicrokernelTester()
    .n(16)
    .test(u8rmax_ukernel__sse2);
}

TEST(U8RMAX__SSE2, n_div_16) {
  for (size_t n = 16; n < 128; n += 16) {
    RMaxMicrokernelTester()
      .n(n)
      .test(u8rmax_ukernel__sse2);
  }
}

TEST(U8RMAX__SSE2, n_gt_16) {
  for (size_t n = 17; n < 32; n++) {
    RMaxMicrokernelTester()
      .n(n)
      .test(u8rmax_ukernel__sse2);
  }
}
#endif /* CPUINFO_ARCH_X86 || CPUINFO_ARCH_X86_64 */
