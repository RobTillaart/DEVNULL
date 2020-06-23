# DEVNULL

Arduino library for a /dev/null stream

## Description

The library implements a stream class that mimics the /dev/null
device of a linux system. You can write everything to it, you can 
never read data from it as it always returns EOF (end of file);

THe 0.1.0 version is a minimal implementation that can be optimized.
Now it only implements the **write()** call and e.g. a float is still
converted to individual characters that are send one after another.
Strings and text send every byte.

The advantage is that printing takes time and e.g. one can use it to measure 
the **print** class performance.

Performance can be increased by implementing all methods of the print interface
with only a return 0; 

## Operation
use with care

See example
