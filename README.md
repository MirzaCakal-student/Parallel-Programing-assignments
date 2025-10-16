1.
ss_zad1:
all comands that I use are:

sudo apt update
sudo apt install -y build-essential pkg-config libcairo2-dev libpng-dev libglib2.0-dev libfontconfig1-dev libx11-dev libxext-dev libxrender-dev libxft-dev zlib1g-dev gnuplot

Cairo installation:
wget https://www.cairographics.org/releases/cairo-1.16.0.tar.xz
tar -xf cairo-1.16.0.tar.xz
cd cairo-1.16.0
./configure --with-x --prefix=/usr/local
make
sudo make install

Hwloc installation:
cd ~
git clone https://github.com/open-mpi/hwloc.git
cd hwloc
./configure --prefix=/usr/local --enable-cairo
make
sudo make install

at the end I run lstopo. I have some configure problems ./configure --prefix=/usr/local --enable-cairo -bash: ./configure: No such file or directory  
so I needed to use:
chmod +x autogen.sh
./autogen.sh
sudo apt install -y autoconf automake libtool
./autogen.sh

after I fix it with this comands I found on google it works.
------------------------------------------------------------------------------------------------ize 
of the arrays if this shows that
you are not getting at least 20 clock ticks per test.
-------------------------------------------------------------
WARNING -- The above is only a rough guideline.
For best results, please be sure you know the
precision of your system timer.
-------------------------------------------------------------
Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:           25421.0     0.006963     0.006294     0.008204
Scale:          18335.8     0.009468     0.008726     0.011902
Add:            209--
2.
ass_zad2:

mirza@Mirza:~$ git clone https://github.com/jeffhammond/STREAM.git
Cloning into 'STREAM'...
remote: Enumerating objects: 89, done.
remote: Counting objects: 100% (38/38), done.
remote: Compressing objects: 100% (14/14), done.
remote: Total 89 (delta 31), reused 24 (delta 24), pack-reused 51 (from 2)
Receiving objects: 100% (89/89), 32.88 KiB | 340.00 KiB/s, done.
Resolving deltas: 100% (50/50), done.
mirza@Mirza:~$ cd STREAM
mirza@Mirza:~/STREAM$ make
gcc -O2 -fopenmp   -c -o mysecond.o mysecond.c
gcc -O2 -fopenmp -c mysecond.c
gfortran -O2 -fopenmp -c stream.f
make: gfortran: No such file or directory
make: *** [Makefile:11: stream_f.exe] Error 127
mirza@Mirza:~/STREAM$ make stream_c.exe
gcc -O2 -fopenmp stream.c -o stream_c.exe
mirza@Mirza:~/STREAM$ ./stream_c.exe
-------------------------------------------------------------
STREAM version $Revision: 5.10 $
-------------------------------------------------------------
This system uses 8 bytes per array element.
-------------------------------------------------------------
Array size = 10000000 (elements), Offset = 0 (elements)
Memory per array = 76.3 MiB (= 0.1 GiB).
Total memory required = 228.9 MiB (= 0.2 GiB).
Each kernel will be executed 10 times.
 The *best* time for each kernel (excluding the first iteration)
 will be used to compute the reported bandwidth.
-------------------------------------------------------------
Number of Threads requested = 4
Number of Threads counted = 4
-------------------------------------------------------------
Your clock granularity/precision appears to be 1 microseconds.
Each test below will take on the order of 6397 microseconds.
   (= 6397 clock ticks)
Increase the size 
of the arrays if this shows that
you are not getting at least 20 clock ticks per test.
-------------------------------------------------------------
WARNING -- The above is only a rough guideline.
For best results, please be sure you know the
precision of your system timer.
-------------------------------------------------------------
Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:           25421.0     0.006963     0.006294     0.008204
Scale:          18335.8     0.009468     0.008726     0.011902
Add:            20924.4     0.012151     0.011470     0.013453
Triad:          20718.2     0.012753     0.011584     0.014675
-------------------------------------------------------------
Solution Validates: avg error less than 1.000000e-13 on all three arrays
-------------------------------------------------------------
mirza@Mirza:~/STREAM$
--------------------------------------------------------------------------------------------------
4.
CloverLeaf Profiling with Valgrind and KCacheGrind

sudo apt update
sudo apt install valgrind kcachegrind
valgrind --version
kcachegrind --version


Now download CloverLeaf from GitHub

git clone --recursive https://github.com/UK-MAC/CloverLeaf.git
cd CloverLeaf/CloverLeaf_Serial

Now we build the program. We use options to include debug info (-g) and disable vectorization so profiling is easier to read.
make COMPILER=GNU IEEE=1 C_OPTIONS="-g -fno-tree-vectorize" OPTIONS="-g -fno-tree-vectorize"


Now we need an input file. Copy one from the InputDecks folder and open it for editing

cp ../InputDecks/clover_bm256_short.in clover.in
nano clover.in

hange some values inside to make it smaller and faster
x_cells=256
y_cells=256
end_step=10

If we don't do this program gets killed because of too much memory

Now run CloverLeaf with Valgrind Callgrind
valgrind --tool=callgrind -v ./clover_leaf
after this we just run
kcachegrind
---------------------------------------------------------------------
5.


student@itcenter-lab128:~$ git clone https://github.com/RRZE-HPC/likwid.git
fatal: destination path 'likwid' already exists and is not an empty directory.
student@itcenter-lab128:~$ cd likwid
student@itcenter-lab128:~/likwid$ nano config.mk
student@itcenter-lab128:~/likwid$ make
===>  ENTER  bench
make[1]: Nothing to be done for 'all'.
student@itcenter-lab128:~/likwid$ sudo make install
===> INSTALL access daemon to /usr/local/sbin/likwid-accessD
install -m 4755 -g root -o root likwid-accessD /usr/local/sbin/likwid-accessD
===> INSTALL setFrequencies tool to /usr/local/sbin/likwid-setFreq
===> No INSTALL of the application interface appDaemon
===> No INSTALL of the container helper likwid-bridge
===> INSTALL applications to /usr/local/bin
===> INSTALL helper applications to /usr/local/bin
===> INSTALL lua to likwid interface to /usr/local/share/lua
===> INSTALL libraries to /usr/local/lib
===> INSTALL man pages to /usr/local/man/man1
===> INSTALL headers to /usr/local/include
===> INSTALL groups to /usr/local/share/likwid/perfgroups
===> INSTALL docs and examples to /usr/local/share/likwid/docs
===> INSTALL filters to /usr/local/share/likwid/filter
===> INSTALL cmake to /usr/local/share/likwid
student@itcenter-lab128:~/likwid$ ^[[200~sudo modprobe msr
sudo: command not found
student@itcenter-lab128:~/likwid$ sudo modprobe msr
student@itcenter-lab128:~/likwid$ likwid-perfctr -C 0-7 -g MEM_DP ./clover_leaf
--------------------------------------------------------------------------------
CPU name:	Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:	Intel Core SandyBridge processor
CPU clock:	3.29 GHz
ERROR - [/home/student/likwid/src/perfgroup.c:perfgroup_readGroup:830] No such file or directory.
Cannot read group file MEM_DP.txt. Searched in /usr/local/share/likwid/perfgroups/sandybridge/MEM_DP.txt and /home/student/.likwid/groups/sandybridge/MEM_DP.txt
ERROR - [/home/student/likwid/src/perfmon.c:perfmon_addEventSet:2533] Permission denied.
Access to performance group MEM_DP not allowed
student@itcenter-lab128:~/likwid$ 
 

 here I do not have access to performabce group 