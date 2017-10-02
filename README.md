# hdf5-tests
Just some clumsy playing around to figure out the file format

Plan:
I can come up with some standard data that is similar to what I will need and then test it. Can also time different options

* continous output every sweep
* saving some and flushing every N sweeps
* only outputting at the end

(guessing that if the last is fastest we might still use the second to avoid memory problems for the program, we'll see)

how does compressing influence this?
Are there hdf5 bindings for eigen/ blaze etc?
* found this for eigen https://github.com/garrison/eigen3-hdf5
