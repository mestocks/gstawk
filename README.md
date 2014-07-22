gstawk
====

**gstawk** calculates some common genome assembly stats from fasta files containing your assembled contigs or scaffolds. **gstawk** is written *C* but implemented using *Gnu Make*, so that statistics are only calculated for new assemblies, or for assemblies that have subsequently changed.

Installation
-------------

Download the latest .tar.gz version and unpack using:

```bash
tar -zxvf gstawk-0.0.1.tar.gz
```
You will now need to compile the *C* script, but this is easy. Move into the *gstawk/bin/* directory, then compile it:

```bash
cd gstawk-0.0.1/bin/
gcc -o gstawk.o gstawk.c
```
You're now ready to go. If you want the script to be excutable from anywhere then add the path to the *gstawk-0.0.1/* directory to your *$PATH*. Documentation on how to do this is only a quick google search away.

Quick guide
-------------

**gstawk** has usage:

```bash
gstawk <assembly_fasta_files>
```

So to calculate statistics for a series of assemblies in the current working directory you would, for example, type:

```bash
gstawk *-scaffolds.fa
```
