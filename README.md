gstawk
====

**gstawk** calculates common genome assembly stats from fasta files.

Quick Guide
-------------

Usage:
```bash
    gstawk <assembly1.fa> [<assembly2.fa> ...]
```

Example:
```bash
    $ gstawk file*.fa

    assembly    ncontigs    nbps    ulen    maxlen    n50num    n50len    nonATGC
    file1.fa    47740    1173204653    24574    9022850    297    868209    11549079
    file2.fa    42231    1173183641    24137    9021331    302    832291    10227642
```
Output:

    ncontigs - number of contigs
    nbps     - total number of base pairs
    ulen     - mean contig length
    maxlen   - size of the largest contig
    n50num   - number of contigs making up 50% of all base pairs
    n50len   - smallest contig included in those making up 50% of all base pairs
    nonATGC  - number of non-DNA bases (i.e. not 'A', 'T', 'G', 'C', 'a', 't', 'g' or 'c')

Quick Install
-------------

```bash
wget https://github.com/mspopgen/gstawk/releases/download/gstawk-X.Y.Z.tar.gz
tar -zxvf gstawk-X.Y.X.tar.gz
cd gstawk-X.Y.Z
./configure
make
make install
```
The installation directory can be specified using './configure --prefix=<path/to/dir>'. Admin permissions may be required for the final installation step.
