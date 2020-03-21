// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple thumbv8.1m.main-arm-none-eabi \
// RUN:   -target-feature +cdecp0 -target-feature +cdecp1 \
// RUN:   -target-feature +mve.fp \
// RUN:   -mfloat-abi hard -O0 -disable-O0-optnone \
// RUN:   -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s

#include <arm_cde.h>

// CHECK-LABEL: @test_vcx1q_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.cde.vcx1q(i32 0, i32 1111)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
uint8x16_t test_vcx1q_u8(void) {
  return __arm_vcx1q_u8(0, 1111);
}

// CHECK-LABEL: @test_vcx1qa_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.cde.vcx1qa(i32 1, <16 x i8> [[ACC:%.*]], i32 1112)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
uint8x16_t test_vcx1qa_1(uint8x16_t acc) {
  return __arm_vcx1qa(1, acc, 1112);
}

// CHECK-LABEL: @test_vcx1qa_2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x i32> [[ACC:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i8> @llvm.arm.cde.vcx1qa(i32 0, <16 x i8> [[TMP0]], i32 1113)
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vcx1qa_2(int32x4_t acc) {
  return __arm_vcx1qa(0, acc, 1113);
}

// CHECK-LABEL: @test_vcx2q_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x half> [[N:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i8> @llvm.arm.cde.vcx2q(i32 1, <16 x i8> [[TMP0]], i32 111)
// CHECK-NEXT:    ret <16 x i8> [[TMP1]]
//
uint8x16_t test_vcx2q_u8(float16x8_t n) {
  return __arm_vcx2q_u8(1, n, 111);
}

// CHECK-LABEL: @test_vcx2q(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[N:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i8> @llvm.arm.cde.vcx2q(i32 1, <16 x i8> [[TMP0]], i32 112)
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x float>
// CHECK-NEXT:    ret <4 x float> [[TMP2]]
//
float32x4_t test_vcx2q(float32x4_t n) {
  return __arm_vcx2q(1, n, 112);
}

// CHECK-LABEL: @test_vcx2qa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[ACC:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <2 x i64> [[N:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.cde.vcx2qa(i32 0, <16 x i8> [[TMP0]], <16 x i8> [[TMP1]], i32 113)
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <16 x i8> [[TMP2]] to <4 x float>
// CHECK-NEXT:    ret <4 x float> [[TMP3]]
//
float32x4_t test_vcx2qa(float32x4_t acc, int64x2_t n) {
  return __arm_vcx2qa(0, acc, n, 113);
}

// CHECK-LABEL: @test_vcx3q_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x i16> [[N:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <4 x i32> [[M:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.cde.vcx3q(i32 0, <16 x i8> [[TMP0]], <16 x i8> [[TMP1]], i32 11)
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
uint8x16_t test_vcx3q_u8(uint16x8_t n, int32x4_t m) {
  return __arm_vcx3q_u8(0, n, m, 11);
}

// CHECK-LABEL: @test_vcx3q(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x i64> [[N:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <4 x float> [[M:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.cde.vcx3q(i32 1, <16 x i8> [[TMP0]], <16 x i8> [[TMP1]], i32 12)
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <16 x i8> [[TMP2]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[TMP3]]
//
uint64x2_t test_vcx3q(uint64x2_t n, float32x4_t m) {
  return __arm_vcx3q(1, n, m, 12);
}

// CHECK-LABEL: @test_vcx3qa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x i16> [[N:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <4 x float> [[M:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.cde.vcx3qa(i32 1, <16 x i8> [[ACC:%.*]], <16 x i8> [[TMP0]], <16 x i8> [[TMP1]], i32 13)
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vcx3qa(int8x16_t acc, uint16x8_t n, float32x4_t m) {
  return __arm_vcx3qa(1, acc, n, m, 13);
}