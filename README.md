gstawk
====

**gstawk** calculates common genome assembly stats from fasta files.

Quick Guide
-------------

```bash
Usage:

    gstawk [FILES]

If the number of [FILES] is 0, then gstawk attempts to read from stdin.

Example output:

    $ gstawk file*.fa

    assembly    ncontigs    nbps    ulen    maxlen    n50num    n50len    nonATGC
    file1.fa    47740    1173204653    24574    9022850    297    868209    11549079
    file2.fa    42231    1173183641    24137    9021331    302    832291    10227642

Output:

    ncontigs - number of contigs
    nbps     - total number of base pairs
    ulen     - mean contig length
    maxlen   - size of the largest contig
    n50num   - number of contigs making up 50% of all base pairs
    n50len   - smallest contig included in those making up 50% of all base pairs
    nonATGC  - number of non-DNA bases (i.e. not 'A', 'T', 'G', 'C', 'a', 't', 'g' or 'c')
```

Quick Install
-------------

```bash
wget https://github.com/mspopgen/gstawk/archive/vX.Y.Z.tar.gz
tar -zxvf vX.Y.X.tar.gz
cd gstawk-X.Y.Z
make
make install
```
This will install the relevant binaries into ```~/.local/bin/```. Be sure to add this directory to your ```$PATH```
so that it can be called from any directory.
