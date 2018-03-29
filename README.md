# Practice repo for reverse engineering

Random note: on MacOS, it's not `main` but `entry0`.

## v1

- strings
- `rabin2 -z` (Radare2)

### v1b

on osx you have to run radare2 with sudo to open with debug

- radare2: `db <address>` -> create a breakpoint

python help:

```
radare2 > aa
radare2 > s entry0
radare2 > pd
radare2 > s section.4.__TEXT.__const
radare2 > ps 0x14      ; verify
radare2 > pcp 0x14

python> # paste
python> print("%s" % bytes([((x - 0xf0 + 256) % 256) for x in buf]).decode("utf-8"))
```

## v2

- `afvn local_18h something` -> rename variable `local_18` to `something`
- `VV` -> visual mode can be helpful

## v3

- Loop in a loop
- Basically the same logic to find the solution as v2 with a twist
- There is an extra check

## v4

TODO

## v5

TODO

## Radare2 help

```
rabin2 -z bin/license-v1   # aka strings
```

```
pdf                 print disassemble function
afvd                analyze function variables display
afvn <old> <new>    analyze function variables name
```
