# radare2 hints

### Commands

```
| aaa[?]                        autoname functions after aa (see afna)
| afvd name                     output r2 command for displaying the value of args/locals in the debugger
| db                            List breakpoints
| db <addr>                     Add breakpoint
| dc                            Continue execution of all children
| ood[r] [args]                 reopen in debugger mode (with args)
| pdf                           disassemble function
| V                             visual mode
| VV                            fancy visual mode with flow
| ? expr                        execute an expression 
```

### For debug:

```
r2 -d ./binary
```

On MacOS:
 - use `sudo` for `-d`
 - it's not `main` but `entry0`
