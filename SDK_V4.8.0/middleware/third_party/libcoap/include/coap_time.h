/* coap_time.h -- Clock Handling
 *
 * Copyright (C) 2010--2013 Olaf Bergmann <bergmann@tzi.org>
 *
 * This file is part of the CoAP library libcoap. Please see
 * README for terms of use.
 */

/**
 * @file coap_time.h
 * @brief Clock Handling
 */

#ifndef _COAP_TIME_H_
#define _COAP_TIME_H_

/*
** Make sure we can call this stuff from C++.
*/
#ifdef __cplusplus
extern "C" {
#endif


#include "coap/config.h"
#include <time.h>
#include "FreeRTOS.h"
#include "task.h"
/**
 * @defgroup clock Clock Handling
 * Default implementation of internal clock. You should redefine this if
 * you do not have time() and gettimeofday().
 * @{
 */

#ifdef WITH_LWIP

#include <stdint.h>
#include <lwip/sys.h>

/* lwIP provides ms in sys_now */
#define COAP_TICKS_PER_SECOND 1000

typedef uint32_t coap_tick_t;

/**
 * This data type is used to represent the difference between two
 * clock_tick_t values. This data type must have the same size in
 * memory as coap_tick_t to allow wrapping.
 */
typedef int coap_tick_diff_t;

static inline void coap_ticks_impl(coap_tick_t *t)
{
	*t = sys_now();
}

static inline void coap_clock_init_impl(void)
{
}

#define coap_clock_init coap_clock_init_impl

#define coap_ticks coap_ticks_impl

#endif
#ifdef WITH_CONTIKI
#include "clock.h"

typedef clock_time_t coap_tick_t;

/**
 * This data type is used to represent the difference between two
 * clock_tick_t values. This data type must have the same size in
 * memory as coap_tick_t to allow wrapping.
 */
typedef int coap_tick_diff_t;

#define COAP_TICKS_PER_SECOND CLOCK_SECOND

/** Set at startup to initialize the internal clock (time in seconds). */
extern clock_time_t clock_offset;

static inline void
contiki_clock_init_impl(void) {
  clock_init();
  clock_offset = clock_time();
}

#define coap_clock_init contiki_clock_init_impl

static inline void
contiki_ticks_impl(coap_tick_t *t) {
  *t = clock_time();
}

#define coap_ticks contiki_ticks_impl

#endif /* WITH_CONTIKI */
#ifdef WITH_POSIX
typedef unsigned int coap_tick_t;

/**
 * This data type is used to represent the difference between two
 * clock_tick_t values. This data type must have the same size in
 * memory as coap_tick_t to allow wrapping.
 */
typedef int coap_tick_diff_t;

#define COAP_TICKS_PER_SECOND 1000

/** Set at startup to initialize the internal clock (time in seconds). */
extern time_t clock_offset;
#endif /* WITH_POSIX */

#ifndef coap_clock_init
static inline void
coap_clock_init_impl(void) {
#ifdef HAVE_TIME_H
  clock_offset = time(NULL);
#else
//#  ifdef __GNUC__
    /* Issue a warning when using gcc. Other prepropressors do
     *  not seem to have a similar feature. */
//#   warning "cannot initialize clock"
//#  endif
  clock_offset = xTaskGetTickCount();
#endif
}
#define coap_clock_init coap_clock_init_impl
#endif /* coap_clock_init */

#ifndef coap_ticks
static inline void
coap_ticks_impl(coap_tick_t *t) {
#ifdef HAVE_SYS_TIME_H
  struct timeval tv;
  gettimeofday(&tv, NULL);
  *t = (tv.tv_sec - clock_offset) * COAP_TICKS_PER_SECOND
    + (tv.tv_usec * COAP_TICKS_PER_SECOND / 1000000);
#else
    *t = xTaskGetTickCount();
#endif
}
#define coap_ticks coap_ticks_impl
#endif /* coap_ticks */

/**
 * Returns @c 1 if and only if @p a is less than @p b where less is
 * defined on a signed data type.
 */
static inline
int coap_time_lt(coap_tick_t a, coap_tick_t b) {
  return ((coap_tick_diff_t)(a - b)) < 0;
}

/**
 * Returns @c 1 if and only if @p a is less than or equal @p b where
 * less is defined on a signed data type.
 */
static inline
int coap_time_le(coap_tick_t a, coap_tick_t b) {
  return a == b || coap_time_lt(a,b);
}

/** @} */

#ifdef __cplusplus
}
#endif


#endif /* _COAP_TIME_H_ */
