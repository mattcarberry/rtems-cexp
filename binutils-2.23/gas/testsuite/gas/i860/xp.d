#as: -mxp
#objdump: -dr
#name: i860 xp (XP-only instructions)

.*: +file format .*

Disassembly of section \.text:

00000000 <\.text>:
   0:	00 00 df 30 	ld.c	%bear,%r31
   4:	00 00 c0 30 	ld.c	%bear,%r0
   8:	00 00 e5 30 	ld.c	%ccr,%r5
   c:	00 00 fe 30 	ld.c	%ccr,%r30
  10:	00 00 0a 31 	ld.c	%p0,%r10
  14:	00 00 02 31 	ld.c	%p0,%sp
  18:	00 00 35 31 	ld.c	%p1,%r21
  1c:	00 00 20 31 	ld.c	%p1,%r0
  20:	00 00 5c 31 	ld.c	%p2,%r28
  24:	00 00 4c 31 	ld.c	%p2,%r12
  28:	00 00 7f 31 	ld.c	%p3,%r31
  2c:	00 00 66 31 	ld.c	%p3,%r6
  30:	00 00 c0 38 	st.c	%r0,%bear
  34:	00 f0 c0 38 	st.c	%r30,%bear
  38:	00 38 e0 38 	st.c	%r7,%ccr
  3c:	00 f8 e0 38 	st.c	%r31,%ccr
  40:	00 58 00 39 	st.c	%r11,%p0
  44:	00 18 00 39 	st.c	%fp,%p0
  48:	00 b0 20 39 	st.c	%r22,%p1
  4c:	00 78 20 39 	st.c	%r15,%p1
  50:	00 e8 40 39 	st.c	%r29,%p2
  54:	00 68 40 39 	st.c	%r13,%p2
  58:	00 20 60 39 	st.c	%r4,%p3
  5c:	00 30 60 39 	st.c	%r6,%p3
  60:	0a 04 05 4c 	ldint.l	%r0,%r5
  64:	0a 04 df 4c 	ldint.l	%r6,%r31
  68:	0a 04 fe 4c 	ldint.l	%r7,%r30
  6c:	0a 04 1d 4d 	ldint.l	%r8,%r29
  70:	0a 04 3c 4d 	ldint.l	%r9,%r28
  74:	0a 04 1b 4c 	ldint.l	%r0,%r27
  78:	0a 04 3a 4c 	ldint.l	%r1,%r26
  7c:	0a 04 99 4d 	ldint.l	%r12,%r25
  80:	0a 04 b8 4d 	ldint.l	%r13,%r24
  84:	0a 04 d7 4d 	ldint.l	%r14,%r23
  88:	0a 04 f6 4d 	ldint.l	%r15,%r22
  8c:	0a 04 15 4e 	ldint.l	%r16,%r21
  90:	0a 04 34 4e 	ldint.l	%r17,%r20
  94:	0a 04 93 4f 	ldint.l	%r28,%r19
  98:	0a 04 f2 4f 	ldint.l	%r31,%r18
  9c:	0a 02 05 4c 	ldint.s	%r0,%r5
  a0:	0a 02 df 4c 	ldint.s	%r6,%r31
  a4:	0a 02 fe 4c 	ldint.s	%r7,%r30
  a8:	0a 02 1d 4d 	ldint.s	%r8,%r29
  ac:	0a 02 3c 4d 	ldint.s	%r9,%r28
  b0:	0a 02 1b 4c 	ldint.s	%r0,%r27
  b4:	0a 02 3a 4c 	ldint.s	%r1,%r26
  b8:	0a 02 99 4d 	ldint.s	%r12,%r25
  bc:	0a 02 b8 4d 	ldint.s	%r13,%r24
  c0:	0a 02 d7 4d 	ldint.s	%r14,%r23
  c4:	0a 02 f6 4d 	ldint.s	%r15,%r22
  c8:	0a 02 15 4e 	ldint.s	%r16,%r21
  cc:	0a 02 34 4e 	ldint.s	%r17,%r20
  d0:	0a 02 93 4f 	ldint.s	%r28,%r19
  d4:	0a 02 f2 4f 	ldint.s	%r31,%r18
  d8:	0a 00 05 4c 	ldint.b	%r0,%r5
  dc:	0a 00 df 4c 	ldint.b	%r6,%r31
  e0:	0a 00 fe 4c 	ldint.b	%r7,%r30
  e4:	0a 00 1d 4d 	ldint.b	%r8,%r29
  e8:	0a 00 3c 4d 	ldint.b	%r9,%r28
  ec:	0a 00 1b 4c 	ldint.b	%r0,%r27
  f0:	0a 00 3a 4c 	ldint.b	%r1,%r26
  f4:	0a 00 99 4d 	ldint.b	%r12,%r25
  f8:	0a 00 b8 4d 	ldint.b	%r13,%r24
  fc:	0a 00 d7 4d 	ldint.b	%r14,%r23
 100:	0a 00 f6 4d 	ldint.b	%r15,%r22
 104:	0a 00 15 4e 	ldint.b	%r16,%r21
 108:	0a 00 34 4e 	ldint.b	%r17,%r20
 10c:	0a 00 93 4f 	ldint.b	%r28,%r19
 110:	0a 00 f2 4f 	ldint.b	%r31,%r18
 114:	08 04 05 4c 	ldio.l	%r0,%r5
 118:	08 04 df 4c 	ldio.l	%r6,%r31
 11c:	08 04 fe 4c 	ldio.l	%r7,%r30
 120:	08 04 1d 4d 	ldio.l	%r8,%r29
 124:	08 04 3c 4d 	ldio.l	%r9,%r28
 128:	08 04 1b 4c 	ldio.l	%r0,%r27
 12c:	08 04 3a 4c 	ldio.l	%r1,%r26
 130:	08 04 99 4d 	ldio.l	%r12,%r25
 134:	08 04 b8 4d 	ldio.l	%r13,%r24
 138:	08 04 d7 4d 	ldio.l	%r14,%r23
 13c:	08 04 f6 4d 	ldio.l	%r15,%r22
 140:	08 04 15 4e 	ldio.l	%r16,%r21
 144:	08 04 34 4e 	ldio.l	%r17,%r20
 148:	08 04 93 4f 	ldio.l	%r28,%r19
 14c:	08 04 f2 4f 	ldio.l	%r31,%r18
 150:	08 02 05 4c 	ldio.s	%r0,%r5
 154:	08 02 df 4c 	ldio.s	%r6,%r31
 158:	08 02 fe 4c 	ldio.s	%r7,%r30
 15c:	08 02 1d 4d 	ldio.s	%r8,%r29
 160:	08 02 3c 4d 	ldio.s	%r9,%r28
 164:	08 02 1b 4c 	ldio.s	%r0,%r27
 168:	08 02 3a 4c 	ldio.s	%r1,%r26
 16c:	08 02 99 4d 	ldio.s	%r12,%r25
 170:	08 02 b8 4d 	ldio.s	%r13,%r24
 174:	08 02 d7 4d 	ldio.s	%r14,%r23
 178:	08 02 f6 4d 	ldio.s	%r15,%r22
 17c:	08 02 15 4e 	ldio.s	%r16,%r21
 180:	08 02 34 4e 	ldio.s	%r17,%r20
 184:	08 02 93 4f 	ldio.s	%r28,%r19
 188:	08 02 f2 4f 	ldio.s	%r31,%r18
 18c:	08 00 05 4c 	ldio.b	%r0,%r5
 190:	08 00 df 4c 	ldio.b	%r6,%r31
 194:	08 00 fe 4c 	ldio.b	%r7,%r30
 198:	08 00 1d 4d 	ldio.b	%r8,%r29
 19c:	08 00 3c 4d 	ldio.b	%r9,%r28
 1a0:	08 00 1b 4c 	ldio.b	%r0,%r27
 1a4:	08 00 3a 4c 	ldio.b	%r1,%r26
 1a8:	08 00 99 4d 	ldio.b	%r12,%r25
 1ac:	08 00 b8 4d 	ldio.b	%r13,%r24
 1b0:	08 00 d7 4d 	ldio.b	%r14,%r23
 1b4:	08 00 f6 4d 	ldio.b	%r15,%r22
 1b8:	08 00 15 4e 	ldio.b	%r16,%r21
 1bc:	08 00 34 4e 	ldio.b	%r17,%r20
 1c0:	08 00 93 4f 	ldio.b	%r28,%r19
 1c4:	08 00 f2 4f 	ldio.b	%r31,%r18
 1c8:	09 04 a0 4c 	stio.l	%r0,%r5
 1cc:	09 34 e0 4f 	stio.l	%r6,%r31
 1d0:	09 3c c0 4f 	stio.l	%r7,%r30
 1d4:	09 44 a0 4f 	stio.l	%r8,%r29
 1d8:	09 4c 80 4f 	stio.l	%r9,%r28
 1dc:	09 04 60 4f 	stio.l	%r0,%r27
 1e0:	09 0c 40 4f 	stio.l	%r1,%r26
 1e4:	09 64 20 4f 	stio.l	%r12,%r25
 1e8:	09 6c 00 4f 	stio.l	%r13,%r24
 1ec:	09 74 e0 4e 	stio.l	%r14,%r23
 1f0:	09 7c c0 4e 	stio.l	%r15,%r22
 1f4:	09 84 a0 4e 	stio.l	%r16,%r21
 1f8:	09 8c 80 4e 	stio.l	%r17,%r20
 1fc:	09 e4 60 4e 	stio.l	%r28,%r19
 200:	09 fc 40 4e 	stio.l	%r31,%r18
 204:	09 02 a0 4c 	stio.s	%r0,%r5
 208:	09 32 e0 4f 	stio.s	%r6,%r31
 20c:	09 3a c0 4f 	stio.s	%r7,%r30
 210:	09 42 a0 4f 	stio.s	%r8,%r29
 214:	09 4a 80 4f 	stio.s	%r9,%r28
 218:	09 02 60 4f 	stio.s	%r0,%r27
 21c:	09 0a 40 4f 	stio.s	%r1,%r26
 220:	09 62 20 4f 	stio.s	%r12,%r25
 224:	09 6a 00 4f 	stio.s	%r13,%r24
 228:	09 72 e0 4e 	stio.s	%r14,%r23
 22c:	09 7a c0 4e 	stio.s	%r15,%r22
 230:	09 82 a0 4e 	stio.s	%r16,%r21
 234:	09 8a 80 4e 	stio.s	%r17,%r20
 238:	09 e2 60 4e 	stio.s	%r28,%r19
 23c:	09 fa 40 4e 	stio.s	%r31,%r18
 240:	09 00 a0 4c 	stio.b	%r0,%r5
 244:	09 30 e0 4f 	stio.b	%r6,%r31
 248:	09 38 c0 4f 	stio.b	%r7,%r30
 24c:	09 40 a0 4f 	stio.b	%r8,%r29
 250:	09 48 80 4f 	stio.b	%r9,%r28
 254:	09 00 60 4f 	stio.b	%r0,%r27
 258:	09 08 40 4f 	stio.b	%r1,%r26
 25c:	09 60 20 4f 	stio.b	%r12,%r25
 260:	09 68 00 4f 	stio.b	%r13,%r24
 264:	09 70 e0 4e 	stio.b	%r14,%r23
 268:	09 78 c0 4e 	stio.b	%r15,%r22
 26c:	09 80 a0 4e 	stio.b	%r16,%r21
 270:	09 88 80 4e 	stio.b	%r17,%r20
 274:	09 e0 60 4e 	stio.b	%r28,%r19
 278:	09 f8 40 4e 	stio.b	%r31,%r18
 27c:	0b 00 00 4c 	scyc.b	%r0
 280:	0b 00 a0 4c 	scyc.b	%r5
 284:	0b 00 c0 4c 	scyc.b	%r6
 288:	0b 00 a0 4d 	scyc.b	%r13
 28c:	0b 00 c0 4d 	scyc.b	%r14
 290:	0b 00 80 4f 	scyc.b	%r28
 294:	0b 00 a0 4f 	scyc.b	%r29
 298:	0b 00 c0 4f 	scyc.b	%r30
 29c:	0b 00 e0 4f 	scyc.b	%r31
 2a0:	04 00 00 64 	pfld.q	0\(%r0\),%f0
 2a4:	84 00 3c 64 	pfld.q	128\(%r1\),%f28
 2a8:	04 01 58 64 	pfld.q	256\(%sp\),%f24
 2ac:	04 02 74 64 	pfld.q	512\(%fp\),%f20
 2b0:	04 04 90 64 	pfld.q	1024\(%r4\),%f16
 2b4:	04 10 ac 64 	pfld.q	4096\(%r5\),%f12
 2b8:	04 20 c8 64 	pfld.q	8192\(%r6\),%f8
 2bc:	04 40 e4 64 	pfld.q	16384\(%r7\),%f4
 2c0:	fc 7f e0 64 	pfld.q	32760\(%r7\),%f0
 2c4:	04 80 fc 64 	pfld.q	-32768\(%r7\),%f28
 2c8:	04 c0 18 65 	pfld.q	-16384\(%r8\),%f24
 2cc:	04 e0 34 65 	pfld.q	-8192\(%r9\),%f20
 2d0:	04 f0 50 65 	pfld.q	-4096\(%r10\),%f16
 2d4:	04 fc 6c 65 	pfld.q	-1024\(%r11\),%f12
 2d8:	04 fe 88 65 	pfld.q	-512\(%r12\),%f8
 2dc:	0c ff a4 65 	pfld.q	-248\(%r13\),%f4
 2e0:	fc ff c0 65 	pfld.q	-8\(%r14\),%f0
 2e4:	05 00 00 64 	pfld.q	0\(%r0\)\+\+,%f0
 2e8:	85 00 24 64 	pfld.q	128\(%r1\)\+\+,%f4
 2ec:	05 01 48 64 	pfld.q	256\(%sp\)\+\+,%f8
 2f0:	05 02 6c 64 	pfld.q	512\(%fp\)\+\+,%f12
 2f4:	05 04 90 64 	pfld.q	1024\(%r4\)\+\+,%f16
 2f8:	05 10 b4 64 	pfld.q	4096\(%r5\)\+\+,%f20
 2fc:	05 20 d8 64 	pfld.q	8192\(%r6\)\+\+,%f24
 300:	05 40 fc 64 	pfld.q	16384\(%r7\)\+\+,%f28
 304:	fd 7f e0 64 	pfld.q	32760\(%r7\)\+\+,%f0
 308:	05 80 e4 64 	pfld.q	-32768\(%r7\)\+\+,%f4
 30c:	05 c0 08 65 	pfld.q	-16384\(%r8\)\+\+,%f8
 310:	05 e0 2c 65 	pfld.q	-8192\(%r9\)\+\+,%f12
 314:	05 f0 50 65 	pfld.q	-4096\(%r10\)\+\+,%f16
 318:	05 fc 74 65 	pfld.q	-1024\(%r11\)\+\+,%f20
 31c:	05 fe 98 65 	pfld.q	-512\(%r12\)\+\+,%f24
 320:	0d ff bc 65 	pfld.q	-248\(%r13\)\+\+,%f28
 324:	fd ff d0 65 	pfld.q	-8\(%r14\)\+\+,%f16
 328:	04 28 1c 60 	pfld.q	%r5\(%r0\),%f28
 32c:	04 30 38 60 	pfld.q	%r6\(%r1\),%f24
 330:	04 38 54 60 	pfld.q	%r7\(%sp\),%f20
 334:	04 40 70 60 	pfld.q	%r8\(%fp\),%f16
 338:	04 48 8c 60 	pfld.q	%r9\(%r4\),%f12
 33c:	04 00 a8 60 	pfld.q	%r0\(%r5\),%f8
 340:	04 08 c4 60 	pfld.q	%r1\(%r6\),%f4
 344:	04 60 e0 60 	pfld.q	%r12\(%r7\),%f0
 348:	04 68 1c 61 	pfld.q	%r13\(%r8\),%f28
 34c:	04 70 38 61 	pfld.q	%r14\(%r9\),%f24
 350:	04 78 54 61 	pfld.q	%r15\(%r10\),%f20
 354:	04 80 70 61 	pfld.q	%r16\(%r11\),%f16
 358:	04 88 8c 61 	pfld.q	%r17\(%r12\),%f12
 35c:	04 e0 a8 61 	pfld.q	%r28\(%r13\),%f8
 360:	04 f8 c4 61 	pfld.q	%r31\(%r14\),%f4
 364:	05 28 00 60 	pfld.q	%r5\(%r0\)\+\+,%f0
 368:	05 30 24 60 	pfld.q	%r6\(%r1\)\+\+,%f4
 36c:	05 38 48 60 	pfld.q	%r7\(%sp\)\+\+,%f8
 370:	05 40 6c 60 	pfld.q	%r8\(%fp\)\+\+,%f12
 374:	05 48 90 60 	pfld.q	%r9\(%r4\)\+\+,%f16
 378:	05 00 b4 60 	pfld.q	%r0\(%r5\)\+\+,%f20
 37c:	05 08 d8 60 	pfld.q	%r1\(%r6\)\+\+,%f24
 380:	05 60 fc 60 	pfld.q	%r12\(%r7\)\+\+,%f28
 384:	05 68 00 61 	pfld.q	%r13\(%r8\)\+\+,%f0
 388:	05 70 24 61 	pfld.q	%r14\(%r9\)\+\+,%f4
 38c:	05 78 48 61 	pfld.q	%r15\(%r10\)\+\+,%f8
 390:	05 80 6c 61 	pfld.q	%r16\(%r11\)\+\+,%f12
 394:	05 88 90 61 	pfld.q	%r17\(%r12\)\+\+,%f16
 398:	05 e0 b4 61 	pfld.q	%r28\(%r13\)\+\+,%f20
 39c:	05 f8 d8 61 	pfld.q	%r31\(%r14\)\+\+,%f24