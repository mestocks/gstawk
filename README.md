gstawk
====

**gstawk** calculates some common genome assembly stats from fasta files containing the assembled contigs or scaffolds. **gstawk** is written *C* but implemented using *Gnu Make*, so that statistics are only calculated for new assemblies, or for assemblies that have subsequently changed.

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
You're now ready to go. If you want the script to be excutable from anywhere then add the path to the *gstawk-0.0.1/* directory to your *$PATH*. 

Quick guide
-------------

Usage:

```bash
gstawk [assembly1.fa assembly2.fa... ]
```
