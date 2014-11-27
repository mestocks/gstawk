gstawk
====

**gstawk** calculates some common genome assembly stats from fasta files containing your assembled contigs or scaffolds. **gstawk** is written ```C``` but implemented using ```Gnu Make```, so that statistics are only calculated for new assemblies, or for assemblies that have subsequently changed.

Installation
-------------

Download the latest .tar.gz version and unpack using:

```bash
tar -zxvf gstawk-x.y.z.tar.gz
```
where ```x.y.z``` is the version number. You will now need to compile the ```C``` script, but this is easy. Move into the ```gstawk-x.y.z/``` directory, then compile it by typing:

```bash
make
```
You're now ready to go. If you want the script to be excutable from anywhere then add the path to the ```gstawk-x.y.z/``` directory to your ```$PATH```. Documentation on how to do this is only a quick google search away.

Quick guide
-------------

**gstawk** has usage:

```bash
gstawk [options] <assembly_fasta_files>
```

So to calculate some basic statistics for a series of assemblies in the current working directory you would, for example, type:

```bash
gstawk *-scaffolds.fa
```

You can parallelise the calculation of these basic stats by using the ```-j``` option. For example, the following command would run 4 parallel processes:

```bash
gstawk -j 4 *-scaffolds.fa
```

**gstawk** can also calculate the more general N(x) statistic, where x represents the the percentiles from 0-100. This can be done using the ```-x``` option:

```bash
gstawk -x assembly-scaffolds.fa
```
