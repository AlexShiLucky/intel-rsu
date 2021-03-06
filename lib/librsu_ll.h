/* SPDX-License-Identifier: BSD-2-Clause */

/* Intel Copyright 2018 */

#ifndef __LIBRSU_LL_H__
#define __LIBRSU_LL_H__

#include <linux/types.h>

struct librsu_ll_intf {
	void (*close)(void);

	struct {
		int (*count)(void);
		char *(*name)(int part_num);
		__s64 (*offset)(int part_num);
		int (*size)(int part_num);
		int (*reserved)(int part_num);
		int (*readonly)(int part_num);
		int (*rename)(int part_num, char *name);
	} partition;

	struct {
		int (*get)(int part_num);
		int (*add)(int part_num);
		int (*remove)(int part_num);
	} priority;

	struct {
		int (*read)(int part_num, int offset, int bytes, void *buf);
		int (*write)(int part_num, int offset, int bytes, void *buf);
		int (*erase)(int part_num);
	} data;
};

int librsu_ll_open_datafile(struct librsu_ll_intf **intf);
int librsu_ll_open_qspi(struct librsu_ll_intf **intf);

#endif
