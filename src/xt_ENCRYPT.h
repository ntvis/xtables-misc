/**
 * xt_ENCRYPT - encrypt/decrypt the UDP payload.
 * Copyright (C) 2013 Changli Gao <xiaosuo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _XT_ENCRYPT_H
#define _XT_ENCRYPT_H

#include <linux/types.h>

/* It is the same as CRYPTO_MAX_ALG_NAME */
#define XT_ENCRYPT_MAX_ALG_NAME	64

#define XT_ENCRYPT_MAX_PASSPHRASE 32

struct xt_encrypt_priv;

struct xt_encrypt_info {
	char				alg_name[XT_ENCRYPT_MAX_ALG_NAME];
	char				passphrase[XT_ENCRYPT_MAX_PASSPHRASE];
	/* The following two are used for encryption. */
	__u16				perturb_time;	/* In second */
	__u16				perturb_number;
	__u8				decrypt;
	__u8				__hole[3];

	/* Kernel data used in the module */
	struct xt_encrypt_priv		*priv __attribute__((aligned(8)));
};

#endif /* _XT_ENCRYPT_H */
