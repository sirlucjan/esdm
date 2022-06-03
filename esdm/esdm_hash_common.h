/*
 * ESDM SHA definition.
 *
 * Copyright (C) 2022, Stephan Mueller <smueller@chronox.de>
 *
 * License: see LICENSE file in root directory
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ALL OF
 * WHICH ARE HEREBY DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef _ESDM_HASH_COMMON_H
#define _ESDM_HASH_COMMON_H

#include "lc_hash.h"
#include "lc_sha512.h"
#include "lc_sha3.h"

#define SHA512_DIGEST_SIZE LC_SHA512_SIZE_DIGEST

#if defined(ESDM_HASH_SHA512)
#define LC_HASH_STATE_SIZE_CONST	200
#elif defined(ESDM_HASH_SHA3_512)
#define LC_HASH_STATE_SIZE_CONST	376
#else
#error "Unknown hash size"
#endif

/*
 * Replace the leancrypto LC_HASH_CTX_SIZE definition as it is not a
 * compile-time constant. NOTE: The caller should implement a check
 * verifying that this result equals to LC_HASH_CTX_SIZE(lc_sha512) to ensure
 * code consistency.
 */
#define LC_HASH_CTX_SIZE_ESDM(x)	(sizeof(struct lc_hash_ctx) + x)
#define HASH_MAX_DESCSIZE	LC_HASH_CTX_SIZE_ESDM(LC_HASH_STATE_SIZE_CONST)

#endif /* _ESDM_HASH_COMMON_H */
