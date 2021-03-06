# ex-3.7
This is *the* original `vi` in the earliest release of it's last version 3.7,
released at October 31, 1981 on 4.1cBSD.
## Installation notes
The software is downloaded with
```sh
git clone https://github.com/n-t-roff/ex-3.7.git
```
and can be kept up-to-date with
```sh
git pull
```
Some configuration (e.g. installation paths) can be done in the
[`makefile`](https://github.com/n-t-roff/ex-3.7/blob/master/Makefile.in).
Three memory allocation methods can be configured:
* Traditionally ex uses sbrk.
  This does only work if malloc is not used by any called library
  function.
  To make ex work with today's libraries Heirloom's mapmalloc had been
  added.
  Use of this is not possible if the ASAN compiler feature is enabled.
* An alternative to Heirloom's mapmalloc is libmapmalloc from solaris.
  Unfortunately ex crashes on some systems with this library.
  The cause of this crash is likely a bug in the ex source code.
  If it is not intended to use libmapmalloc, the directory can
  be removed from the source tree to reduce license issues
  (libmapmalloc is CDDL licensed).
* malloc and realloc can be used instead of sbrk and mapmalloc.
  This is the default in the Makefile.

For compiling it on BSD, Linux and Solaris auto-configuration is required:
```sh
$ ./configure
```
The software is build with
```sh
$ make
```
and installed with
```
$ su
# make install
# exit
```
All generated files are removed with
```sh
$ make distclean
```
## Usage notes
* This early release of version 3.7 did not support window resizing.
  That means that after starting `vi` the terminal size should be kept constant.
* The original `vi` (even the final 3.7 release from 1993)
  never had a `showmode` option.
  This option had been added to the solaris version of `vi`
  by SunOS developers and to
  [heirloom `vi`](https://github.com/n-t-roff/heirloom-ex-vi)
  by Gunnar Ritter.
* PAGE-UP, PAGE-DOWN keys may work on most terminals by putting
  `map  ^[[5~ ^B` and `map  ^[[6~ ^F` into `~/.exrc`.
  If this doesn't work on your terminal you may need other escape sequences
  which can be retrieved with
  `infocmp -l` from capabilities `kpp` and `knp`.
  An example `~/.exrc` may looks like
  (the `map!` commands make it possible to use PAGE and ARROW keys
  while staying in input mode):
```
    set autoindent
    " Only needed if "number" option is off
    set nowrapscan
    map  ^[[5~ ^B
    map! ^[[5~ ^[^Ba
    map  ^[[6~ ^F
    map! ^[[6~ ^[^Fa
    map  ^[OD   h
    map! ^[OD ^[i
    map  ^[OB   j
    map! ^[OB ^[ja
    map  ^[OA   k
    map! ^[OA ^[ka
    map  ^[OC   l
    map! ^[OC ^[la
```
