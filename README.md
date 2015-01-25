# pathname

A very small and simple collection of C++ functions for manipulating POSIX pathnames. It operates on
the honor system and does not make any file system related system calls or perform Dot-Dot
resolution. It's just string munging.

join(paths...) works as you would expect:

`pathname::join("/home", "penguin")` -> `"/home/penguin"`

`pathname::join("data", "tmp", "file")` -> `"data/tmp/file"`

`pathname::join("data/", "/tmp/", "/file")` -> `"data/tmp/file"`

this is not a surprise:

`pathname::is_absolute("/tmp")` -> `true`

`pathname::is_absolute("tmp")` -> `false`

dir(path) and base(path) are similar to the dirname and basename utilities _except_ that the functions
consider a trailing slash to indicate a directory name, unlike dirname and basename (I will never,
ever understand this):

`pathname::dir("/home/")` -> `"/home"`

`pathname::dir("/data/tmp/file")` -> `"/data/tmp"`

`pathname::dir("/")` -> `"/"`


`pathname::base("/home/")` -> `"."`

`pathname::base("/data/tmp/file")` -> `"file"`

`pathname::base("/")` -> `"/"`

(If you take the base of a directory other than root, and join it with a file, the result is ./file)
