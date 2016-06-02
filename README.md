# ex-3.7
This is *the* original `vi` in the earliest release of it's last version 3.7, released at October 31, 1981 on 4.1cBSD.
## Installation notes
Some configuration (e.g. installation paths) can be done in the [`makefile`](https://github.com/n-t-roff/ex-3.7/blob/master/Makefile.in).
For compiling it on BSD, Linux and Solaris autoconfiguration is required:
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
* The original `vi` (even the final 3.7 release from 1993) never had a `showmode` option.
  This option had been added to the solaris version of `vi` by SunOS developers and to
  [heirloom `vi`](https://github.com/n-t-roff/heirloom-ex-vi)
  by Gunnar Ritter.
* PAGE-UP, PAGE-DOWN keys may work on most terminals by putting
  `map  ^[[5~ ^B` and `map  ^[[6~ ^F` into `~/.exrc`.
  If this doesn't work on your terminal you may need other escape sequences which can be retrieved with
  `infocmp -l` from capabilities `kpp` and `knp`.
  My `~/.exrc` looks like this:
```
    set autoindent
    set nowrapscan
    map  ^[[5~ ^B
    map! ^[[5~ ^[^B
    map  ^[[6~ ^F
    map! ^[[6~ ^[^F
    map  ^[OD   h
    map! ^[OD ^[
    map  ^[OB   j
    map! ^[OB ^[jl
    map  ^[OA   k
    map! ^[OA ^[kl
    map  ^[OC   l
    map! ^[OC ^[2l
```

**Attention**:
The original `vi` had not been 8-bit clean!
Moreover it does automatically change all 8-bit characters to 7-bit in the whole file even if no editing is done!
This will e.g. destroy all UTF-8 characters.
`vi` gives you a hint in this case by requiring `:w!` for writing even if you have UNIX write permissions
(so be warned if `vi` asks for `:w!` unexpectedly).
You can use Gunnar Ritter's [heirloom `vi`](https://github.com/n-t-roff/heirloom-ex-vi) for editing UTF-8 files.
