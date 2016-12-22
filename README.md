CANopenMbed
===========

Example program for LPC1768 implementation of CANopenNode.

# Installation

After cloning, you need to init the submodules. To do so:

```sh
$ git submodule init
$ git submodule update
```

Compiled using the mbed toolkit and the mbed-cli tool. A tutorial is available
[here](http://devblog.exmachina.fr/tutorial/2016/12/08/LPC1768-development-toolkit).

# Resources

- `opencfg.cfg` is a config file for openocd debugging an LPC1768 mbed platform
- `MFE_helpers.h` is a small collection of helper functions for communicating
  with a MicroFlex e100
- `.clang` provides a config file for generating tags with clang

# Links

Original source code can be found at [exmachina-dev/CANopenMbed](https://github.com/exmachina-dev/CANopenMbed)

CANopenNode repository can be found at [exmachina-dev/CANopenNode](https://github.com/exmachina-dev/CANopenNode) forked from [CANopenNode/CANopenNode](https://github.com/CANopenNode/CANopenNode/)
