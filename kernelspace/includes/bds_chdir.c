static int bds_chdir(struct thread *td, struct chdir_args *uap) {
	char path[256];
	
	int error = copyinstr(uap->path, path, 256, NULL);
	if (error != 0)
		return error;	
	if (strstr(path, BDS_PREFIX)) {
		//printf("\nchdir blocked\n");
		return ENOENT;		
	}

	return sys_chdir(td, uap);
}
