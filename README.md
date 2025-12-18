# Parallel-Programing-assignments
I use my friends laptop so hostname is
dilfa-XPS-13-9350

compute.png:
Shows compute.sh jobs submitted. Top showing load: 0.31, 0.59, 0.28
Squeue showing jobs in queue. System handling multiple jobs fine

overload.png:
Load: 0.39, 0.56, 0.29. Top showing many processes but organized
Slurm managing everything

Sstrestest.png:
Running stress --cpu 4 WITHOUT Slurm
Load: 3.90, 1.41, 0.61
Multiple stress processes eating CPU

Comands I use:
sudo apt update
sudo apt install -y slurm-wlm slurmd slurmctld munge stress


sudo /usr/sbin/create-munge-key
sudo systemctl start munge


sudo systemctl start slurmctld
sudo systemctl start slurmd


sinfo
squeue


sbatch compute.sh
sbatch overload.sh

top

stress --cpu 4


Slurm prevents system overload - Load of 0.39 vs 3.90 shows clear benefit
Job queuing is essential - Multiple users can submit work without conflicts
Resource tracking ≠ Enforcement - Configuration matters for strict limits
Schedulers improve system stability - Better user experience under load

Batch schedulers like Slurm are critical for HPC environments where multiple users share limited resources. Without them, system performance and stability would be significantly compromised.