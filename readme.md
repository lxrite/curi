*Work in progress*

# CURI - a tiny C URI parser #

A URI C parser respecting [RFC-3986](http://tools.ietf.org/html/rfc3986), inspired by [yajl](http://lloyd.github.io/yajl/), tested with [catch](https://github.com/philsquared/Catch).

## Compilers ##

The library is developped (and thus tested) on:
- Mac OS X Mountain Lion,
    - clang 4.2 (clang-425.0.24);
- Windows 7,
    - 32 bits Visual Studio 2010 SP1 (10.0.40219.1 SP1Rel).

Additionally, it is continuously integrated on [Travis CI](https://travis-ci.org/cloderic/curi) (where master is currently ![Build Status](https://travis-ci.org/cloderic/curi.png?branch=master)), the platforms are:
- 32-bit Ubuntu Linux 12.04,
    - GCC 4.6.x,
    - Clang 3.1.x.
    
## TODO ##

- More unit tests (especially failing unit tests)
- Supporting IP host (e.g. 192.168.0.1)
- Handle relative URI (i.e. schemeless URI)
- Handle path segments callbacks
- Handle query key/value callbacks
- Add on-demand url decoding
- Performance tests and tweaking

